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
#include "incls/_ad_x86_32_format.cpp.incl"


#ifndef PRODUCT
void UniverseOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("$$univ");
}
void UniverseOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("$$univ");
}
#endif

#ifndef PRODUCT
void sRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void sRegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
}
void sRegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
}
#endif

#ifndef PRODUCT
void immIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_M1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_M1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI8Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI8Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI16Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI16Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_32Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_32Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_1_31Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_1_31Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_32_63Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_32_63Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_3Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_3Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
_c0->dump_on(st);
}
void immPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
_c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immP0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
_c0->dump_on(st);
}
void immP0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
_c0->dump_on(st);
}
#endif

#ifndef PRODUCT
void immLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%lld", _c0);
}
void immLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%lld", _c0);
}
#endif

#ifndef PRODUCT
void immL0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%lld", _c0);
}
void immL0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%lld", _c0);
}
#endif

#ifndef PRODUCT
void immL_M1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%lld", _c0);
}
void immL_M1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%lld", _c0);
}
#endif

#ifndef PRODUCT
void immL_127Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%lld", _c0);
}
void immL_127Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%lld", _c0);
}
#endif

#ifndef PRODUCT
void immL_32bitsOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%lld", _c0);
}
void immL_32bitsOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%lld", _c0);
}
#endif

#ifndef PRODUCT
void immL32Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%lld", _c0);
}
void immL32Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%lld", _c0);
}
#endif

#ifndef PRODUCT
void immD0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immD0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immD1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immD1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immXDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immXDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immXD0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immXD0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immF0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immF0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immXFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immXFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immXF0Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%f", _c0);
}
void immXF0Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%f", _c0);
}
#endif

#ifndef PRODUCT
void immI_16Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_16Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_24Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_24Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_255Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_255Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void immI_65535Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
st->print("#%d", _c0);
}
void immI_65535Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
st->print("#%d", _c0);
}
#endif

#ifndef PRODUCT
void eRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void eRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void xRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void xRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void eAXRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EAX");
}
void eAXRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EAX");
}
#endif

#ifndef PRODUCT
void eBXRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EBX");
}
void eBXRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EBX");
}
#endif

#ifndef PRODUCT
void eCXRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("ECX");
}
void eCXRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("ECX");
}
#endif

#ifndef PRODUCT
void eDXRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EDX");
}
void eDXRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EDX");
}
#endif

#ifndef PRODUCT
void eDIRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EDI");
}
void eDIRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EDI");
}
#endif

#ifndef PRODUCT
void naxRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void naxRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void nadxRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void nadxRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void ncxRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void ncxRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void eSIRegIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("ESI");
}
void eSIRegIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("ESI");
}
#endif

#ifndef PRODUCT
void anyRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void anyRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void eRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void eRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void eRegP_no_EBPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void eRegP_no_EBPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void naxRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void naxRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void nabxRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void nabxRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void pRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void pRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void eAXRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EAX");
}
void eAXRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EAX");
}
#endif

#ifndef PRODUCT
void eBXRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EBX");
}
void eBXRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EBX");
}
#endif

#ifndef PRODUCT
void eCXRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("ECX");
}
void eCXRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("ECX");
}
#endif

#ifndef PRODUCT
void eSIRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("ESI");
}
void eSIRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("ESI");
}
#endif

#ifndef PRODUCT
void eDIRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EDI");
}
void eDIRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EDI");
}
#endif

#ifndef PRODUCT
void eBPRegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EBP");
}
void eBPRegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EBP");
}
#endif

#ifndef PRODUCT
void eRegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void eRegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void eADXRegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EDX:EAX");
}
void eADXRegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EDX:EAX");
}
#endif

#ifndef PRODUCT
void eBCXRegLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EBX:ECX");
}
void eBCXRegLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EBX:ECX");
}
#endif

#ifndef PRODUCT
void eADXRegL_low_onlyOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EAX");
}
void eADXRegL_low_onlyOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EAX");
}
#endif

#ifndef PRODUCT
void eFlagsRegOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EFLAGS");
}
void eFlagsRegOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EFLAGS");
}
#endif

#ifndef PRODUCT
void eFlagsRegUOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EFLAGS_U");
}
void eFlagsRegUOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EFLAGS_U");
}
#endif

#ifndef PRODUCT
void eFlagsRegUCFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("EFLAGS_U_CF");
}
void eFlagsRegUCFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("EFLAGS_U_CF");
}
#endif

#ifndef PRODUCT
void flagsReg_long_LTGEOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("FLAGS_LTGE");
}
void flagsReg_long_LTGEOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("FLAGS_LTGE");
}
#endif

#ifndef PRODUCT
void flagsReg_long_EQNEOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("FLAGS_EQNE");
}
void flagsReg_long_EQNEOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("FLAGS_EQNE");
}
#endif

#ifndef PRODUCT
void flagsReg_long_LEGTOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("FLAGS_LEGT");
}
void flagsReg_long_LEGTOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("FLAGS_LEGT");
}
#endif

#ifndef PRODUCT
void regDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void regDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void regDPR1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("FPR1");
}
void regDPR1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("FPR1");
}
#endif

#ifndef PRODUCT
void regDPR2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("FPR2");
}
void regDPR2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("FPR2");
}
#endif

#ifndef PRODUCT
void regnotDPR1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void regnotDPR1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void regXDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void regXDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void regXD6Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("XMM6");
}
void regXD6Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("XMM6");
}
#endif

#ifndef PRODUCT
void regXD7Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("XMM7");
}
void regXD7Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("XMM7");
}
#endif

#ifndef PRODUCT
void regFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void regFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void regFPR1Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("FPR1");
}
void regFPR1Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("FPR1");
}
#endif

#ifndef PRODUCT
void regXOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void regXOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void directOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  _c0->dump_on(st);
  st->print("]");
}
void directOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  _c0->dump_on(st);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indirectOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void indirectOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void indOffset8Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
void indOffset8Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indOffset32Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
void indOffset32Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indOffset32XOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  _c0->dump_on(st);
  st->print("]");
}
void indOffset32XOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  _c0->dump_on(st);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexOffsetOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void indIndexOffsetOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void indIndexOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexScaleOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
void indIndexScaleOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexScaleOffsetOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c1);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
void indIndexScaleOffsetOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c1);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void load_long_RegPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
}
void load_long_RegPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
{ char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
}
#endif

#ifndef PRODUCT
void load_long_indirectOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void load_long_indirectOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void load_long_indOffset32Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
void load_long_indOffset32Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void stackSlotPOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void stackSlotPOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void stackSlotIOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void stackSlotIOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void stackSlotFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void stackSlotFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void stackSlotDOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void stackSlotDOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void stackSlotLOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void stackSlotLOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void indirect_win95_safeOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void indirect_win95_safeOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void indOffset8_win95_safeOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
void indOffset8_win95_safeOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indOffset32_win95_safeOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
void indOffset32_win95_safeOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexOffset_win95_safeOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
void indIndexOffset_win95_safeOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c0);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexScale_win95_safeOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
void indIndexScale_win95_safeOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void indIndexScaleOffset_win95_safeOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c1);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node,reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
void indIndexScaleOffset_win95_safeOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("[");
  { char reg_str[128];
      ra->dump_register(node->in(idx),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" + ");
  st->print("#%d", _c1);
  st->print(" + ");
  { char reg_str[128];
      ra->dump_register(node->in(idx+1),reg_str);
      tty->print("%s",reg_str);
    }
  st->print(" << ");
  st->print("#%d", _c0);
  st->print("]");
}
#endif

#ifndef PRODUCT
void cmpOpOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("le");
    else if( _c0 == BoolTest::ge ) st->print("ge");
    else if( _c0 == BoolTest::lt ) st->print("l");
    else if( _c0 == BoolTest::gt ) st->print("g");
}
void cmpOpOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("le");
    else if( _c0 == BoolTest::ge ) st->print("ge");
    else if( _c0 == BoolTest::lt ) st->print("l");
    else if( _c0 == BoolTest::gt ) st->print("g");
}
#endif

#ifndef PRODUCT
void cmpOpUOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
}
void cmpOpUOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
}
#endif

#ifndef PRODUCT
void cmpOpUCFOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
}
void cmpOpUCFOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
}
#endif

#ifndef PRODUCT
void cmpOpUCF2Oper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
}
void cmpOpUCF2Oper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("be");
    else if( _c0 == BoolTest::ge ) st->print("nb");
    else if( _c0 == BoolTest::lt ) st->print("b");
    else if( _c0 == BoolTest::gt ) st->print("nbe");
}
#endif

#ifndef PRODUCT
void cmpOp_fcmovOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("eq");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("le");
    else if( _c0 == BoolTest::ge ) st->print("ge");
    else if( _c0 == BoolTest::lt ) st->print("lt");
    else if( _c0 == BoolTest::gt ) st->print("gt");
}
void cmpOp_fcmovOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("eq");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("le");
    else if( _c0 == BoolTest::ge ) st->print("ge");
    else if( _c0 == BoolTest::lt ) st->print("lt");
    else if( _c0 == BoolTest::gt ) st->print("gt");
}
#endif

