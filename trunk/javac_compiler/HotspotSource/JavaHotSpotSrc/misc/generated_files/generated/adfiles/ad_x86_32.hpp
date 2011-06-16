//
// Copyright (c) 1997, 2010, Oracle and/or its affiliates. All rights reserved.
// DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
//
// This code is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License version 2 only, as
// published by the Free Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// version 2 for more details (a copy is included in the LICENSE file that
// accompanied this code).
//
// You should have received a copy of the GNU General Public License version
// 2 along with this work; if not, write to the Free Software Foundation,
// Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
// or visit www.oracle.com if you need additional information or have any
// questions.
//
//

// Machine Generated File.  Do Not Edit!



enum MachOperands {
  UNIVERSE, // 0
  LABEL, // 1
  SREGI, // 2
  SREGP, // 3
  SREGF, // 4
  SREGD, // 5
  SREGL, // 6
  METHOD, // 7
  IMMI, // 8
  IMMI0, // 9
  IMMI1, // 10
  IMMI_M1, // 11
  IMMI2, // 12
  IMMI8, // 13
  IMMI16, // 14
  IMMI_32, // 15
  IMMI_1_31, // 16
  IMMI_32_63, // 17
  IMMI_1, // 18
  IMMI_2, // 19
  IMMI_3, // 20
  IMMP, // 21
  IMMP0, // 22
  IMML, // 23
  IMML0, // 24
  IMML_M1, // 25
  IMML_127, // 26
  IMML_32BITS, // 27
  IMML32, // 28
  IMMD0, // 29
  IMMD1, // 30
  IMMD, // 31
  IMMXD, // 32
  IMMXD0, // 33
  IMMF0, // 34
  IMMF, // 35
  IMMXF, // 36
  IMMXF0, // 37
  IMMI_16, // 38
  IMMI_24, // 39
  IMMI_255, // 40
  IMMI_65535, // 41
  EREGI, // 42
  XREGI, // 43
  EAXREGI, // 44
  EBXREGI, // 45
  ECXREGI, // 46
  EDXREGI, // 47
  EDIREGI, // 48
  NAXREGI, // 49
  NADXREGI, // 50
  NCXREGI, // 51
  ESIREGI, // 52
  ANYREGP, // 53
  EREGP, // 54
  EREGP_NO_EBP, // 55
  NAXREGP, // 56
  NABXREGP, // 57
  PREGP, // 58
  EAXREGP, // 59
  EBXREGP, // 60
  ECXREGP, // 61
  ESIREGP, // 62
  EDIREGP, // 63
  EBPREGP, // 64
  EREGL, // 65
  EADXREGL, // 66
  EBCXREGL, // 67
  EADXREGL_LOW_ONLY, // 68
  EFLAGSREG, // 69
  EFLAGSREGU, // 70
  EFLAGSREGUCF, // 71
  FLAGSREG_LONG_LTGE, // 72
  FLAGSREG_LONG_EQNE, // 73
  FLAGSREG_LONG_LEGT, // 74
  REGD, // 75
  REGDPR1, // 76
  REGDPR2, // 77
  REGNOTDPR1, // 78
  REGXD, // 79
  REGXD6, // 80
  REGXD7, // 81
  REGF, // 82
  REGFPR1, // 83
  REGX, // 84
  DIRECT, // 85
  INDIRECT, // 86
  INDOFFSET8, // 87
  INDOFFSET32, // 88
  INDOFFSET32X, // 89
  INDINDEXOFFSET, // 90
  INDINDEX, // 91
  INDINDEXSCALE, // 92
  INDINDEXSCALEOFFSET, // 93
  LOAD_LONG_REGP, // 94
  LOAD_LONG_INDIRECT, // 95
  LOAD_LONG_INDOFFSET32, // 96
  STACKSLOTP, // 97
  STACKSLOTI, // 98
  STACKSLOTF, // 99
  STACKSLOTD, // 100
  STACKSLOTL, // 101
  INDIRECT_WIN95_SAFE, // 102
  INDOFFSET8_WIN95_SAFE, // 103
  INDOFFSET32_WIN95_SAFE, // 104
  INDINDEXOFFSET_WIN95_SAFE, // 105
  INDINDEXSCALE_WIN95_SAFE, // 106
  INDINDEXSCALEOFFSET_WIN95_SAFE, // 107
  CMPOP, // 108
  CMPOPU, // 109
  CMPOPUCF, // 110
  CMPOPUCF2, // 111
  CMPOP_FCMOV, // 112
  CMPOP_COMMUTE, // 113
  // last operand
  LOAD_LONG_MEMORY, // 114
  MEMORY, // 115
  LONG_MEMORY, // 116
  // last operand class
  _ADDP_EREGP_EREGI, // 117
  _LSHIFTI_EREGI_IMMI2, // 118
  _ADDP_EREGP__LSHIFTI_EREGI_IMMI2, // 119
  _ADDP_EREGP_NO_EBP_EREGI, // 120
  _ADDP_EREGP_NO_EBP__LSHIFTI_EREGI_IMMI2, // 121
  _LOADI_MEMORY_, // 122
  _LOADL_MEMORY_, // 123
  _LOADB_MEMORY_, // 124
  _LOADUB_MEMORY_, // 125
  _ANDI__LOADUB_MEMORY__IMMI8, // 126
  _LOADS_MEMORY_, // 127
  _LSHIFTI__LOADS_MEMORY__IMMI_24, // 128
  _LOADUS_MEMORY_, // 129
  _LSHIFTI__LOADUS_MEMORY__IMMI_24, // 130
  _ANDI__LOADUS_MEMORY__IMMI_255, // 131
  _ANDI__LOADUS_MEMORY__IMMI16, // 132
  _LSHIFTI__LOADI_MEMORY__IMMI_24, // 133
  _LSHIFTI__LOADI_MEMORY__IMMI_16, // 134
  _ANDI__LOADI_MEMORY__IMMI_255, // 135
  _ANDI__LOADI_MEMORY__IMMI_65535, // 136
  _ANDI__LOADI_MEMORY__IMMI, // 137
  _CONVL2I_EREGL_, // 138
  _ROUNDDOUBLE_REGDPR1_, // 139
  _ROUNDFLOAT_REGFPR1_, // 140
  _CONVD2F_REGDPR1_, // 141
  _BINARY_CMPOP_EFLAGSREG, // 142
  _BINARY_EREGI_EREGI, // 143
  _BINARY_CMPOPU_EFLAGSREGU, // 144
  _BINARY_CMPOPUCF_EFLAGSREGUCF, // 145
  _BINARY_EREGI__LOADI_MEMORY_, // 146
  _BINARY_EREGP_EREGP, // 147
  _BINARY_CMPOP_FCMOV_EFLAGSREGU, // 148
  _BINARY_REGDPR1_REGD, // 149
  _BINARY_REGFPR1_REGF, // 150
  _BINARY_REGD_REGD, // 151
  _BINARY_REGF_REGF, // 152
  _BINARY_REGX_REGX, // 153
  _BINARY_REGXD_REGXD, // 154
  _BINARY_EREGL_EREGL, // 155
  _ADDI__LOADI_MEMORY__EREGI, // 156
  _ADDI_EREGI__LOADI_MEMORY_, // 157
  _ADDI__LOADI_MEMORY__IMMI, // 158
  _ADDI__LOADI_MEMORY__IMMI1, // 159
  _ADDI__LOADI_MEMORY__IMMI_M1, // 160
  _BINARY_EAXREGP_EREGP, // 161
  _BINARY_EAXREGI_EREGI, // 162
  _BINARY_EADXREGL_EBCXREGL, // 163
  _BINARY_EAXREGP_ECXREGP, // 164
  _BINARY_EAXREGI_ECXREGI, // 165
  _SUBI__LOADI_MEMORY__EREGI, // 166
  _SUBI_IMMI0_EREGI, // 167
  _CONVI2L_NADXREGI_, // 168
  _MULL__CONVI2L_NADXREGI__EADXREGL_LOW_ONLY, // 169
  _RSHIFTL__MULL__CONVI2L_NADXREGI__EADXREGL_LOW_ONLY_IMMI_32, // 170
  _MULL_EADXREGL_LOW_ONLY__CONVI2L_NADXREGI_, // 171
  _RSHIFTL__MULL_EADXREGL_LOW_ONLY__CONVI2L_NADXREGI__IMMI_32, // 172
  _RSHIFTL__MULL__CONVI2L_NADXREGI__EADXREGL_LOW_ONLY_IMMI_32_63, // 173
  _RSHIFTL__MULL_EADXREGL_LOW_ONLY__CONVI2L_NADXREGI__IMMI_32_63, // 174
  _CONVI2L_EAXREGI_, // 175
  _ANDL__CONVI2L_EAXREGI__IMML_32BITS, // 176
  _ANDL__CONVI2L_NADXREGI__IMML_32BITS, // 177
  _RSHIFTI__LOADI_MEMORY__IMMI1, // 178
  _RSHIFTI__LOADI_MEMORY__IMMI8, // 179
  _LSHIFTI_XREGI_IMMI_24, // 180
  _LSHIFTI_XREGI_IMMI_16, // 181
  _ANDI__LOADI_MEMORY__EREGI, // 182
  _ANDI_EREGI__LOADI_MEMORY_, // 183
  _CASTP2X_EREGP_, // 184
  _ORI__LOADI_MEMORY__EREGI, // 185
  _ORI_EREGI__LOADI_MEMORY_, // 186
  _ORI__LOADI_MEMORY__IMMI, // 187
  _LSHIFTI_EREGI_IMMI1, // 188
  _URSHIFTI_EREGI_IMMI_M1, // 189
  _LSHIFTI_EREGI_IMMI8, // 190
  _URSHIFTI_EREGI_IMMI8, // 191
  _LSHIFTI_NCXREGI_ECXREGI, // 192
  _SUBI_IMMI0_ECXREGI, // 193
  _URSHIFTI_NCXREGI__SUBI_IMMI0_ECXREGI, // 194
  _SUBI_IMMI_32_ECXREGI, // 195
  _URSHIFTI_NCXREGI__SUBI_IMMI_32_ECXREGI, // 196
  _URSHIFTI_EREGI_IMMI1, // 197
  _LSHIFTI_EREGI_IMMI_M1, // 198
  _URSHIFTI_NCXREGI_ECXREGI, // 199
  _LSHIFTI_NCXREGI__SUBI_IMMI0_ECXREGI, // 200
  _LSHIFTI_NCXREGI__SUBI_IMMI_32_ECXREGI, // 201
  _XORI__LOADI_MEMORY__EREGI, // 202
  _XORI_EREGI__LOADI_MEMORY_, // 203
  _XORI__LOADI_MEMORY__IMMI, // 204
  _CMPLTMASK_NCXREGI_NCXREGI, // 205
  _ANDI__CMPLTMASK_NCXREGI_NCXREGI_NCXREGI, // 206
  _SUBI_NCXREGI_NCXREGI, // 207
  _ANDI_NCXREGI__CMPLTMASK_NCXREGI_NCXREGI, // 208
  _LOADL_LOAD_LONG_MEMORY_, // 209
  _LOADD_MEMORY_, // 210
  _SUBD_REGD_REGD, // 211
  _ADDD_REGD_REGD, // 212
  _ADDD__LOADD_MEMORY__REGD, // 213
  _ROUNDDOUBLE__ADDD__LOADD_MEMORY__REGD_, // 214
  _ADDD_REGD__LOADD_MEMORY_, // 215
  _ROUNDDOUBLE__ADDD_REGD__LOADD_MEMORY__, // 216
  _ADDD_REGD_IMMD, // 217
  _MULD_REGD_REGD, // 218
  _DIVD_REGD_REGD, // 219
  _LOADF_MEMORY_, // 220
  _CONVF2D_REGX_, // 221
  _SQRTD__CONVF2D_REGX__, // 222
  _CONVF2D__LOADF_MEMORY__, // 223
  _SQRTD__CONVF2D__LOADF_MEMORY___, // 224
  _MULF__LOADF_MEMORY__REGF, // 225
  _MULF_REGF__LOADF_MEMORY_, // 226
  _MULF_REGF_REGF, // 227
  _SUBF_REGF_REGF, // 228
  _CONVI2L_EREGI_, // 229
  _BINARY_EDIREGP_ECXREGI, // 230
  _BINARY_ESIREGP_EBXREGI, // 231
  _BINARY_EDIREGP_ESIREGP, // 232
  _BINARY_EDIREGP_EDXREGI, // 233
  _BINARY_ESIREGP_EAXREGI, // 234
  _ANDI_EREGI_IMMI, // 235
  _ANDI_EREGI_MEMORY, // 236
  _LOADP_MEMORY_, // 237
  _PARTIALSUBTYPECHECK_ESIREGP_EAXREGP, // 238
  _BINARY_CMPOP_FLAGSREG_LONG_LTGE, // 239
  _BINARY_EREGL__LOADL_LOAD_LONG_MEMORY_, // 240
  _BINARY_CMPOP_FLAGSREG_LONG_EQNE, // 241
  _BINARY_CMPOP_COMMUTE_FLAGSREG_LONG_LEGT, // 242
  // last internally defined operand
  _LAST_MACH_OPER
};

