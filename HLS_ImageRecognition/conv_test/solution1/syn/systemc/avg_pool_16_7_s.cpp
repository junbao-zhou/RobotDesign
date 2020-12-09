// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "avg_pool_16_7_s.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic avg_pool_16_7_s::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic avg_pool_16_7_s::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state1 = "1";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state2 = "10";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state3 = "100";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state4 = "1000";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state5 = "10000";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state6 = "100000";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state7 = "1000000";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state8 = "10000000";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state9 = "100000000";
const sc_lv<10> avg_pool_16_7_s::ap_ST_fsm_state10 = "1000000000";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_1 = "1";
const sc_lv<1> avg_pool_16_7_s::ap_const_lv1_0 = "0";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_2 = "10";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_3 = "11";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_4 = "100";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_5 = "101";
const sc_lv<5> avg_pool_16_7_s::ap_const_lv5_0 = "00000";
const sc_lv<32> avg_pool_16_7_s::ap_const_lv32_9 = "1001";
const sc_lv<16> avg_pool_16_7_s::ap_const_lv16_0 = "0000000000000000";
const sc_lv<1> avg_pool_16_7_s::ap_const_lv1_1 = "1";
const sc_lv<3> avg_pool_16_7_s::ap_const_lv3_0 = "000";
const sc_lv<16> avg_pool_16_7_s::ap_const_lv16_5220 = "101001000100000";
const sc_lv<5> avg_pool_16_7_s::ap_const_lv5_10 = "10000";
const sc_lv<5> avg_pool_16_7_s::ap_const_lv5_1 = "1";
const sc_lv<3> avg_pool_16_7_s::ap_const_lv3_7 = "111";
const sc_lv<3> avg_pool_16_7_s::ap_const_lv3_1 = "1";
const bool avg_pool_16_7_s::ap_const_boolean_1 = true;

