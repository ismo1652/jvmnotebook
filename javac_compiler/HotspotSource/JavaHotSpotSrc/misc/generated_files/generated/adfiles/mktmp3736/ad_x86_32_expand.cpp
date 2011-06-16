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
#include "incls/_ad_x86_32_expand.cpp.incl"


// Register masks, one for each register class.
const RegMask ANY_REG_mask( 0xff, 0x0, 0x0, 0x0 );
const RegMask E_REG_mask( 0x7f, 0x0, 0x0, 0x0 );
const RegMask STACK_OR_E_REG_mask( 0x7f, 0xfffffc00, 0xffffffff, 0xffffffff );
const RegMask E_REG_NO_RBP_mask( 0x7b, 0x0, 0x0, 0x0 );
const RegMask X_REG_mask( 0x33, 0x0, 0x0, 0x0 );
const RegMask STACK_OR_X_REG_mask( 0x33, 0xfffffc00, 0xffffffff, 0xffffffff );
const RegMask P_REG_mask( 0x6a, 0x0, 0x0, 0x0 );
const RegMask NCX_REG_mask( 0x7e, 0x0, 0x0, 0x0 );
const RegMask NAX_REG_mask( 0x6b, 0x0, 0x0, 0x0 );
const RegMask NABX_REG_mask( 0x6d, 0x0, 0x0, 0x0 );
const RegMask EAX_REG_mask( 0x10, 0x0, 0x0, 0x0 );
const RegMask EBX_REG_mask( 0x2, 0x0, 0x0, 0x0 );
const RegMask ECX_REG_mask( 0x1, 0x0, 0x0, 0x0 );
const RegMask EDX_REG_mask( 0x20, 0x0, 0x0, 0x0 );
const RegMask EDI_REG_mask( 0x8, 0x0, 0x0, 0x0 );
const RegMask ESI_REG_mask( 0x40, 0x0, 0x0, 0x0 );
const RegMask EBP_REG_mask( 0x4, 0x0, 0x0, 0x0 );
const RegMask SP_REG_mask( 0x80, 0x0, 0x0, 0x0 );
const RegMask INT_FLAGS_mask( 0x0, 0x100, 0x0, 0x0 );
const RegMask LONG_REG_mask( 0x3f, 0x0, 0x0, 0x0 );
const RegMask STACK_OR_LONG_REG_mask( 0x3f, 0xfffffc00, 0xffffffff, 0xffffffff );
const RegMask EADX_REG_mask( 0x30, 0x0, 0x0, 0x0 );
const RegMask EBCX_REG_mask( 0x3, 0x0, 0x0, 0x0 );
const RegMask NADX_REG_mask( 0x4f, 0x0, 0x0, 0x0 );
const RegMask FLT_REG_mask( 0x555400, 0x0, 0x0, 0x0 );
const RegMask STACK_OR_FLT_REG_mask( 0x555400, 0xfffffc00, 0xffffffff, 0xffffffff );
const RegMask XMM_REG_mask( 0x55000000, 0x55, 0x0, 0x0 );
const RegMask STACK_OR_XMM_REG_mask( 0x55000000, 0xfffffc55, 0xffffffff, 0xffffffff );
const RegMask XDB_REG_mask( 0xff000000, 0xff, 0x0, 0x0 );
const RegMask STACK_OR_XDB_REG_mask( 0xff000000, 0xfffffcff, 0xffffffff, 0xffffffff );
const RegMask DBL_REG_mask( 0xfffc00, 0x0, 0x0, 0x0 );
const RegMask STACK_OR_DBL_REG_mask( 0xfffc00, 0xfffffc00, 0xffffffff, 0xffffffff );
const RegMask FLT_REG0_mask( 0x400, 0x0, 0x0, 0x0 );
const RegMask DBL_REG0_mask( 0xc00, 0x0, 0x0, 0x0 );
const RegMask DBL_REG1_mask( 0x3000, 0x0, 0x0, 0x0 );
const RegMask DBL_NOTREG0_mask( 0xfff000, 0x0, 0x0, 0x0 );
const RegMask XDB_REG6_mask( 0x0, 0x30, 0x0, 0x0 );
const RegMask XDB_REG7_mask( 0x0, 0xc0, 0x0, 0x0 );
const RegMask STACK_SLOTS_mask( 0x0, 0x0, 0x0, 0x0 );
const RegMask STACK_OR_STACK_SLOTS_mask( 0x0, 0xfffffc00, 0xffffffff, 0xffffffff );
const RegMask INLINE_CACHE_REG_mask( 0x10, 0x0, 0x0, 0x0 );
const RegMask INTERPRETER_METHOD_OOP_REG_mask( 0x2, 0x0, 0x0, 0x0 );
const RegMask INTERPRETER_FRAME_POINTER_REG_mask( 0x4, 0x0, 0x0, 0x0 );
MachNode *countLeadingZerosINode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *countLeadingZerosI_bsrNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *countLeadingZerosLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *countLeadingZerosL_bsrNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *countTrailingZerosINode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *countTrailingZerosLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *popCountLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( EREGI, C ));
  // TEMP tmp
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *popCountL_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( EREGI, C ));
  // TEMP tmp
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadB2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadUB2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadUB2L_immI8Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadS2BNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *loadS2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadUS2BNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *loadUS2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadUS2L_immI_255Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadUS2L_immI16Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadI2BNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *loadI2SNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *loadI2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadI2L_immI_255Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadI2L_immI_65535Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadI2L_immINode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadUI2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadLX_volatileNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( REGXD, C ));

  return this;
}