enum MachOpcodes {
  Universe_rule, // 0
  label_rule, // 1
  sRegI_rule, // 2
  sRegP_rule, // 3
  sRegF_rule, // 4
  sRegD_rule, // 5
  sRegL_rule, // 6
  method_rule, // 7
  immI_rule, // 8
  immI0_rule, // 9
  immI1_rule, // 10
  immI_M1_rule, // 11
  immI2_rule, // 12
  immI8_rule, // 13
  immI16_rule, // 14
  immI_32_rule, // 15
  immI_1_31_rule, // 16
  immI_32_63_rule, // 17
  immI_1_rule, // 18
  immI_2_rule, // 19
  immI_3_rule, // 20
  immP_rule, // 21
  immP0_rule, // 22
  immL_rule, // 23
  immL0_rule, // 24
  immL_M1_rule, // 25
  immL_127_rule, // 26
  immL_32bits_rule, // 27
  immL32_rule, // 28
  immD0_rule, // 29
  immD1_rule, // 30
  immD_rule, // 31
  immXD_rule, // 32
  immXD0_rule, // 33
  immF0_rule, // 34
  immF_rule, // 35
  immXF_rule, // 36
  immXF0_rule, // 37
  immI_16_rule, // 38
  immI_24_rule, // 39
  immI_255_rule, // 40
  immI_65535_rule, // 41
  eRegI_rule, // 42
  xRegI_rule, // 43
  eAXRegI_rule, // 44
  eBXRegI_rule, // 45
  eCXRegI_rule, // 46
  eDXRegI_rule, // 47
  eDIRegI_rule, // 48
  naxRegI_rule, // 49
  nadxRegI_rule, // 50
  ncxRegI_rule, // 51
  eSIRegI_rule, // 52
  anyRegP_rule, // 53
  eRegP_rule, // 54
  eRegP_no_EBP_rule, // 55
  naxRegP_rule, // 56
  nabxRegP_rule, // 57
  pRegP_rule, // 58
  eAXRegP_rule, // 59
  eBXRegP_rule, // 60
  eCXRegP_rule, // 61
  eSIRegP_rule, // 62
  eDIRegP_rule, // 63
  eBPRegP_rule, // 64
  eRegL_rule, // 65
  eADXRegL_rule, // 66
  eBCXRegL_rule, // 67
  eADXRegL_low_only_rule, // 68
  eFlagsReg_rule, // 69
  eFlagsRegU_rule, // 70
  eFlagsRegUCF_rule, // 71
  flagsReg_long_LTGE_rule, // 72
  flagsReg_long_EQNE_rule, // 73
  flagsReg_long_LEGT_rule, // 74
  regD_rule, // 75
  regDPR1_rule, // 76
  regDPR2_rule, // 77
  regnotDPR1_rule, // 78
  regXD_rule, // 79
  regXD6_rule, // 80
  regXD7_rule, // 81
  regF_rule, // 82
  regFPR1_rule, // 83
  regX_rule, // 84
  direct_rule, // 85
  indirect_rule, // 86
  indOffset8_rule, // 87
  indOffset32_rule, // 88
  indOffset32X_rule, // 89
  indIndexOffset_rule, // 90
  indIndex_rule, // 91
  indIndexScale_rule, // 92
  indIndexScaleOffset_rule, // 93
  load_long_RegP_rule, // 94
  load_long_indirect_rule, // 95
  load_long_indOffset32_rule, // 96
  stackSlotP_rule, // 97
  stackSlotI_rule, // 98
  stackSlotF_rule, // 99
  stackSlotD_rule, // 100
  stackSlotL_rule, // 101
  indirect_win95_safe_rule, // 102
  indOffset8_win95_safe_rule, // 103
  indOffset32_win95_safe_rule, // 104
  indIndexOffset_win95_safe_rule, // 105
  indIndexScale_win95_safe_rule, // 106
  indIndexScaleOffset_win95_safe_rule, // 107
  cmpOp_rule, // 108
  cmpOpU_rule, // 109
  cmpOpUCF_rule, // 110
  cmpOpUCF2_rule, // 111
  cmpOp_fcmov_rule, // 112
  cmpOp_commute_rule, // 113
  // last operand
  load_long_memory_rule, // 114
  memory_rule, // 115
  long_memory_rule, // 116
  // last operand class
  _AddP_eRegP_eRegI_rule, // 117
  _LShiftI_eRegI_immI2_rule, // 118
  _AddP_eRegP__LShiftI_eRegI_immI2_rule, // 119
  _AddP_eRegP_no_EBP_eRegI_rule, // 120
  _AddP_eRegP_no_EBP__LShiftI_eRegI_immI2_rule, // 121
  _LoadI_memory__rule, // 122
  _LoadL_memory__rule, // 123
  _LoadB_memory__rule, // 124
  _LoadUB_memory__rule, // 125
  _AndI__LoadUB_memory__immI8_rule, // 126
  _LoadS_memory__rule, // 127
  _LShiftI__LoadS_memory__immI_24_rule, // 128
  _LoadUS_memory__rule, // 129
  _LShiftI__LoadUS_memory__immI_24_rule, // 130
  _AndI__LoadUS_memory__immI_255_rule, // 131
  _AndI__LoadUS_memory__immI16_rule, // 132
  _LShiftI__LoadI_memory__immI_24_rule, // 133
  _LShiftI__LoadI_memory__immI_16_rule, // 134
  _AndI__LoadI_memory__immI_255_rule, // 135
  _AndI__LoadI_memory__immI_65535_rule, // 136
  _AndI__LoadI_memory__immI_rule, // 137
  _ConvL2I_eRegL__rule, // 138
  _RoundDouble_regDPR1__rule, // 139
  _RoundFloat_regFPR1__rule, // 140
  _ConvD2F_regDPR1__rule, // 141
  _Binary_cmpOp_eFlagsReg_rule, // 142
  _Binary_eRegI_eRegI_rule, // 143
  _Binary_cmpOpU_eFlagsRegU_rule, // 144
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 145
  _Binary_eRegI__LoadI_memory__rule, // 146
  _Binary_eRegP_eRegP_rule, // 147
  _Binary_cmpOp_fcmov_eFlagsRegU_rule, // 148
  _Binary_regDPR1_regD_rule, // 149
  _Binary_regFPR1_regF_rule, // 150
  _Binary_regD_regD_rule, // 151
  _Binary_regF_regF_rule, // 152
  _Binary_regX_regX_rule, // 153
  _Binary_regXD_regXD_rule, // 154
  _Binary_eRegL_eRegL_rule, // 155
  _AddI__LoadI_memory__eRegI_rule, // 156
  _AddI_eRegI__LoadI_memory__rule, // 157
  _AddI__LoadI_memory__immI_rule, // 158
  _AddI__LoadI_memory__immI1_rule, // 159
  _AddI__LoadI_memory__immI_M1_rule, // 160
  _Binary_eAXRegP_eRegP_rule, // 161
  _Binary_eAXRegI_eRegI_rule, // 162
  _Binary_eADXRegL_eBCXRegL_rule, // 163
  _Binary_eAXRegP_eCXRegP_rule, // 164
  _Binary_eAXRegI_eCXRegI_rule, // 165
  _SubI__LoadI_memory__eRegI_rule, // 166
  _SubI_immI0_eRegI_rule, // 167
  _ConvI2L_nadxRegI__rule, // 168
  _MulL__ConvI2L_nadxRegI__eADXRegL_low_only_rule, // 169
  _RShiftL__MulL__ConvI2L_nadxRegI__eADXRegL_low_only_immI_32_rule, // 170
  _MulL_eADXRegL_low_only__ConvI2L_nadxRegI__rule, // 171
  _RShiftL__MulL_eADXRegL_low_only__ConvI2L_nadxRegI__immI_32_rule, // 172
  _RShiftL__MulL__ConvI2L_nadxRegI__eADXRegL_low_only_immI_32_63_rule, // 173
  _RShiftL__MulL_eADXRegL_low_only__ConvI2L_nadxRegI__immI_32_63_rule, // 174
  _ConvI2L_eAXRegI__rule, // 175
  _AndL__ConvI2L_eAXRegI__immL_32bits_rule, // 176
  _AndL__ConvI2L_nadxRegI__immL_32bits_rule, // 177
  _RShiftI__LoadI_memory__immI1_rule, // 178
  _RShiftI__LoadI_memory__immI8_rule, // 179
  _LShiftI_xRegI_immI_24_rule, // 180
  _LShiftI_xRegI_immI_16_rule, // 181
  _AndI__LoadI_memory__eRegI_rule, // 182
  _AndI_eRegI__LoadI_memory__rule, // 183
  _CastP2X_eRegP__rule, // 184
  _OrI__LoadI_memory__eRegI_rule, // 185
  _OrI_eRegI__LoadI_memory__rule, // 186
  _OrI__LoadI_memory__immI_rule, // 187
  _LShiftI_eRegI_immI1_rule, // 188
  _URShiftI_eRegI_immI_M1_rule, // 189
  _LShiftI_eRegI_immI8_rule, // 190
  _URShiftI_eRegI_immI8_rule, // 191
  _LShiftI_ncxRegI_eCXRegI_rule, // 192
  _SubI_immI0_eCXRegI_rule, // 193
  _URShiftI_ncxRegI__SubI_immI0_eCXRegI_rule, // 194
  _SubI_immI_32_eCXRegI_rule, // 195
  _URShiftI_ncxRegI__SubI_immI_32_eCXRegI_rule, // 196
  _URShiftI_eRegI_immI1_rule, // 197
  _LShiftI_eRegI_immI_M1_rule, // 198
  _URShiftI_ncxRegI_eCXRegI_rule, // 199
  _LShiftI_ncxRegI__SubI_immI0_eCXRegI_rule, // 200
  _LShiftI_ncxRegI__SubI_immI_32_eCXRegI_rule, // 201
  _XorI__LoadI_memory__eRegI_rule, // 202
  _XorI_eRegI__LoadI_memory__rule, // 203
  _XorI__LoadI_memory__immI_rule, // 204
  _CmpLTMask_ncxRegI_ncxRegI_rule, // 205
  _AndI__CmpLTMask_ncxRegI_ncxRegI_ncxRegI_rule, // 206
  _SubI_ncxRegI_ncxRegI_rule, // 207
  _AndI_ncxRegI__CmpLTMask_ncxRegI_ncxRegI_rule, // 208
  _LoadL_load_long_memory__rule, // 209
  _LoadD_memory__rule, // 210
  _SubD_regD_regD_rule, // 211
  _AddD_regD_regD_rule, // 212
  _AddD__LoadD_memory__regD_rule, // 213
  _RoundDouble__AddD__LoadD_memory__regD__rule, // 214
  _AddD_regD__LoadD_memory__rule, // 215
  _RoundDouble__AddD_regD__LoadD_memory___rule, // 216
  _AddD_regD_immD_rule, // 217
  _MulD_regD_regD_rule, // 218
  _DivD_regD_regD_rule, // 219
  _LoadF_memory__rule, // 220
  _ConvF2D_regX__rule, // 221
  _SqrtD__ConvF2D_regX___rule, // 222
  _ConvF2D__LoadF_memory___rule, // 223
  _SqrtD__ConvF2D__LoadF_memory____rule, // 224
  _MulF__LoadF_memory__regF_rule, // 225
  _MulF_regF__LoadF_memory__rule, // 226
  _MulF_regF_regF_rule, // 227
  _SubF_regF_regF_rule, // 228
  _ConvI2L_eRegI__rule, // 229
  _Binary_eDIRegP_eCXRegI_rule, // 230
  _Binary_eSIRegP_eBXRegI_rule, // 231
  _Binary_eDIRegP_eSIRegP_rule, // 232
  _Binary_eDIRegP_eDXRegI_rule, // 233
  _Binary_eSIRegP_eAXRegI_rule, // 234
  _AndI_eRegI_immI_rule, // 235
  _AndI_eRegI_memory_rule, // 236
  _LoadP_memory__rule, // 237
  _PartialSubtypeCheck_eSIRegP_eAXRegP_rule, // 238
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 239
  _Binary_eRegL__LoadL_load_long_memory__rule, // 240
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 241
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 242
  // last internally defined operand
  storeSSI_rule, // 243
  storeSSP_rule, // 244
  storeSSL_rule, // 245
  leaP8_rule, // 246
  leaP32_rule, // 247
  leaPIdxOff_rule, // 248
  leaPIdxScale_rule, // 249
  leaPIdxScaleOff_rule, // 250
  loadConI_rule, // 251
  loadConI0_rule, // 252
  loadConP_rule, // 253
  loadConL_rule, // 254
  loadConL0_rule, // 255
  loadConF_rule, // 256
  loadConX_rule, // 257
  loadConX0_rule, // 258
  loadConD_rule, // 259
  loadConXD_rule, // 260
  loadConXD0_rule, // 261
  loadSSI_rule, // 262
  loadSSL_rule, // 263
  loadSSP_rule, // 264
  loadSSF_rule, // 265
  loadSSD_rule, // 266
  loadConL_low_only_rule, // 267
  popCountI_rule, // 268
  popCountI_mem_rule, // 269
  membar_volatile_rule, // 270
  castX2P_rule, // 271
  castP2X_rule, // 272
  checkCastPP_rule, // 273
  castPP_rule, // 274
  castII_rule, // 275
  storePConditional_rule, // 276
  storeIConditional_rule, // 277
  storeLConditional_rule, // 278
  movI_nocopy_rule, // 279
  movP_nocopy_rule, // 280
  cmpD_cc_P6_rule, // 281
  cmpD_cc_P6CF_rule, // 282
  cmpD_cc_rule, // 283
  cmpXD_cc_rule, // 284
  cmpXD_ccCF_rule, // 285
  cmpXD_ccmem_rule, // 286
  cmpXD_ccmemCF_rule, // 287
  absD_reg_rule, // 288
  absXD_reg_rule, // 289
  negD_reg_rule, // 290
  negXD_reg_rule, // 291
  cmpF_cc_P6_rule, // 292
  cmpF_cc_P6CF_rule, // 293
  cmpF_cc_rule, // 294
  cmpX_cc_rule, // 295
  cmpX_ccCF_rule, // 296
  cmpX_ccmem_rule, // 297
  cmpX_ccmemCF_rule, // 298
  absF_reg_rule, // 299
  absX_reg_rule, // 300
  negF_reg_rule, // 301
  negX_reg_rule, // 302
  MoveF2I_stack_reg_rule, // 303
  MoveF2I_reg_reg_sse_rule, // 304
  MoveI2F_stack_reg_rule, // 305
  MoveI2F_stack_reg_sse_rule, // 306
  MoveI2F_reg_reg_sse_rule, // 307
  MoveD2L_stack_reg_rule, // 308
  MoveL2D_stack_reg_rule, // 309
  MoveL2D_stack_reg_sse_rule, // 310
  MoveL2D_stack_reg_sse_partial_rule, // 311
  compI_eReg_rule, // 312
  compI_eReg_imm_rule, // 313
  compI_eReg_mem_rule, // 314
  testI_reg_rule, // 315
  testI_reg_imm_rule, // 316
  testI_reg_mem_rule, // 317
  compU_eReg_rule, // 318
  compU_eReg_imm_rule, // 319
  compU_eReg_mem_rule, // 320
  testU_reg_rule, // 321
  compP_eReg_rule, // 322
  compP_eReg_imm_rule, // 323
  compP_eReg_mem_rule, // 324
  compP_mem_eReg_rule, // 325
  testP_reg_rule, // 326
  testP_Reg_mem_rule, // 327
  partialSubtypeCheck_vs_Zero_rule, // 328
  cmpL_zero_flags_LTGE_rule, // 329
  cmpL_reg_flags_LTGE_rule, // 330
  cmpL_zero_flags_EQNE_rule, // 331
  cmpL_reg_flags_EQNE_rule, // 332
  cmpL_zero_flags_LEGT_rule, // 333
  cmpL_reg_flags_LEGT_rule, // 334
  cmpFastLock_rule, // 335
  cmpFastUnlock_rule, // 336
  safePoint_poll_rule, // 337
  bytes_reverse_int_rule, // 338
  bytes_reverse_long_rule, // 339
  bytes_reverse_unsigned_short_rule, // 340
  bytes_reverse_short_rule, // 341
  countLeadingZerosI_rule, // 342
  countLeadingZerosI_bsr_rule, // 343
  countLeadingZerosL_rule, // 344
  countLeadingZerosL_bsr_rule, // 345
  countTrailingZerosI_rule, // 346
  countTrailingZerosL_rule, // 347
  popCountL_rule, // 348
  popCountL_mem_rule, // 349
  loadB_rule, // 350
  loadB2L_rule, // 351
  loadUB_rule, // 352
  loadUB2L_rule, // 353
  loadUB2L_immI8_rule, // 354
  loadS_rule, // 355
  loadS2B_rule, // 356
  loadS2L_rule, // 357
  loadUS_rule, // 358
  loadUS2B_rule, // 359
  loadUS2L_rule, // 360
  loadUS2L_immI_255_rule, // 361
  loadUS2L_immI16_rule, // 362
  loadI_rule, // 363
  loadI2B_rule, // 364
  loadI2UB_rule, // 365
  loadI2S_rule, // 366
  loadI2US_rule, // 367
  loadI2L_rule, // 368
  loadI2L_immI_255_rule, // 369
  loadI2L_immI_65535_rule, // 370
  loadI2L_immI_rule, // 371
  loadUI2L_rule, // 372
  loadL_rule, // 373
  loadL_volatile_rule, // 374
  loadLX_volatile_rule, // 375
  loadLX_reg_volatile_rule, // 376
  loadRange_rule, // 377
  loadP_rule, // 378
  loadKlass_rule, // 379
  loadD_rule, // 380
  loadXD_rule, // 381
  loadXD_partial_rule, // 382
  loadX_rule, // 383
  loadF_rule, // 384
  loadA8B_rule, // 385
  loadA4S_rule, // 386
  loadA4C_rule, // 387
  load2IU_rule, // 388
  loadA2F_rule, // 389
  prefetchr0_rule, // 390
  prefetchr_rule, // 391
  prefetchrNTA_rule, // 392
  prefetchrT0_rule, // 393
  prefetchrT2_rule, // 394
  prefetchw0_rule, // 395
  prefetchw_rule, // 396
  prefetchwNTA_rule, // 397
  prefetchwT0_rule, // 398
  prefetchwT2_rule, // 399
  storeB_rule, // 400
  storeC_rule, // 401
  storeI_rule, // 402
  storeL_rule, // 403
  storeL2I_rule, // 404
  storeL_volatile_rule, // 405
  storeLX_volatile_rule, // 406
  storeLX_reg_volatile_rule, // 407
  storeP_rule, // 408
  storeImmI_rule, // 409
  storeImmI16_rule, // 410
  storeImmP_rule, // 411
  storeImmB_rule, // 412
  storeA8B_rule, // 413
  storeA4C_rule, // 414
  storeA2I_rule, // 415
  storeImmCM_rule, // 416
  storeD_rule, // 417
  storeD_rounded_rule, // 418
  storeXD_rule, // 419
  storeX_rule, // 420
  storeA2F_rule, // 421
  storeF_rule, // 422
  storeF_rounded_rule, // 423
  storeF_Drounded_rule, // 424
  storeF_imm_rule, // 425
  storeX_imm_rule, // 426
  membar_acquire_rule, // 427
  membar_acquire_lock_rule, // 428
  membar_release_rule, // 429
  membar_release_lock_rule, // 430
  unnecessary_membar_volatile_rule, // 431
  cmovI_reg_rule, // 432
  cmovI_regU_rule, // 433
  cmovI_regUCF_rule, // 434
  cmovI_mem_rule, // 435
  cmovI_memU_rule, // 436
  cmovI_memUCF_rule, // 437
  cmovP_reg_rule, // 438
  cmovP_reg_nonP6_rule, // 439
  cmovP_regU_rule, // 440
  cmovP_regUCF_rule, // 441
  fcmovD_regU_rule, // 442
  fcmovF_regU_rule, // 443
  fcmovD_regS_rule, // 444
  fcmovF_regS_rule, // 445
  fcmovX_regS_rule, // 446
  fcmovXD_regS_rule, // 447
  fcmovX_regU_rule, // 448
  fcmovX_regUCF_rule, // 449
  fcmovXD_regU_rule, // 450
  fcmovXD_regUCF_rule, // 451
  cmovL_reg_rule, // 452
  cmovL_regU_rule, // 453
  cmovL_regUCF_rule, // 454
  addI_eReg_rule, // 455
  addI_eReg_imm_rule, // 456
  incI_eReg_rule, // 457
  leaI_eReg_immI_rule, // 458
  leaP_eReg_immI_rule, // 459
  decI_eReg_rule, // 460
  addP_eReg_rule, // 461
  addP_eReg_imm_rule, // 462
  addI_eReg_mem_rule, // 463
  addI_eReg_mem_0_rule, // 464
  addI_mem_eReg_rule, // 465
  addI_mem_eReg_0_rule, // 466
  addI_mem_imm_rule, // 467
  incI_mem_rule, // 468
  decI_mem_rule, // 469
  loadPLocked_rule, // 470
  loadLLocked_rule, // 471
  loadLX_Locked_rule, // 472
  loadLX_reg_Locked_rule, // 473
  compareAndSwapL_rule, // 474
  compareAndSwapP_rule, // 475
  compareAndSwapI_rule, // 476
  subI_eReg_rule, // 477
  subI_eReg_imm_rule, // 478
  subI_eReg_mem_rule, // 479
  subI_mem_eReg_rule, // 480
  subP_eReg_rule, // 481
  negI_eReg_rule, // 482
  mulI_eReg_rule, // 483
  mulI_eReg_imm_rule, // 484
  mulI_imm_high_rule, // 485
  mulI_imm_high_0_rule, // 486
  mulI_imm_RShift_high_rule, // 487
  mulI_imm_RShift_high_0_rule, // 488
  mulI_mem_imm_rule, // 489
  mulI_rule, // 490
  mulI_0_rule, // 491
  mulI2L_rule, // 492
  mulI2L_0_rule, // 493
  mulIS_eReg_rule, // 494
  mulIS_eReg_0_rule, // 495
  mulL_eReg_rule, // 496
  mulL_eReg_lhi0_rule, // 497
  mulL_eReg_rhi0_rule, // 498
  mulL_eReg_hi0_rule, // 499
  mulL_eReg_con_rule, // 500
  divI_eReg_rule, // 501
  divL_eReg_rule, // 502
  divModI_eReg_divmod_rule, // 503
  modI_eReg_rule, // 504
  modL_eReg_rule, // 505
  shlI_eReg_1_rule, // 506
  salI_eReg_imm_rule, // 507
  salI_eReg_CL_rule, // 508
  sarI_eReg_1_rule, // 509
  sarI_mem_1_rule, // 510
  sarI_eReg_imm_rule, // 511
  sarI_mem_imm_rule, // 512
  sarI_eReg_CL_rule, // 513
  shrI_eReg_1_rule, // 514
  shrI_eReg_imm_rule, // 515
  i2b_rule, // 516
  i2s_rule, // 517
  shrI_eReg_CL_rule, // 518
  andI_eReg_rule, // 519
  andI_eReg_imm_rule, // 520
  andI_eReg_mem_rule, // 521
  andI_eReg_mem_0_rule, // 522
  andI_mem_eReg_rule, // 523
  andI_mem_eReg_0_rule, // 524
  andI_mem_imm_rule, // 525
  orI_eReg_rule, // 526
  orI_eReg_castP2X_rule, // 527
  orI_eReg_castP2X_0_rule, // 528
  orI_eReg_imm_rule, // 529
  orI_eReg_mem_rule, // 530
  orI_eReg_mem_0_rule, // 531
  orI_mem_eReg_rule, // 532
  orI_mem_eReg_0_rule, // 533
  orI_mem_imm_rule, // 534
  rolI_eReg_imm1_rule, // 535
  rolI_eReg_imm8_rule, // 536
  rolI_eReg_CL_rule, // 537
  rolI_eReg_i1_rule, // 538
  rolI_eReg_i1_0_rule, // 539
  rolI_eReg_i8_rule, // 540
  rolI_eReg_i8_0_rule, // 541
  rolI_eReg_Var_C0_rule, // 542
  rolI_eReg_Var_C0_0_rule, // 543
  rolI_eReg_Var_C32_rule, // 544
  rolI_eReg_Var_C32_0_rule, // 545
  rorI_eReg_imm1_rule, // 546
  rorI_eReg_imm8_rule, // 547
  rorI_eReg_CL_rule, // 548
  rorI_eReg_i1_rule, // 549
  rorI_eReg_i1_0_rule, // 550
  rorI_eReg_i8_rule, // 551
  rorI_eReg_i8_0_rule, // 552
  rorI_eReg_Var_C0_rule, // 553
  rorI_eReg_Var_C0_0_rule, // 554
  rorI_eReg_Var_C32_rule, // 555
  rorI_eReg_Var_C32_0_rule, // 556
  xorI_eReg_rule, // 557
  xorI_eReg_im1_rule, // 558
  xorI_eReg_imm_rule, // 559
  xorI_eReg_mem_rule, // 560
  xorI_eReg_mem_0_rule, // 561
  xorI_mem_eReg_rule, // 562
  xorI_mem_eReg_0_rule, // 563
  xorI_mem_imm_rule, // 564
  ci2b_rule, // 565
  convI2B_rule, // 566
  cp2b_rule, // 567
  convP2B_rule, // 568
  cmpLTMask_rule, // 569
  cmpLTMask0_rule, // 570
  cadd_cmpLTMask_rule, // 571
  cadd_cmpLTMask_1_rule, // 572
  cadd_cmpLTMask_0_rule, // 573
  cadd_cmpLTMask_2_rule, // 574
  addL_eReg_rule, // 575
  addL_eReg_imm_rule, // 576
  addL_eReg_mem_rule, // 577
  addL_eReg_mem_0_rule, // 578
  subL_eReg_rule, // 579
  subL_eReg_imm_rule, // 580
  subL_eReg_mem_rule, // 581
  negL_eReg_rule, // 582
  andL_eReg_rule, // 583
  andL_eReg_imm_rule, // 584
  andL_eReg_mem_rule, // 585
  andL_eReg_mem_0_rule, // 586
  orl_eReg_rule, // 587
  orl_eReg_imm_rule, // 588
  orl_eReg_mem_rule, // 589
  orl_eReg_mem_0_rule, // 590
  xorl_eReg_rule, // 591
  xorl_eReg_im1_rule, // 592
  xorl_eReg_imm_rule, // 593
  xorl_eReg_mem_rule, // 594
  xorl_eReg_mem_0_rule, // 595
  shlL_eReg_1_rule, // 596
  shlL_eReg_2_rule, // 597
  shlL_eReg_3_rule, // 598
  shlL_eReg_1_31_rule, // 599
  shlL_eReg_32_63_rule, // 600
  salL_eReg_CL_rule, // 601
  shrL_eReg_1_31_rule, // 602
  shrL_eReg_32_63_rule, // 603
  shrL_eReg_CL_rule, // 604
  sarL_eReg_1_31_rule, // 605
  sarL_eReg_32_63_rule, // 606
  sarL_eReg_CL_rule, // 607
  cmpD_0_rule, // 608
  cmpD_reg_rule, // 609
  cmpXD_reg_rule, // 610
  cmpXD_regmem_rule, // 611
  subD_reg_rule, // 612
  subD_reg_round_rule, // 613
  subD_reg_mem_rule, // 614
  addD_reg_rule, // 615
  addD_reg_round_rule, // 616
  addD_reg_mem_rule, // 617
  addD_reg_mem_0_rule, // 618
  addD_mem_reg_rule, // 619
  addD_mem_reg_0_rule, // 620
  addD_reg_imm1_rule, // 621
  addD_reg_imm_rule, // 622
  addD_reg_imm_round_rule, // 623
  addXD_reg_rule, // 624
  addXD_imm_rule, // 625
  addXD_mem_rule, // 626
  addXD_mem_0_rule, // 627
  subXD_reg_rule, // 628
  subXD_imm_rule, // 629
  subXD_mem_rule, // 630
  mulXD_reg_rule, // 631
  mulXD_imm_rule, // 632
  mulXD_mem_rule, // 633
  mulXD_mem_0_rule, // 634
  divXD_reg_rule, // 635
  divXD_imm_rule, // 636
  divXD_mem_rule, // 637
  mulD_reg_rule, // 638
  strictfp_mulD_reg_rule, // 639
  mulD_reg_imm_rule, // 640
  mulD_reg_mem_rule, // 641
  mulD_reg_mem_0_rule, // 642
  mulD_reg_mem_cisc_rule, // 643
  mulD_reg_mem_cisc_0_rule, // 644
  addD_mulD_reg_rule, // 645
  addD_mulD_reg_0_rule, // 646
  subD_mulD_reg_rule, // 647
  divD_reg_rule, // 648
  strictfp_divD_reg_rule, // 649
  divD_reg_round_rule, // 650
  modD_reg_rule, // 651
  modXD_reg_rule, // 652
  sinD_reg_rule, // 653
  sinXD_reg_rule, // 654
  cosD_reg_rule, // 655
  cosXD_reg_rule, // 656
  tanD_reg_rule, // 657
  tanXD_reg_rule, // 658
  atanD_reg_rule, // 659
  atanXD_reg_rule, // 660
  sqrtD_reg_rule, // 661
  powD_reg_rule, // 662
  powXD_reg_rule, // 663
  expD_reg_rule, // 664
  expXD_reg_rule, // 665
  log10D_reg_rule, // 666
  log10XD_reg_rule, // 667
  logD_reg_rule, // 668
  logXD_reg_rule, // 669
  cmpF_0_rule, // 670
  cmpF_reg_rule, // 671
  cmpX_reg_rule, // 672
  cmpX_regmem_rule, // 673
  subF24_reg_rule, // 674
  subF_reg_rule, // 675
  addF24_reg_rule, // 676
  addF_reg_rule, // 677
  addX_reg_rule, // 678
  addX_imm_rule, // 679
  addX_mem_rule, // 680
  addX_mem_0_rule, // 681
  subX_reg_rule, // 682
  subX_imm_rule, // 683
  subX_mem_rule, // 684
  mulX_reg_rule, // 685
  mulX_imm_rule, // 686
  mulX_mem_rule, // 687
  mulX_mem_0_rule, // 688
  divX_reg_rule, // 689
  divX_imm_rule, // 690
  divX_mem_rule, // 691
  sqrtX_reg_rule, // 692
  sqrtX_mem_rule, // 693
  sqrtXD_reg_rule, // 694
  sqrtXD_mem_rule, // 695
  addF24_reg_mem_rule, // 696
  addF24_reg_mem_0_rule, // 697
  addF_reg_mem_rule, // 698
  addF_reg_mem_0_rule, // 699
  addF24_mem_reg_rule, // 700
  addF24_mem_cisc_rule, // 701
  addF24_mem_cisc_0_rule, // 702
  addF24_mem_mem_rule, // 703
  addF24_reg_imm_rule, // 704
  addF_reg_imm_rule, // 705
  mulF24_reg_rule, // 706
  mulF_reg_rule, // 707
  mulF24_reg_mem_rule, // 708
  mulF24_reg_mem_0_rule, // 709
  mulF_reg_mem_rule, // 710
  mulF_reg_mem_0_rule, // 711
  mulF24_mem_mem_rule, // 712
  mulF24_reg_imm_rule, // 713
  mulF_reg_imm_rule, // 714
  mulF_reg_load1_rule, // 715
  mulF_reg_load1_0_rule, // 716
  addF_mulF_reg_load1_rule, // 717
  addF_mulF_reg_load1_1_rule, // 718
  addF_mulF_reg_load1_0_rule, // 719
  addF_mulF_reg_load1_2_rule, // 720
  addF_mulF_reg_rule, // 721
  addF_mulF_reg_0_rule, // 722
  subF_divF_reg_rule, // 723
  divF24_reg_rule, // 724
  divF_reg_rule, // 725
  modF24_reg_rule, // 726
  modF_reg_rule, // 727
  modX_reg_rule, // 728
  roundFloat_mem_reg_rule, // 729
  roundDouble_mem_reg_rule, // 730
  convD2F_reg_rule, // 731
  convD2X_reg_rule, // 732
  convXD2X_reg_rule, // 733
  convF2D_reg_reg_rule, // 734
  convF2D_reg_rule, // 735
  convX2D_reg_rule, // 736
  convX2XD_reg_rule, // 737
  convD2I_reg_reg_rule, // 738
  convXD2I_reg_reg_rule, // 739
  convD2L_reg_reg_rule, // 740
  convXD2L_reg_reg_rule, // 741
  convF2I_reg_reg_rule, // 742
  convX2I_reg_rule, // 743
  convF2L_reg_reg_rule, // 744
  convX2L_reg_reg_rule, // 745
  convI2D_reg_rule, // 746
  convI2XD_reg_rule, // 747
  convI2XD_mem_rule, // 748
  convXI2XD_reg_rule, // 749
  convI2D_mem_rule, // 750
  conv24I2F_reg_rule, // 751
  convI2F_SSF_rule, // 752
  convI2F_SSF_mem_rule, // 753
  convI2F_reg_rule, // 754
  convI2F_mem_rule, // 755
  convI2X_reg_rule, // 756
  convXI2X_reg_rule, // 757
  convI2L_reg_rule, // 758
  convI2L_reg_zex_rule, // 759
  zerox_long_rule, // 760
  convL2D_reg_rule, // 761
  convL2XD_reg_rule, // 762
  convL2X_reg_rule, // 763
  convL2F_reg_rule, // 764
  convL2I_reg_rule, // 765
  MoveF2I_reg_stack_rule, // 766
  MoveF2I_reg_stack_sse_rule, // 767
  MoveI2F_reg_stack_rule, // 768
  MoveD2L_reg_stack_rule, // 769
  MoveD2L_reg_stack_sse_rule, // 770
  MoveD2L_reg_reg_sse_rule, // 771
  MoveL2D_reg_stack_rule, // 772
  MoveL2D_reg_reg_sse_rule, // 773
  Repl8B_reg_rule, // 774
  Repl8B_eRegI_rule, // 775
  Repl8B_immI0_rule, // 776
  Repl4S_reg_rule, // 777
  Repl4S_eRegI_rule, // 778
  Repl4S_immI0_rule, // 779
  Repl4C_reg_rule, // 780
  Repl4C_eRegI_rule, // 781
  Repl4C_immI0_rule, // 782
  Repl2I_reg_rule, // 783
  Repl2I_eRegI_rule, // 784
  Repl2I_immI0_rule, // 785
  Repl2F_reg_rule, // 786
  Repl2F_regX_rule, // 787
  Repl2F_immXF0_rule, // 788
  rep_stos_rule, // 789
  string_compare_rule, // 790
  string_equals_rule, // 791
  string_indexof_rule, // 792
  array_equals_rule, // 793
  minI_eReg_rule, // 794
  maxI_eReg_rule, // 795
  jumpXtnd_rule, // 796
  jmpDir_rule, // 797
  jmpCon_rule, // 798
  jmpLoopEnd_rule, // 799
  jmpLoopEndU_rule, // 800
  jmpLoopEndUCF_rule, // 801
  jmpConU_rule, // 802
  jmpConUCF_rule, // 803
  jmpConUCF2_rule, // 804
  partialSubtypeCheck_rule, // 805
  jmpDir_short_rule, // 806
  jmpCon_short_rule, // 807
  jmpLoopEnd_short_rule, // 808
  jmpLoopEndU_short_rule, // 809
  jmpLoopEndUCF_short_rule, // 810
  jmpConU_short_rule, // 811
  jmpConUCF_short_rule, // 812
  jmpConUCF2_short_rule, // 813
  cmpL3_reg_reg_rule, // 814
  cmpL_LTGE_rule, // 815
  cmovLL_reg_LTGE_rule, // 816
  cmovLL_mem_LTGE_rule, // 817
  cmovII_reg_LTGE_rule, // 818
  cmovII_mem_LTGE_rule, // 819
  cmovPP_reg_LTGE_rule, // 820
  cmovDD_reg_LTGE_rule, // 821
  cmovXDD_reg_LTGE_rule, // 822
  cmovFF_reg_LTGE_rule, // 823
  cmovXX_reg_LTGE_rule, // 824
  cmpL_EQNE_rule, // 825
  cmovLL_reg_EQNE_rule, // 826
  cmovLL_mem_EQNE_rule, // 827
  cmovII_reg_EQNE_rule, // 828
  cmovII_mem_EQNE_rule, // 829
  cmovPP_reg_EQNE_rule, // 830
  cmovDD_reg_EQNE_rule, // 831
  cmovXDD_reg_EQNE_rule, // 832
  cmovFF_reg_EQNE_rule, // 833
  cmovXX_reg_EQNE_rule, // 834
  cmpL_LEGT_rule, // 835
  cmovLL_reg_LEGT_rule, // 836
  cmovLL_mem_LEGT_rule, // 837
  cmovII_reg_LEGT_rule, // 838
  cmovII_mem_LEGT_rule, // 839
  cmovPP_reg_LEGT_rule, // 840
  cmovDD_reg_LEGT_rule, // 841
  cmovXDD_reg_LEGT_rule, // 842
  cmovFF_reg_LEGT_rule, // 843
  cmovXX_reg_LEGT_rule, // 844
  CallStaticJavaDirect_rule, // 845
  CallStaticJavaHandle_rule, // 846
  CallDynamicJavaDirect_rule, // 847
  CallRuntimeDirect_rule, // 848
  CallLeafDirect_rule, // 849
  CallLeafNoFPDirect_rule, // 850
  Ret_rule, // 851
  TailCalljmpInd_rule, // 852
  tailjmpInd_rule, // 853
  CreateException_rule, // 854
  RethrowException_rule, // 855
  tlsLoadP_rule, // 856
  TLS_rule, // 857
  ShouldNotReachHere_rule, // 858
  // last instruction
  _BEGIN_INST_CHAIN_RULE = 243,
  _END_INST_CHAIN_RULE  = 268,
  _BEGIN_REMATERIALIZE   = 246,
  _END_REMATERIALIZE    = 338,
  _last_Mach_Node  = 859 
};