#ifndef PRODUCT
void cmpOp_commuteOper::int_format(PhaseRegAlloc *ra, const MachNode *node, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("ge");
    else if( _c0 == BoolTest::ge ) st->print("le");
    else if( _c0 == BoolTest::lt ) st->print("g");
    else if( _c0 == BoolTest::gt ) st->print("l");
}
void cmpOp_commuteOper::ext_format(PhaseRegAlloc *ra, const MachNode *node, int idx, outputStream *st) const {
  st->print("");
         if( _c0 == BoolTest::eq ) st->print("e");
    else if( _c0 == BoolTest::ne ) st->print("ne");
    else if( _c0 == BoolTest::le ) st->print("ge");
    else if( _c0 == BoolTest::ge ) st->print("le");
    else if( _c0 == BoolTest::lt ) st->print("g");
    else if( _c0 == BoolTest::gt ) st->print("l");
}
#endif
#ifndef PRODUCT
void bytes_reverse_intNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("BSWAP  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void bytes_reverse_longNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("BSWAP  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("BSWAP  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n\t");
    st->print("XCHG   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void bytes_reverse_unsigned_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("BSWAP  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print("\n\t");
    st->print("SHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",16\n\t");
  }
#endif
#ifndef PRODUCT
void bytes_reverse_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("BSWAP  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print("\n\t");
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",16\n\t");
  }
#endif
#ifndef PRODUCT
void countLeadingZerosINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("LZCNT  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# count leading zeros (int)");
  }
#endif
#ifndef PRODUCT
void countLeadingZerosI_bsrNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("BSR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# count leading zeros (int)\n\t");
    st->print("JNZ    skip\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", -1\n");
    st->print("skip:\n\t");
    st->print("NEG    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("ADD    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", 31");
  }
#endif
#ifndef PRODUCT
void countLeadingZerosLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("LZCNT  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# count leading zeros (long)\n\t");
    st->print("JNC    done\n\t");
    st->print("LZCNT  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", 32\n");
    st->print("done:");
  }
#endif
#ifndef PRODUCT
void countLeadingZerosL_bsrNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("BSR    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# count leading zeros (long)\n\t");
    st->print("JZ     msw_is_zero\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", 32\n\t");
    st->print("JMP    not_zero\n");
    st->print("msw_is_zero:\n\t");
    st->print("BSR    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("JNZ    not_zero\n\t");
    st->print("MOV    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", -1\n");
    st->print("not_zero:\n\t");
    st->print("NEG    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print("\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", 63\n");
  }
#endif
#ifndef PRODUCT
void countTrailingZerosINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("BSF    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# count trailing zeros (int)\n\t");
    st->print("JNZ    done\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", 32\n");
    st->print("done:");
  }
#endif
#ifndef PRODUCT
void countTrailingZerosLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("BSF    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\t# count trailing zeros (long)\n\t");
    st->print("JNZ    done\n\t");
    st->print("BSF    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\n\t");
    st->print("JNZ    msw_not_zero\n\t");
    st->print("MOV    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", 32\n");
    st->print("msw_not_zero:\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", 32\n");
    st->print("done:");
  }
#endif
#ifndef PRODUCT
void popCountINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("POPCNT ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void popCountI_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("POPCNT ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void popCountLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("POPCNT ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("POPCNT ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void popCountL_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("POPCNT ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("POPCNT ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(", ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void loadBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVSX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# byte");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadB2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVSX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# byte -> long\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo\n\t");
    st->print("SAR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,7");
  }
#endif
#ifndef PRODUCT
void loadUBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVZX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ubyte -> int");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadUB2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVZX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ubyte -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadUB2L_immI8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ubyte & 8-bit mask -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi\n\t");
    st->print("AND    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mask
  }
#endif
#ifndef PRODUCT
void loadSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# short");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadS2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# short -> byte");
  }
#endif
#ifndef PRODUCT
void loadS2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# short -> long\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo\n\t");
    st->print("SAR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,15");
  }
#endif
#ifndef PRODUCT
void loadUSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVZX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ushort/char -> int");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadUS2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ushort -> byte");
  }
#endif
#ifndef PRODUCT
void loadUS2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVZX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ushort/char -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadUS2L_immI_255Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ushort/char & 0xFF -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadUS2L_immI16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo, ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# ushort/char & 16-bit mask -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi\n\t");
    st->print("AND    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mask
  }
#endif
#ifndef PRODUCT
void loadINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadI2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int -> byte");
  }
#endif
#ifndef PRODUCT
void loadI2UBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int -> ubyte");
  }
#endif
#ifndef PRODUCT
void loadI2SNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int -> short");
  }
#endif
#ifndef PRODUCT
void loadI2USNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int -> ushort/char");
  }
#endif
#ifndef PRODUCT
void loadI2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int -> long\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo\n\t");
    st->print("SAR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,31");
  }
#endif
#ifndef PRODUCT
void loadI2L_immI_255Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX8 ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int & 0xFF -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadI2L_immI_65535Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVZX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int & 0xFFFF -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadI2L_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# int & 32-bit mask -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi\n\t");
    st->print("AND    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mask
  }
#endif
#ifndef PRODUCT
void loadUI2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# uint -> long\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# long\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadL_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Atomic volatile long load\n\t");
    st->print("FISTp  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadLX_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSD  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Atomic volatile long load\n\t");
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadLX_reg_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSD  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Atomic volatile long load\n\t");
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print("\n\t");
    st->print("PSRLQ  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",32\n\t");
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadRangeNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadKlassNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FLD_D  ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadXDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadXD_partialNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVLPD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FLD_S  ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadA8BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVQ  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! packed8B");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadA4SNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVQ  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! packed4S");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadA4CNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVQ  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! packed4C");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void load2IUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVQ  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! packed2I");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadA2FNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOVQ  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! packed2F");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void leaP8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void leaP32Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void leaPIdxOffNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void leaPIdxScaleNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void leaPIdxScaleOffNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void loadConINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void loadConI0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void loadConPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void loadConLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadConL0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadConFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD_S  ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void loadConXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void loadConX0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("XORPS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# float 0.0");
  }
#endif
#ifndef PRODUCT
void loadConDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD_D  ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void loadConXDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void loadConXD0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("XORPD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# double 0.0");
  }
#endif
#ifndef PRODUCT
void loadSSINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void loadSSLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("+4,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void loadSSPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void loadSSFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD_S  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void loadSSDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void prefetchr0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("PREFETCHR (non-SSE is empty encoding)");
  }
#endif
#ifndef PRODUCT
void prefetchrNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHR ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into level 1 cache for read");
  }
#endif
#ifndef PRODUCT
void prefetchrNTANode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHNTA ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into non-temporal cache for read");
  }
#endif
#ifndef PRODUCT
void prefetchrT0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHT0 ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into L1 and L2 caches for read");
  }
#endif
#ifndef PRODUCT
void prefetchrT2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHT2 ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into L2 cache for read");
  }
#endif
#ifndef PRODUCT
void prefetchw0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("Prefetch (non-SSE is empty encoding)");
  }
#endif
#ifndef PRODUCT
void prefetchwNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHW ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into L1 cache and mark modified");
  }
#endif
#ifndef PRODUCT
void prefetchwNTANode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHNTA ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into non-temporal cache for write");
  }
#endif
#ifndef PRODUCT
void prefetchwT0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHT0 ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into L1 and L2 caches for write");
  }
#endif
#ifndef PRODUCT
void prefetchwT2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("PREFETCHT2 ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t! Prefetch into L2 cache for write");
  }
#endif
#ifndef PRODUCT
void storeBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV8   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeCNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV16  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeL2INode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\t# long -> int");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeL_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",EAX\t# Probe address for implicit null check\n\t");
    st->print("FILD   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FISTp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t # 64-bit atomic volatile long store");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeLX_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",EAX\t# Probe address for implicit null check\n\t");
    st->print("MOVSD  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("MOVSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print("\t # 64-bit atomic volatile long store");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeLX_reg_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",EAX\t# Probe address for implicit null check\n\t");
    st->print("MOVD   ");
    opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("MOVD   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp2
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi\n\t");
    st->print("PUNPCKLDQ ");
    opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp2
    st->print("\n\t");
    st->print("MOVSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // tmp
    st->print("\t # 64-bit atomic volatile long store");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storePNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeImmINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeImmI16Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV16  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeImmPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeImmBNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV8   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeA8BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVQ  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t! packed8B");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeA4CNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVQ  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t! packed4C");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeA2INode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVQ  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t! packed2I");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeImmCMNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV8   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t! CMS card-mark imm0");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FST_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeD_roundedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FST_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t# round");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeXDNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeA2FNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVQ  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t! packed2F");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FST_S  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeF_roundedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FST_S  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t# round");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeF_DroundedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FST_S  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t# D-round");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeF_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t# store float");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeX_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\t# store float");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storeSSINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void storeSSPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void storeSSLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("+4,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void membar_acquireNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("MEMBAR-acquire ! (empty encoding)");
  }
#endif
#ifndef PRODUCT
void membar_acquire_lockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("MEMBAR-acquire (prior CMPXCHG in FastLock so empty encoding)");
  }
#endif
#ifndef PRODUCT
void membar_releaseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("MEMBAR-release ! (empty encoding)");
  }
#endif
#ifndef PRODUCT
void membar_release_lockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("MEMBAR-release (a FastUnlock follows so empty encoding)");
  }
#endif
#ifndef PRODUCT
void membar_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    if (os::is_MP()) {
          st->print("LOCK ADDL [ESP + #0], 0\t! membar_volatile");
    } else {
          st->print("MEMBAR-volatile ! (empty encoding)");
    }
    }
#endif
#ifndef PRODUCT
void unnecessary_membar_volatileNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("MEMBAR-volatile (unnecessary so empty encoding)");
  }
#endif
#ifndef PRODUCT
void castX2PNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("# X2P  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void castP2XNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# CastP2X");
  }
#endif
#ifndef PRODUCT
void cmovI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovI_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovI_regUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovI_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovI_memUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovI_memUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# ptr");
  }
#endif
#ifndef PRODUCT
void cmovP_reg_nonP6Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("   skip\n\t");
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# pointer\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void cmovP_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# ptr");
  }