MachNode *loadLX_reg_volatileNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( REGXD, C ));

  return this;
}

MachNode *loadConI0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadConLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadConL0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *storeL_volatileNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *storeLX_volatileNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( REGXD, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *storeLX_reg_volatileNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp2
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( REGXD, C ));
  // TEMP tmp
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(4, state->MachOperGenerator( REGXD, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *membar_volatileNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmovI_regUCFNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  cmovI_regUNode *n0 = new (C) cmovI_regUNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cop
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // cr
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovI_memUCFNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  if (mem == (Node*)1) {
    idx0--; // Adjust base because memory edge hasn't been inserted yet
  }
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  cmovI_memUNode *n0 = new (C) cmovI_memUNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  if (mem != (Node*)1) {
    n0->add_req(_in[1]);	// Add memory edge
  }
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cop
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // cr
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovP_regUCFNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  cmovP_regUNode *n0 = new (C) cmovP_regUNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGP, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cop
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // cr
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *fcmovX_regUCFNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovX_regUNode *n0 = new (C) fcmovX_regUNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGX, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cop
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // cr
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *fcmovXD_regUCFNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovXD_regUNode *n0 = new (C) fcmovXD_regUNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGXD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cop
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // cr
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovL_regUCFNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  cmovL_regUNode *n0 = new (C) cmovL_regUNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGL, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cop
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // cr
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *addI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *incI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *decI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addP_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addP_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addI_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addI_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addI_mem_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addI_mem_eReg_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addI_mem_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *incI_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *decI_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadLX_LockedNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( REGXD, C ));

  return this;
}

MachNode *loadLX_reg_LockedNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( REGXD, C ));

  return this;
}

MachNode *storeIConditionalNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL oldval
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *storeLConditionalNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL oldval
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EADX_REG_mask), Op_RegL );
  proj_list.push(kill);

  return this;
}