// Enumerate machine registers starting after reserved regs.
// in the order of occurrence in the alloc_class(es).
enum MachRegisterEncodes {
  ECX_enc = 1,
  EBX_enc = 3,
  EBP_enc = 5,
  EDI_enc = 7,
  EAX_enc = 0,
  EDX_enc = 2,
  ESI_enc = 6,
  ESP_enc = 4,
  FPR0L_enc = 0,
  FPR0H_enc = 0,
  FPR1L_enc = 1,
  FPR1H_enc = 1,
  FPR2L_enc = 2,
  FPR2H_enc = 2,
  FPR3L_enc = 3,
  FPR3H_enc = 3,
  FPR4L_enc = 4,
  FPR4H_enc = 4,
  FPR5L_enc = 5,
  FPR5H_enc = 5,
  FPR6L_enc = 6,
  FPR6H_enc = 6,
  FPR7L_enc = 7,
  FPR7H_enc = 7,
  XMM0a_enc = 0,
  XMM0b_enc = 0,
  XMM1a_enc = 1,
  XMM1b_enc = 1,
  XMM2a_enc = 2,
  XMM2b_enc = 2,
  XMM3a_enc = 3,
  XMM3b_enc = 3,
  XMM4a_enc = 4,
  XMM4b_enc = 4,
  XMM5a_enc = 5,
  XMM5b_enc = 5,
  XMM6a_enc = 6,
  XMM6b_enc = 6,
  XMM7a_enc = 7,
  XMM7b_enc = 7,
  EFLAGS_enc = 8
};

// Pipeline Stages
enum machPipelineStages {
   stage_undefined = 0,
   stage_S0        = 1,
   stage_S1        = 2,
   stage_S2        = 3,
   stage_S3        = 4,
   stage_S4        = 5,
   stage_S5        = 6,
   stage_count     = 6
};

// Pipeline Resources
enum machPipelineResources {
   resource_D0     = 0,
   resource_D1     = 1,
   resource_D2     = 2,
   resource_MS0    = 3,
   resource_MS1    = 4,
   resource_BR     = 5,
   resource_FPU    = 6,
   resource_ALU0   = 7,
   resource_ALU1   = 8,

   res_mask_D0     = 0x00000001,
   res_mask_D1     = 0x00000002,
   res_mask_D2     = 0x00000004,
   res_mask_DECODE = 0x00000007,
   res_mask_MS0    = 0x00000008,
   res_mask_MS1    = 0x00000010,
   res_mask_MEM    = 0x00000018,
   res_mask_BR     = 0x00000020,
   res_mask_FPU    = 0x00000040,
   res_mask_ALU0   = 0x00000080,
   res_mask_ALU1   = 0x00000100,
   res_mask_ALU    = 0x00000180,

   resource_count = 9
};

// MACROS to inline and constant fold State::valid(index)...
// when given a constant 'index' in dfa_<arch>.cpp
//   uint word   = index >> 5;       // Shift out bit position
//   uint bitpos = index & 0x0001F;  // Mask off word bits
#define STATE__VALID(index)     (_valid[((uint)index) >> 5] &  (0x1 << (((uint)index) & 0x0001F)))

#define STATE__NOT_YET_VALID(index)   ( (_valid[((uint)index) >> 5] &  (0x1 << (((uint)index) & 0x0001F))) == 0 )

#define STATE__VALID_CHILD(state,index)   ( state && (state->_valid[((uint)index) >> 5] &  (0x1 << (((uint)index) & 0x0001F))) )

#define STATE__SET_VALID(index)   (_valid[((uint)index) >> 5] |= (0x1 << (((uint)index) & 0x0001F)))

//---------------------------State-------------------------------------------
// State contains an integral cost vector, indexed by machine operand opcodes,
// a rule vector consisting of machine operand/instruction opcodes, and also
// indexed by machine operand opcodes, pointers to the children in the label
// tree generated by the Label routines in ideal nodes (currently limited to
// two for convenience, but this could change).
class State : public ResourceObj {
public:
  int    _id;         // State identifier
  Node  *_leaf;       // Ideal (non-machine-node) leaf of match tree
  State *_kids[2];       // Children of state node in label tree
  unsigned int _cost[_LAST_MACH_OPER];  // Cost vector, indexed by operand opcodes
  unsigned int _rule[_LAST_MACH_OPER];  // Rule vector, indexed by operand opcodes
  unsigned int _valid[(_LAST_MACH_OPER/32)+1]; // Bit Map of valid Cost/Rule entries

  State(void);                      // Constructor
  DEBUG_ONLY( ~State(void); )       // Destructor

  // Methods created by ADLC and invoked by Reduce
  MachOper *MachOperGenerator( int opcode, Compile* C );
  MachNode *MachNodeGenerator( int opcode, Compile* C );

  // Assign a state to a node, definition of method produced by ADLC
  bool DFA( int opcode, const Node *ideal );

  // Access function for _valid bit vector
  bool valid(uint index) {
    return( STATE__VALID(index) != 0 );
  }

  // Set function for _valid bit vector
  void set_valid(uint index) {
    STATE__SET_VALID(index);
  }

#ifndef PRODUCT
  void dump();                // Debugging prints
  void dump(int depth);
#endif
  void  _sub_Op_RegI(const Node *n);
  void  _sub_Op_RegP(const Node *n);
  void  _sub_Op_RegF(const Node *n);
  void  _sub_Op_RegD(const Node *n);
  void  _sub_Op_RegL(const Node *n);
  void  _sub_Op_RegFlags(const Node *n);
  void  _sub_Op_AbsD(const Node *n);
  void  _sub_Op_AbsF(const Node *n);
  void  _sub_Op_AddD(const Node *n);
  void  _sub_Op_AddF(const Node *n);
  void  _sub_Op_AddI(const Node *n);
  void  _sub_Op_AddL(const Node *n);
  void  _sub_Op_AddP(const Node *n);
  void  _sub_Op_AndI(const Node *n);
  void  _sub_Op_AndL(const Node *n);
  void  _sub_Op_AryEq(const Node *n);
  void  _sub_Op_AtanD(const Node *n);
  void  _sub_Op_Binary(const Node *n);
  void  _sub_Op_Bool(const Node *n);
  void  _sub_Op_ReverseBytesI(const Node *n);
  void  _sub_Op_ReverseBytesL(const Node *n);
  void  _sub_Op_ReverseBytesUS(const Node *n);
  void  _sub_Op_ReverseBytesS(const Node *n);
  void  _sub_Op_CallDynamicJava(const Node *n);
  void  _sub_Op_CallLeaf(const Node *n);
  void  _sub_Op_CallLeafNoFP(const Node *n);
  void  _sub_Op_CallRuntime(const Node *n);
  void  _sub_Op_CallStaticJava(const Node *n);
  void  _sub_Op_CastII(const Node *n);
  void  _sub_Op_CastX2P(const Node *n);
  void  _sub_Op_CastP2X(const Node *n);
  void  _sub_Op_CastPP(const Node *n);
  void  _sub_Op_CheckCastPP(const Node *n);
  void  _sub_Op_ClearArray(const Node *n);
  void  _sub_Op_CMoveD(const Node *n);
  void  _sub_Op_CMoveF(const Node *n);
  void  _sub_Op_CMoveI(const Node *n);
  void  _sub_Op_CMoveL(const Node *n);
  void  _sub_Op_CMoveP(const Node *n);
  void  _sub_Op_CmpD(const Node *n);
  void  _sub_Op_CmpD3(const Node *n);
  void  _sub_Op_CmpF(const Node *n);
  void  _sub_Op_CmpF3(const Node *n);
  void  _sub_Op_CmpI(const Node *n);
  void  _sub_Op_CmpL(const Node *n);
  void  _sub_Op_CmpL3(const Node *n);
  void  _sub_Op_CmpLTMask(const Node *n);
  void  _sub_Op_CmpP(const Node *n);
  void  _sub_Op_CmpU(const Node *n);
  void  _sub_Op_CompareAndSwapI(const Node *n);
  void  _sub_Op_CompareAndSwapL(const Node *n);
  void  _sub_Op_CompareAndSwapP(const Node *n);
  void  _sub_Op_ConD(const Node *n);
  void  _sub_Op_ConF(const Node *n);
  void  _sub_Op_ConI(const Node *n);
  void  _sub_Op_ConL(const Node *n);
  void  _sub_Op_ConP(const Node *n);
  void  _sub_Op_Conv2B(const Node *n);
  void  _sub_Op_ConvD2F(const Node *n);
  void  _sub_Op_ConvD2I(const Node *n);
  void  _sub_Op_ConvD2L(const Node *n);
  void  _sub_Op_ConvF2D(const Node *n);
  void  _sub_Op_ConvF2I(const Node *n);
  void  _sub_Op_ConvF2L(const Node *n);
  void  _sub_Op_ConvI2D(const Node *n);
  void  _sub_Op_ConvI2F(const Node *n);
  void  _sub_Op_ConvI2L(const Node *n);
  void  _sub_Op_ConvL2D(const Node *n);
  void  _sub_Op_ConvL2F(const Node *n);
  void  _sub_Op_ConvL2I(const Node *n);
  void  _sub_Op_CosD(const Node *n);
  void  _sub_Op_CountedLoopEnd(const Node *n);
  void  _sub_Op_CountLeadingZerosI(const Node *n);
  void  _sub_Op_CountLeadingZerosL(const Node *n);
  void  _sub_Op_CountTrailingZerosI(const Node *n);
  void  _sub_Op_CountTrailingZerosL(const Node *n);
  void  _sub_Op_CreateEx(const Node *n);
  void  _sub_Op_DivD(const Node *n);
  void  _sub_Op_DivF(const Node *n);
  void  _sub_Op_DivI(const Node *n);
  void  _sub_Op_DivL(const Node *n);
  void  _sub_Op_DivModI(const Node *n);
  void  _sub_Op_ExpD(const Node *n);
  void  _sub_Op_FastLock(const Node *n);
  void  _sub_Op_FastUnlock(const Node *n);
  void  _sub_Op_Goto(const Node *n);
  void  _sub_Op_Halt(const Node *n);
  void  _sub_Op_If(const Node *n);
  void  _sub_Op_Jump(const Node *n);
  void  _sub_Op_LShiftI(const Node *n);
  void  _sub_Op_LShiftL(const Node *n);
  void  _sub_Op_LoadB(const Node *n);
  void  _sub_Op_LoadUB(const Node *n);
  void  _sub_Op_LoadUS(const Node *n);
  void  _sub_Op_LoadD(const Node *n);
  void  _sub_Op_LoadF(const Node *n);
  void  _sub_Op_LoadI(const Node *n);
  void  _sub_Op_LoadUI2L(const Node *n);
  void  _sub_Op_LoadKlass(const Node *n);
  void  _sub_Op_LoadL(const Node *n);
  void  _sub_Op_LoadPLocked(const Node *n);
  void  _sub_Op_LoadLLocked(const Node *n);
  void  _sub_Op_LoadP(const Node *n);
  void  _sub_Op_LoadRange(const Node *n);
  void  _sub_Op_LoadS(const Node *n);
  void  _sub_Op_LogD(const Node *n);
  void  _sub_Op_Log10D(const Node *n);
  void  _sub_Op_MaxI(const Node *n);
  void  _sub_Op_MemBarAcquire(const Node *n);
  void  _sub_Op_MemBarRelease(const Node *n);
  void  _sub_Op_MemBarVolatile(const Node *n);
  void  _sub_Op_MinI(const Node *n);
  void  _sub_Op_ModD(const Node *n);
  void  _sub_Op_ModF(const Node *n);
  void  _sub_Op_ModI(const Node *n);
  void  _sub_Op_ModL(const Node *n);
  void  _sub_Op_MoveI2F(const Node *n);
  void  _sub_Op_MoveF2I(const Node *n);
  void  _sub_Op_MoveL2D(const Node *n);
  void  _sub_Op_MoveD2L(const Node *n);
  void  _sub_Op_MulD(const Node *n);
  void  _sub_Op_MulF(const Node *n);
  void  _sub_Op_MulI(const Node *n);
  void  _sub_Op_MulL(const Node *n);
  void  _sub_Op_NegD(const Node *n);
  void  _sub_Op_NegF(const Node *n);
  void  _sub_Op_OrI(const Node *n);
  void  _sub_Op_OrL(const Node *n);
  void  _sub_Op_PartialSubtypeCheck(const Node *n);
  void  _sub_Op_PopCountI(const Node *n);
  void  _sub_Op_PopCountL(const Node *n);
  void  _sub_Op_PowD(const Node *n);
  void  _sub_Op_PrefetchRead(const Node *n);
  void  _sub_Op_PrefetchWrite(const Node *n);
  void  _sub_Op_RShiftI(const Node *n);
  void  _sub_Op_RShiftL(const Node *n);
  void  _sub_Op_Rethrow(const Node *n);
  void  _sub_Op_Return(const Node *n);
  void  _sub_Op_RoundDouble(const Node *n);
  void  _sub_Op_RoundFloat(const Node *n);
  void  _sub_Op_SafePoint(const Node *n);
  void  _sub_Op_SinD(const Node *n);
  void  _sub_Op_SqrtD(const Node *n);
  void  _sub_Op_StoreB(const Node *n);
  void  _sub_Op_StoreC(const Node *n);
  void  _sub_Op_StoreCM(const Node *n);
  void  _sub_Op_StorePConditional(const Node *n);
  void  _sub_Op_StoreIConditional(const Node *n);
  void  _sub_Op_StoreLConditional(const Node *n);
  void  _sub_Op_StoreD(const Node *n);
  void  _sub_Op_StoreF(const Node *n);
  void  _sub_Op_StoreI(const Node *n);
  void  _sub_Op_StoreL(const Node *n);
  void  _sub_Op_StoreP(const Node *n);
  void  _sub_Op_StrComp(const Node *n);
  void  _sub_Op_StrEquals(const Node *n);
  void  _sub_Op_StrIndexOf(const Node *n);
  void  _sub_Op_SubD(const Node *n);
  void  _sub_Op_SubF(const Node *n);
  void  _sub_Op_SubI(const Node *n);
  void  _sub_Op_SubL(const Node *n);
  void  _sub_Op_TailCall(const Node *n);
  void  _sub_Op_TailJump(const Node *n);
  void  _sub_Op_TanD(const Node *n);
  void  _sub_Op_ThreadLocal(const Node *n);
  void  _sub_Op_URShiftI(const Node *n);
  void  _sub_Op_URShiftL(const Node *n);
  void  _sub_Op_XorI(const Node *n);
  void  _sub_Op_XorL(const Node *n);
  void  _sub_Op_Load8B(const Node *n);
  void  _sub_Op_Load4C(const Node *n);
  void  _sub_Op_Load4S(const Node *n);
  void  _sub_Op_Load2I(const Node *n);
  void  _sub_Op_Load2F(const Node *n);
  void  _sub_Op_Store8B(const Node *n);
  void  _sub_Op_Store4C(const Node *n);
  void  _sub_Op_Store2I(const Node *n);
  void  _sub_Op_Store2F(const Node *n);
  void  _sub_Op_Replicate8B(const Node *n);
  void  _sub_Op_Replicate4S(const Node *n);
  void  _sub_Op_Replicate4C(const Node *n);
  void  _sub_Op_Replicate2I(const Node *n);
  void  _sub_Op_Replicate2F(const Node *n);
};



// Total number of operands defined in architecture definition
#define FIRST_OPERAND_CLASS   114
#define NUM_OPERANDS          117

// Total number of instructions defined in architecture definition
#define NUM_INSTRUCTIONS   606

//----------------------------Declare classes derived from MachOper----------

class UniverseOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
public:
  UniverseOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return UNIVERSE; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "Universe";}
#endif
};

class sRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return SREGI; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegI";}
#endif
};

class sRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return SREGP; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegP";}
#endif
};

class sRegFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegFOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return SREGF; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegF";}
#endif
};

class sRegDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegDOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return SREGD; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegD";}
#endif
};

class sRegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  sRegLOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return SREGL; }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node));/* sReg */
  }
  virtual int            reg(PhaseRegAlloc *ra_, const Node *node, int idx) const {
    return (int)OptoReg::reg2stack(ra_->get_reg_first(node->in(idx)));/* sReg */
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "sRegL";}
#endif
};

class immIOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immIOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI";}
#endif
};

class immI0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI0Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI0; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI0";}
#endif
};

class immI1Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI1Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI1; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI1";}
#endif
};

class immI_M1Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_M1Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_M1; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_M1";}
#endif
};

class immI2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI2Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI2; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI2";}
#endif
};

class immI8Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI8Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI8; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI8";}
#endif
};

class immI16Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI16Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI16; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI16";}
#endif
};

class immI_32Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_32Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_32; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_32";}
#endif
};

class immI_1_31Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_1_31Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_1_31; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_1_31";}
#endif
};

class immI_32_63Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_32_63Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_32_63; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_32_63";}
#endif
};

class immI_1Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_1Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_1; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_1";}
#endif
};

class immI_2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_2Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_2; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_2";}
#endif
};

class immI_3Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_3Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_3; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_3";}
#endif
};

class immPOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  immPOper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMP; }
  virtual const Type *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_con(); }
  virtual bool           constant_is_oop() const { return _c0->isa_oop_ptr(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immP";}
#endif
};

class immP0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  immP0Oper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMP0; }
  virtual const Type *type() const { return _c0; }

  virtual intptr_t       constant() const { return _c0->get_con(); }
  virtual bool           constant_is_oop() const { return _c0->isa_oop_ptr(); }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "immP0";}
#endif
};

class immLOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immLOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML; }
  virtual const Type *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, _c0);
  }
  virtual const char    *Name() const { return "immL";}
#endif
};

class immL0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL0Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML0; }
  virtual const Type *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, _c0);
  }
  virtual const char    *Name() const { return "immL0";}
#endif
};

class immL_M1Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL_M1Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML_M1; }
  virtual const Type *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, _c0);
  }
  virtual const char    *Name() const { return "immL_M1";}
#endif
};

class immL_127Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL_127Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML_127; }
  virtual const Type *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, _c0);
  }
  virtual const char    *Name() const { return "immL_127";}
#endif
};

class immL_32bitsOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL_32bitsOper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML_32BITS; }
  virtual const Type *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, _c0);
  }
  virtual const char    *Name() const { return "immL_32bits";}
#endif
};

class immL32Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jlong          _c0;
public:
  immL32Oper(jlong c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMML32; }
  virtual const Type *type() const { return TypeLong::LONG; }

  virtual intptr_t       constant() const {  return (intptr_t)_c0; }
  virtual jlong          constantL() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#" INT64_FORMAT, _c0);
  }
  virtual const char    *Name() const { return "immL32";}
#endif
};

class immD0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immD0Oper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMD0; }
  virtual const Type *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immD0";}
#endif
};

class immD1Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immD1Oper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMD1; }
  virtual const Type *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immD1";}
#endif
};

class immDOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immDOper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMD; }
  virtual const Type *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immD";}
#endif
};

class immXDOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immXDOper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMXD; }
  virtual const Type *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immXD";}
#endif
};

