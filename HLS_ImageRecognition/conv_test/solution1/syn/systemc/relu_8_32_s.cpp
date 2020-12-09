// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "relu_8_32_s.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic relu_8_32_s::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic relu_8_32_s::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state1 = "1";
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state2 = "10";
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state3 = "100";
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state4 = "1000";
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state5 = "10000";
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state6 = "100000";
const sc_lv<7> relu_8_32_s::ap_ST_fsm_state7 = "1000000";
const sc_lv<32> relu_8_32_s::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> relu_8_32_s::ap_const_lv32_1 = "1";
const sc_lv<1> relu_8_32_s::ap_const_lv1_0 = "0";
const sc_lv<32> relu_8_32_s::ap_const_lv32_2 = "10";
const sc_lv<32> relu_8_32_s::ap_const_lv32_3 = "11";
const sc_lv<32> relu_8_32_s::ap_const_lv32_4 = "100";
const sc_lv<32> relu_8_32_s::ap_const_lv32_5 = "101";
const sc_lv<4> relu_8_32_s::ap_const_lv4_0 = "0000";
const sc_lv<1> relu_8_32_s::ap_const_lv1_1 = "1";
const sc_lv<6> relu_8_32_s::ap_const_lv6_0 = "000000";
const sc_lv<32> relu_8_32_s::ap_const_lv32_6 = "110";
const sc_lv<16> relu_8_32_s::ap_const_lv16_0 = "0000000000000000";
const sc_lv<4> relu_8_32_s::ap_const_lv4_8 = "1000";
const sc_lv<4> relu_8_32_s::ap_const_lv4_1 = "1";
const sc_lv<5> relu_8_32_s::ap_const_lv5_0 = "00000";
const sc_lv<6> relu_8_32_s::ap_const_lv6_20 = "100000";
const sc_lv<6> relu_8_32_s::ap_const_lv6_1 = "1";
const sc_lv<5> relu_8_32_s::ap_const_lv5_2 = "10";
const bool relu_8_32_s::ap_const_boolean_1 = true;