avg_pool_16_7_s::avg_pool_16_7_s(sc_module_name name) : sc_module(name), mVcdFile(0) {
    test_hadd_16ns_16eOg_U34 = new test_hadd_16ns_16eOg<1,2,16,16,16>("test_hadd_16ns_16eOg_U34");
    test_hadd_16ns_16eOg_U34->clk(ap_clk);
    test_hadd_16ns_16eOg_U34->reset(ap_rst);
    test_hadd_16ns_16eOg_U34->din0(m_1_reg_92);
    test_hadd_16ns_16eOg_U34->din1(in_r_q0);
    test_hadd_16ns_16eOg_U34->ce(ap_var_for_const0);
    test_hadd_16ns_16eOg_U34->dout(grp_fu_115_p2);
    test_hdiv_16ns_16kbM_U35 = new test_hdiv_16ns_16kbM<1,5,16,16,16>("test_hdiv_16ns_16kbM_U35");
    test_hdiv_16ns_16kbM_U35->clk(ap_clk);
    test_hdiv_16ns_16kbM_U35->reset(ap_rst);
    test_hdiv_16ns_16kbM_U35->din0(m_0_reg_69);
    test_hdiv_16ns_16kbM_U35->din1(ap_var_for_const1);
    test_hdiv_16ns_16kbM_U35->ce(ap_var_for_const0);
    test_hdiv_16ns_16kbM_U35->dout(grp_fu_121_p2);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln104_1_fu_229_p2);
    sensitive << ( sub_ln104_1_reg_265 );
    sensitive << ( zext_ln104_4_fu_225_p1 );

    SC_METHOD(thread_add_ln104_fu_186_p2);
    sensitive << ( sext_ln104_reg_252 );
    sensitive << ( zext_ln104_3_fu_182_p1 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state10);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state4);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state5);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state6);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln96_fu_128_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln96_fu_128_p2 );

    SC_METHOD(thread_i_fu_134_p2);
    sensitive << ( i_0_reg_58 );

    SC_METHOD(thread_icmp_ln101_fu_213_p2);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( k_0_reg_104 );

    SC_METHOD(thread_icmp_ln96_fu_128_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( i_0_reg_58 );

    SC_METHOD(thread_icmp_ln99_fu_170_p2);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( j_0_reg_81 );

    SC_METHOD(thread_in_r_address0);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( zext_ln104_5_fu_234_p1 );

    SC_METHOD(thread_in_r_ce0);
    sensitive << ( ap_CS_fsm_state4 );

    SC_METHOD(thread_j_fu_176_p2);
    sensitive << ( j_0_reg_81 );

    SC_METHOD(thread_k_fu_219_p2);
    sensitive << ( k_0_reg_104 );

    SC_METHOD(thread_out_r_address0);
    sensitive << ( zext_ln104_reg_247 );
    sensitive << ( ap_CS_fsm_state10 );

    SC_METHOD(thread_out_r_ce0);
    sensitive << ( ap_CS_fsm_state10 );

    SC_METHOD(thread_out_r_d0);
    sensitive << ( ap_CS_fsm_state10 );
    sensitive << ( grp_fu_121_p2 );

    SC_METHOD(thread_out_r_we0);
    sensitive << ( ap_CS_fsm_state10 );

    SC_METHOD(thread_p_shl1_cast_fu_199_p3);
    sensitive << ( trunc_ln104_fu_195_p1 );

    SC_METHOD(thread_sext_ln104_1_fu_191_p1);
    sensitive << ( add_ln104_fu_186_p2 );

    SC_METHOD(thread_sext_ln104_fu_166_p1);
    sensitive << ( sub_ln104_fu_160_p2 );

    SC_METHOD(thread_sub_ln104_1_fu_207_p2);
    sensitive << ( p_shl1_cast_fu_199_p3 );
    sensitive << ( sext_ln104_1_fu_191_p1 );

    SC_METHOD(thread_sub_ln104_fu_160_p2);
    sensitive << ( zext_ln104_2_fu_156_p1 );
    sensitive << ( zext_ln104_1_fu_144_p1 );

    SC_METHOD(thread_tmp_s_fu_148_p3);
    sensitive << ( i_0_reg_58 );

    SC_METHOD(thread_trunc_ln104_fu_195_p1);
    sensitive << ( add_ln104_fu_186_p2 );

    SC_METHOD(thread_zext_ln104_1_fu_144_p1);
    sensitive << ( i_0_reg_58 );

    SC_METHOD(thread_zext_ln104_2_fu_156_p1);
    sensitive << ( tmp_s_fu_148_p3 );

    SC_METHOD(thread_zext_ln104_3_fu_182_p1);
    sensitive << ( j_0_reg_81 );

    SC_METHOD(thread_zext_ln104_4_fu_225_p1);
    sensitive << ( k_0_reg_104 );

    SC_METHOD(thread_zext_ln104_5_fu_234_p1);
    sensitive << ( add_ln104_1_fu_229_p2 );

    SC_METHOD(thread_zext_ln104_fu_140_p1);
    sensitive << ( i_0_reg_58 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln96_fu_128_p2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln99_fu_170_p2 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln101_fu_213_p2 );

    SC_THREAD(thread_ap_var_for_const0);

    SC_THREAD(thread_ap_var_for_const1);

    ap_CS_fsm = "0000000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "avg_pool_16_7_s_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, in_r_address0, "(port)in_r_address0");
    sc_trace(mVcdFile, in_r_ce0, "(port)in_r_ce0");
    sc_trace(mVcdFile, in_r_q0, "(port)in_r_q0");
    sc_trace(mVcdFile, out_r_address0, "(port)out_r_address0");
    sc_trace(mVcdFile, out_r_ce0, "(port)out_r_ce0");
    sc_trace(mVcdFile, out_r_we0, "(port)out_r_we0");
    sc_trace(mVcdFile, out_r_d0, "(port)out_r_d0");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, i_fu_134_p2, "i_fu_134_p2");
    sc_trace(mVcdFile, i_reg_242, "i_reg_242");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, zext_ln104_fu_140_p1, "zext_ln104_fu_140_p1");
    sc_trace(mVcdFile, zext_ln104_reg_247, "zext_ln104_reg_247");
    sc_trace(mVcdFile, icmp_ln96_fu_128_p2, "icmp_ln96_fu_128_p2");
    sc_trace(mVcdFile, sext_ln104_fu_166_p1, "sext_ln104_fu_166_p1");
    sc_trace(mVcdFile, sext_ln104_reg_252, "sext_ln104_reg_252");
    sc_trace(mVcdFile, j_fu_176_p2, "j_fu_176_p2");
    sc_trace(mVcdFile, j_reg_260, "j_reg_260");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, sub_ln104_1_fu_207_p2, "sub_ln104_1_fu_207_p2");
    sc_trace(mVcdFile, sub_ln104_1_reg_265, "sub_ln104_1_reg_265");
    sc_trace(mVcdFile, icmp_ln99_fu_170_p2, "icmp_ln99_fu_170_p2");
    sc_trace(mVcdFile, k_fu_219_p2, "k_fu_219_p2");
    sc_trace(mVcdFile, k_reg_273, "k_reg_273");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, icmp_ln101_fu_213_p2, "icmp_ln101_fu_213_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, grp_fu_115_p2, "grp_fu_115_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state6, "ap_CS_fsm_state6");
    sc_trace(mVcdFile, i_0_reg_58, "i_0_reg_58");
    sc_trace(mVcdFile, ap_CS_fsm_state10, "ap_CS_fsm_state10");
    sc_trace(mVcdFile, m_0_reg_69, "m_0_reg_69");
    sc_trace(mVcdFile, j_0_reg_81, "j_0_reg_81");
    sc_trace(mVcdFile, m_1_reg_92, "m_1_reg_92");
    sc_trace(mVcdFile, k_0_reg_104, "k_0_reg_104");
    sc_trace(mVcdFile, zext_ln104_5_fu_234_p1, "zext_ln104_5_fu_234_p1");
    sc_trace(mVcdFile, grp_fu_121_p2, "grp_fu_121_p2");
    sc_trace(mVcdFile, tmp_s_fu_148_p3, "tmp_s_fu_148_p3");
    sc_trace(mVcdFile, zext_ln104_2_fu_156_p1, "zext_ln104_2_fu_156_p1");
    sc_trace(mVcdFile, zext_ln104_1_fu_144_p1, "zext_ln104_1_fu_144_p1");
    sc_trace(mVcdFile, sub_ln104_fu_160_p2, "sub_ln104_fu_160_p2");
    sc_trace(mVcdFile, zext_ln104_3_fu_182_p1, "zext_ln104_3_fu_182_p1");
    sc_trace(mVcdFile, add_ln104_fu_186_p2, "add_ln104_fu_186_p2");
    sc_trace(mVcdFile, trunc_ln104_fu_195_p1, "trunc_ln104_fu_195_p1");
    sc_trace(mVcdFile, p_shl1_cast_fu_199_p3, "p_shl1_cast_fu_199_p3");
    sc_trace(mVcdFile, sext_ln104_1_fu_191_p1, "sext_ln104_1_fu_191_p1");
    sc_trace(mVcdFile, zext_ln104_4_fu_225_p1, "zext_ln104_4_fu_225_p1");
    sc_trace(mVcdFile, add_ln104_1_fu_229_p2, "add_ln104_1_fu_229_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

avg_pool_16_7_s::~avg_pool_16_7_s() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete test_hadd_16ns_16eOg_U34;
    delete test_hdiv_16ns_16kbM_U35;
}