class immXD0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jdouble        _c0;
public:
  immXD0Oper(jdouble c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMXD0; }
  virtual const Type *type() const { return Type::DOUBLE; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jdouble        constantD() const { return _c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immXD0";}
#endif
};

class immF0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  immF0Oper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMF0; }
  virtual const Type *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immF0";}
#endif
};

class immFOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  immFOper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMF; }
  virtual const Type *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immF";}
#endif
};

class immXFOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  immXFOper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMXF; }
  virtual const Type *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immXF";}
#endif
};

class immXF0Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  jfloat         _c0;
public:
  immXF0Oper(jfloat c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return IMMXF0; }
  virtual const Type *type() const { return Type::FLOAT; }

  virtual intptr_t       constant() const { ShouldNotReachHere(); return 0;  }
  virtual jfloat         constantF() const { return (jfloat)_c0; }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    st->print("#%f", _c0);
  }
  virtual const char    *Name() const { return "immXF0";}
#endif
};

class immI_16Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_16Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_16; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_16";}
#endif
};

class immI_24Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_24Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_24; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_24";}
#endif
};

class immI_255Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_255Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_255; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_255";}
#endif
};

class immI_65535Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  int32          _c0;
public:
  immI_65535Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return IMMI_65535; }
  virtual const Type *type() const { return TypeInt::INT; }

  virtual intptr_t       constant() const { return (intptr_t)_c0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "immI_65535";}
#endif
};

class eRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eRegI";}
#endif
};

class xRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  xRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return XREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "xRegI";}
#endif
};

class eAXRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eAXRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EAXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eAXRegI";}
#endif
};

class eBXRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eBXRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EBXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eBXRegI";}
#endif
};

class eCXRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eCXRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return ECXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eCXRegI";}
#endif
};

class eDXRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eDXRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EDXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eDXRegI";}
#endif
};

class eDIRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eDIRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EDIREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eDIRegI";}
#endif
};

class naxRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  naxRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return NAXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "naxRegI";}
#endif
};

class nadxRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  nadxRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return NADXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "nadxRegI";}
#endif
};

class ncxRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  ncxRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return NCXREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "ncxRegI";}
#endif
};

class eSIRegIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eSIRegIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return ESIREGI; }
  virtual const Type *type() const { return TypeInt::INT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eSIRegI";}
#endif
};

class anyRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  anyRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return ANYREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "anyRegP";}
#endif
};

class eRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eRegP";}
#endif
};

class eRegP_no_EBPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eRegP_no_EBPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EREGP_NO_EBP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eRegP_no_EBP";}
#endif
};

class naxRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  naxRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return NAXREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "naxRegP";}
#endif
};

class nabxRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  nabxRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return NABXREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "nabxRegP";}
#endif
};

class pRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  pRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return PREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "pRegP";}
#endif
};

class eAXRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eAXRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EAXREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eAXRegP";}
#endif
};

class eBXRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eBXRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EBXREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eBXRegP";}
#endif
};

class eCXRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eCXRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return ECXREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eCXRegP";}
#endif
};

class eSIRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eSIRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return ESIREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eSIRegP";}
#endif
};

class eDIRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eDIRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EDIREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eDIRegP";}
#endif
};

class eBPRegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eBPRegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EBPREGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eBPRegP";}
#endif
};

class eRegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eRegLOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EREGL; }
  virtual const Type *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eRegL";}
#endif
};

class eADXRegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eADXRegLOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EADXREGL; }
  virtual const Type *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eADXRegL";}
#endif
};

class eBCXRegLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eBCXRegLOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EBCXREGL; }
  virtual const Type *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eBCXRegL";}
#endif
};

class eADXRegL_low_onlyOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eADXRegL_low_onlyOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EADXREGL_LOW_ONLY; }
  virtual const Type *type() const { return TypeLong::LONG; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eADXRegL_low_only";}
#endif
};

class eFlagsRegOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eFlagsRegOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EFLAGSREG; }
  virtual const Type *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eFlagsReg";}
#endif
};

class eFlagsRegUOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eFlagsRegUOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EFLAGSREGU; }
  virtual const Type *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eFlagsRegU";}
#endif
};

class eFlagsRegUCFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  eFlagsRegUCFOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return EFLAGSREGUCF; }
  virtual const Type *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "eFlagsRegUCF";}
#endif
};

class flagsReg_long_LTGEOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsReg_long_LTGEOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return FLAGSREG_LONG_LTGE; }
  virtual const Type *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsReg_long_LTGE";}
#endif
};

class flagsReg_long_EQNEOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsReg_long_EQNEOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return FLAGSREG_LONG_EQNE; }
  virtual const Type *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsReg_long_EQNE";}
#endif
};

class flagsReg_long_LEGTOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  flagsReg_long_LEGTOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return FLAGSREG_LONG_LEGT; }
  virtual const Type *type() const { return TypeInt::CC /*flags*/; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "flagsReg_long_LEGT";}
#endif
};

class regDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regDOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGD; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regD";}
#endif
};

class regDPR1Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regDPR1Oper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGDPR1; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regDPR1";}
#endif
};

class regDPR2Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regDPR2Oper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGDPR2; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regDPR2";}
#endif
};

class regnotDPR1Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regnotDPR1Oper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGNOTDPR1; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regnotDPR1";}
#endif
};

class regXDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regXDOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGXD; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regXD";}
#endif
};

class regXD6Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regXD6Oper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGXD6; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regXD6";}
#endif
};

class regXD7Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regXD7Oper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGXD7; }
  virtual const Type *type() const { return Type::DOUBLE; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regXD7";}
#endif
};

class regFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regFOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGF; }
  virtual const Type *type() const { return Type::FLOAT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regF";}
#endif
};

class regFPR1Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regFPR1Oper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGFPR1; }
  virtual const Type *type() const { return Type::FLOAT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regFPR1";}
#endif
};

class regXOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  regXOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return REGX; }
  virtual const Type *type() const { return Type::FLOAT; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "regX";}
#endif
};

class directOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
  const TypePtr *_c0;
public:
  directOper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return DIRECT; }
  virtual const Type *type() const { return _c0; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0xFFFFFFFF;  }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: addr
    return (int)_c0->get_con();
  }
  virtual bool disp_is_oop() const {  return _c0->isa_oop_ptr(); }
  virtual int            constant_disp() const { // Replacement variable: addr
    return (int)_c0->get_con();
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "direct";}
#endif
};

class indirectOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  indirectOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return INDIRECT; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x0;  }
  virtual int            constant_disp() const { return 0x0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "indirect";}
#endif
};

class indOffset8Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffset8Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSET8; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indOffset8";}
#endif
};

class indOffset32Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffset32Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSET32; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indOffset32";}
#endif
};

class indOffset32XOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  const TypePtr *_c0;
public:
  indOffset32XOper(const TypePtr *c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return INDOFFSET32X; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual const TypePtr *disp_as_type() const { return _c0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0->get_con();
  }
  virtual bool disp_is_oop() const {  return _c0->isa_oop_ptr(); }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0->get_con();
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
    _c0->dump_on(st);
  }
  virtual const char    *Name() const { return "indOffset32X";}
#endif
};

class indIndexOffsetOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indIndexOffsetOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDINDEXOFFSET; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indIndexOffset";}
#endif
};

class indIndexOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
public:
  indIndexOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return INDINDEX; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x0;  }
  virtual int            constant_disp() const { return 0x0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "indIndex";}
#endif
};

class indIndexScaleOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indIndexScaleOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDINDEXSCALE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { // Replacement variable: scale
    return (int)_c0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x0;  }
  virtual int            constant_disp() const { return 0x0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indIndexScale";}
#endif
};

class indIndexScaleOffsetOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
  jint             _c1;
public:
  indIndexScaleOffsetOper(int32 c0, int32 c1)  : _c0(c0), _c1(c1) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return INDINDEXSCALEOFFSET; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { // Replacement variable: scale
    return (int)_c0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c1;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c1;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("#%d", _c1);
  }
  virtual const char    *Name() const { return "indIndexScaleOffset";}
#endif
};

class load_long_RegPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  load_long_RegPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return LOAD_LONG_REGP; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }


#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "load_long_RegP";}
#endif
};

class load_long_indirectOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  load_long_indirectOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return LOAD_LONG_INDIRECT; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x0;  }
  virtual int            constant_disp() const { return 0x0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "load_long_indirect";}
#endif
};

class load_long_indOffset32Oper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  load_long_indOffset32Oper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return LOAD_LONG_INDOFFSET32; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "load_long_indOffset32";}
#endif
};

class stackSlotPOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  stackSlotPOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return STACKSLOTP; }
  virtual const Type    *type() const { return TypePtr::BOTTOM; } // stackSlotX

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    if( idx != 0 ) {
      // Access register number for input operand
      return ra_->reg2offset(ra_->get_reg_first(node->in(idx)));/* sReg */
    }
    // Access register number from myself
    return ra_->reg2offset(ra_->get_reg_first(node));/* sReg */
  }
  virtual int       constant_disp() const { return Type::OffsetBot; }
#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "stackSlotP";}
#endif
};

class stackSlotIOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  stackSlotIOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return STACKSLOTI; }
  virtual const Type    *type() const { return TypeInt::INT; } // stackSlotX

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    if( idx != 0 ) {
      // Access register number for input operand
      return ra_->reg2offset(ra_->get_reg_first(node->in(idx)));/* sReg */
    }
    // Access register number from myself
    return ra_->reg2offset(ra_->get_reg_first(node));/* sReg */
  }
  virtual int       constant_disp() const { return Type::OffsetBot; }
#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "stackSlotI";}
#endif
};

class stackSlotFOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  stackSlotFOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return STACKSLOTF; }
  virtual const Type    *type() const { return Type::FLOAT; } // stackSlotX

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    if( idx != 0 ) {
      // Access register number for input operand
      return ra_->reg2offset(ra_->get_reg_first(node->in(idx)));/* sReg */
    }
    // Access register number from myself
    return ra_->reg2offset(ra_->get_reg_first(node));/* sReg */
  }
  virtual int       constant_disp() const { return Type::OffsetBot; }
#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "stackSlotF";}
#endif
};

class stackSlotDOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  stackSlotDOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return STACKSLOTD; }
  virtual const Type    *type() const { return Type::DOUBLE; } // stackSlotX

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    if( idx != 0 ) {
      // Access register number for input operand
      return ra_->reg2offset(ra_->get_reg_first(node->in(idx)));/* sReg */
    }
    // Access register number from myself
    return ra_->reg2offset(ra_->get_reg_first(node));/* sReg */
  }
  virtual int       constant_disp() const { return Type::OffsetBot; }
#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "stackSlotD";}
#endif
};

class stackSlotLOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  stackSlotLOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return STACKSLOTL; }
  virtual const Type    *type() const { return TypeLong::LONG; } // stackSlotX

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    if( idx != 0 ) {
      // Access register number for input operand
      return ra_->reg2offset(ra_->get_reg_first(node->in(idx)));/* sReg */
    }
    // Access register number from myself
    return ra_->reg2offset(ra_->get_reg_first(node));/* sReg */
  }
  virtual int       constant_disp() const { return Type::OffsetBot; }
#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "stackSlotL";}
#endif
};

class indirect_win95_safeOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
public:
  indirect_win95_safeOper() {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return INDIRECT_WIN95_SAFE; }
  virtual const Type *type() const { return TypePtr::BOTTOM; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x0;  }
  virtual int            constant_disp() const { return 0x0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual const char    *Name() const { return "indirect_win95_safe";}
#endif
};

class indOffset8_win95_safeOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffset8_win95_safeOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSET8_WIN95_SAFE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indOffset8_win95_safe";}
#endif
};

class indOffset32_win95_safeOper : public MachOper { 
private:
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indOffset32_win95_safeOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDOFFSET32_WIN95_SAFE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x4;  }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indOffset32_win95_safe";}
#endif
};

class indIndexOffset_win95_safeOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indIndexOffset_win95_safeOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDINDEXOFFSET_WIN95_SAFE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { return 0x0;  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c0;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c0;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indIndexOffset_win95_safe";}
#endif
};

class indIndexScale_win95_safeOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
public:
  indIndexScale_win95_safeOper(int32 c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual void set_con( jint c0 ) { _c0 = c0; }
  virtual uint           opcode() const { return INDINDEXSCALE_WIN95_SAFE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { // Replacement variable: scale
    return (int)_c0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
return 0x0;  }
  virtual int            constant_disp() const { return 0x0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
  }
  virtual const char    *Name() const { return "indIndexScale_win95_safe";}
#endif
};

class indIndexScaleOffset_win95_safeOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 2; }
  virtual const RegMask *in_RegMask(int index) const;
  jint             _c0;
  jint             _c1;
public:
  indIndexScaleOffset_win95_safeOper(int32 c0, int32 c1)  : _c0(c0), _c1(c1) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return INDINDEXSCALEOFFSET_WIN95_SAFE; }

  virtual int            base(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: reg
    return (int)ra_->get_encode(node->in(idx));
  }
  virtual int            base_position() const { return 0; }
  virtual int            index(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: ireg
    return (int)ra_->get_encode(node->in(idx+1));
  }
  virtual int            index_position() const { return 1; }
  virtual int            scale() const { // Replacement variable: scale
    return (int)_c0;
  }
  virtual int            disp(PhaseRegAlloc *ra_, const Node *node, int idx) const { 
// Replacement variable: off
    return (int)_c1;
  }
  virtual int            constant_disp() const { // Replacement variable: off
    return (int)_c1;
  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
   st->print("#%d", _c0);
   st->print("#%d", _c1);
  }
  virtual const char    *Name() const { return "indIndexScaleOffset_win95_safe";}
#endif
};

class cmpOpOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return CMPOP; }
  virtual const Type *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const { return 0x4;  }
  virtual int            not_equal() const { return 0x5;  }
  virtual int            less() const { return 0xC;  }
  virtual int            greater_equal() const { return 0xD;  }
  virtual int            less_equal() const { return 0xE;  }
  virtual int            greater() const { return 0xF;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("le");
    else if( _c0 == BoolTest::ge ) st->print("ge");
    else if( _c0 == BoolTest::lt ) st->print("l");
    else if( _c0 == BoolTest::gt ) st->print("g");
  }
  virtual const char    *Name() const { return "cmpOp";}
#endif
};

class cmpOpUOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpUOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return CMPOPU; }
  virtual const Type *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const { return 0x4;  }
  virtual int            not_equal() const { return 0x5;  }
  virtual int            less() const { return 0x2;  }
  virtual int            greater_equal() const { return 0x3;  }
  virtual int            less_equal() const { return 0x6;  }
  virtual int            greater() const { return 0x7;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
  }
  virtual const char    *Name() const { return "cmpOpU";}
#endif
};

class cmpOpUCFOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpUCFOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return CMPOPUCF; }
  virtual const Type *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const { return 0x4;  }
  virtual int            not_equal() const { return 0x5;  }
  virtual int            less() const { return 0x2;  }
  virtual int            greater_equal() const { return 0x3;  }
  virtual int            less_equal() const { return 0x6;  }
  virtual int            greater() const { return 0x7;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
  }
  virtual const char    *Name() const { return "cmpOpUCF";}
#endif
};

class cmpOpUCF2Oper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOpUCF2Oper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return CMPOPUCF2; }
  virtual const Type *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const { return 0x4;  }
  virtual int            not_equal() const { return 0x5;  }
  virtual int            less() const { return 0x2;  }
  virtual int            greater_equal() const { return 0x3;  }
  virtual int            less_equal() const { return 0x6;  }
  virtual int            greater() const { return 0x7;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
  }
  virtual const char    *Name() const { return "cmpOpUCF2";}
#endif
};

class cmpOp_fcmovOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOp_fcmovOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return CMPOP_FCMOV; }
  virtual const Type *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const { return 0x0C8;  }
  virtual int            not_equal() const { return 0x1C8;  }
  virtual int            less() const { return 0x0C0;  }
  virtual int            greater_equal() const { return 0x1C0;  }
  virtual int            less_equal() const { return 0x0D0;  }
  virtual int            greater() const { return 0x1D0;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
         if( _c0 == BoolTest::eq ) st->print("eq");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("le");
    else if( _c0 == BoolTest::ge ) st->print("ge");
    else if( _c0 == BoolTest::lt ) st->print("lt");
    else if( _c0 == BoolTest::gt ) st->print("gt");
  }
  virtual const char    *Name() const { return "cmpOp_fcmov";}
#endif
};

class cmpOp_commuteOper : public MachOper { 
private:
  virtual uint           num_edges() const { return 0; }
private:
  BoolTest::mask _c0;
public:
  virtual int ccode() const { 
    switch (_c0) {
    case  BoolTest::eq : return equal();
    case  BoolTest::gt : return greater();
    case  BoolTest::lt : return less();
    case  BoolTest::ne : return not_equal();
    case  BoolTest::le : return less_equal();
    case  BoolTest::ge : return greater_equal();
    default : ShouldNotReachHere(); return 0;
    }
  };
  virtual void negate() { 
    _c0 = (BoolTest::mask)((int)_c0^0x4); 
  };
public:
  cmpOp_commuteOper(BoolTest::mask c0)  : _c0(c0) {}
  virtual MachOper      *clone(Compile* C) const;
  virtual uint           opcode() const { return CMPOP_COMMUTE; }
  virtual const Type *type() const { ShouldNotCallThis(); return Type::BOTTOM; }

  virtual int            equal() const { return 0x4;  }
  virtual int            not_equal() const { return 0x5;  }
  virtual int            less() const { return 0xF;  }
  virtual int            greater_equal() const { return 0xE;  }
  virtual int            less_equal() const { return 0xD;  }
  virtual int            greater() const { return 0xC;  }

#ifndef PRODUCT
  virtual void           int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const;
  virtual void           ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const;
  virtual void           dump_spec(outputStream *st) const {
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("ge");
    else if( _c0 == BoolTest::ge ) st->print("le");
    else if( _c0 == BoolTest::lt ) st->print("g");
    else if( _c0 == BoolTest::gt ) st->print("l");
  }
  virtual const char    *Name() const { return "cmpOp_commute";}
#endif
};

//----------------------------Declare classes for Pipelines-----------------

// Pipeline_Use_Cycle_Mask Class
class Pipeline_Use_Cycle_Mask {
protected:
  uint _mask;

public:
  Pipeline_Use_Cycle_Mask() : _mask(0) {}

  Pipeline_Use_Cycle_Mask(uint mask) : _mask(mask) {}

  Pipeline_Use_Cycle_Mask& operator=(const Pipeline_Use_Cycle_Mask &in) {
    _mask = in._mask;
    return *this;
  }

  bool overlaps(const Pipeline_Use_Cycle_Mask &in2) const {
    return ((_mask & in2._mask) != 0);
  }

  Pipeline_Use_Cycle_Mask& operator<<=(int n) {
    _mask <<= n;
    return *this;
  }

  void Or(const Pipeline_Use_Cycle_Mask &in2) {
    _mask |= in2._mask;
  }

  friend Pipeline_Use_Cycle_Mask operator&(const Pipeline_Use_Cycle_Mask &, const Pipeline_Use_Cycle_Mask &);
  friend Pipeline_Use_Cycle_Mask operator|(const Pipeline_Use_Cycle_Mask &, const Pipeline_Use_Cycle_Mask &);

  friend class Pipeline_Use;

  friend class Pipeline_Use_Element;

};

// Pipeline_Use_Element Class
class Pipeline_Use_Element {
protected:
  // Mask of used functional units
  uint _used;

  // Lower and upper bound of functional unit number range
  uint _lb, _ub;

  // Indicates multiple functionals units available
  bool _multiple;

  // Mask of specific used cycles
  Pipeline_Use_Cycle_Mask _mask;

public:
  Pipeline_Use_Element() {}

  Pipeline_Use_Element(uint used, uint lb, uint ub, bool multiple, Pipeline_Use_Cycle_Mask mask)
  : _used(used), _lb(lb), _ub(ub), _multiple(multiple), _mask(mask) {}

  uint used() const { return _used; }

  uint lowerBound() const { return _lb; }

  uint upperBound() const { return _ub; }

  bool multiple() const { return _multiple; }

  Pipeline_Use_Cycle_Mask mask() const { return _mask; }

  bool overlaps(const Pipeline_Use_Element &in2) const {
    return ((_used & in2._used) != 0 && _mask.overlaps(in2._mask));
  }

  void step(uint cycles) {
    _used = 0;
    _mask <<= cycles;
  }

  friend class Pipeline_Use;
};

// Pipeline_Use Class
class Pipeline_Use {
protected:
  // These resources can be used
  uint _resources_used;

  // These resources are used; excludes multiple choice functional units
  uint _resources_used_exclusively;

  // Number of elements
  uint _count;

  // This is the array of Pipeline_Use_Elements
  Pipeline_Use_Element * _elements;

public:
  Pipeline_Use(uint resources_used, uint resources_used_exclusively, uint count, Pipeline_Use_Element *elements)
  : _resources_used(resources_used)
  , _resources_used_exclusively(resources_used_exclusively)
  , _count(count)
  , _elements(elements)
  {}

  uint resourcesUsed() const { return _resources_used; }

  uint resourcesUsedExclusively() const { return _resources_used_exclusively; }

  uint count() const { return _count; }

  Pipeline_Use_Element * element(uint i) const { return &_elements[i]; }

  uint full_latency(uint delay, const Pipeline_Use &pred) const;

  void add_usage(const Pipeline_Use &pred);

  void reset() {
    _resources_used = _resources_used_exclusively = 0;
  };

  void step(uint cycles) {
    reset();
    for (uint i = 0; i < 9; i++)
      (&_elements[i])->step(cycles);
  };

  static const Pipeline_Use         elaborated_use;
  static const Pipeline_Use_Element elaborated_elements[9];

  friend class Pipeline;
};

// Pipeline Class
class Pipeline {
public:
  static bool enabled() { return true; }

  enum {
    _variable_size_instructions = 1,
    _fixed_size_instructions = 0,
    _branch_has_delay_slot = 0,
    _max_instrs_per_bundle = 3,
    _max_bundles_per_cycle = 1,
    _max_instrs_per_cycle = 3
  };

  static bool instr_has_unit_size() { return true; }

// Bundling is not supported

  // Size of an instruction
  static uint instr_unit_size() { return 1; };

  // Bundles do not exist - unsupported
  static uint bundle_unit_size() { assert( false, "Bundles are not supported" ); return 0; };

  static bool requires_bundling() { return false; }

private:
  Pipeline();  // Not a legal constructor

  const unsigned char                   _read_stage_count;
  const unsigned char                   _write_stage;
  const unsigned char                   _fixed_latency;
  const unsigned char                   _instruction_count;
  const bool                            _has_fixed_latency;
  const bool                            _has_branch_delay;
  const bool                            _has_multiple_bundles;
  const bool                            _force_serialization;
  const bool                            _may_have_no_code;
  const enum machPipelineStages * const _read_stages;
  const enum machPipelineStages * const _resource_stage;
  const uint                    * const _resource_cycles;
  const Pipeline_Use                    _resource_use;

public:
  Pipeline(uint                            write_stage,
           uint                            count,
           bool                            has_fixed_latency,
           uint                            fixed_latency,
           uint                            instruction_count,
           bool                            has_branch_delay,
           bool                            has_multiple_bundles,
           bool                            force_serialization,
           bool                            may_have_no_code,
           enum machPipelineStages * const dst,
           enum machPipelineStages * const stage,
           uint                    * const cycles,
           Pipeline_Use                    resource_use)
  : _write_stage(write_stage)
  , _read_stage_count(count)
  , _has_fixed_latency(has_fixed_latency)
  , _fixed_latency(fixed_latency)
  , _read_stages(dst)
  , _resource_stage(stage)
  , _resource_cycles(cycles)
  , _resource_use(resource_use)
  , _instruction_count(instruction_count)
  , _has_branch_delay(has_branch_delay)
  , _has_multiple_bundles(has_multiple_bundles)
  , _force_serialization(force_serialization)
  , _may_have_no_code(may_have_no_code)
  {};

