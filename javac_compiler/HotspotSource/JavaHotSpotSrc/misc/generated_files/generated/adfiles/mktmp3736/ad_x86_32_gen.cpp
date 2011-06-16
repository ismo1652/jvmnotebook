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


#include "incls/_precompiled.incl"
#include "incls/_ad_x86_32_gen.cpp.incl"



//------------------------- MachOper Generator ---------------
// A switch statement on the dense-packed user-defined type system
// that invokes 'new' on the corresponding class constructor.

MachOper *State::MachOperGenerator(int opcode, Compile* C){

  switch(opcode) {
  case UNIVERSE:
    return new (C) UniverseOper( );
  case LABEL:
    return new (C) labelOper( );
  case SREGI:
    return new (C) sRegIOper( );
  case SREGP:
    return new (C) sRegPOper( );
  case SREGF:
    return new (C) sRegFOper( );
  case SREGD:
    return new (C) sRegDOper( );
  case SREGL:
    return new (C) sRegLOper( );
  case METHOD:
    return new (C) methodOper( );
  case IMMI:
    return new (C) immIOper(_leaf->get_int() );
  case IMMI0:
    return new (C) immI0Oper(_leaf->get_int() );
  case IMMI1:
    return new (C) immI1Oper(_leaf->get_int() );
  case IMMI_M1:
    return new (C) immI_M1Oper(_leaf->get_int() );
  case IMMI2:
    return new (C) immI2Oper(_leaf->get_int() );
  case IMMI8:
    return new (C) immI8Oper(_leaf->get_int() );
  case IMMI16:
    return new (C) immI16Oper(_leaf->get_int() );
  case IMMI_32:
    return new (C) immI_32Oper(_leaf->get_int() );
  case IMMI_1_31:
    return new (C) immI_1_31Oper(_leaf->get_int() );
  case IMMI_32_63:
    return new (C) immI_32_63Oper(_leaf->get_int() );
  case IMMI_1:
    return new (C) immI_1Oper(_leaf->get_int() );
  case IMMI_2:
    return new (C) immI_2Oper(_leaf->get_int() );
  case IMMI_3:
    return new (C) immI_3Oper(_leaf->get_int() );
  case IMMP:
    return new (C) immPOper(_leaf->bottom_type()->is_ptr() );
  case IMMP0:
    return new (C) immP0Oper(_leaf->bottom_type()->is_ptr() );
  case IMML:
    return new (C) immLOper(_leaf->get_long() );
  case IMML0:
    return new (C) immL0Oper(_leaf->get_long() );
  case IMML_M1:
    return new (C) immL_M1Oper(_leaf->get_long() );
  case IMML_127:
    return new (C) immL_127Oper(_leaf->get_long() );
  case IMML_32BITS:
    return new (C) immL_32bitsOper(_leaf->get_long() );
  case IMML32:
    return new (C) immL32Oper(_leaf->get_long() );
  case IMMD0:
    return new (C) immD0Oper(_leaf->getd() );
  case IMMD1:
    return new (C) immD1Oper(_leaf->getd() );
  case IMMD:
    return new (C) immDOper(_leaf->getd() );
  case IMMXD:
    return new (C) immXDOper(_leaf->getd() );
  case IMMXD0:
    return new (C) immXD0Oper(_leaf->getd() );
  case IMMF0:
    return new (C) immF0Oper(_leaf->getf() );
  case IMMF:
    return new (C) immFOper(_leaf->getf() );
  case IMMXF:
    return new (C) immXFOper(_leaf->getf() );
  case IMMXF0:
    return new (C) immXF0Oper(_leaf->getf() );
  case IMMI_16:
    return new (C) immI_16Oper(_leaf->get_int() );
  case IMMI_24:
    return new (C) immI_24Oper(_leaf->get_int() );
  case IMMI_255:
    return new (C) immI_255Oper(_leaf->get_int() );
  case IMMI_65535:
    return new (C) immI_65535Oper(_leaf->get_int() );
  case EREGI:
    return new (C) eRegIOper( );
  case XREGI:
    return new (C) xRegIOper( );
  case EAXREGI:
    return new (C) eAXRegIOper( );
  case EBXREGI:
    return new (C) eBXRegIOper( );
  case ECXREGI:
    return new (C) eCXRegIOper( );
  case EDXREGI:
    return new (C) eDXRegIOper( );
  case EDIREGI:
    return new (C) eDIRegIOper( );
  case NAXREGI:
    return new (C) naxRegIOper( );
  case NADXREGI:
    return new (C) nadxRegIOper( );
  case NCXREGI:
    return new (C) ncxRegIOper( );
  case ESIREGI:
    return new (C) eSIRegIOper( );
  case ANYREGP:
    return new (C) anyRegPOper( );
  case EREGP:
    return new (C) eRegPOper( );
  case EREGP_NO_EBP:
    return new (C) eRegP_no_EBPOper( );
  case NAXREGP:
    return new (C) naxRegPOper( );
  case NABXREGP:
    return new (C) nabxRegPOper( );
  case PREGP:
    return new (C) pRegPOper( );
  case EAXREGP:
    return new (C) eAXRegPOper( );
  case EBXREGP:
    return new (C) eBXRegPOper( );
  case ECXREGP:
    return new (C) eCXRegPOper( );
  case ESIREGP:
    return new (C) eSIRegPOper( );
  case EDIREGP:
    return new (C) eDIRegPOper( );
  case EBPREGP:
    return new (C) eBPRegPOper( );
  case EREGL:
    return new (C) eRegLOper( );
  case EADXREGL:
    return new (C) eADXRegLOper( );
  case EBCXREGL:
    return new (C) eBCXRegLOper( );
  case EADXREGL_LOW_ONLY:
    return new (C) eADXRegL_low_onlyOper( );
  case EFLAGSREG:
    return new (C) eFlagsRegOper( );
  case EFLAGSREGU:
    return new (C) eFlagsRegUOper( );
  case EFLAGSREGUCF:
    return new (C) eFlagsRegUCFOper( );
  case FLAGSREG_LONG_LTGE:
    return new (C) flagsReg_long_LTGEOper( );
  case FLAGSREG_LONG_EQNE:
    return new (C) flagsReg_long_EQNEOper( );
  case FLAGSREG_LONG_LEGT:
    return new (C) flagsReg_long_LEGTOper( );
  case REGD:
    return new (C) regDOper( );
  case REGDPR1:
    return new (C) regDPR1Oper( );
  case REGDPR2:
    return new (C) regDPR2Oper( );
  case REGNOTDPR1:
    return new (C) regnotDPR1Oper( );
  case REGXD:
    return new (C) regXDOper( );
  case REGXD6:
    return new (C) regXD6Oper( );
  case REGXD7:
    return new (C) regXD7Oper( );
  case REGF:
    return new (C) regFOper( );
  case REGFPR1:
    return new (C) regFPR1Oper( );
  case REGX:
    return new (C) regXOper( );
  case DIRECT:
    return new (C) directOper(_leaf->bottom_type()->is_ptr() );
  case INDIRECT:
    return new (C) indirectOper( );
  case INDOFFSET8:
    return new (C) indOffset8Oper(_kids[1]->_leaf->get_int() );
  case INDOFFSET32:
    return new (C) indOffset32Oper(_kids[1]->_leaf->get_int() );
  case INDOFFSET32X:
    return new (C) indOffset32XOper(_kids[0]->_leaf->bottom_type()->is_ptr() );
  case INDINDEXOFFSET:
    return new (C) indIndexOffsetOper(_kids[1]->_leaf->get_int() );
  case INDINDEX:
    return new (C) indIndexOper( );
  case INDINDEXSCALE:
    return new (C) indIndexScaleOper(_kids[1]->_kids[1]->_leaf->get_int() );
  case INDINDEXSCALEOFFSET:
    return new (C) indIndexScaleOffsetOper(_kids[0]->_kids[1]->_kids[1]->_leaf->get_int(), _kids[1]->_leaf->get_int() );
  case LOAD_LONG_REGP:
    return new (C) load_long_RegPOper( );
  case LOAD_LONG_INDIRECT:
    return new (C) load_long_indirectOper( );
  case LOAD_LONG_INDOFFSET32:
    return new (C) load_long_indOffset32Oper(_kids[1]->_leaf->get_int() );
  case STACKSLOTP:
    return new (C) stackSlotPOper( );
  case STACKSLOTI:
    return new (C) stackSlotIOper( );
  case STACKSLOTF:
    return new (C) stackSlotFOper( );
  case STACKSLOTD:
    return new (C) stackSlotDOper( );
  case STACKSLOTL:
    return new (C) stackSlotLOper( );
  case INDIRECT_WIN95_SAFE:
    return new (C) indirect_win95_safeOper( );
  case INDOFFSET8_WIN95_SAFE:
    return new (C) indOffset8_win95_safeOper(_kids[1]->_leaf->get_int() );
  case INDOFFSET32_WIN95_SAFE:
    return new (C) indOffset32_win95_safeOper(_kids[1]->_leaf->get_int() );
  case INDINDEXOFFSET_WIN95_SAFE:
    return new (C) indIndexOffset_win95_safeOper(_kids[1]->_leaf->get_int() );
  case INDINDEXSCALE_WIN95_SAFE:
    return new (C) indIndexScale_win95_safeOper(_kids[1]->_kids[1]->_leaf->get_int() );
  case INDINDEXSCALEOFFSET_WIN95_SAFE:
    return new (C) indIndexScaleOffset_win95_safeOper(_kids[0]->_kids[1]->_kids[1]->_leaf->get_int(), _kids[1]->_leaf->get_int() );
  case CMPOP:
    return new (C) cmpOpOper(_leaf->as_Bool()->_test._test );
  case CMPOPU:
    return new (C) cmpOpUOper(_leaf->as_Bool()->_test._test );
  case CMPOPUCF:
    return new (C) cmpOpUCFOper(_leaf->as_Bool()->_test._test );
  case CMPOPUCF2:
    return new (C) cmpOpUCF2Oper(_leaf->as_Bool()->_test._test );
  case CMPOP_FCMOV:
    return new (C) cmpOp_fcmovOper(_leaf->as_Bool()->_test._test );
  case CMPOP_COMMUTE:
    return new (C) cmpOp_commuteOper(_leaf->as_Bool()->_test._test );
  case _ADDP_EREGP_EREGI:    return NULL;
  case _LSHIFTI_EREGI_IMMI2:    return NULL;
  case _ADDP_EREGP__LSHIFTI_EREGI_IMMI2:    return NULL;
  case _ADDP_EREGP_NO_EBP_EREGI:    return NULL;
  case _ADDP_EREGP_NO_EBP__LSHIFTI_EREGI_IMMI2:    return NULL;
  case _LOADI_MEMORY_:    return NULL;
  case _LOADL_MEMORY_:    return NULL;
  case _LOADB_MEMORY_:    return NULL;
  case _LOADUB_MEMORY_:    return NULL;
  case _ANDI__LOADUB_MEMORY__IMMI8:    return NULL;
  case _LOADS_MEMORY_:    return NULL;
  case _LSHIFTI__LOADS_MEMORY__IMMI_24:    return NULL;
  case _LOADUS_MEMORY_:    return NULL;
  case _LSHIFTI__LOADUS_MEMORY__IMMI_24:    return NULL;
  case _ANDI__LOADUS_MEMORY__IMMI_255:    return NULL;
  case _ANDI__LOADUS_MEMORY__IMMI16:    return NULL;
  case _LSHIFTI__LOADI_MEMORY__IMMI_24:    return NULL;
  case _LSHIFTI__LOADI_MEMORY__IMMI_16:    return NULL;
  case _ANDI__LOADI_MEMORY__IMMI_255:    return NULL;
  case _ANDI__LOADI_MEMORY__IMMI_65535:    return NULL;
  case _ANDI__LOADI_MEMORY__IMMI:    return NULL;
  case _CONVL2I_EREGL_:    return NULL;
  case _ROUNDDOUBLE_REGDPR1_:    return NULL;
  case _ROUNDFLOAT_REGFPR1_:    return NULL;
  case _CONVD2F_REGDPR1_:    return NULL;
  case _BINARY_CMPOP_EFLAGSREG:    return NULL;
  case _BINARY_EREGI_EREGI:    return NULL;
  case _BINARY_CMPOPU_EFLAGSREGU:    return NULL;
  case _BINARY_CMPOPUCF_EFLAGSREGUCF:    return NULL;
  case _BINARY_EREGI__LOADI_MEMORY_:    return NULL;
  case _BINARY_EREGP_EREGP:    return NULL;
  case _BINARY_CMPOP_FCMOV_EFLAGSREGU:    return NULL;
  case _BINARY_REGDPR1_REGD:    return NULL;
  case _BINARY_REGFPR1_REGF:    return NULL;
  case _BINARY_REGD_REGD:    return NULL;
  case _BINARY_REGF_REGF:    return NULL;
  case _BINARY_REGX_REGX:    return NULL;
  case _BINARY_REGXD_REGXD:    return NULL;
  case _BINARY_EREGL_EREGL:    return NULL;
  case _ADDI__LOADI_MEMORY__EREGI:    return NULL;
  case _ADDI_EREGI__LOADI_MEMORY_:    return NULL;
  case _ADDI__LOADI_MEMORY__IMMI:    return NULL;
  case _ADDI__LOADI_MEMORY__IMMI1:    return NULL;
  case _ADDI__LOADI_MEMORY__IMMI_M1:    return NULL;
  case _BINARY_EAXREGP_EREGP:    return NULL;
  case _BINARY_EAXREGI_EREGI:    return NULL;
  case _BINARY_EADXREGL_EBCXREGL:    return NULL;
  case _BINARY_EAXREGP_ECXREGP:    return NULL;
  case _BINARY_EAXREGI_ECXREGI:    return NULL;
  case _SUBI__LOADI_MEMORY__EREGI:    return NULL;
  case _SUBI_IMMI0_EREGI:    return NULL;
  case _CONVI2L_NADXREGI_:    return NULL;
  case _MULL__CONVI2L_NADXREGI__EADXREGL_LOW_ONLY:    return NULL;
  case _RSHIFTL__MULL__CONVI2L_NADXREGI__EADXREGL_LOW_ONLY_IMMI_32:    return NULL;
  case _MULL_EADXREGL_LOW_ONLY__CONVI2L_NADXREGI_:    return NULL;
  case _RSHIFTL__MULL_EADXREGL_LOW_ONLY__CONVI2L_NADXREGI__IMMI_32:    return NULL;
  case _RSHIFTL__MULL__CONVI2L_NADXREGI__EADXREGL_LOW_ONLY_IMMI_32_63:    return NULL;
  case _RSHIFTL__MULL_EADXREGL_LOW_ONLY__CONVI2L_NADXREGI__IMMI_32_63:    return NULL;
  case _CONVI2L_EAXREGI_:    return NULL;
  case _ANDL__CONVI2L_EAXREGI__IMML_32BITS:    return NULL;
  case _ANDL__CONVI2L_NADXREGI__IMML_32BITS:    return NULL;
  case _RSHIFTI__LOADI_MEMORY__IMMI1:    return NULL;
  case _RSHIFTI__LOADI_MEMORY__IMMI8:    return NULL;
  case _LSHIFTI_XREGI_IMMI_24:    return NULL;
  case _LSHIFTI_XREGI_IMMI_16:    return NULL;
  case _ANDI__LOADI_MEMORY__EREGI:    return NULL;
  case _ANDI_EREGI__LOADI_MEMORY_:    return NULL;
  case _CASTP2X_EREGP_:    return NULL;
  case _ORI__LOADI_MEMORY__EREGI:    return NULL;
  case _ORI_EREGI__LOADI_MEMORY_:    return NULL;
  case _ORI__LOADI_MEMORY__IMMI:    return NULL;
  case _LSHIFTI_EREGI_IMMI1:    return NULL;
  case _URSHIFTI_EREGI_IMMI_M1:    return NULL;
  case _LSHIFTI_EREGI_IMMI8:    return NULL;
  case _URSHIFTI_EREGI_IMMI8:    return NULL;
  case _LSHIFTI_NCXREGI_ECXREGI:    return NULL;
  case _SUBI_IMMI0_ECXREGI:    return NULL;
  case _URSHIFTI_NCXREGI__SUBI_IMMI0_ECXREGI:    return NULL;
  case _SUBI_IMMI_32_ECXREGI:    return NULL;
  case _URSHIFTI_NCXREGI__SUBI_IMMI_32_ECXREGI:    return NULL;
  case _URSHIFTI_EREGI_IMMI1:    return NULL;
  case _LSHIFTI_EREGI_IMMI_M1:    return NULL;
  case _URSHIFTI_NCXREGI_ECXREGI:    return NULL;
  case _LSHIFTI_NCXREGI__SUBI_IMMI0_ECXREGI:    return NULL;
  case _LSHIFTI_NCXREGI__SUBI_IMMI_32_ECXREGI:    return NULL;
  case _XORI__LOADI_MEMORY__EREGI:    return NULL;
  case _XORI_EREGI__LOADI_MEMORY_:    return NULL;
  case _XORI__LOADI_MEMORY__IMMI:    return NULL;
  case _CMPLTMASK_NCXREGI_NCXREGI:    return NULL;
  case _ANDI__CMPLTMASK_NCXREGI_NCXREGI_NCXREGI:    return NULL;
  case _SUBI_NCXREGI_NCXREGI:    return NULL;
  case _ANDI_NCXREGI__CMPLTMASK_NCXREGI_NCXREGI:    return NULL;
  case _LOADL_LOAD_LONG_MEMORY_:    return NULL;
  case _LOADD_MEMORY_:    return NULL;
  case _SUBD_REGD_REGD:    return NULL;
  case _ADDD_REGD_REGD:    return NULL;
  case _ADDD__LOADD_MEMORY__REGD:    return NULL;
  case _ROUNDDOUBLE__ADDD__LOADD_MEMORY__REGD_:    return NULL;
  case _ADDD_REGD__LOADD_MEMORY_:    return NULL;
  case _ROUNDDOUBLE__ADDD_REGD__LOADD_MEMORY__:    return NULL;
  case _ADDD_REGD_IMMD:    return NULL;
  case _MULD_REGD_REGD:    return NULL;
  case _DIVD_REGD_REGD:    return NULL;
  case _LOADF_MEMORY_:    return NULL;
  case _CONVF2D_REGX_:    return NULL;
  case _SQRTD__CONVF2D_REGX__:    return NULL;
  case _CONVF2D__LOADF_MEMORY__:    return NULL;
  case _SQRTD__CONVF2D__LOADF_MEMORY___:    return NULL;
  case _MULF__LOADF_MEMORY__REGF:    return NULL;
  case _MULF_REGF__LOADF_MEMORY_:    return NULL;
  case _MULF_REGF_REGF:    return NULL;
  case _SUBF_REGF_REGF:    return NULL;
  case _CONVI2L_EREGI_:    return NULL;
  case _BINARY_EDIREGP_ECXREGI:    return NULL;
  case _BINARY_ESIREGP_EBXREGI:    return NULL;
  case _BINARY_EDIREGP_ESIREGP:    return NULL;
  case _BINARY_EDIREGP_EDXREGI:    return NULL;
  case _BINARY_ESIREGP_EAXREGI:    return NULL;
  case _ANDI_EREGI_IMMI:    return NULL;
  case _ANDI_EREGI_MEMORY:    return NULL;
  case _LOADP_MEMORY_:    return NULL;
  case _PARTIALSUBTYPECHECK_ESIREGP_EAXREGP:    return NULL;
  case _BINARY_CMPOP_FLAGSREG_LONG_LTGE:    return NULL;
  case _BINARY_EREGL__LOADL_LOAD_LONG_MEMORY_:    return NULL;
  case _BINARY_CMPOP_FLAGSREG_LONG_EQNE:    return NULL;
  case _BINARY_CMPOP_COMMUTE_FLAGSREG_LONG_LEGT:    return NULL;
  
  default:
    fprintf(stderr, "Default MachOper Generator invoked for: \n");
    fprintf(stderr, "   opcode = %d\n", opcode);
    break;
  }
  return NULL;
};


