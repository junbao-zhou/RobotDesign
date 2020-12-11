// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __test_layerfc_bias_H__
#define __test_layerfc_bias_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct test_layerfc_bias_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 16;
  static const unsigned AddressRange = 12;
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


   SC_CTOR(test_layerfc_bias_ram) {
        ram[0] = "0b1011000000100100";
        ram[1] = "0b0011100000110100";
        ram[2] = "0b1010000110100010";
        ram[3] = "0b0010111110101001";
        ram[4] = "0b1010100010000001";
        ram[5] = "0b0010100111110111";
        ram[6] = "0b0011001011110110";
        ram[7] = "0b1011100010101010";
        ram[8] = "0b0011010001100110";
        ram[9] = "0b1011011110101011";
        ram[10] = "0b1011110010001111";
        ram[11] = "0b0011100111100111";


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


SC_MODULE(test_layerfc_bias) {


static const unsigned DataWidth = 16;
static const unsigned AddressRange = 12;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


test_layerfc_bias_ram* meminst;


SC_CTOR(test_layerfc_bias) {
meminst = new test_layerfc_bias_ram("test_layerfc_bias_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~test_layerfc_bias() {
    delete meminst;
}


};//endmodule
#endif