MachNode *compareAndSwapLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL oldval
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EADX_REG_mask), Op_RegL );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *compareAndSwapPNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL oldval
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *compareAndSwapINode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL oldval
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subI_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subI_mem_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subP_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *negI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *loadConL_low_onlyNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_imm_highNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_imm_high_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_imm_RShift_highNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_imm_RShift_high_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_mem_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulINode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI2LNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulI2L_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulIS_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  for(int i = idx5 - 1; i >= (int)idx4; i--) {
    del_req(i);
  }
  _num_opnds = 4;
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulIS_eReg_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  for(int i = idx5 - 1; i >= (int)idx4; i--) {
    del_req(i);
  }
  _num_opnds = 4;
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulL_eReg_lhi0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulL_eReg_rhi0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulL_eReg_hi0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *mulL_eReg_conNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *divI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rdx
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *divL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);
  // DEF/KILL cx
  kill = new (C, 1) MachProjNode( this, 2, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL bx
  kill = new (C, 1) MachProjNode( this, 3, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *divModI_eReg_divmodNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *modI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *modL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);
  // DEF/KILL cx
  kill = new (C, 1) MachProjNode( this, 2, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL bx
  kill = new (C, 1) MachProjNode( this, 3, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *shlI_eReg_1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *salI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *salI_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarI_eReg_1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarI_mem_1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // shift
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarI_mem_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // shift
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarI_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shrI_eReg_1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shrI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *i2bNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *i2sNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *shrI_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_mem_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_mem_eReg_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andI_mem_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_eReg_castP2XNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_eReg_castP2X_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_mem_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_mem_eReg_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orI_mem_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rolI_eReg_imm1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rolI_eReg_imm8Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rolI_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rolI_eReg_i1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rolI_eReg_imm1Node *n0 = new (C) rolI_eReg_imm1Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // lshift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_i1_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rolI_eReg_imm1Node *n0 = new (C) rolI_eReg_imm1Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(4)->clone(C)); // lshift
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_i8Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rolI_eReg_imm8Node *n0 = new (C) rolI_eReg_imm8Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // lshift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_i8_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rolI_eReg_imm8Node *n0 = new (C) rolI_eReg_imm8Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(4)->clone(C)); // lshift
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_Var_C0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rolI_eReg_CLNode *n0 = new (C) rolI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_Var_C0_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rolI_eReg_CLNode *n0 = new (C) rolI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(3)->clone(C)); // shift
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_Var_C32Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rolI_eReg_CLNode *n0 = new (C) rolI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rolI_eReg_Var_C32_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rolI_eReg_CLNode *n0 = new (C) rolI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(3)->clone(C)); // shift
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_imm1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rorI_eReg_imm8Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rorI_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *rorI_eReg_i1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rorI_eReg_imm1Node *n0 = new (C) rorI_eReg_imm1Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // rshift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_i1_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rorI_eReg_imm1Node *n0 = new (C) rorI_eReg_imm1Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(4)->clone(C)); // rshift
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_i8Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rorI_eReg_imm8Node *n0 = new (C) rorI_eReg_imm8Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // rshift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_i8_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  rorI_eReg_imm8Node *n0 = new (C) rorI_eReg_imm8Node();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(4)->clone(C)); // rshift
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_Var_C0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rorI_eReg_CLNode *n0 = new (C) rorI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_Var_C0_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rorI_eReg_CLNode *n0 = new (C) rorI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(3)->clone(C)); // shift
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_Var_C32Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rorI_eReg_CLNode *n0 = new (C) rorI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // shift
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *rorI_eReg_Var_C32_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  MachNode *tmp5 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  MachNode *result = NULL;

  rorI_eReg_CLNode *n0 = new (C) rorI_eReg_CLNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( NCXREGI, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // dst
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  tmp1 = n0;
  n0->set_opnd_array(2, opnd_array(3)->clone(C)); // shift
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *xorI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorI_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorI_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorI_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorI_mem_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorI_mem_eReg_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorI_mem_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *ci2bNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convI2BNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  movI_nocopyNode *n0 = new (C) movI_nocopyNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );

  ci2bNode *n1 = new (C) ci2bNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n1->set_opnd_array(1, opnd_array(0)->clone(C)); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n1->add_req(_in[i + idx0]);
    }
  }
  else n1->add_req(tmp0);
  tmp0 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone(C)); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  result = n1->Expand( state, proj_list, mem );


  return result;
}