relu_8_32_s::relu_8_32_s(sc_module_name name) : sc_module(name), mVcdFile(0) {
    test_hcmp_16ns_16g8j_U12 = new test_hcmp_16ns_16g8j<1,1,16,16,1>("test_hcmp_16ns_16g8j_U12");
    test_hcmp_16ns_16g8j_U12->din0(in_load_reg_226);
    test_hcmp_16ns_16g8j_U12->din1(ap_var_for_const0);
    test_hcmp_16ns_16g8j_U12->opcode(ap_var_for_const1);
    test_hcmp_16ns_16g8j_U12->dout(tmp_fu_91_p2);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln117_1_fu_165_p2);
    sensitive << ( tmp_8_cast_reg_203 );
    sensitive << ( zext_ln117_1_fu_161_p1 );

    SC_METHOD(thread_add_ln117_fu_136_p2);
    sensitive << ( zext_ln115_reg_190 );
    sensitive << ( zext_ln117_fu_132_p1 );

    SC_METHOD(thread_ap_CS_fsm_state1);
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

    SC_METHOD(thread_ap_CS_fsm_state7);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln114_fu_96_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln114_fu_96_p2 );

    SC_METHOD(thread_c_fu_155_p2);
    sensitive << ( c_0_reg_80 );

    SC_METHOD(thread_icmp_ln114_fu_96_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( m_0_reg_58 );

    SC_METHOD(thread_icmp_ln115_fu_120_p2);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( r_0_reg_69 );

    SC_METHOD(thread_icmp_ln116_fu_149_p2);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( c_0_reg_80 );

    SC_METHOD(thread_in_r_address0);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( zext_ln117_2_fu_170_p1 );

    SC_METHOD(thread_in_r_ce0);
    sensitive << ( ap_CS_fsm_state4 );

    SC_METHOD(thread_m_fu_102_p2);
    sensitive << ( m_0_reg_58 );

    SC_METHOD(thread_out_r_address0);
    sensitive << ( zext_ln117_2_reg_216 );
    sensitive << ( ap_CS_fsm_state7 );

    SC_METHOD(thread_out_r_ce0);
    sensitive << ( ap_CS_fsm_state7 );

    SC_METHOD(thread_out_r_d0);
    sensitive << ( select_ln117_reg_232 );
    sensitive << ( ap_CS_fsm_state7 );

    SC_METHOD(thread_out_r_we0);
    sensitive << ( ap_CS_fsm_state7 );

    SC_METHOD(thread_r_fu_126_p2);
    sensitive << ( r_0_reg_69 );

    SC_METHOD(thread_select_ln117_fu_175_p3);
    sensitive << ( in_load_reg_226 );
    sensitive << ( tmp_fu_91_p2 );

    SC_METHOD(thread_tmp_6_fu_108_p3);
    sensitive << ( m_0_reg_58 );

    SC_METHOD(thread_tmp_8_cast_fu_141_p3);
    sensitive << ( add_ln117_fu_136_p2 );

    SC_METHOD(thread_zext_ln115_fu_116_p1);
    sensitive << ( tmp_6_fu_108_p3 );

    SC_METHOD(thread_zext_ln117_1_fu_161_p1);
    sensitive << ( c_0_reg_80 );

    SC_METHOD(thread_zext_ln117_2_fu_170_p1);
    sensitive << ( add_ln117_1_fu_165_p2 );

    SC_METHOD(thread_zext_ln117_fu_132_p1);
    sensitive << ( r_0_reg_69 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln114_fu_96_p2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln115_fu_120_p2 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln116_fu_149_p2 );

    SC_THREAD(thread_ap_var_for_const0);

    SC_THREAD(thread_ap_var_for_const1);

    ap_CS_fsm = "0000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "relu_8_32_s_sc_trace_" << apTFileNum ++;
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
    sc_trace(mVcdFile, m_fu_102_p2, "m_fu_102_p2");
    sc_trace(mVcdFile, m_reg_185, "m_reg_185");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, zext_ln115_fu_116_p1, "zext_ln115_fu_116_p1");
    sc_trace(mVcdFile, zext_ln115_reg_190, "zext_ln115_reg_190");
    sc_trace(mVcdFile, icmp_ln114_fu_96_p2, "icmp_ln114_fu_96_p2");
    sc_trace(mVcdFile, r_fu_126_p2, "r_fu_126_p2");
    sc_trace(mVcdFile, r_reg_198, "r_reg_198");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, tmp_8_cast_fu_141_p3, "tmp_8_cast_fu_141_p3");
    sc_trace(mVcdFile, tmp_8_cast_reg_203, "tmp_8_cast_reg_203");
    sc_trace(mVcdFile, icmp_ln115_fu_120_p2, "icmp_ln115_fu_120_p2");
    sc_trace(mVcdFile, c_fu_155_p2, "c_fu_155_p2");
    sc_trace(mVcdFile, c_reg_211, "c_reg_211");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, zext_ln117_2_fu_170_p1, "zext_ln117_2_fu_170_p1");
    sc_trace(mVcdFile, zext_ln117_2_reg_216, "zext_ln117_2_reg_216");
    sc_trace(mVcdFile, icmp_ln116_fu_149_p2, "icmp_ln116_fu_149_p2");
    sc_trace(mVcdFile, in_load_reg_226, "in_load_reg_226");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, select_ln117_fu_175_p3, "select_ln117_fu_175_p3");
    sc_trace(mVcdFile, select_ln117_reg_232, "select_ln117_reg_232");
    sc_trace(mVcdFile, ap_CS_fsm_state6, "ap_CS_fsm_state6");
    sc_trace(mVcdFile, m_0_reg_58, "m_0_reg_58");
    sc_trace(mVcdFile, r_0_reg_69, "r_0_reg_69");
    sc_trace(mVcdFile, c_0_reg_80, "c_0_reg_80");
    sc_trace(mVcdFile, ap_CS_fsm_state7, "ap_CS_fsm_state7");
    sc_trace(mVcdFile, tmp_6_fu_108_p3, "tmp_6_fu_108_p3");
    sc_trace(mVcdFile, zext_ln117_fu_132_p1, "zext_ln117_fu_132_p1");
    sc_trace(mVcdFile, add_ln117_fu_136_p2, "add_ln117_fu_136_p2");
    sc_trace(mVcdFile, zext_ln117_1_fu_161_p1, "zext_ln117_1_fu_161_p1");
    sc_trace(mVcdFile, add_ln117_1_fu_165_p2, "add_ln117_1_fu_165_p2");
    sc_trace(mVcdFile, tmp_fu_91_p2, "tmp_fu_91_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

relu_8_32_s::~relu_8_32_s() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete test_hcmp_16ns_16g8j_U12;
}