void avg_pool_16_7_s::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_logic_1;
}

void avg_pool_16_7_s::thread_ap_var_for_const1() {
    ap_var_for_const1 = ap_const_lv16_5220;
}

void avg_pool_16_7_s::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state10.read())) {
        i_0_reg_58 = i_reg_242.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        i_0_reg_58 = ap_const_lv5_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln101_fu_213_p2.read(), ap_const_lv1_1))) {
        j_0_reg_81 = j_reg_260.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(icmp_ln96_fu_128_p2.read(), ap_const_lv1_0))) {
        j_0_reg_81 = ap_const_lv3_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln99_fu_170_p2.read()))) {
        k_0_reg_104 = ap_const_lv3_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        k_0_reg_104 = k_reg_273.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln101_fu_213_p2.read(), ap_const_lv1_1))) {
        m_0_reg_69 = m_1_reg_92.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(icmp_ln96_fu_128_p2.read(), ap_const_lv1_0))) {
        m_0_reg_69 = ap_const_lv16_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln99_fu_170_p2.read()))) {
        m_1_reg_92 = m_0_reg_69.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        m_1_reg_92 = grp_fu_115_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        i_reg_242 = i_fu_134_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        j_reg_260 = j_fu_176_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        k_reg_273 = k_fu_219_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln96_fu_128_p2.read(), ap_const_lv1_0))) {
        sext_ln104_reg_252 = sext_ln104_fu_166_p1.read();
        zext_ln104_reg_247 = zext_ln104_fu_140_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln99_fu_170_p2.read()))) {
        sub_ln104_1_reg_265 = sub_ln104_1_fu_207_p2.read();
    }
}