  uint writeStage() const {
    return (_write_stage);
  }

  enum machPipelineStages readStage(int ndx) const {
    return (ndx < _read_stage_count ? _read_stages[ndx] : stage_undefined);  }

  uint resourcesUsed() const {
    return _resource_use.resourcesUsed();
  }

  uint resourcesUsedExclusively() const {
    return _resource_use.resourcesUsedExclusively();
  }

  bool hasFixedLatency() const {
    return (_has_fixed_latency);
  }

  uint fixedLatency() const {
    return (_fixed_latency);
  }

  uint functional_unit_latency(uint start, const Pipeline *pred) const;

  uint operand_latency(uint opnd, const Pipeline *pred) const;

  const Pipeline_Use& resourceUse() const {
    return (_resource_use); }

  const Pipeline_Use_Element * resourceUseElement(uint i) const {
    return (&_resource_use._elements[i]); }

  uint resourceUseCount() const {
    return (_resource_use._count); }

  uint instructionCount() const {
    return (_instruction_count); }

  bool hasBranchDelay() const {
    return (_has_branch_delay); }

  bool hasMultipleBundles() const {
    return (_has_multiple_bundles); }

  bool forceSerialization() const {
    return (_force_serialization); }

  bool mayHaveNoCode() const {
    return (_may_have_no_code); }

//const Pipeline_Use_Cycle_Mask& resourceUseMask(int resource) const {
//  return (_resource_use_masks[resource]); }


#ifndef PRODUCT
  static const char * stageName(uint i);
#endif
};

// Bundle class
class Bundle {
protected:
  enum {
    _unused_delay                   = 0x0,
    _use_nop_delay                  = 0x1,
    _use_unconditional_delay        = 0x2,
    _use_conditional_delay          = 0x3,
    _used_in_conditional_delay      = 0x4,
    _used_in_unconditional_delay    = 0x5,
    _used_in_all_conditional_delays = 0x6,

    _use_delay                      = 0x3,
    _used_in_delay                  = 0x4
  };

  uint _flags          : 3,
       _starts_bundle  : 1,
       _instr_count    : 2,
       _resources_used : 9;
public:
  Bundle() : _flags(_unused_delay), _starts_bundle(0), _instr_count(0), _resources_used(0) {}

  void set_instr_count(uint i) { _instr_count  = i; }
  void set_resources_used(uint i) { _resources_used   = i; }
  void clear_usage() { _flags = _unused_delay; }
  void set_starts_bundle() { _starts_bundle = true; }
  uint flags() const { return (_flags); }
  uint instr_count() const { return (_instr_count); }
  uint resources_used() const { return (_resources_used); }
  bool starts_bundle() const { return (_starts_bundle != 0); }
  void set_use_nop_delay() { _flags = _use_nop_delay; }
  void set_use_unconditional_delay() { _flags = _use_unconditional_delay; }
  void set_use_conditional_delay() { _flags = _use_conditional_delay; }
  void set_used_in_unconditional_delay() { _flags = _used_in_unconditional_delay; }
  void set_used_in_conditional_delay() { _flags = _used_in_conditional_delay; }
  void set_used_in_all_conditional_delays() { _flags = _used_in_all_conditional_delays; }
  bool use_nop_delay() { return (_flags == _use_nop_delay); }
  bool use_unconditional_delay() { return (_flags == _use_unconditional_delay); }
  bool use_conditional_delay() { return (_flags == _use_conditional_delay); }
  bool used_in_unconditional_delay() { return (_flags == _used_in_unconditional_delay); }
  bool used_in_conditional_delay() { return (_flags == _used_in_conditional_delay); }
  bool used_in_all_conditional_delays() { return (_flags == _used_in_all_conditional_delays); }
  bool use_delay() { return ((_flags & _use_delay) != 0); }
  bool used_in_delay() { return ((_flags & _used_in_delay) != 0); }

  enum {
    _nop_count = 1
  };

  static void initialize_nops(MachNode *nop_list[1], Compile* C);

#ifndef PRODUCT
  void dump() const;
#endif
};


//----------------------------Declare classes derived from MachNode----------

class bytes_reverse_intNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_int_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  bytes_reverse_intNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_intNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_int";}
#endif
};

class bytes_reverse_longNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_long_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  bytes_reverse_longNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_longNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_long";}
#endif
};

class bytes_reverse_unsigned_shortNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_unsigned_short_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesUS; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  bytes_reverse_unsigned_shortNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_unsigned_shortNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_unsigned_short";}
#endif
};

class bytes_reverse_shortNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return bytes_reverse_short_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ReverseBytesS; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  bytes_reverse_shortNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(bytes_reverse_shortNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "bytes_reverse_short";}
#endif
};

class countLeadingZerosINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countLeadingZerosI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountLeadingZerosI; }
public:
  countLeadingZerosINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countLeadingZerosINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countLeadingZerosI";}
#endif
};

class countLeadingZerosI_bsrNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countLeadingZerosI_bsr_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountLeadingZerosI; }
public:
  countLeadingZerosI_bsrNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countLeadingZerosI_bsrNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countLeadingZerosI_bsr";}
#endif
};

class countLeadingZerosLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countLeadingZerosL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountLeadingZerosL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  countLeadingZerosLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countLeadingZerosLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countLeadingZerosL";}
#endif
};

class countLeadingZerosL_bsrNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countLeadingZerosL_bsr_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountLeadingZerosL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  countLeadingZerosL_bsrNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countLeadingZerosL_bsrNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countLeadingZerosL_bsr";}
#endif
};

class countTrailingZerosINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countTrailingZerosI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountTrailingZerosI; }
public:
  countTrailingZerosINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countTrailingZerosINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countTrailingZerosI";}
#endif
};

class countTrailingZerosLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return countTrailingZerosL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountTrailingZerosL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  countTrailingZerosLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(countTrailingZerosLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "countTrailingZerosL";}
#endif
};

class popCountINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return popCountI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PopCountI; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  popCountINode() { _cisc_RegMask = NULL;  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(popCountINode); }
  // Rematerialize popCountI
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "popCountI";}
#endif
};

class popCountI_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return popCountI_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PopCountI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  popCountI_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(popCountI_memNode); }
  // Rematerialize popCountI_mem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "popCountI_mem";}
#endif
};

class popCountLNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return popCountL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PopCountL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  popCountLNode() { _cisc_RegMask = NULL;  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(popCountLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "popCountL";}
#endif
};

class popCountL_memNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return popCountL_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PopCountL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  popCountL_memNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(popCountL_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "popCountL_mem";}
#endif
};

class loadBNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadB; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadBNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadB";}
#endif
};

class loadB2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadB2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadB2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadB2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadB2L";}
#endif
};

class loadUBNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadUB; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUBNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUB";}
#endif
};

class loadUB2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUB2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUB2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUB2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUB2L";}
#endif
};

class loadUB2L_immI8Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUB2L_immI8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUB2L_immI8Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUB2L_immI8Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUB2L_immI8";}
#endif
};

class loadSNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadS; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadSNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadS";}
#endif
};

class loadS2BNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadS2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadS2BNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadS2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadS2B";}
#endif
};

class loadS2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadS2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadS2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadS2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadS2L";}
#endif
};

class loadUSNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadUS; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUSNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS";}
#endif
};

class loadUS2BNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2BNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2B";}
#endif
};

class loadUS2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2L";}
#endif
};

class loadUS2L_immI_255Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2L_immI_255_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2L_immI_255Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2L_immI_255Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2L_immI_255";}
#endif
};

class loadUS2L_immI16Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUS2L_immI16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUS2L_immI16Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUS2L_immI16Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUS2L_immI16";}
#endif
};

class loadINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadI; }
  virtual MachNode      *peephole(Block *block, int block_index, PhaseRegAlloc *ra_, int &deleted, Compile *C);
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadINode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI";}
#endif
};

class loadI2BNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2BNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2B";}
#endif
};

class loadI2UBNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2UB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2UBNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2UBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2UB";}
#endif
};

class loadI2SNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2S_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2SNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2SNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2S";}
#endif
};

class loadI2USNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2US_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2USNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2USNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2US";}
#endif
};

class loadI2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L";}
#endif
};

class loadI2L_immI_255Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_immI_255_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_immI_255Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_immI_255Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_immI_255";}
#endif
};

class loadI2L_immI_65535Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_immI_65535_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_immI_65535Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_immI_65535Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_immI_65535";}
#endif
};

class loadI2L_immINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadI2L_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadI2L_immINode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadI2L_immINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadI2L_immI";}
#endif
};

class loadUI2LNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadUI2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadUI2L; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadUI2LNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadUI2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadUI2L";}
#endif
};

class loadLNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL";}
#endif
};

class loadL_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadL_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadL_volatileNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadL_volatileNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadL_volatile";}
#endif
};

class loadLX_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadLX_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLX_volatileNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLX_volatileNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadLX_volatile";}
#endif
};

class loadLX_reg_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadLX_reg_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLX_reg_volatileNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLX_reg_volatileNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadLX_reg_volatile";}
#endif
};

class loadRangeNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadRange_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadRange; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadRangeNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadRangeNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadRange";}
#endif
};

class loadPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadPNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadPNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadP";}
#endif
};

class loadKlassNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadKlass_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadKlass; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadKlassNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(loadKlassNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadKlass";}
#endif
};

class loadDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadDNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadD";}
#endif
};

class loadXDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadXD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadXDNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadXDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadXD";}
#endif
};

class loadXD_partialNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadXD_partial_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadXD_partialNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadXD_partialNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadXD_partial";}
#endif
};

class loadXNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadXNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadX";}
#endif
};

class loadFNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadFNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadFNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadF";}
#endif
};

class loadA8BNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadA8B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Load8B; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadA8BNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadA8BNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadA8B";}
#endif
};

class loadA4SNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadA4S_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Load4S; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadA4SNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadA4SNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadA4S";}
#endif
};

class loadA4CNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadA4C_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Load4C; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadA4CNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadA4CNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadA4C";}
#endif
};

class load2IUNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return load2IU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Load2I; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  load2IUNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(load2IUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "load2IU";}
#endif
};

class loadA2FNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadA2F_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Load2F; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadA2FNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadA2FNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadA2F";}
#endif
};

class leaP8Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaP8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  leaP8Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(leaP8Node); }
  // Rematerialize leaP8
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaP8";}
#endif
};

class leaP32Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaP32_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  leaP32Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(leaP32Node); }
  // Rematerialize leaP32
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaP32";}
#endif
};

class leaPIdxOffNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaPIdxOff_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  leaPIdxOffNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(leaPIdxOffNode); }
  // Rematerialize leaPIdxOff
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaPIdxOff";}
#endif
};

class leaPIdxScaleNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaPIdxScale_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  leaPIdxScaleNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(leaPIdxScaleNode); }
  // Rematerialize leaPIdxScale
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaPIdxScale";}
#endif
};

class leaPIdxScaleOffNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaPIdxScaleOff_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  leaPIdxScaleOffNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(leaPIdxScaleOffNode); }
  // Rematerialize leaPIdxScaleOff
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaPIdxScaleOff";}
#endif
};

class loadConINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConI; }
public:
  loadConINode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConINode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConI
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeInt::make(opnd_array(1)->constant());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI";}
#endif
};

class loadConI0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConI0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConI; }
public:
  loadConI0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConI0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConI0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeInt::make(opnd_array(1)->constant());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConI0";}
#endif
};

class loadConPNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConP; }
  virtual int            reloc()   const;
public:
  loadConPNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConPNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  opnd_array(1)->type();
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConP";}
#endif
};

class loadConLNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConL; }
public:
  loadConLNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConL
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeLong::make(opnd_array(1)->constantL());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConL";}
#endif
};

class loadConL0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConL0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConL; }
public:
  loadConL0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConL0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConL0
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeLong::make(opnd_array(1)->constantL());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConL0";}
#endif
};

class loadConFNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConF; }
  virtual int            reloc()   const;
public:
  loadConFNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConFNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConF
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeF::make(opnd_array(1)->constantF());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConF";}
#endif
};

class loadConXNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConF; }
  virtual int            reloc()   const;
public:
  loadConXNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConXNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConX
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeF::make(opnd_array(1)->constantF());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConX";}
#endif
};

class loadConX0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConX0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConF; }
  virtual int            reloc()   const;
public:
  loadConX0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConX0Node); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConX0
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeF::make(opnd_array(1)->constantF());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConX0";}
#endif
};

class loadConDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConD; }
  virtual int            reloc()   const;
public:
  loadConDNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConD
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeD::make(opnd_array(1)->constantD());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConD";}
#endif
};

class loadConXDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConXD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConD; }
  virtual int            reloc()   const;
public:
  loadConXDNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConXDNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConXD
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeD::make(opnd_array(1)->constantD());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConXD";}
#endif
};

class loadConXD0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConXD0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConD; }
  virtual int            reloc()   const;
public:
  loadConXD0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConXD0Node); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConXD0
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeD::make(opnd_array(1)->constantD());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConXD0";}
#endif
};

class loadSSINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadSSI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  loadSSINode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSSINode); }
  // Rematerialize loadSSI
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadSSI";}
#endif
};

class loadSSLNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadSSL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  loadSSLNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSSLNode); }
  // Rematerialize loadSSL
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadSSL";}
#endif
};

class loadSSPNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadSSP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  loadSSPNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSSPNode); }
  // Rematerialize loadSSP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadSSP";}
#endif
};

class loadSSFNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadSSF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  loadSSFNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSSFNode); }
  // Rematerialize loadSSF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadSSF";}
#endif
};

class loadSSDNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadSSD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  loadSSDNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadSSDNode); }
  // Rematerialize loadSSD
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadSSD";}
#endif
};

class prefetchr0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchr0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchRead; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchr0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchr0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchr0";}
#endif
};

class prefetchrNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchr_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchRead; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchrNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchrNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchr";}
#endif
};

class prefetchrNTANode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchrNTA_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchRead; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchrNTANode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchrNTANode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchrNTA";}
#endif
};

class prefetchrT0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchrT0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchRead; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchrT0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchrT0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchrT0";}
#endif
};

class prefetchrT2Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchrT2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchRead; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchrT2Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchrT2Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchrT2";}
#endif
};

class prefetchw0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchw0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchWrite; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchw0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchw0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchw0";}
#endif
};

class prefetchwNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchw_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchWrite; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchwNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchwNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchw";}
#endif
};

class prefetchwNTANode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchwNTA_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchWrite; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchwNTANode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchwNTANode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchwNTA";}
#endif
};

class prefetchwT0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchwT0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchWrite; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchwT0Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchwT0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchwT0";}
#endif
};

class prefetchwT2Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return prefetchwT2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PrefetchWrite; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  prefetchwT2Node() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(prefetchwT2Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "prefetchwT2";}
#endif
};

class storeBNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreB; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeBNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeB";}
#endif
};

class storeCNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeC_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreC; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeCNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeCNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeC";}
#endif
};

class storeINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeI";}
#endif
};

class storeLNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeLNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL";}
#endif
};

class storeL2INode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL2I_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeL2INode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeL2INode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL2I";}
#endif
};

class storeL_volatileNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeL_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeL_volatileNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeL_volatileNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeL_volatile";}
#endif
};

class storeLX_volatileNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeLX_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeLX_volatileNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeLX_volatileNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeLX_volatile";}
#endif
};

class storeLX_reg_volatileNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeLX_reg_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreL; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeLX_reg_volatileNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeLX_reg_volatileNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeLX_reg_volatile";}
#endif
};

class storePNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storePNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storePNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeP";}
#endif
};

class storeImmINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeImmI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeImmINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeImmINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeImmI";}
#endif
};

class storeImmI16Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeImmI16_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreC; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeImmI16Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeImmI16Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeImmI16";}
#endif
};

class storeImmPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeImmP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeImmPNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeImmPNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeImmP";}
#endif
};

class storeImmBNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeImmB_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreB; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeImmBNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeImmBNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeImmB";}
#endif
};

class storeA8BNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeA8B_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Store8B; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeA8BNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeA8BNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeA8B";}
#endif
};

class storeA4CNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeA4C_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Store4C; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeA4CNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeA4CNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeA4C";}
#endif
};

class storeA2INode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeA2I_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Store2I; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeA2INode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeA2INode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeA2I";}
#endif
};

class storeImmCMNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeImmCM_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreCM; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeImmCMNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeImmCMNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeImmCM";}
#endif
};

class storeDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeD";}
#endif
};

class storeD_roundedNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeD_rounded_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeD_roundedNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeD_roundedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeD_rounded";}
#endif
};

class storeXDNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeXD_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeXDNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeXDNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeXD";}
#endif
};

class storeXNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeXNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeX";}
#endif
};

class storeA2FNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeA2F_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Store2F; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeA2FNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeA2FNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeA2F";}
#endif
};

class storeFNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeFNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeFNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeF";}
#endif
};

class storeF_roundedNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeF_rounded_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeF_roundedNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeF_roundedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeF_rounded";}
#endif
};

class storeF_DroundedNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeF_Drounded_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeF_DroundedNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeF_DroundedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeF_Drounded";}
#endif
};

class storeF_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeF_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeF_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeF_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeF_imm";}
#endif
};

class storeX_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeX_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeX_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(storeX_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeX_imm";}
#endif
};

class storeSSINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeSSI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RegI; }
public:
  storeSSINode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Copy); }
  virtual uint           size_of() const { return sizeof(storeSSINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeSSI";}
#endif
};

class storeSSPNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeSSP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RegP; }
public:
  storeSSPNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Copy); }
  virtual uint           size_of() const { return sizeof(storeSSPNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return in(1)->bottom_type(); } // Copy?
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeSSP";}
#endif
};

class storeSSLNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeSSL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RegL; }
public:
  storeSSLNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Copy); }
  virtual uint           size_of() const { return sizeof(storeSSLNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeSSL";}
#endif
};

class membar_acquireNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_acquire_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarAcquire; }
public:
  membar_acquireNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_acquireNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_acquire";}
#endif
};

class membar_acquire_lockNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_acquire_lock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarAcquire; }
public:
  membar_acquire_lockNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_acquire_lockNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_acquire_lock";}
#endif
};

class membar_releaseNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_release_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarRelease; }
public:
  membar_releaseNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_releaseNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_release";}
#endif
};

class membar_release_lockNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_release_lock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarRelease; }
public:
  membar_release_lockNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_release_lockNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_release_lock";}
#endif
};

class membar_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return membar_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarVolatile; }
public:
  membar_volatileNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(membar_volatileNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize membar_volatile
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "membar_volatile";}
#endif
};

class unnecessary_membar_volatileNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return unnecessary_membar_volatile_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MemBarVolatile; }
public:
  unnecessary_membar_volatileNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(unnecessary_membar_volatileNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::MEMBAR; } // matched MemBar
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "unnecessary_membar_volatile";}
#endif
};

class castX2PNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castX2P_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastX2P; }
  virtual uint           oper_input_base() const { return 1; }
public:
  castX2PNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castX2PNode); }
  // Rematerialize castX2P
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castX2P";}
#endif
};

class castP2XNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castP2X_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastP2X; }
public:
  castP2XNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castP2XNode); }
  // Rematerialize castP2X
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castP2X";}
#endif
};

class cmovI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovI_regNode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_reg";}
#endif
};

class cmovI_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovI_regUNode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_regU";}
#endif
};

class cmovI_regUCFNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_regUCF_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovI_regUCFNode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovI_regUCFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_regUCF";}
#endif
};

class cmovI_memNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovI_memNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovI_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_mem";}
#endif
};

class cmovI_memUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_memU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovI_memUNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovI_memUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_memU";}
#endif
};

class cmovI_memUCFNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovI_memUCF_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovI_memUCFNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovI_memUCFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovI_memUCF";}
#endif
};

class cmovP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovP_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovP_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovP_reg";}
#endif
};

class cmovP_reg_nonP6Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovP_reg_nonP6_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovP_reg_nonP6Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovP_reg_nonP6Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovP_reg_nonP6";}
#endif
};

class cmovP_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovP_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovP_regUNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovP_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovP_regU";}
#endif
};

class cmovP_regUCFNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovP_regUCF_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovP_regUCFNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovP_regUCFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovP_regUCF";}
#endif
};

class fcmovD_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovD_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovD_regUNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovD_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovD_regU";}
#endif
};

class fcmovF_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovF_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovF_regUNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovF_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovF_regU";}
#endif
};

class fcmovD_regSNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovD_regS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovD_regSNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovD_regSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovD_regS";}
#endif
};

class fcmovF_regSNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovF_regS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovF_regSNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovF_regSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovF_regS";}
#endif
};

class fcmovX_regSNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovX_regS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovX_regSNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovX_regSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovX_regS";}
#endif
};

class fcmovXD_regSNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovXD_regS_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovXD_regSNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovXD_regSNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovXD_regS";}
#endif
};

class fcmovX_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovX_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovX_regUNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovX_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovX_regU";}
#endif
};

class fcmovX_regUCFNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovX_regUCF_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovX_regUCFNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovX_regUCFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovX_regUCF";}
#endif
};

class fcmovXD_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovXD_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovXD_regUNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovXD_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovXD_regU";}
#endif
};

class fcmovXD_regUCFNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return fcmovXD_regUCF_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  fcmovXD_regUCFNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(fcmovXD_regUCFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "fcmovXD_regUCF";}
#endif
};

class cmovL_regNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovL_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovL_regNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovL_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovL_reg";}
#endif
};

class cmovL_regUNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovL_regU_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovL_regUNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovL_regUNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovL_regU";}
#endif
};

class cmovL_regUCFNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovL_regUCF_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovL_regUCFNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovL_regUCFNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovL_regUCF";}
#endif
};

class addI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_eReg";}
#endif
};

class addI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  addI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_eReg_imm";}
#endif
};

class incI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return incI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  incI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(incI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "incI_eReg";}
#endif
};

class leaI_eReg_immINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaI_eReg_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
public:
  leaI_eReg_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(leaI_eReg_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaI_eReg_immI";}
#endif
};

class leaP_eReg_immINode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return leaP_eReg_immI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  leaP_eReg_immINode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(leaP_eReg_immINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "leaP_eReg_immI";}
#endif
};

class decI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return decI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  decI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(decI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "decI_eReg";}
#endif
};

class addP_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addP_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 2; }
public:
  addP_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addP_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addP_eReg";}
#endif
};

class addP_eReg_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addP_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 2; }
public:
  addP_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addP_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addP_eReg_imm";}
#endif
};

class addI_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addI_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addI_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_eReg_mem";}
#endif
};

class addI_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addI_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addI_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_eReg_mem_0";}
#endif
};

class addI_mem_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_mem_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addI_mem_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_mem_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_mem_eReg";}
#endif
};