#endif
#ifndef PRODUCT
void cmovP_regUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void fcmovD_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("FCMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# double");
  }
#endif
#ifndef PRODUCT
void fcmovF_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("FCMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# float");
  }
#endif
#ifndef PRODUCT
void fcmovD_regSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("   skip\n\t");
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# double\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void fcmovF_regSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("    skip\n\t");
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# float\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void fcmovX_regSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("   skip\n\t");
    st->print("MOVSS  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# float\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void fcmovXD_regSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("   skip\n\t");
    st->print("MOVSD  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# float\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void fcmovX_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("   skip\n\t");
    st->print("MOVSS  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# float\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void fcmovX_regUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void fcmovXD_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Jn");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("   skip\n\t");
    st->print("MOVSD  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print("\t# float\n");
    st->print("skip:");
  }
#endif
#ifndef PRODUCT
void fcmovXD_regUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovL_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovL_regUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovL_regUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void addI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void incI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("INC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void leaI_eReg_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print(" + ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("]");
  }
#endif
#ifndef PRODUCT
void leaP_eReg_immINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("LEA    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print(" + ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("]\t# ptr");
  }
#endif
#ifndef PRODUCT
void decI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DEC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void addP_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addP_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addI_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addI_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void addI_mem_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void addI_mem_eReg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void addI_mem_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void incI_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("INC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void decI_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DEC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void checkCastPPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("#checkcastPP of ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void castPPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("#castPP of ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void castIINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("#castII of ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void loadPLockedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Load ptr. locked");
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadLLockedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Atomic volatile long load\n\t");
    st->print("FISTp  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadLX_LockedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSD  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Atomic volatile long load\n\t");
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void loadLX_reg_LockedNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSD  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\t# Atomic volatile long load\n\t");
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print("\n\t");
    st->print("PSRLQ  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",32\n\t");
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void storePConditionalNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMPXCHG ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // heap_top_ptr
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print("\t# If EAX==");
    opnd_array(1)->ext_format(ra, this,idx1, st); // heap_top_ptr
    st->print(" Then store ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print(" into ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // heap_top_ptr
  }
#endif
#ifndef PRODUCT
void storeIConditionalNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMPXCHG ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print("\t# If EAX==");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(" Then store ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print(" into ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void storeLConditionalNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("XCHG   EBX,ECX\t# correct order for CMPXCHG8 instruction\n\t");
    st->print("CMPXCHG8 ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(",ECX:EBX\t# If EDX:EAX==");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print(" Then store ECX:EBX into ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("XCHG   EBX,ECX");
  }
#endif
#ifndef PRODUCT
void compareAndSwapLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMPXCHG8 [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("],");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print("\t# If EDX:EAX==[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("] Then store ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print(" into [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("]\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // res
    st->print(",0\n\t");
    st->print("JNE,s  fail\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // res
    st->print(",1\n");
    st->print("fail:");
  }
#endif
#ifndef PRODUCT
void compareAndSwapPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMPXCHG [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("],");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print("\t# If EAX==[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("] Then store ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print(" into [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("]\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // res
    st->print(",0\n\t");
    st->print("JNE,s  fail\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // res
    st->print(",1\n");
    st->print("fail:");
  }
#endif
#ifndef PRODUCT
void compareAndSwapINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMPXCHG [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("],");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print("\t# If EAX==[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("] Then store ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // newval
    st->print(" into [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem_ptr
    st->print("]\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // res
    st->print(",0\n\t");
    st->print("JNE,s  fail\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // res
    st->print(",1\n");
    st->print("fail:");
  }
#endif
#ifndef PRODUCT
void subI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void subI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void subI_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void subI_mem_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void subP_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src
  }
#endif
#ifndef PRODUCT
void negI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("NEG    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
  }
#endif
#ifndef PRODUCT
void mulI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void mulI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // imm
  }
#endif
#ifndef PRODUCT
void loadConL_low_onlyNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    EAX,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t// low word only");
  }
#endif
#ifndef PRODUCT
void mulI_imm_highNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("IMUL   EDX:EAX,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  }
#endif
#ifndef PRODUCT
void mulI_imm_high_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("IMUL   EDX:EAX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  }
#endif
#ifndef PRODUCT
void mulI_imm_RShift_highNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("IMUL   EDX:EAX,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("SAR    EDX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // cnt
    st->print("-32");
  }
#endif
#ifndef PRODUCT
void mulI_imm_RShift_high_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("IMUL   EDX:EAX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("SAR    EDX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // cnt
    st->print("-32");
  }
#endif
#ifndef PRODUCT
void mulI_mem_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // imm
  }
#endif
#ifndef PRODUCT
void mulINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void mulI_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void mulI2LNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
  }
#endif
#ifndef PRODUCT
void mulI2L_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("IMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  }
#endif
#ifndef PRODUCT
void mulIS_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MUL    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src1
  }
#endif
#ifndef PRODUCT
void mulIS_eReg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MUL    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  }
#endif
#ifndef PRODUCT
void mulL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("IMUL   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",EDX\n\t");
    st->print("MOV    EDX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi\n\t");
    st->print("IMUL   EDX,EAX\n\t");
    st->print("ADD    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",EDX\n\t");
    st->print("MUL    EDX:EAX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("ADD    EDX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void mulL_eReg_lhi0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi\n\t");
    st->print("IMUL   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",EAX\n\t");
    st->print("MUL    EDX:EAX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("ADD    EDX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void mulL_eReg_rhi0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("IMUL   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",EDX\n\t");
    st->print("MUL    EDX:EAX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("ADD    EDX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void mulL_eReg_hi0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MUL    EDX:EAX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
  }
#endif
#ifndef PRODUCT
void mulL_eReg_conNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("IMUL   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",EDX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("MOV    EDX,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("MUL    EDX\t# EDX*EAX -> EDX:EAX\n\t");
    st->print("ADD    EDX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void divI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    EAX,0x80000000\n\t");
    st->print("JNE,s  normal\n\t");
    st->print("XOR    EDX,EDX\n\t");
    st->print("CMP    ECX,-1\n\t");
    st->print("JE,s   done\n");
    st->print("normal: CDQ\n\t");
    st->print("IDIV   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // div
    st->print("\n\t");
    st->print("done:");
  }
#endif
#ifndef PRODUCT
void divL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".hi\n\t");
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".lo\n\t");
    st->print("PUSH   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".hi\n\t");
    st->print("PUSH   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".lo\n\t");
    st->print("CALL   SharedRuntime::ldiv\n\t");
    st->print("ADD    ESP,16");
  }
#endif
#ifndef PRODUCT
void divModI_eReg_divmodNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    EAX,0x80000000\n\t");
    st->print("JNE,s  normal\n\t");
    st->print("XOR    EDX,EDX\n\t");
    st->print("CMP    ECX,-1\n\t");
    st->print("JE,s   done\n");
    st->print("normal: CDQ\n\t");
    st->print("IDIV   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // div
    st->print("\n\t");
    st->print("done:");
  }
#endif
#ifndef PRODUCT
void modI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CDQ\n\t");
    st->print("IDIV   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // div
  }
#endif
#ifndef PRODUCT
void modL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".hi\n\t");
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".lo\n\t");
    st->print("PUSH   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".hi\n\t");
    st->print("PUSH   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".lo\n\t");
    st->print("CALL   SharedRuntime::lrem\n\t");
    st->print("ADD    ESP,16");
  }
#endif
#ifndef PRODUCT
void shlI_eReg_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void salI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void salI_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void sarI_eReg_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void sarI_mem_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void sarI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void sarI_mem_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void sarI_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void shrI_eReg_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void shrI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void i2bNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(" :8");
  }
#endif
#ifndef PRODUCT
void i2sNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVSX  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(" :16");
  }
#endif
#ifndef PRODUCT
void shrI_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void andI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void andI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void andI_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void andI_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void andI_mem_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void andI_mem_eReg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void andI_mem_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void orI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void orI_eReg_castP2XNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void orI_eReg_castP2X_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void orI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void orI_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void orI_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void orI_mem_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void orI_mem_eReg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void orI_mem_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void rolI_eReg_imm1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ROL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void rolI_eReg_imm8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ROL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void rolI_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ROL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void rolI_eReg_i1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_i1_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_i8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_i8_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_Var_C0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_Var_C0_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_Var_C32Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rolI_eReg_Var_C32_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_imm1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ROR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void rorI_eReg_imm8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ROR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void rorI_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ROR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void rorI_eReg_i1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_i1_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_i8Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_i8_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_Var_C0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_Var_C0_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_Var_C32Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void rorI_eReg_Var_C32_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void xorI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void xorI_eReg_im1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("NOT    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void xorI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void xorI_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void xorI_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void xorI_mem_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void xorI_mem_eReg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void xorI_mem_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void movI_nocopyNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void ci2bNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("NEG    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print("\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void convI2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void movP_nocopyNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void cp2bNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("NEG    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print("\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void convP2BNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmpLTMaskNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // q
    st->print("\n\t");
    st->print("SETlt  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("NEG    ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void cmpLTMask0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",31");
  }
#endif
#ifndef PRODUCT
void cadd_cmpLTMaskNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // q
    st->print("\n\t");
    st->print("SBB    ECX,ECX\n\t");
    st->print("AND    ECX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // y
    st->print("\n\t");
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",ECX");
  }
#endif
#ifndef PRODUCT
void cadd_cmpLTMask_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // q
    st->print("\n\t");
    st->print("SBB    ECX,ECX\n\t");
    st->print("AND    ECX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // y
    st->print("\n\t");
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",ECX");
  }
#endif
#ifndef PRODUCT
void cadd_cmpLTMask_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("SUB    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // p
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // q
    st->print("\n\t");
    st->print("SBB    ECX,ECX\n\t");
    st->print("AND    ECX,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // y
    st->print("\n\t");
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // p
    st->print(",ECX");
  }
#endif
#ifndef PRODUCT
void cadd_cmpLTMask_2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // q
    st->print("\n\t");
    st->print("SBB    ECX,ECX\n\t");
    st->print("AND    ECX,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // y
    st->print("\n\t");
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // p
    st->print(",ECX");
  }
#endif
#ifndef PRODUCT
void addL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void addL_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void addL_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void addL_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("ADC    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void subL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("SBB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void subL_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("SBB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void subL_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n\t");
    st->print("SBB    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void negL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("NEG    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".hi\n\tNEG    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".lo\n\tSBB    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".hi,0");
  }
#endif
#ifndef PRODUCT
void andL_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void andL_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void andL_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n\t");
    st->print("AND    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void andL_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("AND    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("AND    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void orl_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void orl_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void orl_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n\t");
    st->print("OR     ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void orl_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("OR     ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("OR     ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void xorl_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void xorl_eReg_im1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("NOT    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("NOT    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void xorl_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".lo\n\t");
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void xorl_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n\t");
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void xorl_eReg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("XOR    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("+4");
  }
#endif
#ifndef PRODUCT
void shlL_eReg_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void shlL_eReg_2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n\t");
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void shlL_eReg_3Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n\t");
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n\t");
    st->print("ADD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("ADC    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void shlL_eReg_1_31Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHLD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
    st->print("\n\t");
    st->print("SHL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
  }
#endif
#ifndef PRODUCT
void shlL_eReg_32_63Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n");
    st->print("\tSHL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
    st->print("-32\n");
    st->print("\tXOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo");
  }
#endif
#ifndef PRODUCT
void salL_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    st->print(",32\n\t");
    st->print("JEQ,s  small\n\t");
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n\t");
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo\n");
    st->print("small:\tSHLD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    st->print("\n\t");
    st->print("SHL    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void shrL_eReg_1_31Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHRD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
    st->print("\n\t");
    st->print("SHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
  }
#endif
#ifndef PRODUCT
void shrL_eReg_32_63Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n");
    st->print("\tSHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
    st->print("-32\n");
    st->print("\tXOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void shrL_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    st->print(",32\n\t");
    st->print("JEQ,s  small\n\t");
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n\t");
    st->print("XOR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n");
    st->print("small:\tSHRD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    st->print("\n\t");
    st->print("SHR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void sarL_eReg_1_31Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SHRD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
    st->print("\n\t");
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
  }
#endif
#ifndef PRODUCT
void sarL_eReg_32_63Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n");
    st->print("\tSAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt
    st->print("-32\n");
    st->print("\tSAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,31");
  }
#endif
#ifndef PRODUCT
void sarL_eReg_CLNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    st->print(",32\n\t");
    st->print("JEQ,s  small\n\t");
    st->print("MOV    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi\n\t");
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,31\n");
    st->print("small:\tSHRD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
    st->print("\n\t");
    st->print("SAR    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // shift
  }
#endif
#ifndef PRODUCT
void cmpD_cc_P6Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FUCOMIP ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("  // P6 instruction\n\t");
    st->print("JNP    exit\n\t");
    st->print("MOV    ah,1       // saw a NaN, set CF\n\t");
    st->print("SAHF\n");
    st->print("exit:\tNOP               // avoid branch to branch");
  }
#endif
#ifndef PRODUCT
void cmpD_cc_P6CFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FUCOMIP ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("  // P6 instruction");
  }
#endif
#ifndef PRODUCT
void cmpD_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FCOMp  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FNSTSW AX\n\t");
    st->print("TEST   AX,0x400\n\t");
    st->print("JZ,s   flags\n\t");
    st->print("MOV    AH,1\t# unordered treat as LT\n");
    st->print("flags:\tSAHF");
  }
#endif
#ifndef PRODUCT
void cmpD_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FTSTD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  }
#endif
#ifndef PRODUCT
void cmpD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FCMPD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void cmpXD_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISD ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n");
    st->print("\tJNP    exit\n");
    st->print("\tMOV    ah,1       // saw a NaN, set CF\n");
    st->print("\tSAHF\n");
    st->print("exit:\tNOP               // avoid branch to branch");
  }
#endif
#ifndef PRODUCT
void cmpXD_ccCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISD ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void cmpXD_ccmemNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISD ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n");
    st->print("\tJNP    exit\n");
    st->print("\tMOV    ah,1       // saw a NaN, set CF\n");
    st->print("\tSAHF\n");
    st->print("exit:\tNOP               // avoid branch to branch");
  }
#endif
#ifndef PRODUCT
void cmpXD_ccmemCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISD ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void cmpXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("\tCOMISD ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n");
    st->print("\tJP,s   nan\n");
    st->print("\tJEQ,s  exit\n");
    st->print("\tJA,s   inc\n");
    st->print("nan:\tDEC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("\tJMP,s  exit\n");
    st->print("inc:\tINC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("exit:");
  }
#endif
#ifndef PRODUCT
void cmpXD_regmemNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISD ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n");
    st->print("\tMOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0\t\t# do not blow flags\n");
    st->print("\tJP,s   nan\n");
    st->print("\tJEQ,s  exit\n");
    st->print("\tJA,s   inc\n");
    st->print("nan:\tDEC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("\tJMP,s  exit\n");
    st->print("inc:\tINC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("exit:");
  }
#endif
#ifndef PRODUCT
void subD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DSUBp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void subD_reg_roundNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("DSUB   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void subD_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DSUBp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void absD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FABS");
  }
#endif
#ifndef PRODUCT
void absXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("ANDPD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[0x7FFFFFFFFFFFFFFF]\t# ABS D by sign masking");
  }
#endif
#ifndef PRODUCT
void negD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FCHS");
  }
#endif
#ifndef PRODUCT
void negXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("XORPD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[0x8000000000000000]\t# CHS D by sign flipping");
  }
#endif
#ifndef PRODUCT
void addD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DADD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addD_reg_roundNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("DADD   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void addD_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DADDp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addD_reg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("DADDp  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addD_mem_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print("\n\t");
    st->print("DADD   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FST_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void addD_mem_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print("\n\t");
    st->print("DADD   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FST_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    if (ra->C->alias_type(adr_type())->field() != NULL) {
      st->print(" ! Field ");
      if( ra->C->alias_type(adr_type())->is_volatile() )
        st->print(" Volatile");
      ra->C->alias_type(adr_type())->field()->holder()->name()->print_symbol_on(st);
      st->print(".");
      ra->C->alias_type(adr_type())->field()->name()->print_symbol_on(st);
    } else
    if( ra->C->alias_type(adr_type())->is_volatile() )
      st->print(" Volatile!");
  }
#endif
#ifndef PRODUCT
void addD_reg_imm1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD1\n\t");
    st->print("DADDp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addD_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  [");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("]\n\t");
    st->print("DADDp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addD_reg_imm_roundNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  [");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]\n\t");
    st->print("DADD   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void addXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addXD_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void addXD_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void addXD_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSD  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void subXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUBSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void subXD_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUBSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void subXD_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUBSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void mulXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void mulXD_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void mulXD_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void mulXD_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSD  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void divXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DIVSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void divXD_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DIVSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void divXD_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DIVSD  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void mulD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void strictfp_mulD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    StubRoutines::_fpu_subnormal_bias1\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST\n\t");
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST\n\t");
    st->print("FLD    StubRoutines::_fpu_subnormal_bias2\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST\n\t");
  }
#endif
#ifndef PRODUCT
void mulD_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  [");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("]\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void mulD_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void mulD_reg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("DMULp  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void mulD_reg_mem_ciscNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n\t");
    st->print("DMUL   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulD_reg_mem_cisc_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("DMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addD_mulD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("\t# ===MACRO3d===\n\t");
    st->print("DMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("DADDp  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src2
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addD_mulD_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src0
    st->print("\t# ===MACRO3d===\n\t");
    st->print("DMUL   ST,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src1
    st->print("\n\t");
    st->print("DADDp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void subD_mulD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("\t# ===MACRO3d===\n\t");
    st->print("DMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("DSUBRp ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src2
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void divD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FDIVp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void strictfp_divD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    StubRoutines::_fpu_subnormal_bias1\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST\n\t");
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FDIVp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST\n\t");
    st->print("FLD    StubRoutines::_fpu_subnormal_bias2\n\t");
    st->print("DMULp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST\n\t");
  }
#endif
#ifndef PRODUCT
void divD_reg_roundNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FDIV   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void modD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DMOD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void modXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ESP,8\t # DMOD\n");
    st->print("\tMOVSD  [ESP+0],");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n");
    st->print("\tFLD_D  [ESP+0]\n");
    st->print("\tMOVSD  [ESP+0],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("\n");
    st->print("\tFLD_D  [ESP+0]\n");
    st->print("loop:\tFPREM\n");
    st->print("\tFWAIT\n");
    st->print("\tFNSTSW AX\n");
    st->print("\tSAHF\n");
    st->print("\tJP     loop\n");
    st->print("\tFSTP_D [ESP+0]\n");
    st->print("\tMOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP+0]\n");
    st->print("\tADD    ESP,8\n");
    st->print("\tFSTP   ST0\t # Restore FPU Stack");
  }
#endif
#ifndef PRODUCT
void sinD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DSIN   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void sinXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DSIN   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void cosD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DCOS   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void cosXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DCOS   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void tanD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DTAN   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void tanXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DTAN   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
  }
#endif
#ifndef PRODUCT
void atanD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DATA   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void atanXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DATA   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void sqrtD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("DSQRT  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void powD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ESP,8\t\t# Fast-path POW encoding\n\t");
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // X
    st->print("\n\t");
    st->print("FYL2X  \t\t\t# Q=Y*ln2(X)\n\t");
    st->print("FDUP   \t\t\t# Q Q\n\t");
    st->print("FRNDINT\t\t\t# int(Q) Q\n\t");
    st->print("FSUB   ST(1),ST(0)\t# int(Q) frac(Q)\n\t");
    st->print("FISTP  dword [ESP]\n\t");
    st->print("F2XM1  \t\t\t# 2^frac(Q)-1 int(Q)\n\t");
    st->print("FLD1   \t\t\t# 1 2^frac(Q)-1 int(Q)\n\t");
    st->print("FADDP  \t\t\t# 2^frac(Q) int(Q)\n\t");
    st->print("MOV    EAX,[ESP]\t# Pick up int(Q)\n\t");
    st->print("MOV    ECX,0xFFFFF800\t# Overflow mask\n\t");
    st->print("ADD    EAX,1023\t\t# Double exponent bias\n\t");
    st->print("MOV    EBX,EAX\t\t# Preshifted biased expo\n\t");
    st->print("SHL    EAX,20\t\t# Shift exponent into place\n\t");
    st->print("TEST   EBX,ECX\t\t# Check for overflow\n\t");
    st->print("CMOVne EAX,ECX\t\t# If overflow, stuff NaN into EAX\n\t");
    st->print("MOV    [ESP+4],EAX\t# Marshal 64-bit scaling double\n\t");
    st->print("MOV    [ESP+0],0\n\t");
    st->print("FMUL   ST(0),[ESP+0]\t# Scale\n\t");
    st->print("ADD    ESP,8");
  }
#endif
#ifndef PRODUCT
void powXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ESP,8\t\t# Fast-path POW encoding\n\t");
    st->print("MOVSD  [ESP],");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("FLD    FPR1,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("MOVSD  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("\n\t");
    st->print("FLD    FPR1,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("\n\t");
    st->print("FYL2X  \t\t\t# Q=Y*ln2(X)\n\t");
    st->print("FDUP   \t\t\t# Q Q\n\t");
    st->print("FRNDINT\t\t\t# int(Q) Q\n\t");
    st->print("FSUB   ST(1),ST(0)\t# int(Q) frac(Q)\n\t");
    st->print("FISTP  dword [ESP]\n\t");
    st->print("F2XM1  \t\t\t# 2^frac(Q)-1 int(Q)\n\t");
    st->print("FLD1   \t\t\t# 1 2^frac(Q)-1 int(Q)\n\t");
    st->print("FADDP  \t\t\t# 2^frac(Q) int(Q)\n\t");
    st->print("MOV    EAX,[ESP]\t# Pick up int(Q)\n\t");
    st->print("MOV    ECX,0xFFFFF800\t# Overflow mask\n\t");
    st->print("ADD    EAX,1023\t\t# Double exponent bias\n\t");
    st->print("MOV    EBX,EAX\t\t# Preshifted biased expo\n\t");
    st->print("SHL    EAX,20\t\t# Shift exponent into place\n\t");
    st->print("TEST   EBX,ECX\t\t# Check for overflow\n\t");
    st->print("CMOVne EAX,ECX\t\t# If overflow, stuff NaN into EAX\n\t");
    st->print("MOV    [ESP+4],EAX\t# Marshal 64-bit scaling double\n\t");
    st->print("MOV    [ESP+0],0\n\t");
    st->print("FMUL   ST(0),[ESP+0]\t# Scale\n\t");
    st->print("FST_D  [ESP]\n\t");
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP]\n\t");
    st->print("ADD    ESP,8");
  }
#endif
#ifndef PRODUCT
void expD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("SUB    ESP,8\t\t# Fast-path EXP encoding");
    st->print("FLDL2E \t\t\t# Ld log2(e) X\n\t");
    st->print("FMULP  \t\t\t# Q=X*log2(e)\n\t");
    st->print("FDUP   \t\t\t# Q Q\n\t");
    st->print("FRNDINT\t\t\t# int(Q) Q\n\t");
    st->print("FSUB   ST(1),ST(0)\t# int(Q) frac(Q)\n\t");
    st->print("FISTP  dword [ESP]\n\t");
    st->print("F2XM1  \t\t\t# 2^frac(Q)-1 int(Q)\n\t");
    st->print("FLD1   \t\t\t# 1 2^frac(Q)-1 int(Q)\n\t");
    st->print("FADDP  \t\t\t# 2^frac(Q) int(Q)\n\t");
    st->print("MOV    EAX,[ESP]\t# Pick up int(Q)\n\t");
    st->print("MOV    ECX,0xFFFFF800\t# Overflow mask\n\t");
    st->print("ADD    EAX,1023\t\t# Double exponent bias\n\t");
    st->print("MOV    EBX,EAX\t\t# Preshifted biased expo\n\t");
    st->print("SHL    EAX,20\t\t# Shift exponent into place\n\t");
    st->print("TEST   EBX,ECX\t\t# Check for overflow\n\t");
    st->print("CMOVne EAX,ECX\t\t# If overflow, stuff NaN into EAX\n\t");
    st->print("MOV    [ESP+4],EAX\t# Marshal 64-bit scaling double\n\t");
    st->print("MOV    [ESP+0],0\n\t");
    st->print("FMUL   ST(0),[ESP+0]\t# Scale\n\t");
    st->print("ADD    ESP,8");
  }
#endif
#ifndef PRODUCT
void expXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SUB    ESP,8\t\t# Fast-path EXP encoding\n\t");
    st->print("MOVSD  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLDL2E \t\t\t# Ld log2(e) X\n\t");
    st->print("FMULP  \t\t\t# Q=X*log2(e) X\n\t");
    st->print("FDUP   \t\t\t# Q Q\n\t");
    st->print("FRNDINT\t\t\t# int(Q) Q\n\t");
    st->print("FSUB   ST(1),ST(0)\t# int(Q) frac(Q)\n\t");
    st->print("FISTP  dword [ESP]\n\t");
    st->print("F2XM1  \t\t\t# 2^frac(Q)-1 int(Q)\n\t");
    st->print("FLD1   \t\t\t# 1 2^frac(Q)-1 int(Q)\n\t");
    st->print("FADDP  \t\t\t# 2^frac(Q) int(Q)\n\t");
    st->print("MOV    EAX,[ESP]\t# Pick up int(Q)\n\t");
    st->print("MOV    ECX,0xFFFFF800\t# Overflow mask\n\t");
    st->print("ADD    EAX,1023\t\t# Double exponent bias\n\t");
    st->print("MOV    EBX,EAX\t\t# Preshifted biased expo\n\t");
    st->print("SHL    EAX,20\t\t# Shift exponent into place\n\t");
    st->print("TEST   EBX,ECX\t\t# Check for overflow\n\t");
    st->print("CMOVne EAX,ECX\t\t# If overflow, stuff NaN into EAX\n\t");
    st->print("MOV    [ESP+4],EAX\t# Marshal 64-bit scaling double\n\t");
    st->print("MOV    [ESP+0],0\n\t");
    st->print("FMUL   ST(0),[ESP+0]\t# Scale\n\t");
    st->print("FST_D  [ESP]\n\t");
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP]\n\t");
    st->print("ADD    ESP,8");
  }
#endif
#ifndef PRODUCT
void log10D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FLDLG2 \t\t\t#Log10\n\t");
    st->print("FXCH   \n\t");
    st->print("FYL2X  \t\t\t# Q=Log10*Log_2(x)");
  }
#endif
#ifndef PRODUCT
void log10XD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FLDLG2 \t\t\t#Log10\n\t");
    st->print("FYL2X  \t\t\t# Q=Log10*Log_2(x)");
  }
#endif
#ifndef PRODUCT
void logD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FLDLN2 \t\t\t#Log_e\n\t");
    st->print("FXCH   \n\t");
    st->print("FYL2X  \t\t\t# Q=Log_e*Log_2(x)");
  }
#endif
#ifndef PRODUCT
void logXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FLDLN2 \t\t\t#Log_e\n\t");
    st->print("FYL2X  \t\t\t# Q=Log_e*Log_2(x)");
  }
#endif
#ifndef PRODUCT
void cmpF_cc_P6Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FUCOMIP ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("  // P6 instruction\n\t");
    st->print("JNP    exit\n\t");
    st->print("MOV    ah,1       // saw a NaN, set CF (treat as LT)\n\t");
    st->print("SAHF\n");
    st->print("exit:\tNOP               // avoid branch to branch");
  }
#endif
#ifndef PRODUCT
void cmpF_cc_P6CFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FUCOMIP ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("  // P6 instruction");
  }
#endif
#ifndef PRODUCT
void cmpF_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FCOMp  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FNSTSW AX\n\t");
    st->print("TEST   AX,0x400\n\t");
    st->print("JZ,s   flags\n\t");
    st->print("MOV    AH,1\t# unordered treat as LT\n");
    st->print("flags:\tSAHF");
  }
#endif
#ifndef PRODUCT
void cmpF_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FTSTF  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
  }
#endif
#ifndef PRODUCT
void cmpF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FCMPF  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void cmpX_ccNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISS ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n");
    st->print("\tJNP    exit\n");
    st->print("\tMOV    ah,1       // saw a NaN, set CF\n");
    st->print("\tSAHF\n");
    st->print("exit:\tNOP               // avoid branch to branch");
  }
#endif
#ifndef PRODUCT
void cmpX_ccCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISS ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void cmpX_ccmemNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISS ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n");
    st->print("\tJNP    exit\n");
    st->print("\tMOV    ah,1       // saw a NaN, set CF\n");
    st->print("\tSAHF\n");
    st->print("exit:\tNOP               // avoid branch to branch");
  }
#endif
#ifndef PRODUCT
void cmpX_ccmemCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISS ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void cmpX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("\tCOMISS ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n");
    st->print("\tJP,s   nan\n");
    st->print("\tJEQ,s  exit\n");
    st->print("\tJA,s   inc\n");
    st->print("nan:\tDEC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("\tJMP,s  exit\n");
    st->print("inc:\tINC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("exit:");
  }
#endif
#ifndef PRODUCT
void cmpX_regmemNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("COMISS ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
    st->print("\n");
    st->print("\tMOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0\t\t# do not blow flags\n");
    st->print("\tJP,s   nan\n");
    st->print("\tJEQ,s  exit\n");
    st->print("\tJA,s   inc\n");
    st->print("nan:\tDEC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("\tJMP,s  exit\n");
    st->print("inc:\tINC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("exit:");
  }
#endif
#ifndef PRODUCT
void subF24_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FSUB   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(" - ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void subF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FSUB   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addF24_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void addF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FADDp  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addX_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void addX_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void addX_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("ADDSS  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void subX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUBSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void subX_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUBSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void subX_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUBSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void mulX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void mulX_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void mulX_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void mulX_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MULSS  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void divX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DIVSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void divX_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DIVSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
    st->print("]");
  }
#endif
#ifndef PRODUCT
void divX_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("DIVSS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void sqrtX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SQRTSS ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void sqrtX_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("SQRTSS ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void sqrtXD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SQRTSD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void sqrtXD_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("SQRTSD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void absF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FABS");
  }
#endif
#ifndef PRODUCT
void absX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("ANDPS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[0x7FFFFFFF]\t# ABS F by sign masking");
  }
#endif
#ifndef PRODUCT
void negF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("FCHS");
  }
#endif
#ifndef PRODUCT
void negX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("XORPS  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",[0x80000000]\t# CHS F by sign flipping");
  }
#endif
#ifndef PRODUCT
void addF24_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FADD   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF24_reg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print("\n\t");
    st->print("FADD   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void addF_reg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void addF24_mem_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void addF24_mem_ciscNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(" cisc");
  }
#endif
#ifndef PRODUCT
void addF24_mem_cisc_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print(" cisc");
  }
#endif
#ifndef PRODUCT
void addF24_mem_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FADD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void addF24_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FADD   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FADD   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulF24_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FMUL   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FMUL   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulF24_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_S  ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print("\n\t");
    st->print("FMUL   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulF24_reg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD_S  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print("\n\t");
    st->print("FMUL   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulF_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void mulF_reg_mem_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
  }
#endif
#ifndef PRODUCT
void mulF24_mem_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMUL   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void mulF24_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMULc ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void mulF_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMULc ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(". ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void mulF_reg_load1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem1
    st->print("    ===MACRO1===\n\t");
    st->print("FMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void mulF_reg_load1_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem1
    st->print("    ===MACRO1===\n\t");
    st->print("FMUL   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_mulF_reg_load1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem1
    st->print("     ===MACRO2===\n\t");
    st->print("FMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("  subsume mulF left load\n\t");
    st->print("FADD   ST,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src2
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_mulF_reg_load1_1Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem1
    st->print("     ===MACRO2===\n\t");
    st->print("FMUL   ST,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src1
    st->print("  subsume mulF left load\n\t");
    st->print("FADD   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_mulF_reg_load1_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem1
    st->print("     ===MACRO2===\n\t");
    st->print("FMUL   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print("  subsume mulF left load\n\t");
    st->print("FADD   ST,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src2
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_mulF_reg_load1_2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // mem1
    st->print("     ===MACRO2===\n\t");
    st->print("FMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("  subsume mulF left load\n\t");
    st->print("FADD   ST,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void addF_mulF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("     ===MACRO3===\n\t");
    st->print("FMUL   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("FADDP  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src2
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void addF_mulF_reg_0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src0
    st->print("     ===MACRO3===\n\t");
    st->print("FMUL   ST,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src1
    st->print("\n\t");
    st->print("FADDP  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print(",ST");
  }
#endif
#ifndef PRODUCT
void subF_divF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src2
    st->print("   ===MACRO4===\n\t");
    st->print("FSUB   ST,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n\t");
    st->print("FDIV   ST,");
    opnd_array(3)->ext_format(ra, this,idx3, st); // src3
    st->print("\n\t");
    st->print("FSTP  ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void divF24_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FDIV   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void divF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FDIV   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void modF24_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMOD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
  }
#endif
#ifndef PRODUCT
void modF_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("FMOD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void modX_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("SUB    ESP,4\t # FMOD\n");
    st->print("\tMOVSS  [ESP+0],");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src1
    st->print("\n");
    st->print("\tFLD_S  [ESP+0]\n");
    st->print("\tMOVSS  [ESP+0],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src0
    st->print("\n");
    st->print("\tFLD_S  [ESP+0]\n");
    st->print("loop:\tFPREM\n");
    st->print("\tFWAIT\n");
    st->print("\tFNSTSW AX\n");
    st->print("\tSAHF\n");
    st->print("\tJP     loop\n");
    st->print("\tFSTP_S [ESP+0]\n");
    st->print("\tMOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP+0]\n");
    st->print("\tADD    ESP,4\n");
    st->print("\tFSTP   ST0\t # Restore FPU Stack");
  }
#endif
#ifndef PRODUCT
void roundFloat_mem_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_S  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# F-round");
  }
#endif
#ifndef PRODUCT
void roundDouble_mem_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_D  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void convD2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_S  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# F-round");
  }
#endif
#ifndef PRODUCT
void convD2X_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SUB    ESP,4\n\t");
    st->print("FST_S  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# F-round\n\t");
    st->print("MOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP]\n\t");
    st->print("ADD ESP,4");
  }
#endif
#ifndef PRODUCT
void convXD2X_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("CVTSD2SS ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# F-round");
  }
#endif
#ifndef PRODUCT
void convF2D_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_S  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void convF2D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_D  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void convX2D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SUB    ESP,4\n\t");
    st->print("MOVSS  [ESP] ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD_S  [ESP]\n\t");
    st->print("ADD    ESP,4\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void convX2XD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("CVTSS2SD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void convD2I_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# Convert double to int \n\t");
    st->print("FLDCW  trunc mode\n\t");
    st->print("SUB    ESP,4\n\t");
    st->print("FISTp  [ESP + #0]\n\t");
    st->print("FLDCW  std/24-bit mode\n\t");
    st->print("POP    EAX\n\t");
    st->print("CMP    EAX,0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CALL   d2i_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convXD2I_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("CVTTSD2SI ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CMP    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("SUB    ESP, 8\n\t");
    st->print("MOVSD  [ESP], ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD_D  [ESP]\n\t");
    st->print("ADD    ESP, 8\n\t");
    st->print("CALL   d2i_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convD2L_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# Convert double to long\n\t");
    st->print("FLDCW  trunc mode\n\t");
    st->print("SUB    ESP,8\n\t");
    st->print("FISTp  [ESP + #0]\n\t");
    st->print("FLDCW  std/24-bit mode\n\t");
    st->print("POP    EAX\n\t");
    st->print("POP    EDX\n\t");
    st->print("CMP    EDX,0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("TEST   EAX,EAX\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CALL   d2l_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convXD2L_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SUB    ESP,8\t# Convert double to long\n\t");
    st->print("MOVSD  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD_D  [ESP]\n\t");
    st->print("FLDCW  trunc mode\n\t");
    st->print("FISTp  [ESP + #0]\n\t");
    st->print("FLDCW  std/24-bit mode\n\t");
    st->print("POP    EAX\n\t");
    st->print("POP    EDX\n\t");
    st->print("CMP    EDX,0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("TEST   EAX,EAX\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("SUB    ESP,8\n\t");
    st->print("MOVSD  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD_D  [ESP]\n\t");
    st->print("CALL   d2l_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convF2I_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# Convert float to int \n\t");
    st->print("FLDCW  trunc mode\n\t");
    st->print("SUB    ESP,4\n\t");
    st->print("FISTp  [ESP + #0]\n\t");
    st->print("FLDCW  std/24-bit mode\n\t");
    st->print("POP    EAX\n\t");
    st->print("CMP    EAX,0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CALL   d2i_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convX2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("CVTTSS2SI ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CMP    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("SUB    ESP, 4\n\t");
    st->print("MOVSS  [ESP], ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD    [ESP]\n\t");
    st->print("ADD    ESP, 4\n\t");
    st->print("CALL   d2i_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convF2L_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# Convert float to long\n\t");
    st->print("FLDCW  trunc mode\n\t");
    st->print("SUB    ESP,8\n\t");
    st->print("FISTp  [ESP + #0]\n\t");
    st->print("FLDCW  std/24-bit mode\n\t");
    st->print("POP    EAX\n\t");
    st->print("POP    EDX\n\t");
    st->print("CMP    EDX,0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("TEST   EAX,EAX\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("FLD    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CALL   d2l_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convX2L_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("SUB    ESP,8\t# Convert float to long\n\t");
    st->print("MOVSS  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD_S  [ESP]\n\t");
    st->print("FLDCW  trunc mode\n\t");
    st->print("FISTp  [ESP + #0]\n\t");
    st->print("FLDCW  std/24-bit mode\n\t");
    st->print("POP    EAX\n\t");
    st->print("POP    EDX\n\t");
    st->print("CMP    EDX,0x80000000\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("TEST   EAX,EAX\n\t");
    st->print("JNE,s  fast\n\t");
    st->print("SUB    ESP,4\t# Convert float to long\n\t");
    st->print("MOVSS  [ESP],");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FLD_S  [ESP]\n\t");
    st->print("ADD    ESP,4\n\t");
    st->print("CALL   d2l_wrapper\n");
    st->print("fast:");
  }
#endif
#ifndef PRODUCT
void convI2D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void convI2XD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("CVTSI2SD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void convI2XD_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("CVTSI2SD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
  }
#endif
#ifndef PRODUCT
void convXI2XD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CVTDQ2PD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# i2d");
  }
#endif
#ifndef PRODUCT
void convI2D_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void conv24I2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void convI2F_SSFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void convI2F_SSF_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void convI2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void convI2F_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    st->print("FILD   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // mem
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
  }
#endif
#ifndef PRODUCT
void convI2X_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("CVTSI2SS ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void convXI2X_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("CVTDQ2PS ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# i2f");
  }
#endif
#ifndef PRODUCT
void convI2L_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("SAR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,31");
  }
#endif
#ifndef PRODUCT
void convI2L_reg_zexNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void zerox_longNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi\n\t");
  }
#endif
#ifndef PRODUCT
void convL2D_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# Convert long to double\n\t");
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("FILD   ST,[ESP + #0]\n\t");
    st->print("ADD    ESP,8\n\t");
    st->print("FSTP_D ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# D-round");
  }
#endif
#ifndef PRODUCT
void convL2XD_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# Convert long to double\n\t");
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("FILD_D [ESP]\n\t");
    st->print("FSTP_D [ESP]\n\t");
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP]\n\t");
    st->print("ADD    ESP,8");
  }
#endif
#ifndef PRODUCT
void convL2X_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# Convert long to single float\n\t");
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("FILD_D [ESP]\n\t");
    st->print("FSTP_S [ESP]\n\t");
    st->print("MOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",[ESP]\n\t");
    st->print("ADD    ESP,8");
  }
#endif
#ifndef PRODUCT
void convL2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# Convert long to single float\n\t");
    st->print("PUSH   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("FILD   ST,[ESP + #0]\n\t");
    st->print("ADD    ESP,8\n\t");
    st->print("FSTP_S ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# F-round");
  }
#endif
#ifndef PRODUCT
void convL2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo");
  }
#endif
#ifndef PRODUCT
void MoveF2I_stack_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveF2I_stack_reg");
  }
#endif
#ifndef PRODUCT
void MoveF2I_reg_stackNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_S  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveF2I_reg_stack");
  }
#endif
#ifndef PRODUCT
void MoveF2I_reg_stack_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveF2I_reg_stack_sse");
  }
#endif
#ifndef PRODUCT
void MoveF2I_reg_reg_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveF2I_reg_reg_sse");
  }
#endif
#ifndef PRODUCT
void MoveI2F_reg_stackNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveI2F_reg_stack");
  }
#endif
#ifndef PRODUCT
void MoveI2F_stack_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD_S  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# MoveI2F_stack_reg");
  }
#endif
#ifndef PRODUCT
void MoveI2F_stack_reg_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVSS  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveI2F_stack_reg_sse");
  }
#endif
#ifndef PRODUCT
void MoveI2F_reg_reg_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveI2F_reg_reg_sse");
  }
#endif
#ifndef PRODUCT
void MoveD2L_stack_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("+4\t# MoveD2L_stack_reg");
  }
#endif
#ifndef PRODUCT
void MoveD2L_reg_stackNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FST_D  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveD2L_reg_stack");
  }
#endif
#ifndef PRODUCT
void MoveD2L_reg_stack_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveD2L_reg_stack_sse");
  }
#endif
#ifndef PRODUCT
void MoveD2L_reg_reg_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("PSHUFLW ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",0x4E\n\t");
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // tmp
    st->print("\t# MoveD2L_reg_reg_sse");
  }
#endif
#ifndef PRODUCT
void MoveL2D_reg_stackNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("+4,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t# MoveL2D_reg_stack");
  }
#endif
#ifndef PRODUCT
void MoveL2D_stack_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("FLD_D  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("FSTP   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t# MoveL2D_stack_reg");
  }
#endif
#ifndef PRODUCT
void MoveL2D_stack_reg_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVSD  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveL2D_stack_reg_sse");
  }
#endif
#ifndef PRODUCT
void MoveL2D_stack_reg_sse_partialNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVLPD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\t# MoveL2D_stack_reg_sse");
  }