MachNode *cp2bNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convP2BNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  movP_nocopyNode *n0 = new (C) movP_nocopyNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );

  cp2bNode *n1 = new (C) cp2bNode();
  n1->add_req(_in[0]);
  n1->set_opnd_array(0, state->MachOperGenerator( EREGI, C ));
  n1->set_opnd_array(1, opnd_array(0)->clone(C)); // dst
  if(tmp0 == this) {
    for(unsigned i = 0; i < num0; i++) {
      n1->add_req(_in[i + idx0]);
    }
  }
  else n1->add_req(tmp0);
  tmp0 = n1;
  n1->set_opnd_array(2, opnd_array(1)->clone(C)); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n1->add_req(_in[i + idx1]);
    }
  }
  else n1->add_req(tmp1);
  result = n1->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmpLTMaskNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpLTMask0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cadd_cmpLTMaskNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  for(int i = idx6 - 1; i >= (int)idx4; i--) {
    del_req(i);
  }
  _num_opnds = 4;
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cadd_cmpLTMask_1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  set_opnd_array(3, opnd_array(5)->clone(C)); // y
  for(unsigned i = 0; i < num5; i++) {
    set_req(i + idx3, _in[i + idx5]);
  }
  num3 = num5;
  idx4 = idx3 + num3;
  for(int i = idx6 - 1; i >= (int)idx4; i--) {
    del_req(i);
  }
  _num_opnds = 4;
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cadd_cmpLTMask_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  for(int i = idx6 - 1; i >= (int)idx4; i--) {
    del_req(i);
  }
  _num_opnds = 4;
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cadd_cmpLTMask_2Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned num5 = opnd_array(5)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  unsigned idx6 = idx5 + num5;
  for(int i = idx6 - 1; i >= (int)idx4; i--) {
    del_req(i);
  }
  _num_opnds = 4;
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addL_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addL_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addL_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subL_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *subL_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *negL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andL_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andL_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andL_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *andL_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orl_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orl_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orl_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *orl_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorl_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorl_eReg_immNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorl_eReg_memNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *xorl_eReg_mem_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shlL_eReg_1Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shlL_eReg_2Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shlL_eReg_3Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shlL_eReg_1_31Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shlL_eReg_32_63Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *salL_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shrL_eReg_1_31Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shrL_eReg_32_63Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *shrL_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarL_eReg_1_31Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarL_eReg_32_63Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sarL_eReg_CLNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpD_cc_P6Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpD_ccNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpD_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpXD_ccNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpXD_ccmemNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpXD_regmemNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *addD_mem_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  set_opnd_array(2, opnd_array(3)->clone(C)); // src
  for(unsigned i = 0; i < num3; i++) {
    set_req(i + idx2, _in[i + idx3]);
  }
  num2 = num3;
  idx3 = idx2 + num2;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *addD_mem_reg_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  for(int i = idx4 - 1; i >= (int)idx3; i--) {
    del_req(i);
  }
  _num_opnds = 3;

  return this;
}

MachNode *modD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *modXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *sinXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cosXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *tanXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *atanXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *powD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rbx
  kill = new (C, 1) MachProjNode( this, 2, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rcx
  kill = new (C, 1) MachProjNode( this, 3, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *powXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp1
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (DBL_REG0_mask), Op_RegD );
  proj_list.push(kill);
  // DEF/KILL rax
  kill = new (C, 1) MachProjNode( this, 2, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rbx
  kill = new (C, 1) MachProjNode( this, 3, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rcx
  kill = new (C, 1) MachProjNode( this, 4, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *expD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rbx
  kill = new (C, 1) MachProjNode( this, 2, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rcx
  kill = new (C, 1) MachProjNode( this, 3, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *expXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp1
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (DBL_REG0_mask), Op_RegD );
  proj_list.push(kill);
  // DEF/KILL rax
  kill = new (C, 1) MachProjNode( this, 2, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rbx
  kill = new (C, 1) MachProjNode( this, 3, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL rcx
  kill = new (C, 1) MachProjNode( this, 4, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *log10XD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *logXD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpF_cc_P6Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpF_ccNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpF_0Node::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpF_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpX_ccNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpX_ccmemNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);

  return this;
}

MachNode *cmpX_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpX_regmemNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *modF24_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *modF_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *modX_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rax
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convD2F_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  roundFloat_mem_regNode *n0 = new (C) roundFloat_mem_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( STACKSLOTF, C ));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *convD2X_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convF2D_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  MachNode *result = NULL;

  roundDouble_mem_regNode *n0 = new (C) roundDouble_mem_regNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( STACKSLOTD, C ));
  tmp0 = n0;
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // src
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *convX2D_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convD2I_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convXD2I_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convD2L_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convXD2L_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convF2I_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convX2I_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL tmp
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convF2L_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convX2L_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convI2L_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convI2L_reg_zexNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *zerox_longNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convL2D_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convL2XD_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convL2X_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *convL2F_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *MoveD2L_reg_reg_sseNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( REGXD, C ));

  return this;
}

MachNode *MoveL2D_reg_reg_sseNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP dst
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(2, state->MachOperGenerator( REGXD, C ));
  // TEMP tmp
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( REGXD, C ));

  return this;
}