class addI_mem_eReg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_mem_eReg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addI_mem_eReg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_mem_eReg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_mem_eReg_0";}
#endif
};

class addI_mem_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addI_mem_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addI_mem_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addI_mem_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addI_mem_imm";}
#endif
};

class incI_memNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return incI_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  incI_memNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(incI_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "incI_mem";}
#endif
};

class decI_memNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return decI_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  decI_memNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(decI_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "decI_mem";}
#endif
};

class checkCastPPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return checkCastPP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CheckCastPP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 1; }
public:
  checkCastPPNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(checkCastPPNode); }
  // Rematerialize checkCastPP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "checkCastPP";}
#endif
};

class castPPNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castPP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastPP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 1; }
public:
  castPPNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castPPNode); }
  // Rematerialize castPP
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castPP";}
#endif
};

class castIINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return castII_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CastII; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  castIINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(castIINode); }
  // Rematerialize castII
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "castII";}
#endif
};

class loadPLockedNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadPLocked_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadPLocked; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadPLockedNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadPLockedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadPLocked";}
#endif
};

class loadLLockedNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadLLocked_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadLLocked; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLLockedNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLLockedNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadLLocked";}
#endif
};

class loadLX_LockedNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadLX_Locked_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadLLocked; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLX_LockedNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLX_LockedNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadLX_Locked";}
#endif
};

class loadLX_reg_LockedNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadLX_reg_Locked_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LoadLLocked; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  loadLX_reg_LockedNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(loadLX_reg_LockedNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadLX_reg_Locked";}
#endif
};

class storePConditionalNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storePConditional_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StorePConditional; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storePConditionalNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(storePConditionalNode); }
  // Rematerialize storePConditional
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storePConditional";}
#endif
};

class storeIConditionalNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeIConditional_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreIConditional; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeIConditionalNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(storeIConditionalNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  // Rematerialize storeIConditional
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeIConditional";}
#endif
};

class storeLConditionalNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return storeLConditional_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreLConditional; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  storeLConditionalNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(storeLConditionalNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  // Rematerialize storeLConditional
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "storeLConditional";}
#endif
};

class compareAndSwapLNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compareAndSwapL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CompareAndSwapL; }
  virtual uint           oper_input_base() const { return 2; }
public:
  compareAndSwapLNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compareAndSwapLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compareAndSwapL";}
#endif
};

class compareAndSwapPNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compareAndSwapP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CompareAndSwapP; }
  virtual uint           oper_input_base() const { return 2; }
public:
  compareAndSwapPNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compareAndSwapPNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compareAndSwapP";}
#endif
};

class compareAndSwapINode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compareAndSwapI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CompareAndSwapI; }
  virtual uint           oper_input_base() const { return 2; }
public:
  compareAndSwapINode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compareAndSwapINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compareAndSwapI";}
#endif
};

class subI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  subI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_eReg";}
#endif
};

class subI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  subI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_eReg_imm";}
#endif
};

class subI_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  subI_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(subI_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_eReg_mem";}
#endif
};

class subI_mem_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subI_mem_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  subI_mem_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subI_mem_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subI_mem_eReg";}
#endif
};

class subP_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subP_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddP; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual uint           oper_input_base() const { return 2; }
public:
  subP_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subP_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subP_eReg";}
#endif
};

class negI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  negI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negI_eReg";}
#endif
};

class mulI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_eReg";}
#endif
};

class mulI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulI; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulI_eReg_immNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_eReg_imm";}
#endif
};

class loadConL_low_onlyNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return loadConL_low_only_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConL; }
public:
  loadConL_low_onlyNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Con); }
  virtual uint           size_of() const { return sizeof(loadConL_low_onlyNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize loadConL_low_only
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const class Type *bottom_type() const{
    return  TypeLong::make(opnd_array(1)->constantL());
  };
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "loadConL_low_only";}
#endif
};

class mulI_imm_highNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_imm_high_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  mulI_imm_highNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_imm_highNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_imm_high";}
#endif
};

class mulI_imm_high_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_imm_high_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  mulI_imm_high_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_imm_high_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_imm_high_0";}
#endif
};

class mulI_imm_RShift_highNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_imm_RShift_high_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  mulI_imm_RShift_highNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_imm_RShift_highNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_imm_RShift_high";}
#endif
};

class mulI_imm_RShift_high_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_imm_RShift_high_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  mulI_imm_RShift_high_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI_imm_RShift_high_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_imm_RShift_high_0";}
#endif
};

class mulI_mem_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_mem_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulI_mem_immNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulI_mem_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_mem_imm";}
#endif
};

class mulINode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulINode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulINode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI";}
#endif
};

class mulI_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulI_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulI_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI_0";}
#endif
};

class mulI2LNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI2L_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
public:
  mulI2LNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI2LNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI2L";}
#endif
};

class mulI2L_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulI2L_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
public:
  mulI2L_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulI2L_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulI2L_0";}
#endif
};

class mulIS_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulIS_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
public:
  mulIS_eRegNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulIS_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulIS_eReg";}
#endif
};

class mulIS_eReg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulIS_eReg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
public:
  mulIS_eReg_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulIS_eReg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulIS_eReg_0";}
#endif
};

class mulL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_eReg";}
#endif
};

class mulL_eReg_lhi0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_eReg_lhi0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_eReg_lhi0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_eReg_lhi0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_eReg_lhi0";}
#endif
};

class mulL_eReg_rhi0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_eReg_rhi0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_eReg_rhi0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_eReg_rhi0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_eReg_rhi0";}
#endif
};

class mulL_eReg_hi0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_eReg_hi0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_eReg_hi0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_eReg_hi0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_eReg_hi0";}
#endif
};

class mulL_eReg_conNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulL_eReg_con_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  mulL_eReg_conNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulL_eReg_conNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulL_eReg_con";}
#endif
};

class divI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  divI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divI_eReg";}
#endif
};

class divL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivL; }
public:
  divL_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divL_eReg";}
#endif
};

class divModI_eReg_divmodNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divModI_eReg_divmod_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivModI; }
public:
  divModI_eReg_divmodNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divModI_eReg_divmodNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divModI_eReg_divmod";}
#endif
};

class modI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModI; }
public:
  modI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modI_eReg";}
#endif
};

class modL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModL; }
public:
  modL_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modL_eReg";}
#endif
};

class shlI_eReg_1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlI_eReg_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlI_eReg_1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlI_eReg_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlI_eReg_1";}
#endif
};

class salI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return salI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  salI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(salI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "salI_eReg_imm";}
#endif
};

class salI_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return salI_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  salI_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(salI_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "salI_eReg_CL";}
#endif
};

class sarI_eReg_1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_eReg_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarI_eReg_1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_eReg_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_eReg_1";}
#endif
};

class sarI_mem_1Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_mem_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  sarI_mem_1Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_mem_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_mem_1";}
#endif
};

class sarI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_eReg_imm";}
#endif
};

class sarI_mem_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_mem_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  sarI_mem_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_mem_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_mem_imm";}
#endif
};

class sarI_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarI_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarI_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarI_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarI_eReg_CL";}
#endif
};

class shrI_eReg_1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrI_eReg_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrI_eReg_1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrI_eReg_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrI_eReg_1";}
#endif
};

class shrI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrI_eReg_imm";}
#endif
};

class i2bNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return i2b_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  i2bNode() { _cisc_RegMask = NULL;  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(i2bNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "i2b";}
#endif
};

class i2sNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return i2s_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftI; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  i2sNode() { _cisc_RegMask = NULL;  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(i2sNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "i2s";}
#endif
};

class shrI_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrI_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrI_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrI_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrI_eReg_CL";}
#endif
};

class andI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  andI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_eReg";}
#endif
};

class andI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  andI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_eReg_imm";}
#endif
};

class andI_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andI_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(andI_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_eReg_mem";}
#endif
};

class andI_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andI_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(andI_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_eReg_mem_0";}
#endif
};

class andI_mem_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_mem_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andI_mem_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_mem_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_mem_eReg";}
#endif
};

class andI_mem_eReg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_mem_eReg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andI_mem_eReg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_mem_eReg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_mem_eReg_0";}
#endif
};

class andI_mem_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andI_mem_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andI_mem_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andI_mem_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andI_mem_imm";}
#endif
};

class orI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  orI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_eReg";}
#endif
};

class orI_eReg_castP2XNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_eReg_castP2X_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  orI_eReg_castP2XNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_eReg_castP2XNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_eReg_castP2X";}
#endif
};

class orI_eReg_castP2X_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_eReg_castP2X_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  orI_eReg_castP2X_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_eReg_castP2X_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_eReg_castP2X_0";}
#endif
};

class orI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  orI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_eReg_imm";}
#endif
};

class orI_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orI_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(orI_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_eReg_mem";}
#endif
};

class orI_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orI_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(orI_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_eReg_mem_0";}
#endif
};

class orI_mem_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_mem_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orI_mem_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_mem_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_mem_eReg";}
#endif
};

class orI_mem_eReg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_mem_eReg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orI_mem_eReg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_mem_eReg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_mem_eReg_0";}
#endif
};

class orI_mem_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orI_mem_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orI_mem_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orI_mem_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orI_mem_imm";}
#endif
};

class rolI_eReg_imm1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_imm1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_imm1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_imm1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_imm1";}
#endif
};

class rolI_eReg_imm8Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_imm8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_imm8Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_imm8Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_imm8";}
#endif
};

class rolI_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_CL";}
#endif
};

class rolI_eReg_i1Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_i1_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_i1Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_i1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_i1";}
#endif
};

class rolI_eReg_i1_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_i1_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_i1_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_i1_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_i1_0";}
#endif
};

class rolI_eReg_i8Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_i8_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_i8Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_i8Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_i8";}
#endif
};

class rolI_eReg_i8_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_i8_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_i8_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_i8_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_i8_0";}
#endif
};

class rolI_eReg_Var_C0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_Var_C0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_Var_C0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_Var_C0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_Var_C0";}
#endif
};

class rolI_eReg_Var_C0_0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_Var_C0_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_Var_C0_0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_Var_C0_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_Var_C0_0";}
#endif
};

class rolI_eReg_Var_C32Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_Var_C32_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_Var_C32Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_Var_C32Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_Var_C32";}
#endif
};

class rolI_eReg_Var_C32_0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rolI_eReg_Var_C32_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rolI_eReg_Var_C32_0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rolI_eReg_Var_C32_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rolI_eReg_Var_C32_0";}
#endif
};

class rorI_eReg_imm1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_imm1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_imm1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_imm1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_imm1";}
#endif
};

class rorI_eReg_imm8Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_imm8_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_imm8Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_imm8Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_imm8";}
#endif
};

class rorI_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_CL";}
#endif
};

class rorI_eReg_i1Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_i1_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_i1Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_i1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_i1";}
#endif
};

class rorI_eReg_i1_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_i1_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_i1_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_i1_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_i1_0";}
#endif
};

class rorI_eReg_i8Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_i8_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_i8Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_i8Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_i8";}
#endif
};

class rorI_eReg_i8_0Node : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_i8_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_i8_0Node() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_i8_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_i8_0";}
#endif
};

class rorI_eReg_Var_C0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_Var_C0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_Var_C0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_Var_C0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_Var_C0";}
#endif
};

class rorI_eReg_Var_C0_0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_Var_C0_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_Var_C0_0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_Var_C0_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_Var_C0_0";}
#endif
};

class rorI_eReg_Var_C32Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_Var_C32_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_Var_C32Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_Var_C32Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_Var_C32";}
#endif
};

class rorI_eReg_Var_C32_0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rorI_eReg_Var_C32_0_rule; }
  virtual int            ideal_Opcode() const { return Op_OrI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  rorI_eReg_Var_C32_0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rorI_eReg_Var_C32_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rorI_eReg_Var_C32_0";}
#endif
};

class xorI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  xorI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_eReg";}
#endif
};

class xorI_eReg_im1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_eReg_im1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  xorI_eReg_im1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_eReg_im1Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_eReg_im1";}
#endif
};

class xorI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  xorI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_eReg_imm";}
#endif
};

class xorI_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorI_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xorI_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_eReg_mem";}
#endif
};

class xorI_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorI_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xorI_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_eReg_mem_0";}
#endif
};

class xorI_mem_eRegNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_mem_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorI_mem_eRegNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_mem_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_mem_eReg";}
#endif
};

class xorI_mem_eReg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_mem_eReg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorI_mem_eReg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_mem_eReg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_mem_eReg_0";}
#endif
};

class xorI_mem_immNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorI_mem_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorI_mem_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorI_mem_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorI_mem_imm";}
#endif
};

class movI_nocopyNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return movI_nocopy_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  movI_nocopyNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(movI_nocopyNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize movI_nocopy
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "movI_nocopy";}
#endif
};

class ci2bNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return ci2b_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  ci2bNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(ci2bNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "ci2b";}
#endif
};

class convI2BNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2B_rule; }
  virtual int            ideal_Opcode() const { return Op_Conv2B; }
public:
  convI2BNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2B";}
#endif
};

class movP_nocopyNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return movP_nocopy_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
public:
  movP_nocopyNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(movP_nocopyNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize movP_nocopy
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "movP_nocopy";}
#endif
};

class cp2bNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cp2b_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cp2bNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cp2bNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cp2b";}
#endif
};

class convP2BNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convP2B_rule; }
  virtual int            ideal_Opcode() const { return Op_Conv2B; }
public:
  convP2BNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convP2BNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convP2B";}
#endif
};

class cmpLTMaskNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpLTMask_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpLTMask; }
public:
  cmpLTMaskNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpLTMaskNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpLTMask";}
#endif
};

class cmpLTMask0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpLTMask0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpLTMask; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cmpLTMask0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpLTMask0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpLTMask0";}
#endif
};

class cadd_cmpLTMaskNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMaskNode() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMaskNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask";}
#endif
};

class cadd_cmpLTMask_1Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask_1Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask_1";}
#endif
};

class cadd_cmpLTMask_0Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  cadd_cmpLTMask_0Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask_0";}
#endif
};

class cadd_cmpLTMask_2Node : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cadd_cmpLTMask_2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cadd_cmpLTMask_2Node() {  _num_opnds = 6; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cadd_cmpLTMask_2Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cadd_cmpLTMask_2";}
#endif
};

class addL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addL_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addL_eReg";}
#endif
};

class addL_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addL_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  addL_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addL_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addL_eReg_imm";}
#endif
};

class addL_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addL_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addL_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addL_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addL_eReg_mem";}
#endif
};

class addL_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addL_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addL_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addL_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addL_eReg_mem_0";}
#endif
};

class subL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  subL_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subL_eReg";}
#endif
};

class subL_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subL_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  subL_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subL_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subL_eReg_imm";}
#endif
};

class subL_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subL_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  subL_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(subL_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subL_eReg_mem";}
#endif
};

class negL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  negL_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negL_eReg";}
#endif
};

class andL_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andL_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  andL_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andL_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andL_eReg";}
#endif
};

class andL_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andL_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  andL_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(andL_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andL_eReg_imm";}
#endif
};

class andL_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andL_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andL_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(andL_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andL_eReg_mem";}
#endif
};

class andL_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return andL_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  andL_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(andL_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "andL_eReg_mem_0";}
#endif
};

class orl_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orl_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  orl_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orl_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orl_eReg";}
#endif
};

class orl_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orl_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  orl_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(orl_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orl_eReg_imm";}
#endif
};

class orl_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orl_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orl_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(orl_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orl_eReg_mem";}
#endif
};

class orl_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return orl_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_OrL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  orl_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(orl_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "orl_eReg_mem_0";}
#endif
};

class xorl_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorl_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  xorl_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorl_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorl_eReg";}
#endif
};

class xorl_eReg_im1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorl_eReg_im1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  xorl_eReg_im1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorl_eReg_im1Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorl_eReg_im1";}
#endif
};

class xorl_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorl_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  xorl_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(xorl_eReg_immNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorl_eReg_imm";}
#endif
};

class xorl_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorl_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorl_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xorl_eReg_memNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorl_eReg_mem";}
#endif
};

class xorl_eReg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return xorl_eReg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_XorL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  xorl_eReg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(xorl_eReg_mem_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "xorl_eReg_mem_0";}
#endif
};

class shlL_eReg_1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_eReg_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_eReg_1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_eReg_1Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_eReg_1";}
#endif
};

class shlL_eReg_2Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_eReg_2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_eReg_2Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_eReg_2Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_eReg_2";}
#endif
};

class shlL_eReg_3Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_eReg_3_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_eReg_3Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_eReg_3Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_eReg_3";}
#endif
};

class shlL_eReg_1_31Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_eReg_1_31_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_eReg_1_31Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_eReg_1_31Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_eReg_1_31";}
#endif
};

class shlL_eReg_32_63Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shlL_eReg_32_63_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shlL_eReg_32_63Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shlL_eReg_32_63Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shlL_eReg_32_63";}
#endif
};

class salL_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return salL_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  salL_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(salL_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "salL_eReg_CL";}
#endif
};

class shrL_eReg_1_31Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_eReg_1_31_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrL_eReg_1_31Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_eReg_1_31Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_eReg_1_31";}
#endif
};

class shrL_eReg_32_63Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_eReg_32_63_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrL_eReg_32_63Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_eReg_32_63Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_eReg_32_63";}
#endif
};

class shrL_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return shrL_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_URShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  shrL_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(shrL_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "shrL_eReg_CL";}
#endif
};

class sarL_eReg_1_31Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_eReg_1_31_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarL_eReg_1_31Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_eReg_1_31Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_eReg_1_31";}
#endif
};

class sarL_eReg_32_63Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_eReg_32_63_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarL_eReg_32_63Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_eReg_32_63Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_eReg_32_63";}
#endif
};

class sarL_eReg_CLNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sarL_eReg_CL_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RShiftL; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sarL_eReg_CLNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sarL_eReg_CLNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sarL_eReg_CL";}
#endif
};

class cmpD_cc_P6Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_cc_P6_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
public:
  cmpD_cc_P6Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_cc_P6Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpD_cc_P6
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_cc_P6";}
#endif
};

class cmpD_cc_P6CFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_cc_P6CF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
public:
  cmpD_cc_P6CFNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_cc_P6CFNode); }
  // Rematerialize cmpD_cc_P6CF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_cc_P6CF";}
#endif
};

class cmpD_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
public:
  cmpD_ccNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpD_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_cc";}
#endif
};

class cmpD_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD3; }
  virtual int            reloc()   const;
public:
  cmpD_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_0";}
#endif
};

class cmpD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD3; }
public:
  cmpD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpD_reg";}
#endif
};

class cmpXD_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpXD_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmpXD_ccNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpXD_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpXD_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpXD_cc";}
#endif
};

class cmpXD_ccCFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpXD_ccCF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmpXD_ccCFNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpXD_ccCFNode); }
  // Rematerialize cmpXD_ccCF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpXD_ccCF";}
#endif
};

class cmpXD_ccmemNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpXD_ccmem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmpXD_ccmemNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmpXD_ccmemNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpXD_ccmem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpXD_ccmem";}
#endif
};

class cmpXD_ccmemCFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpXD_ccmemCF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmpXD_ccmemCFNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmpXD_ccmemCFNode); }
  // Rematerialize cmpXD_ccmemCF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpXD_ccmemCF";}
#endif
};

class cmpXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD3; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmpXD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpXD_reg";}
#endif
};

class cmpXD_regmemNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpXD_regmem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpD3; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmpXD_regmemNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmpXD_regmemNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpXD_regmem";}
#endif
};

class subD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  subD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subD_reg";}
#endif
};

class subD_reg_roundNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subD_reg_round_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RoundDouble; }
public:
  subD_reg_roundNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subD_reg_roundNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subD_reg_round";}
#endif
};

class subD_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subD_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  subD_reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(subD_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subD_reg_mem";}
#endif
};

class absD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return absD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AbsD; }
public:
  absD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(absD_regNode); }
  // Rematerialize absD_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "absD_reg";}
#endif
};

class absXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return absXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AbsD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  absXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(absXD_regNode); }
  // Rematerialize absXD_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "absXD_reg";}
#endif
};

class negD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_NegD; }
public:
  negD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negD_regNode); }
  // Rematerialize negD_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negD_reg";}
#endif
};

class negXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_NegD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  negXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negXD_regNode); }
  // Rematerialize negXD_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negXD_reg";}
#endif
};

class addD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg";}
#endif
};

class addD_reg_roundNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_round_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RoundDouble; }
public:
  addD_reg_roundNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_reg_roundNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_round";}
#endif
};

class addD_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addD_reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addD_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_mem";}
#endif
};

class addD_reg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addD_reg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addD_reg_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_mem_0";}
#endif
};

class addD_mem_regNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_mem_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addD_mem_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_mem_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_mem_reg";}
#endif
};

class addD_mem_reg_0Node : public MachTypeNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_mem_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StoreD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addD_mem_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_mem_reg_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_mem_reg_0";}
#endif
};

class addD_reg_imm1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_imm1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  addD_reg_imm1Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_reg_imm1Node); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_imm1";}
#endif
};

class addD_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  addD_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_reg_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_imm";}
#endif
};

class addD_reg_imm_roundNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_reg_imm_round_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RoundDouble; }
  virtual int            reloc()   const;
public:
  addD_reg_imm_roundNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_reg_imm_roundNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_reg_imm_round";}
#endif
};

class addXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addXD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addXD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addXD_reg";}
#endif
};

class addXD_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addXD_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  addXD_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addXD_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addXD_imm";}
#endif
};

class addXD_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addXD_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addXD_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addXD_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addXD_mem";}
#endif
};

class addXD_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addXD_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addXD_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addXD_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addXD_mem_0";}
#endif
};

class subXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  subXD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subXD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subXD_reg";}
#endif
};

class subXD_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subXD_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  subXD_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subXD_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subXD_imm";}
#endif
};

class subXD_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subXD_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  subXD_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(subXD_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subXD_mem";}
#endif
};

class mulXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulXD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulXD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulXD_reg";}
#endif
};

class mulXD_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulXD_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  mulXD_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulXD_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulXD_imm";}
#endif
};

class mulXD_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulXD_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulXD_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulXD_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulXD_mem";}
#endif
};

class mulXD_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulXD_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulXD_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulXD_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulXD_mem_0";}
#endif
};

class divXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  divXD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divXD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divXD_reg";}
#endif
};

class divXD_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divXD_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  divXD_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divXD_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divXD_imm";}
#endif
};

class divXD_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divXD_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  divXD_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(divXD_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divXD_mem";}
#endif
};

class mulD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg";}
#endif
};

class strictfp_mulD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return strictfp_mulD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  strictfp_mulD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(strictfp_mulD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "strictfp_mulD_reg";}
#endif
};

class mulD_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  mulD_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulD_reg_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg_imm";}
#endif
};

class mulD_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulD_reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulD_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg_mem";}
#endif
};

class mulD_reg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulD_reg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulD_reg_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg_mem_0";}
#endif
};

class mulD_reg_mem_ciscNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_mem_cisc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulD_reg_mem_ciscNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulD_reg_mem_ciscNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg_mem_cisc";}
#endif
};

class mulD_reg_mem_cisc_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulD_reg_mem_cisc_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulD_reg_mem_cisc_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulD_reg_mem_cisc_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulD_reg_mem_cisc_0";}
#endif
};

class addD_mulD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_mulD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  addD_mulD_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_mulD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_mulD_reg";}
#endif
};

class addD_mulD_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addD_mulD_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  addD_mulD_reg_0Node() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addD_mulD_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addD_mulD_reg_0";}
#endif
};

