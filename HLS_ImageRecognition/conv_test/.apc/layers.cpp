// #include <iostream>
#include <cmath>
 #include "ap_axi_sdata.h"
 #include "ap_int.h"
#include "layers_weight.h"

template <int in_channels, int in_size, int padding>
void pad(half input[in_channels][in_size][in_size], half output[in_channels][in_size + 2 * padding][in_size + 2 * padding])
{
	int out_size = in_size + 2 * padding;
	for (int i = 0; i < in_channels; i++)
	{
		for (int j = 0; j < out_size; j++)
		{
			for (int k = 0; k < out_size; k++)
			{
				// #pragma HLS PIPELINE
				//buffer1(i,j,k) = (j == 0 || k == 0 || j == num - 1 || k == num - 1) ? 0 : num3[i][j - 1][k - 1];
				output[i][j][k] = (j < padding || j >= out_size - padding || k < padding || k >= out_size - padding) ? 0 : input[i][j - padding][k - padding];
			}
		}
	}
}

template <int in_channels, int in_size, int out_channels, int kernel_size, int padding, int stride>
void conv(half input[in_channels][in_size][in_size], half weight[out_channels][in_channels][kernel_size][kernel_size], half bias[out_channels], half output[out_channels][(in_size + 2 * padding - kernel_size) / stride + 1][(in_size + 2 * padding - kernel_size) / stride + 1])
{
	int out_size = (in_size + 2 * padding - kernel_size) / stride + 1;
	half input_after_padding[in_channels][in_size + 2 * padding][in_size + 2 * padding];
	pad<in_channels, in_size, padding>(input, input_after_padding);
	for (int i = 0; i < out_channels; i++) //out_ch
	{

		for (int x = 0; x < out_size; x++)
		{
			for (int y = 0; y < out_size; y++)
			{
				half convsum = 0;
				for (int j = 0; j < in_channels; j++) //in_ch
				{
					for (int i1 = 0; i1 < kernel_size; i1++) //ker_size
					{
						// #pragma HLS PIPELINE
						for (int j1 = 0; j1 < kernel_size; j1++)
						{
							// #pragma HLS UNROLL
							convsum += half(input_after_padding[j][x * stride + i1][y * stride + j1] * weight[i][j][i1][j1]);
						}
					}
				}
				output[i][x][y] = convsum;
			}
		}
	}
	for (int i = 0; i < out_channels; i++)
	{
		for (int x = 0; x < out_size; x++)
		{
			// #pragma HLS PIPELINE
			for (int y = 0; y < out_size; y++)
			{
				// #pragma HLS UNROLL
				output[i][x][y] += bias[i];
			}
		}
	}
}

template <int in_channels, int in_size, int kernel_size, int stride>
void max_pool(half in[in_channels][in_size][in_size], half out[in_channels][(in_size - kernel_size) / stride + 1][(in_size - kernel_size) / stride + 1])
{
	int out_size = (in_size - kernel_size) / stride + 1;
	for (int m = 0; m < in_channels; ++m)
	{
		for (int i = 0; i < out_size; i++)
		{
			for (int j = 0; j < out_size; j++)
			{
				half max_record = -10000000;
				for (int x = i * stride; x < i * stride + kernel_size; x++)
					for (int y = j * stride; y < j * stride + kernel_size; y++)
					{
						if (in[m][x][y] > max_record)
							max_record = in[m][x][y];
					}
				// #pragma HLS UNROLL
				out[m][i][j] = max_record;
			}
		}
	}
}

template <int in_channels, int in_size>
void relu(half in[in_channels][in_size][in_size], half out[in_channels][in_size][in_size])
{
	for (int m = 0; m < in_channels; ++m)
		for (int r = 0; r < in_size; ++r)
			for (int c = 0; c < in_size; ++c)
				out[m][r][c] = (in[m][r][c] > 0) ? in[m][r][c] : 0;
}