void relu_8_32_s::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_lv16_0;
}

void relu_8_32_s::thread_ap_var_for_const1() {
    ap_var_for_const1 = ap_const_lv5_2;
}

void relu_8_32_s::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln115_fu_120_p2.read()))) {
        c_0_reg_80 = ap_const_lv6_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        c_0_reg_80 = c_reg_211.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(icmp_ln115_fu_120_p2.read(), ap_const_lv1_1))) {
        m_0_reg_58 = m_reg_185.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        m_0_reg_58 = ap_const_lv4_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln116_fu_149_p2.read(), ap_const_lv1_1))) {
        r_0_reg_69 = r_reg_198.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(icmp_ln114_fu_96_p2.read(), ap_const_lv1_0))) {
        r_0_reg_69 = ap_const_lv6_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        c_reg_211 = c_fu_155_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        in_load_reg_226 = in_r_q0.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        m_reg_185 = m_fu_102_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        r_reg_198 = r_fu_126_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        select_ln117_reg_232 = select_ln117_fu_175_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln115_fu_120_p2.read()))) {
        tmp_8_cast_reg_203 = tmp_8_cast_fu_141_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln114_fu_96_p2.read(), ap_const_lv1_0))) {
        zext_ln115_reg_190 = zext_ln115_fu_116_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln116_fu_149_p2.read()))) {
        zext_ln117_2_reg_216 = zext_ln117_2_fu_170_p1.read();
    }
}

void relu_8_32_s::thread_add_ln117_1_fu_165_p2() {
    add_ln117_1_fu_165_p2 = (!tmp_8_cast_reg_203.read().is_01() || !zext_ln117_1_fu_161_p1.read().is_01())? sc_lv<15>(): (sc_biguint<15>(tmp_8_cast_reg_203.read()) + sc_biguint<15>(zext_ln117_1_fu_161_p1.read()));
}

void relu_8_32_s::thread_add_ln117_fu_136_p2() {
    add_ln117_fu_136_p2 = (!zext_ln117_fu_132_p1.read().is_01() || !zext_ln115_reg_190.read().is_01())? sc_lv<10>(): (sc_biguint<10>(zext_ln117_fu_132_p1.read()) + sc_biguint<10>(zext_ln115_reg_190.read()));
}

void relu_8_32_s::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void relu_8_32_s::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void relu_8_32_s::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void relu_8_32_s::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void relu_8_32_s::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void relu_8_32_s::thread_ap_CS_fsm_state6() {
    ap_CS_fsm_state6 = ap_CS_fsm.read()[5];
}

void relu_8_32_s::thread_ap_CS_fsm_state7() {
    ap_CS_fsm_state7 = ap_CS_fsm.read()[6];
}