void avg_pool_16_7_s::thread_add_ln104_1_fu_229_p2() {
    add_ln104_1_fu_229_p2 = (!sub_ln104_1_reg_265.read().is_01() || !zext_ln104_4_fu_225_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(sub_ln104_1_reg_265.read()) + sc_biguint<11>(zext_ln104_4_fu_225_p1.read()));
}

void avg_pool_16_7_s::thread_add_ln104_fu_186_p2() {
    add_ln104_fu_186_p2 = (!zext_ln104_3_fu_182_p1.read().is_01() || !sext_ln104_reg_252.read().is_01())? sc_lv<10>(): (sc_biguint<10>(zext_ln104_3_fu_182_p1.read()) + sc_bigint<10>(sext_ln104_reg_252.read()));
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state10() {
    ap_CS_fsm_state10 = ap_CS_fsm.read()[9];
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void avg_pool_16_7_s::thread_ap_CS_fsm_state6() {
    ap_CS_fsm_state6 = ap_CS_fsm.read()[5];
}

void avg_pool_16_7_s::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(icmp_ln96_fu_128_p2.read(), ap_const_lv1_1)))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void avg_pool_16_7_s::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void avg_pool_16_7_s::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln96_fu_128_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void avg_pool_16_7_s::thread_i_fu_134_p2() {
    i_fu_134_p2 = (!i_0_reg_58.read().is_01() || !ap_const_lv5_1.is_01())? sc_lv<5>(): (sc_biguint<5>(i_0_reg_58.read()) + sc_biguint<5>(ap_const_lv5_1));
}

void avg_pool_16_7_s::thread_icmp_ln101_fu_213_p2() {
    icmp_ln101_fu_213_p2 = (!k_0_reg_104.read().is_01() || !ap_const_lv3_7.is_01())? sc_lv<1>(): sc_lv<1>(k_0_reg_104.read() == ap_const_lv3_7);
}

void avg_pool_16_7_s::thread_icmp_ln96_fu_128_p2() {
    icmp_ln96_fu_128_p2 = (!i_0_reg_58.read().is_01() || !ap_const_lv5_10.is_01())? sc_lv<1>(): sc_lv<1>(i_0_reg_58.read() == ap_const_lv5_10);
}

void avg_pool_16_7_s::thread_icmp_ln99_fu_170_p2() {
    icmp_ln99_fu_170_p2 = (!j_0_reg_81.read().is_01() || !ap_const_lv3_7.is_01())? sc_lv<1>(): sc_lv<1>(j_0_reg_81.read() == ap_const_lv3_7);
}

void avg_pool_16_7_s::thread_in_r_address0() {
    in_r_address0 =  (sc_lv<10>) (zext_ln104_5_fu_234_p1.read());
}

void avg_pool_16_7_s::thread_in_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        in_r_ce0 = ap_const_logic_1;
    } else {
        in_r_ce0 = ap_const_logic_0;
    }
}