template <int in_channels, int in_size>
void mean(half input[in_channels][in_size][in_size], half out[in_channels])
{
	for (int i = 0; i < in_channels; i++)
	{
		half m = 0;
		for (int j = 0; j < in_size; j++)
		{
			for (int k = 0; k < in_size; k++)
			{
				// #pragma HLS PIPELINE
				m += input[i][j][k];
			}
		}
		out[i] = m / (in_size * in_size);
	}
}

template <int in_channels, int in_size>
void var(half input[in_channels][in_size][in_size], half out[in_channels], half mean[in_channels])
{
	for (int i = 0; i < in_channels; i++)
	{
		half v = 0;
		for (int j = 0; j < in_size; j++)
		{
			for (int k = 0; k < in_size; k++)
			{
				// #pragma HLS PIPELINE
				v += (input[i][j][k] - mean[i]) * (input[i][j][k] - mean[i]);
			}
		}
		out[i] = v / (in_size * in_size);
	}
}

template <int in_channels, int in_size>
void bn(half input[in_channels][in_size][in_size], half out[in_channels][in_size][in_size], half weight[in_channels], half bias[in_channels])
{
	half m[in_channels];
	mean<in_channels, in_size>(input, m);
	half v[in_channels];
	var<in_channels, in_size>(input, v, m);
	for (int i = 0; i < in_channels; i++)
	{
		for (int j = 0; j < in_size; j++)
		{
			for (int k = 0; k < in_size; k++)
			{
				// #pragma HLS PIPELINE
				half temp = (input[i][j][k] - m[i]);
				temp *= weight[i];
				temp /= sqrt(v[i] + 0.00001);
				temp += bias[i];
				out[i][j][k] = temp;
			}
		}
	}
}

template <int in_size, int out_size>
void linear(half input[in_size], half out[out_size], half weight[out_size][in_size], half bias[out_size])
{
	for (int i = 0; i < out_size; i++)
	{
		for (int j = 0; j < in_size; j++)
		{
			// #pragma HLS PIPELINE
			out[i] += input[j] * weight[i][j];
		}
		out[i] += bias[i];
	}
}

struct my_half
{
	half data;
	ap_uint<1> last;
};

const int input_pic_size = 51;
const int output_features = 12;
static half input_num[3][input_pic_size][input_pic_size];
void test(my_half input[3][input_pic_size][input_pic_size], my_half output[output_features])
{
#pragma HLS INTERFACE ap_ctrl_none port = return
#pragma HLS INTERFACE axis register both port = input
#pragma HLS INTERFACE axis register both port = output
	for (int m = 0; m < 3; m++)
		for (int i = 0; i < input_pic_size; i++)
		{
#pragma HLS PIPELINE
			for (int j = 0; j < input_pic_size; j++)
			{
#pragma HLS PIPELINE
				input_num[m][i][j] = input[m][i][j].data;
			}
		}
	const int conv1_out_size = 49;
	const int conv1_out_features = 8;
	half out[conv1_out_features][conv1_out_size][conv1_out_size];
	conv<3, input_pic_size, conv1_out_features, 3, 0, 1>(input_num, layerconv1_0_weight, layerconv1_0_bias, out);
	half out1[conv1_out_features][conv1_out_size][conv1_out_size];
	relu<conv1_out_features, conv1_out_size>(out, out1);

	const int conv2_out_size = 24;
	const int conv2_out_features = 14;
	half out2[conv2_out_features][conv2_out_size][conv2_out_size];
	conv<conv1_out_features, conv1_out_size, conv2_out_features, 3, 0, 2>(out1, layerconv2_0_weight, layerconv2_0_bias, out2);
	half out3[conv2_out_features][conv2_out_size][conv2_out_size];
	relu<conv2_out_features, conv2_out_size>(out2, out3);

	const int conv3_out_size = 22;
	const int conv3_out_features = 24;
	half out4[conv3_out_features][conv3_out_size][conv3_out_size];
	conv<conv2_out_features, conv2_out_size, conv3_out_features, 3, 0, 1>(out3, layerconv3_0_weight, layerconv3_0_bias, out4);
	half out5[conv3_out_features][conv3_out_size][conv3_out_size];
	relu<conv3_out_features, conv3_out_size>(out4, out5);

	const int max_pool_out_size = 11;
	half out6[conv3_out_features][max_pool_out_size][max_pool_out_size];
	max_pool<conv3_out_features, conv3_out_size, 2, 2>(out5, out6);

	half out18[conv3_out_features];
	mean<conv3_out_features, max_pool_out_size>(out6, out18);
	half out19[output_features];
	linear<conv3_out_features, output_features>(out18, out19, layerfc_weight, layerfc_bias);

	for (int m = 0; m < output_features; m++)
	{
		output[m].data = out19[m];
		output[m].last = (m == output_features - 1) ? 1 : 0;
	}
}