void relu_8_32_s::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(icmp_ln114_fu_96_p2.read(), ap_const_lv1_1)))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void relu_8_32_s::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void relu_8_32_s::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln114_fu_96_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void relu_8_32_s::thread_c_fu_155_p2() {
    c_fu_155_p2 = (!c_0_reg_80.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(c_0_reg_80.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void relu_8_32_s::thread_icmp_ln114_fu_96_p2() {
    icmp_ln114_fu_96_p2 = (!m_0_reg_58.read().is_01() || !ap_const_lv4_8.is_01())? sc_lv<1>(): sc_lv<1>(m_0_reg_58.read() == ap_const_lv4_8);
}

void relu_8_32_s::thread_icmp_ln115_fu_120_p2() {
    icmp_ln115_fu_120_p2 = (!r_0_reg_69.read().is_01() || !ap_const_lv6_20.is_01())? sc_lv<1>(): sc_lv<1>(r_0_reg_69.read() == ap_const_lv6_20);
}

void relu_8_32_s::thread_icmp_ln116_fu_149_p2() {
    icmp_ln116_fu_149_p2 = (!c_0_reg_80.read().is_01() || !ap_const_lv6_20.is_01())? sc_lv<1>(): sc_lv<1>(c_0_reg_80.read() == ap_const_lv6_20);
}

void relu_8_32_s::thread_in_r_address0() {
    in_r_address0 =  (sc_lv<13>) (zext_ln117_2_fu_170_p1.read());
}

void relu_8_32_s::thread_in_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        in_r_ce0 = ap_const_logic_1;
    } else {
        in_r_ce0 = ap_const_logic_0;
    }
}

void relu_8_32_s::thread_m_fu_102_p2() {
    m_fu_102_p2 = (!m_0_reg_58.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_biguint<4>(m_0_reg_58.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void relu_8_32_s::thread_out_r_address0() {
    out_r_address0 =  (sc_lv<13>) (zext_ln117_2_reg_216.read());
}

void relu_8_32_s::thread_out_r_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        out_r_ce0 = ap_const_logic_1;
    } else {
        out_r_ce0 = ap_const_logic_0;
    }
}

void relu_8_32_s::thread_out_r_d0() {
    out_r_d0 = select_ln117_reg_232.read();
}

void relu_8_32_s::thread_out_r_we0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        out_r_we0 = ap_const_logic_1;
    } else {
        out_r_we0 = ap_const_logic_0;
    }
}

void relu_8_32_s::thread_r_fu_126_p2() {
    r_fu_126_p2 = (!r_0_reg_69.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(r_0_reg_69.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void relu_8_32_s::thread_select_ln117_fu_175_p3() {
    select_ln117_fu_175_p3 = (!tmp_fu_91_p2.read()[0].is_01())? sc_lv<16>(): ((tmp_fu_91_p2.read()[0].to_bool())? in_load_reg_226.read(): ap_const_lv16_0);
}

void relu_8_32_s::thread_tmp_6_fu_108_p3() {
    tmp_6_fu_108_p3 = esl_concat<4,5>(m_0_reg_58.read(), ap_const_lv5_0);
}

void relu_8_32_s::thread_tmp_8_cast_fu_141_p3() {
    tmp_8_cast_fu_141_p3 = esl_concat<10,5>(add_ln117_fu_136_p2.read(), ap_const_lv5_0);
}

void relu_8_32_s::thread_zext_ln115_fu_116_p1() {
    zext_ln115_fu_116_p1 = esl_zext<10,9>(tmp_6_fu_108_p3.read());
}

void relu_8_32_s::thread_zext_ln117_1_fu_161_p1() {
    zext_ln117_1_fu_161_p1 = esl_zext<15,6>(c_0_reg_80.read());
}

void relu_8_32_s::thread_zext_ln117_2_fu_170_p1() {
    zext_ln117_2_fu_170_p1 = esl_zext<64,15>(add_ln117_1_fu_165_p2.read());
}

void relu_8_32_s::thread_zext_ln117_fu_132_p1() {
    zext_ln117_fu_132_p1 = esl_zext<10,6>(r_0_reg_69.read());
}

void relu_8_32_s::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln114_fu_96_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(icmp_ln115_fu_120_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state4;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(icmp_ln116_fu_149_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state6;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state7;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        default : 
            ap_NS_fsm = "XXXXXXX";
            break;
    }
}

}