#endif
#ifndef PRODUCT
void MoveL2D_reg_reg_sseNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MOVD   ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("MOVD   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\n\t");
    st->print("PUNPCKLDQ ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // dst
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print("\t# MoveL2D_reg_reg_sse");
  }
#endif
#ifndef PRODUCT
void Repl8B_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVDQA  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("PUNPCKLBW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("PSHUFLW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x00\t! replicate8B");
  }
#endif
#ifndef PRODUCT
void Repl8B_eRegINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("PUNPCKLBW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("PSHUFLW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x00\t! replicate8B");
  }
#endif
#ifndef PRODUCT
void Repl8B_immI0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PXOR  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t! replicate8B");
  }
#endif
#ifndef PRODUCT
void Repl4S_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PSHUFLW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",0x00\t! replicate4S");
  }
#endif
#ifndef PRODUCT
void Repl4S_eRegINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("PSHUFLW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x00\t! replicate4S");
  }
#endif
#ifndef PRODUCT
void Repl4S_immI0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PXOR  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t! replicate4S");
  }
#endif
#ifndef PRODUCT
void Repl4C_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PSHUFLW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",0x00\t! replicate4C");
  }
#endif
#ifndef PRODUCT
void Repl4C_eRegINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("PSHUFLW ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x00\t! replicate4C");
  }