// int main()
// {
// 	half in[2][16][16] = {{{-84, 89, -60, -16, -34, -75, -42, -12, -53, 74,
// 							 83, 84, -118, 115, -111, -82},
// 							{66, 112, -109, 19, 122, -7, 64, 98, 72, 22,
// 							 90, 113, 72, 83, -63, -114},
// 							{-69, 23, 80, -73, -109, -54, 61, 11, -18, 26,
// 							 -3, 52, -22, 53, -2, 75},
// 							{18, -22, 54, 85, -94, 73, -10, -15, 12, -48,
// 							 114, 1, 108, 122, 12, -77},
// 							{75, -28, -89, 96, -93, -120, -9, -81, -14, -61,
// 							 34, 88, -95, -8, -114, 15},
// 							{102, -23, 83, -44, 39, 35, -53, 71, 46, 82,
// 							 -119, 80, -108, 88, -83, -104},
// 							{-6, 106, 108, -101, -89, -41, 69, 77, -58, -27,
// 							 -98, 122, -63, -30, -55, -51},
// 							{-21, 1, 46, -9, -34, -28, -44, -5, -96, -101,
// 							 84, 34, -53, 92, 30, 36},
// 							{-97, -4, 44, 111, -92, 61, -78, -4, -70, -29,
// 							 -38, -7, 9, 60, -95, -94},
// 							{23, 106, 120, 85, 28, 51, -52, -10, -19, -44,
// 							 125, 34, 42, 22, -46, 37},
// 							{127, 25, 76, -103, 106, -87, -113, 104, -116, -80,
// 							 74, -37, 63, 90, -107, -92},
// 							{-12, -127, 27, 46, 119, 2, -33, 43, 94, -104,
// 							 37, -50, 89, -47, 101, 121},
// 							{16, -27, 7, 20, -45, 8, 70, -45, 89, -55,
// 							 114, 58, -10, -106, -30, 93},
// 							{54, -85, 117, -11, -16, 81, 26, -27, 25, 2,
// 							 8, 55, 50, -97, -83, 19},
// 							{-2, -79, 55, 80, 90, 36, -61, -36, -125, -90,
// 							 66, 71, -12, 47, 20, -98},
// 							{-96, -55, -123, -127, -56, -43, -103, -122, -85, 96,
// 							 68, -70, -98, -83, -108, 66}},