void avg_pool_16_7_s::thread_j_fu_176_p2() {
    j_fu_176_p2 = (!j_0_reg_81.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(j_0_reg_81.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void avg_pool_16_7_s::thread_k_fu_219_p2() {
    k_fu_219_p2 = (!k_0_reg_104.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(k_0_reg_104.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void avg_pool_16_7_s::thread_out_r_address0() {
    out_r_address0 =  (sc_lv<4>) (zext_ln104_reg_247.read());
}

void avg_pool_16_7_s::thread_out_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state10.read())) {
        out_r_ce0 = ap_const_logic_1;
    } else {
        out_r_ce0 = ap_const_logic_0;
    }
}

void avg_pool_16_7_s::thread_out_r_d0() {
    out_r_d0 = grp_fu_121_p2.read();
}

void avg_pool_16_7_s::thread_out_r_we0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state10.read())) {
        out_r_we0 = ap_const_logic_1;
    } else {
        out_r_we0 = ap_const_logic_0;
    }
}

void avg_pool_16_7_s::thread_p_shl1_cast_fu_199_p3() {
    p_shl1_cast_fu_199_p3 = esl_concat<8,3>(trunc_ln104_fu_195_p1.read(), ap_const_lv3_0);
}

void avg_pool_16_7_s::thread_sext_ln104_1_fu_191_p1() {
    sext_ln104_1_fu_191_p1 = esl_sext<11,10>(add_ln104_fu_186_p2.read());
}

void avg_pool_16_7_s::thread_sext_ln104_fu_166_p1() {
    sext_ln104_fu_166_p1 = esl_sext<10,9>(sub_ln104_fu_160_p2.read());
}

void avg_pool_16_7_s::thread_sub_ln104_1_fu_207_p2() {
    sub_ln104_1_fu_207_p2 = (!p_shl1_cast_fu_199_p3.read().is_01() || !sext_ln104_1_fu_191_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(p_shl1_cast_fu_199_p3.read()) - sc_bigint<11>(sext_ln104_1_fu_191_p1.read()));
}

void avg_pool_16_7_s::thread_sub_ln104_fu_160_p2() {
    sub_ln104_fu_160_p2 = (!zext_ln104_2_fu_156_p1.read().is_01() || !zext_ln104_1_fu_144_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(zext_ln104_2_fu_156_p1.read()) - sc_biguint<9>(zext_ln104_1_fu_144_p1.read()));
}

void avg_pool_16_7_s::thread_tmp_s_fu_148_p3() {
    tmp_s_fu_148_p3 = esl_concat<5,3>(i_0_reg_58.read(), ap_const_lv3_0);
}

void avg_pool_16_7_s::thread_trunc_ln104_fu_195_p1() {
    trunc_ln104_fu_195_p1 = add_ln104_fu_186_p2.read().range(8-1, 0);
}

void avg_pool_16_7_s::thread_zext_ln104_1_fu_144_p1() {
    zext_ln104_1_fu_144_p1 = esl_zext<9,5>(i_0_reg_58.read());
}

void avg_pool_16_7_s::thread_zext_ln104_2_fu_156_p1() {
    zext_ln104_2_fu_156_p1 = esl_zext<9,8>(tmp_s_fu_148_p3.read());
}

void avg_pool_16_7_s::thread_zext_ln104_3_fu_182_p1() {
    zext_ln104_3_fu_182_p1 = esl_zext<10,3>(j_0_reg_81.read());
}

void avg_pool_16_7_s::thread_zext_ln104_4_fu_225_p1() {
    zext_ln104_4_fu_225_p1 = esl_zext<11,3>(k_0_reg_104.read());
}

void avg_pool_16_7_s::thread_zext_ln104_5_fu_234_p1() {
    zext_ln104_5_fu_234_p1 = esl_zext<64,11>(add_ln104_1_fu_229_p2.read());
}

void avg_pool_16_7_s::thread_zext_ln104_fu_140_p1() {
    zext_ln104_fu_140_p1 = esl_zext<64,5>(i_0_reg_58.read());
}

void avg_pool_16_7_s::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln96_fu_128_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln99_fu_170_p2.read()))) {
                ap_NS_fsm = ap_ST_fsm_state4;
            } else {
                ap_NS_fsm = ap_ST_fsm_state7;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(icmp_ln101_fu_213_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state6;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_fsm_state9;
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_fsm_state10;
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_fsm_state2;
            break;
        default : 
            ap_NS_fsm = "XXXXXXXXXX";
            break;
    }
}

}