#endif
#ifndef PRODUCT
void Repl4C_immI0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PXOR  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t! replicate4C");
  }
#endif
#ifndef PRODUCT
void Repl2I_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PSHUFD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",0x00\t! replicate2I");
  }
#endif
#ifndef PRODUCT
void Repl2I_eRegINode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOVD   ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print("\n\t");
    st->print("PSHUFD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",0x00\t! replicate2I");
  }
#endif
#ifndef PRODUCT
void Repl2I_immI0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PXOR  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t! replicate2I");
  }
#endif
#ifndef PRODUCT
void Repl2F_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PSHUFD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",0xe0\t! replicate2F");
  }
#endif
#ifndef PRODUCT
void Repl2F_regXNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PSHUFD ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",0xe0\t! replicate2F");
  }
#endif
#ifndef PRODUCT
void Repl2F_immXF0Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("PXOR  ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\t! replicate2F");
  }
#endif
#ifndef PRODUCT
void rep_stosNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("SHL    ECX,1\t# Convert doublewords to words\n\t");
    st->print("XOR    EAX,EAX\n\t");
    st->print("REP STOS\t# store EAX into [EDI++] while ECX--");
  }
#endif
#ifndef PRODUCT
void string_compareNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    unsigned idx5 = idx4 + opnd_array(4)->num_edges();
    unsigned idx6 = idx5 + opnd_array(5)->num_edges();
    st->print("String Compare ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // str1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt1
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // str2
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // cnt2
    st->print(" -> ");
    opnd_array(0)->int_format(ra, this, st); // result
    st->print("   // KILL ");
    opnd_array(5)->ext_format(ra, this,idx5, st); // tmp1
    st->print(", ");
    opnd_array(6)->ext_format(ra, this,idx6, st); // tmp2
  }
