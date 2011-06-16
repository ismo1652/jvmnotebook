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


// the number of reserved registers + machine registers.
#define REG_COUNT    41

// the number of save_on_entry + always_saved registers.
#define MAX_SAVED_ON_ENTRY_REG_COUNT    4
#define     SAVED_ON_ENTRY_REG_COUNT    0
#define   C_SAVED_ON_ENTRY_REG_COUNT    4

// Enumerate machine register numbers starting after reserved regs.
// in the order of occurrence in the register block.
enum MachRegisterNumbers {
  ECX_num,		// 0
  EBX_num,		// 1
  EBP_num,		// 2
  EDI_num,		// 3
  EAX_num,		// 4
  EDX_num,		// 5
  ESI_num,		// 6
  ESP_num,		// 7
  FPR0L_num,		// 8
  FPR0H_num,		// 9
  FPR1L_num,		// 10
  FPR1H_num,		// 11
  FPR2L_num,		// 12
  FPR2H_num,		// 13
  FPR3L_num,		// 14
  FPR3H_num,		// 15
  FPR4L_num,		// 16
  FPR4H_num,		// 17
  FPR5L_num,		// 18
  FPR5H_num,		// 19
  FPR6L_num,		// 20
  FPR6H_num,		// 21
  FPR7L_num,		// 22
  FPR7H_num,		// 23
  XMM0a_num,		// 24
  XMM0b_num,		// 25
  XMM1a_num,		// 26
  XMM1b_num,		// 27
  XMM2a_num,		// 28
  XMM2b_num,		// 29
  XMM3a_num,		// 30
  XMM3b_num,		// 31
  XMM4a_num,		// 32
  XMM4b_num,		// 33
  XMM5a_num,		// 34
  XMM5b_num,		// 35
  XMM6a_num,		// 36
  XMM6b_num,		// 37
  XMM7a_num,		// 38
  XMM7b_num,		// 39
  EFLAGS_num,		// 40
  _last_Mach_Reg	// 41
};

// Size of register-mask in ints
#define RM_SIZE 4
// Unroll factor for loops over the data in a RegMask
#define FORALL_BODY BODY(0) BODY(1) BODY(2) BODY(3) 

class RegMask;