class subD_mulD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subD_mulD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  subD_mulD_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subD_mulD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subD_mulD_reg";}
#endif
};

class divD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  divD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divD_reg";}
#endif
};

class strictfp_divD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return strictfp_divD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  strictfp_divD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(strictfp_divD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "strictfp_divD_reg";}
#endif
};

class divD_reg_roundNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divD_reg_round_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RoundDouble; }
public:
  divD_reg_roundNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divD_reg_roundNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divD_reg_round";}
#endif
};

class modD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  modD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modD_reg";}
#endif
};

class modXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModD; }
public:
  modXD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modXD_reg";}
#endif
};

class sinD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sinD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SinD; }
public:
  sinD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sinD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sinD_reg";}
#endif
};

class sinXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sinXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SinD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  sinXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sinXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sinXD_reg";}
#endif
};

class cosD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cosD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CosD; }
public:
  cosD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cosD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cosD_reg";}
#endif
};

class cosXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cosXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CosD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  cosXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cosXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cosXD_reg";}
#endif
};

class tanD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return tanD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_TanD; }
public:
  tanD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(tanD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "tanD_reg";}
#endif
};

class tanXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return tanXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_TanD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  tanXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(tanXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "tanXD_reg";}
#endif
};

class atanD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return atanD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AtanD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  atanD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(atanD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "atanD_reg";}
#endif
};

class atanXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return atanXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AtanD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  atanXD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(atanXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "atanXD_reg";}
#endif
};

class sqrtD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SqrtD; }
public:
  sqrtD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sqrtD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtD_reg";}
#endif
};

class powD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return powD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PowD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  powD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(powD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "powD_reg";}
#endif
};

class powXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return powXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PowD; }
public:
  powXD_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(powXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "powXD_reg";}
#endif
};

class expD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return expD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ExpD; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  expD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(expD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "expD_reg";}
#endif
};

class expXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return expXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ExpD; }
public:
  expXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(expXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "expXD_reg";}
#endif
};

class log10D_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return log10D_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Log10D; }
public:
  log10D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(log10D_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "log10D_reg";}
#endif
};

class log10XD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return log10XD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Log10D; }
public:
  log10XD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(log10XD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "log10XD_reg";}
#endif
};

class logD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return logD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LogD; }
public:
  logD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(logD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "logD_reg";}
#endif
};

class logXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return logXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_LogD; }
public:
  logXD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(logXD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "logXD_reg";}
#endif
};

class cmpF_cc_P6Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_cc_P6_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
public:
  cmpF_cc_P6Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_cc_P6Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpF_cc_P6
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_cc_P6";}
#endif
};

class cmpF_cc_P6CFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_cc_P6CF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
public:
  cmpF_cc_P6CFNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_cc_P6CFNode); }
  // Rematerialize cmpF_cc_P6CF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_cc_P6CF";}
#endif
};

class cmpF_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
public:
  cmpF_ccNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpF_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_cc";}
#endif
};

class cmpF_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF3; }
  virtual int            reloc()   const;
public:
  cmpF_0Node() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_0Node); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_0";}
#endif
};

class cmpF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF3; }
public:
  cmpF_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpF_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpF_reg";}
#endif
};

class cmpX_ccNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpX_cc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmpX_ccNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpX_ccNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpX_cc
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpX_cc";}
#endif
};

class cmpX_ccCFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpX_ccCF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmpX_ccCFNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpX_ccCFNode); }
  // Rematerialize cmpX_ccCF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpX_ccCF";}
#endif
};

class cmpX_ccmemNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpX_ccmem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmpX_ccmemNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmpX_ccmemNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpX_ccmem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpX_ccmem";}
#endif
};

class cmpX_ccmemCFNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpX_ccmemCF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmpX_ccmemCFNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmpX_ccmemCFNode); }
  // Rematerialize cmpX_ccmemCF
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpX_ccmemCF";}
#endif
};

class cmpX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF3; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmpX_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpX_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpX_reg";}
#endif
};

class cmpX_regmemNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpX_regmem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpF3; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmpX_regmemNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmpX_regmemNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpX_regmem";}
#endif
};

class subF24_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subF24_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubF; }
public:
  subF24_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subF24_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subF24_reg";}
#endif
};

class subF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  subF_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subF_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subF_reg";}
#endif
};

class addF24_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addF24_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF24_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_reg";}
#endif
};

class addF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addF_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_reg";}
#endif
};

class addX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addX_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addX_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addX_reg";}
#endif
};

class addX_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addX_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  addX_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addX_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addX_imm";}
#endif
};

class addX_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addX_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addX_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addX_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addX_mem";}
#endif
};

class addX_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addX_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addX_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addX_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addX_mem_0";}
#endif
};

class subX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  subX_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subX_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subX_reg";}
#endif
};

class subX_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subX_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  subX_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subX_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subX_imm";}
#endif
};

class subX_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subX_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SubF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  subX_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(subX_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subX_mem";}
#endif
};

class mulX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulX_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulX_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulX_reg";}
#endif
};

class mulX_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulX_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  mulX_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulX_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulX_imm";}
#endif
};

class mulX_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulX_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulX_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulX_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulX_mem";}
#endif
};

class mulX_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulX_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulX_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulX_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulX_mem_0";}
#endif
};

class divX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  divX_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divX_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divX_reg";}
#endif
};

class divX_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divX_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
public:
  divX_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divX_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divX_imm";}
#endif
};

class divX_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divX_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  divX_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(divX_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divX_mem";}
#endif
};

class sqrtX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  sqrtX_regNode() { _cisc_RegMask = NULL;  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sqrtX_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtX_reg";}
#endif
};

class sqrtX_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtX_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  sqrtX_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(sqrtX_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtX_mem";}
#endif
};

class sqrtXD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtXD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SqrtD; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  sqrtXD_regNode() { _cisc_RegMask = NULL;  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(sqrtXD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtXD_reg";}
#endif
};

class sqrtXD_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return sqrtXD_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SqrtD; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  sqrtXD_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(sqrtXD_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "sqrtXD_mem";}
#endif
};

class absF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return absF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AbsF; }
public:
  absF_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(absF_regNode); }
  // Rematerialize absF_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "absF_reg";}
#endif
};

class absX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return absX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AbsF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  absX_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(absX_regNode); }
  // Rematerialize absX_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "absX_reg";}
#endif
};

class negF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_NegF; }
public:
  negF_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negF_regNode); }
  // Rematerialize negF_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negF_reg";}
#endif
};

class negX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return negX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_NegF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  negX_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(negX_regNode); }
  // Rematerialize negX_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "negX_reg";}
#endif
};

class addF24_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF24_reg_memNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF24_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_reg_mem";}
#endif
};

class addF24_reg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_reg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF24_reg_mem_0Node() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF24_reg_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_reg_mem_0";}
#endif
};

class addF_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF_reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_reg_mem";}
#endif
};

class addF_reg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_reg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF_reg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF_reg_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_reg_mem_0";}
#endif
};

class addF24_mem_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_mem_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
  virtual int            reloc()   const;
public:
  addF24_mem_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF24_mem_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_mem_reg";}
#endif
};

class addF24_mem_ciscNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_mem_cisc_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF24_mem_ciscNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF24_mem_ciscNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_mem_cisc";}
#endif
};

class addF24_mem_cisc_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_mem_cisc_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF24_mem_cisc_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF24_mem_cisc_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_mem_cisc_0";}
#endif
};

class addF24_mem_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_mem_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
public:
  addF24_mem_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF24_mem_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_mem_mem";}
#endif
};

class addF24_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF24_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
public:
  addF24_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF24_reg_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF24_reg_imm";}
#endif
};

class addF_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
public:
  addF_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF_reg_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_reg_imm";}
#endif
};

class mulF24_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF24_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulF24_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulF24_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF24_reg";}
#endif
};

class mulF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  mulF_regNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulF_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg";}
#endif
};

class mulF24_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF24_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulF24_reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF24_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF24_reg_mem";}
#endif
};

class mulF24_reg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF24_reg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulF24_reg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF24_reg_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF24_reg_mem_0";}
#endif
};

class mulF_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulF_reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF_reg_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg_mem";}
#endif
};

class mulF_reg_mem_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_mem_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulF_reg_mem_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF_reg_mem_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg_mem_0";}
#endif
};

class mulF24_mem_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF24_mem_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
public:
  mulF24_mem_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF24_mem_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const TypePtr *adr_type() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF24_mem_mem";}
#endif
};

class mulF24_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF24_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
public:
  mulF24_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulF24_reg_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF24_reg_imm";}
#endif
};

class mulF_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
public:
  mulF_reg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(mulF_reg_immNode); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg_imm";}
#endif
};

class mulF_reg_load1Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_load1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulF_reg_load1Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF_reg_load1Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg_load1";}
#endif
};

class mulF_reg_load1_0Node : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return mulF_reg_load1_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MulF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  mulF_reg_load1_0Node() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(mulF_reg_load1_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "mulF_reg_load1_0";}
#endif
};

class addF_mulF_reg_load1Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_mulF_reg_load1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF_mulF_reg_load1Node() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF_mulF_reg_load1Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_mulF_reg_load1";}
#endif
};

class addF_mulF_reg_load1_1Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_mulF_reg_load1_1_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF_mulF_reg_load1_1Node() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF_mulF_reg_load1_1Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_mulF_reg_load1_1";}
#endif
};

class addF_mulF_reg_load1_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_mulF_reg_load1_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF_mulF_reg_load1_0Node() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF_mulF_reg_load1_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_mulF_reg_load1_0";}
#endif
};

class addF_mulF_reg_load1_2Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_mulF_reg_load1_2_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  addF_mulF_reg_load1_2Node() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(addF_mulF_reg_load1_2Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_mulF_reg_load1_2";}
#endif
};

class addF_mulF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_mulF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addF_mulF_regNode() { _cisc_RegMask = NULL;  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF_mulF_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_mulF_reg";}
#endif
};

class addF_mulF_reg_0Node : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return addF_mulF_reg_0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AddF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  addF_mulF_reg_0Node() { _cisc_RegMask = NULL;  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(addF_mulF_reg_0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "addF_mulF_reg_0";}
#endif
};

class subF_divF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return subF_divF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
public:
  subF_divF_regNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(subF_divF_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "subF_divF_reg";}
#endif
};

class divF24_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divF24_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
public:
  divF24_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divF24_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divF24_reg";}
#endif
};

class divF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return divF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_DivF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  divF_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(divF_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "divF_reg";}
#endif
};

class modF24_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modF24_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModF; }
public:
  modF24_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modF24_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modF24_reg";}
#endif
};

class modF_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modF_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModF; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  modF_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modF_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modF_reg";}
#endif
};

class modX_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return modX_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ModF; }
public:
  modX_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(modX_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "modX_reg";}
#endif
};

class roundFloat_mem_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return roundFloat_mem_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RoundFloat; }
public:
  roundFloat_mem_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(roundFloat_mem_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "roundFloat_mem_reg";}
#endif
};

class roundDouble_mem_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return roundDouble_mem_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_RoundDouble; }
public:
  roundDouble_mem_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(roundDouble_mem_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "roundDouble_mem_reg";}
#endif
};

class convD2F_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2F_reg_rule; }
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
public:
  convD2F_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convD2F_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2F_reg";}
#endif
};

class convD2X_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2X_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
public:
  convD2X_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convD2X_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2X_reg";}
#endif
};

class convXD2X_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convXD2X_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2F; }
public:
  convXD2X_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convXD2X_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convXD2X_reg";}
#endif
};

class convF2D_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2D_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2D; }
public:
  convF2D_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convF2D_reg_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2D_reg_reg";}
#endif
};

class convF2D_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2D_reg_rule; }
  virtual int            ideal_Opcode() const { return Op_ConvF2D; }
public:
  convF2D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convF2D_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2D_reg";}
#endif
};

class convX2D_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convX2D_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2D; }
public:
  convX2D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convX2D_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convX2D_reg";}
#endif
};

class convX2XD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convX2XD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2D; }
public:
  convX2XD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convX2XD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convX2XD_reg";}
#endif
};

class convD2I_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2I_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2I; }
public:
  convD2I_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convD2I_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2I_reg_reg";}
#endif
};

class convXD2I_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convXD2I_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2I; }
public:
  convXD2I_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convXD2I_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convXD2I_reg_reg";}
#endif
};

class convD2L_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convD2L_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2L; }
public:
  convD2L_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convD2L_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convD2L_reg_reg";}
#endif
};

class convXD2L_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convXD2L_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvD2L; }
public:
  convXD2L_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convXD2L_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convXD2L_reg_reg";}
#endif
};

class convF2I_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2I_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2I; }
public:
  convF2I_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convF2I_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2I_reg_reg";}
#endif
};

class convX2I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convX2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2I; }
public:
  convX2I_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convX2I_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convX2I_reg";}
#endif
};

class convF2L_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convF2L_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2L; }
public:
  convF2L_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convF2L_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convF2L_reg_reg";}
#endif
};

class convX2L_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convX2L_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvF2L; }
public:
  convX2L_reg_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convX2L_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convX2L_reg_reg";}
#endif
};

class convI2D_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2D_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2D; }
public:
  convI2D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2D_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2D_reg";}
#endif
};

class convI2XD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2XD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2D; }
public:
  convI2XD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2XD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2XD_reg";}
#endif
};

class convI2XD_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2XD_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2D; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  convI2XD_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2XD_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2XD_mem";}
#endif
};

class convXI2XD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convXI2XD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2D; }
public:
  convXI2XD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convXI2XD_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convXI2XD_reg";}
#endif
};

class convI2D_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2D_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2D; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  convI2D_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2D_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2D_mem";}
#endif
};

class conv24I2F_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return conv24I2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
public:
  conv24I2F_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(conv24I2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "conv24I2F_reg";}
#endif
};

class convI2F_SSFNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2F_SSF_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
public:
  convI2F_SSFNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2F_SSFNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2F_SSF";}
#endif
};

class convI2F_SSF_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2F_SSF_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  convI2F_SSF_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2F_SSF_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2F_SSF_mem";}
#endif
};

class convI2F_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
public:
  convI2F_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2F_reg";}
#endif
};

class convI2F_memNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2F_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  convI2F_memNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(convI2F_memNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2F_mem";}
#endif
};

class convI2X_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2X_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
public:
  convI2X_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2X_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2X_reg";}
#endif
};

class convXI2X_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convXI2X_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2F; }
public:
  convXI2X_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convXI2X_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convXI2X_reg";}
#endif
};

class convI2L_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2L_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvI2L; }
  virtual int            cisc_operand() const { return 1; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  convI2L_regNode() { _cisc_RegMask = NULL;  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2L_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2L_reg";}
#endif
};

class convI2L_reg_zexNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convI2L_reg_zex_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
public:
  convI2L_reg_zexNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convI2L_reg_zexNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convI2L_reg_zex";}
#endif
};

class zerox_longNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return zerox_long_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AndL; }
public:
  zerox_longNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(zerox_longNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "zerox_long";}
#endif
};

class convL2D_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2D_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2D; }
public:
  convL2D_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2D_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2D_reg";}
#endif
};

class convL2XD_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2XD_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2D; }
public:
  convL2XD_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2XD_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2XD_reg";}
#endif
};

class convL2X_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2X_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2F; }
public:
  convL2X_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2X_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2X_reg";}
#endif
};

class convL2F_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2F; }
public:
  convL2F_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2F_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2F_reg";}
#endif
};

class convL2I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return convL2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ConvL2I; }
public:
  convL2I_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(convL2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "convL2I_reg";}
#endif
};

class MoveF2I_stack_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveF2I_stack_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveF2I; }
public:
  MoveF2I_stack_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveF2I_stack_regNode); }
  // Rematerialize MoveF2I_stack_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveF2I_stack_reg";}
#endif
};

class MoveF2I_reg_stackNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveF2I_reg_stack_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveF2I; }
public:
  MoveF2I_reg_stackNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveF2I_reg_stackNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveF2I_reg_stack";}
#endif
};

class MoveF2I_reg_stack_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveF2I_reg_stack_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveF2I; }
public:
  MoveF2I_reg_stack_sseNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveF2I_reg_stack_sseNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveF2I_reg_stack_sse";}
#endif
};

class MoveF2I_reg_reg_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveF2I_reg_reg_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveF2I; }
public:
  MoveF2I_reg_reg_sseNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveF2I_reg_reg_sseNode); }
  // Rematerialize MoveF2I_reg_reg_sse
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveF2I_reg_reg_sse";}
#endif
};

class MoveI2F_reg_stackNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveI2F_reg_stack_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveI2F; }
public:
  MoveI2F_reg_stackNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveI2F_reg_stackNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveI2F_reg_stack";}
#endif
};

class MoveI2F_stack_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveI2F_stack_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveI2F; }
public:
  MoveI2F_stack_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveI2F_stack_regNode); }
  // Rematerialize MoveI2F_stack_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveI2F_stack_reg";}
#endif
};

class MoveI2F_stack_reg_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveI2F_stack_reg_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveI2F; }
public:
  MoveI2F_stack_reg_sseNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveI2F_stack_reg_sseNode); }
  // Rematerialize MoveI2F_stack_reg_sse
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveI2F_stack_reg_sse";}
#endif
};

class MoveI2F_reg_reg_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveI2F_reg_reg_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveI2F; }
public:
  MoveI2F_reg_reg_sseNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveI2F_reg_reg_sseNode); }
  // Rematerialize MoveI2F_reg_reg_sse
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveI2F_reg_reg_sse";}
#endif
};

class MoveD2L_stack_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveD2L_stack_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveD2L; }
public:
  MoveD2L_stack_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveD2L_stack_regNode); }
  // Rematerialize MoveD2L_stack_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveD2L_stack_reg";}
#endif
};

class MoveD2L_reg_stackNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveD2L_reg_stack_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveD2L; }
public:
  MoveD2L_reg_stackNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveD2L_reg_stackNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveD2L_reg_stack";}
#endif
};

class MoveD2L_reg_stack_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveD2L_reg_stack_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveD2L; }
public:
  MoveD2L_reg_stack_sseNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveD2L_reg_stack_sseNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveD2L_reg_stack_sse";}
#endif
};

class MoveD2L_reg_reg_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveD2L_reg_reg_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveD2L; }
public:
  MoveD2L_reg_reg_sseNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveD2L_reg_reg_sseNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveD2L_reg_reg_sse";}
#endif
};

class MoveL2D_reg_stackNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveL2D_reg_stack_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveL2D; }
public:
  MoveL2D_reg_stackNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveL2D_reg_stackNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveL2D_reg_stack";}
#endif
};

class MoveL2D_stack_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveL2D_stack_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveL2D; }
public:
  MoveL2D_stack_regNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveL2D_stack_regNode); }
  // Rematerialize MoveL2D_stack_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveL2D_stack_reg";}
#endif
};

class MoveL2D_stack_reg_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveL2D_stack_reg_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveL2D; }
public:
  MoveL2D_stack_reg_sseNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveL2D_stack_reg_sseNode); }
  // Rematerialize MoveL2D_stack_reg_sse
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveL2D_stack_reg_sse";}
#endif
};

class MoveL2D_stack_reg_sse_partialNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveL2D_stack_reg_sse_partial_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveL2D; }
public:
  MoveL2D_stack_reg_sse_partialNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(MoveL2D_stack_reg_sse_partialNode); }
  // Rematerialize MoveL2D_stack_reg_sse_partial
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveL2D_stack_reg_sse_partial";}
#endif
};

class MoveL2D_reg_reg_sseNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return MoveL2D_reg_reg_sse_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MoveL2D; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges(); }
public:
  MoveL2D_reg_reg_sseNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(MoveL2D_reg_reg_sseNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "MoveL2D_reg_reg_sse";}
#endif
};

class Repl8B_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate8B; }
public:
  Repl8B_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_reg";}
#endif
};

class Repl8B_eRegINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_eRegI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate8B; }
public:
  Repl8B_eRegINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_eRegINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_eRegI";}
#endif
};

class Repl8B_immI0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl8B_immI0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate8B; }
public:
  Repl8B_immI0Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl8B_immI0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl8B_immI0";}
#endif
};

class Repl4S_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate4S; }
public:
  Repl4S_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_reg";}
#endif
};

class Repl4S_eRegINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_eRegI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate4S; }
public:
  Repl4S_eRegINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_eRegINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_eRegI";}
#endif
};

class Repl4S_immI0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4S_immI0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate4S; }
public:
  Repl4S_immI0Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4S_immI0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4S_immI0";}
#endif
};

class Repl4C_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4C_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate4C; }
public:
  Repl4C_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4C_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4C_reg";}
#endif
};

class Repl4C_eRegINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4C_eRegI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate4C; }
public:
  Repl4C_eRegINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4C_eRegINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4C_eRegI";}
#endif
};

class Repl4C_immI0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl4C_immI0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate4C; }
public:
  Repl4C_immI0Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl4C_immI0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl4C_immI0";}
#endif
};

class Repl2I_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate2I; }
public:
  Repl2I_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_reg";}
#endif
};

class Repl2I_eRegINode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_eRegI_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate2I; }
public:
  Repl2I_eRegINode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_eRegINode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_eRegI";}
#endif
};

class Repl2I_immI0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2I_immI0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate2I; }
public:
  Repl2I_immI0Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2I_immI0Node); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2I_immI0";}
#endif
};

class Repl2F_regNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate2F; }
public:
  Repl2F_regNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_regNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_reg";}
#endif
};

class Repl2F_regXNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_regX_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate2F; }
public:
  Repl2F_regXNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_regXNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_regX";}
#endif
};

class Repl2F_immXF0Node : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Repl2F_immXF0_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Replicate2F; }
  virtual int            reloc()   const;
public:
  Repl2F_immXF0Node() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(Repl2F_immXF0Node); }
  virtual int            const_size() const { return 1; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Repl2F_immXF0";}
#endif
};

class rep_stosNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return rep_stos_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ClearArray; }
  virtual uint           oper_input_base() const { return 2; }
public:
  rep_stosNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(rep_stosNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "rep_stos";}
#endif
};

class string_compareNode : public MachNode { 
private:
  MachOper *_opnd_array[7];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return string_compare_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StrComp; }
  virtual uint           oper_input_base() const { return 2; }
public:
  string_compareNode() {  _num_opnds = 7; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(string_compareNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "string_compare";}
#endif
};

class string_equalsNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return string_equals_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StrEquals; }
  virtual uint           oper_input_base() const { return 2; }
public:
  string_equalsNode() {  _num_opnds = 6; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(string_equalsNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "string_equals";}
#endif
};

class string_indexofNode : public MachNode { 
private:
  MachOper *_opnd_array[6];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return string_indexof_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_StrIndexOf; }
  virtual uint           oper_input_base() const { return 2; }
public:
  string_indexofNode() {  _num_opnds = 6; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(string_indexofNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "string_indexof";}
#endif
};

class array_equalsNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return array_equals_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_AryEq; }
  virtual uint           oper_input_base() const { return 2; }
public:
  array_equalsNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(array_equalsNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "array_equals";}
#endif
};

class compI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  compI_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compI_eRegNode); }
  // Rematerialize compI_eReg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compI_eReg";}
#endif
};

class compI_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compI_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  compI_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compI_eReg_immNode); }
  // Rematerialize compI_eReg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compI_eReg_imm";}
#endif
};