#endif
#ifndef PRODUCT
void string_equalsNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    unsigned idx5 = idx4 + opnd_array(4)->num_edges();
    st->print("String Equals ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // str1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // str2
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // cnt
    st->print(" -> ");
    opnd_array(0)->int_format(ra, this, st); // result
    st->print("    // KILL ");
    opnd_array(4)->ext_format(ra, this,idx4, st); // tmp1
    st->print(", ");
    opnd_array(5)->ext_format(ra, this,idx5, st); // tmp2
    st->print(", ");
        tty->print("EBX");
  }
#endif
#ifndef PRODUCT
void string_indexofNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    unsigned idx5 = idx4 + opnd_array(4)->num_edges();
    st->print("String IndexOf ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // str1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // cnt1
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // str2
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // cnt2
    st->print(" -> ");
    opnd_array(0)->int_format(ra, this, st); // result
    st->print("   // KILL ");
        tty->print("ECX");
    st->print(", ");
    opnd_array(5)->ext_format(ra, this,idx5, st); // tmp1
  }
#endif
#ifndef PRODUCT
void array_equalsNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("Array Equals ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // ary1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // ary2
    st->print(" -> ");
    opnd_array(0)->int_format(ra, this, st); // result
    st->print("   // KILL ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp1
    st->print(", ");
    opnd_array(4)->ext_format(ra, this,idx4, st); // tmp2
    st->print(", ");
        tty->print("ECX");
    st->print(", ");
        tty->print("EBX");
  }
#endif
#ifndef PRODUCT
void compI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compI_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compI_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void testI_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void testI_reg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("TEST   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // con
  }
#endif
#ifndef PRODUCT
void testI_reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("TEST   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // mem
  }
#endif
#ifndef PRODUCT
void compU_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compU_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compU_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void testU_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TESTu  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void compP_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compP_eReg_immNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compP_eReg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void compP_mem_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMPu   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op1
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // op2
  }