// 						   {{-43, 84, -106, -72, -73, 14, 72, 24, 33, -85,
// 							 -13, -85, -113, -53, 113, -69},
// 							{-88, -20, 86, -30, -88, 67, 39, -104, 104, 5,
// 							 40, 125, 11, -93, 27, -39},
// 							{17, 18, 113, -63, 92, -33, 20, 50, -52, -102,
// 							 -116, 81, -79, -98, 82, 110},
// 							{39, 46, -52, 25, -7, 127, 110, -126, 60, 12,
// 							 88, 82, -118, -122, 70, 3},
// 							{65, -16, 50, 100, 48, -62, -128, 49, -6, 78,
// 							 51, -64, 13, -95, 61, -93},
// 							{35, 19, 87, -79, -80, -116, 37, -46, 80, -115,
// 							 38, 110, 54, -56, 18, -28},
// 							{-43, -79, -52, 41, -16, -75, -85, 75, 78, 115,
// 							 66, -61, 107, 69, 26, 0},
// 							{90, -89, 49, 49, 68, -96, -67, 122, 52, -94,
// 							 67, 100, -18, 65, 107, 63},
// 							{-84, -48, -22, 99, -11, 37, 27, 71, 44, 114,
// 							 66, -35, -99, -128, -102, -40},
// 							{111, -62, -65, 117, -106, -16, -46, 83, 93, -85,
// 							 55, -82, -65, -8, 40, 2},
// 							{39, -97, -18, 113, 49, -14, 29, -76, 66, -8,
// 							 -42, 116, 96, -117, 84, -81},
// 							{-120, -127, 110, -41, 6, -105, 56, 73, 51, 31,
// 							 38, 26, 33, 3, 44, 15},
// 							{124, -20, -25, -95, 68, -127, -60, 75, 86, 56,
// 							 -50, -56, -85, -49, 60, -21},
// 							{52, 120, 47, -44, 118, 86, -77, 93, 1, 62,
// 							 -75, -117, -27, 97, 17, 79},
// 							{78, -49, -67, -86, -6, 64, 77, -16, 18, -33,
// 							 44, 14, -41, 69, 58, -37},
// 							{64, -59, 68, 3, -78, -105, 56, 67, -13, 48,
// 							 -40, 85, -101, -29, 24, -4}}};
// 	half w[6][2][3][3] = {{{{-0.0021, 0.0489, 0.1594},
// 							 {0.0125, 0.0516, -0.1385},
// 							 {0.2246, 0.0845, 0.1533}},

// 							{{0.1269, 0.1563, 0.0308},
// 							 {-0.0457, -0.1172, 0.1573},
// 							 {0.1416, 0.0097, 0.0987}}},

// 						   {{{-0.0839, 0.1127, -0.0561},
// 							 {0.1179, -0.0307, -0.1897},
// 							 {-0.1951, -0.0903, 0.1172}},

// 							{{-0.0302, 0.2208, 0.0350},
// 							 {0.0749, 0.1984, -0.1825},
// 							 {0.1753, -0.0229, 0.0102}}},

// 						   {{{-0.0543, -0.0315, 0.2258},
// 							 {-0.1299, -0.1637, 0.0259},
// 							 {0.1532, 0.2159, 0.0947}},

// 							{{-0.2232, -0.0901, 0.0644},
// 							 {-0.0085, -0.0246, 0.1225},
// 							 {0.2076, 0.0277, -0.0334}}},

// 						   {{{0.0416, 0.1226, 0.0378},
// 							 {-0.0470, 0.1895, 0.1343},
// 							 {-0.0470, 0.1932, -0.0630}},

// 							{{-0.1047, -0.0540, -0.2121},
// 							 {0.2116, 0.0996, -0.1280},
// 							 {-0.0915, -0.0849, -0.0725}}},

// 						   {{{-0.2061, -0.0763, -0.0356},
// 							 {0.0487, -0.0867, -0.0686},
// 							 {0.2078, 0.1314, -0.0844}},

// 							{{0.0193, -0.1657, 0.0349},
// 							 {0.1126, 0.1907, 0.2249},
// 							 {0.1342, 0.1638, -0.0376}}},

// 						   {{{-0.1636, 0.1034, -0.0791},
// 							 {-0.0767, 0.2154, 0.1294},
// 							 {-0.1740, -0.0095, -0.1943}},

// 							{{0.0986, -0.0492, -0.1407},
// 							 {0.0298, 0.1529, -0.0510},
// 							 {-0.1361, -0.1213, -0.0181}}}};
// 	half b[6] = {-0.1869, -0.1181, -0.0899, 0.1593, 0.1114, 0.1980};

// 	half out[6][9][9];
// 	conv<2, 16, 6, 3, 2, 2>(in, w, b, out);

// 	for (int m = 0; m < 6; m++)
// 	{
// 		for (int i = 0; i < 9; i++)
// 		{
// 			for (int j = 0; j < 9; j++)
// 				std::cout << out[m][i][j] << '\t';
// 			std::cout << std::endl;
// 		}
// 		std::cout << std::endl;
// 	}
// }