class compI_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compI_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compI_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compI_eReg_memNode); }
  // Rematerialize compI_eReg_mem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compI_eReg_mem";}
#endif
};

class testI_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testI_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testI_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testI_regNode); }
  // Rematerialize testI_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testI_reg";}
#endif
};

class testI_reg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testI_reg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
public:
  testI_reg_immNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testI_reg_immNode); }
  // Rematerialize testI_reg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testI_reg_imm";}
#endif
};

class testI_reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testI_reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpI; }
  virtual int            reloc()   const;
public:
  testI_reg_memNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(testI_reg_memNode); }
  // Rematerialize testI_reg_mem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testI_reg_mem";}
#endif
};

class compU_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compU_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpU; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  compU_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compU_eRegNode); }
  // Rematerialize compU_eReg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compU_eReg";}
#endif
};

class compU_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compU_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpU; }
public:
  compU_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compU_eReg_immNode); }
  // Rematerialize compU_eReg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compU_eReg_imm";}
#endif
};

class compU_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compU_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpU; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compU_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compU_eReg_memNode); }
  // Rematerialize compU_eReg_mem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compU_eReg_mem";}
#endif
};

class testU_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testU_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpU; }
public:
  testU_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testU_regNode); }
  // Rematerialize testU_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testU_reg";}
#endif
};

class compP_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compP_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            cisc_operand() const { return 2; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  compP_eRegNode() { _cisc_RegMask = NULL;  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compP_eRegNode); }
  // Rematerialize compP_eReg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compP_eReg";}
#endif
};

class compP_eReg_immNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compP_eReg_imm_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc()   const;
public:
  compP_eReg_immNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(compP_eReg_immNode); }
  // Rematerialize compP_eReg_imm
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compP_eReg_imm";}
#endif
};

class compP_eReg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compP_eReg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compP_eReg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compP_eReg_memNode); }
  // Rematerialize compP_eReg_mem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compP_eReg_mem";}
#endif
};

class compP_mem_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return compP_mem_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  compP_mem_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(compP_mem_eRegNode); }
  // Rematerialize compP_mem_eReg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "compP_mem_eReg";}
#endif
};

class testP_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testP_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc()   const;
public:
  testP_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(testP_regNode); }
  // Rematerialize testP_reg
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testP_reg";}
#endif
};

class testP_Reg_memNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return testP_Reg_mem_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  testP_Reg_memNode() {  _num_opnds = 3; _opnds = _opnd_array; init_flags(Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(testP_Reg_memNode); }
  // Rematerialize testP_Reg_mem
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "testP_Reg_mem";}
#endif
};

class minI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return minI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MinI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  minI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(minI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "minI_eReg";}
#endif
};

class maxI_eRegNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return maxI_eReg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_MaxI; }
  virtual uint           two_adr() const  { return oper_input_base(); }
public:
  maxI_eRegNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(maxI_eRegNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "maxI_eReg";}
#endif
};

class jumpXtndNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
  GrowableArray<Label*> _index2label;
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual void           add_case_label(int index_num, Label* blockLabel) {
                                          _index2label.at_put_grow(index_num, blockLabel);}
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jumpXtnd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Jump; }
public:
  jumpXtndNode() : _index2label(MinJumpTableSize*2) {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jumpXtndNode); }
  virtual bool           pinned() const { return true; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jumpXtnd";}
#endif
};

class jmpDirNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpDir_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Goto; }
public:
  jmpDirNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Goto | Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpDirNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpDir";}
#endif
};

class jmpConNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpCon_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpConNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpCon";}
#endif
};

class jmpLoopEndNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpLoopEnd_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpLoopEndNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpLoopEndNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpLoopEnd";}
#endif
};

class jmpLoopEndUNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpLoopEndU_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpLoopEndUNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpLoopEndUNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpLoopEndU";}
#endif
};

class jmpLoopEndUCFNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpLoopEndUCF_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpLoopEndUCFNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpLoopEndUCFNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpLoopEndUCF";}
#endif
};

class jmpConUNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpConU_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConUNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpConUNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpConU";}
#endif
};

class jmpConUCFNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpConUCF_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConUCFNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpConUCFNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpConUCF";}
#endif
};

class jmpConUCF2Node : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpConUCF2_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConUCF2Node() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative | Flag_may_be_short_branch); }
  virtual uint           size_of() const { return sizeof(jmpConUCF2Node); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  virtual MachNode      *short_branch_version(Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpConUCF2";}
#endif
};

class partialSubtypeCheckNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return partialSubtypeCheck_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_PartialSubtypeCheck; }
public:
  partialSubtypeCheckNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(partialSubtypeCheckNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "partialSubtypeCheck";}
#endif
};

class partialSubtypeCheck_vs_ZeroNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return partialSubtypeCheck_vs_Zero_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpP; }
  virtual int            reloc()   const;
public:
  partialSubtypeCheck_vs_ZeroNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(partialSubtypeCheck_vs_ZeroNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize partialSubtypeCheck_vs_Zero
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "partialSubtypeCheck_vs_Zero";}
#endif
};

class jmpDir_shortNode : public MachNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpDir_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Goto; }
public:
  jmpDir_shortNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_Goto | Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpDir_shortNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpDir_short";}
#endif
};

class jmpCon_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpCon_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpCon_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpCon_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpCon_short";}
#endif
};

class jmpLoopEnd_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpLoopEnd_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpLoopEnd_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpLoopEnd_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpLoopEnd_short";}
#endif
};

class jmpLoopEndU_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpLoopEndU_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpLoopEndU_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpLoopEndU_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpLoopEndU_short";}
#endif
};

class jmpLoopEndUCF_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpLoopEndUCF_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CountedLoopEnd; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpLoopEndUCF_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpLoopEndUCF_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpLoopEndUCF_short";}
#endif
};

class jmpConU_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpConU_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConU_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpConU_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpConU_short";}
#endif
};

class jmpConUCF_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpConUCF_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConUCF_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpConUCF_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpConUCF_short";}
#endif
};

class jmpConUCF2_shortNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return jmpConUCF2_short_rule; }
  virtual void           label_set( Label& label, uint block_num );
  int             ins_short_branch() const { return 1; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  jmpConUCF2_shortNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch | Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(jmpConUCF2_shortNode); }
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "jmpConUCF2_short";}
#endif
};

class cmpL3_reg_regNode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL3_reg_reg_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL3; }
public:
  cmpL3_reg_regNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL3_reg_regNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL3_reg_reg";}
#endif
};

class cmpL_zero_flags_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_zero_flags_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  cmpL_zero_flags_LTGENode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL_zero_flags_LTGENode); }
  // Rematerialize cmpL_zero_flags_LTGE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_zero_flags_LTGE";}
#endif
};

class cmpL_reg_flags_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_reg_flags_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  cmpL_reg_flags_LTGENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL_reg_flags_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpL_reg_flags_LTGE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_reg_flags_LTGE";}
#endif
};

class cmpL_LTGENode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_LTGE_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  cmpL_LTGENode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch); }
  virtual uint           size_of() const { return sizeof(cmpL_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_LTGE";}
#endif
};

class cmovLL_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovLL_reg_LTGENode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_reg_LTGE";}
#endif
};

class cmovLL_mem_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_mem_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovLL_mem_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovLL_mem_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_mem_LTGE";}
#endif
};

class cmovII_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovII_reg_LTGENode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_reg_LTGE";}
#endif
};

class cmovII_mem_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_mem_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovII_mem_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovII_mem_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_mem_LTGE";}
#endif
};

class cmovPP_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPP_reg_LTGE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPP_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPP_reg_LTGENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPP_reg_LTGE";}
#endif
};

class cmovDD_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDD_reg_LTGE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDD_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDD_reg_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDD_reg_LTGE";}
#endif
};

class cmovXDD_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovXDD_reg_LTGE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovXDD_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovXDD_reg_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovXDD_reg_LTGE";}
#endif
};

class cmovFF_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFF_reg_LTGE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFF_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFF_reg_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFF_reg_LTGE";}
#endif
};

class cmovXX_reg_LTGENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovXX_reg_LTGE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovXX_reg_LTGENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovXX_reg_LTGENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovXX_reg_LTGE";}
#endif
};

class cmpL_zero_flags_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_zero_flags_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  cmpL_zero_flags_EQNENode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL_zero_flags_EQNENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpL_zero_flags_EQNE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_zero_flags_EQNE";}
#endif
};

class cmpL_reg_flags_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_reg_flags_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  cmpL_reg_flags_EQNENode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL_reg_flags_EQNENode); }
  // Rematerialize cmpL_reg_flags_EQNE
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_reg_flags_EQNE";}
#endif
};

class cmpL_EQNENode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_EQNE_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  cmpL_EQNENode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch); }
  virtual uint           size_of() const { return sizeof(cmpL_EQNENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_EQNE";}
#endif
};

class cmovLL_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovLL_reg_EQNENode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_reg_EQNE";}
#endif
};

class cmovLL_mem_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_mem_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovLL_mem_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovLL_mem_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_mem_EQNE";}
#endif
};

class cmovII_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovII_reg_EQNENode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_reg_EQNE";}
#endif
};

class cmovII_mem_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_mem_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovII_mem_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovII_mem_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_mem_EQNE";}
#endif
};

class cmovPP_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPP_reg_EQNE_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPP_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPP_reg_EQNENode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPP_reg_EQNE";}
#endif
};

class cmovDD_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDD_reg_EQNE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDD_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDD_reg_EQNENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDD_reg_EQNE";}
#endif
};

class cmovXDD_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovXDD_reg_EQNE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovXDD_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovXDD_reg_EQNENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovXDD_reg_EQNE";}
#endif
};

class cmovFF_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFF_reg_EQNE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFF_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFF_reg_EQNENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFF_reg_EQNE";}
#endif
};

class cmovXX_reg_EQNENode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovXX_reg_EQNE_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovXX_reg_EQNENode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovXX_reg_EQNENode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovXX_reg_EQNE";}
#endif
};

class cmpL_zero_flags_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_zero_flags_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  cmpL_zero_flags_LEGTNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL_zero_flags_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpL_zero_flags_LEGT
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_zero_flags_LEGT";}
#endif
};

class cmpL_reg_flags_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_reg_flags_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CmpL; }
public:
  cmpL_reg_flags_LEGTNode() {  _num_opnds = 4; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmpL_reg_flags_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpL_reg_flags_LEGT
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_reg_flags_LEGT";}
#endif
};

class cmpL_LEGTNode : public MachIfNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpL_LEGT_rule; }
  virtual void           label_set( Label& label, uint block_num );
  virtual int            ideal_Opcode() const { return Op_If; }
  virtual void           negate() { 
    opnd_array(1)->negate();
    _prob = 1.0f - _prob;
  };
  virtual uint           oper_input_base() const { return 1; }
public:
  cmpL_LEGTNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_Branch); }
  virtual uint           size_of() const { return sizeof(cmpL_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  virtual bool           pinned() const { return true; }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  const Type            *bottom_type() const { return TypeTuple::IFBOTH; } // matched IfNode
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpL_LEGT";}
#endif
};

class cmovLL_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovLL_reg_LEGTNode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovLL_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_reg_LEGT";}
#endif
};

class cmovLL_mem_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovLL_mem_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveL; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovLL_mem_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovLL_mem_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovLL_mem_LEGT";}
#endif
};

class cmovII_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  const RegMask  *_cisc_RegMask;
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            cisc_operand() const { return 4; }
  virtual MachNode      *cisc_version(int offset, Compile* C);
  virtual void           use_cisc_RegMask();
  virtual const RegMask *cisc_RegMask() const { return _cisc_RegMask; }
public:
  cmovII_reg_LEGTNode() { _cisc_RegMask = NULL;  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovII_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_reg_LEGT";}
#endif
};

class cmovII_mem_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovII_mem_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveI; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 2; }
public:
  cmovII_mem_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_cisc_alternate | Flag_needs_anti_dependence_check); }
  virtual uint           size_of() const { return sizeof(cmovII_mem_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  virtual const MachOper *memory_operand() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovII_mem_LEGT";}
#endif
};

class cmovPP_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovPP_reg_LEGT_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CMoveP; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovPP_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovPP_reg_LEGTNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { const Type *t = in(oper_input_base()+1)->bottom_type(); return (req() <= oper_input_base()+2) ? t : t->meet(in(oper_input_base()+2)->bottom_type()); } // CMoveP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovPP_reg_LEGT";}
#endif
};

class cmovDD_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovDD_reg_LEGT_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovDD_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovDD_reg_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovDD_reg_LEGT";}
#endif
};

class cmovXDD_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovXDD_reg_LEGT_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveD; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovXDD_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovXDD_reg_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovXDD_reg_LEGT";}
#endif
};

class cmovFF_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovFF_reg_LEGT_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovFF_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovFF_reg_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovFF_reg_LEGT";}
#endif
};

class cmovXX_reg_LEGTNode : public MachNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmovXX_reg_LEGT_rule; }
  virtual int            ideal_Opcode() const { return Op_CMoveF; }
  virtual uint           two_adr() const  { return oper_input_base() + opnd_array(1)->num_edges() + opnd_array(2)->num_edges(); }
public:
  cmovXX_reg_LEGTNode() {  _num_opnds = 5; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(cmovXX_reg_LEGTNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmovXX_reg_LEGT";}
#endif
};

class CallStaticJavaDirectNode : public MachCallStaticJavaNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallStaticJavaDirect_rule; }
  virtual void           method_set( intptr_t method );
  int             ins_alignment() const { return 4; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallStaticJava; }
  virtual int            reloc()   const;
  virtual int            alignment_required()   const { return 4; }
  virtual int            compute_padding(int current_offset)   const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallStaticJavaDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(CallStaticJavaDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallStaticJavaDirect";}
#endif
};

class CallStaticJavaHandleNode : public MachCallStaticJavaNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallStaticJavaHandle_rule; }
  virtual void           method_set( intptr_t method );
  int             ins_alignment() const { return 4; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallStaticJava; }
  virtual int            reloc()   const;
  virtual int            alignment_required()   const { return 4; }
  virtual int            compute_padding(int current_offset)   const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallStaticJavaHandleNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(CallStaticJavaHandleNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallStaticJavaHandle";}
#endif
};

class CallDynamicJavaDirectNode : public MachCallDynamicJavaNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallDynamicJavaDirect_rule; }
  virtual void           method_set( intptr_t method );
  int             ins_alignment() const { return 4; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallDynamicJava; }
  virtual int            reloc()   const;
  virtual int            alignment_required()   const { return 4; }
  virtual int            compute_padding(int current_offset)   const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallDynamicJavaDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(CallDynamicJavaDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallDynamicJavaDirect";}
#endif
};

class CallRuntimeDirectNode : public MachCallRuntimeNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallRuntimeDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallRuntime; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallRuntimeDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(CallRuntimeDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallRuntimeDirect";}
#endif
};

class CallLeafDirectNode : public MachCallLeafNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallLeafDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallLeaf; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallLeafDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); clear_flag(Flag_is_safepoint_node); }
  virtual uint           size_of() const { return sizeof(CallLeafDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallLeafDirect";}
#endif
};

class CallLeafNoFPDirectNode : public MachCallLeafNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CallLeafNoFPDirect_rule; }
  virtual void           method_set( intptr_t method );
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CallLeafNoFP; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 1; }
public:
  CallLeafNoFPDirectNode() {  _num_opnds = 2; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); clear_flag(Flag_is_safepoint_node); }
  virtual uint           size_of() const { return sizeof(CallLeafNoFPDirectNode); }
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CallLeafNoFPDirect";}
#endif
};

class RetNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return Ret_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Return; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 5; }
public:
  RetNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(RetNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "Ret";}
#endif
};

class TailCalljmpIndNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return TailCalljmpInd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_TailCall; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 5; }
public:
  TailCalljmpIndNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(TailCalljmpIndNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "TailCalljmpInd";}
#endif
};

class tailjmpIndNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[3];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return tailjmpInd_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_TailJump; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 5; }
public:
  tailjmpIndNode() {  _num_opnds = 3; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(tailjmpIndNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "tailjmpInd";}
#endif
};

class CreateExceptionNode : public MachTypeNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return CreateException_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_CreateEx; }
  virtual uint           oper_input_base() const { return 1; }
public:
  CreateExceptionNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(CreateExceptionNode); }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "CreateException";}
#endif
};

class RethrowExceptionNode : public MachReturnNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return RethrowException_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Rethrow; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 5; }
public:
  RethrowExceptionNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(RethrowExceptionNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "RethrowException";}
#endif
};

class cmpFastLockNode : public MachFastLockNode { 
private:
  MachOper *_opnd_array[5];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpFastLock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_FastLock; }
  virtual uint           oper_input_base() const { return 1; }
public:
  cmpFastLockNode() {  _num_opnds = 5; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(cmpFastLockNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpFastLock
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpFastLock";}
#endif
};

class cmpFastUnlockNode : public MachNode { 
private:
  MachOper *_opnd_array[4];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return cmpFastUnlock_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_FastUnlock; }
public:
  cmpFastUnlockNode() {  _num_opnds = 4; _opnds = _opnd_array; init_flags(Flag_is_pc_relative); }
  virtual uint           size_of() const { return sizeof(cmpFastUnlockNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize cmpFastUnlock
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "cmpFastUnlock";}
#endif
};

class safePoint_pollNode : public MachSafePointNode { 
private:
  MachOper *_opnd_array[2];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return safePoint_poll_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual uint           size(PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_SafePoint; }
  virtual int            reloc()   const;
  virtual uint           oper_input_base() const { return 5; }
public:
  safePoint_pollNode() {  _num_opnds = 2; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(safePoint_pollNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  // Rematerialize safePoint_poll
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "safePoint_poll";}
#endif
};

class tlsLoadPNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return tlsLoadP_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_ThreadLocal; }
public:
  tlsLoadPNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(tlsLoadPNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
  friend MachNode *State::MachNodeGenerator(int opcode, Compile* C);
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
  const Type            *bottom_type() const { return TypeRawPtr::BOTTOM; } // tlsLoadP
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "tlsLoadP";}
#endif
};

class TLSNode : public MachNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return TLS_rule; }
  virtual int            ideal_Opcode() const { return Op_ThreadLocal; }
public:
  TLSNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(TLSNode); }
  virtual MachNode      *Expand(State *state, Node_List &proj_list, Node* mem);
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "TLS";}
#endif
};

class ShouldNotReachHereNode : public MachHaltNode { 
private:
  MachOper *_opnd_array[1];
public:
  MachOper *opnd_array(uint operand_index) const { assert(operand_index < _num_opnds, "invalid _opnd_array index"); return _opnd_array[operand_index]; }
  void      set_opnd_array(uint operand_index, MachOper *operand) { assert(operand_index < _num_opnds, "invalid _opnd_array index"); _opnd_array[operand_index] = operand; }
private:
  virtual const RegMask &out_RegMask() const;
  virtual uint           rule() const { return ShouldNotReachHere_rule; }
  virtual void           emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const;
  virtual int            ideal_Opcode() const { return Op_Halt; }
  virtual uint           oper_input_base() const { return 5; }
public:
  ShouldNotReachHereNode() {  _num_opnds = 1; _opnds = _opnd_array; }
  virtual uint           size_of() const { return sizeof(ShouldNotReachHereNode); }
  virtual bool           pinned() const { return true; }
  virtual const Node *is_block_proj() const { return this; }
  static  const Pipeline *pipeline_class();
  virtual const Pipeline *pipeline() const;
#ifndef PRODUCT
  virtual void           format(PhaseRegAlloc *ra, outputStream *st) const;
  virtual const char    *Name() const { return "ShouldNotReachHere";}
#endif
};

//HeaderForm

#line 238 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

// Must be visible to the DFA in dfa_x86_32.cpp
extern bool is_operand_hi32_zero(Node* n);

#line 20085 "../generated/adfiles/ad_x86_32.hpp"


extern const char  register_save_policy[];
extern const char  c_reg_save_policy[];
extern const int   register_save_type[];

extern const int   reduceOp[];
extern const int   leftOp[];
extern const int   rightOp[];
extern const char *ruleName[];
extern const bool  swallowed[];
// Mapping from machine-independent opcode to boolean
// Flag cases where machine needs cloned values or instructions
extern const char must_clone[];


// Enumeration of register class names
enum machRegisterClass {
  ANY_REG,
  E_REG,
  E_REG_NO_RBP,
  X_REG,
  P_REG,
  NCX_REG,
  NAX_REG,
  NABX_REG,
  EAX_REG,
  EBX_REG,
  ECX_REG,
  EDX_REG,
  EDI_REG,
  ESI_REG,
  EBP_REG,
  SP_REG,
  INT_FLAGS,
  LONG_REG,
  EADX_REG,
  EBCX_REG,
  NADX_REG,
  FLT_REG,
  XMM_REG,
  XDB_REG,
  DBL_REG,
  FLT_REG0,
  DBL_REG0,
  DBL_REG1,
  DBL_NOTREG0,
  XDB_REG6,
  XDB_REG7,
  STACK_SLOTS,
  INLINE_CACHE_REG,
  INTERPRETER_METHOD_OOP_REG,
  INTERPRETER_FRAME_POINTER_REG,
  _last_Mach_Reg_Class
};

// Register masks, one for each register class.
extern const RegMask ANY_REG_mask;
extern const RegMask E_REG_mask;
extern const RegMask STACK_OR_E_REG_mask;
extern const RegMask E_REG_NO_RBP_mask;
extern const RegMask X_REG_mask;
extern const RegMask STACK_OR_X_REG_mask;
extern const RegMask P_REG_mask;
extern const RegMask NCX_REG_mask;
extern const RegMask NAX_REG_mask;
extern const RegMask NABX_REG_mask;
extern const RegMask EAX_REG_mask;
extern const RegMask EBX_REG_mask;
extern const RegMask ECX_REG_mask;
extern const RegMask EDX_REG_mask;
extern const RegMask EDI_REG_mask;
extern const RegMask ESI_REG_mask;
extern const RegMask EBP_REG_mask;
extern const RegMask SP_REG_mask;
extern const RegMask INT_FLAGS_mask;
extern const RegMask LONG_REG_mask;
extern const RegMask STACK_OR_LONG_REG_mask;
extern const RegMask EADX_REG_mask;
extern const RegMask EBCX_REG_mask;
extern const RegMask NADX_REG_mask;
extern const RegMask FLT_REG_mask;
extern const RegMask STACK_OR_FLT_REG_mask;
extern const RegMask XMM_REG_mask;
extern const RegMask STACK_OR_XMM_REG_mask;
extern const RegMask XDB_REG_mask;
extern const RegMask STACK_OR_XDB_REG_mask;
extern const RegMask DBL_REG_mask;
extern const RegMask STACK_OR_DBL_REG_mask;
extern const RegMask FLT_REG0_mask;
extern const RegMask DBL_REG0_mask;
extern const RegMask DBL_REG1_mask;
extern const RegMask DBL_NOTREG0_mask;
extern const RegMask XDB_REG6_mask;
extern const RegMask XDB_REG7_mask;
extern const RegMask STACK_SLOTS_mask;
extern const RegMask STACK_OR_STACK_SLOTS_mask;
extern const RegMask INLINE_CACHE_REG_mask;
extern const RegMask INTERPRETER_METHOD_OOP_REG_mask;
extern const RegMask INTERPRETER_FRAME_POINTER_REG_mask;