#endif
#ifndef PRODUCT
void testP_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
  }
#endif
#ifndef PRODUCT
void testP_Reg_memNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // op
    st->print(",0xFFFFFFFF");
  }
#endif
#ifndef PRODUCT
void minI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MIN    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void maxI_eRegNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MAX    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // dst
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src
  }
#endif
#ifndef PRODUCT
void jumpXtndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("JMP    [table_base](,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // switch_val
    st->print(",1)\n\t");
  }
#endif
#ifndef PRODUCT
void jmpDirNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("JMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // labl
  }
#endif
#ifndef PRODUCT
void jmpConNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpLoopEndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print("    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\t# Loop end");
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpLoopEndUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\t# Loop end");
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpLoopEndUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\t# Loop end");
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpConUNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpConUCFNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpConUCF2Node::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    if (    opnd_array(1)->ccode()     == Assembler::notEqual) {
          st->print("JP,u   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\n\t");
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    } else {
          st->print("JP,u   done\n\t");
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\n\t");
    st->print("done:");
    }
      st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void partialSubtypeCheckNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("MOV    EDI,[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // sub
    st->print("+Klass::secondary_supers]\n\t");
    st->print("MOV    ECX,[EDI+arrayKlass::length]\t# length to scan\n\t");
    st->print("ADD    EDI,arrayKlass::base_offset\t# Skip to start of data; set NZ in case count is zero\n\t");
    st->print("REPNE SCASD\t# Scan *EDI++ for a match with EAX while CX-- != 0\n\t");
    st->print("JNE,s  miss\t\t# Missed: EDI not-zero\n\t");
    st->print("MOV    [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // sub
    st->print("+Klass::secondary_super_cache],");
    opnd_array(2)->ext_format(ra, this,idx2, st); // super
    st->print("\t# Hit: update cache\n\t");
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // result
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // result
    st->print("\t\t Hit: EDI zero\n\t");
    st->print("miss:\t");
  }
#endif
#ifndef PRODUCT
void partialSubtypeCheck_vs_ZeroNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MOV    EDI,[");
    opnd_array(1)->ext_format(ra, this,idx1, st); // sub
    st->print("+Klass::secondary_supers]\n\t");
    st->print("MOV    ECX,[EDI+arrayKlass::length]\t# length to scan\n\t");
    st->print("ADD    EDI,arrayKlass::base_offset\t# Skip to start of data; set NZ in case count is zero\n\t");
    st->print("REPNE SCASD\t# Scan *EDI++ for a match with EAX while CX-- != 0\n\t");
    st->print("JNE,s  miss\t\t# Missed: flags NZ\n\t");
    st->print("MOV    [");
    opnd_array(1)->ext_format(ra, this,idx1, st); // sub
    st->print("+Klass::secondary_super_cache],");
    opnd_array(2)->ext_format(ra, this,idx2, st); // super
    st->print("\t# Hit: update cache, flags Z\n\t");
    st->print("miss:\t");
  }
#endif
#ifndef PRODUCT
void jmpDir_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("JMP,s  ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // labl
  }
#endif
#ifndef PRODUCT
void jmpCon_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",s  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpLoopEnd_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",s  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\t# Loop end");
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpLoopEndU_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",us ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\t# Loop end");
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpLoopEndUCF_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",us ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\t# Loop end");
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpConU_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",us ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpConUCF_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",us ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void jmpConUCF2_shortNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    if (    opnd_array(1)->ccode()     == Assembler::notEqual) {
          st->print("JP,u,s   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\n\t");
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u,s   ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    } else {
          st->print("JP,u,s   done\n\t");
    st->print("J");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cop
    st->print(",u,s  ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // labl
    st->print("\n\t");
    st->print("done:");
    }
      st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void cmpL3_reg_regNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("XOR    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(",");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".hi\n\t");
    st->print("JLT,s  m_one\n\t");
    st->print("JGT,s  p_one\n\t");
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".lo\n\t");
    st->print("JB,s   m_one\n\t");
    st->print("JEQ,s  done\n");
    st->print("p_one:\tINC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n\t");
    st->print("JMP,s  done\n");
    st->print("m_one:\tDEC    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print("\n");
    st->print("done:");
  }
#endif
#ifndef PRODUCT
void cmpL_zero_flags_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("TEST   ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmpL_reg_flags_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".lo\t! Long compare; set flags for low bits\n\t");
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".hi\n\t");
    st->print("SBB    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".hi\t! Compute flags for long compare");
  }
#endif
#ifndef PRODUCT
void cmpL_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void cmovLL_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovLL_mem_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovII_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovII_mem_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovPP_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovDD_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovXDD_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovFF_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovXX_reg_LTGENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmpL_zero_flags_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("OR     ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\t! Long is EQ/NE 0?");
  }
