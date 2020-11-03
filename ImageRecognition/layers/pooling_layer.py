# -*- encoding: utf-8 -*-

import numpy as np
import numpy.lib.stride_tricks


class MaxPoolingLayer():
    def __init__(self, kernel_size, pad=0):
        '''
        This class performs max pooling operation on the input.
        Args:
                kernel_size: The height/width of the pooling kernel.
                pad: The width of the pad zone.
        '''

        self.kernel_size = kernel_size
        self.pad = pad
        self.trainable = False

    def forward(self, Input):
        '''
        This method performs max pooling operation on the input.
        Args:
                Input: The input need to be pooled.
        Return:
                The tensor after being pooled.
        '''
        ############################################################################
    # TODO: Put your code here
        # Apply convolution operation to Input, and return results.
        # Tips: you can use np.pad() to deal with padding.

        # print("pooling layer forward")
        self.Input = Input
        input_after_pad = np.pad(
            Input, ((0,), (0,), (self.pad,), (self.pad,)), mode='constant', constant_values=0)

        output = np.zeros([input_after_pad.shape[0], input_after_pad.shape[1], int(
            input_after_pad.shape[2] / self.kernel_size), int(input_after_pad.shape[3]/self.kernel_size)])
        self.max_pos_x = np.zeros(output.shape)
        self.max_pos_y = np.zeros(output.shape)

        input_after_pad_stride = numpy.lib.stride_tricks.as_strided(
            input_after_pad,
            output.shape +
            (self.kernel_size, self.kernel_size),
            strides=(input_after_pad.strides[0], input_after_pad.strides[1],
                     self.kernel_size * input_after_pad.strides[2],
                     self.kernel_size * input_after_pad.strides[3],
                     input_after_pad.strides[2], input_after_pad.strides[3]))
        # print(input_after_pad_stride)
        output = np.amax(input_after_pad_stride, axis=(4, 5))
        # print(output)
        input_after_pad_stride_reshape = input_after_pad_stride.reshape(
            input_after_pad_stride.shape[0], input_after_pad_stride.shape[1], input_after_pad_stride.shape[2], input_after_pad_stride.shape[3], -1)
        # print(input_after_pad_stride_reshape)
        # print(np.argmax(input_after_pad_stride_reshape, 4))
        # print(input_after_pad_stride[0, 0, 0, 0].shape)
        self.max_pos_x, self.max_pos_y = np.unravel_index(np.argmax(input_after_pad_stride_reshape, 4),
                                                          input_after_pad_stride[0, 0, 0, 0].shape)
        # print((self.max_pos_x, self.max_pos_y))
        # for batch in range(output.shape[0]):
        #     for filt in range(output.shape[1]):
        #         stride = numpy.lib.stride_tricks.as_strided(
        #             input_after_pad[batch, filt],
        #             output[batch, filt].shape +
        #             (self.kernel_size, self.kernel_size),
        #             strides=tuple(
        #                 i * self.kernel_size for i in input_after_pad[batch, filt].strides) +
        #             input_after_pad[batch, filt].strides)
        #         # print(stride)
        #         output[batch, filt] = np.amax(stride, axis=(2, 3))
        #         stride_reshape = stride.reshape(
        #             stride.shape[0], stride.shape[1], -1)
        #         self.max_pos_x[batch, filt], self.max_pos_y[batch, filt] = np.unravel_index(np.argmax(stride_reshape, 2),
        # stride[0, 0].shape)
        # print(output)
        # print(f'output shape : {output.shape}')
        return output

        ############################################################################

    def backward(self, delta):
        '''
        Args:
                delta: Local sensitivity, shape-(batch_size, filters, output_height, output_width)
        Return:
                delta of previous layer
        '''
        ############################################################################
        # # TODO: Put your code here
        # Calculate and return the new delta.
        # print("pooling layer backward")
        input_after_pad = np.pad(
            self.Input, ((0,), (0,), (self.pad,), (self.pad,)), mode='constant', constant_values=0)
        # print(input_after_pad)
        gradient = np.zeros(input_after_pad.shape)

        gradient_stride = numpy.lib.stride_tricks.as_strided(
            gradient,
            delta.shape +
            (self.kernel_size, self.kernel_size),
            strides=(gradient.strides[0], gradient.strides[1],
                     self.kernel_size * gradient.strides[2],
                     self.kernel_size * gradient.strides[3],
                     gradient.strides[2], gradient.strides[3]))

        # print(gradient_stride)

        x1 = np.kron(np.arange(gradient_stride.shape[0]), np.ones(
            gradient_stride.shape[1]*gradient_stride.shape[2]*gradient_stride.shape[3]))
        # print(x1)
        x2 = np.kron(np.ones(gradient_stride.shape[0]),
                     np.kron(np.arange(gradient_stride.shape[1]),
                             np.ones(gradient_stride.shape[2]*gradient_stride.shape[3])))
        # print(x2)
        x3 = np.kron(np.ones(gradient_stride.shape[0]*gradient_stride.shape[1]),
                     np.kron(np.arange(gradient_stride.shape[2]),
                             np.ones(gradient_stride.shape[3])))
        # print(x3)
        x4 = np.kron(np.ones(gradient_stride.shape[0]*gradient_stride.shape[1]*gradient_stride.shape[2]),
                     np.arange(gradient_stride.shape[3]))
        # print(x4)

        gradient_stride[x1.astype(int), x2.astype(int), x3.astype(
            int), x4.astype(int), self.max_pos_x.astype(int).reshape(1, -1), self.max_pos_y.astype(int).reshape(1, -1)] = 1
        # print(gradient)
        gradient = gradient * \
            np.kron(delta, np.ones(gradient_stride[0, 0, 0, 0].shape))

        # for batch in range(delta.shape[0]):
        #     for filt in range(delta.shape[1]):
        #         stride = numpy.lib.stride_tricks.as_strided(
        #             gradient[batch, filt],
        #             delta[batch, filt].shape +
        #             (self.kernel_size, self.kernel_size),
        #             strides=tuple(
        #                 i * self.kernel_size for i in input_after_pad[batch, filt].strides) +
        #             input_after_pad[batch, filt].strides)
        #         # print(stride)
        #         xx = np.kron(
        #             np.arange(stride.shape[0]), np.ones(stride.shape[1], dtype='int'))
        #         yy = np.kron(
        #             np.ones(stride.shape[0], dtype='int'), np.arange(stride.shape[1]))
        #         # print(xx)
        #         # print(yy)
        #         # print(self.max_pos_x.reshape(
        #         #     1, -1))
        #         stride[xx, yy, self.max_pos_x[batch, filt].astype(int).reshape(
        #             1, -1), self.max_pos_y[batch, filt].astype(int).reshape(1, -1)] = 1
        #         # print(stride)
        #         # print(gradient[batch, filt])
        #         gradient[batch, filt] = numpy.lib.stride_tricks.as_strided(
        #             stride, gradient[batch, filt].shape, gradient[batch, filt].strides)
        #         # print(gradient[batch, filt])
        #         # print(np.kron(delta[batch, filt], np.ones(stride[0, 0].shape)))
        #         gradient[batch, filt] = gradient[batch, filt] * \
        #             np.kron(delta[batch, filt], np.ones(stride[0, 0].shape))

        gradient = gradient[:, :, self.pad:(
            self.pad+self.Input.shape[2]), self.pad:(self.pad+self.Input.shape[3])]
        # print(gradient)
        # print(f"output shape : {gradient.shape}")
        return gradient

        ############################################################################


# pool = MaxPoolingLayer(3, 1)
# x = np.random.randint(0, 16, [2, 2, 4, 7])
# print(x)
# pool.forward(x)
# x = np.array([[[[14, 11, 13],
#                 [15, 14,  9]],

#                [[12, 14, 9],
#                 [12, 15, 13]]],


#               [[[13, 10, 14],
#                 [7, 13, 14]],

#                [[12, 14, 10],
#                   [13,  8, 15]]]])
# print(x)
# pool.backward(x)
