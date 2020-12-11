// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _mean_24_11_s_HH_
#define _mean_24_11_s_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "test_hadd_16ns_16eOg.h"
#include "test_hdiv_16ns_16pcA.h"

namespace ap_rtl {

struct mean_24_11_s : public sc_module {
    // Port declarations 13
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<12> > input_r_address0;
    sc_out< sc_logic > input_r_ce0;
    sc_in< sc_lv<16> > input_r_q0;
    sc_out< sc_lv<5> > out_r_address0;
    sc_out< sc_logic > out_r_ce0;
    sc_out< sc_logic > out_r_we0;
    sc_out< sc_lv<16> > out_r_d0;
    sc_signal< sc_logic > ap_var_for_const0;
    sc_signal< sc_lv<16> > ap_var_for_const1;


    // Module declarations
    mean_24_11_s(sc_module_name name);
    SC_HAS_PROCESS(mean_24_11_s);

    ~mean_24_11_s();

    sc_trace_file* mVcdFile;

    test_hadd_16ns_16eOg<1,2,16,16,16>* test_hadd_16ns_16eOg_U49;
    test_hdiv_16ns_16pcA<1,5,16,16,16>* test_hdiv_16ns_16pcA_U50;
    sc_signal< sc_lv<10> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<9> > add_ln105_fu_142_p2;
    sc_signal< sc_lv<9> > add_ln105_reg_222;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<5> > i_fu_154_p2;
    sc_signal< sc_lv<5> > i_reg_230;
    sc_signal< sc_lv<64> > zext_ln113_fu_160_p1;
    sc_signal< sc_lv<64> > zext_ln113_reg_235;
    sc_signal< sc_lv<1> > icmp_ln105_fu_148_p2;
    sc_signal< sc_lv<4> > j_fu_170_p2;
    sc_signal< sc_lv<4> > j_reg_243;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<12> > mul_ln113_fu_190_p2;
    sc_signal< sc_lv<12> > mul_ln113_reg_248;
    sc_signal< sc_lv<1> > icmp_ln108_fu_164_p2;
    sc_signal< sc_lv<4> > k_fu_202_p2;
    sc_signal< sc_lv<4> > k_reg_256;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > icmp_ln110_fu_196_p2;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<16> > grp_fu_129_p2;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<5> > i_0_reg_60;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<9> > phi_mul_reg_71;
    sc_signal< sc_lv<16> > m_0_reg_83;
    sc_signal< sc_lv<4> > j_0_reg_95;
    sc_signal< sc_lv<16> > m_1_reg_106;
    sc_signal< sc_lv<4> > k_0_reg_118;
    sc_signal< sc_lv<64> > zext_ln113_4_fu_217_p1;
    sc_signal< sc_lv<16> > grp_fu_135_p2;
    sc_signal< sc_lv<9> > zext_ln113_1_fu_176_p1;
    sc_signal< sc_lv<9> > add_ln113_fu_180_p2;
    sc_signal< sc_lv<9> > mul_ln113_fu_190_p0;
    sc_signal< sc_lv<12> > zext_ln113_3_fu_208_p1;
    sc_signal< sc_lv<12> > add_ln113_1_fu_212_p2;
    sc_signal< sc_lv<10> > ap_NS_fsm;
    sc_signal< sc_lv<12> > mul_ln113_fu_190_p00;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<10> ap_ST_fsm_state1;
    static const sc_lv<10> ap_ST_fsm_state2;
    static const sc_lv<10> ap_ST_fsm_state3;
    static const sc_lv<10> ap_ST_fsm_state4;
    static const sc_lv<10> ap_ST_fsm_state5;
    static const sc_lv<10> ap_ST_fsm_state6;
    static const sc_lv<10> ap_ST_fsm_state7;
    static const sc_lv<10> ap_ST_fsm_state8;
    static const sc_lv<10> ap_ST_fsm_state9;
    static const sc_lv<10> ap_ST_fsm_state10;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<9> ap_const_lv9_0;
    static const sc_lv<16> ap_const_lv16_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<16> ap_const_lv16_5790;
    static const sc_lv<9> ap_const_lv9_B;
    static const sc_lv<5> ap_const_lv5_18;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<4> ap_const_lv4_B;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<12> ap_const_lv12_B;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_var_for_const1();
    void thread_ap_clk_no_reset_();
    void thread_add_ln105_fu_142_p2();
    void thread_add_ln113_1_fu_212_p2();
    void thread_add_ln113_fu_180_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_i_fu_154_p2();
    void thread_icmp_ln105_fu_148_p2();
    void thread_icmp_ln108_fu_164_p2();
    void thread_icmp_ln110_fu_196_p2();
    void thread_input_r_address0();
    void thread_input_r_ce0();
    void thread_j_fu_170_p2();
    void thread_k_fu_202_p2();
    void thread_mul_ln113_fu_190_p0();
    void thread_mul_ln113_fu_190_p00();
    void thread_mul_ln113_fu_190_p2();
    void thread_out_r_address0();
    void thread_out_r_ce0();
    void thread_out_r_d0();
    void thread_out_r_we0();
    void thread_zext_ln113_1_fu_176_p1();
    void thread_zext_ln113_3_fu_208_p1();
    void thread_zext_ln113_4_fu_217_p1();
    void thread_zext_ln113_fu_160_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif