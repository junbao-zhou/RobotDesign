// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __test_layerfc_weight_H__
#define __test_layerfc_weight_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct test_layerfc_weight_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 16;
  static const unsigned AddressRange = 96;
  static const unsigned AddressWidth = 7;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(test_layerfc_weight_ram) {
        ram[0] = "0b0010110000011111";
        ram[1] = "0b1010110111111110";
        ram[2] = "0b1011011010101110";
        ram[3] = "0b0011000010100010";
        ram[4] = "0b0010110110111000";
        ram[5] = "0b0001011010100010";
        ram[6] = "0b0010110110100110";
        ram[7] = "0b0010111110001001";
        ram[8] = "0b0011010001011110";
        ram[9] = "0b0011000101010011";
        ram[10] = "0b1011011001100001";
        ram[11] = "0b1011001001000111";
        ram[12] = "0b1011010011100000";
        ram[13] = "0b0011001100111110";
        ram[14] = "0b1011001000100101";
        ram[15] = "0b1011000001001111";
        ram[16] = "0b1010110001001111";
        ram[17] = "0b0011001000010111";
        ram[18] = "0b0011011000110011";
        ram[19] = "0b0010100010001101";
        ram[20] = "0b1011010000001101";
        ram[21] = "0b1011010000110110";
        ram[22] = "0b1011011010010011";
        ram[23] = "0b1011001101100110";
        ram[24] = "0b1010111010101001";
        ram[25] = "0b0010110001010000";
        ram[26] = "0b0011101000101111";
        ram[27] = "0b1011011100110011";
        ram[28] = "0b0011010001110001";
        ram[29] = "0b0010111001000111";
        ram[30] = "0b0011000010111100";
        ram[31] = "0b0010100111010011";
        ram[32] = "0b1010110001110011";
        ram[33] = "0b1011000011001000";
        ram[34] = "0b1011101001100101";
        ram[35] = "0b0010111101011101";
        ram[36] = "0b1010111100000100";
        ram[37] = "0b0010110001101101";
        ram[38] = "0b0011000100100110";
        ram[39] = "0b0011010010010001";
        ram[40] = "0b1011001110010111";
        ram[41] = "0b0010111000111110";
        ram[42] = "0b1010100011110011";
        ram[43] = "0b0011001001000111";
        ram[44] = "0b1011010111011110";
        ram[45] = "0b1011000100011001";
        ram[46] = "0b1001111110110100";
        ram[47] = "0b1011100110101111";
        ram[48] = "0b0011000000100011";
        ram[49] = "0b0011000111101111";
        ram[50] = "0b1011011101100010";
        ram[51] = "0b1011000001011111";
        ram[52] = "0b0001111100001100";
        ram[53] = "0b1010111010011001";
        ram[54] = "0b1011000100001101";
        ram[55] = "0b1010010101000111";
        ram[56] = "0b0011011100010000";
        ram[57] = "0b1011001001100110";
        ram[58] = "0b1011100111011000";
        ram[59] = "0b1011100011000100";
        ram[60] = "0b0001100011000100";
        ram[61] = "0b1011000000110111";
        ram[62] = "0b1010101000101111";
        ram[63] = "0b0011001010111110";
        ram[64] = "0b0011000110111110";
        ram[65] = "0b1011000000111110";
        ram[66] = "0b1011010001011100";
        ram[67] = "0b1011000001000010";
        ram[68] = "0b0010101011000111";
        ram[69] = "0b0010110010001101";
        ram[70] = "0b0011010110111000";
        ram[71] = "0b0000100111111010";
        ram[72] = "0b1011101101001100";
        ram[73] = "0b1011000001011001";
        ram[74] = "0b1011001100011111";
        ram[75] = "0b0011010100110110";
        ram[76] = "0b1011011011111110";
        ram[77] = "0b0011000100111110";
        ram[78] = "0b1011001110110100";
        ram[79] = "0b1011010000000110";
        ram[80] = "0b0010111001101110";
        ram[81] = "0b1011001101000110";
        ram[82] = "0b0011000101000001";
        ram[83] = "0b0010100101100100";
        ram[84] = "0b0010111010000111";
        ram[85] = "0b1010100100110000";
        ram[86] = "0b1011100001011011";
        ram[87] = "0b0011001000100011";
        ram[88] = "0b0011001001110001";
        ram[89] = "0b1011000011000000";
        ram[90] = "0b1011010000000010";
        ram[91] = "0b1011011100001011";
        ram[92] = "0b0011100000001001";
        ram[93] = "0b1011000010110111";
        ram[94] = "0b1011001110100101";
        ram[95] = "0b0011000100011000";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(test_layerfc_weight) {


static const unsigned DataWidth = 16;
static const unsigned AddressRange = 96;
static const unsigned AddressWidth = 7;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


test_layerfc_weight_ram* meminst;


SC_CTOR(test_layerfc_weight) {
meminst = new test_layerfc_weight_ram("test_layerfc_weight_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~test_layerfc_weight() {
    delete meminst;
}


};//endmodule
#endif
