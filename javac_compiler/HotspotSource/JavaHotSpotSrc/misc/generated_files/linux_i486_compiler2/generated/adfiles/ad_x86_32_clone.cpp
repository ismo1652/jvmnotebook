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
#include "incls/_ad_x86_32_clone.cpp.incl"

MachOper  *UniverseOper::clone(Compile* C) const {
  return  new (C) UniverseOper();
}
MachOper  *sRegIOper::clone(Compile* C) const {
  return  new (C) sRegIOper();
}
MachOper  *sRegPOper::clone(Compile* C) const {
  return  new (C) sRegPOper();
}
MachOper  *sRegFOper::clone(Compile* C) const {
  return  new (C) sRegFOper();
}
MachOper  *sRegDOper::clone(Compile* C) const {
  return  new (C) sRegDOper();
}
MachOper  *sRegLOper::clone(Compile* C) const {
  return  new (C) sRegLOper();
}
MachOper  *immIOper::clone(Compile* C) const {
  return  new (C) immIOper(_c0);
}
MachOper  *immI0Oper::clone(Compile* C) const {
  return  new (C) immI0Oper(_c0);
}
MachOper  *immI1Oper::clone(Compile* C) const {
  return  new (C) immI1Oper(_c0);
}
MachOper  *immI_M1Oper::clone(Compile* C) const {
  return  new (C) immI_M1Oper(_c0);
}
MachOper  *immI2Oper::clone(Compile* C) const {
  return  new (C) immI2Oper(_c0);
}
MachOper  *immI8Oper::clone(Compile* C) const {
  return  new (C) immI8Oper(_c0);
}
MachOper  *immI16Oper::clone(Compile* C) const {
  return  new (C) immI16Oper(_c0);
}
MachOper  *immI_32Oper::clone(Compile* C) const {
  return  new (C) immI_32Oper(_c0);
}
MachOper  *immI_1_31Oper::clone(Compile* C) const {
  return  new (C) immI_1_31Oper(_c0);
}
MachOper  *immI_32_63Oper::clone(Compile* C) const {
  return  new (C) immI_32_63Oper(_c0);
}
MachOper  *immI_1Oper::clone(Compile* C) const {
  return  new (C) immI_1Oper(_c0);
}
MachOper  *immI_2Oper::clone(Compile* C) const {
  return  new (C) immI_2Oper(_c0);
}
MachOper  *immI_3Oper::clone(Compile* C) const {
  return  new (C) immI_3Oper(_c0);
}
MachOper  *immPOper::clone(Compile* C) const {
  return  new (C) immPOper(_c0);
}
MachOper  *immP0Oper::clone(Compile* C) const {
  return  new (C) immP0Oper(_c0);
}
MachOper  *immLOper::clone(Compile* C) const {
  return  new (C) immLOper(_c0);
}
MachOper  *immL0Oper::clone(Compile* C) const {
  return  new (C) immL0Oper(_c0);
}
MachOper  *immL_M1Oper::clone(Compile* C) const {
  return  new (C) immL_M1Oper(_c0);
}
MachOper  *immL_127Oper::clone(Compile* C) const {
  return  new (C) immL_127Oper(_c0);
}
MachOper  *immL_32bitsOper::clone(Compile* C) const {
  return  new (C) immL_32bitsOper(_c0);
}
MachOper  *immL32Oper::clone(Compile* C) const {
  return  new (C) immL32Oper(_c0);
}
MachOper  *immD0Oper::clone(Compile* C) const {
  return  new (C) immD0Oper(_c0);
}
MachOper  *immD1Oper::clone(Compile* C) const {
  return  new (C) immD1Oper(_c0);
}
MachOper  *immDOper::clone(Compile* C) const {
  return  new (C) immDOper(_c0);
}
MachOper  *immXDOper::clone(Compile* C) const {
  return  new (C) immXDOper(_c0);
}
MachOper  *immXD0Oper::clone(Compile* C) const {
  return  new (C) immXD0Oper(_c0);
}
MachOper  *immF0Oper::clone(Compile* C) const {
  return  new (C) immF0Oper(_c0);
}
MachOper  *immFOper::clone(Compile* C) const {
  return  new (C) immFOper(_c0);
}
MachOper  *immXFOper::clone(Compile* C) const {
  return  new (C) immXFOper(_c0);
}
MachOper  *immXF0Oper::clone(Compile* C) const {
  return  new (C) immXF0Oper(_c0);
}
MachOper  *immI_16Oper::clone(Compile* C) const {
  return  new (C) immI_16Oper(_c0);
}
MachOper  *immI_24Oper::clone(Compile* C) const {
  return  new (C) immI_24Oper(_c0);
}
MachOper  *immI_255Oper::clone(Compile* C) const {
  return  new (C) immI_255Oper(_c0);
}
MachOper  *immI_65535Oper::clone(Compile* C) const {
  return  new (C) immI_65535Oper(_c0);
}
MachOper  *eRegIOper::clone(Compile* C) const {
  return  new (C) eRegIOper();
}
MachOper  *xRegIOper::clone(Compile* C) const {
  return  new (C) xRegIOper();
}
MachOper  *eAXRegIOper::clone(Compile* C) const {
  return  new (C) eAXRegIOper();
}
MachOper  *eBXRegIOper::clone(Compile* C) const {
  return  new (C) eBXRegIOper();
}
MachOper  *eCXRegIOper::clone(Compile* C) const {
  return  new (C) eCXRegIOper();
}
MachOper  *eDXRegIOper::clone(Compile* C) const {
  return  new (C) eDXRegIOper();
}
MachOper  *eDIRegIOper::clone(Compile* C) const {
  return  new (C) eDIRegIOper();
}
MachOper  *naxRegIOper::clone(Compile* C) const {
  return  new (C) naxRegIOper();
}
MachOper  *nadxRegIOper::clone(Compile* C) const {
  return  new (C) nadxRegIOper();
}
MachOper  *ncxRegIOper::clone(Compile* C) const {
  return  new (C) ncxRegIOper();
}
MachOper  *eSIRegIOper::clone(Compile* C) const {
  return  new (C) eSIRegIOper();
}
MachOper  *anyRegPOper::clone(Compile* C) const {
  return  new (C) anyRegPOper();
}
MachOper  *eRegPOper::clone(Compile* C) const {
  return  new (C) eRegPOper();
}
MachOper  *eRegP_no_EBPOper::clone(Compile* C) const {
  return  new (C) eRegP_no_EBPOper();
}
MachOper  *naxRegPOper::clone(Compile* C) const {
  return  new (C) naxRegPOper();
}
MachOper  *nabxRegPOper::clone(Compile* C) const {
  return  new (C) nabxRegPOper();
}
MachOper  *pRegPOper::clone(Compile* C) const {
  return  new (C) pRegPOper();
}
MachOper  *eAXRegPOper::clone(Compile* C) const {
  return  new (C) eAXRegPOper();
}
MachOper  *eBXRegPOper::clone(Compile* C) const {
  return  new (C) eBXRegPOper();
}
MachOper  *eCXRegPOper::clone(Compile* C) const {
  return  new (C) eCXRegPOper();
}
MachOper  *eSIRegPOper::clone(Compile* C) const {
  return  new (C) eSIRegPOper();
}
MachOper  *eDIRegPOper::clone(Compile* C) const {
  return  new (C) eDIRegPOper();
}
MachOper  *eBPRegPOper::clone(Compile* C) const {
  return  new (C) eBPRegPOper();
}
MachOper  *eRegLOper::clone(Compile* C) const {
  return  new (C) eRegLOper();
}
MachOper  *eADXRegLOper::clone(Compile* C) const {
  return  new (C) eADXRegLOper();
}
MachOper  *eBCXRegLOper::clone(Compile* C) const {
  return  new (C) eBCXRegLOper();
}
MachOper  *eADXRegL_low_onlyOper::clone(Compile* C) const {
  return  new (C) eADXRegL_low_onlyOper();
}
MachOper  *eFlagsRegOper::clone(Compile* C) const {
  return  new (C) eFlagsRegOper();
}
MachOper  *eFlagsRegUOper::clone(Compile* C) const {
  return  new (C) eFlagsRegUOper();
}
MachOper  *eFlagsRegUCFOper::clone(Compile* C) const {
  return  new (C) eFlagsRegUCFOper();
}
MachOper  *flagsReg_long_LTGEOper::clone(Compile* C) const {
  return  new (C) flagsReg_long_LTGEOper();
}
MachOper  *flagsReg_long_EQNEOper::clone(Compile* C) const {
  return  new (C) flagsReg_long_EQNEOper();
}
MachOper  *flagsReg_long_LEGTOper::clone(Compile* C) const {
  return  new (C) flagsReg_long_LEGTOper();
}
MachOper  *regDOper::clone(Compile* C) const {
  return  new (C) regDOper();
}
MachOper  *regDPR1Oper::clone(Compile* C) const {
  return  new (C) regDPR1Oper();
}
MachOper  *regDPR2Oper::clone(Compile* C) const {
  return  new (C) regDPR2Oper();
}
MachOper  *regnotDPR1Oper::clone(Compile* C) const {
  return  new (C) regnotDPR1Oper();
}
MachOper  *regXDOper::clone(Compile* C) const {
  return  new (C) regXDOper();
}
MachOper  *regXD6Oper::clone(Compile* C) const {
  return  new (C) regXD6Oper();
}
MachOper  *regXD7Oper::clone(Compile* C) const {
  return  new (C) regXD7Oper();
}
MachOper  *regFOper::clone(Compile* C) const {
  return  new (C) regFOper();
}
MachOper  *regFPR1Oper::clone(Compile* C) const {
  return  new (C) regFPR1Oper();
}
MachOper  *regXOper::clone(Compile* C) const {
  return  new (C) regXOper();
}
MachOper  *directOper::clone(Compile* C) const {
  return  new (C) directOper(_c0);
}
MachOper  *indirectOper::clone(Compile* C) const {
  return  new (C) indirectOper();
}
MachOper  *indOffset8Oper::clone(Compile* C) const {
  return  new (C) indOffset8Oper(_c0);
}
MachOper  *indOffset32Oper::clone(Compile* C) const {
  return  new (C) indOffset32Oper(_c0);
}
MachOper  *indOffset32XOper::clone(Compile* C) const {
  return  new (C) indOffset32XOper(_c0);
}
MachOper  *indIndexOffsetOper::clone(Compile* C) const {
  return  new (C) indIndexOffsetOper(_c0);
}
MachOper  *indIndexOper::clone(Compile* C) const {
  return  new (C) indIndexOper();
}
MachOper  *indIndexScaleOper::clone(Compile* C) const {
  return  new (C) indIndexScaleOper(_c0);
}
MachOper  *indIndexScaleOffsetOper::clone(Compile* C) const {
  return  new (C) indIndexScaleOffsetOper(_c0, _c1);
}
MachOper  *load_long_RegPOper::clone(Compile* C) const {
  return  new (C) load_long_RegPOper();
}
MachOper  *load_long_indirectOper::clone(Compile* C) const {
  return  new (C) load_long_indirectOper();
}
MachOper  *load_long_indOffset32Oper::clone(Compile* C) const {
  return  new (C) load_long_indOffset32Oper(_c0);
}
MachOper  *stackSlotPOper::clone(Compile* C) const {
  return  new (C) stackSlotPOper();
}
MachOper  *stackSlotIOper::clone(Compile* C) const {
  return  new (C) stackSlotIOper();
}
MachOper  *stackSlotFOper::clone(Compile* C) const {
  return  new (C) stackSlotFOper();
}
MachOper  *stackSlotDOper::clone(Compile* C) const {
  return  new (C) stackSlotDOper();
}
MachOper  *stackSlotLOper::clone(Compile* C) const {
  return  new (C) stackSlotLOper();
}
MachOper  *indirect_win95_safeOper::clone(Compile* C) const {
  return  new (C) indirect_win95_safeOper();
}
MachOper  *indOffset8_win95_safeOper::clone(Compile* C) const {
  return  new (C) indOffset8_win95_safeOper(_c0);
}
MachOper  *indOffset32_win95_safeOper::clone(Compile* C) const {
  return  new (C) indOffset32_win95_safeOper(_c0);
}
MachOper  *indIndexOffset_win95_safeOper::clone(Compile* C) const {
  return  new (C) indIndexOffset_win95_safeOper(_c0);
}
MachOper  *indIndexScale_win95_safeOper::clone(Compile* C) const {
  return  new (C) indIndexScale_win95_safeOper(_c0);
}
MachOper  *indIndexScaleOffset_win95_safeOper::clone(Compile* C) const {
  return  new (C) indIndexScaleOffset_win95_safeOper(_c0, _c1);
}
MachOper  *cmpOpOper::clone(Compile* C) const {
  return  new (C) cmpOpOper(_c0);
}
MachOper  *cmpOpUOper::clone(Compile* C) const {
  return  new (C) cmpOpUOper(_c0);
}
MachOper  *cmpOpUCFOper::clone(Compile* C) const {
  return  new (C) cmpOpUCFOper(_c0);
}
MachOper  *cmpOpUCF2Oper::clone(Compile* C) const {
  return  new (C) cmpOpUCF2Oper(_c0);
}
MachOper  *cmpOp_fcmovOper::clone(Compile* C) const {
  return  new (C) cmpOp_fcmovOper(_c0);
}
MachOper  *cmpOp_commuteOper::clone(Compile* C) const {
  return  new (C) cmpOp_commuteOper(_c0);
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