MachNode *rep_stosNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cnt
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL base
  kill = new (C, 1) MachProjNode( this, 2, (EDI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL zero
  kill = new (C, 1) MachProjNode( this, 3, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 4, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *string_compareNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL str1
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL cnt1
  kill = new (C, 1) MachProjNode( this, 2, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL str2
  kill = new (C, 1) MachProjNode( this, 3, (ESI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL cnt2
  kill = new (C, 1) MachProjNode( this, 4, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // TEMP tmp1
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(5, state->MachOperGenerator( REGXD, C ));
  // TEMP tmp2
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(6, state->MachOperGenerator( REGXD, C ));
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 5, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *string_equalsNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL str1
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL str2
  kill = new (C, 1) MachProjNode( this, 2, (ESI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL cnt
  kill = new (C, 1) MachProjNode( this, 3, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // TEMP tmp1
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(4, state->MachOperGenerator( REGXD, C ));
  // TEMP tmp2
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(5, state->MachOperGenerator( REGXD, C ));
  // DEF/KILL tmp3
  kill = new (C, 1) MachProjNode( this, 4, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 5, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *string_indexofNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL str1
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL cnt1
  kill = new (C, 1) MachProjNode( this, 2, (EDX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL str2
  kill = new (C, 1) MachProjNode( this, 3, (ESI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL cnt2
  kill = new (C, 1) MachProjNode( this, 4, (EAX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // TEMP tmp1
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(5, state->MachOperGenerator( REGXD, C ));
  // DEF/KILL tmp2
  kill = new (C, 1) MachProjNode( this, 5, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 6, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *array_equalsNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL ary1
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (EDI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // DEF/KILL ary2
  kill = new (C, 1) MachProjNode( this, 2, (ESI_REG_mask), Op_RegP );
  proj_list.push(kill);
  // TEMP tmp1
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( REGXD, C ));
  // TEMP tmp2
  def = new (C) MachTempNode(state->MachOperGenerator( REGXD, C ));
  add_req(def);
  set_opnd_array(4, state->MachOperGenerator( REGXD, C ));
  // DEF/KILL tmp3
  kill = new (C, 1) MachProjNode( this, 3, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL tmp4
  kill = new (C, 1) MachProjNode( this, 4, (EBX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 5, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *minI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *maxI_eRegNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *partialSubtypeCheckNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rcx
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL cr
  kill = new (C, 1) MachProjNode( this, 2, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *partialSubtypeCheck_vs_ZeroNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL rcx
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (ECX_REG_mask), Op_RegI );
  proj_list.push(kill);
  // DEF/KILL result
  kill = new (C, 1) MachProjNode( this, 2, (EDI_REG_mask), Op_RegP );
  proj_list.push(kill);

  return this;
}

MachNode *cmpL3_reg_regNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL flags
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *cmpL_reg_flags_LTGENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));

  return this;
}

MachNode *cmpL_LTGENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  MachNode *result = NULL;

  jmpConNode *n0 = new (C) jmpConNode();
  n0->add_req(_in[0]);
  ((MachIfNode*)n0)->_prob = _prob;
  ((MachIfNode*)n0)->_fcnt = _fcnt;
  n0->set_opnd_array(0, state->MachOperGenerator( UNIVERSE, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // labl
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovDD_reg_LTGENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovD_regSNode *n0 = new (C) fcmovD_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovXDD_reg_LTGENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovXD_regSNode *n0 = new (C) fcmovXD_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGXD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovFF_reg_LTGENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovF_regSNode *n0 = new (C) fcmovF_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGF, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovXX_reg_LTGENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovX_regSNode *n0 = new (C) fcmovX_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGX, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmpL_zero_flags_EQNENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));

  return this;
}

MachNode *cmpL_EQNENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  MachNode *result = NULL;

  jmpConNode *n0 = new (C) jmpConNode();
  n0->add_req(_in[0]);
  ((MachIfNode*)n0)->_prob = _prob;
  ((MachIfNode*)n0)->_fcnt = _fcnt;
  n0->set_opnd_array(0, state->MachOperGenerator( UNIVERSE, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // labl
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovDD_reg_EQNENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovD_regSNode *n0 = new (C) fcmovD_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovXDD_reg_EQNENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovXD_regSNode *n0 = new (C) fcmovXD_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGXD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovFF_reg_EQNENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovF_regSNode *n0 = new (C) fcmovF_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGF, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovXX_reg_EQNENode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovX_regSNode *n0 = new (C) fcmovX_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGX, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmpL_zero_flags_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));

  return this;
}

MachNode *cmpL_reg_flags_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGI, C ));

  return this;
}

MachNode *cmpL_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  MachNode *result = NULL;

  jmpConNode *n0 = new (C) jmpConNode();
  n0->add_req(_in[0]);
  ((MachIfNode*)n0)->_prob = _prob;
  ((MachIfNode*)n0)->_fcnt = _fcnt;
  n0->set_opnd_array(0, state->MachOperGenerator( UNIVERSE, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // labl
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovDD_reg_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovD_regSNode *n0 = new (C) fcmovD_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovXDD_reg_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovXD_regSNode *n0 = new (C) fcmovXD_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGXD, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovFF_reg_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovF_regSNode *n0 = new (C) fcmovF_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGF, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmovXX_reg_LEGTNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  MachNode *tmp1 = this;
  MachNode *tmp2 = this;
  MachNode *tmp3 = this;
  MachNode *tmp4 = this;
  unsigned num0 = 0;
  unsigned num1 = opnd_array(1)->num_edges();
  unsigned num2 = opnd_array(2)->num_edges();
  unsigned num3 = opnd_array(3)->num_edges();
  unsigned num4 = opnd_array(4)->num_edges();
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  unsigned idx2 = idx1 + num1;
  unsigned idx3 = idx2 + num2;
  unsigned idx4 = idx3 + num3;
  unsigned idx5 = idx4 + num4;
  MachNode *result = NULL;

  fcmovX_regSNode *n0 = new (C) fcmovX_regSNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( REGX, C ));
  n0->set_opnd_array(1, opnd_array(1)->clone(C)); // cmp
  if(tmp1 == this) {
    for(unsigned i = 0; i < num1; i++) {
      n0->add_req(_in[i + idx1]);
    }
  }
  else n0->add_req(tmp1);
  n0->set_opnd_array(2, opnd_array(2)->clone(C)); // flags
  if(tmp2 == this) {
    for(unsigned i = 0; i < num2; i++) {
      n0->add_req(_in[i + idx2]);
    }
  }
  else n0->add_req(tmp2);
  n0->set_opnd_array(3, opnd_array(3)->clone(C)); // dst
  if(tmp3 == this) {
    for(unsigned i = 0; i < num3; i++) {
      n0->add_req(_in[i + idx3]);
    }
  }
  else n0->add_req(tmp3);
  tmp3 = n0;
  n0->set_opnd_array(4, opnd_array(4)->clone(C)); // src
  if(tmp4 == this) {
    for(unsigned i = 0; i < num4; i++) {
      n0->add_req(_in[i + idx4]);
    }
  }
  else n0->add_req(tmp4);
  result = n0->Expand( state, proj_list, mem );


  return result;
}

MachNode *cmpFastLockNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EAXREGI, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EAXREGI, C ));
  // TEMP scr
  def = new (C) MachTempNode(state->MachOperGenerator( EREGP, C ));
  add_req(def);
  set_opnd_array(4, state->MachOperGenerator( EREGP, C ));

  return this;
}

MachNode *cmpFastUnlockNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // TEMP tmp
  MachTempNode *def;
  def = new (C) MachTempNode(state->MachOperGenerator( EREGP, C ));
  add_req(def);
  set_opnd_array(3, state->MachOperGenerator( EREGP, C ));

  return this;
}

MachNode *safePoint_pollNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *tlsLoadPNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  // Add projection edges for additional defs or kills
  // DEF/KILL cr
  MachProjNode *kill;
  kill = new (C, 1) MachProjNode( this, 1, (INT_FLAGS_mask), Op_RegFlags );
  proj_list.push(kill);

  return this;
}

MachNode *TLSNode::Expand(State *state, Node_List &proj_list, Node* mem) {
Compile* C = Compile::current();
  MachNode *tmp0 = this;
  unsigned num0 = 0;
  unsigned idx0 = oper_input_base();
  unsigned idx1 = idx0 + num0;
  MachNode *result = NULL;

  tlsLoadPNode *n0 = new (C) tlsLoadPNode();
  n0->add_req(_in[0]);
  n0->set_opnd_array(0, state->MachOperGenerator( EREGP, C ));
  tmp0 = n0;
  result = n0->Expand( state, proj_list, mem );


  return result;
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
