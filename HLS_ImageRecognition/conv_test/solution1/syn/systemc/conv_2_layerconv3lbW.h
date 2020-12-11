// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __conv_2_layerconv3lbW_H__
#define __conv_2_layerconv3lbW_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct conv_2_layerconv3lbW_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 16;
  static const unsigned AddressRange = 24;
  static const unsigned AddressWidth = 5;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(conv_2_layerconv3lbW_ram) {
        ram[0] = "0b1011001000000001";
        ram[1] = "0b1010100011110111";
        ram[2] = "0b1010000011110111";
        ram[3] = "0b0011111100110000";
        ram[4] = "0b1011010010001010";
        ram[5] = "0b1011000000110010";
        ram[6] = "0b1011010101110000";
        ram[7] = "0b1011010001111111";
        ram[8] = "0b0011111111000100";
        ram[9] = "0b1010110000110011";
        ram[10] = "0b1010100101100000";
        ram[11] = "0b1010100010101001";
        ram[12] = "0b1010110100001110";
        ram[13] = "0b0011100000001010";
        ram[14] = "0b0011101110011010";
        ram[15] = "0b1011011000110011";
        ram[16] = "0b1011000001111000";
        ram[17] = "0b1011000011101000";
        ram[18] = "0b1010011010101000";
        ram[19] = "0b1010111011000111";
        ram[20] = "0b1010110100100010";
        ram[21] = "0b1011010000001011";
        ram[22] = "0b1011000001100001";
        ram[23] = "0b1010110101000110";


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


SC_MODULE(conv_2_layerconv3lbW) {


static const unsigned DataWidth = 16;
static const unsigned AddressRange = 24;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


conv_2_layerconv3lbW_ram* meminst;


SC_CTOR(conv_2_layerconv3lbW) {
meminst = new conv_2_layerconv3lbW_ram("conv_2_layerconv3lbW_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~conv_2_layerconv3lbW() {
    delete meminst;
}


};//endmodule
#endif
