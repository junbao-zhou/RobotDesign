// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __conv_layerconv2_0ibs_H__
#define __conv_layerconv2_0ibs_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct conv_layerconv2_0ibs_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 16;
  static const unsigned AddressRange = 16;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(conv_layerconv2_0ibs_ram) {
        ram[0] = "0b1010111000100000";
        ram[1] = "0b1011001011001101";
        ram[2] = "0b1010101011010110";
        ram[3] = "0b1011000000110001";
        ram[4] = "0b1010111101100011";
        ram[5] = "0b1010100101110100";
        ram[6] = "0b0010011001011001";
        ram[7] = "0b1010011110111011";
        ram[8] = "0b0010110100111100";
        ram[9] = "0b1010101100110010";
        ram[10] = "0b1010100101100000";
        ram[11] = "0b0010111000101000";
        ram[12] = "0b0011000000110011";
        ram[13] = "0b1010110100101010";
        ram[14] = "0b0010011100111000";
        ram[15] = "0b1010010110100010";


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


SC_MODULE(conv_layerconv2_0ibs) {


static const unsigned DataWidth = 16;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


conv_layerconv2_0ibs_ram* meminst;


SC_CTOR(conv_layerconv2_0ibs) {
meminst = new conv_layerconv2_0ibs_ram("conv_layerconv2_0ibs_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~conv_layerconv2_0ibs() {
    delete meminst;
}


};//endmodule
#endif