//------------------------- MachNode Generator ---------------
// A switch statement on the dense-packed user-defined type system
// that invokes 'new' on the corresponding class constructor.

MachNode *State::MachNodeGenerator(int opcode, Compile* C){
  switch(opcode) {
  case bytes_reverse_int_rule:  {
      bytes_reverse_intNode *node = new (C) bytes_reverse_intNode();
      return node;
    }
  case bytes_reverse_long_rule:  {
      bytes_reverse_longNode *node = new (C) bytes_reverse_longNode();
      return node;
    }
  case bytes_reverse_unsigned_short_rule:  {
      bytes_reverse_unsigned_shortNode *node = new (C) bytes_reverse_unsigned_shortNode();
      return node;
    }
  case bytes_reverse_short_rule:  {
      bytes_reverse_shortNode *node = new (C) bytes_reverse_shortNode();
      return node;
    }
  case countLeadingZerosI_rule:  {
      countLeadingZerosINode *node = new (C) countLeadingZerosINode();
      return node;
    }
  case countLeadingZerosI_bsr_rule:  {
      countLeadingZerosI_bsrNode *node = new (C) countLeadingZerosI_bsrNode();
      return node;
    }
  case countLeadingZerosL_rule:  {
      countLeadingZerosLNode *node = new (C) countLeadingZerosLNode();
      node->set_opnd_array(2, MachOperGenerator(EREGI, C));
      return node;
    }
  case countLeadingZerosL_bsr_rule:  {
      countLeadingZerosL_bsrNode *node = new (C) countLeadingZerosL_bsrNode();
      node->set_opnd_array(2, MachOperGenerator(EREGI, C));
      return node;
    }
  case countTrailingZerosI_rule:  {
      countTrailingZerosINode *node = new (C) countTrailingZerosINode();
      return node;
    }
  case countTrailingZerosL_rule:  {
      countTrailingZerosLNode *node = new (C) countTrailingZerosLNode();
      node->set_opnd_array(2, MachOperGenerator(EREGI, C));
      return node;
    }
  case popCountI_rule:  {
      popCountINode *node = new (C) popCountINode();
      return node;
    }
  case popCountI_mem_rule:  {
      popCountI_memNode *node = new (C) popCountI_memNode();
      return node;
    }
  case popCountL_rule:  {
      popCountLNode *node = new (C) popCountLNode();
      node->set_opnd_array(2, MachOperGenerator(EREGI, C));
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case popCountL_mem_rule:  {
      popCountL_memNode *node = new (C) popCountL_memNode();
      node->set_opnd_array(2, MachOperGenerator(EREGI, C));
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case loadB_rule:  {
      loadBNode *node = new (C) loadBNode();
      return node;
    }
  case loadB2L_rule:  {
      loadB2LNode *node = new (C) loadB2LNode();
      return node;
    }
  case loadUB_rule:  {
      loadUBNode *node = new (C) loadUBNode();
      return node;
    }
  case loadUB2L_rule:  {
      loadUB2LNode *node = new (C) loadUB2LNode();
      return node;
    }
  case loadUB2L_immI8_rule:  {
      loadUB2L_immI8Node *node = new (C) loadUB2L_immI8Node();
      return node;
    }
  case loadS_rule:  {
      loadSNode *node = new (C) loadSNode();
      return node;
    }
  case loadS2B_rule:  {
      loadS2BNode *node = new (C) loadS2BNode();
      return node;
    }
  case loadS2L_rule:  {
      loadS2LNode *node = new (C) loadS2LNode();
      return node;
    }
  case loadUS_rule:  {
      loadUSNode *node = new (C) loadUSNode();
      return node;
    }
  case loadUS2B_rule:  {
      loadUS2BNode *node = new (C) loadUS2BNode();
      return node;
    }
  case loadUS2L_rule:  {
      loadUS2LNode *node = new (C) loadUS2LNode();
      return node;
    }
  case loadUS2L_immI_255_rule:  {
      loadUS2L_immI_255Node *node = new (C) loadUS2L_immI_255Node();
      return node;
    }
  case loadUS2L_immI16_rule:  {
      loadUS2L_immI16Node *node = new (C) loadUS2L_immI16Node();
      return node;
    }
  case loadI_rule:  {
      loadINode *node = new (C) loadINode();
      return node;
    }
  case loadI2B_rule:  {
      loadI2BNode *node = new (C) loadI2BNode();
      return node;
    }
  case loadI2UB_rule:  {
      loadI2UBNode *node = new (C) loadI2UBNode();
      return node;
    }
  case loadI2S_rule:  {
      loadI2SNode *node = new (C) loadI2SNode();
      return node;
    }
  case loadI2US_rule:  {
      loadI2USNode *node = new (C) loadI2USNode();
      return node;
    }
  case loadI2L_rule:  {
      loadI2LNode *node = new (C) loadI2LNode();
      return node;
    }
  case loadI2L_immI_255_rule:  {
      loadI2L_immI_255Node *node = new (C) loadI2L_immI_255Node();
      return node;
    }
  case loadI2L_immI_65535_rule:  {
      loadI2L_immI_65535Node *node = new (C) loadI2L_immI_65535Node();
      return node;
    }
  case loadI2L_immI_rule:  {
      loadI2L_immINode *node = new (C) loadI2L_immINode();
      return node;
    }
  case loadUI2L_rule:  {
      loadUI2LNode *node = new (C) loadUI2LNode();
      return node;
    }
  case loadL_rule:  {
      loadLNode *node = new (C) loadLNode();
      return node;
    }
  case loadL_volatile_rule:  {
      loadL_volatileNode *node = new (C) loadL_volatileNode();
      return node;
    }
  case loadLX_volatile_rule:  {
      loadLX_volatileNode *node = new (C) loadLX_volatileNode();
      node->set_opnd_array(2, MachOperGenerator(REGXD, C));
      return node;
    }
  case loadLX_reg_volatile_rule:  {
      loadLX_reg_volatileNode *node = new (C) loadLX_reg_volatileNode();
      node->set_opnd_array(2, MachOperGenerator(REGXD, C));
      return node;
    }
  case loadRange_rule:  {
      loadRangeNode *node = new (C) loadRangeNode();
      return node;
    }
  case loadP_rule:  {
      loadPNode *node = new (C) loadPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadKlass_rule:  {
      loadKlassNode *node = new (C) loadKlassNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadD_rule:  {
      loadDNode *node = new (C) loadDNode();
      return node;
    }
  case loadXD_rule:  {
      loadXDNode *node = new (C) loadXDNode();
      return node;
    }
  case loadXD_partial_rule:  {
      loadXD_partialNode *node = new (C) loadXD_partialNode();
      return node;
    }
  case loadX_rule:  {
      loadXNode *node = new (C) loadXNode();
      return node;
    }
  case loadF_rule:  {
      loadFNode *node = new (C) loadFNode();
      return node;
    }
  case loadA8B_rule:  {
      loadA8BNode *node = new (C) loadA8BNode();
      return node;
    }
  case loadA4S_rule:  {
      loadA4SNode *node = new (C) loadA4SNode();
      return node;
    }
  case loadA4C_rule:  {
      loadA4CNode *node = new (C) loadA4CNode();
      return node;
    }
  case load2IU_rule:  {
      load2IUNode *node = new (C) load2IUNode();
      return node;
    }
  case loadA2F_rule:  {
      loadA2FNode *node = new (C) loadA2FNode();
      return node;
    }
  case leaP8_rule:  {
      leaP8Node *node = new (C) leaP8Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case leaP32_rule:  {
      leaP32Node *node = new (C) leaP32Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case leaPIdxOff_rule:  {
      leaPIdxOffNode *node = new (C) leaPIdxOffNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case leaPIdxScale_rule:  {
      leaPIdxScaleNode *node = new (C) leaPIdxScaleNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case leaPIdxScaleOff_rule:  {
      leaPIdxScaleOffNode *node = new (C) leaPIdxScaleOffNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadConI_rule:  {
      loadConINode *node = new (C) loadConINode();
      node->_opnd_array[1] = new (C) immIOper(_leaf->get_int() );
      return node;
    }
  case loadConI0_rule:  {
      loadConI0Node *node = new (C) loadConI0Node();
      return node;
    }
  case loadConP_rule:  {
      loadConPNode *node = new (C) loadConPNode();
      node->_opnd_array[1] = new (C) immPOper(_leaf->bottom_type()->is_ptr() );
      return node;
    }
  case loadConL_rule:  {
      loadConLNode *node = new (C) loadConLNode();
      return node;
    }
  case loadConL0_rule:  {
      loadConL0Node *node = new (C) loadConL0Node();
      return node;
    }
  case loadConF_rule:  {
      loadConFNode *node = new (C) loadConFNode();
      node->_opnd_array[1] = new (C) immFOper(_leaf->getf() );
      return node;
    }
  case loadConX_rule:  {
      loadConXNode *node = new (C) loadConXNode();
      node->_opnd_array[1] = new (C) immXFOper(_leaf->getf() );
      return node;
    }
  case loadConX0_rule:  {
      loadConX0Node *node = new (C) loadConX0Node();
      node->_opnd_array[1] = new (C) immXF0Oper(_leaf->getf() );
      return node;
    }
  case loadConD_rule:  {
      loadConDNode *node = new (C) loadConDNode();
      node->_opnd_array[1] = new (C) immDOper(_leaf->getd() );
      return node;
    }
  case loadConXD_rule:  {
      loadConXDNode *node = new (C) loadConXDNode();
      node->_opnd_array[1] = new (C) immXDOper(_leaf->getd() );
      return node;
    }
  case loadConXD0_rule:  {
      loadConXD0Node *node = new (C) loadConXD0Node();
      node->_opnd_array[1] = new (C) immXD0Oper(_leaf->getd() );
      return node;
    }
  case loadSSI_rule:  {
      loadSSINode *node = new (C) loadSSINode();
      return node;
    }
  case loadSSL_rule:  {
      loadSSLNode *node = new (C) loadSSLNode();
      return node;
    }
  case loadSSP_rule:  {
      loadSSPNode *node = new (C) loadSSPNode();
      return node;
    }
  case loadSSF_rule:  {
      loadSSFNode *node = new (C) loadSSFNode();
      return node;
    }
  case loadSSD_rule:  {
      loadSSDNode *node = new (C) loadSSDNode();
      return node;
    }
  case prefetchr0_rule:  {
      prefetchr0Node *node = new (C) prefetchr0Node();
      return node;
    }
  case prefetchr_rule:  {
      prefetchrNode *node = new (C) prefetchrNode();
      return node;
    }
  case prefetchrNTA_rule:  {
      prefetchrNTANode *node = new (C) prefetchrNTANode();
      return node;
    }
  case prefetchrT0_rule:  {
      prefetchrT0Node *node = new (C) prefetchrT0Node();
      return node;
    }
  case prefetchrT2_rule:  {
      prefetchrT2Node *node = new (C) prefetchrT2Node();
      return node;
    }
  case prefetchw0_rule:  {
      prefetchw0Node *node = new (C) prefetchw0Node();
      return node;
    }
  case prefetchw_rule:  {
      prefetchwNode *node = new (C) prefetchwNode();
      return node;
    }
  case prefetchwNTA_rule:  {
      prefetchwNTANode *node = new (C) prefetchwNTANode();
      return node;
    }
  case prefetchwT0_rule:  {
      prefetchwT0Node *node = new (C) prefetchwT0Node();
      return node;
    }
  case prefetchwT2_rule:  {
      prefetchwT2Node *node = new (C) prefetchwT2Node();
      return node;
    }
  case storeB_rule:  {
      storeBNode *node = new (C) storeBNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeC_rule:  {
      storeCNode *node = new (C) storeCNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeI_rule:  {
      storeINode *node = new (C) storeINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL_rule:  {
      storeLNode *node = new (C) storeLNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL2I_rule:  {
      storeL2INode *node = new (C) storeL2INode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeL_volatile_rule:  {
      storeL_volatileNode *node = new (C) storeL_volatileNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeLX_volatile_rule:  {
      storeLX_volatileNode *node = new (C) storeLX_volatileNode();
      node->set_opnd_array(3, MachOperGenerator(REGXD, C));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeLX_reg_volatile_rule:  {
      storeLX_reg_volatileNode *node = new (C) storeLX_reg_volatileNode();
      node->set_opnd_array(3, MachOperGenerator(REGXD, C));
      node->set_opnd_array(4, MachOperGenerator(REGXD, C));
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeP_rule:  {
      storePNode *node = new (C) storePNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeImmI_rule:  {
      storeImmINode *node = new (C) storeImmINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeImmI16_rule:  {
      storeImmI16Node *node = new (C) storeImmI16Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeImmP_rule:  {
      storeImmPNode *node = new (C) storeImmPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeImmB_rule:  {
      storeImmBNode *node = new (C) storeImmBNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeA8B_rule:  {
      storeA8BNode *node = new (C) storeA8BNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeA4C_rule:  {
      storeA4CNode *node = new (C) storeA4CNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeA2I_rule:  {
      storeA2INode *node = new (C) storeA2INode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeImmCM_rule:  {
      storeImmCMNode *node = new (C) storeImmCMNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeD_rule:  {
      storeDNode *node = new (C) storeDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeD_rounded_rule:  {
      storeD_roundedNode *node = new (C) storeD_roundedNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeXD_rule:  {
      storeXDNode *node = new (C) storeXDNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeX_rule:  {
      storeXNode *node = new (C) storeXNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeA2F_rule:  {
      storeA2FNode *node = new (C) storeA2FNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeF_rule:  {
      storeFNode *node = new (C) storeFNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeF_rounded_rule:  {
      storeF_roundedNode *node = new (C) storeF_roundedNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeF_Drounded_rule:  {
      storeF_DroundedNode *node = new (C) storeF_DroundedNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeF_imm_rule:  {
      storeF_immNode *node = new (C) storeF_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeX_imm_rule:  {
      storeX_immNode *node = new (C) storeX_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case storeSSI_rule:  {
      storeSSINode *node = new (C) storeSSINode();
      return node;
    }
  case storeSSP_rule:  {
      storeSSPNode *node = new (C) storeSSPNode();
      return node;
    }
  case storeSSL_rule:  {
      storeSSLNode *node = new (C) storeSSLNode();
      return node;
    }
  case membar_acquire_rule:  {
      membar_acquireNode *node = new (C) membar_acquireNode();
      return node;
    }
  case membar_acquire_lock_rule:  {
      membar_acquire_lockNode *node = new (C) membar_acquire_lockNode();
      return node;
    }
  case membar_release_rule:  {
      membar_releaseNode *node = new (C) membar_releaseNode();
      return node;
    }
  case membar_release_lock_rule:  {
      membar_release_lockNode *node = new (C) membar_release_lockNode();
      return node;
    }
  case membar_volatile_rule:  {
      membar_volatileNode *node = new (C) membar_volatileNode();
      node->set_opnd_array(1, MachOperGenerator(EFLAGSREG, C));
      return node;
    }
  case unnecessary_membar_volatile_rule:  {
      unnecessary_membar_volatileNode *node = new (C) unnecessary_membar_volatileNode();
      return node;
    }
  case castX2P_rule:  {
      castX2PNode *node = new (C) castX2PNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case castP2X_rule:  {
      castP2XNode *node = new (C) castP2XNode();
      return node;
    }
  case cmovI_reg_rule:  {
      cmovI_regNode *node = new (C) cmovI_regNode();
      return node;
    }
  case cmovI_regU_rule:  {
      cmovI_regUNode *node = new (C) cmovI_regUNode();
      return node;
    }
  case cmovI_regUCF_rule:  {
      cmovI_regUCFNode *node = new (C) cmovI_regUCFNode();
      return node;
    }
  case cmovI_mem_rule:  {
      cmovI_memNode *node = new (C) cmovI_memNode();
      return node;
    }
  case cmovI_memU_rule:  {
      cmovI_memUNode *node = new (C) cmovI_memUNode();
      return node;
    }
  case cmovI_memUCF_rule:  {
      cmovI_memUCFNode *node = new (C) cmovI_memUCFNode();
      return node;
    }
  case cmovP_reg_rule:  {
      cmovP_regNode *node = new (C) cmovP_regNode();
      return node;
    }
  case cmovP_reg_nonP6_rule:  {
      cmovP_reg_nonP6Node *node = new (C) cmovP_reg_nonP6Node();
      return node;
    }
  case cmovP_regU_rule:  {
      cmovP_regUNode *node = new (C) cmovP_regUNode();
      return node;
    }
  case cmovP_regUCF_rule:  {
      cmovP_regUCFNode *node = new (C) cmovP_regUCFNode();
      return node;
    }
  case fcmovD_regU_rule:  {
      fcmovD_regUNode *node = new (C) fcmovD_regUNode();
      return node;
    }
  case fcmovF_regU_rule:  {
      fcmovF_regUNode *node = new (C) fcmovF_regUNode();
      return node;
    }
  case fcmovD_regS_rule:  {
      fcmovD_regSNode *node = new (C) fcmovD_regSNode();
      return node;
    }
  case fcmovF_regS_rule:  {
      fcmovF_regSNode *node = new (C) fcmovF_regSNode();
      return node;
    }
  case fcmovX_regS_rule:  {
      fcmovX_regSNode *node = new (C) fcmovX_regSNode();
      return node;
    }
  case fcmovXD_regS_rule:  {
      fcmovXD_regSNode *node = new (C) fcmovXD_regSNode();
      return node;
    }
  case fcmovX_regU_rule:  {
      fcmovX_regUNode *node = new (C) fcmovX_regUNode();
      return node;
    }
  case fcmovX_regUCF_rule:  {
      fcmovX_regUCFNode *node = new (C) fcmovX_regUCFNode();
      return node;
    }
  case fcmovXD_regU_rule:  {
      fcmovXD_regUNode *node = new (C) fcmovXD_regUNode();
      return node;
    }
  case fcmovXD_regUCF_rule:  {
      fcmovXD_regUCFNode *node = new (C) fcmovXD_regUCFNode();
      return node;
    }
  case cmovL_reg_rule:  {
      cmovL_regNode *node = new (C) cmovL_regNode();
      return node;
    }
  case cmovL_regU_rule:  {
      cmovL_regUNode *node = new (C) cmovL_regUNode();
      return node;
    }
  case cmovL_regUCF_rule:  {
      cmovL_regUCFNode *node = new (C) cmovL_regUCFNode();
      return node;
    }
  case addI_eReg_rule:  {
      addI_eRegNode *node = new (C) addI_eRegNode();
      return node;
    }
  case addI_eReg_imm_rule:  {
      addI_eReg_immNode *node = new (C) addI_eReg_immNode();
      return node;
    }
  case incI_eReg_rule:  {
      incI_eRegNode *node = new (C) incI_eRegNode();
      return node;
    }
  case leaI_eReg_immI_rule:  {
      leaI_eReg_immINode *node = new (C) leaI_eReg_immINode();
      return node;
    }
  case leaP_eReg_immI_rule:  {
      leaP_eReg_immINode *node = new (C) leaP_eReg_immINode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case decI_eReg_rule:  {
      decI_eRegNode *node = new (C) decI_eRegNode();
      return node;
    }
  case addP_eReg_rule:  {
      addP_eRegNode *node = new (C) addP_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addP_eReg_imm_rule:  {
      addP_eReg_immNode *node = new (C) addP_eReg_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addI_eReg_mem_rule:  {
      addI_eReg_memNode *node = new (C) addI_eReg_memNode();
      return node;
    }
  case addI_eReg_mem_0_rule:  {
      addI_eReg_mem_0Node *node = new (C) addI_eReg_mem_0Node();
      return node;
    }
  case addI_mem_eReg_rule:  {
      addI_mem_eRegNode *node = new (C) addI_mem_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addI_mem_eReg_0_rule:  {
      addI_mem_eReg_0Node *node = new (C) addI_mem_eReg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addI_mem_imm_rule:  {
      addI_mem_immNode *node = new (C) addI_mem_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case incI_mem_rule:  {
      incI_memNode *node = new (C) incI_memNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case decI_mem_rule:  {
      decI_memNode *node = new (C) decI_memNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case checkCastPP_rule:  {
      checkCastPPNode *node = new (C) checkCastPPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case castPP_rule:  {
      castPPNode *node = new (C) castPPNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case castII_rule:  {
      castIINode *node = new (C) castIINode();
      return node;
    }
  case loadPLocked_rule:  {
      loadPLockedNode *node = new (C) loadPLockedNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case loadLLocked_rule:  {
      loadLLockedNode *node = new (C) loadLLockedNode();
      return node;
    }
  case loadLX_Locked_rule:  {
      loadLX_LockedNode *node = new (C) loadLX_LockedNode();
      node->set_opnd_array(2, MachOperGenerator(REGXD, C));
      return node;
    }
  case loadLX_reg_Locked_rule:  {
      loadLX_reg_LockedNode *node = new (C) loadLX_reg_LockedNode();
      node->set_opnd_array(2, MachOperGenerator(REGXD, C));
      return node;
    }
  case storePConditional_rule:  {
      storePConditionalNode *node = new (C) storePConditionalNode();
      return node;
    }
  case storeIConditional_rule:  {
      storeIConditionalNode *node = new (C) storeIConditionalNode();
      return node;
    }
  case storeLConditional_rule:  {
      storeLConditionalNode *node = new (C) storeLConditionalNode();
      return node;
    }
  case compareAndSwapL_rule:  {
      compareAndSwapLNode *node = new (C) compareAndSwapLNode();
      return node;
    }
  case compareAndSwapP_rule:  {
      compareAndSwapPNode *node = new (C) compareAndSwapPNode();
      return node;
    }
  case compareAndSwapI_rule:  {
      compareAndSwapINode *node = new (C) compareAndSwapINode();
      return node;
    }
  case subI_eReg_rule:  {
      subI_eRegNode *node = new (C) subI_eRegNode();
      return node;
    }
  case subI_eReg_imm_rule:  {
      subI_eReg_immNode *node = new (C) subI_eReg_immNode();
      return node;
    }
  case subI_eReg_mem_rule:  {
      subI_eReg_memNode *node = new (C) subI_eReg_memNode();
      return node;
    }
  case subI_mem_eReg_rule:  {
      subI_mem_eRegNode *node = new (C) subI_mem_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case subP_eReg_rule:  {
      subP_eRegNode *node = new (C) subP_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case negI_eReg_rule:  {
      negI_eRegNode *node = new (C) negI_eRegNode();
      return node;
    }
  case mulI_eReg_rule:  {
      mulI_eRegNode *node = new (C) mulI_eRegNode();
      return node;
    }
  case mulI_eReg_imm_rule:  {
      mulI_eReg_immNode *node = new (C) mulI_eReg_immNode();
      return node;
    }
  case loadConL_low_only_rule:  {
      loadConL_low_onlyNode *node = new (C) loadConL_low_onlyNode();
      return node;
    }
  case mulI_imm_high_rule:  {
      mulI_imm_highNode *node = new (C) mulI_imm_highNode();
      return node;
    }
  case mulI_imm_high_0_rule:  {
      mulI_imm_high_0Node *node = new (C) mulI_imm_high_0Node();
      return node;
    }
  case mulI_imm_RShift_high_rule:  {
      mulI_imm_RShift_highNode *node = new (C) mulI_imm_RShift_highNode();
      return node;
    }
  case mulI_imm_RShift_high_0_rule:  {
      mulI_imm_RShift_high_0Node *node = new (C) mulI_imm_RShift_high_0Node();
      return node;
    }
  case mulI_mem_imm_rule:  {
      mulI_mem_immNode *node = new (C) mulI_mem_immNode();
      return node;
    }
  case mulI_rule:  {
      mulINode *node = new (C) mulINode();
      return node;
    }
  case mulI_0_rule:  {
      mulI_0Node *node = new (C) mulI_0Node();
      return node;
    }
  case mulI2L_rule:  {
      mulI2LNode *node = new (C) mulI2LNode();
      return node;
    }
  case mulI2L_0_rule:  {
      mulI2L_0Node *node = new (C) mulI2L_0Node();
      return node;
    }
  case mulIS_eReg_rule:  {
      mulIS_eRegNode *node = new (C) mulIS_eRegNode();
      return node;
    }
  case mulIS_eReg_0_rule:  {
      mulIS_eReg_0Node *node = new (C) mulIS_eReg_0Node();
      return node;
    }
  case mulL_eReg_rule:  {
      mulL_eRegNode *node = new (C) mulL_eRegNode();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case mulL_eReg_lhi0_rule:  {
      mulL_eReg_lhi0Node *node = new (C) mulL_eReg_lhi0Node();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case mulL_eReg_rhi0_rule:  {
      mulL_eReg_rhi0Node *node = new (C) mulL_eReg_rhi0Node();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case mulL_eReg_hi0_rule:  {
      mulL_eReg_hi0Node *node = new (C) mulL_eReg_hi0Node();
      return node;
    }
  case mulL_eReg_con_rule:  {
      mulL_eReg_conNode *node = new (C) mulL_eReg_conNode();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case divI_eReg_rule:  {
      divI_eRegNode *node = new (C) divI_eRegNode();
      return node;
    }
  case divL_eReg_rule:  {
      divL_eRegNode *node = new (C) divL_eRegNode();
      return node;
    }
  case divModI_eReg_divmod_rule:  {
      divModI_eReg_divmodNode *node = new (C) divModI_eReg_divmodNode();
      return node;
    }
  case modI_eReg_rule:  {
      modI_eRegNode *node = new (C) modI_eRegNode();
      return node;
    }
  case modL_eReg_rule:  {
      modL_eRegNode *node = new (C) modL_eRegNode();
      return node;
    }
  case shlI_eReg_1_rule:  {
      shlI_eReg_1Node *node = new (C) shlI_eReg_1Node();
      return node;
    }
  case salI_eReg_imm_rule:  {
      salI_eReg_immNode *node = new (C) salI_eReg_immNode();
      return node;
    }
  case salI_eReg_CL_rule:  {
      salI_eReg_CLNode *node = new (C) salI_eReg_CLNode();
      return node;
    }
  case sarI_eReg_1_rule:  {
      sarI_eReg_1Node *node = new (C) sarI_eReg_1Node();
      return node;
    }
  case sarI_mem_1_rule:  {
      sarI_mem_1Node *node = new (C) sarI_mem_1Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case sarI_eReg_imm_rule:  {
      sarI_eReg_immNode *node = new (C) sarI_eReg_immNode();
      return node;
    }
  case sarI_mem_imm_rule:  {
      sarI_mem_immNode *node = new (C) sarI_mem_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case sarI_eReg_CL_rule:  {
      sarI_eReg_CLNode *node = new (C) sarI_eReg_CLNode();
      return node;
    }
  case shrI_eReg_1_rule:  {
      shrI_eReg_1Node *node = new (C) shrI_eReg_1Node();
      return node;
    }
  case shrI_eReg_imm_rule:  {
      shrI_eReg_immNode *node = new (C) shrI_eReg_immNode();
      return node;
    }
  case i2b_rule:  {
      i2bNode *node = new (C) i2bNode();
      return node;
    }
  case i2s_rule:  {
      i2sNode *node = new (C) i2sNode();
      return node;
    }
  case shrI_eReg_CL_rule:  {
      shrI_eReg_CLNode *node = new (C) shrI_eReg_CLNode();
      return node;
    }
  case andI_eReg_rule:  {
      andI_eRegNode *node = new (C) andI_eRegNode();
      return node;
    }
  case andI_eReg_imm_rule:  {
      andI_eReg_immNode *node = new (C) andI_eReg_immNode();
      return node;
    }
  case andI_eReg_mem_rule:  {
      andI_eReg_memNode *node = new (C) andI_eReg_memNode();
      return node;
    }
  case andI_eReg_mem_0_rule:  {
      andI_eReg_mem_0Node *node = new (C) andI_eReg_mem_0Node();
      return node;
    }
  case andI_mem_eReg_rule:  {
      andI_mem_eRegNode *node = new (C) andI_mem_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case andI_mem_eReg_0_rule:  {
      andI_mem_eReg_0Node *node = new (C) andI_mem_eReg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case andI_mem_imm_rule:  {
      andI_mem_immNode *node = new (C) andI_mem_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case orI_eReg_rule:  {
      orI_eRegNode *node = new (C) orI_eRegNode();
      return node;
    }
  case orI_eReg_castP2X_rule:  {
      orI_eReg_castP2XNode *node = new (C) orI_eReg_castP2XNode();
      return node;
    }
  case orI_eReg_castP2X_0_rule:  {
      orI_eReg_castP2X_0Node *node = new (C) orI_eReg_castP2X_0Node();
      return node;
    }
  case orI_eReg_imm_rule:  {
      orI_eReg_immNode *node = new (C) orI_eReg_immNode();
      return node;
    }
  case orI_eReg_mem_rule:  {
      orI_eReg_memNode *node = new (C) orI_eReg_memNode();
      return node;
    }
  case orI_eReg_mem_0_rule:  {
      orI_eReg_mem_0Node *node = new (C) orI_eReg_mem_0Node();
      return node;
    }
  case orI_mem_eReg_rule:  {
      orI_mem_eRegNode *node = new (C) orI_mem_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case orI_mem_eReg_0_rule:  {
      orI_mem_eReg_0Node *node = new (C) orI_mem_eReg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case orI_mem_imm_rule:  {
      orI_mem_immNode *node = new (C) orI_mem_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case rolI_eReg_i1_rule:  {
      rolI_eReg_i1Node *node = new (C) rolI_eReg_i1Node();
      return node;
    }
  case rolI_eReg_i1_0_rule:  {
      rolI_eReg_i1_0Node *node = new (C) rolI_eReg_i1_0Node();
      return node;
    }
  case rolI_eReg_i8_rule:  {
      rolI_eReg_i8Node *node = new (C) rolI_eReg_i8Node();
      return node;
    }
  case rolI_eReg_i8_0_rule:  {
      rolI_eReg_i8_0Node *node = new (C) rolI_eReg_i8_0Node();
      return node;
    }
  case rolI_eReg_Var_C0_rule:  {
      rolI_eReg_Var_C0Node *node = new (C) rolI_eReg_Var_C0Node();
      return node;
    }
  case rolI_eReg_Var_C0_0_rule:  {
      rolI_eReg_Var_C0_0Node *node = new (C) rolI_eReg_Var_C0_0Node();
      return node;
    }
  case rolI_eReg_Var_C32_rule:  {
      rolI_eReg_Var_C32Node *node = new (C) rolI_eReg_Var_C32Node();
      return node;
    }
  case rolI_eReg_Var_C32_0_rule:  {
      rolI_eReg_Var_C32_0Node *node = new (C) rolI_eReg_Var_C32_0Node();
      return node;
    }
  case rorI_eReg_i1_rule:  {
      rorI_eReg_i1Node *node = new (C) rorI_eReg_i1Node();
      return node;
    }
  case rorI_eReg_i1_0_rule:  {
      rorI_eReg_i1_0Node *node = new (C) rorI_eReg_i1_0Node();
      return node;
    }
  case rorI_eReg_i8_rule:  {
      rorI_eReg_i8Node *node = new (C) rorI_eReg_i8Node();
      return node;
    }
  case rorI_eReg_i8_0_rule:  {
      rorI_eReg_i8_0Node *node = new (C) rorI_eReg_i8_0Node();
      return node;
    }
  case rorI_eReg_Var_C0_rule:  {
      rorI_eReg_Var_C0Node *node = new (C) rorI_eReg_Var_C0Node();
      return node;
    }
  case rorI_eReg_Var_C0_0_rule:  {
      rorI_eReg_Var_C0_0Node *node = new (C) rorI_eReg_Var_C0_0Node();
      return node;
    }
  case rorI_eReg_Var_C32_rule:  {
      rorI_eReg_Var_C32Node *node = new (C) rorI_eReg_Var_C32Node();
      return node;
    }
  case rorI_eReg_Var_C32_0_rule:  {
      rorI_eReg_Var_C32_0Node *node = new (C) rorI_eReg_Var_C32_0Node();
      return node;
    }
  case xorI_eReg_rule:  {
      xorI_eRegNode *node = new (C) xorI_eRegNode();
      return node;
    }
  case xorI_eReg_im1_rule:  {
      xorI_eReg_im1Node *node = new (C) xorI_eReg_im1Node();
      return node;
    }
  case xorI_eReg_imm_rule:  {
      xorI_eReg_immNode *node = new (C) xorI_eReg_immNode();
      return node;
    }
  case xorI_eReg_mem_rule:  {
      xorI_eReg_memNode *node = new (C) xorI_eReg_memNode();
      return node;
    }
  case xorI_eReg_mem_0_rule:  {
      xorI_eReg_mem_0Node *node = new (C) xorI_eReg_mem_0Node();
      return node;
    }
  case xorI_mem_eReg_rule:  {
      xorI_mem_eRegNode *node = new (C) xorI_mem_eRegNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case xorI_mem_eReg_0_rule:  {
      xorI_mem_eReg_0Node *node = new (C) xorI_mem_eReg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case xorI_mem_imm_rule:  {
      xorI_mem_immNode *node = new (C) xorI_mem_immNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case convI2B_rule:  {
      convI2BNode *node = new (C) convI2BNode();
      return node;
    }
  case convP2B_rule:  {
      convP2BNode *node = new (C) convP2BNode();
      return node;
    }
  case cmpLTMask_rule:  {
      cmpLTMaskNode *node = new (C) cmpLTMaskNode();
      return node;
    }
  case cmpLTMask0_rule:  {
      cmpLTMask0Node *node = new (C) cmpLTMask0Node();
      return node;
    }
  case cadd_cmpLTMask_rule:  {
      cadd_cmpLTMaskNode *node = new (C) cadd_cmpLTMaskNode();
      return node;
    }
  case cadd_cmpLTMask_1_rule:  {
      cadd_cmpLTMask_1Node *node = new (C) cadd_cmpLTMask_1Node();
      return node;
    }
  case cadd_cmpLTMask_0_rule:  {
      cadd_cmpLTMask_0Node *node = new (C) cadd_cmpLTMask_0Node();
      return node;
    }
  case cadd_cmpLTMask_2_rule:  {
      cadd_cmpLTMask_2Node *node = new (C) cadd_cmpLTMask_2Node();
      return node;
    }
  case addL_eReg_rule:  {
      addL_eRegNode *node = new (C) addL_eRegNode();
      return node;
    }
  case addL_eReg_imm_rule:  {
      addL_eReg_immNode *node = new (C) addL_eReg_immNode();
      return node;
    }
  case addL_eReg_mem_rule:  {
      addL_eReg_memNode *node = new (C) addL_eReg_memNode();
      return node;
    }
  case addL_eReg_mem_0_rule:  {
      addL_eReg_mem_0Node *node = new (C) addL_eReg_mem_0Node();
      return node;
    }
  case subL_eReg_rule:  {
      subL_eRegNode *node = new (C) subL_eRegNode();
      return node;
    }
  case subL_eReg_imm_rule:  {
      subL_eReg_immNode *node = new (C) subL_eReg_immNode();
      return node;
    }
  case subL_eReg_mem_rule:  {
      subL_eReg_memNode *node = new (C) subL_eReg_memNode();
      return node;
    }
  case negL_eReg_rule:  {
      negL_eRegNode *node = new (C) negL_eRegNode();
      return node;
    }
  case andL_eReg_rule:  {
      andL_eRegNode *node = new (C) andL_eRegNode();
      return node;
    }
  case andL_eReg_imm_rule:  {
      andL_eReg_immNode *node = new (C) andL_eReg_immNode();
      return node;
    }
  case andL_eReg_mem_rule:  {
      andL_eReg_memNode *node = new (C) andL_eReg_memNode();
      return node;
    }
  case andL_eReg_mem_0_rule:  {
      andL_eReg_mem_0Node *node = new (C) andL_eReg_mem_0Node();
      return node;
    }
  case orl_eReg_rule:  {
      orl_eRegNode *node = new (C) orl_eRegNode();
      return node;
    }
  case orl_eReg_imm_rule:  {
      orl_eReg_immNode *node = new (C) orl_eReg_immNode();
      return node;
    }
  case orl_eReg_mem_rule:  {
      orl_eReg_memNode *node = new (C) orl_eReg_memNode();
      return node;
    }
  case orl_eReg_mem_0_rule:  {
      orl_eReg_mem_0Node *node = new (C) orl_eReg_mem_0Node();
      return node;
    }
  case xorl_eReg_rule:  {
      xorl_eRegNode *node = new (C) xorl_eRegNode();
      return node;
    }
  case xorl_eReg_im1_rule:  {
      xorl_eReg_im1Node *node = new (C) xorl_eReg_im1Node();
      return node;
    }
  case xorl_eReg_imm_rule:  {
      xorl_eReg_immNode *node = new (C) xorl_eReg_immNode();
      return node;
    }
  case xorl_eReg_mem_rule:  {
      xorl_eReg_memNode *node = new (C) xorl_eReg_memNode();
      return node;
    }
  case xorl_eReg_mem_0_rule:  {
      xorl_eReg_mem_0Node *node = new (C) xorl_eReg_mem_0Node();
      return node;
    }
  case shlL_eReg_1_rule:  {
      shlL_eReg_1Node *node = new (C) shlL_eReg_1Node();
      return node;
    }
  case shlL_eReg_2_rule:  {
      shlL_eReg_2Node *node = new (C) shlL_eReg_2Node();
      return node;
    }
  case shlL_eReg_3_rule:  {
      shlL_eReg_3Node *node = new (C) shlL_eReg_3Node();
      return node;
    }
  case shlL_eReg_1_31_rule:  {
      shlL_eReg_1_31Node *node = new (C) shlL_eReg_1_31Node();
      return node;
    }
  case shlL_eReg_32_63_rule:  {
      shlL_eReg_32_63Node *node = new (C) shlL_eReg_32_63Node();
      return node;
    }
  case salL_eReg_CL_rule:  {
      salL_eReg_CLNode *node = new (C) salL_eReg_CLNode();
      return node;
    }
  case shrL_eReg_1_31_rule:  {
      shrL_eReg_1_31Node *node = new (C) shrL_eReg_1_31Node();
      return node;
    }
  case shrL_eReg_32_63_rule:  {
      shrL_eReg_32_63Node *node = new (C) shrL_eReg_32_63Node();
      return node;
    }
  case shrL_eReg_CL_rule:  {
      shrL_eReg_CLNode *node = new (C) shrL_eReg_CLNode();
      return node;
    }
  case sarL_eReg_1_31_rule:  {
      sarL_eReg_1_31Node *node = new (C) sarL_eReg_1_31Node();
      return node;
    }
  case sarL_eReg_32_63_rule:  {
      sarL_eReg_32_63Node *node = new (C) sarL_eReg_32_63Node();
      return node;
    }
  case sarL_eReg_CL_rule:  {
      sarL_eReg_CLNode *node = new (C) sarL_eReg_CLNode();
      return node;
    }
  case cmpD_cc_P6_rule:  {
      cmpD_cc_P6Node *node = new (C) cmpD_cc_P6Node();
      return node;
    }
  case cmpD_cc_P6CF_rule:  {
      cmpD_cc_P6CFNode *node = new (C) cmpD_cc_P6CFNode();
      return node;
    }
  case cmpD_cc_rule:  {
      cmpD_ccNode *node = new (C) cmpD_ccNode();
      return node;
    }
  case cmpD_0_rule:  {
      cmpD_0Node *node = new (C) cmpD_0Node();
      return node;
    }
  case cmpD_reg_rule:  {
      cmpD_regNode *node = new (C) cmpD_regNode();
      return node;
    }
  case cmpXD_cc_rule:  {
      cmpXD_ccNode *node = new (C) cmpXD_ccNode();
      return node;
    }
  case cmpXD_ccCF_rule:  {
      cmpXD_ccCFNode *node = new (C) cmpXD_ccCFNode();
      return node;
    }
  case cmpXD_ccmem_rule:  {
      cmpXD_ccmemNode *node = new (C) cmpXD_ccmemNode();
      return node;
    }
  case cmpXD_ccmemCF_rule:  {
      cmpXD_ccmemCFNode *node = new (C) cmpXD_ccmemCFNode();
      return node;
    }
  case cmpXD_reg_rule:  {
      cmpXD_regNode *node = new (C) cmpXD_regNode();
      return node;
    }
  case cmpXD_regmem_rule:  {
      cmpXD_regmemNode *node = new (C) cmpXD_regmemNode();
      return node;
    }
  case subD_reg_rule:  {
      subD_regNode *node = new (C) subD_regNode();
      return node;
    }
  case subD_reg_round_rule:  {
      subD_reg_roundNode *node = new (C) subD_reg_roundNode();
      return node;
    }
  case subD_reg_mem_rule:  {
      subD_reg_memNode *node = new (C) subD_reg_memNode();
      return node;
    }
  case absD_reg_rule:  {
      absD_regNode *node = new (C) absD_regNode();
      return node;
    }
  case absXD_reg_rule:  {
      absXD_regNode *node = new (C) absXD_regNode();
      return node;
    }
  case negD_reg_rule:  {
      negD_regNode *node = new (C) negD_regNode();
      return node;
    }
  case negXD_reg_rule:  {
      negXD_regNode *node = new (C) negXD_regNode();
      return node;
    }
  case addD_reg_rule:  {
      addD_regNode *node = new (C) addD_regNode();
      return node;
    }
  case addD_reg_round_rule:  {
      addD_reg_roundNode *node = new (C) addD_reg_roundNode();
      return node;
    }
  case addD_reg_mem_rule:  {
      addD_reg_memNode *node = new (C) addD_reg_memNode();
      return node;
    }
  case addD_reg_mem_0_rule:  {
      addD_reg_mem_0Node *node = new (C) addD_reg_mem_0Node();
      return node;
    }
  case addD_mem_reg_rule:  {
      addD_mem_regNode *node = new (C) addD_mem_regNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addD_mem_reg_0_rule:  {
      addD_mem_reg_0Node *node = new (C) addD_mem_reg_0Node();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case addD_reg_imm1_rule:  {
      addD_reg_imm1Node *node = new (C) addD_reg_imm1Node();
      return node;
    }
  case addD_reg_imm_rule:  {
      addD_reg_immNode *node = new (C) addD_reg_immNode();
      return node;
    }
  case addD_reg_imm_round_rule:  {
      addD_reg_imm_roundNode *node = new (C) addD_reg_imm_roundNode();
      return node;
    }
  case addXD_reg_rule:  {
      addXD_regNode *node = new (C) addXD_regNode();
      return node;
    }
  case addXD_imm_rule:  {
      addXD_immNode *node = new (C) addXD_immNode();
      return node;
    }
  case addXD_mem_rule:  {
      addXD_memNode *node = new (C) addXD_memNode();
      return node;
    }
  case addXD_mem_0_rule:  {
      addXD_mem_0Node *node = new (C) addXD_mem_0Node();
      return node;
    }
  case subXD_reg_rule:  {
      subXD_regNode *node = new (C) subXD_regNode();
      return node;
    }
  case subXD_imm_rule:  {
      subXD_immNode *node = new (C) subXD_immNode();
      return node;
    }
  case subXD_mem_rule:  {
      subXD_memNode *node = new (C) subXD_memNode();
      return node;
    }
  case mulXD_reg_rule:  {
      mulXD_regNode *node = new (C) mulXD_regNode();
      return node;
    }
  case mulXD_imm_rule:  {
      mulXD_immNode *node = new (C) mulXD_immNode();
      return node;
    }
  case mulXD_mem_rule:  {
      mulXD_memNode *node = new (C) mulXD_memNode();
      return node;
    }
  case mulXD_mem_0_rule:  {
      mulXD_mem_0Node *node = new (C) mulXD_mem_0Node();
      return node;
    }
  case divXD_reg_rule:  {
      divXD_regNode *node = new (C) divXD_regNode();
      return node;
    }
  case divXD_imm_rule:  {
      divXD_immNode *node = new (C) divXD_immNode();
      return node;
    }
  case divXD_mem_rule:  {
      divXD_memNode *node = new (C) divXD_memNode();
      return node;
    }
  case mulD_reg_rule:  {
      mulD_regNode *node = new (C) mulD_regNode();
      return node;
    }
  case strictfp_mulD_reg_rule:  {
      strictfp_mulD_regNode *node = new (C) strictfp_mulD_regNode();
      return node;
    }
  case mulD_reg_imm_rule:  {
      mulD_reg_immNode *node = new (C) mulD_reg_immNode();
      return node;
    }
  case mulD_reg_mem_rule:  {
      mulD_reg_memNode *node = new (C) mulD_reg_memNode();
      return node;
    }
  case mulD_reg_mem_0_rule:  {
      mulD_reg_mem_0Node *node = new (C) mulD_reg_mem_0Node();
      return node;
    }
  case mulD_reg_mem_cisc_rule:  {
      mulD_reg_mem_ciscNode *node = new (C) mulD_reg_mem_ciscNode();
      return node;
    }
  case mulD_reg_mem_cisc_0_rule:  {
      mulD_reg_mem_cisc_0Node *node = new (C) mulD_reg_mem_cisc_0Node();
      return node;
    }
  case addD_mulD_reg_rule:  {
      addD_mulD_regNode *node = new (C) addD_mulD_regNode();
      return node;
    }
  case addD_mulD_reg_0_rule:  {
      addD_mulD_reg_0Node *node = new (C) addD_mulD_reg_0Node();
      return node;
    }
  case subD_mulD_reg_rule:  {
      subD_mulD_regNode *node = new (C) subD_mulD_regNode();
      return node;
    }
  case divD_reg_rule:  {
      divD_regNode *node = new (C) divD_regNode();
      return node;
    }
  case strictfp_divD_reg_rule:  {
      strictfp_divD_regNode *node = new (C) strictfp_divD_regNode();
      return node;
    }
  case divD_reg_round_rule:  {
      divD_reg_roundNode *node = new (C) divD_reg_roundNode();
      return node;
    }
  case modD_reg_rule:  {
      modD_regNode *node = new (C) modD_regNode();
      return node;
    }
  case modXD_reg_rule:  {
      modXD_regNode *node = new (C) modXD_regNode();
      return node;
    }
  case sinD_reg_rule:  {
      sinD_regNode *node = new (C) sinD_regNode();
      return node;
    }
  case sinXD_reg_rule:  {
      sinXD_regNode *node = new (C) sinXD_regNode();
      return node;
    }
  case cosD_reg_rule:  {
      cosD_regNode *node = new (C) cosD_regNode();
      return node;
    }
  case cosXD_reg_rule:  {
      cosXD_regNode *node = new (C) cosXD_regNode();
      return node;
    }
  case tanD_reg_rule:  {
      tanD_regNode *node = new (C) tanD_regNode();
      return node;
    }
  case tanXD_reg_rule:  {
      tanXD_regNode *node = new (C) tanXD_regNode();
      return node;
    }
  case atanD_reg_rule:  {
      atanD_regNode *node = new (C) atanD_regNode();
      return node;
    }
  case atanXD_reg_rule:  {
      atanXD_regNode *node = new (C) atanXD_regNode();
      return node;
    }
  case sqrtD_reg_rule:  {
      sqrtD_regNode *node = new (C) sqrtD_regNode();
      return node;
    }
  case powD_reg_rule:  {
      powD_regNode *node = new (C) powD_regNode();
      return node;
    }
  case powXD_reg_rule:  {
      powXD_regNode *node = new (C) powXD_regNode();
      return node;
    }
  case expD_reg_rule:  {
      expD_regNode *node = new (C) expD_regNode();
      return node;
    }
  case expXD_reg_rule:  {
      expXD_regNode *node = new (C) expXD_regNode();
      return node;
    }
  case log10D_reg_rule:  {
      log10D_regNode *node = new (C) log10D_regNode();
      return node;
    }
  case log10XD_reg_rule:  {
      log10XD_regNode *node = new (C) log10XD_regNode();
      return node;
    }
  case logD_reg_rule:  {
      logD_regNode *node = new (C) logD_regNode();
      return node;
    }
  case logXD_reg_rule:  {
      logXD_regNode *node = new (C) logXD_regNode();
      return node;
    }
  case cmpF_cc_P6_rule:  {
      cmpF_cc_P6Node *node = new (C) cmpF_cc_P6Node();
      return node;
    }
  case cmpF_cc_P6CF_rule:  {
      cmpF_cc_P6CFNode *node = new (C) cmpF_cc_P6CFNode();
      return node;
    }
  case cmpF_cc_rule:  {
      cmpF_ccNode *node = new (C) cmpF_ccNode();
      return node;
    }
  case cmpF_0_rule:  {
      cmpF_0Node *node = new (C) cmpF_0Node();
      return node;
    }
  case cmpF_reg_rule:  {
      cmpF_regNode *node = new (C) cmpF_regNode();
      return node;
    }
  case cmpX_cc_rule:  {
      cmpX_ccNode *node = new (C) cmpX_ccNode();
      return node;
    }
  case cmpX_ccCF_rule:  {
      cmpX_ccCFNode *node = new (C) cmpX_ccCFNode();
      return node;
    }
  case cmpX_ccmem_rule:  {
      cmpX_ccmemNode *node = new (C) cmpX_ccmemNode();
      return node;
    }
  case cmpX_ccmemCF_rule:  {
      cmpX_ccmemCFNode *node = new (C) cmpX_ccmemCFNode();
      return node;
    }
  case cmpX_reg_rule:  {
      cmpX_regNode *node = new (C) cmpX_regNode();
      return node;
    }
  case cmpX_regmem_rule:  {
      cmpX_regmemNode *node = new (C) cmpX_regmemNode();
      return node;
    }
  case subF24_reg_rule:  {
      subF24_regNode *node = new (C) subF24_regNode();
      return node;
    }
  case subF_reg_rule:  {
      subF_regNode *node = new (C) subF_regNode();
      return node;
    }
  case addF24_reg_rule:  {
      addF24_regNode *node = new (C) addF24_regNode();
      return node;
    }
  case addF_reg_rule:  {
      addF_regNode *node = new (C) addF_regNode();
      return node;
    }
  case addX_reg_rule:  {
      addX_regNode *node = new (C) addX_regNode();
      return node;
    }
  case addX_imm_rule:  {
      addX_immNode *node = new (C) addX_immNode();
      return node;
    }
  case addX_mem_rule:  {
      addX_memNode *node = new (C) addX_memNode();
      return node;
    }
  case addX_mem_0_rule:  {
      addX_mem_0Node *node = new (C) addX_mem_0Node();
      return node;
    }
  case subX_reg_rule:  {
      subX_regNode *node = new (C) subX_regNode();
      return node;
    }
  case subX_imm_rule:  {
      subX_immNode *node = new (C) subX_immNode();
      return node;
    }
  case subX_mem_rule:  {
      subX_memNode *node = new (C) subX_memNode();
      return node;
    }
  case mulX_reg_rule:  {
      mulX_regNode *node = new (C) mulX_regNode();
      return node;
    }
  case mulX_imm_rule:  {
      mulX_immNode *node = new (C) mulX_immNode();
      return node;
    }
  case mulX_mem_rule:  {
      mulX_memNode *node = new (C) mulX_memNode();
      return node;
    }
  case mulX_mem_0_rule:  {
      mulX_mem_0Node *node = new (C) mulX_mem_0Node();
      return node;
    }
  case divX_reg_rule:  {
      divX_regNode *node = new (C) divX_regNode();
      return node;
    }
  case divX_imm_rule:  {
      divX_immNode *node = new (C) divX_immNode();
      return node;
    }
  case divX_mem_rule:  {
      divX_memNode *node = new (C) divX_memNode();
      return node;
    }
  case sqrtX_reg_rule:  {
      sqrtX_regNode *node = new (C) sqrtX_regNode();
      return node;
    }
  case sqrtX_mem_rule:  {
      sqrtX_memNode *node = new (C) sqrtX_memNode();
      return node;
    }
  case sqrtXD_reg_rule:  {
      sqrtXD_regNode *node = new (C) sqrtXD_regNode();
      return node;
    }
  case sqrtXD_mem_rule:  {
      sqrtXD_memNode *node = new (C) sqrtXD_memNode();
      return node;
    }
  case absF_reg_rule:  {
      absF_regNode *node = new (C) absF_regNode();
      return node;
    }
  case absX_reg_rule:  {
      absX_regNode *node = new (C) absX_regNode();
      return node;
    }
  case negF_reg_rule:  {
      negF_regNode *node = new (C) negF_regNode();
      return node;
    }
  case negX_reg_rule:  {
      negX_regNode *node = new (C) negX_regNode();
      return node;
    }
  case addF24_reg_mem_rule:  {
      addF24_reg_memNode *node = new (C) addF24_reg_memNode();
      return node;
    }
  case addF24_reg_mem_0_rule:  {
      addF24_reg_mem_0Node *node = new (C) addF24_reg_mem_0Node();
      return node;
    }
  case addF_reg_mem_rule:  {
      addF_reg_memNode *node = new (C) addF_reg_memNode();
      return node;
    }
  case addF_reg_mem_0_rule:  {
      addF_reg_mem_0Node *node = new (C) addF_reg_mem_0Node();
      return node;
    }
  case addF24_mem_reg_rule:  {
      addF24_mem_regNode *node = new (C) addF24_mem_regNode();
      return node;
    }
  case addF24_mem_cisc_rule:  {
      addF24_mem_ciscNode *node = new (C) addF24_mem_ciscNode();
      return node;
    }
  case addF24_mem_cisc_0_rule:  {
      addF24_mem_cisc_0Node *node = new (C) addF24_mem_cisc_0Node();
      return node;
    }
  case addF24_mem_mem_rule:  {
      addF24_mem_memNode *node = new (C) addF24_mem_memNode();
      return node;
    }
  case addF24_reg_imm_rule:  {
      addF24_reg_immNode *node = new (C) addF24_reg_immNode();
      return node;
    }
  case addF_reg_imm_rule:  {
      addF_reg_immNode *node = new (C) addF_reg_immNode();
      return node;
    }
  case mulF24_reg_rule:  {
      mulF24_regNode *node = new (C) mulF24_regNode();
      return node;
    }
  case mulF_reg_rule:  {
      mulF_regNode *node = new (C) mulF_regNode();
      return node;
    }
  case mulF24_reg_mem_rule:  {
      mulF24_reg_memNode *node = new (C) mulF24_reg_memNode();
      return node;
    }
  case mulF24_reg_mem_0_rule:  {
      mulF24_reg_mem_0Node *node = new (C) mulF24_reg_mem_0Node();
      return node;
    }
  case mulF_reg_mem_rule:  {
      mulF_reg_memNode *node = new (C) mulF_reg_memNode();
      return node;
    }
  case mulF_reg_mem_0_rule:  {
      mulF_reg_mem_0Node *node = new (C) mulF_reg_mem_0Node();
      return node;
    }
  case mulF24_mem_mem_rule:  {
      mulF24_mem_memNode *node = new (C) mulF24_mem_memNode();
      return node;
    }
  case mulF24_reg_imm_rule:  {
      mulF24_reg_immNode *node = new (C) mulF24_reg_immNode();
      return node;
    }
  case mulF_reg_imm_rule:  {
      mulF_reg_immNode *node = new (C) mulF_reg_immNode();
      return node;
    }
  case mulF_reg_load1_rule:  {
      mulF_reg_load1Node *node = new (C) mulF_reg_load1Node();
      return node;
    }
  case mulF_reg_load1_0_rule:  {
      mulF_reg_load1_0Node *node = new (C) mulF_reg_load1_0Node();
      return node;
    }
  case addF_mulF_reg_load1_rule:  {
      addF_mulF_reg_load1Node *node = new (C) addF_mulF_reg_load1Node();
      return node;
    }
  case addF_mulF_reg_load1_1_rule:  {
      addF_mulF_reg_load1_1Node *node = new (C) addF_mulF_reg_load1_1Node();
      return node;
    }
  case addF_mulF_reg_load1_0_rule:  {
      addF_mulF_reg_load1_0Node *node = new (C) addF_mulF_reg_load1_0Node();
      return node;
    }
  case addF_mulF_reg_load1_2_rule:  {
      addF_mulF_reg_load1_2Node *node = new (C) addF_mulF_reg_load1_2Node();
      return node;
    }
  case addF_mulF_reg_rule:  {
      addF_mulF_regNode *node = new (C) addF_mulF_regNode();
      return node;
    }
  case addF_mulF_reg_0_rule:  {
      addF_mulF_reg_0Node *node = new (C) addF_mulF_reg_0Node();
      return node;
    }
  case subF_divF_reg_rule:  {
      subF_divF_regNode *node = new (C) subF_divF_regNode();
      return node;
    }
  case divF24_reg_rule:  {
      divF24_regNode *node = new (C) divF24_regNode();
      return node;
    }
  case divF_reg_rule:  {
      divF_regNode *node = new (C) divF_regNode();
      return node;
    }
  case modF24_reg_rule:  {
      modF24_regNode *node = new (C) modF24_regNode();
      return node;
    }
  case modF_reg_rule:  {
      modF_regNode *node = new (C) modF_regNode();
      return node;
    }
  case modX_reg_rule:  {
      modX_regNode *node = new (C) modX_regNode();
      return node;
    }
  case roundFloat_mem_reg_rule:  {
      roundFloat_mem_regNode *node = new (C) roundFloat_mem_regNode();
      return node;
    }
  case roundDouble_mem_reg_rule:  {
      roundDouble_mem_regNode *node = new (C) roundDouble_mem_regNode();
      return node;
    }
  case convD2F_reg_rule:  {
      convD2F_regNode *node = new (C) convD2F_regNode();
      return node;
    }
  case convD2X_reg_rule:  {
      convD2X_regNode *node = new (C) convD2X_regNode();
      return node;
    }
  case convXD2X_reg_rule:  {
      convXD2X_regNode *node = new (C) convXD2X_regNode();
      return node;
    }
  case convF2D_reg_reg_rule:  {
      convF2D_reg_regNode *node = new (C) convF2D_reg_regNode();
      return node;
    }
  case convF2D_reg_rule:  {
      convF2D_regNode *node = new (C) convF2D_regNode();
      return node;
    }
  case convX2D_reg_rule:  {
      convX2D_regNode *node = new (C) convX2D_regNode();
      return node;
    }
  case convX2XD_reg_rule:  {
      convX2XD_regNode *node = new (C) convX2XD_regNode();
      return node;
    }
  case convD2I_reg_reg_rule:  {
      convD2I_reg_regNode *node = new (C) convD2I_reg_regNode();
      return node;
    }
  case convXD2I_reg_reg_rule:  {
      convXD2I_reg_regNode *node = new (C) convXD2I_reg_regNode();
      return node;
    }
  case convD2L_reg_reg_rule:  {
      convD2L_reg_regNode *node = new (C) convD2L_reg_regNode();
      return node;
    }
  case convXD2L_reg_reg_rule:  {
      convXD2L_reg_regNode *node = new (C) convXD2L_reg_regNode();
      return node;
    }
  case convF2I_reg_reg_rule:  {
      convF2I_reg_regNode *node = new (C) convF2I_reg_regNode();
      return node;
    }
  case convX2I_reg_rule:  {
      convX2I_regNode *node = new (C) convX2I_regNode();
      return node;
    }
  case convF2L_reg_reg_rule:  {
      convF2L_reg_regNode *node = new (C) convF2L_reg_regNode();
      return node;
    }
  case convX2L_reg_reg_rule:  {
      convX2L_reg_regNode *node = new (C) convX2L_reg_regNode();
      return node;
    }
  case convI2D_reg_rule:  {
      convI2D_regNode *node = new (C) convI2D_regNode();
      return node;
    }
  case convI2XD_reg_rule:  {
      convI2XD_regNode *node = new (C) convI2XD_regNode();
      return node;
    }
  case convI2XD_mem_rule:  {
      convI2XD_memNode *node = new (C) convI2XD_memNode();
      return node;
    }
  case convXI2XD_reg_rule:  {
      convXI2XD_regNode *node = new (C) convXI2XD_regNode();
      return node;
    }
  case convI2D_mem_rule:  {
      convI2D_memNode *node = new (C) convI2D_memNode();
      return node;
    }
  case conv24I2F_reg_rule:  {
      conv24I2F_regNode *node = new (C) conv24I2F_regNode();
      return node;
    }
  case convI2F_SSF_rule:  {
      convI2F_SSFNode *node = new (C) convI2F_SSFNode();
      return node;
    }
  case convI2F_SSF_mem_rule:  {
      convI2F_SSF_memNode *node = new (C) convI2F_SSF_memNode();
      return node;
    }
  case convI2F_reg_rule:  {
      convI2F_regNode *node = new (C) convI2F_regNode();
      return node;
    }
  case convI2F_mem_rule:  {
      convI2F_memNode *node = new (C) convI2F_memNode();
      return node;
    }
  case convI2X_reg_rule:  {
      convI2X_regNode *node = new (C) convI2X_regNode();
      return node;
    }
  case convXI2X_reg_rule:  {
      convXI2X_regNode *node = new (C) convXI2X_regNode();
      return node;
    }
  case convI2L_reg_rule:  {
      convI2L_regNode *node = new (C) convI2L_regNode();
      return node;
    }
  case convI2L_reg_zex_rule:  {
      convI2L_reg_zexNode *node = new (C) convI2L_reg_zexNode();
      return node;
    }
  case zerox_long_rule:  {
      zerox_longNode *node = new (C) zerox_longNode();
      return node;
    }
  case convL2D_reg_rule:  {
      convL2D_regNode *node = new (C) convL2D_regNode();
      return node;
    }
  case convL2XD_reg_rule:  {
      convL2XD_regNode *node = new (C) convL2XD_regNode();
      return node;
    }
  case convL2X_reg_rule:  {
      convL2X_regNode *node = new (C) convL2X_regNode();
      return node;
    }
  case convL2F_reg_rule:  {
      convL2F_regNode *node = new (C) convL2F_regNode();
      return node;
    }
  case convL2I_reg_rule:  {
      convL2I_regNode *node = new (C) convL2I_regNode();
      return node;
    }
  case MoveF2I_stack_reg_rule:  {
      MoveF2I_stack_regNode *node = new (C) MoveF2I_stack_regNode();
      return node;
    }
  case MoveF2I_reg_stack_rule:  {
      MoveF2I_reg_stackNode *node = new (C) MoveF2I_reg_stackNode();
      return node;
    }
  case MoveF2I_reg_stack_sse_rule:  {
      MoveF2I_reg_stack_sseNode *node = new (C) MoveF2I_reg_stack_sseNode();
      return node;
    }
  case MoveF2I_reg_reg_sse_rule:  {
      MoveF2I_reg_reg_sseNode *node = new (C) MoveF2I_reg_reg_sseNode();
      return node;
    }
  case MoveI2F_reg_stack_rule:  {
      MoveI2F_reg_stackNode *node = new (C) MoveI2F_reg_stackNode();
      return node;
    }
  case MoveI2F_stack_reg_rule:  {
      MoveI2F_stack_regNode *node = new (C) MoveI2F_stack_regNode();
      return node;
    }
  case MoveI2F_stack_reg_sse_rule:  {
      MoveI2F_stack_reg_sseNode *node = new (C) MoveI2F_stack_reg_sseNode();
      return node;
    }
  case MoveI2F_reg_reg_sse_rule:  {
      MoveI2F_reg_reg_sseNode *node = new (C) MoveI2F_reg_reg_sseNode();
      return node;
    }
  case MoveD2L_stack_reg_rule:  {
      MoveD2L_stack_regNode *node = new (C) MoveD2L_stack_regNode();
      return node;
    }
  case MoveD2L_reg_stack_rule:  {
      MoveD2L_reg_stackNode *node = new (C) MoveD2L_reg_stackNode();
      return node;
    }
  case MoveD2L_reg_stack_sse_rule:  {
      MoveD2L_reg_stack_sseNode *node = new (C) MoveD2L_reg_stack_sseNode();
      return node;
    }
  case MoveD2L_reg_reg_sse_rule:  {
      MoveD2L_reg_reg_sseNode *node = new (C) MoveD2L_reg_reg_sseNode();
      node->set_opnd_array(2, MachOperGenerator(REGXD, C));
      return node;
    }
  case MoveL2D_reg_stack_rule:  {
      MoveL2D_reg_stackNode *node = new (C) MoveL2D_reg_stackNode();
      return node;
    }
  case MoveL2D_stack_reg_rule:  {
      MoveL2D_stack_regNode *node = new (C) MoveL2D_stack_regNode();
      return node;
    }
  case MoveL2D_stack_reg_sse_rule:  {
      MoveL2D_stack_reg_sseNode *node = new (C) MoveL2D_stack_reg_sseNode();
      return node;
    }
  case MoveL2D_stack_reg_sse_partial_rule:  {
      MoveL2D_stack_reg_sse_partialNode *node = new (C) MoveL2D_stack_reg_sse_partialNode();
      return node;
    }
  case MoveL2D_reg_reg_sse_rule:  {
      MoveL2D_reg_reg_sseNode *node = new (C) MoveL2D_reg_reg_sseNode();
      node->set_opnd_array(2, MachOperGenerator(REGXD, C));
      node->set_opnd_array(3, MachOperGenerator(REGXD, C));
      return node;
    }
  case Repl8B_reg_rule:  {
      Repl8B_regNode *node = new (C) Repl8B_regNode();
      return node;
    }
  case Repl8B_eRegI_rule:  {
      Repl8B_eRegINode *node = new (C) Repl8B_eRegINode();
      return node;
    }
  case Repl8B_immI0_rule:  {
      Repl8B_immI0Node *node = new (C) Repl8B_immI0Node();
      return node;
    }
  case Repl4S_reg_rule:  {
      Repl4S_regNode *node = new (C) Repl4S_regNode();
      return node;
    }
  case Repl4S_eRegI_rule:  {
      Repl4S_eRegINode *node = new (C) Repl4S_eRegINode();
      return node;
    }
  case Repl4S_immI0_rule:  {
      Repl4S_immI0Node *node = new (C) Repl4S_immI0Node();
      return node;
    }
  case Repl4C_reg_rule:  {
      Repl4C_regNode *node = new (C) Repl4C_regNode();
      return node;
    }
  case Repl4C_eRegI_rule:  {
      Repl4C_eRegINode *node = new (C) Repl4C_eRegINode();
      return node;
    }
  case Repl4C_immI0_rule:  {
      Repl4C_immI0Node *node = new (C) Repl4C_immI0Node();
      return node;
    }
  case Repl2I_reg_rule:  {
      Repl2I_regNode *node = new (C) Repl2I_regNode();
      return node;
    }
  case Repl2I_eRegI_rule:  {
      Repl2I_eRegINode *node = new (C) Repl2I_eRegINode();
      return node;
    }
  case Repl2I_immI0_rule:  {
      Repl2I_immI0Node *node = new (C) Repl2I_immI0Node();
      return node;
    }
  case Repl2F_reg_rule:  {
      Repl2F_regNode *node = new (C) Repl2F_regNode();
      return node;
    }
  case Repl2F_regX_rule:  {
      Repl2F_regXNode *node = new (C) Repl2F_regXNode();
      return node;
    }
  case Repl2F_immXF0_rule:  {
      Repl2F_immXF0Node *node = new (C) Repl2F_immXF0Node();
      return node;
    }
  case rep_stos_rule:  {
      rep_stosNode *node = new (C) rep_stosNode();
      return node;
    }
  case string_compare_rule:  {
      string_compareNode *node = new (C) string_compareNode();
      node->set_opnd_array(5, MachOperGenerator(REGXD, C));
      node->set_opnd_array(6, MachOperGenerator(REGXD, C));
      return node;
    }
  case string_equals_rule:  {
      string_equalsNode *node = new (C) string_equalsNode();
      node->set_opnd_array(4, MachOperGenerator(REGXD, C));
      node->set_opnd_array(5, MachOperGenerator(REGXD, C));
      return node;
    }
  case string_indexof_rule:  {
      string_indexofNode *node = new (C) string_indexofNode();
      node->set_opnd_array(5, MachOperGenerator(REGXD, C));
      return node;
    }
  case array_equals_rule:  {
      array_equalsNode *node = new (C) array_equalsNode();
      node->set_opnd_array(3, MachOperGenerator(REGXD, C));
      node->set_opnd_array(4, MachOperGenerator(REGXD, C));
      return node;
    }
  case compI_eReg_rule:  {
      compI_eRegNode *node = new (C) compI_eRegNode();
      return node;
    }
  case compI_eReg_imm_rule:  {
      compI_eReg_immNode *node = new (C) compI_eReg_immNode();
      return node;
    }
  case compI_eReg_mem_rule:  {
      compI_eReg_memNode *node = new (C) compI_eReg_memNode();
      return node;
    }
  case testI_reg_rule:  {
      testI_regNode *node = new (C) testI_regNode();
      return node;
    }
  case testI_reg_imm_rule:  {
      testI_reg_immNode *node = new (C) testI_reg_immNode();
      return node;
    }
  case testI_reg_mem_rule:  {
      testI_reg_memNode *node = new (C) testI_reg_memNode();
      return node;
    }
  case compU_eReg_rule:  {
      compU_eRegNode *node = new (C) compU_eRegNode();
      return node;
    }
  case compU_eReg_imm_rule:  {
      compU_eReg_immNode *node = new (C) compU_eReg_immNode();
      return node;
    }
  case compU_eReg_mem_rule:  {
      compU_eReg_memNode *node = new (C) compU_eReg_memNode();
      return node;
    }
  case testU_reg_rule:  {
      testU_regNode *node = new (C) testU_regNode();
      return node;
    }
  case compP_eReg_rule:  {
      compP_eRegNode *node = new (C) compP_eRegNode();
      return node;
    }
  case compP_eReg_imm_rule:  {
      compP_eReg_immNode *node = new (C) compP_eReg_immNode();
      return node;
    }
  case compP_eReg_mem_rule:  {
      compP_eReg_memNode *node = new (C) compP_eReg_memNode();
      return node;
    }
  case compP_mem_eReg_rule:  {
      compP_mem_eRegNode *node = new (C) compP_mem_eRegNode();
      return node;
    }
  case testP_reg_rule:  {
      testP_regNode *node = new (C) testP_regNode();
      return node;
    }
  case testP_Reg_mem_rule:  {
      testP_Reg_memNode *node = new (C) testP_Reg_memNode();
      return node;
    }
  case minI_eReg_rule:  {
      minI_eRegNode *node = new (C) minI_eRegNode();
      return node;
    }
  case maxI_eReg_rule:  {
      maxI_eRegNode *node = new (C) maxI_eRegNode();
      return node;
    }
  case jumpXtnd_rule:  {
      jumpXtndNode *node = new (C) jumpXtndNode();
      return node;
    }
  case jmpDir_rule:  {
      jmpDirNode *node = new (C) jmpDirNode();
      node->set_opnd_array(1, MachOperGenerator(LABEL, C));
      return node;
    }
  case jmpCon_rule:  {
      jmpConNode *node = new (C) jmpConNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpLoopEnd_rule:  {
      jmpLoopEndNode *node = new (C) jmpLoopEndNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpLoopEndU_rule:  {
      jmpLoopEndUNode *node = new (C) jmpLoopEndUNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpLoopEndUCF_rule:  {
      jmpLoopEndUCFNode *node = new (C) jmpLoopEndUCFNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpConU_rule:  {
      jmpConUNode *node = new (C) jmpConUNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpConUCF_rule:  {
      jmpConUCFNode *node = new (C) jmpConUCFNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpConUCF2_rule:  {
      jmpConUCF2Node *node = new (C) jmpConUCF2Node();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case partialSubtypeCheck_rule:  {
      partialSubtypeCheckNode *node = new (C) partialSubtypeCheckNode();
      return node;
    }
  case partialSubtypeCheck_vs_Zero_rule:  {
      partialSubtypeCheck_vs_ZeroNode *node = new (C) partialSubtypeCheck_vs_ZeroNode();
      return node;
    }
  case jmpDir_short_rule:  {
      jmpDir_shortNode *node = new (C) jmpDir_shortNode();
      node->set_opnd_array(1, MachOperGenerator(LABEL, C));
      return node;
    }
  case jmpCon_short_rule:  {
      jmpCon_shortNode *node = new (C) jmpCon_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpLoopEnd_short_rule:  {
      jmpLoopEnd_shortNode *node = new (C) jmpLoopEnd_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpLoopEndU_short_rule:  {
      jmpLoopEndU_shortNode *node = new (C) jmpLoopEndU_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpLoopEndUCF_short_rule:  {
      jmpLoopEndUCF_shortNode *node = new (C) jmpLoopEndUCF_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpConU_short_rule:  {
      jmpConU_shortNode *node = new (C) jmpConU_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpConUCF_short_rule:  {
      jmpConUCF_shortNode *node = new (C) jmpConUCF_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case jmpConUCF2_short_rule:  {
      jmpConUCF2_shortNode *node = new (C) jmpConUCF2_shortNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case cmpL3_reg_reg_rule:  {
      cmpL3_reg_regNode *node = new (C) cmpL3_reg_regNode();
      return node;
    }
  case cmpL_zero_flags_LTGE_rule:  {
      cmpL_zero_flags_LTGENode *node = new (C) cmpL_zero_flags_LTGENode();
      return node;
    }
  case cmpL_reg_flags_LTGE_rule:  {
      cmpL_reg_flags_LTGENode *node = new (C) cmpL_reg_flags_LTGENode();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case cmpL_LTGE_rule:  {
      cmpL_LTGENode *node = new (C) cmpL_LTGENode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case cmovLL_reg_LTGE_rule:  {
      cmovLL_reg_LTGENode *node = new (C) cmovLL_reg_LTGENode();
      return node;
    }
  case cmovLL_mem_LTGE_rule:  {
      cmovLL_mem_LTGENode *node = new (C) cmovLL_mem_LTGENode();
      return node;
    }
  case cmovII_reg_LTGE_rule:  {
      cmovII_reg_LTGENode *node = new (C) cmovII_reg_LTGENode();
      return node;
    }
  case cmovII_mem_LTGE_rule:  {
      cmovII_mem_LTGENode *node = new (C) cmovII_mem_LTGENode();
      return node;
    }
  case cmovPP_reg_LTGE_rule:  {
      cmovPP_reg_LTGENode *node = new (C) cmovPP_reg_LTGENode();
      return node;
    }
  case cmovDD_reg_LTGE_rule:  {
      cmovDD_reg_LTGENode *node = new (C) cmovDD_reg_LTGENode();
      return node;
    }
  case cmovXDD_reg_LTGE_rule:  {
      cmovXDD_reg_LTGENode *node = new (C) cmovXDD_reg_LTGENode();
      return node;
    }
  case cmovFF_reg_LTGE_rule:  {
      cmovFF_reg_LTGENode *node = new (C) cmovFF_reg_LTGENode();
      return node;
    }
  case cmovXX_reg_LTGE_rule:  {
      cmovXX_reg_LTGENode *node = new (C) cmovXX_reg_LTGENode();
      return node;
    }
  case cmpL_zero_flags_EQNE_rule:  {
      cmpL_zero_flags_EQNENode *node = new (C) cmpL_zero_flags_EQNENode();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case cmpL_reg_flags_EQNE_rule:  {
      cmpL_reg_flags_EQNENode *node = new (C) cmpL_reg_flags_EQNENode();
      return node;
    }
  case cmpL_EQNE_rule:  {
      cmpL_EQNENode *node = new (C) cmpL_EQNENode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case cmovLL_reg_EQNE_rule:  {
      cmovLL_reg_EQNENode *node = new (C) cmovLL_reg_EQNENode();
      return node;
    }
  case cmovLL_mem_EQNE_rule:  {
      cmovLL_mem_EQNENode *node = new (C) cmovLL_mem_EQNENode();
      return node;
    }
  case cmovII_reg_EQNE_rule:  {
      cmovII_reg_EQNENode *node = new (C) cmovII_reg_EQNENode();
      return node;
    }
  case cmovII_mem_EQNE_rule:  {
      cmovII_mem_EQNENode *node = new (C) cmovII_mem_EQNENode();
      return node;
    }
  case cmovPP_reg_EQNE_rule:  {
      cmovPP_reg_EQNENode *node = new (C) cmovPP_reg_EQNENode();
      return node;
    }
  case cmovDD_reg_EQNE_rule:  {
      cmovDD_reg_EQNENode *node = new (C) cmovDD_reg_EQNENode();
      return node;
    }
  case cmovXDD_reg_EQNE_rule:  {
      cmovXDD_reg_EQNENode *node = new (C) cmovXDD_reg_EQNENode();
      return node;
    }
  case cmovFF_reg_EQNE_rule:  {
      cmovFF_reg_EQNENode *node = new (C) cmovFF_reg_EQNENode();
      return node;
    }
  case cmovXX_reg_EQNE_rule:  {
      cmovXX_reg_EQNENode *node = new (C) cmovXX_reg_EQNENode();
      return node;
    }
  case cmpL_zero_flags_LEGT_rule:  {
      cmpL_zero_flags_LEGTNode *node = new (C) cmpL_zero_flags_LEGTNode();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case cmpL_reg_flags_LEGT_rule:  {
      cmpL_reg_flags_LEGTNode *node = new (C) cmpL_reg_flags_LEGTNode();
      node->set_opnd_array(3, MachOperGenerator(EREGI, C));
      return node;
    }
  case cmpL_LEGT_rule:  {
      cmpL_LEGTNode *node = new (C) cmpL_LEGTNode();
      node->set_opnd_array(3, MachOperGenerator(LABEL, C));
      node->_prob = _leaf->as_If()->_prob;
      node->_fcnt = _leaf->as_If()->_fcnt;
      return node;
    }
  case cmovLL_reg_LEGT_rule:  {
      cmovLL_reg_LEGTNode *node = new (C) cmovLL_reg_LEGTNode();
      return node;
    }
  case cmovLL_mem_LEGT_rule:  {
      cmovLL_mem_LEGTNode *node = new (C) cmovLL_mem_LEGTNode();
      return node;
    }
  case cmovII_reg_LEGT_rule:  {
      cmovII_reg_LEGTNode *node = new (C) cmovII_reg_LEGTNode();
      return node;
    }
  case cmovII_mem_LEGT_rule:  {
      cmovII_mem_LEGTNode *node = new (C) cmovII_mem_LEGTNode();
      return node;
    }
  case cmovPP_reg_LEGT_rule:  {
      cmovPP_reg_LEGTNode *node = new (C) cmovPP_reg_LEGTNode();
      return node;
    }
  case cmovDD_reg_LEGT_rule:  {
      cmovDD_reg_LEGTNode *node = new (C) cmovDD_reg_LEGTNode();
      return node;
    }
  case cmovXDD_reg_LEGT_rule:  {
      cmovXDD_reg_LEGTNode *node = new (C) cmovXDD_reg_LEGTNode();
      return node;
    }
  case cmovFF_reg_LEGT_rule:  {
      cmovFF_reg_LEGTNode *node = new (C) cmovFF_reg_LEGTNode();
      return node;
    }
  case cmovXX_reg_LEGT_rule:  {
      cmovXX_reg_LEGTNode *node = new (C) cmovXX_reg_LEGTNode();
      return node;
    }
  case CallStaticJavaDirect_rule:  {
      CallStaticJavaDirectNode *node = new (C) CallStaticJavaDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD, C));
      return node;
    }
  case CallStaticJavaHandle_rule:  {
      CallStaticJavaHandleNode *node = new (C) CallStaticJavaHandleNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD, C));
      return node;
    }
  case CallDynamicJavaDirect_rule:  {
      CallDynamicJavaDirectNode *node = new (C) CallDynamicJavaDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD, C));
      return node;
    }
  case CallRuntimeDirect_rule:  {
      CallRuntimeDirectNode *node = new (C) CallRuntimeDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD, C));
      return node;
    }
  case CallLeafDirect_rule:  {
      CallLeafDirectNode *node = new (C) CallLeafDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD, C));
      return node;
    }
  case CallLeafNoFPDirect_rule:  {
      CallLeafNoFPDirectNode *node = new (C) CallLeafNoFPDirectNode();
      node->set_opnd_array(1, MachOperGenerator(METHOD, C));
      return node;
    }
  case Ret_rule:  {
      RetNode *node = new (C) RetNode();
      return node;
    }
  case TailCalljmpInd_rule:  {
      TailCalljmpIndNode *node = new (C) TailCalljmpIndNode();
      return node;
    }
  case tailjmpInd_rule:  {
      tailjmpIndNode *node = new (C) tailjmpIndNode();
      return node;
    }
  case CreateException_rule:  {
      CreateExceptionNode *node = new (C) CreateExceptionNode();
      node->_bottom_type = _leaf->bottom_type();
      return node;
    }
  case RethrowException_rule:  {
      RethrowExceptionNode *node = new (C) RethrowExceptionNode();
      return node;
    }
  case cmpFastLock_rule:  {
      cmpFastLockNode *node = new (C) cmpFastLockNode();
      node->set_opnd_array(3, MachOperGenerator(EAXREGI, C));
      node->set_opnd_array(4, MachOperGenerator(EREGP, C));
      node->_counters = _leaf->as_FastLock()->counters();
      return node;
    }
  case cmpFastUnlock_rule:  {
      cmpFastUnlockNode *node = new (C) cmpFastUnlockNode();
      node->set_opnd_array(3, MachOperGenerator(EREGP, C));
      return node;
    }
  case safePoint_poll_rule:  {
      safePoint_pollNode *node = new (C) safePoint_pollNode();
      node->set_opnd_array(1, MachOperGenerator(EFLAGSREG, C));
      return node;
    }
  case tlsLoadP_rule:  {
      tlsLoadPNode *node = new (C) tlsLoadPNode();
      return node;
    }
  case TLS_rule:  {
      TLSNode *node = new (C) TLSNode();
      return node;
    }
  case ShouldNotReachHere_rule:  {
      ShouldNotReachHereNode *node = new (C) ShouldNotReachHereNode();
      return node;
    }
  
  default:
    fprintf(stderr, "Default MachNode Generator invoked for: \n");
    fprintf(stderr, "   opcode = %d\n", opcode);
    break;
  };
  return NULL;
}
// Check consistency of C++ compilation with ADLC options:
// Check adlc -DLINUX=1
#ifndef LINUX
#  error "LINUX must be defined"
#endif // LINUX
// Check adlc -D_GNU_SOURCE=1
#ifndef _GNU_SOURCE
#  error "_GNU_SOURCE must be defined"
#endif // _GNU_SOURCE
// Check adlc -DIA32=1
#ifndef IA32
#  error "IA32 must be defined"
#endif // IA32
// Check adlc -U_LP64
#ifdef _LP64
#  error "_LP64 must not be defined"
#endif // _LP64