#endif
#ifndef PRODUCT
void cmpL_reg_flags_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".lo,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".lo\t! Long compare; set flags for low bits\n\t");
    st->print("JNE,s  skip\n\t");
    st->print("CMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".hi,");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".hi\n\t");
    st->print("skip:\t");
  }
#endif
#ifndef PRODUCT
void cmpL_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void cmovLL_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovLL_mem_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovII_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovII_mem_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovPP_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovDD_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovXDD_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovFF_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovXX_reg_EQNENode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmpL_zero_flags_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("XOR    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print("\t# Long compare for -");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(" < 0, use commuted test\n\t");
    st->print("CMP    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".lo\n\t");
    st->print("SBB    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src
    st->print(".hi\n\t");
  }
#endif
#ifndef PRODUCT
void cmpL_reg_flags_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("CMP    ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".lo,");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".lo\t! Long compare, swapped operands, use with commuted test\n\t");
    st->print("MOV    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(2)->ext_format(ra, this,idx2, st); // src2
    st->print(".hi\n\t");
    st->print("SBB    ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(1)->ext_format(ra, this,idx1, st); // src1
    st->print(".hi\t! Compute flags for long compare");
  }
#endif
#ifndef PRODUCT
void cmpL_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("  P=%f C=%f",_prob,_fcnt);
  }
#endif
#ifndef PRODUCT
void cmovLL_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi");
  }
#endif
#ifndef PRODUCT
void cmovLL_mem_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".lo,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".lo\n\t");
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(".hi,");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
    st->print(".hi+4");
  }
#endif
#ifndef PRODUCT
void cmovII_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovII_mem_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovPP_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("CMOV");
    opnd_array(1)->ext_format(ra, this,idx1, st); // cmp
    st->print(" ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // dst
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // src
  }
#endif
#ifndef PRODUCT
void cmovDD_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovXDD_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovFF_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void cmovXX_reg_LEGTNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void CallStaticJavaDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("CALL,static ");
    if( _method ) _method->print_short_name(st); else st->print(" wrapper for: %s", _name);
    if( !_method ) dump_trap_args(st);
    st->print_cr("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void CallStaticJavaHandleNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("CALL,static/MethodHandle ");
    if( _method ) _method->print_short_name(st); else st->print(" wrapper for: %s", _name);
    if( !_method ) dump_trap_args(st);
    st->print_cr("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void CallDynamicJavaDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("MOV    EAX,(oop)-1\n\t");
    st->print("CALL,dynamic");
    _method->print_short_name();
    st->print_cr("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void CallRuntimeDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("CALL,runtime ");
    st->print(" %s", _name);    st->print_cr("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void CallLeafDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("CALL_LEAF,runtime ");
    st->print(" %s", _name);    st->print_cr("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void CallLeafNoFPDirectNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("CALL_LEAF_NOFP,runtime ");
    st->print(" %s", _name);    st->print_cr("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void RetNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("RET");
  }
#endif
#ifndef PRODUCT
void TailCalljmpIndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("JMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // jump_target
    st->print(" \t# EBX holds method oop");
  }
#endif
#ifndef PRODUCT
void tailjmpIndNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    st->print("POP    EDX\t# pop return address into dummy\n\t");
    st->print("JMP    ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // jump_target
    st->print(" ");
  }
#endif
#ifndef PRODUCT
void CreateExceptionNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("# exception oop is in EAX; no code emitted");
  }
#endif
#ifndef PRODUCT
void RethrowExceptionNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("JMP    rethrow_stub");
  }
#endif
#ifndef PRODUCT
void cmpFastLockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    st->print("FASTLOCK ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // object
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // box
    st->print(" KILLS ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
    st->print(",");
    opnd_array(4)->ext_format(ra, this,idx4, st); // scr
  }
#endif
#ifndef PRODUCT
void cmpFastUnlockNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    st->print("FASTUNLOCK ");
    opnd_array(1)->ext_format(ra, this,idx1, st); // object
    st->print(", ");
    opnd_array(2)->ext_format(ra, this,idx2, st); // box
    st->print(", ");
    opnd_array(3)->ext_format(ra, this,idx3, st); // tmp
  }
#endif
#ifndef PRODUCT
void safePoint_pollNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("TSTL   #polladdr,EAX\t! Safepoint: poll for GC");
    st->print("");
    if (_jvms) _jvms->format(ra, this, st); else st->print_cr("        No JVM State Info");
    st->print("        # ");
    if( _jvms ) _oop_map->print_on(st);
  }
#endif
#ifndef PRODUCT
void tlsLoadPNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    st->print("MOV    ");
    opnd_array(0)->int_format(ra, this, st); // dst
    st->print(", Thread::current()");
  }
#endif
#ifndef PRODUCT
void TLSNode::format(PhaseRegAlloc *ra, outputStream *st) const {
  }
#endif
#ifndef PRODUCT
void ShouldNotReachHereNode::format(PhaseRegAlloc *ra, outputStream *st) const {
    st->print("INT3   ; ShouldNotReachHere");
  }
#endif
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
