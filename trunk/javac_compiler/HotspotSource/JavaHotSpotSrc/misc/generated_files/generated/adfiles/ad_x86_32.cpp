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
#include "incls/_ad_x86_32.cpp.incl"


//SourceForm

#line 243 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

#define   RELOC_IMM32    Assembler::imm_operand
#define   RELOC_DISP32   Assembler::disp32_operand

#define __ _masm.

// How to find the high register of a Long pair, given the low register
#define   HIGH_FROM_LOW(x) ((x)+2)

// These masks are used to provide 128-bit aligned bitmasks to the XMM
// instructions, to allow sign-masking or sign-bit flipping.  They allow
// fast versions of NegF/NegD and AbsF/AbsD.

// Note: 'double' and 'long long' have 32-bits alignment on x86.
static jlong* double_quadword(jlong *adr, jlong lo, jlong hi) {
  // Use the expression (adr)&(~0xF) to provide 128-bits aligned address
  // of 128-bits operands for SSE instructions.
  jlong *operand = (jlong*)(((uintptr_t)adr)&((uintptr_t)(~0xF)));
  // Store the value to a 128-bits operand.
  operand[0] = lo;
  operand[1] = hi;
  return operand;
}

// Buffer for 128-bits masks used by SSE instructions.
static jlong fp_signmask_pool[(4+1)*2]; // 4*128bits(data) + 128bits(alignment)

// Static initialization during VM startup.
static jlong *float_signmask_pool  = double_quadword(&fp_signmask_pool[1*2], CONST64(0x7FFFFFFF7FFFFFFF), CONST64(0x7FFFFFFF7FFFFFFF));
static jlong *double_signmask_pool = double_quadword(&fp_signmask_pool[2*2], CONST64(0x7FFFFFFFFFFFFFFF), CONST64(0x7FFFFFFFFFFFFFFF));
static jlong *float_signflip_pool  = double_quadword(&fp_signmask_pool[3*2], CONST64(0x8000000080000000), CONST64(0x8000000080000000));
static jlong *double_signflip_pool = double_quadword(&fp_signmask_pool[4*2], CONST64(0x8000000000000000), CONST64(0x8000000000000000));

// Offset hacking within calls.
static int pre_call_FPU_size() {
  if (Compile::current()->in_24_bit_fp_mode())
    return 6; // fldcw
  return 0;
}

static int preserve_SP_size() {
  return LP64_ONLY(1 +) 2;  // [rex,] op, rm(reg/reg)
}

// !!!!! Special hack to get all type of calls to specify the byte offset
//       from the start of the call to the point where the return address
//       will point.
int MachCallStaticJavaNode::ret_addr_offset() {
  int offset = 5 + pre_call_FPU_size();  // 5 bytes from start of call to where return address points
  if (_method_handle_invoke)
    offset += preserve_SP_size();
  return offset;
}

int MachCallDynamicJavaNode::ret_addr_offset() {
  return 10 + pre_call_FPU_size();  // 10 bytes from start of call to where return address points
}

static int sizeof_FFree_Float_Stack_All = -1;

int MachCallRuntimeNode::ret_addr_offset() {
  assert(sizeof_FFree_Float_Stack_All != -1, "must have been emitted already");
  return sizeof_FFree_Float_Stack_All + 5 + pre_call_FPU_size();
}

// Indicate if the safepoint node needs the polling page as an input.
// Since x86 does have absolute addressing, it doesn't.
bool SafePointNode::needs_polling_address_input() {
  return false;
}

//
// Compute padding required for nodes which need alignment
//

// The address of the call instruction needs to be 4-byte aligned to
// ensure that it does not span a cache line so that it can be patched.
int CallStaticJavaDirectNode::compute_padding(int current_offset) const {
  current_offset += pre_call_FPU_size();  // skip fldcw, if any
  current_offset += 1;      // skip call opcode byte
  return round_to(current_offset, alignment_required()) - current_offset;
}

// The address of the call instruction needs to be 4-byte aligned to
// ensure that it does not span a cache line so that it can be patched.
int CallStaticJavaHandleNode::compute_padding(int current_offset) const {
  current_offset += pre_call_FPU_size();  // skip fldcw, if any
  current_offset += preserve_SP_size();   // skip mov rbp, rsp
  current_offset += 1;      // skip call opcode byte
  return round_to(current_offset, alignment_required()) - current_offset;
}

// The address of the call instruction needs to be 4-byte aligned to
// ensure that it does not span a cache line so that it can be patched.
int CallDynamicJavaDirectNode::compute_padding(int current_offset) const {
  current_offset += pre_call_FPU_size();  // skip fldcw, if any
  current_offset += 5;      // skip MOV instruction
  current_offset += 1;      // skip call opcode byte
  return round_to(current_offset, alignment_required()) - current_offset;
}

#ifndef PRODUCT
void MachBreakpointNode::format( PhaseRegAlloc *, outputStream* st ) const {
  st->print("INT3");
}
#endif

// EMIT_RM()
void emit_rm(CodeBuffer &cbuf, int f1, int f2, int f3) {
  unsigned char c = (unsigned char)((f1 << 6) | (f2 << 3) | f3);
  *(cbuf.code_end()) = c;
  cbuf.set_code_end(cbuf.code_end() + 1);
}

// EMIT_CC()
void emit_cc(CodeBuffer &cbuf, int f1, int f2) {
  unsigned char c = (unsigned char)( f1 | f2 );
  *(cbuf.code_end()) = c;
  cbuf.set_code_end(cbuf.code_end() + 1);
}

// EMIT_OPCODE()
void emit_opcode(CodeBuffer &cbuf, int code) {
  *(cbuf.code_end()) = (unsigned char)code;
  cbuf.set_code_end(cbuf.code_end() + 1);
}

// EMIT_OPCODE() w/ relocation information
void emit_opcode(CodeBuffer &cbuf, int code, relocInfo::relocType reloc, int offset = 0) {
  cbuf.relocate(cbuf.inst_mark() + offset, reloc);
  emit_opcode(cbuf, code);
}

// EMIT_D8()
void emit_d8(CodeBuffer &cbuf, int d8) {
  *(cbuf.code_end()) = (unsigned char)d8;
  cbuf.set_code_end(cbuf.code_end() + 1);
}

// EMIT_D16()
void emit_d16(CodeBuffer &cbuf, int d16) {
  *((short *)(cbuf.code_end())) = d16;
  cbuf.set_code_end(cbuf.code_end() + 2);
}

// EMIT_D32()
void emit_d32(CodeBuffer &cbuf, int d32) {
  *((int *)(cbuf.code_end())) = d32;
  cbuf.set_code_end(cbuf.code_end() + 4);
}

// emit 32 bit value and construct relocation entry from relocInfo::relocType
void emit_d32_reloc(CodeBuffer &cbuf, int d32, relocInfo::relocType reloc,
        int format) {
  cbuf.relocate(cbuf.inst_mark(), reloc, format);

  *((int *)(cbuf.code_end())) = d32;
  cbuf.set_code_end(cbuf.code_end() + 4);
}

// emit 32 bit value and construct relocation entry from RelocationHolder
void emit_d32_reloc(CodeBuffer &cbuf, int d32, RelocationHolder const& rspec,
        int format) {
#ifdef ASSERT
  if (rspec.reloc()->type() == relocInfo::oop_type && d32 != 0 && d32 != (int)Universe::non_oop_word()) {
    assert(oop(d32)->is_oop() && (ScavengeRootsInCode || !oop(d32)->is_scavengable()), "cannot embed scavengable oops in code");
  }
#endif
  cbuf.relocate(cbuf.inst_mark(), rspec, format);

  *((int *)(cbuf.code_end())) = d32;
  cbuf.set_code_end(cbuf.code_end() + 4);
}

// Access stack slot for load or store
void store_to_stackslot(CodeBuffer &cbuf, int opcode, int rm_field, int disp) {
  emit_opcode( cbuf, opcode );               // (e.g., FILD   [ESP+src])
  if( -128 <= disp && disp <= 127 ) {
    emit_rm( cbuf, 0x01, rm_field, ESP_enc );  // R/M byte
    emit_rm( cbuf, 0x00, ESP_enc, ESP_enc);    // SIB byte
    emit_d8 (cbuf, disp);     // Displacement  // R/M byte
  } else {
    emit_rm( cbuf, 0x02, rm_field, ESP_enc );  // R/M byte
    emit_rm( cbuf, 0x00, ESP_enc, ESP_enc);    // SIB byte
    emit_d32(cbuf, disp);     // Displacement  // R/M byte
  }
}

   // eRegI ereg, memory mem) %{    // emit_reg_mem
void encode_RegMem( CodeBuffer &cbuf, int reg_encoding, int base, int index, int scale, int displace, bool displace_is_oop ) {
  // There is no index & no scale, use form without SIB byte
  if ((index == 0x4) &&
      (scale == 0) && (base != ESP_enc)) {
    // If no displacement, mode is 0x0; unless base is [EBP]
    if ( (displace == 0) && (base != EBP_enc) ) {
      emit_rm(cbuf, 0x0, reg_encoding, base);
    }
    else {                    // If 8-bit displacement, mode 0x1
      if ((displace >= -128) && (displace <= 127)
          && !(displace_is_oop) ) {
        emit_rm(cbuf, 0x1, reg_encoding, base);
        emit_d8(cbuf, displace);
      }
      else {                  // If 32-bit displacement
        if (base == -1) { // Special flag for absolute address
          emit_rm(cbuf, 0x0, reg_encoding, 0x5);
          // (manual lies; no SIB needed here)
          if ( displace_is_oop ) {
            emit_d32_reloc(cbuf, displace, relocInfo::oop_type, 1);
          } else {
            emit_d32      (cbuf, displace);
          }
        }
        else {                // Normal base + offset
          emit_rm(cbuf, 0x2, reg_encoding, base);
          if ( displace_is_oop ) {
            emit_d32_reloc(cbuf, displace, relocInfo::oop_type, 1);
          } else {
            emit_d32      (cbuf, displace);
          }
        }
      }
    }
  }
  else {                      // Else, encode with the SIB byte
    // If no displacement, mode is 0x0; unless base is [EBP]
    if (displace == 0 && (base != EBP_enc)) {  // If no displacement
      emit_rm(cbuf, 0x0, reg_encoding, 0x4);
      emit_rm(cbuf, scale, index, base);
    }
    else {                    // If 8-bit displacement, mode 0x1
      if ((displace >= -128) && (displace <= 127)
          && !(displace_is_oop) ) {
        emit_rm(cbuf, 0x1, reg_encoding, 0x4);
        emit_rm(cbuf, scale, index, base);
        emit_d8(cbuf, displace);
      }
      else {                  // If 32-bit displacement
        if (base == 0x04 ) {
          emit_rm(cbuf, 0x2, reg_encoding, 0x4);
          emit_rm(cbuf, scale, index, 0x04);
        } else {
          emit_rm(cbuf, 0x2, reg_encoding, 0x4);
          emit_rm(cbuf, scale, index, base);
        }
        if ( displace_is_oop ) {
          emit_d32_reloc(cbuf, displace, relocInfo::oop_type, 1);
        } else {
          emit_d32      (cbuf, displace);
        }
      }
    }
  }
}


void encode_Copy( CodeBuffer &cbuf, int dst_encoding, int src_encoding ) {
  if( dst_encoding == src_encoding ) {
    // reg-reg copy, use an empty encoding
  } else {
    emit_opcode( cbuf, 0x8B );
    emit_rm(cbuf, 0x3, dst_encoding, src_encoding );
  }
}

void encode_CopyXD( CodeBuffer &cbuf, int dst_encoding, int src_encoding ) {
  if( dst_encoding == src_encoding ) {
    // reg-reg copy, use an empty encoding
  } else {
    MacroAssembler _masm(&cbuf);

    __ movdqa(as_XMMRegister(dst_encoding), as_XMMRegister(src_encoding));
  }
}


//=============================================================================
#ifndef PRODUCT
void MachPrologNode::format( PhaseRegAlloc *ra_, outputStream* st ) const {
  Compile* C = ra_->C;
  if( C->in_24_bit_fp_mode() ) {
    st->print("FLDCW  24 bit fpu control word");
    st->print_cr(""); st->print("\t");
  }

  int framesize = C->frame_slots() << LogBytesPerInt;
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  // Remove two words for return addr and rbp,
  framesize -= 2*wordSize;

  // Calls to C2R adapters often do not accept exceptional returns.
  // We require that their callers must bang for them.  But be careful, because
  // some VM calls (such as call site linkage) can use several kilobytes of
  // stack.  But the stack safety zone should account for that.
  // See bugs 4446381, 4468289, 4497237.
  if (C->need_stack_bang(framesize)) {
    st->print_cr("# stack bang"); st->print("\t");
  }
  st->print_cr("PUSHL  EBP"); st->print("\t");

  if( VerifyStackAtCalls ) { // Majik cookie to verify stack depth
    st->print("PUSH   0xBADB100D\t# Majik cookie for stack depth check");
    st->print_cr(""); st->print("\t");
    framesize -= wordSize;
  }

  if ((C->in_24_bit_fp_mode() || VerifyStackAtCalls ) && framesize < 128 ) {
    if (framesize) {
      st->print("SUB    ESP,%d\t# Create frame",framesize);
    }
  } else {
    st->print("SUB    ESP,%d\t# Create frame",framesize);
  }
}
#endif


void MachPrologNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  Compile* C = ra_->C;

  if (UseSSE >= 2 && VerifyFPU) {
    MacroAssembler masm(&cbuf);
    masm.verify_FPU(0, "FPU stack must be clean on entry");
  }

  // WARNING: Initial instruction MUST be 5 bytes or longer so that
  // NativeJump::patch_verified_entry will be able to patch out the entry
  // code safely. The fldcw is ok at 6 bytes, the push to verify stack
  // depth is ok at 5 bytes, the frame allocation can be either 3 or
  // 6 bytes. So if we don't do the fldcw or the push then we must
  // use the 6 byte frame allocation even if we have no frame. :-(
  // If method sets FPU control word do it now
  if( C->in_24_bit_fp_mode() ) {
    MacroAssembler masm(&cbuf);
    masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_24()));
  }

  int framesize = C->frame_slots() << LogBytesPerInt;
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  // Remove two words for return addr and rbp,
  framesize -= 2*wordSize;

  // Calls to C2R adapters often do not accept exceptional returns.
  // We require that their callers must bang for them.  But be careful, because
  // some VM calls (such as call site linkage) can use several kilobytes of
  // stack.  But the stack safety zone should account for that.
  // See bugs 4446381, 4468289, 4497237.
  if (C->need_stack_bang(framesize)) {
    MacroAssembler masm(&cbuf);
    masm.generate_stack_overflow_check(framesize);
  }

  // We always push rbp, so that on return to interpreter rbp, will be
  // restored correctly and we can correct the stack.
  emit_opcode(cbuf, 0x50 | EBP_enc);

  if( VerifyStackAtCalls ) { // Majik cookie to verify stack depth
    emit_opcode(cbuf, 0x68); // push 0xbadb100d
    emit_d32(cbuf, 0xbadb100d);
    framesize -= wordSize;
  }

  if ((C->in_24_bit_fp_mode() || VerifyStackAtCalls ) && framesize < 128 ) {
    if (framesize) {
      emit_opcode(cbuf, 0x83);   // sub  SP,#framesize
      emit_rm(cbuf, 0x3, 0x05, ESP_enc);
      emit_d8(cbuf, framesize);
    }
  } else {
    emit_opcode(cbuf, 0x81);   // sub  SP,#framesize
    emit_rm(cbuf, 0x3, 0x05, ESP_enc);
    emit_d32(cbuf, framesize);
  }
  C->set_frame_complete(cbuf.code_end() - cbuf.code_begin());

#ifdef ASSERT
  if (VerifyStackAtCalls) {
    Label L;
    MacroAssembler masm(&cbuf);
    masm.push(rax);
    masm.mov(rax, rsp);
    masm.andptr(rax, StackAlignmentInBytes-1);
    masm.cmpptr(rax, StackAlignmentInBytes-wordSize);
    masm.pop(rax);
    masm.jcc(Assembler::equal, L);
    masm.stop("Stack is not properly aligned!");
    masm.bind(L);
  }
#endif

}

uint MachPrologNode::size(PhaseRegAlloc *ra_) const {
  return MachNode::size(ra_); // too many variables; just compute it the hard way
}

int MachPrologNode::reloc() const {
  return 0; // a large enough number
}

//=============================================================================
#ifndef PRODUCT
void MachEpilogNode::format( PhaseRegAlloc *ra_, outputStream* st ) const {
  Compile *C = ra_->C;
  int framesize = C->frame_slots() << LogBytesPerInt;
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  // Remove two words for return addr and rbp,
  framesize -= 2*wordSize;

  if( C->in_24_bit_fp_mode() ) {
    st->print("FLDCW  standard control word");
    st->cr(); st->print("\t");
  }
  if( framesize ) {
    st->print("ADD    ESP,%d\t# Destroy frame",framesize);
    st->cr(); st->print("\t");
  }
  st->print_cr("POPL   EBP"); st->print("\t");
  if( do_polling() && C->is_method_compilation() ) {
    st->print("TEST   PollPage,EAX\t! Poll Safepoint");
    st->cr(); st->print("\t");
  }
}
#endif

void MachEpilogNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  Compile *C = ra_->C;

  // If method set FPU control word, restore to standard control word
  if( C->in_24_bit_fp_mode() ) {
    MacroAssembler masm(&cbuf);
    masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_std()));
  }

  int framesize = C->frame_slots() << LogBytesPerInt;
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  // Remove two words for return addr and rbp,
  framesize -= 2*wordSize;

  // Note that VerifyStackAtCalls' Majik cookie does not change the frame size popped here

  if( framesize >= 128 ) {
    emit_opcode(cbuf, 0x81); // add  SP, #framesize
    emit_rm(cbuf, 0x3, 0x00, ESP_enc);
    emit_d32(cbuf, framesize);
  }
  else if( framesize ) {
    emit_opcode(cbuf, 0x83); // add  SP, #framesize
    emit_rm(cbuf, 0x3, 0x00, ESP_enc);
    emit_d8(cbuf, framesize);
  }

  emit_opcode(cbuf, 0x58 | EBP_enc);

  if( do_polling() && C->is_method_compilation() ) {
    cbuf.relocate(cbuf.code_end(), relocInfo::poll_return_type, 0);
    emit_opcode(cbuf,0x85);
    emit_rm(cbuf, 0x0, EAX_enc, 0x5); // EAX
    emit_d32(cbuf, (intptr_t)os::get_polling_page());
  }
}

uint MachEpilogNode::size(PhaseRegAlloc *ra_) const {
  Compile *C = ra_->C;
  // If method set FPU control word, restore to standard control word
  int size = C->in_24_bit_fp_mode() ? 6 : 0;
  if( do_polling() && C->is_method_compilation() ) size += 6;

  int framesize = C->frame_slots() << LogBytesPerInt;
  assert((framesize & (StackAlignmentInBytes-1)) == 0, "frame size not aligned");
  // Remove two words for return addr and rbp,
  framesize -= 2*wordSize;

  size++; // popl rbp,

  if( framesize >= 128 ) {
    size += 6;
  } else {
    size += framesize ? 3 : 0;
  }
  return size;
}

int MachEpilogNode::reloc() const {
  return 0; // a large enough number
}

const Pipeline * MachEpilogNode::pipeline() const {
  return MachNode::pipeline_class();
}

int MachEpilogNode::safepoint_offset() const { return 0; }

//=============================================================================

enum RC { rc_bad, rc_int, rc_float, rc_xmm, rc_stack };
static enum RC rc_class( OptoReg::Name reg ) {

  if( !OptoReg::is_valid(reg)  ) return rc_bad;
  if (OptoReg::is_stack(reg)) return rc_stack;

  VMReg r = OptoReg::as_VMReg(reg);
  if (r->is_Register()) return rc_int;
  if (r->is_FloatRegister()) {
    assert(UseSSE < 2, "shouldn't be used in SSE2+ mode");
    return rc_float;
  }
  assert(r->is_XMMRegister(), "must be");
  return rc_xmm;
}

static int impl_helper( CodeBuffer *cbuf, bool do_size, bool is_load, int offset, int reg,
                        int opcode, const char *op_str, int size, outputStream* st ) {
  if( cbuf ) {
    emit_opcode  (*cbuf, opcode );
    encode_RegMem(*cbuf, Matcher::_regEncode[reg], ESP_enc, 0x4, 0, offset, false);
#ifndef PRODUCT
  } else if( !do_size ) {
    if( size != 0 ) st->print("\n\t");
    if( opcode == 0x8B || opcode == 0x89 ) { // MOV
      if( is_load ) st->print("%s   %s,[ESP + #%d]",op_str,Matcher::regName[reg],offset);
      else          st->print("%s   [ESP + #%d],%s",op_str,offset,Matcher::regName[reg]);
    } else { // FLD, FST, PUSH, POP
      st->print("%s [ESP + #%d]",op_str,offset);
    }
#endif
  }
  int offset_size = (offset == 0) ? 0 : ((offset <= 127) ? 1 : 4);
  return size+3+offset_size;
}

// Helper for XMM registers.  Extra opcode bits, limited syntax.
static int impl_x_helper( CodeBuffer *cbuf, bool do_size, bool is_load,
                         int offset, int reg_lo, int reg_hi, int size, outputStream* st ) {
  if( cbuf ) {
    if( reg_lo+1 == reg_hi ) { // double move?
      if( is_load && !UseXmmLoadAndClearUpper )
        emit_opcode(*cbuf, 0x66 ); // use 'movlpd' for load
      else
        emit_opcode(*cbuf, 0xF2 ); // use 'movsd' otherwise
    } else {
      emit_opcode(*cbuf, 0xF3 );
    }
    emit_opcode(*cbuf, 0x0F );
    if( reg_lo+1 == reg_hi && is_load && !UseXmmLoadAndClearUpper )
      emit_opcode(*cbuf, 0x12 );   // use 'movlpd' for load
    else
      emit_opcode(*cbuf, is_load ? 0x10 : 0x11 );
    encode_RegMem(*cbuf, Matcher::_regEncode[reg_lo], ESP_enc, 0x4, 0, offset, false);
#ifndef PRODUCT
  } else if( !do_size ) {
    if( size != 0 ) st->print("\n\t");
    if( reg_lo+1 == reg_hi ) { // double move?
      if( is_load ) st->print("%s %s,[ESP + #%d]",
                               UseXmmLoadAndClearUpper ? "MOVSD " : "MOVLPD",
                               Matcher::regName[reg_lo], offset);
      else          st->print("MOVSD  [ESP + #%d],%s",
                               offset, Matcher::regName[reg_lo]);
    } else {
      if( is_load ) st->print("MOVSS  %s,[ESP + #%d]",
                               Matcher::regName[reg_lo], offset);
      else          st->print("MOVSS  [ESP + #%d],%s",
                               offset, Matcher::regName[reg_lo]);
    }
#endif
  }
  int offset_size = (offset == 0) ? 0 : ((offset <= 127) ? 1 : 4);
  return size+5+offset_size;
}


static int impl_movx_helper( CodeBuffer *cbuf, bool do_size, int src_lo, int dst_lo,
                            int src_hi, int dst_hi, int size, outputStream* st ) {
  if( UseXmmRegToRegMoveAll ) {//Use movaps,movapd to move between xmm registers
    if( cbuf ) {
      if( (src_lo+1 == src_hi && dst_lo+1 == dst_hi) ) {
        emit_opcode(*cbuf, 0x66 );
      }
      emit_opcode(*cbuf, 0x0F );
      emit_opcode(*cbuf, 0x28 );
      emit_rm    (*cbuf, 0x3, Matcher::_regEncode[dst_lo], Matcher::_regEncode[src_lo] );
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      if( src_lo+1 == src_hi && dst_lo+1 == dst_hi ) { // double move?
        st->print("MOVAPD %s,%s",Matcher::regName[dst_lo],Matcher::regName[src_lo]);
      } else {
        st->print("MOVAPS %s,%s",Matcher::regName[dst_lo],Matcher::regName[src_lo]);
      }
#endif
    }
    return size + ((src_lo+1 == src_hi && dst_lo+1 == dst_hi) ? 4 : 3);
  } else {
    if( cbuf ) {
      emit_opcode(*cbuf, (src_lo+1 == src_hi && dst_lo+1 == dst_hi) ? 0xF2 : 0xF3 );
      emit_opcode(*cbuf, 0x0F );
      emit_opcode(*cbuf, 0x10 );
      emit_rm    (*cbuf, 0x3, Matcher::_regEncode[dst_lo], Matcher::_regEncode[src_lo] );
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      if( src_lo+1 == src_hi && dst_lo+1 == dst_hi ) { // double move?
        st->print("MOVSD  %s,%s",Matcher::regName[dst_lo],Matcher::regName[src_lo]);
      } else {
        st->print("MOVSS  %s,%s",Matcher::regName[dst_lo],Matcher::regName[src_lo]);
      }
#endif
    }
    return size+4;
  }
}

static int impl_movgpr2x_helper( CodeBuffer *cbuf, bool do_size, int src_lo, int dst_lo,
                            int src_hi, int dst_hi, int size, outputStream* st ) {
  // 32-bit
  if (cbuf) {
    emit_opcode(*cbuf, 0x66);
    emit_opcode(*cbuf, 0x0F);
    emit_opcode(*cbuf, 0x6E);
    emit_rm(*cbuf, 0x3, Matcher::_regEncode[dst_lo] & 7, Matcher::_regEncode[src_lo] & 7);
#ifndef PRODUCT
  } else if (!do_size) {
    st->print("movdl   %s, %s\t# spill", Matcher::regName[dst_lo], Matcher::regName[src_lo]);
#endif
  }
  return 4;
}


static int impl_movx2gpr_helper( CodeBuffer *cbuf, bool do_size, int src_lo, int dst_lo,
                                 int src_hi, int dst_hi, int size, outputStream* st ) {
  // 32-bit
  if (cbuf) {
    emit_opcode(*cbuf, 0x66);
    emit_opcode(*cbuf, 0x0F);
    emit_opcode(*cbuf, 0x7E);
    emit_rm(*cbuf, 0x3, Matcher::_regEncode[src_lo] & 7, Matcher::_regEncode[dst_lo] & 7);
#ifndef PRODUCT
  } else if (!do_size) {
    st->print("movdl   %s, %s\t# spill", Matcher::regName[dst_lo], Matcher::regName[src_lo]);
#endif
  }
  return 4;
}

static int impl_mov_helper( CodeBuffer *cbuf, bool do_size, int src, int dst, int size, outputStream* st ) {
  if( cbuf ) {
    emit_opcode(*cbuf, 0x8B );
    emit_rm    (*cbuf, 0x3, Matcher::_regEncode[dst], Matcher::_regEncode[src] );
#ifndef PRODUCT
  } else if( !do_size ) {
    if( size != 0 ) st->print("\n\t");
    st->print("MOV    %s,%s",Matcher::regName[dst],Matcher::regName[src]);
#endif
  }
  return size+2;
}

static int impl_fp_store_helper( CodeBuffer *cbuf, bool do_size, int src_lo, int src_hi, int dst_lo, int dst_hi,
                                 int offset, int size, outputStream* st ) {
  if( src_lo != FPR1L_num ) {      // Move value to top of FP stack, if not already there
    if( cbuf ) {
      emit_opcode( *cbuf, 0xD9 );  // FLD (i.e., push it)
      emit_d8( *cbuf, 0xC0-1+Matcher::_regEncode[src_lo] );
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      st->print("FLD    %s",Matcher::regName[src_lo]);
#endif
    }
    size += 2;
  }

  int st_op = (src_lo != FPR1L_num) ? EBX_num /*store & pop*/ : EDX_num /*store no pop*/;
  const char *op_str;
  int op;
  if( src_lo+1 == src_hi && dst_lo+1 == dst_hi ) { // double store?
    op_str = (src_lo != FPR1L_num) ? "FSTP_D" : "FST_D ";
    op = 0xDD;
  } else {                   // 32-bit store
    op_str = (src_lo != FPR1L_num) ? "FSTP_S" : "FST_S ";
    op = 0xD9;
    assert( !OptoReg::is_valid(src_hi) && !OptoReg::is_valid(dst_hi), "no non-adjacent float-stores" );
  }

  return impl_helper(cbuf,do_size,false,offset,st_op,op,op_str,size, st);
}

uint MachSpillCopyNode::implementation( CodeBuffer *cbuf, PhaseRegAlloc *ra_, bool do_size, outputStream* st ) const {
  // Get registers to move
  OptoReg::Name src_second = ra_->get_reg_second(in(1));
  OptoReg::Name src_first = ra_->get_reg_first(in(1));
  OptoReg::Name dst_second = ra_->get_reg_second(this );
  OptoReg::Name dst_first = ra_->get_reg_first(this );

  enum RC src_second_rc = rc_class(src_second);
  enum RC src_first_rc = rc_class(src_first);
  enum RC dst_second_rc = rc_class(dst_second);
  enum RC dst_first_rc = rc_class(dst_first);

  assert( OptoReg::is_valid(src_first) && OptoReg::is_valid(dst_first), "must move at least 1 register" );

  // Generate spill code!
  int size = 0;

  if( src_first == dst_first && src_second == dst_second )
    return size;            // Self copy, no move

  // --------------------------------------
  // Check for mem-mem move.  push/pop to move.
  if( src_first_rc == rc_stack && dst_first_rc == rc_stack ) {
    if( src_second == dst_first ) { // overlapping stack copy ranges
      assert( src_second_rc == rc_stack && dst_second_rc == rc_stack, "we only expect a stk-stk copy here" );
      size = impl_helper(cbuf,do_size,true ,ra_->reg2offset(src_second),ESI_num,0xFF,"PUSH  ",size, st);
      size = impl_helper(cbuf,do_size,false,ra_->reg2offset(dst_second),EAX_num,0x8F,"POP   ",size, st);
      src_second_rc = dst_second_rc = rc_bad;  // flag as already moved the second bits
    }
    // move low bits
    size = impl_helper(cbuf,do_size,true ,ra_->reg2offset(src_first),ESI_num,0xFF,"PUSH  ",size, st);
    size = impl_helper(cbuf,do_size,false,ra_->reg2offset(dst_first),EAX_num,0x8F,"POP   ",size, st);
    if( src_second_rc == rc_stack && dst_second_rc == rc_stack ) { // mov second bits
      size = impl_helper(cbuf,do_size,true ,ra_->reg2offset(src_second),ESI_num,0xFF,"PUSH  ",size, st);
      size = impl_helper(cbuf,do_size,false,ra_->reg2offset(dst_second),EAX_num,0x8F,"POP   ",size, st);
    }
    return size;
  }

  // --------------------------------------
  // Check for integer reg-reg copy
  if( src_first_rc == rc_int && dst_first_rc == rc_int )
    size = impl_mov_helper(cbuf,do_size,src_first,dst_first,size, st);

  // Check for integer store
  if( src_first_rc == rc_int && dst_first_rc == rc_stack )
    size = impl_helper(cbuf,do_size,false,ra_->reg2offset(dst_first),src_first,0x89,"MOV ",size, st);

  // Check for integer load
  if( dst_first_rc == rc_int && src_first_rc == rc_stack )
    size = impl_helper(cbuf,do_size,true ,ra_->reg2offset(src_first),dst_first,0x8B,"MOV ",size, st);

  // Check for integer reg-xmm reg copy
  if( src_first_rc == rc_int && dst_first_rc == rc_xmm ) {
    assert( (src_second_rc == rc_bad && dst_second_rc == rc_bad),
            "no 64 bit integer-float reg moves" );
    return impl_movgpr2x_helper(cbuf,do_size,src_first,dst_first,src_second, dst_second, size, st);
  }
  // --------------------------------------
  // Check for float reg-reg copy
  if( src_first_rc == rc_float && dst_first_rc == rc_float ) {
    assert( (src_second_rc == rc_bad && dst_second_rc == rc_bad) ||
            (src_first+1 == src_second && dst_first+1 == dst_second), "no non-adjacent float-moves" );
    if( cbuf ) {

      // Note the mucking with the register encode to compensate for the 0/1
      // indexing issue mentioned in a comment in the reg_def sections
      // for FPR registers many lines above here.

      if( src_first != FPR1L_num ) {
        emit_opcode  (*cbuf, 0xD9 );           // FLD    ST(i)
        emit_d8      (*cbuf, 0xC0+Matcher::_regEncode[src_first]-1 );
        emit_opcode  (*cbuf, 0xDD );           // FSTP   ST(i)
        emit_d8      (*cbuf, 0xD8+Matcher::_regEncode[dst_first] );
     } else {
        emit_opcode  (*cbuf, 0xDD );           // FST    ST(i)
        emit_d8      (*cbuf, 0xD0+Matcher::_regEncode[dst_first]-1 );
     }
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      if( src_first != FPR1L_num ) st->print("FLD    %s\n\tFSTP   %s",Matcher::regName[src_first],Matcher::regName[dst_first]);
      else                      st->print(             "FST    %s",                            Matcher::regName[dst_first]);
#endif
    }
    return size + ((src_first != FPR1L_num) ? 2+2 : 2);
  }

  // Check for float store
  if( src_first_rc == rc_float && dst_first_rc == rc_stack ) {
    return impl_fp_store_helper(cbuf,do_size,src_first,src_second,dst_first,dst_second,ra_->reg2offset(dst_first),size, st);
  }

  // Check for float load
  if( dst_first_rc == rc_float && src_first_rc == rc_stack ) {
    int offset = ra_->reg2offset(src_first);
    const char *op_str;
    int op;
    if( src_first+1 == src_second && dst_first+1 == dst_second ) { // double load?
      op_str = "FLD_D";
      op = 0xDD;
    } else {                   // 32-bit load
      op_str = "FLD_S";
      op = 0xD9;
      assert( src_second_rc == rc_bad && dst_second_rc == rc_bad, "no non-adjacent float-loads" );
    }
    if( cbuf ) {
      emit_opcode  (*cbuf, op );
      encode_RegMem(*cbuf, 0x0, ESP_enc, 0x4, 0, offset, false);
      emit_opcode  (*cbuf, 0xDD );           // FSTP   ST(i)
      emit_d8      (*cbuf, 0xD8+Matcher::_regEncode[dst_first] );
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      st->print("%s  ST,[ESP + #%d]\n\tFSTP   %s",op_str, offset,Matcher::regName[dst_first]);
#endif
    }
    int offset_size = (offset == 0) ? 0 : ((offset <= 127) ? 1 : 4);
    return size + 3+offset_size+2;
  }

  // Check for xmm reg-reg copy
  if( src_first_rc == rc_xmm && dst_first_rc == rc_xmm ) {
    assert( (src_second_rc == rc_bad && dst_second_rc == rc_bad) ||
            (src_first+1 == src_second && dst_first+1 == dst_second),
            "no non-adjacent float-moves" );
    return impl_movx_helper(cbuf,do_size,src_first,dst_first,src_second, dst_second, size, st);
  }

  // Check for xmm reg-integer reg copy
  if( src_first_rc == rc_xmm && dst_first_rc == rc_int ) {
    assert( (src_second_rc == rc_bad && dst_second_rc == rc_bad),
            "no 64 bit float-integer reg moves" );
    return impl_movx2gpr_helper(cbuf,do_size,src_first,dst_first,src_second, dst_second, size, st);
  }

  // Check for xmm store
  if( src_first_rc == rc_xmm && dst_first_rc == rc_stack ) {
    return impl_x_helper(cbuf,do_size,false,ra_->reg2offset(dst_first),src_first, src_second, size, st);
  }

  // Check for float xmm load
  if( dst_first_rc == rc_xmm && src_first_rc == rc_stack ) {
    return impl_x_helper(cbuf,do_size,true ,ra_->reg2offset(src_first),dst_first, dst_second, size, st);
  }

  // Copy from float reg to xmm reg
  if( dst_first_rc == rc_xmm && src_first_rc == rc_float ) {
    // copy to the top of stack from floating point reg
    // and use LEA to preserve flags
    if( cbuf ) {
      emit_opcode(*cbuf,0x8D);  // LEA  ESP,[ESP-8]
      emit_rm(*cbuf, 0x1, ESP_enc, 0x04);
      emit_rm(*cbuf, 0x0, 0x04, ESP_enc);
      emit_d8(*cbuf,0xF8);
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      st->print("LEA    ESP,[ESP-8]");
#endif
    }
    size += 4;

    size = impl_fp_store_helper(cbuf,do_size,src_first,src_second,dst_first,dst_second,0,size, st);

    // Copy from the temp memory to the xmm reg.
    size = impl_x_helper(cbuf,do_size,true ,0,dst_first, dst_second, size, st);

    if( cbuf ) {
      emit_opcode(*cbuf,0x8D);  // LEA  ESP,[ESP+8]
      emit_rm(*cbuf, 0x1, ESP_enc, 0x04);
      emit_rm(*cbuf, 0x0, 0x04, ESP_enc);
      emit_d8(*cbuf,0x08);
#ifndef PRODUCT
    } else if( !do_size ) {
      if( size != 0 ) st->print("\n\t");
      st->print("LEA    ESP,[ESP+8]");
#endif
    }
    size += 4;
    return size;
  }

  assert( size > 0, "missed a case" );

  // --------------------------------------------------------------------
  // Check for second bits still needing moving.
  if( src_second == dst_second )
    return size;               // Self copy; no move
  assert( src_second_rc != rc_bad && dst_second_rc != rc_bad, "src_second & dst_second cannot be Bad" );

  // Check for second word int-int move
  if( src_second_rc == rc_int && dst_second_rc == rc_int )
    return impl_mov_helper(cbuf,do_size,src_second,dst_second,size, st);

  // Check for second word integer store
  if( src_second_rc == rc_int && dst_second_rc == rc_stack )
    return impl_helper(cbuf,do_size,false,ra_->reg2offset(dst_second),src_second,0x89,"MOV ",size, st);

  // Check for second word integer load
  if( dst_second_rc == rc_int && src_second_rc == rc_stack )
    return impl_helper(cbuf,do_size,true ,ra_->reg2offset(src_second),dst_second,0x8B,"MOV ",size, st);


  Unimplemented();
}

#ifndef PRODUCT
void MachSpillCopyNode::format( PhaseRegAlloc *ra_, outputStream* st ) const {
  implementation( NULL, ra_, false, st );
}
#endif

void MachSpillCopyNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  implementation( &cbuf, ra_, false, NULL );
}

uint MachSpillCopyNode::size(PhaseRegAlloc *ra_) const {
  return implementation( NULL, ra_, true, NULL );
}

//=============================================================================
#ifndef PRODUCT
void MachNopNode::format( PhaseRegAlloc *, outputStream* st ) const {
  st->print("NOP \t# %d bytes pad for loops and calls", _count);
}
#endif

void MachNopNode::emit(CodeBuffer &cbuf, PhaseRegAlloc * ) const {
  MacroAssembler _masm(&cbuf);
  __ nop(_count);
}

uint MachNopNode::size(PhaseRegAlloc *) const {
  return _count;
}


//=============================================================================
#ifndef PRODUCT
void BoxLockNode::format( PhaseRegAlloc *ra_, outputStream* st ) const {
  int offset = ra_->reg2offset(in_RegMask(0).find_first_elem());
  int reg = ra_->get_reg_first(this);
  st->print("LEA    %s,[ESP + #%d]",Matcher::regName[reg],offset);
}
#endif

void BoxLockNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  int offset = ra_->reg2offset(in_RegMask(0).find_first_elem());
  int reg = ra_->get_encode(this);
  if( offset >= 128 ) {
    emit_opcode(cbuf, 0x8D);      // LEA  reg,[SP+offset]
    emit_rm(cbuf, 0x2, reg, 0x04);
    emit_rm(cbuf, 0x0, 0x04, ESP_enc);
    emit_d32(cbuf, offset);
  }
  else {
    emit_opcode(cbuf, 0x8D);      // LEA  reg,[SP+offset]
    emit_rm(cbuf, 0x1, reg, 0x04);
    emit_rm(cbuf, 0x0, 0x04, ESP_enc);
    emit_d8(cbuf, offset);
  }
}

uint BoxLockNode::size(PhaseRegAlloc *ra_) const {
  int offset = ra_->reg2offset(in_RegMask(0).find_first_elem());
  if( offset >= 128 ) {
    return 7;
  }
  else {
    return 4;
  }
}

//=============================================================================

// emit call stub, compiled java to interpreter
void emit_java_to_interp(CodeBuffer &cbuf ) {
  // Stub is fixed up when the corresponding call is converted from calling
  // compiled code to calling interpreted code.
  // mov rbx,0
  // jmp -1

  address mark = cbuf.inst_mark();  // get mark within main instrs section

  // Note that the code buffer's inst_mark is always relative to insts.
  // That's why we must use the macroassembler to generate a stub.
  MacroAssembler _masm(&cbuf);

  address base =
  __ start_a_stub(Compile::MAX_stubs_size);
  if (base == NULL)  return;  // CodeBuffer::expand failed
  // static stub relocation stores the instruction address of the call
  __ relocate(static_stub_Relocation::spec(mark), RELOC_IMM32);
  // static stub relocation also tags the methodOop in the code-stream.
  __ movoop(rbx, (jobject)NULL);  // method is zapped till fixup time
  // This is recognized as unresolved by relocs/nativeInst/ic code
  __ jump(RuntimeAddress(__ pc()));

  __ end_a_stub();
  // Update current stubs pointer and restore code_end.
}
// size of call stub, compiled java to interpretor
uint size_java_to_interp() {
  return 10;  // movl; jmp
}
// relocation entries for call stub, compiled java to interpretor
uint reloc_java_to_interp() {
  return 4;  // 3 in emit_java_to_interp + 1 in Java_Static_Call
}

//=============================================================================
#ifndef PRODUCT
void MachUEPNode::format( PhaseRegAlloc *ra_, outputStream* st ) const {
  st->print_cr(  "CMP    EAX,[ECX+4]\t# Inline cache check");
  st->print_cr("\tJNE    SharedRuntime::handle_ic_miss_stub");
  st->print_cr("\tNOP");
  st->print_cr("\tNOP");
  if( !OptoBreakpoint )
    st->print_cr("\tNOP");
}
#endif

void MachUEPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  MacroAssembler masm(&cbuf);
#ifdef ASSERT
  uint code_size = cbuf.code_size();
#endif
  masm.cmpptr(rax, Address(rcx, oopDesc::klass_offset_in_bytes()));
  masm.jump_cc(Assembler::notEqual,
               RuntimeAddress(SharedRuntime::get_ic_miss_stub()));
  /* WARNING these NOPs are critical so that verified entry point is properly
     aligned for patching by NativeJump::patch_verified_entry() */
  int nops_cnt = 2;
  if( !OptoBreakpoint ) // Leave space for int3
     nops_cnt += 1;
  masm.nop(nops_cnt);

  assert(cbuf.code_size() - code_size == size(ra_), "checking code size of inline cache node");
}

uint MachUEPNode::size(PhaseRegAlloc *ra_) const {
  return OptoBreakpoint ? 11 : 12;
}


//=============================================================================
uint size_exception_handler() {
  // NativeCall instruction size is the same as NativeJump.
  // exception handler starts out as jump and can be patched to
  // a call be deoptimization.  (4932387)
  // Note that this value is also credited (in output.cpp) to
  // the size of the code section.
  return NativeJump::instruction_size;
}

// Emit exception handler code.  Stuff framesize into a register
// and call a VM stub routine.
int emit_exception_handler(CodeBuffer& cbuf) {

  // Note that the code buffer's inst_mark is always relative to insts.
  // That's why we must use the macroassembler to generate a handler.
  MacroAssembler _masm(&cbuf);
  address base =
  __ start_a_stub(size_exception_handler());
  if (base == NULL)  return 0;  // CodeBuffer::expand failed
  int offset = __ offset();
  __ jump(RuntimeAddress(OptoRuntime::exception_blob()->instructions_begin()));
  assert(__ offset() - offset <= (int) size_exception_handler(), "overflow");
  __ end_a_stub();
  return offset;
}

uint size_deopt_handler() {
  // NativeCall instruction size is the same as NativeJump.
  // exception handler starts out as jump and can be patched to
  // a call be deoptimization.  (4932387)
  // Note that this value is also credited (in output.cpp) to
  // the size of the code section.
  return 5 + NativeJump::instruction_size; // pushl(); jmp;
}

// Emit deopt handler code.
int emit_deopt_handler(CodeBuffer& cbuf) {

  // Note that the code buffer's inst_mark is always relative to insts.
  // That's why we must use the macroassembler to generate a handler.
  MacroAssembler _masm(&cbuf);
  address base =
  __ start_a_stub(size_exception_handler());
  if (base == NULL)  return 0;  // CodeBuffer::expand failed
  int offset = __ offset();
  InternalAddress here(__ pc());
  __ pushptr(here.addr());

  __ jump(RuntimeAddress(SharedRuntime::deopt_blob()->unpack()));
  assert(__ offset() - offset <= (int) size_deopt_handler(), "overflow");
  __ end_a_stub();
  return offset;
}


static void emit_double_constant(CodeBuffer& cbuf, double x) {
  int mark = cbuf.insts()->mark_off();
  MacroAssembler _masm(&cbuf);
  address double_address = __ double_constant(x);
  cbuf.insts()->set_mark_off(mark);  // preserve mark across masm shift
  emit_d32_reloc(cbuf,
                 (int)double_address,
                 internal_word_Relocation::spec(double_address),
                 RELOC_DISP32);
}

static void emit_float_constant(CodeBuffer& cbuf, float x) {
  int mark = cbuf.insts()->mark_off();
  MacroAssembler _masm(&cbuf);
  address float_address = __ float_constant(x);
  cbuf.insts()->set_mark_off(mark);  // preserve mark across masm shift
  emit_d32_reloc(cbuf,
                 (int)float_address,
                 internal_word_Relocation::spec(float_address),
                 RELOC_DISP32);
}


const bool Matcher::match_rule_supported(int opcode) {
  if (!has_match_rule(opcode))
    return false;

  return true;  // Per default match rules are supported.
}

int Matcher::regnum_to_fpu_offset(int regnum) {
  return regnum - 32; // The FP registers are in the second chunk
}

bool is_positive_zero_float(jfloat f) {
  return jint_cast(f) == jint_cast(0.0F);
}

bool is_positive_one_float(jfloat f) {
  return jint_cast(f) == jint_cast(1.0F);
}

bool is_positive_zero_double(jdouble d) {
  return jlong_cast(d) == jlong_cast(0.0);
}

bool is_positive_one_double(jdouble d) {
  return jlong_cast(d) == jlong_cast(1.0);
}

// This is UltraSparc specific, true just means we have fast l2f conversion
const bool Matcher::convL2FSupported(void) {
  return true;
}

// Vector width in bytes
const uint Matcher::vector_width_in_bytes(void) {
  return UseSSE >= 2 ? 8 : 0;
}

// Vector ideal reg
const uint Matcher::vector_ideal_reg(void) {
  return Op_RegD;
}

// Is this branch offset short enough that a short branch can be used?
//
// NOTE: If the platform does not provide any short branch variants, then
//       this method should return false for offset 0.
bool Matcher::is_short_branch_offset(int rule, int offset) {
  // the short version of jmpConUCF2 contains multiple branches,
  // making the reach slightly less
  if (rule == jmpConUCF2_rule)
    return (-126 <= offset && offset <= 125);
  return (-128 <= offset && offset <= 127);
}

const bool Matcher::isSimpleConstant64(jlong value) {
  // Will one (StoreL ConL) be cheaper than two (StoreI ConI)?.
  return false;
}

// The ecx parameter to rep stos for the ClearArray node is in dwords.
const bool Matcher::init_array_count_is_in_bytes = false;

// Threshold size for cleararray.
const int Matcher::init_array_short_size = 8 * BytesPerLong;

// Should the Matcher clone shifts on addressing modes, expecting them to
// be subsumed into complex addressing expressions or compute them into
// registers?  True for Intel but false for most RISCs
const bool Matcher::clone_shift_expressions = true;

bool Matcher::narrow_oop_use_complex_address() {
  ShouldNotCallThis();
  return true;
}


// Is it better to copy float constants, or load them directly from memory?
// Intel can load a float constant from a direct address, requiring no
// extra registers.  Most RISCs will have to materialize an address into a
// register first, so they would do better to copy the constant from stack.
const bool Matcher::rematerialize_float_constants = true;

// If CPU can load and store mis-aligned doubles directly then no fixup is
// needed.  Else we split the double into 2 integer pieces and move it
// piece-by-piece.  Only happens when passing doubles into C code as the
// Java calling convention forces doubles to be aligned.
const bool Matcher::misaligned_doubles_ok = true;


void Matcher::pd_implicit_null_fixup(MachNode *node, uint idx) {
  // Get the memory operand from the node
  uint numopnds = node->num_opnds();        // Virtual call for number of operands
  uint skipped  = node->oper_input_base();  // Sum of leaves skipped so far
  assert( idx >= skipped, "idx too low in pd_implicit_null_fixup" );
  uint opcnt     = 1;                 // First operand
  uint num_edges = node->_opnds[1]->num_edges(); // leaves for first operand
  while( idx >= skipped+num_edges ) {
    skipped += num_edges;
    opcnt++;                          // Bump operand count
    assert( opcnt < numopnds, "Accessing non-existent operand" );
    num_edges = node->_opnds[opcnt]->num_edges(); // leaves for next operand
  }

  MachOper *memory = node->_opnds[opcnt];
  MachOper *new_memory = NULL;
  switch (memory->opcode()) {
  case DIRECT:
  case INDOFFSET32X:
    // No transformation necessary.
    return;
  case INDIRECT:
    new_memory = new (C) indirect_win95_safeOper( );
    break;
  case INDOFFSET8:
    new_memory = new (C) indOffset8_win95_safeOper(memory->disp(NULL, NULL, 0));
    break;
  case INDOFFSET32:
    new_memory = new (C) indOffset32_win95_safeOper(memory->disp(NULL, NULL, 0));
    break;
  case INDINDEXOFFSET:
    new_memory = new (C) indIndexOffset_win95_safeOper(memory->disp(NULL, NULL, 0));
    break;
  case INDINDEXSCALE:
    new_memory = new (C) indIndexScale_win95_safeOper(memory->scale());
    break;
  case INDINDEXSCALEOFFSET:
    new_memory = new (C) indIndexScaleOffset_win95_safeOper(memory->scale(), memory->disp(NULL, NULL, 0));
    break;
  case LOAD_LONG_INDIRECT:
  case LOAD_LONG_INDOFFSET32:
    // Does not use EBP as address register, use { EDX, EBX, EDI, ESI}
    return;
  default:
    assert(false, "unexpected memory operand in pd_implicit_null_fixup()");
    return;
  }
  node->_opnds[opcnt] = new_memory;
}

// Advertise here if the CPU requires explicit rounding operations
// to implement the UseStrictFP mode.
const bool Matcher::strict_fp_requires_explicit_rounding = true;

// Are floats conerted to double when stored to stack during deoptimization?
// On x32 it is stored with convertion only when FPU is used for floats.
bool Matcher::float_in_double() { return (UseSSE == 0); }

// Do ints take an entire long register or just half?
const bool Matcher::int_in_long = false;

// Return whether or not this register is ever used as an argument.  This
// function is used on startup to build the trampoline stubs in generateOptoStub.
// Registers not mentioned will be killed by the VM call in the trampoline, and
// arguments in those registers not be available to the callee.
bool Matcher::can_be_java_arg( int reg ) {
  if(  reg == ECX_num   || reg == EDX_num   ) return true;
  if( (reg == XMM0a_num || reg == XMM1a_num) && UseSSE>=1 ) return true;
  if( (reg == XMM0b_num || reg == XMM1b_num) && UseSSE>=2 ) return true;
  return false;
}

bool Matcher::is_spillable_arg( int reg ) {
  return can_be_java_arg(reg);
}

// Register for DIVI projection of divmodI
RegMask Matcher::divI_proj_mask() {
  return EAX_REG_mask;
}

// Register for MODI projection of divmodI
RegMask Matcher::modI_proj_mask() {
  return EDX_REG_mask;
}

// Register for DIVL projection of divmodL
RegMask Matcher::divL_proj_mask() {
  ShouldNotReachHere();
  return RegMask();
}

// Register for MODL projection of divmodL
RegMask Matcher::modL_proj_mask() {
  ShouldNotReachHere();
  return RegMask();
}

const RegMask Matcher::method_handle_invoke_SP_save_mask() {
  return EBP_REG_mask;
}

// Returns true if the high 32 bits of the value is known to be zero.
bool is_operand_hi32_zero(Node* n) {
  int opc = n->Opcode();
  if (opc == Op_LoadUI2L) {
    return true;
  }
  if (opc == Op_AndL) {
    Node* o2 = n->in(2);
    if (o2->is_Con() && (o2->get_long() & 0xFFFFFFFF00000000LL) == 0LL) {
      return true;
    }
  }
  return false;
}


#line 1356 "../generated/adfiles/ad_x86_32.cpp"


//SourceForm

#line 141 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/os_cpu/linux_x86/vm/linux_x86_32.ad"


// emit an interrupt that is caught by the debugger
void emit_break(CodeBuffer &cbuf) {

  // Debugger doesn't really catch this but best we can do so far QQQ
  MacroAssembler* masm = new MacroAssembler(&cbuf);
  masm->call(RuntimeAddress(CAST_FROM_FN_PTR(address, os::breakpoint)));
}

void MachBreakpointNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
  emit_break(cbuf);
}


uint MachBreakpointNode::size(PhaseRegAlloc *ra_) const {
  return 5;
}


#line 1382 "../generated/adfiles/ad_x86_32.cpp"


#ifndef PRODUCT
void Compile::adlc_verification() {

  // Following assertions generated from definition section
}
#endif

// Map from machine-independent register number to register_save_policy
const        char register_save_policy[] = {
  'C',
  'C',
  'N',
  'C',
  'C',
  'C',
  'C',
  'N',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C' // no trailing comma
};

// Map from machine-independent register number to c_reg_save_policy
const        char c_reg_save_policy[] = {
  'C',
  'E',
  'E',
  'E',
  'C',
  'C',
  'E',
  'N',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C',
  'C' // no trailing comma
};

// Map from machine-independent register number to register_save_type
const        int register_save_type[] = {
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegI,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  Op_RegF,
  0 // no trailing comma
};


const        int   reduceOp[] = {
  0, // 0
  0, // 1
  0, // 2
  0, // 3
  0, // 4
  0, // 5
  0, // 6
  0, // 7
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
  stackSlotI_rule, // 243
  stackSlotP_rule, // 244
  stackSlotL_rule, // 245
  eRegP_rule, // 246
  eRegP_rule, // 247
  eRegP_rule, // 248
  eRegP_rule, // 249
  eRegP_rule, // 250
  eRegI_rule, // 251
  eRegI_rule, // 252
  eRegP_rule, // 253
  eRegL_rule, // 254
  eRegL_rule, // 255
  regF_rule, // 256
  regX_rule, // 257
  regX_rule, // 258
  regD_rule, // 259
  regXD_rule, // 260
  regXD_rule, // 261
  eRegI_rule, // 262
  eRegL_rule, // 263
  eRegP_rule, // 264
  regF_rule, // 265
  regD_rule, // 266
  eADXRegL_low_only_rule, // 267
  eRegI_rule, // 268
  eRegI_rule, // 269
  Universe_rule, // 270
  eAXRegP_rule, // 271
  eRegI_rule, // 272
  eRegP_rule, // 273
  eRegP_rule, // 274
  eRegI_rule, // 275
  eFlagsReg_rule, // 276
  eFlagsReg_rule, // 277
  eFlagsReg_rule, // 278
  0, // 279
  0, // 280
  eFlagsRegU_rule, // 281
  eFlagsRegUCF_rule, // 282
  eFlagsRegU_rule, // 283
  eFlagsRegU_rule, // 284
  eFlagsRegUCF_rule, // 285
  eFlagsRegU_rule, // 286
  eFlagsRegUCF_rule, // 287
  regDPR1_rule, // 288
  regXD_rule, // 289
  regDPR1_rule, // 290
  regXD_rule, // 291
  eFlagsRegU_rule, // 292
  eFlagsRegUCF_rule, // 293
  eFlagsRegU_rule, // 294
  eFlagsRegU_rule, // 295
  eFlagsRegUCF_rule, // 296
  eFlagsRegU_rule, // 297
  eFlagsRegUCF_rule, // 298
  regFPR1_rule, // 299
  regX_rule, // 300
  regFPR1_rule, // 301
  regX_rule, // 302
  eRegI_rule, // 303
  eRegI_rule, // 304
  regF_rule, // 305
  regX_rule, // 306
  regX_rule, // 307
  eRegL_rule, // 308
  regD_rule, // 309
  regXD_rule, // 310
  regXD_rule, // 311
  eFlagsReg_rule, // 312
  eFlagsReg_rule, // 313
  eFlagsReg_rule, // 314
  eFlagsReg_rule, // 315
  eFlagsReg_rule, // 316
  eFlagsReg_rule, // 317
  eFlagsRegU_rule, // 318
  eFlagsRegU_rule, // 319
  eFlagsRegU_rule, // 320
  eFlagsRegU_rule, // 321
  eFlagsRegU_rule, // 322
  eFlagsRegU_rule, // 323
  eFlagsRegU_rule, // 324
  eFlagsRegU_rule, // 325
  eFlagsReg_rule, // 326
  eFlagsReg_rule, // 327
  eFlagsReg_rule, // 328
  flagsReg_long_LTGE_rule, // 329
  flagsReg_long_LTGE_rule, // 330
  flagsReg_long_EQNE_rule, // 331
  flagsReg_long_EQNE_rule, // 332
  flagsReg_long_LEGT_rule, // 333
  flagsReg_long_LEGT_rule, // 334
  eFlagsReg_rule, // 335
  eFlagsReg_rule, // 336
  Universe_rule, // 337
  eRegI_rule, // 338
  eRegL_rule, // 339
  eRegI_rule, // 340
  eRegI_rule, // 341
  eRegI_rule, // 342
  eRegI_rule, // 343
  eRegI_rule, // 344
  eRegI_rule, // 345
  eRegI_rule, // 346
  eRegI_rule, // 347
  eRegI_rule, // 348
  eRegI_rule, // 349
  xRegI_rule, // 350
  eRegL_rule, // 351
  xRegI_rule, // 352
  eRegL_rule, // 353
  eRegL_rule, // 354
  eRegI_rule, // 355
  eRegI_rule, // 356
  eRegL_rule, // 357
  eRegI_rule, // 358
  eRegI_rule, // 359
  eRegL_rule, // 360
  eRegL_rule, // 361
  eRegL_rule, // 362
  eRegI_rule, // 363
  eRegI_rule, // 364
  eRegI_rule, // 365
  eRegI_rule, // 366
  eRegI_rule, // 367
  eRegL_rule, // 368
  eRegL_rule, // 369
  eRegL_rule, // 370
  eRegL_rule, // 371
  eRegL_rule, // 372
  eRegL_rule, // 373
  stackSlotL_rule, // 374
  stackSlotL_rule, // 375
  eRegL_rule, // 376
  eRegI_rule, // 377
  eRegP_rule, // 378
  eRegP_rule, // 379
  regD_rule, // 380
  regXD_rule, // 381
  regXD_rule, // 382
  regX_rule, // 383
  regF_rule, // 384
  regXD_rule, // 385
  regXD_rule, // 386
  regXD_rule, // 387
  regXD_rule, // 388
  regXD_rule, // 389
  Universe_rule, // 390
  Universe_rule, // 391
  Universe_rule, // 392
  Universe_rule, // 393
  Universe_rule, // 394
  Universe_rule, // 395
  Universe_rule, // 396
  Universe_rule, // 397
  Universe_rule, // 398
  Universe_rule, // 399
  Universe_rule, // 400
  Universe_rule, // 401
  Universe_rule, // 402
  Universe_rule, // 403
  Universe_rule, // 404
  Universe_rule, // 405
  Universe_rule, // 406
  Universe_rule, // 407
  Universe_rule, // 408
  Universe_rule, // 409
  Universe_rule, // 410
  Universe_rule, // 411
  Universe_rule, // 412
  Universe_rule, // 413
  Universe_rule, // 414
  Universe_rule, // 415
  Universe_rule, // 416
  Universe_rule, // 417
  Universe_rule, // 418
  Universe_rule, // 419
  Universe_rule, // 420
  Universe_rule, // 421
  Universe_rule, // 422
  Universe_rule, // 423
  Universe_rule, // 424
  Universe_rule, // 425
  Universe_rule, // 426
  Universe_rule, // 427
  Universe_rule, // 428
  Universe_rule, // 429
  Universe_rule, // 430
  Universe_rule, // 431
  eRegI_rule, // 432
  eRegI_rule, // 433
  eRegI_rule, // 434
  eRegI_rule, // 435
  eRegI_rule, // 436
  eRegI_rule, // 437
  eRegP_rule, // 438
  eRegP_rule, // 439
  eRegP_rule, // 440
  eRegP_rule, // 441
  regDPR1_rule, // 442
  regFPR1_rule, // 443
  regD_rule, // 444
  regF_rule, // 445
  regX_rule, // 446
  regXD_rule, // 447
  regX_rule, // 448
  regX_rule, // 449
  regXD_rule, // 450
  regXD_rule, // 451
  eRegL_rule, // 452
  eRegL_rule, // 453
  eRegL_rule, // 454
  eRegI_rule, // 455
  eRegI_rule, // 456
  eRegI_rule, // 457
  eRegI_rule, // 458
  eRegP_rule, // 459
  eRegI_rule, // 460
  eRegP_rule, // 461
  eRegP_rule, // 462
  eRegI_rule, // 463
  eRegI_rule, // 464
  Universe_rule, // 465
  Universe_rule, // 466
  Universe_rule, // 467
  Universe_rule, // 468
  Universe_rule, // 469
  eRegP_rule, // 470
  stackSlotL_rule, // 471
  stackSlotL_rule, // 472
  eRegL_rule, // 473
  eRegI_rule, // 474
  eRegI_rule, // 475
  eRegI_rule, // 476
  eRegI_rule, // 477
  eRegI_rule, // 478
  eRegI_rule, // 479
  Universe_rule, // 480
  eRegP_rule, // 481
  eRegI_rule, // 482
  eRegI_rule, // 483
  eRegI_rule, // 484
  eDXRegI_rule, // 485
  eDXRegI_rule, // 486
  eDXRegI_rule, // 487
  eDXRegI_rule, // 488
  eRegI_rule, // 489
  eRegI_rule, // 490
  eRegI_rule, // 491
  eADXRegL_rule, // 492
  eADXRegL_rule, // 493
  eADXRegL_rule, // 494
  eADXRegL_rule, // 495
  eADXRegL_rule, // 496
  eADXRegL_rule, // 497
  eADXRegL_rule, // 498
  eADXRegL_rule, // 499
  eADXRegL_rule, // 500
  eAXRegI_rule, // 501
  eADXRegL_rule, // 502
  Universe_rule, // 503
  eDXRegI_rule, // 504
  eADXRegL_rule, // 505
  eRegI_rule, // 506
  eRegI_rule, // 507
  eRegI_rule, // 508
  eRegI_rule, // 509
  Universe_rule, // 510
  eRegI_rule, // 511
  Universe_rule, // 512
  eRegI_rule, // 513
  eRegI_rule, // 514
  eRegI_rule, // 515
  eRegI_rule, // 516
  eRegI_rule, // 517
  eRegI_rule, // 518
  eRegI_rule, // 519
  eRegI_rule, // 520
  eRegI_rule, // 521
  eRegI_rule, // 522
  Universe_rule, // 523
  Universe_rule, // 524
  Universe_rule, // 525
  eRegI_rule, // 526
  eRegI_rule, // 527
  eRegI_rule, // 528
  eRegI_rule, // 529
  eRegI_rule, // 530
  eRegI_rule, // 531
  Universe_rule, // 532
  Universe_rule, // 533
  Universe_rule, // 534
  0, // 535
  0, // 536
  0, // 537
  eRegI_rule, // 538
  eRegI_rule, // 539
  eRegI_rule, // 540
  eRegI_rule, // 541
  ncxRegI_rule, // 542
  ncxRegI_rule, // 543
  ncxRegI_rule, // 544
  ncxRegI_rule, // 545
  0, // 546
  0, // 547
  0, // 548
  eRegI_rule, // 549
  eRegI_rule, // 550
  eRegI_rule, // 551
  eRegI_rule, // 552
  ncxRegI_rule, // 553
  ncxRegI_rule, // 554
  ncxRegI_rule, // 555
  ncxRegI_rule, // 556
  eRegI_rule, // 557
  eRegI_rule, // 558
  eRegI_rule, // 559
  eRegI_rule, // 560
  eRegI_rule, // 561
  Universe_rule, // 562
  Universe_rule, // 563
  Universe_rule, // 564
  0, // 565
  eRegI_rule, // 566
  0, // 567
  eRegI_rule, // 568
  eCXRegI_rule, // 569
  eRegI_rule, // 570
  ncxRegI_rule, // 571
  ncxRegI_rule, // 572
  ncxRegI_rule, // 573
  ncxRegI_rule, // 574
  eRegL_rule, // 575
  eRegL_rule, // 576
  eRegL_rule, // 577
  eRegL_rule, // 578
  eRegL_rule, // 579
  eRegL_rule, // 580
  eRegL_rule, // 581
  eRegL_rule, // 582
  eRegL_rule, // 583
  eRegL_rule, // 584
  eRegL_rule, // 585
  eRegL_rule, // 586
  eRegL_rule, // 587
  eRegL_rule, // 588
  eRegL_rule, // 589
  eRegL_rule, // 590
  eRegL_rule, // 591
  eRegL_rule, // 592
  eRegL_rule, // 593
  eRegL_rule, // 594
  eRegL_rule, // 595
  eRegL_rule, // 596
  eRegL_rule, // 597
  eRegL_rule, // 598
  eRegL_rule, // 599
  eRegL_rule, // 600
  eRegL_rule, // 601
  eRegL_rule, // 602
  eRegL_rule, // 603
  eRegL_rule, // 604
  eRegL_rule, // 605
  eRegL_rule, // 606
  eRegL_rule, // 607
  eRegI_rule, // 608
  eRegI_rule, // 609
  eRegI_rule, // 610
  eRegI_rule, // 611
  regD_rule, // 612
  stackSlotD_rule, // 613
  regD_rule, // 614
  regD_rule, // 615
  stackSlotD_rule, // 616
  regD_rule, // 617
  regD_rule, // 618
  Universe_rule, // 619
  Universe_rule, // 620
  regD_rule, // 621
  regD_rule, // 622
  stackSlotD_rule, // 623
  regXD_rule, // 624
  regXD_rule, // 625
  regXD_rule, // 626
  regXD_rule, // 627
  regXD_rule, // 628
  regXD_rule, // 629
  regXD_rule, // 630
  regXD_rule, // 631
  regXD_rule, // 632
  regXD_rule, // 633
  regXD_rule, // 634
  regXD_rule, // 635
  regXD_rule, // 636
  regXD_rule, // 637
  regD_rule, // 638
  regDPR1_rule, // 639
  regD_rule, // 640
  regD_rule, // 641
  regD_rule, // 642
  regD_rule, // 643
  regD_rule, // 644
  regD_rule, // 645
  regD_rule, // 646
  regD_rule, // 647
  regD_rule, // 648
  regDPR1_rule, // 649
  stackSlotD_rule, // 650
  regD_rule, // 651
  regXD_rule, // 652
  regDPR1_rule, // 653
  regXD_rule, // 654
  regDPR1_rule, // 655
  regXD_rule, // 656
  regDPR1_rule, // 657
  regXD_rule, // 658
  regD_rule, // 659
  regXD_rule, // 660
  regD_rule, // 661
  regDPR1_rule, // 662
  regXD_rule, // 663
  regDPR1_rule, // 664
  regXD_rule, // 665
  regDPR1_rule, // 666
  regXD_rule, // 667
  regDPR1_rule, // 668
  regXD_rule, // 669
  eRegI_rule, // 670
  eRegI_rule, // 671
  eRegI_rule, // 672
  eRegI_rule, // 673
  stackSlotF_rule, // 674
  regF_rule, // 675
  stackSlotF_rule, // 676
  regF_rule, // 677
  regX_rule, // 678
  regX_rule, // 679
  regX_rule, // 680
  regX_rule, // 681
  regX_rule, // 682
  regX_rule, // 683
  regX_rule, // 684
  regX_rule, // 685
  regX_rule, // 686
  regX_rule, // 687
  regX_rule, // 688
  regX_rule, // 689
  regX_rule, // 690
  regX_rule, // 691
  regX_rule, // 692
  regX_rule, // 693
  regXD_rule, // 694
  regXD_rule, // 695
  stackSlotF_rule, // 696
  stackSlotF_rule, // 697
  regF_rule, // 698
  regF_rule, // 699
  stackSlotF_rule, // 700
  stackSlotF_rule, // 701
  stackSlotF_rule, // 702
  stackSlotF_rule, // 703
  stackSlotF_rule, // 704
  regF_rule, // 705
  stackSlotF_rule, // 706
  regF_rule, // 707
  stackSlotF_rule, // 708
  stackSlotF_rule, // 709
  regF_rule, // 710
  regF_rule, // 711
  stackSlotF_rule, // 712
  stackSlotF_rule, // 713
  regF_rule, // 714
  regF_rule, // 715
  regF_rule, // 716
  regF_rule, // 717
  regF_rule, // 718
  regF_rule, // 719
  regF_rule, // 720
  regF_rule, // 721
  regF_rule, // 722
  regF_rule, // 723
  stackSlotF_rule, // 724
  regF_rule, // 725
  stackSlotF_rule, // 726
  regF_rule, // 727
  regX_rule, // 728
  stackSlotF_rule, // 729
  stackSlotD_rule, // 730
  stackSlotF_rule, // 731
  regX_rule, // 732
  regX_rule, // 733
  regD_rule, // 734
  stackSlotD_rule, // 735
  regD_rule, // 736
  regXD_rule, // 737
  eAXRegI_rule, // 738
  eAXRegI_rule, // 739
  eADXRegL_rule, // 740
  eADXRegL_rule, // 741
  eAXRegI_rule, // 742
  eAXRegI_rule, // 743
  eADXRegL_rule, // 744
  eADXRegL_rule, // 745
  regD_rule, // 746
  regXD_rule, // 747
  regXD_rule, // 748
  regXD_rule, // 749
  regD_rule, // 750
  regF_rule, // 751
  stackSlotF_rule, // 752
  stackSlotF_rule, // 753
  regF_rule, // 754
  regF_rule, // 755
  regX_rule, // 756
  regX_rule, // 757
  eRegL_rule, // 758
  eRegL_rule, // 759
  eRegL_rule, // 760
  stackSlotD_rule, // 761
  regXD_rule, // 762
  regX_rule, // 763
  stackSlotF_rule, // 764
  eRegI_rule, // 765
  stackSlotI_rule, // 766
  stackSlotI_rule, // 767
  stackSlotF_rule, // 768
  stackSlotL_rule, // 769
  stackSlotL_rule, // 770
  eRegL_rule, // 771
  stackSlotD_rule, // 772
  regXD_rule, // 773
  regXD_rule, // 774
  regXD_rule, // 775
  regXD_rule, // 776
  regXD_rule, // 777
  regXD_rule, // 778
  regXD_rule, // 779
  regXD_rule, // 780
  regXD_rule, // 781
  regXD_rule, // 782
  regXD_rule, // 783
  regXD_rule, // 784
  regXD_rule, // 785
  regXD_rule, // 786
  regXD_rule, // 787
  regXD_rule, // 788
  Universe_rule, // 789
  eAXRegI_rule, // 790
  eAXRegI_rule, // 791
  eBXRegI_rule, // 792
  eAXRegI_rule, // 793
  eRegI_rule, // 794
  eRegI_rule, // 795
  Universe_rule, // 796
  Universe_rule, // 797
  Universe_rule, // 798
  Universe_rule, // 799
  Universe_rule, // 800
  Universe_rule, // 801
  Universe_rule, // 802
  Universe_rule, // 803
  Universe_rule, // 804
  eDIRegP_rule, // 805
  Universe_rule, // 806
  Universe_rule, // 807
  Universe_rule, // 808
  Universe_rule, // 809
  Universe_rule, // 810
  Universe_rule, // 811
  Universe_rule, // 812
  Universe_rule, // 813
  eSIRegI_rule, // 814
  Universe_rule, // 815
  eRegL_rule, // 816
  eRegL_rule, // 817
  eRegI_rule, // 818
  eRegI_rule, // 819
  eRegP_rule, // 820
  regD_rule, // 821
  regXD_rule, // 822
  regF_rule, // 823
  regX_rule, // 824
  Universe_rule, // 825
  eRegL_rule, // 826
  eRegL_rule, // 827
  eRegI_rule, // 828
  eRegI_rule, // 829
  eRegP_rule, // 830
  regD_rule, // 831
  regXD_rule, // 832
  regF_rule, // 833
  regX_rule, // 834
  Universe_rule, // 835
  eRegL_rule, // 836
  eRegL_rule, // 837
  eRegI_rule, // 838
  eRegI_rule, // 839
  eRegP_rule, // 840
  regD_rule, // 841
  regXD_rule, // 842
  regF_rule, // 843
  regX_rule, // 844
  Universe_rule, // 845
  Universe_rule, // 846
  Universe_rule, // 847
  Universe_rule, // 848
  Universe_rule, // 849
  Universe_rule, // 850
  Universe_rule, // 851
  Universe_rule, // 852
  Universe_rule, // 853
  eAXRegP_rule, // 854
  Universe_rule, // 855
  eRegP_rule, // 856
  eRegP_rule, // 857
  Universe_rule, // 858
  // last instruction
  0 // no trailing comma
};

const        int   leftOp[] = {
  0, // 0
  0, // 1
  0, // 2
  0, // 3
  0, // 4
  0, // 5
  0, // 6
  0, // 7
  0, // 8
  0, // 9
  0, // 10
  0, // 11
  0, // 12
  0, // 13
  0, // 14
  0, // 15
  0, // 16
  0, // 17
  0, // 18
  0, // 19
  0, // 20
  0, // 21
  0, // 22
  0, // 23
  0, // 24
  0, // 25
  0, // 26
  0, // 27
  0, // 28
  0, // 29
  0, // 30
  0, // 31
  0, // 32
  0, // 33
  0, // 34
  0, // 35
  0, // 36
  0, // 37
  0, // 38
  0, // 39
  0, // 40
  0, // 41
  0, // 42
  0, // 43
  0, // 44
  0, // 45
  0, // 46
  0, // 47
  0, // 48
  0, // 49
  0, // 50
  0, // 51
  0, // 52
  0, // 53
  0, // 54
  0, // 55
  0, // 56
  0, // 57
  0, // 58
  0, // 59
  0, // 60
  0, // 61
  0, // 62
  0, // 63
  0, // 64
  0, // 65
  0, // 66
  0, // 67
  0, // 68
  0, // 69
  0, // 70
  0, // 71
  0, // 72
  0, // 73
  0, // 74
  0, // 75
  0, // 76
  0, // 77
  0, // 78
  0, // 79
  0, // 80
  0, // 81
  0, // 82
  0, // 83
  0, // 84
  0, // 85
  0, // 86
  eRegP_rule, // 87
  eRegP_rule, // 88
  immP_rule, // 89
  _AddP_eRegP_eRegI_rule, // 90
  eRegP_rule, // 91
  eRegP_rule, // 92
  _AddP_eRegP__LShiftI_eRegI_immI2_rule, // 93
  0, // 94
  0, // 95
  load_long_RegP_rule, // 96
  0, // 97
  0, // 98
  0, // 99
  0, // 100
  0, // 101
  0, // 102
  eRegP_no_EBP_rule, // 103
  eRegP_no_EBP_rule, // 104
  _AddP_eRegP_no_EBP_eRegI_rule, // 105
  eRegP_no_EBP_rule, // 106
  _AddP_eRegP_no_EBP__LShiftI_eRegI_immI2_rule, // 107
  0, // 108
  0, // 109
  0, // 110
  0, // 111
  0, // 112
  0, // 113
  // last operand
  0, // 114
  0, // 115
  0, // 116
  // last operand class
  eRegP_rule, // 117
  eRegI_rule, // 118
  eRegP_rule, // 119
  eRegP_no_EBP_rule, // 120
  eRegP_no_EBP_rule, // 121
  memory_rule, // 122
  memory_rule, // 123
  memory_rule, // 124
  memory_rule, // 125
  _LoadUB_memory__rule, // 126
  memory_rule, // 127
  _LoadS_memory__rule, // 128
  memory_rule, // 129
  _LoadUS_memory__rule, // 130
  _LoadUS_memory__rule, // 131
  _LoadUS_memory__rule, // 132
  _LoadI_memory__rule, // 133
  _LoadI_memory__rule, // 134
  _LoadI_memory__rule, // 135
  _LoadI_memory__rule, // 136
  _LoadI_memory__rule, // 137
  eRegL_rule, // 138
  regDPR1_rule, // 139
  regFPR1_rule, // 140
  regDPR1_rule, // 141
  cmpOp_rule, // 142
  eRegI_rule, // 143
  cmpOpU_rule, // 144
  cmpOpUCF_rule, // 145
  eRegI_rule, // 146
  eRegP_rule, // 147
  cmpOp_fcmov_rule, // 148
  regDPR1_rule, // 149
  regFPR1_rule, // 150
  regD_rule, // 151
  regF_rule, // 152
  regX_rule, // 153
  regXD_rule, // 154
  eRegL_rule, // 155
  _LoadI_memory__rule, // 156
  eRegI_rule, // 157
  _LoadI_memory__rule, // 158
  _LoadI_memory__rule, // 159
  _LoadI_memory__rule, // 160
  eAXRegP_rule, // 161
  eAXRegI_rule, // 162
  eADXRegL_rule, // 163
  eAXRegP_rule, // 164
  eAXRegI_rule, // 165
  _LoadI_memory__rule, // 166
  immI0_rule, // 167
  nadxRegI_rule, // 168
  _ConvI2L_nadxRegI__rule, // 169
  _MulL__ConvI2L_nadxRegI__eADXRegL_low_only_rule, // 170
  eADXRegL_low_only_rule, // 171
  _MulL_eADXRegL_low_only__ConvI2L_nadxRegI__rule, // 172
  _MulL__ConvI2L_nadxRegI__eADXRegL_low_only_rule, // 173
  _MulL_eADXRegL_low_only__ConvI2L_nadxRegI__rule, // 174
  eAXRegI_rule, // 175
  _ConvI2L_eAXRegI__rule, // 176
  _ConvI2L_nadxRegI__rule, // 177
  _LoadI_memory__rule, // 178
  _LoadI_memory__rule, // 179
  xRegI_rule, // 180
  xRegI_rule, // 181
  _LoadI_memory__rule, // 182
  eRegI_rule, // 183
  eRegP_rule, // 184
  _LoadI_memory__rule, // 185
  eRegI_rule, // 186
  _LoadI_memory__rule, // 187
  eRegI_rule, // 188
  eRegI_rule, // 189
  eRegI_rule, // 190
  eRegI_rule, // 191
  ncxRegI_rule, // 192
  immI0_rule, // 193
  ncxRegI_rule, // 194
  immI_32_rule, // 195
  ncxRegI_rule, // 196
  eRegI_rule, // 197
  eRegI_rule, // 198
  ncxRegI_rule, // 199
  ncxRegI_rule, // 200
  ncxRegI_rule, // 201
  _LoadI_memory__rule, // 202
  eRegI_rule, // 203
  _LoadI_memory__rule, // 204
  ncxRegI_rule, // 205
  _CmpLTMask_ncxRegI_ncxRegI_rule, // 206
  ncxRegI_rule, // 207
  ncxRegI_rule, // 208
  load_long_memory_rule, // 209
  memory_rule, // 210
  regD_rule, // 211
  regD_rule, // 212
  _LoadD_memory__rule, // 213
  _AddD__LoadD_memory__regD_rule, // 214
  regD_rule, // 215
  _AddD_regD__LoadD_memory__rule, // 216
  regD_rule, // 217
  regD_rule, // 218
  regD_rule, // 219
  memory_rule, // 220
  regX_rule, // 221
  _ConvF2D_regX__rule, // 222
  _LoadF_memory__rule, // 223
  _ConvF2D__LoadF_memory___rule, // 224
  _LoadF_memory__rule, // 225
  regF_rule, // 226
  regF_rule, // 227
  regF_rule, // 228
  eRegI_rule, // 229
  eDIRegP_rule, // 230
  eSIRegP_rule, // 231
  eDIRegP_rule, // 232
  eDIRegP_rule, // 233
  eSIRegP_rule, // 234
  eRegI_rule, // 235
  eRegI_rule, // 236
  memory_rule, // 237
  eSIRegP_rule, // 238
  cmpOp_rule, // 239
  eRegL_rule, // 240
  cmpOp_rule, // 241
  cmpOp_commute_rule, // 242
  // last internally defined operand
  eRegI_rule, // 243
  eRegP_rule, // 244
  eRegL_rule, // 245
  indOffset8_rule, // 246
  indOffset32_rule, // 247
  indIndexOffset_rule, // 248
  indIndexScale_rule, // 249
  indIndexScaleOffset_rule, // 250
  immI_rule, // 251
  immI0_rule, // 252
  immP_rule, // 253
  immL_rule, // 254
  immL0_rule, // 255
  immF_rule, // 256
  immXF_rule, // 257
  immXF0_rule, // 258
  immD_rule, // 259
  immXD_rule, // 260
  immXD0_rule, // 261
  stackSlotI_rule, // 262
  stackSlotL_rule, // 263
  stackSlotP_rule, // 264
  stackSlotF_rule, // 265
  stackSlotD_rule, // 266
  immL32_rule, // 267
  eRegI_rule, // 268
  _LoadI_memory__rule, // 269
  0, // 270
  eAXRegI_rule, // 271
  eRegP_rule, // 272
  eRegP_rule, // 273
  eRegP_rule, // 274
  eRegI_rule, // 275
  memory_rule, // 276
  memory_rule, // 277
  memory_rule, // 278
  0, // 279
  0, // 280
  regD_rule, // 281
  regD_rule, // 282
  regD_rule, // 283
  regXD_rule, // 284
  regXD_rule, // 285
  regXD_rule, // 286
  regXD_rule, // 287
  regDPR1_rule, // 288
  regXD_rule, // 289
  regDPR1_rule, // 290
  regXD_rule, // 291
  regF_rule, // 292
  regF_rule, // 293
  regF_rule, // 294
  regX_rule, // 295
  regX_rule, // 296
  regX_rule, // 297
  regX_rule, // 298
  regFPR1_rule, // 299
  regX_rule, // 300
  regFPR1_rule, // 301
  regX_rule, // 302
  stackSlotF_rule, // 303
  regX_rule, // 304
  stackSlotI_rule, // 305
  stackSlotI_rule, // 306
  eRegI_rule, // 307
  stackSlotD_rule, // 308
  stackSlotL_rule, // 309
  stackSlotL_rule, // 310
  stackSlotL_rule, // 311
  eRegI_rule, // 312
  eRegI_rule, // 313
  eRegI_rule, // 314
  eRegI_rule, // 315
  _AndI_eRegI_immI_rule, // 316
  _AndI_eRegI_memory_rule, // 317
  eRegI_rule, // 318
  eRegI_rule, // 319
  eRegI_rule, // 320
  eRegI_rule, // 321
  eRegP_rule, // 322
  eRegP_rule, // 323
  eRegP_rule, // 324
  eRegP_rule, // 325
  eRegP_rule, // 326
  _LoadP_memory__rule, // 327
  _PartialSubtypeCheck_eSIRegP_eAXRegP_rule, // 328
  eRegL_rule, // 329
  eRegL_rule, // 330
  eRegL_rule, // 331
  eRegL_rule, // 332
  eRegL_rule, // 333
  eRegL_rule, // 334
  eRegP_rule, // 335
  eRegP_rule, // 336
  0, // 337
  eRegI_rule, // 338
  eRegL_rule, // 339
  eRegI_rule, // 340
  eRegI_rule, // 341
  eRegI_rule, // 342
  eRegI_rule, // 343
  eRegL_rule, // 344
  eRegL_rule, // 345
  eRegI_rule, // 346
  eRegL_rule, // 347
  eRegL_rule, // 348
  _LoadL_memory__rule, // 349
  memory_rule, // 350
  _LoadB_memory__rule, // 351
  memory_rule, // 352
  _LoadUB_memory__rule, // 353
  _AndI__LoadUB_memory__immI8_rule, // 354
  memory_rule, // 355
  _LShiftI__LoadS_memory__immI_24_rule, // 356
  _LoadS_memory__rule, // 357
  memory_rule, // 358
  _LShiftI__LoadUS_memory__immI_24_rule, // 359
  _LoadUS_memory__rule, // 360
  _AndI__LoadUS_memory__immI_255_rule, // 361
  _AndI__LoadUS_memory__immI16_rule, // 362
  memory_rule, // 363
  _LShiftI__LoadI_memory__immI_24_rule, // 364
  _LoadI_memory__rule, // 365
  _LShiftI__LoadI_memory__immI_16_rule, // 366
  _LoadI_memory__rule, // 367
  _LoadI_memory__rule, // 368
  _AndI__LoadI_memory__immI_255_rule, // 369
  _AndI__LoadI_memory__immI_65535_rule, // 370
  _AndI__LoadI_memory__immI_rule, // 371
  memory_rule, // 372
  load_long_memory_rule, // 373
  memory_rule, // 374
  memory_rule, // 375
  memory_rule, // 376
  memory_rule, // 377
  memory_rule, // 378
  memory_rule, // 379
  memory_rule, // 380
  memory_rule, // 381
  memory_rule, // 382
  memory_rule, // 383
  memory_rule, // 384
  memory_rule, // 385
  memory_rule, // 386
  memory_rule, // 387
  memory_rule, // 388
  memory_rule, // 389
  memory_rule, // 390
  memory_rule, // 391
  memory_rule, // 392
  memory_rule, // 393
  memory_rule, // 394
  memory_rule, // 395
  memory_rule, // 396
  memory_rule, // 397
  memory_rule, // 398
  memory_rule, // 399
  memory_rule, // 400
  memory_rule, // 401
  memory_rule, // 402
  long_memory_rule, // 403
  memory_rule, // 404
  memory_rule, // 405
  memory_rule, // 406
  memory_rule, // 407
  memory_rule, // 408
  memory_rule, // 409
  memory_rule, // 410
  memory_rule, // 411
  memory_rule, // 412
  memory_rule, // 413
  memory_rule, // 414
  memory_rule, // 415
  memory_rule, // 416
  memory_rule, // 417
  memory_rule, // 418
  memory_rule, // 419
  memory_rule, // 420
  memory_rule, // 421
  memory_rule, // 422
  memory_rule, // 423
  memory_rule, // 424
  memory_rule, // 425
  memory_rule, // 426
  0, // 427
  0, // 428
  0, // 429
  0, // 430
  0, // 431
  _Binary_cmpOp_eFlagsReg_rule, // 432
  _Binary_cmpOpU_eFlagsRegU_rule, // 433
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 434
  _Binary_cmpOp_eFlagsReg_rule, // 435
  _Binary_cmpOpU_eFlagsRegU_rule, // 436
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 437
  _Binary_cmpOp_eFlagsReg_rule, // 438
  _Binary_cmpOp_eFlagsReg_rule, // 439
  _Binary_cmpOpU_eFlagsRegU_rule, // 440
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 441
  _Binary_cmpOp_fcmov_eFlagsRegU_rule, // 442
  _Binary_cmpOp_fcmov_eFlagsRegU_rule, // 443
  _Binary_cmpOp_eFlagsReg_rule, // 444
  _Binary_cmpOp_eFlagsReg_rule, // 445
  _Binary_cmpOp_eFlagsReg_rule, // 446
  _Binary_cmpOp_eFlagsReg_rule, // 447
  _Binary_cmpOpU_eFlagsRegU_rule, // 448
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 449
  _Binary_cmpOpU_eFlagsRegU_rule, // 450
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 451
  _Binary_cmpOp_eFlagsReg_rule, // 452
  _Binary_cmpOpU_eFlagsRegU_rule, // 453
  _Binary_cmpOpUCF_eFlagsRegUCF_rule, // 454
  eRegI_rule, // 455
  eRegI_rule, // 456
  eRegI_rule, // 457
  eRegI_rule, // 458
  eRegP_rule, // 459
  eRegI_rule, // 460
  eRegP_rule, // 461
  eRegP_rule, // 462
  eRegI_rule, // 463
  _LoadI_memory__rule, // 464
  memory_rule, // 465
  memory_rule, // 466
  memory_rule, // 467
  memory_rule, // 468
  memory_rule, // 469
  memory_rule, // 470
  load_long_memory_rule, // 471
  load_long_memory_rule, // 472
  load_long_memory_rule, // 473
  eSIRegP_rule, // 474
  pRegP_rule, // 475
  pRegP_rule, // 476
  eRegI_rule, // 477
  eRegI_rule, // 478
  eRegI_rule, // 479
  memory_rule, // 480
  eRegP_rule, // 481
  immI0_rule, // 482
  eRegI_rule, // 483
  eRegI_rule, // 484
  _RShiftL__MulL__ConvI2L_nadxRegI__eADXRegL_low_only_immI_32_rule, // 485
  _RShiftL__MulL_eADXRegL_low_only__ConvI2L_nadxRegI__immI_32_rule, // 486
  _RShiftL__MulL__ConvI2L_nadxRegI__eADXRegL_low_only_immI_32_63_rule, // 487
  _RShiftL__MulL_eADXRegL_low_only__ConvI2L_nadxRegI__immI_32_63_rule, // 488
  _LoadI_memory__rule, // 489
  eRegI_rule, // 490
  _LoadI_memory__rule, // 491
  _ConvI2L_eAXRegI__rule, // 492
  _ConvI2L_nadxRegI__rule, // 493
  _AndL__ConvI2L_eAXRegI__immL_32bits_rule, // 494
  _AndL__ConvI2L_nadxRegI__immL_32bits_rule, // 495
  eADXRegL_rule, // 496
  eADXRegL_rule, // 497
  eADXRegL_rule, // 498
  eADXRegL_rule, // 499
  eADXRegL_rule, // 500
  eAXRegI_rule, // 501
  eRegL_rule, // 502
  eAXRegI_rule, // 503
  eAXRegI_rule, // 504
  eRegL_rule, // 505
  eRegI_rule, // 506
  eRegI_rule, // 507
  eRegI_rule, // 508
  eRegI_rule, // 509
  memory_rule, // 510
  eRegI_rule, // 511
  memory_rule, // 512
  eRegI_rule, // 513
  eRegI_rule, // 514
  eRegI_rule, // 515
  _LShiftI_xRegI_immI_24_rule, // 516
  _LShiftI_xRegI_immI_16_rule, // 517
  eRegI_rule, // 518
  eRegI_rule, // 519
  eRegI_rule, // 520
  eRegI_rule, // 521
  _LoadI_memory__rule, // 522
  memory_rule, // 523
  memory_rule, // 524
  memory_rule, // 525
  eRegI_rule, // 526
  eRegI_rule, // 527
  _CastP2X_eRegP__rule, // 528
  eRegI_rule, // 529
  eRegI_rule, // 530
  _LoadI_memory__rule, // 531
  memory_rule, // 532
  memory_rule, // 533
  memory_rule, // 534
  0, // 535
  0, // 536
  0, // 537
  _LShiftI_eRegI_immI1_rule, // 538
  _URShiftI_eRegI_immI_M1_rule, // 539
  _LShiftI_eRegI_immI8_rule, // 540
  _URShiftI_eRegI_immI8_rule, // 541
  _LShiftI_ncxRegI_eCXRegI_rule, // 542
  _URShiftI_ncxRegI__SubI_immI0_eCXRegI_rule, // 543
  _LShiftI_ncxRegI_eCXRegI_rule, // 544
  _URShiftI_ncxRegI__SubI_immI_32_eCXRegI_rule, // 545
  0, // 546
  0, // 547
  0, // 548
  _URShiftI_eRegI_immI1_rule, // 549
  _LShiftI_eRegI_immI_M1_rule, // 550
  _URShiftI_eRegI_immI8_rule, // 551
  _LShiftI_eRegI_immI8_rule, // 552
  _URShiftI_ncxRegI_eCXRegI_rule, // 553
  _LShiftI_ncxRegI__SubI_immI0_eCXRegI_rule, // 554
  _URShiftI_ncxRegI_eCXRegI_rule, // 555
  _LShiftI_ncxRegI__SubI_immI_32_eCXRegI_rule, // 556
  eRegI_rule, // 557
  eRegI_rule, // 558
  eRegI_rule, // 559
  eRegI_rule, // 560
  _LoadI_memory__rule, // 561
  memory_rule, // 562
  memory_rule, // 563
  memory_rule, // 564
  0, // 565
  eRegI_rule, // 566
  0, // 567
  eRegP_rule, // 568
  ncxRegI_rule, // 569
  eRegI_rule, // 570
  _AndI__CmpLTMask_ncxRegI_ncxRegI_ncxRegI_rule, // 571
  _SubI_ncxRegI_ncxRegI_rule, // 572
  _AndI_ncxRegI__CmpLTMask_ncxRegI_ncxRegI_rule, // 573
  _SubI_ncxRegI_ncxRegI_rule, // 574
  eRegL_rule, // 575
  eRegL_rule, // 576
  eRegL_rule, // 577
  _LoadL_load_long_memory__rule, // 578
  eRegL_rule, // 579
  eRegL_rule, // 580
  eRegL_rule, // 581
  immL0_rule, // 582
  eRegL_rule, // 583
  eRegL_rule, // 584
  eRegL_rule, // 585
  _LoadL_load_long_memory__rule, // 586
  eRegL_rule, // 587
  eRegL_rule, // 588
  eRegL_rule, // 589
  _LoadL_load_long_memory__rule, // 590
  eRegL_rule, // 591
  eRegL_rule, // 592
  eRegL_rule, // 593
  eRegL_rule, // 594
  _LoadL_load_long_memory__rule, // 595
  eRegL_rule, // 596
  eRegL_rule, // 597
  eRegL_rule, // 598
  eRegL_rule, // 599
  eRegL_rule, // 600
  eRegL_rule, // 601
  eRegL_rule, // 602
  eRegL_rule, // 603
  eRegL_rule, // 604
  eRegL_rule, // 605
  eRegL_rule, // 606
  eRegL_rule, // 607
  regD_rule, // 608
  regD_rule, // 609
  regXD_rule, // 610
  regXD_rule, // 611
  regD_rule, // 612
  _SubD_regD_regD_rule, // 613
  regD_rule, // 614
  regD_rule, // 615
  _AddD_regD_regD_rule, // 616
  regD_rule, // 617
  _LoadD_memory__rule, // 618
  memory_rule, // 619
  memory_rule, // 620
  regD_rule, // 621
  regD_rule, // 622
  _AddD_regD_immD_rule, // 623
  regXD_rule, // 624
  regXD_rule, // 625
  regXD_rule, // 626
  _LoadD_memory__rule, // 627
  regXD_rule, // 628
  regXD_rule, // 629
  regXD_rule, // 630
  regXD_rule, // 631
  regXD_rule, // 632
  regXD_rule, // 633
  _LoadD_memory__rule, // 634
  regXD_rule, // 635
  regXD_rule, // 636
  regXD_rule, // 637
  regD_rule, // 638
  regDPR1_rule, // 639
  regD_rule, // 640
  regD_rule, // 641
  _LoadD_memory__rule, // 642
  regD_rule, // 643
  _LoadD_memory__rule, // 644
  _MulD_regD_regD_rule, // 645
  regD_rule, // 646
  _MulD_regD_regD_rule, // 647
  regD_rule, // 648
  regDPR1_rule, // 649
  _DivD_regD_regD_rule, // 650
  regD_rule, // 651
  regXD_rule, // 652
  regDPR1_rule, // 653
  regXD_rule, // 654
  regDPR1_rule, // 655
  regXD_rule, // 656
  regDPR1_rule, // 657
  regXD_rule, // 658
  regD_rule, // 659
  regXD_rule, // 660
  regD_rule, // 661
  regD_rule, // 662
  regXD_rule, // 663
  regDPR1_rule, // 664
  regXD_rule, // 665
  regDPR1_rule, // 666
  regXD_rule, // 667
  regDPR1_rule, // 668
  regXD_rule, // 669
  regF_rule, // 670
  regF_rule, // 671
  regX_rule, // 672
  regX_rule, // 673
  regF_rule, // 674
  regF_rule, // 675
  regF_rule, // 676
  regF_rule, // 677
  regX_rule, // 678
  regX_rule, // 679
  regX_rule, // 680
  _LoadF_memory__rule, // 681
  regX_rule, // 682
  regX_rule, // 683
  regX_rule, // 684
  regX_rule, // 685
  regX_rule, // 686
  regX_rule, // 687
  _LoadF_memory__rule, // 688
  regX_rule, // 689
  regX_rule, // 690
  regX_rule, // 691
  _SqrtD__ConvF2D_regX___rule, // 692
  _SqrtD__ConvF2D__LoadF_memory____rule, // 693
  regXD_rule, // 694
  _LoadD_memory__rule, // 695
  regF_rule, // 696
  _LoadF_memory__rule, // 697
  regF_rule, // 698
  _LoadF_memory__rule, // 699
  memory_rule, // 700
  memory_rule, // 701
  _LoadF_memory__rule, // 702
  memory_rule, // 703
  regF_rule, // 704
  regF_rule, // 705
  regF_rule, // 706
  regF_rule, // 707
  regF_rule, // 708
  _LoadF_memory__rule, // 709
  regF_rule, // 710
  _LoadF_memory__rule, // 711
  memory_rule, // 712
  regF_rule, // 713
  regF_rule, // 714
  _LoadF_memory__rule, // 715
  regF_rule, // 716
  _MulF__LoadF_memory__regF_rule, // 717
  regF_rule, // 718
  _MulF_regF__LoadF_memory__rule, // 719
  regF_rule, // 720
  _MulF_regF_regF_rule, // 721
  regF_rule, // 722
  _SubF_regF_regF_rule, // 723
  regF_rule, // 724
  regF_rule, // 725
  regF_rule, // 726
  regF_rule, // 727
  regX_rule, // 728
  regF_rule, // 729
  regD_rule, // 730
  regD_rule, // 731
  regD_rule, // 732
  regXD_rule, // 733
  regF_rule, // 734
  regF_rule, // 735
  regX_rule, // 736
  regX_rule, // 737
  regD_rule, // 738
  regXD_rule, // 739
  regD_rule, // 740
  regXD_rule, // 741
  regF_rule, // 742
  regX_rule, // 743
  regF_rule, // 744
  regX_rule, // 745
  stackSlotI_rule, // 746
  eRegI_rule, // 747
  _LoadI_memory__rule, // 748
  eRegI_rule, // 749
  _LoadI_memory__rule, // 750
  stackSlotI_rule, // 751
  stackSlotI_rule, // 752
  _LoadI_memory__rule, // 753
  stackSlotI_rule, // 754
  _LoadI_memory__rule, // 755
  eRegI_rule, // 756
  eRegI_rule, // 757
  eRegI_rule, // 758
  _ConvI2L_eRegI__rule, // 759
  eRegL_rule, // 760
  eRegL_rule, // 761
  eRegL_rule, // 762
  eRegL_rule, // 763
  eRegL_rule, // 764
  eRegL_rule, // 765
  regF_rule, // 766
  regX_rule, // 767
  eRegI_rule, // 768
  regD_rule, // 769
  regXD_rule, // 770
  regXD_rule, // 771
  eRegL_rule, // 772
  eRegL_rule, // 773
  regXD_rule, // 774
  eRegI_rule, // 775
  immI0_rule, // 776
  regXD_rule, // 777
  eRegI_rule, // 778
  immI0_rule, // 779
  regXD_rule, // 780
  eRegI_rule, // 781
  immI0_rule, // 782
  regXD_rule, // 783
  eRegI_rule, // 784
  immI0_rule, // 785
  regXD_rule, // 786
  regX_rule, // 787
  immXF0_rule, // 788
  eCXRegI_rule, // 789
  _Binary_eDIRegP_eCXRegI_rule, // 790
  _Binary_eDIRegP_eSIRegP_rule, // 791
  _Binary_eDIRegP_eDXRegI_rule, // 792
  eDIRegP_rule, // 793
  eRegI_rule, // 794
  eRegI_rule, // 795
  eRegI_rule, // 796
  0, // 797
  cmpOp_rule, // 798
  cmpOp_rule, // 799
  cmpOpU_rule, // 800
  cmpOpUCF_rule, // 801
  cmpOpU_rule, // 802
  cmpOpUCF_rule, // 803
  cmpOpUCF2_rule, // 804
  eSIRegP_rule, // 805
  0, // 806
  cmpOp_rule, // 807
  cmpOp_rule, // 808
  cmpOpU_rule, // 809
  cmpOpUCF_rule, // 810
  cmpOpU_rule, // 811
  cmpOpUCF_rule, // 812
  cmpOpUCF2_rule, // 813
  eRegL_rule, // 814
  cmpOp_rule, // 815
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 816
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 817
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 818
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 819
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 820
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 821
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 822
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 823
  _Binary_cmpOp_flagsReg_long_LTGE_rule, // 824
  cmpOp_rule, // 825
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 826
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 827
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 828
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 829
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 830
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 831
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 832
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 833
  _Binary_cmpOp_flagsReg_long_EQNE_rule, // 834
  cmpOp_commute_rule, // 835
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 836
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 837
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 838
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 839
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 840
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 841
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 842
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 843
  _Binary_cmpOp_commute_flagsReg_long_LEGT_rule, // 844
  0, // 845
  0, // 846
  0, // 847
  0, // 848
  0, // 849
  0, // 850
  0, // 851
  eRegP_no_EBP_rule, // 852
  eRegP_no_EBP_rule, // 853
  0, // 854
  0, // 855
  0, // 856
  0, // 857
  0, // 858
  // last instruction
  0 // no trailing comma
};

const        int   rightOp[] = {
  0, // 0
  0, // 1
  0, // 2
  0, // 3
  0, // 4
  0, // 5
  0, // 6
  0, // 7
  0, // 8
  0, // 9
  0, // 10
  0, // 11
  0, // 12
  0, // 13
  0, // 14
  0, // 15
  0, // 16
  0, // 17
  0, // 18
  0, // 19
  0, // 20
  0, // 21
  0, // 22
  0, // 23
  0, // 24
  0, // 25
  0, // 26
  0, // 27
  0, // 28
  0, // 29
  0, // 30
  0, // 31
  0, // 32
  0, // 33
  0, // 34
  0, // 35
  0, // 36
  0, // 37
  0, // 38
  0, // 39
  0, // 40
  0, // 41
  0, // 42
  0, // 43
  0, // 44
  0, // 45
  0, // 46
  0, // 47
  0, // 48
  0, // 49
  0, // 50
  0, // 51
  0, // 52
  0, // 53
  0, // 54
  0, // 55
  0, // 56
  0, // 57
  0, // 58
  0, // 59
  0, // 60
  0, // 61
  0, // 62
  0, // 63
  0, // 64
  0, // 65
  0, // 66
  0, // 67
  0, // 68
  0, // 69
  0, // 70
  0, // 71
  0, // 72
  0, // 73
  0, // 74
  0, // 75
  0, // 76
  0, // 77
  0, // 78
  0, // 79
  0, // 80
  0, // 81
  0, // 82
  0, // 83
  0, // 84
  0, // 85
  0, // 86
  immI8_rule, // 87
  immI_rule, // 88
  eRegI_rule, // 89
  immI_rule, // 90
  eRegI_rule, // 91
  _LShiftI_eRegI_immI2_rule, // 92
  immI_rule, // 93
  0, // 94
  0, // 95
  immI_rule, // 96
  0, // 97
  0, // 98
  0, // 99
  0, // 100
  0, // 101
  0, // 102
  immI8_rule, // 103
  immI_rule, // 104
  immI_rule, // 105
  _LShiftI_eRegI_immI2_rule, // 106
  immI_rule, // 107
  0, // 108
  0, // 109
  0, // 110
  0, // 111
  0, // 112
  0, // 113
  // last operand
  0, // 114
  0, // 115
  0, // 116
  // last operand class
  eRegI_rule, // 117
  immI2_rule, // 118
  _LShiftI_eRegI_immI2_rule, // 119
  eRegI_rule, // 120
  _LShiftI_eRegI_immI2_rule, // 121
  0, // 122
  0, // 123
  0, // 124
  0, // 125
  immI8_rule, // 126
  0, // 127
  immI_24_rule, // 128
  0, // 129
  immI_24_rule, // 130
  immI_255_rule, // 131
  immI16_rule, // 132
  immI_24_rule, // 133
  immI_16_rule, // 134
  immI_255_rule, // 135
  immI_65535_rule, // 136
  immI_rule, // 137
  0, // 138
  0, // 139
  0, // 140
  0, // 141
  eFlagsReg_rule, // 142
  eRegI_rule, // 143
  eFlagsRegU_rule, // 144
  eFlagsRegUCF_rule, // 145
  _LoadI_memory__rule, // 146
  eRegP_rule, // 147
  eFlagsRegU_rule, // 148
  regD_rule, // 149
  regF_rule, // 150
  regD_rule, // 151
  regF_rule, // 152
  regX_rule, // 153
  regXD_rule, // 154
  eRegL_rule, // 155
  eRegI_rule, // 156
  _LoadI_memory__rule, // 157
  immI_rule, // 158
  immI1_rule, // 159
  immI_M1_rule, // 160
  eRegP_rule, // 161
  eRegI_rule, // 162
  eBCXRegL_rule, // 163
  eCXRegP_rule, // 164
  eCXRegI_rule, // 165
  eRegI_rule, // 166
  eRegI_rule, // 167
  0, // 168
  eADXRegL_low_only_rule, // 169
  immI_32_rule, // 170
  _ConvI2L_nadxRegI__rule, // 171
  immI_32_rule, // 172
  immI_32_63_rule, // 173
  immI_32_63_rule, // 174
  0, // 175
  immL_32bits_rule, // 176
  immL_32bits_rule, // 177
  immI1_rule, // 178
  immI8_rule, // 179
  immI_24_rule, // 180
  immI_16_rule, // 181
  eRegI_rule, // 182
  _LoadI_memory__rule, // 183
  0, // 184
  eRegI_rule, // 185
  _LoadI_memory__rule, // 186
  immI_rule, // 187
  immI1_rule, // 188
  immI_M1_rule, // 189
  immI8_rule, // 190
  immI8_rule, // 191
  eCXRegI_rule, // 192
  eCXRegI_rule, // 193
  _SubI_immI0_eCXRegI_rule, // 194
  eCXRegI_rule, // 195
  _SubI_immI_32_eCXRegI_rule, // 196
  immI1_rule, // 197
  immI_M1_rule, // 198
  eCXRegI_rule, // 199
  _SubI_immI0_eCXRegI_rule, // 200
  _SubI_immI_32_eCXRegI_rule, // 201
  eRegI_rule, // 202
  _LoadI_memory__rule, // 203
  immI_rule, // 204
  ncxRegI_rule, // 205
  ncxRegI_rule, // 206
  ncxRegI_rule, // 207
  _CmpLTMask_ncxRegI_ncxRegI_rule, // 208
  0, // 209
  0, // 210
  regD_rule, // 211
  regD_rule, // 212
  regD_rule, // 213
  0, // 214
  _LoadD_memory__rule, // 215
  0, // 216
  immD_rule, // 217
  regD_rule, // 218
  regD_rule, // 219
  0, // 220
  0, // 221
  0, // 222
  0, // 223
  0, // 224
  regF_rule, // 225
  _LoadF_memory__rule, // 226
  regF_rule, // 227
  regF_rule, // 228
  0, // 229
  eCXRegI_rule, // 230
  eBXRegI_rule, // 231
  eSIRegP_rule, // 232
  eDXRegI_rule, // 233
  eAXRegI_rule, // 234
  immI_rule, // 235
  memory_rule, // 236
  0, // 237
  eAXRegP_rule, // 238
  flagsReg_long_LTGE_rule, // 239
  _LoadL_load_long_memory__rule, // 240
  flagsReg_long_EQNE_rule, // 241
  flagsReg_long_LEGT_rule, // 242
  // last internally defined operand
  0, // 243
  0, // 244
  0, // 245
  0, // 246
  0, // 247
  0, // 248
  0, // 249
  0, // 250
  0, // 251
  0, // 252
  0, // 253
  0, // 254
  0, // 255
  0, // 256
  0, // 257
  0, // 258
  0, // 259
  0, // 260
  0, // 261
  0, // 262
  0, // 263
  0, // 264
  0, // 265
  0, // 266
  0, // 267
  0, // 268
  0, // 269
  0, // 270
  0, // 271
  0, // 272
  0, // 273
  0, // 274
  0, // 275
  _Binary_eAXRegP_eRegP_rule, // 276
  _Binary_eAXRegI_eRegI_rule, // 277
  _Binary_eADXRegL_eBCXRegL_rule, // 278
  0, // 279
  0, // 280
  regD_rule, // 281
  regD_rule, // 282
  regD_rule, // 283
  regXD_rule, // 284
  regXD_rule, // 285
  _LoadD_memory__rule, // 286
  _LoadD_memory__rule, // 287
  0, // 288
  0, // 289
  0, // 290
  0, // 291
  regF_rule, // 292
  regF_rule, // 293
  regF_rule, // 294
  regX_rule, // 295
  regX_rule, // 296
  _LoadF_memory__rule, // 297
  _LoadF_memory__rule, // 298
  0, // 299
  0, // 300
  0, // 301
  0, // 302
  0, // 303
  0, // 304
  0, // 305
  0, // 306
  0, // 307
  0, // 308
  0, // 309
  0, // 310
  0, // 311
  eRegI_rule, // 312
  immI_rule, // 313
  _LoadI_memory__rule, // 314
  immI0_rule, // 315
  immI0_rule, // 316
  immI0_rule, // 317
  eRegI_rule, // 318
  immI_rule, // 319
  _LoadI_memory__rule, // 320
  immI0_rule, // 321
  eRegP_rule, // 322
  immP_rule, // 323
  _LoadP_memory__rule, // 324
  _LoadP_memory__rule, // 325
  immP0_rule, // 326
  immI0_rule, // 327
  immP0_rule, // 328
  immL0_rule, // 329
  eRegL_rule, // 330
  immL0_rule, // 331
  eRegL_rule, // 332
  immL0_rule, // 333
  eRegL_rule, // 334
  eRegP_rule, // 335
  eAXRegP_rule, // 336
  0, // 337
  0, // 338
  0, // 339
  0, // 340
  0, // 341
  0, // 342
  0, // 343
  0, // 344
  0, // 345
  0, // 346
  0, // 347
  0, // 348
  0, // 349
  0, // 350
  0, // 351
  0, // 352
  0, // 353
  0, // 354
  0, // 355
  immI_24_rule, // 356
  0, // 357
  0, // 358
  immI_24_rule, // 359
  0, // 360
  0, // 361
  0, // 362
  0, // 363
  immI_24_rule, // 364
  immI_255_rule, // 365
  immI_16_rule, // 366
  immI_65535_rule, // 367
  0, // 368
  0, // 369
  0, // 370
  0, // 371
  0, // 372
  0, // 373
  0, // 374
  0, // 375
  0, // 376
  0, // 377
  0, // 378
  0, // 379
  0, // 380
  0, // 381
  0, // 382
  0, // 383
  0, // 384
  0, // 385
  0, // 386
  0, // 387
  0, // 388
  0, // 389
  0, // 390
  0, // 391
  0, // 392
  0, // 393
  0, // 394
  0, // 395
  0, // 396
  0, // 397
  0, // 398
  0, // 399
  xRegI_rule, // 400
  eRegI_rule, // 401
  eRegI_rule, // 402
  eRegL_rule, // 403
  _ConvL2I_eRegL__rule, // 404
  stackSlotL_rule, // 405
  stackSlotL_rule, // 406
  eRegL_rule, // 407
  anyRegP_rule, // 408
  immI_rule, // 409
  immI16_rule, // 410
  immP_rule, // 411
  immI8_rule, // 412
  regXD_rule, // 413
  regXD_rule, // 414
  regXD_rule, // 415
  immI8_rule, // 416
  regDPR1_rule, // 417
  _RoundDouble_regDPR1__rule, // 418
  regXD_rule, // 419
  regX_rule, // 420
  regXD_rule, // 421
  regFPR1_rule, // 422
  _RoundFloat_regFPR1__rule, // 423
  _ConvD2F_regDPR1__rule, // 424
  immF_rule, // 425
  immXF_rule, // 426
  0, // 427
  0, // 428
  0, // 429
  0, // 430
  0, // 431
  _Binary_eRegI_eRegI_rule, // 432
  _Binary_eRegI_eRegI_rule, // 433
  _Binary_eRegI_eRegI_rule, // 434
  _Binary_eRegI__LoadI_memory__rule, // 435
  _Binary_eRegI__LoadI_memory__rule, // 436
  _Binary_eRegI__LoadI_memory__rule, // 437
  _Binary_eRegP_eRegP_rule, // 438
  _Binary_eRegP_eRegP_rule, // 439
  _Binary_eRegP_eRegP_rule, // 440
  _Binary_eRegP_eRegP_rule, // 441
  _Binary_regDPR1_regD_rule, // 442
  _Binary_regFPR1_regF_rule, // 443
  _Binary_regD_regD_rule, // 444
  _Binary_regF_regF_rule, // 445
  _Binary_regX_regX_rule, // 446
  _Binary_regXD_regXD_rule, // 447
  _Binary_regX_regX_rule, // 448
  _Binary_regX_regX_rule, // 449
  _Binary_regXD_regXD_rule, // 450
  _Binary_regXD_regXD_rule, // 451
  _Binary_eRegL_eRegL_rule, // 452
  _Binary_eRegL_eRegL_rule, // 453
  _Binary_eRegL_eRegL_rule, // 454
  eRegI_rule, // 455
  immI_rule, // 456
  immI1_rule, // 457
  immI_rule, // 458
  immI_rule, // 459
  immI_M1_rule, // 460
  eRegI_rule, // 461
  immI_rule, // 462
  _LoadI_memory__rule, // 463
  eRegI_rule, // 464
  _AddI__LoadI_memory__eRegI_rule, // 465
  _AddI_eRegI__LoadI_memory__rule, // 466
  _AddI__LoadI_memory__immI_rule, // 467
  _AddI__LoadI_memory__immI1_rule, // 468
  _AddI__LoadI_memory__immI_M1_rule, // 469
  0, // 470
  0, // 471
  0, // 472
  0, // 473
  _Binary_eADXRegL_eBCXRegL_rule, // 474
  _Binary_eAXRegP_eCXRegP_rule, // 475
  _Binary_eAXRegI_eCXRegI_rule, // 476
  eRegI_rule, // 477
  immI_rule, // 478
  _LoadI_memory__rule, // 479
  _SubI__LoadI_memory__eRegI_rule, // 480
  _SubI_immI0_eRegI_rule, // 481
  eRegI_rule, // 482
  eRegI_rule, // 483
  immI_rule, // 484
  0, // 485
  0, // 486
  0, // 487
  0, // 488
  immI_rule, // 489
  _LoadI_memory__rule, // 490
  eRegI_rule, // 491
  _ConvI2L_nadxRegI__rule, // 492
  _ConvI2L_eAXRegI__rule, // 493
  _AndL__ConvI2L_nadxRegI__immL_32bits_rule, // 494
  _AndL__ConvI2L_eAXRegI__immL_32bits_rule, // 495
  eRegL_rule, // 496
  eRegL_rule, // 497
  eRegL_rule, // 498
  eRegL_rule, // 499
  immL_127_rule, // 500
  eCXRegI_rule, // 501
  eRegL_rule, // 502
  eCXRegI_rule, // 503
  eCXRegI_rule, // 504
  eRegL_rule, // 505
  immI1_rule, // 506
  immI8_rule, // 507
  eCXRegI_rule, // 508
  immI1_rule, // 509
  _RShiftI__LoadI_memory__immI1_rule, // 510
  immI8_rule, // 511
  _RShiftI__LoadI_memory__immI8_rule, // 512
  eCXRegI_rule, // 513
  immI1_rule, // 514
  immI8_rule, // 515
  immI_24_rule, // 516
  immI_16_rule, // 517
  eCXRegI_rule, // 518
  eRegI_rule, // 519
  immI_rule, // 520
  _LoadI_memory__rule, // 521
  eRegI_rule, // 522
  _AndI__LoadI_memory__eRegI_rule, // 523
  _AndI_eRegI__LoadI_memory__rule, // 524
  _AndI__LoadI_memory__immI_rule, // 525
  eRegI_rule, // 526
  _CastP2X_eRegP__rule, // 527
  eRegI_rule, // 528
  immI_rule, // 529
  _LoadI_memory__rule, // 530
  eRegI_rule, // 531
  _OrI__LoadI_memory__eRegI_rule, // 532
  _OrI_eRegI__LoadI_memory__rule, // 533
  _OrI__LoadI_memory__immI_rule, // 534
  0, // 535
  0, // 536
  0, // 537
  _URShiftI_eRegI_immI_M1_rule, // 538
  _LShiftI_eRegI_immI1_rule, // 539
  _URShiftI_eRegI_immI8_rule, // 540
  _LShiftI_eRegI_immI8_rule, // 541
  _URShiftI_ncxRegI__SubI_immI0_eCXRegI_rule, // 542
  _LShiftI_ncxRegI_eCXRegI_rule, // 543
  _URShiftI_ncxRegI__SubI_immI_32_eCXRegI_rule, // 544
  _LShiftI_ncxRegI_eCXRegI_rule, // 545
  0, // 546
  0, // 547
  0, // 548
  _LShiftI_eRegI_immI_M1_rule, // 549
  _URShiftI_eRegI_immI1_rule, // 550
  _LShiftI_eRegI_immI8_rule, // 551
  _URShiftI_eRegI_immI8_rule, // 552
  _LShiftI_ncxRegI__SubI_immI0_eCXRegI_rule, // 553
  _URShiftI_ncxRegI_eCXRegI_rule, // 554
  _LShiftI_ncxRegI__SubI_immI_32_eCXRegI_rule, // 555
  _URShiftI_ncxRegI_eCXRegI_rule, // 556
  eRegI_rule, // 557
  immI_M1_rule, // 558
  immI_rule, // 559
  _LoadI_memory__rule, // 560
  eRegI_rule, // 561
  _XorI__LoadI_memory__eRegI_rule, // 562
  _XorI_eRegI__LoadI_memory__rule, // 563
  _XorI__LoadI_memory__immI_rule, // 564
  0, // 565
  0, // 566
  0, // 567
  0, // 568
  ncxRegI_rule, // 569
  immI0_rule, // 570
  _SubI_ncxRegI_ncxRegI_rule, // 571
  _AndI__CmpLTMask_ncxRegI_ncxRegI_ncxRegI_rule, // 572
  _SubI_ncxRegI_ncxRegI_rule, // 573
  _AndI_ncxRegI__CmpLTMask_ncxRegI_ncxRegI_rule, // 574
  eRegL_rule, // 575
  immL_rule, // 576
  _LoadL_load_long_memory__rule, // 577
  eRegL_rule, // 578
  eRegL_rule, // 579
  immL_rule, // 580
  _LoadL_load_long_memory__rule, // 581
  eRegL_rule, // 582
  eRegL_rule, // 583
  immL_rule, // 584
  _LoadL_load_long_memory__rule, // 585
  eRegL_rule, // 586
  eRegL_rule, // 587
  immL_rule, // 588
  _LoadL_load_long_memory__rule, // 589
  eRegL_rule, // 590
  eRegL_rule, // 591
  immL_M1_rule, // 592
  immL_rule, // 593
  _LoadL_load_long_memory__rule, // 594
  eRegL_rule, // 595
  immI_1_rule, // 596
  immI_2_rule, // 597
  immI_3_rule, // 598
  immI_1_31_rule, // 599
  immI_32_63_rule, // 600
  eCXRegI_rule, // 601
  immI_1_31_rule, // 602
  immI_32_63_rule, // 603
  eCXRegI_rule, // 604
  immI_1_31_rule, // 605
  immI_32_63_rule, // 606
  eCXRegI_rule, // 607
  immD0_rule, // 608
  regD_rule, // 609
  regXD_rule, // 610
  _LoadD_memory__rule, // 611
  regD_rule, // 612
  0, // 613
  _LoadD_memory__rule, // 614
  regD_rule, // 615
  0, // 616
  _LoadD_memory__rule, // 617
  regD_rule, // 618
  _RoundDouble__AddD__LoadD_memory__regD__rule, // 619
  _RoundDouble__AddD_regD__LoadD_memory___rule, // 620
  immD1_rule, // 621
  immD_rule, // 622
  0, // 623
  regXD_rule, // 624
  immXD_rule, // 625
  _LoadD_memory__rule, // 626
  regXD_rule, // 627
  regXD_rule, // 628
  immXD_rule, // 629
  _LoadD_memory__rule, // 630
  regXD_rule, // 631
  immXD_rule, // 632
  _LoadD_memory__rule, // 633
  regXD_rule, // 634
  regXD_rule, // 635
  immXD_rule, // 636
  _LoadD_memory__rule, // 637
  regD_rule, // 638
  regnotDPR1_rule, // 639
  immD_rule, // 640
  _LoadD_memory__rule, // 641
  regD_rule, // 642
  _LoadD_memory__rule, // 643
  regD_rule, // 644
  regD_rule, // 645
  _MulD_regD_regD_rule, // 646
  regD_rule, // 647
  regD_rule, // 648
  regnotDPR1_rule, // 649
  0, // 650
  regD_rule, // 651
  regXD_rule, // 652
  0, // 653
  0, // 654
  0, // 655
  0, // 656
  0, // 657
  0, // 658
  regD_rule, // 659
  regXD_rule, // 660
  0, // 661
  regDPR1_rule, // 662
  regXD_rule, // 663
  0, // 664
  0, // 665
  0, // 666
  0, // 667
  0, // 668
  0, // 669
  immF0_rule, // 670
  regF_rule, // 671
  regX_rule, // 672
  _LoadF_memory__rule, // 673
  regF_rule, // 674
  regF_rule, // 675
  regF_rule, // 676
  regF_rule, // 677
  regX_rule, // 678
  immXF_rule, // 679
  _LoadF_memory__rule, // 680
  regX_rule, // 681
  regX_rule, // 682
  immXF_rule, // 683
  _LoadF_memory__rule, // 684
  regX_rule, // 685
  immXF_rule, // 686
  _LoadF_memory__rule, // 687
  regX_rule, // 688
  regX_rule, // 689
  immXF_rule, // 690
  _LoadF_memory__rule, // 691
  0, // 692
  0, // 693
  0, // 694
  0, // 695
  _LoadF_memory__rule, // 696
  regF_rule, // 697
  _LoadF_memory__rule, // 698
  regF_rule, // 699
  regF_rule, // 700
  _LoadF_memory__rule, // 701
  memory_rule, // 702
  memory_rule, // 703
  immF_rule, // 704
  immF_rule, // 705
  regF_rule, // 706
  regF_rule, // 707
  _LoadF_memory__rule, // 708
  regF_rule, // 709
  _LoadF_memory__rule, // 710
  regF_rule, // 711
  memory_rule, // 712
  immF_rule, // 713
  immF_rule, // 714
  regF_rule, // 715
  _LoadF_memory__rule, // 716
  regF_rule, // 717
  _MulF__LoadF_memory__regF_rule, // 718
  regF_rule, // 719
  _MulF_regF__LoadF_memory__rule, // 720
  regF_rule, // 721
  _MulF_regF_regF_rule, // 722
  regF_rule, // 723
  regF_rule, // 724
  regF_rule, // 725
  regF_rule, // 726
  regF_rule, // 727
  regX_rule, // 728
  0, // 729
  0, // 730
  0, // 731
  0, // 732
  0, // 733
  0, // 734
  0, // 735
  0, // 736
  0, // 737
  0, // 738
  0, // 739
  0, // 740
  0, // 741
  0, // 742
  0, // 743
  0, // 744
  0, // 745
  0, // 746
  0, // 747
  0, // 748
  0, // 749
  0, // 750
  0, // 751
  0, // 752
  0, // 753
  0, // 754
  0, // 755
  0, // 756
  0, // 757
  0, // 758
  immL_32bits_rule, // 759
  immL_32bits_rule, // 760
  0, // 761
  0, // 762
  0, // 763
  0, // 764
  0, // 765
  0, // 766
  0, // 767
  0, // 768
  0, // 769
  0, // 770
  0, // 771
  0, // 772
  0, // 773
  0, // 774
  0, // 775
  0, // 776
  0, // 777
  0, // 778
  0, // 779
  0, // 780
  0, // 781
  0, // 782
  0, // 783
  0, // 784
  0, // 785
  0, // 786
  0, // 787
  0, // 788
  eDIRegP_rule, // 789
  _Binary_eSIRegP_eBXRegI_rule, // 790
  eCXRegI_rule, // 791
  _Binary_eSIRegP_eAXRegI_rule, // 792
  eSIRegP_rule, // 793
  eRegI_rule, // 794
  eRegI_rule, // 795
  0, // 796
  0, // 797
  eFlagsReg_rule, // 798
  eFlagsReg_rule, // 799
  eFlagsRegU_rule, // 800
  eFlagsRegUCF_rule, // 801
  eFlagsRegU_rule, // 802
  eFlagsRegUCF_rule, // 803
  eFlagsRegUCF_rule, // 804
  eAXRegP_rule, // 805
  0, // 806
  eFlagsReg_rule, // 807
  eFlagsReg_rule, // 808
  eFlagsRegU_rule, // 809
  eFlagsRegUCF_rule, // 810
  eFlagsRegU_rule, // 811
  eFlagsRegUCF_rule, // 812
  eFlagsRegUCF_rule, // 813
  eRegL_rule, // 814
  flagsReg_long_LTGE_rule, // 815
  _Binary_eRegL_eRegL_rule, // 816
  _Binary_eRegL__LoadL_load_long_memory__rule, // 817
  _Binary_eRegI_eRegI_rule, // 818
  _Binary_eRegI__LoadI_memory__rule, // 819
  _Binary_eRegP_eRegP_rule, // 820
  _Binary_regD_regD_rule, // 821
  _Binary_regXD_regXD_rule, // 822
  _Binary_regF_regF_rule, // 823
  _Binary_regX_regX_rule, // 824
  flagsReg_long_EQNE_rule, // 825
  _Binary_eRegL_eRegL_rule, // 826
  _Binary_eRegL__LoadL_load_long_memory__rule, // 827
  _Binary_eRegI_eRegI_rule, // 828
  _Binary_eRegI__LoadI_memory__rule, // 829
  _Binary_eRegP_eRegP_rule, // 830
  _Binary_regD_regD_rule, // 831
  _Binary_regXD_regXD_rule, // 832
  _Binary_regF_regF_rule, // 833
  _Binary_regX_regX_rule, // 834
  flagsReg_long_LEGT_rule, // 835
  _Binary_eRegL_eRegL_rule, // 836
  _Binary_eRegL__LoadL_load_long_memory__rule, // 837
  _Binary_eRegI_eRegI_rule, // 838
  _Binary_eRegI__LoadI_memory__rule, // 839
  _Binary_eRegP_eRegP_rule, // 840
  _Binary_regD_regD_rule, // 841
  _Binary_regXD_regXD_rule, // 842
  _Binary_regF_regF_rule, // 843
  _Binary_regX_regX_rule, // 844
  0, // 845
  0, // 846
  0, // 847
  0, // 848
  0, // 849
  0, // 850
  0, // 851
  eBXRegP_rule, // 852
  eAXRegP_rule, // 853
  0, // 854
  0, // 855
  0, // 856
  0, // 857
  0, // 858
  // last instruction
  0 // no trailing comma
};

const char        *ruleName[] = {
  "UNIVERSE", // 0
  "LABEL", // 1
  "SREGI", // 2
  "SREGP", // 3
  "SREGF", // 4
  "SREGD", // 5
  "SREGL", // 6
  "METHOD", // 7
  "IMMI", // 8
  "IMMI0", // 9
  "IMMI1", // 10
  "IMMI_M1", // 11
  "IMMI2", // 12
  "IMMI8", // 13
  "IMMI16", // 14
  "IMMI_32", // 15
  "IMMI_1_31", // 16
  "IMMI_32_63", // 17
  "IMMI_1", // 18
  "IMMI_2", // 19
  "IMMI_3", // 20
  "IMMP", // 21
  "IMMP0", // 22
  "IMML", // 23
  "IMML0", // 24
  "IMML_M1", // 25
  "IMML_127", // 26
  "IMML_32BITS", // 27
  "IMML32", // 28
  "IMMD0", // 29
  "IMMD1", // 30
  "IMMD", // 31
  "IMMXD", // 32
  "IMMXD0", // 33
  "IMMF0", // 34
  "IMMF", // 35
  "IMMXF", // 36
  "IMMXF0", // 37
  "IMMI_16", // 38
  "IMMI_24", // 39
  "IMMI_255", // 40
  "IMMI_65535", // 41
  "EREGI", // 42
  "XREGI", // 43
  "EAXREGI", // 44
  "EBXREGI", // 45
  "ECXREGI", // 46
  "EDXREGI", // 47
  "EDIREGI", // 48
  "NAXREGI", // 49
  "NADXREGI", // 50
  "NCXREGI", // 51
  "ESIREGI", // 52
  "ANYREGP", // 53
  "EREGP", // 54
  "EREGP_NO_EBP", // 55
  "NAXREGP", // 56
  "NABXREGP", // 57
  "PREGP", // 58
  "EAXREGP", // 59
  "EBXREGP", // 60
  "ECXREGP", // 61
  "ESIREGP", // 62
  "EDIREGP", // 63
  "EBPREGP", // 64
  "EREGL", // 65
  "EADXREGL", // 66
  "EBCXREGL", // 67
  "EADXREGL_LOW_ONLY", // 68
  "EFLAGSREG", // 69
  "EFLAGSREGU", // 70
  "EFLAGSREGUCF", // 71
  "FLAGSREG_LONG_LTGE", // 72
  "FLAGSREG_LONG_EQNE", // 73
  "FLAGSREG_LONG_LEGT", // 74
  "REGD", // 75
  "REGDPR1", // 76
  "REGDPR2", // 77
  "REGNOTDPR1", // 78
  "REGXD", // 79
  "REGXD6", // 80
  "REGXD7", // 81
  "REGF", // 82
  "REGFPR1", // 83
  "REGX", // 84
  "DIRECT", // 85
  "INDIRECT", // 86
  "INDOFFSET8", // 87
  "INDOFFSET32", // 88
  "INDOFFSET32X", // 89
  "INDINDEXOFFSET", // 90
  "INDINDEX", // 91
  "INDINDEXSCALE", // 92
  "INDINDEXSCALEOFFSET", // 93
  "LOAD_LONG_REGP", // 94
  "LOAD_LONG_INDIRECT", // 95
  "LOAD_LONG_INDOFFSET32", // 96
  "STACKSLOTP", // 97
  "STACKSLOTI", // 98
  "STACKSLOTF", // 99
  "STACKSLOTD", // 100
  "STACKSLOTL", // 101
  "INDIRECT_WIN95_SAFE", // 102
  "INDOFFSET8_WIN95_SAFE", // 103
  "INDOFFSET32_WIN95_SAFE", // 104
  "INDINDEXOFFSET_WIN95_SAFE", // 105
  "INDINDEXSCALE_WIN95_SAFE", // 106
  "INDINDEXSCALEOFFSET_WIN95_SAFE", // 107
  "CMPOP", // 108
  "CMPOPU", // 109
  "CMPOPUCF", // 110
  "CMPOPUCF2", // 111
  "CMPOP_FCMOV", // 112
  "CMPOP_COMMUTE", // 113
  // last operand
  "LOAD_LONG_MEMORY", // 114
  "MEMORY", // 115
  "LONG_MEMORY", // 116
  // last operand class
  "_AddP_eRegP_eRegI", // 117
  "_LShiftI_eRegI_immI2", // 118
  "_AddP_eRegP__LShiftI_eRegI_immI2", // 119
  "_AddP_eRegP_no_EBP_eRegI", // 120
  "_AddP_eRegP_no_EBP__LShiftI_eRegI_immI2", // 121
  "_LoadI_memory_", // 122
  "_LoadL_memory_", // 123
  "_LoadB_memory_", // 124
  "_LoadUB_memory_", // 125
  "_AndI__LoadUB_memory__immI8", // 126
  "_LoadS_memory_", // 127
  "_LShiftI__LoadS_memory__immI_24", // 128
  "_LoadUS_memory_", // 129
  "_LShiftI__LoadUS_memory__immI_24", // 130
  "_AndI__LoadUS_memory__immI_255", // 131
  "_AndI__LoadUS_memory__immI16", // 132
  "_LShiftI__LoadI_memory__immI_24", // 133
  "_LShiftI__LoadI_memory__immI_16", // 134
  "_AndI__LoadI_memory__immI_255", // 135
  "_AndI__LoadI_memory__immI_65535", // 136
  "_AndI__LoadI_memory__immI", // 137
  "_ConvL2I_eRegL_", // 138
  "_RoundDouble_regDPR1_", // 139
  "_RoundFloat_regFPR1_", // 140
  "_ConvD2F_regDPR1_", // 141
  "_Binary_cmpOp_eFlagsReg", // 142
  "_Binary_eRegI_eRegI", // 143
  "_Binary_cmpOpU_eFlagsRegU", // 144
  "_Binary_cmpOpUCF_eFlagsRegUCF", // 145
  "_Binary_eRegI__LoadI_memory_", // 146
  "_Binary_eRegP_eRegP", // 147
  "_Binary_cmpOp_fcmov_eFlagsRegU", // 148
  "_Binary_regDPR1_regD", // 149
  "_Binary_regFPR1_regF", // 150
  "_Binary_regD_regD", // 151
  "_Binary_regF_regF", // 152
  "_Binary_regX_regX", // 153
  "_Binary_regXD_regXD", // 154
  "_Binary_eRegL_eRegL", // 155
  "_AddI__LoadI_memory__eRegI", // 156
  "_AddI_eRegI__LoadI_memory_", // 157
  "_AddI__LoadI_memory__immI", // 158
  "_AddI__LoadI_memory__immI1", // 159
  "_AddI__LoadI_memory__immI_M1", // 160
  "_Binary_eAXRegP_eRegP", // 161
  "_Binary_eAXRegI_eRegI", // 162
  "_Binary_eADXRegL_eBCXRegL", // 163
  "_Binary_eAXRegP_eCXRegP", // 164
  "_Binary_eAXRegI_eCXRegI", // 165
  "_SubI__LoadI_memory__eRegI", // 166
  "_SubI_immI0_eRegI", // 167
  "_ConvI2L_nadxRegI_", // 168
  "_MulL__ConvI2L_nadxRegI__eADXRegL_low_only", // 169
  "_RShiftL__MulL__ConvI2L_nadxRegI__eADXRegL_low_only_immI_32", // 170
  "_MulL_eADXRegL_low_only__ConvI2L_nadxRegI_", // 171
  "_RShiftL__MulL_eADXRegL_low_only__ConvI2L_nadxRegI__immI_32", // 172
  "_RShiftL__MulL__ConvI2L_nadxRegI__eADXRegL_low_only_immI_32_63", // 173
  "_RShiftL__MulL_eADXRegL_low_only__ConvI2L_nadxRegI__immI_32_63", // 174
  "_ConvI2L_eAXRegI_", // 175
  "_AndL__ConvI2L_eAXRegI__immL_32bits", // 176
  "_AndL__ConvI2L_nadxRegI__immL_32bits", // 177
  "_RShiftI__LoadI_memory__immI1", // 178
  "_RShiftI__LoadI_memory__immI8", // 179
  "_LShiftI_xRegI_immI_24", // 180
  "_LShiftI_xRegI_immI_16", // 181
  "_AndI__LoadI_memory__eRegI", // 182
  "_AndI_eRegI__LoadI_memory_", // 183
  "_CastP2X_eRegP_", // 184
  "_OrI__LoadI_memory__eRegI", // 185
  "_OrI_eRegI__LoadI_memory_", // 186
  "_OrI__LoadI_memory__immI", // 187
  "_LShiftI_eRegI_immI1", // 188
  "_URShiftI_eRegI_immI_M1", // 189
  "_LShiftI_eRegI_immI8", // 190
  "_URShiftI_eRegI_immI8", // 191
  "_LShiftI_ncxRegI_eCXRegI", // 192
  "_SubI_immI0_eCXRegI", // 193
  "_URShiftI_ncxRegI__SubI_immI0_eCXRegI", // 194
  "_SubI_immI_32_eCXRegI", // 195
  "_URShiftI_ncxRegI__SubI_immI_32_eCXRegI", // 196
  "_URShiftI_eRegI_immI1", // 197
  "_LShiftI_eRegI_immI_M1", // 198
  "_URShiftI_ncxRegI_eCXRegI", // 199
  "_LShiftI_ncxRegI__SubI_immI0_eCXRegI", // 200
  "_LShiftI_ncxRegI__SubI_immI_32_eCXRegI", // 201
  "_XorI__LoadI_memory__eRegI", // 202
  "_XorI_eRegI__LoadI_memory_", // 203
  "_XorI__LoadI_memory__immI", // 204
  "_CmpLTMask_ncxRegI_ncxRegI", // 205
  "_AndI__CmpLTMask_ncxRegI_ncxRegI_ncxRegI", // 206
  "_SubI_ncxRegI_ncxRegI", // 207
  "_AndI_ncxRegI__CmpLTMask_ncxRegI_ncxRegI", // 208
  "_LoadL_load_long_memory_", // 209
  "_LoadD_memory_", // 210
  "_SubD_regD_regD", // 211
  "_AddD_regD_regD", // 212
  "_AddD__LoadD_memory__regD", // 213
  "_RoundDouble__AddD__LoadD_memory__regD_", // 214
  "_AddD_regD__LoadD_memory_", // 215
  "_RoundDouble__AddD_regD__LoadD_memory__", // 216
  "_AddD_regD_immD", // 217
  "_MulD_regD_regD", // 218
  "_DivD_regD_regD", // 219
  "_LoadF_memory_", // 220
  "_ConvF2D_regX_", // 221
  "_SqrtD__ConvF2D_regX__", // 222
  "_ConvF2D__LoadF_memory__", // 223
  "_SqrtD__ConvF2D__LoadF_memory___", // 224
  "_MulF__LoadF_memory__regF", // 225
  "_MulF_regF__LoadF_memory_", // 226
  "_MulF_regF_regF", // 227
  "_SubF_regF_regF", // 228
  "_ConvI2L_eRegI_", // 229
  "_Binary_eDIRegP_eCXRegI", // 230
  "_Binary_eSIRegP_eBXRegI", // 231
  "_Binary_eDIRegP_eSIRegP", // 232
  "_Binary_eDIRegP_eDXRegI", // 233
  "_Binary_eSIRegP_eAXRegI", // 234
  "_AndI_eRegI_immI", // 235
  "_AndI_eRegI_memory", // 236
  "_LoadP_memory_", // 237
  "_PartialSubtypeCheck_eSIRegP_eAXRegP", // 238
  "_Binary_cmpOp_flagsReg_long_LTGE", // 239
  "_Binary_eRegL__LoadL_load_long_memory_", // 240
  "_Binary_cmpOp_flagsReg_long_EQNE", // 241
  "_Binary_cmpOp_commute_flagsReg_long_LEGT", // 242
  // last internally defined operand
  "storeSSI", // 243
  "storeSSP", // 244
  "storeSSL", // 245
  "leaP8", // 246
  "leaP32", // 247
  "leaPIdxOff", // 248
  "leaPIdxScale", // 249
  "leaPIdxScaleOff", // 250
  "loadConI", // 251
  "loadConI0", // 252
  "loadConP", // 253
  "loadConL", // 254
  "loadConL0", // 255
  "loadConF", // 256
  "loadConX", // 257
  "loadConX0", // 258
  "loadConD", // 259
  "loadConXD", // 260
  "loadConXD0", // 261
  "loadSSI", // 262
  "loadSSL", // 263
  "loadSSP", // 264
  "loadSSF", // 265
  "loadSSD", // 266
  "loadConL_low_only", // 267
  "popCountI", // 268
  "popCountI_mem", // 269
  "membar_volatile", // 270
  "castX2P", // 271
  "castP2X", // 272
  "checkCastPP", // 273
  "castPP", // 274
  "castII", // 275
  "storePConditional", // 276
  "storeIConditional", // 277
  "storeLConditional", // 278
  "movI_nocopy", // 279
  "movP_nocopy", // 280
  "cmpD_cc_P6", // 281
  "cmpD_cc_P6CF", // 282
  "cmpD_cc", // 283
  "cmpXD_cc", // 284
  "cmpXD_ccCF", // 285
  "cmpXD_ccmem", // 286
  "cmpXD_ccmemCF", // 287
  "absD_reg", // 288
  "absXD_reg", // 289
  "negD_reg", // 290
  "negXD_reg", // 291
  "cmpF_cc_P6", // 292
  "cmpF_cc_P6CF", // 293
  "cmpF_cc", // 294
  "cmpX_cc", // 295
  "cmpX_ccCF", // 296
  "cmpX_ccmem", // 297
  "cmpX_ccmemCF", // 298
  "absF_reg", // 299
  "absX_reg", // 300
  "negF_reg", // 301
  "negX_reg", // 302
  "MoveF2I_stack_reg", // 303
  "MoveF2I_reg_reg_sse", // 304
  "MoveI2F_stack_reg", // 305
  "MoveI2F_stack_reg_sse", // 306
  "MoveI2F_reg_reg_sse", // 307
  "MoveD2L_stack_reg", // 308
  "MoveL2D_stack_reg", // 309
  "MoveL2D_stack_reg_sse", // 310
  "MoveL2D_stack_reg_sse_partial", // 311
  "compI_eReg", // 312
  "compI_eReg_imm", // 313
  "compI_eReg_mem", // 314
  "testI_reg", // 315
  "testI_reg_imm", // 316
  "testI_reg_mem", // 317
  "compU_eReg", // 318
  "compU_eReg_imm", // 319
  "compU_eReg_mem", // 320
  "testU_reg", // 321
  "compP_eReg", // 322
  "compP_eReg_imm", // 323
  "compP_eReg_mem", // 324
  "compP_mem_eReg", // 325
  "testP_reg", // 326
  "testP_Reg_mem", // 327
  "partialSubtypeCheck_vs_Zero", // 328
  "cmpL_zero_flags_LTGE", // 329
  "cmpL_reg_flags_LTGE", // 330
  "cmpL_zero_flags_EQNE", // 331
  "cmpL_reg_flags_EQNE", // 332
  "cmpL_zero_flags_LEGT", // 333
  "cmpL_reg_flags_LEGT", // 334
  "cmpFastLock", // 335
  "cmpFastUnlock", // 336
  "safePoint_poll", // 337
  "bytes_reverse_int", // 338
  "bytes_reverse_long", // 339
  "bytes_reverse_unsigned_short", // 340
  "bytes_reverse_short", // 341
  "countLeadingZerosI", // 342
  "countLeadingZerosI_bsr", // 343
  "countLeadingZerosL", // 344
  "countLeadingZerosL_bsr", // 345
  "countTrailingZerosI", // 346
  "countTrailingZerosL", // 347
  "popCountL", // 348
  "popCountL_mem", // 349
  "loadB", // 350
  "loadB2L", // 351
  "loadUB", // 352
  "loadUB2L", // 353
  "loadUB2L_immI8", // 354
  "loadS", // 355
  "loadS2B", // 356
  "loadS2L", // 357
  "loadUS", // 358
  "loadUS2B", // 359
  "loadUS2L", // 360
  "loadUS2L_immI_255", // 361
  "loadUS2L_immI16", // 362
  "loadI", // 363
  "loadI2B", // 364
  "loadI2UB", // 365
  "loadI2S", // 366
  "loadI2US", // 367
  "loadI2L", // 368
  "loadI2L_immI_255", // 369
  "loadI2L_immI_65535", // 370
  "loadI2L_immI", // 371
  "loadUI2L", // 372
  "loadL", // 373
  "loadL_volatile", // 374
  "loadLX_volatile", // 375
  "loadLX_reg_volatile", // 376
  "loadRange", // 377
  "loadP", // 378
  "loadKlass", // 379
  "loadD", // 380
  "loadXD", // 381
  "loadXD_partial", // 382
  "loadX", // 383
  "loadF", // 384
  "loadA8B", // 385
  "loadA4S", // 386
  "loadA4C", // 387
  "load2IU", // 388
  "loadA2F", // 389
  "prefetchr0", // 390
  "prefetchr", // 391
  "prefetchrNTA", // 392
  "prefetchrT0", // 393
  "prefetchrT2", // 394
  "prefetchw0", // 395
  "prefetchw", // 396
  "prefetchwNTA", // 397
  "prefetchwT0", // 398
  "prefetchwT2", // 399
  "storeB", // 400
  "storeC", // 401
  "storeI", // 402
  "storeL", // 403
  "storeL2I", // 404
  "storeL_volatile", // 405
  "storeLX_volatile", // 406
  "storeLX_reg_volatile", // 407
  "storeP", // 408
  "storeImmI", // 409
  "storeImmI16", // 410
  "storeImmP", // 411
  "storeImmB", // 412
  "storeA8B", // 413
  "storeA4C", // 414
  "storeA2I", // 415
  "storeImmCM", // 416
  "storeD", // 417
  "storeD_rounded", // 418
  "storeXD", // 419
  "storeX", // 420
  "storeA2F", // 421
  "storeF", // 422
  "storeF_rounded", // 423
  "storeF_Drounded", // 424
  "storeF_imm", // 425
  "storeX_imm", // 426
  "membar_acquire", // 427
  "membar_acquire_lock", // 428
  "membar_release", // 429
  "membar_release_lock", // 430
  "unnecessary_membar_volatile", // 431
  "cmovI_reg", // 432
  "cmovI_regU", // 433
  "cmovI_regUCF", // 434
  "cmovI_mem", // 435
  "cmovI_memU", // 436
  "cmovI_memUCF", // 437
  "cmovP_reg", // 438
  "cmovP_reg_nonP6", // 439
  "cmovP_regU", // 440
  "cmovP_regUCF", // 441
  "fcmovD_regU", // 442
  "fcmovF_regU", // 443
  "fcmovD_regS", // 444
  "fcmovF_regS", // 445
  "fcmovX_regS", // 446
  "fcmovXD_regS", // 447
  "fcmovX_regU", // 448
  "fcmovX_regUCF", // 449
  "fcmovXD_regU", // 450
  "fcmovXD_regUCF", // 451
  "cmovL_reg", // 452
  "cmovL_regU", // 453
  "cmovL_regUCF", // 454
  "addI_eReg", // 455
  "addI_eReg_imm", // 456
  "incI_eReg", // 457
  "leaI_eReg_immI", // 458
  "leaP_eReg_immI", // 459
  "decI_eReg", // 460
  "addP_eReg", // 461
  "addP_eReg_imm", // 462
  "addI_eReg_mem", // 463
  "addI_eReg_mem_0", // 464
  "addI_mem_eReg", // 465
  "addI_mem_eReg_0", // 466
  "addI_mem_imm", // 467
  "incI_mem", // 468
  "decI_mem", // 469
  "loadPLocked", // 470
  "loadLLocked", // 471
  "loadLX_Locked", // 472
  "loadLX_reg_Locked", // 473
  "compareAndSwapL", // 474
  "compareAndSwapP", // 475
  "compareAndSwapI", // 476
  "subI_eReg", // 477
  "subI_eReg_imm", // 478
  "subI_eReg_mem", // 479
  "subI_mem_eReg", // 480
  "subP_eReg", // 481
  "negI_eReg", // 482
  "mulI_eReg", // 483
  "mulI_eReg_imm", // 484
  "mulI_imm_high", // 485
  "mulI_imm_high_0", // 486
  "mulI_imm_RShift_high", // 487
  "mulI_imm_RShift_high_0", // 488
  "mulI_mem_imm", // 489
  "mulI", // 490
  "mulI_0", // 491
  "mulI2L", // 492
  "mulI2L_0", // 493
  "mulIS_eReg", // 494
  "mulIS_eReg_0", // 495
  "mulL_eReg", // 496
  "mulL_eReg_lhi0", // 497
  "mulL_eReg_rhi0", // 498
  "mulL_eReg_hi0", // 499
  "mulL_eReg_con", // 500
  "divI_eReg", // 501
  "divL_eReg", // 502
  "divModI_eReg_divmod", // 503
  "modI_eReg", // 504
  "modL_eReg", // 505
  "shlI_eReg_1", // 506
  "salI_eReg_imm", // 507
  "salI_eReg_CL", // 508
  "sarI_eReg_1", // 509
  "sarI_mem_1", // 510
  "sarI_eReg_imm", // 511
  "sarI_mem_imm", // 512
  "sarI_eReg_CL", // 513
  "shrI_eReg_1", // 514
  "shrI_eReg_imm", // 515
  "i2b", // 516
  "i2s", // 517
  "shrI_eReg_CL", // 518
  "andI_eReg", // 519
  "andI_eReg_imm", // 520
  "andI_eReg_mem", // 521
  "andI_eReg_mem_0", // 522
  "andI_mem_eReg", // 523
  "andI_mem_eReg_0", // 524
  "andI_mem_imm", // 525
  "orI_eReg", // 526
  "orI_eReg_castP2X", // 527
  "orI_eReg_castP2X_0", // 528
  "orI_eReg_imm", // 529
  "orI_eReg_mem", // 530
  "orI_eReg_mem_0", // 531
  "orI_mem_eReg", // 532
  "orI_mem_eReg_0", // 533
  "orI_mem_imm", // 534
  "rolI_eReg_imm1", // 535
  "rolI_eReg_imm8", // 536
  "rolI_eReg_CL", // 537
  "rolI_eReg_i1", // 538
  "rolI_eReg_i1_0", // 539
  "rolI_eReg_i8", // 540
  "rolI_eReg_i8_0", // 541
  "rolI_eReg_Var_C0", // 542
  "rolI_eReg_Var_C0_0", // 543
  "rolI_eReg_Var_C32", // 544
  "rolI_eReg_Var_C32_0", // 545
  "rorI_eReg_imm1", // 546
  "rorI_eReg_imm8", // 547
  "rorI_eReg_CL", // 548
  "rorI_eReg_i1", // 549
  "rorI_eReg_i1_0", // 550
  "rorI_eReg_i8", // 551
  "rorI_eReg_i8_0", // 552
  "rorI_eReg_Var_C0", // 553
  "rorI_eReg_Var_C0_0", // 554
  "rorI_eReg_Var_C32", // 555
  "rorI_eReg_Var_C32_0", // 556
  "xorI_eReg", // 557
  "xorI_eReg_im1", // 558
  "xorI_eReg_imm", // 559
  "xorI_eReg_mem", // 560
  "xorI_eReg_mem_0", // 561
  "xorI_mem_eReg", // 562
  "xorI_mem_eReg_0", // 563
  "xorI_mem_imm", // 564
  "ci2b", // 565
  "convI2B", // 566
  "cp2b", // 567
  "convP2B", // 568
  "cmpLTMask", // 569
  "cmpLTMask0", // 570
  "cadd_cmpLTMask", // 571
  "cadd_cmpLTMask_1", // 572
  "cadd_cmpLTMask_0", // 573
  "cadd_cmpLTMask_2", // 574
  "addL_eReg", // 575
  "addL_eReg_imm", // 576
  "addL_eReg_mem", // 577
  "addL_eReg_mem_0", // 578
  "subL_eReg", // 579
  "subL_eReg_imm", // 580
  "subL_eReg_mem", // 581
  "negL_eReg", // 582
  "andL_eReg", // 583
  "andL_eReg_imm", // 584
  "andL_eReg_mem", // 585
  "andL_eReg_mem_0", // 586
  "orl_eReg", // 587
  "orl_eReg_imm", // 588
  "orl_eReg_mem", // 589
  "orl_eReg_mem_0", // 590
  "xorl_eReg", // 591
  "xorl_eReg_im1", // 592
  "xorl_eReg_imm", // 593
  "xorl_eReg_mem", // 594
  "xorl_eReg_mem_0", // 595
  "shlL_eReg_1", // 596
  "shlL_eReg_2", // 597
  "shlL_eReg_3", // 598
  "shlL_eReg_1_31", // 599
  "shlL_eReg_32_63", // 600
  "salL_eReg_CL", // 601
  "shrL_eReg_1_31", // 602
  "shrL_eReg_32_63", // 603
  "shrL_eReg_CL", // 604
  "sarL_eReg_1_31", // 605
  "sarL_eReg_32_63", // 606
  "sarL_eReg_CL", // 607
  "cmpD_0", // 608
  "cmpD_reg", // 609
  "cmpXD_reg", // 610
  "cmpXD_regmem", // 611
  "subD_reg", // 612
  "subD_reg_round", // 613
  "subD_reg_mem", // 614
  "addD_reg", // 615
  "addD_reg_round", // 616
  "addD_reg_mem", // 617
  "addD_reg_mem_0", // 618
  "addD_mem_reg", // 619
  "addD_mem_reg_0", // 620
  "addD_reg_imm1", // 621
  "addD_reg_imm", // 622
  "addD_reg_imm_round", // 623
  "addXD_reg", // 624
  "addXD_imm", // 625
  "addXD_mem", // 626
  "addXD_mem_0", // 627
  "subXD_reg", // 628
  "subXD_imm", // 629
  "subXD_mem", // 630
  "mulXD_reg", // 631
  "mulXD_imm", // 632
  "mulXD_mem", // 633
  "mulXD_mem_0", // 634
  "divXD_reg", // 635
  "divXD_imm", // 636
  "divXD_mem", // 637
  "mulD_reg", // 638
  "strictfp_mulD_reg", // 639
  "mulD_reg_imm", // 640
  "mulD_reg_mem", // 641
  "mulD_reg_mem_0", // 642
  "mulD_reg_mem_cisc", // 643
  "mulD_reg_mem_cisc_0", // 644
  "addD_mulD_reg", // 645
  "addD_mulD_reg_0", // 646
  "subD_mulD_reg", // 647
  "divD_reg", // 648
  "strictfp_divD_reg", // 649
  "divD_reg_round", // 650
  "modD_reg", // 651
  "modXD_reg", // 652
  "sinD_reg", // 653
  "sinXD_reg", // 654
  "cosD_reg", // 655
  "cosXD_reg", // 656
  "tanD_reg", // 657
  "tanXD_reg", // 658
  "atanD_reg", // 659
  "atanXD_reg", // 660
  "sqrtD_reg", // 661
  "powD_reg", // 662
  "powXD_reg", // 663
  "expD_reg", // 664
  "expXD_reg", // 665
  "log10D_reg", // 666
  "log10XD_reg", // 667
  "logD_reg", // 668
  "logXD_reg", // 669
  "cmpF_0", // 670
  "cmpF_reg", // 671
  "cmpX_reg", // 672
  "cmpX_regmem", // 673
  "subF24_reg", // 674
  "subF_reg", // 675
  "addF24_reg", // 676
  "addF_reg", // 677
  "addX_reg", // 678
  "addX_imm", // 679
  "addX_mem", // 680
  "addX_mem_0", // 681
  "subX_reg", // 682
  "subX_imm", // 683
  "subX_mem", // 684
  "mulX_reg", // 685
  "mulX_imm", // 686
  "mulX_mem", // 687
  "mulX_mem_0", // 688
  "divX_reg", // 689
  "divX_imm", // 690
  "divX_mem", // 691
  "sqrtX_reg", // 692
  "sqrtX_mem", // 693
  "sqrtXD_reg", // 694
  "sqrtXD_mem", // 695
  "addF24_reg_mem", // 696
  "addF24_reg_mem_0", // 697
  "addF_reg_mem", // 698
  "addF_reg_mem_0", // 699
  "addF24_mem_reg", // 700
  "addF24_mem_cisc", // 701
  "addF24_mem_cisc_0", // 702
  "addF24_mem_mem", // 703
  "addF24_reg_imm", // 704
  "addF_reg_imm", // 705
  "mulF24_reg", // 706
  "mulF_reg", // 707
  "mulF24_reg_mem", // 708
  "mulF24_reg_mem_0", // 709
  "mulF_reg_mem", // 710
  "mulF_reg_mem_0", // 711
  "mulF24_mem_mem", // 712
  "mulF24_reg_imm", // 713
  "mulF_reg_imm", // 714
  "mulF_reg_load1", // 715
  "mulF_reg_load1_0", // 716
  "addF_mulF_reg_load1", // 717
  "addF_mulF_reg_load1_1", // 718
  "addF_mulF_reg_load1_0", // 719
  "addF_mulF_reg_load1_2", // 720
  "addF_mulF_reg", // 721
  "addF_mulF_reg_0", // 722
  "subF_divF_reg", // 723
  "divF24_reg", // 724
  "divF_reg", // 725
  "modF24_reg", // 726
  "modF_reg", // 727
  "modX_reg", // 728
  "roundFloat_mem_reg", // 729
  "roundDouble_mem_reg", // 730
  "convD2F_reg", // 731
  "convD2X_reg", // 732
  "convXD2X_reg", // 733
  "convF2D_reg_reg", // 734
  "convF2D_reg", // 735
  "convX2D_reg", // 736
  "convX2XD_reg", // 737
  "convD2I_reg_reg", // 738
  "convXD2I_reg_reg", // 739
  "convD2L_reg_reg", // 740
  "convXD2L_reg_reg", // 741
  "convF2I_reg_reg", // 742
  "convX2I_reg", // 743
  "convF2L_reg_reg", // 744
  "convX2L_reg_reg", // 745
  "convI2D_reg", // 746
  "convI2XD_reg", // 747
  "convI2XD_mem", // 748
  "convXI2XD_reg", // 749
  "convI2D_mem", // 750
  "conv24I2F_reg", // 751
  "convI2F_SSF", // 752
  "convI2F_SSF_mem", // 753
  "convI2F_reg", // 754
  "convI2F_mem", // 755
  "convI2X_reg", // 756
  "convXI2X_reg", // 757
  "convI2L_reg", // 758
  "convI2L_reg_zex", // 759
  "zerox_long", // 760
  "convL2D_reg", // 761
  "convL2XD_reg", // 762
  "convL2X_reg", // 763
  "convL2F_reg", // 764
  "convL2I_reg", // 765
  "MoveF2I_reg_stack", // 766
  "MoveF2I_reg_stack_sse", // 767
  "MoveI2F_reg_stack", // 768
  "MoveD2L_reg_stack", // 769
  "MoveD2L_reg_stack_sse", // 770
  "MoveD2L_reg_reg_sse", // 771
  "MoveL2D_reg_stack", // 772
  "MoveL2D_reg_reg_sse", // 773
  "Repl8B_reg", // 774
  "Repl8B_eRegI", // 775
  "Repl8B_immI0", // 776
  "Repl4S_reg", // 777
  "Repl4S_eRegI", // 778
  "Repl4S_immI0", // 779
  "Repl4C_reg", // 780
  "Repl4C_eRegI", // 781
  "Repl4C_immI0", // 782
  "Repl2I_reg", // 783
  "Repl2I_eRegI", // 784
  "Repl2I_immI0", // 785
  "Repl2F_reg", // 786
  "Repl2F_regX", // 787
  "Repl2F_immXF0", // 788
  "rep_stos", // 789
  "string_compare", // 790
  "string_equals", // 791
  "string_indexof", // 792
  "array_equals", // 793
  "minI_eReg", // 794
  "maxI_eReg", // 795
  "jumpXtnd", // 796
  "jmpDir", // 797
  "jmpCon", // 798
  "jmpLoopEnd", // 799
  "jmpLoopEndU", // 800
  "jmpLoopEndUCF", // 801
  "jmpConU", // 802
  "jmpConUCF", // 803
  "jmpConUCF2", // 804
  "partialSubtypeCheck", // 805
  "jmpDir_short", // 806
  "jmpCon_short", // 807
  "jmpLoopEnd_short", // 808
  "jmpLoopEndU_short", // 809
  "jmpLoopEndUCF_short", // 810
  "jmpConU_short", // 811
  "jmpConUCF_short", // 812
  "jmpConUCF2_short", // 813
  "cmpL3_reg_reg", // 814
  "cmpL_LTGE", // 815
  "cmovLL_reg_LTGE", // 816
  "cmovLL_mem_LTGE", // 817
  "cmovII_reg_LTGE", // 818
  "cmovII_mem_LTGE", // 819
  "cmovPP_reg_LTGE", // 820
  "cmovDD_reg_LTGE", // 821
  "cmovXDD_reg_LTGE", // 822
  "cmovFF_reg_LTGE", // 823
  "cmovXX_reg_LTGE", // 824
  "cmpL_EQNE", // 825
  "cmovLL_reg_EQNE", // 826
  "cmovLL_mem_EQNE", // 827
  "cmovII_reg_EQNE", // 828
  "cmovII_mem_EQNE", // 829
  "cmovPP_reg_EQNE", // 830
  "cmovDD_reg_EQNE", // 831
  "cmovXDD_reg_EQNE", // 832
  "cmovFF_reg_EQNE", // 833
  "cmovXX_reg_EQNE", // 834
  "cmpL_LEGT", // 835
  "cmovLL_reg_LEGT", // 836
  "cmovLL_mem_LEGT", // 837
  "cmovII_reg_LEGT", // 838
  "cmovII_mem_LEGT", // 839
  "cmovPP_reg_LEGT", // 840
  "cmovDD_reg_LEGT", // 841
  "cmovXDD_reg_LEGT", // 842
  "cmovFF_reg_LEGT", // 843
  "cmovXX_reg_LEGT", // 844
  "CallStaticJavaDirect", // 845
  "CallStaticJavaHandle", // 846
  "CallDynamicJavaDirect", // 847
  "CallRuntimeDirect", // 848
  "CallLeafDirect", // 849
  "CallLeafNoFPDirect", // 850
  "Ret", // 851
  "TailCalljmpInd", // 852
  "tailjmpInd", // 853
  "CreateException", // 854
  "RethrowException", // 855
  "tlsLoadP", // 856
  "TLS", // 857
  "ShouldNotReachHere", // 858
  // last instruction
  "no trailing comma"
};

const        bool  swallowed[] = {
  false, // 0
  false, // 1
  false, // 2
  false, // 3
  false, // 4
  false, // 5
  false, // 6
  false, // 7
  true, // 8
  true, // 9
  true, // 10
  true, // 11
  true, // 12
  true, // 13
  true, // 14
  true, // 15
  true, // 16
  true, // 17
  true, // 18
  true, // 19
  true, // 20
  true, // 21
  true, // 22
  true, // 23
  true, // 24
  true, // 25
  true, // 26
  true, // 27
  true, // 28
  true, // 29
  true, // 30
  true, // 31
  true, // 32
  true, // 33
  true, // 34
  true, // 35
  true, // 36
  true, // 37
  true, // 38
  true, // 39
  true, // 40
  true, // 41
  false, // 42
  false, // 43
  false, // 44
  false, // 45
  false, // 46
  false, // 47
  false, // 48
  false, // 49
  false, // 50
  false, // 51
  false, // 52
  false, // 53
  false, // 54
  false, // 55
  false, // 56
  false, // 57
  false, // 58
  false, // 59
  false, // 60
  false, // 61
  false, // 62
  false, // 63
  false, // 64
  false, // 65
  false, // 66
  false, // 67
  false, // 68
  false, // 69
  false, // 70
  false, // 71
  false, // 72
  false, // 73
  false, // 74
  false, // 75
  false, // 76
  false, // 77
  false, // 78
  false, // 79
  false, // 80
  false, // 81
  false, // 82
  false, // 83
  false, // 84
  true, // 85
  false, // 86
  false, // 87
  false, // 88
  false, // 89
  false, // 90
  false, // 91
  false, // 92
  false, // 93
  false, // 94
  false, // 95
  false, // 96
  false, // 97
  false, // 98
  false, // 99
  false, // 100
  false, // 101
  false, // 102
  false, // 103
  false, // 104
  false, // 105
  false, // 106
  false, // 107
  true, // 108
  true, // 109
  true, // 110
  true, // 111
  true, // 112
  true, // 113
  // last operand
  false, // 114
  false, // 115
  false, // 116
  // last operand class
  false, // 117
  false, // 118
  false, // 119
  false, // 120
  false, // 121
  false, // 122
  false, // 123
  false, // 124
  false, // 125
  false, // 126
  false, // 127
  false, // 128
  false, // 129
  false, // 130
  false, // 131
  false, // 132
  false, // 133
  false, // 134
  false, // 135
  false, // 136
  false, // 137
  false, // 138
  false, // 139
  false, // 140
  false, // 141
  false, // 142
  false, // 143
  false, // 144
  false, // 145
  false, // 146
  false, // 147
  false, // 148
  false, // 149
  false, // 150
  false, // 151
  false, // 152
  false, // 153
  false, // 154
  false, // 155
  false, // 156
  false, // 157
  false, // 158
  false, // 159
  false, // 160
  false, // 161
  false, // 162
  false, // 163
  false, // 164
  false, // 165
  false, // 166
  false, // 167
  false, // 168
  false, // 169
  false, // 170
  false, // 171
  false, // 172
  false, // 173
  false, // 174
  false, // 175
  false, // 176
  false, // 177
  false, // 178
  false, // 179
  false, // 180
  false, // 181
  false, // 182
  false, // 183
  false, // 184
  false, // 185
  false, // 186
  false, // 187
  false, // 188
  false, // 189
  false, // 190
  false, // 191
  false, // 192
  false, // 193
  false, // 194
  false, // 195
  false, // 196
  false, // 197
  false, // 198
  false, // 199
  false, // 200
  false, // 201
  false, // 202
  false, // 203
  false, // 204
  false, // 205
  false, // 206
  false, // 207
  false, // 208
  false, // 209
  false, // 210
  false, // 211
  false, // 212
  false, // 213
  false, // 214
  false, // 215
  false, // 216
  false, // 217
  false, // 218
  false, // 219
  false, // 220
  false, // 221
  false, // 222
  false, // 223
  false, // 224
  false, // 225
  false, // 226
  false, // 227
  false, // 228
  false, // 229
  false, // 230
  false, // 231
  false, // 232
  false, // 233
  false, // 234
  false, // 235
  false, // 236
  false, // 237
  false, // 238
  false, // 239
  false, // 240
  false, // 241
  false, // 242
  // last internally defined operand
  false, // 243
  false, // 244
  false, // 245
  false, // 246
  false, // 247
  false, // 248
  false, // 249
  false, // 250
  false, // 251
  false, // 252
  false, // 253
  false, // 254
  false, // 255
  false, // 256
  false, // 257
  false, // 258
  false, // 259
  false, // 260
  false, // 261
  false, // 262
  false, // 263
  false, // 264
  false, // 265
  false, // 266
  false, // 267
  false, // 268
  false, // 269
  false, // 270
  false, // 271
  false, // 272
  false, // 273
  false, // 274
  false, // 275
  false, // 276
  false, // 277
  false, // 278
  false, // 279
  false, // 280
  false, // 281
  false, // 282
  false, // 283
  false, // 284
  false, // 285
  false, // 286
  false, // 287
  false, // 288
  false, // 289
  false, // 290
  false, // 291
  false, // 292
  false, // 293
  false, // 294
  false, // 295
  false, // 296
  false, // 297
  false, // 298
  false, // 299
  false, // 300
  false, // 301
  false, // 302
  false, // 303
  false, // 304
  false, // 305
  false, // 306
  false, // 307
  false, // 308
  false, // 309
  false, // 310
  false, // 311
  false, // 312
  false, // 313
  false, // 314
  false, // 315
  false, // 316
  false, // 317
  false, // 318
  false, // 319
  false, // 320
  false, // 321
  false, // 322
  false, // 323
  false, // 324
  false, // 325
  false, // 326
  false, // 327
  false, // 328
  false, // 329
  false, // 330
  false, // 331
  false, // 332
  false, // 333
  false, // 334
  false, // 335
  false, // 336
  false, // 337
  false, // 338
  false, // 339
  false, // 340
  false, // 341
  false, // 342
  false, // 343
  false, // 344
  false, // 345
  false, // 346
  false, // 347
  false, // 348
  false, // 349
  false, // 350
  false, // 351
  false, // 352
  false, // 353
  false, // 354
  false, // 355
  false, // 356
  false, // 357
  false, // 358
  false, // 359
  false, // 360
  false, // 361
  false, // 362
  false, // 363
  false, // 364
  false, // 365
  false, // 366
  false, // 367
  false, // 368
  false, // 369
  false, // 370
  false, // 371
  false, // 372
  false, // 373
  false, // 374
  false, // 375
  false, // 376
  false, // 377
  false, // 378
  false, // 379
  false, // 380
  false, // 381
  false, // 382
  false, // 383
  false, // 384
  false, // 385
  false, // 386
  false, // 387
  false, // 388
  false, // 389
  false, // 390
  false, // 391
  false, // 392
  false, // 393
  false, // 394
  false, // 395
  false, // 396
  false, // 397
  false, // 398
  false, // 399
  false, // 400
  false, // 401
  false, // 402
  false, // 403
  false, // 404
  false, // 405
  false, // 406
  false, // 407
  false, // 408
  false, // 409
  false, // 410
  false, // 411
  false, // 412
  false, // 413
  false, // 414
  false, // 415
  false, // 416
  false, // 417
  false, // 418
  false, // 419
  false, // 420
  false, // 421
  false, // 422
  false, // 423
  false, // 424
  false, // 425
  false, // 426
  false, // 427
  false, // 428
  false, // 429
  false, // 430
  false, // 431
  false, // 432
  false, // 433
  false, // 434
  false, // 435
  false, // 436
  false, // 437
  false, // 438
  false, // 439
  false, // 440
  false, // 441
  false, // 442
  false, // 443
  false, // 444
  false, // 445
  false, // 446
  false, // 447
  false, // 448
  false, // 449
  false, // 450
  false, // 451
  false, // 452
  false, // 453
  false, // 454
  false, // 455
  false, // 456
  false, // 457
  false, // 458
  false, // 459
  false, // 460
  false, // 461
  false, // 462
  false, // 463
  false, // 464
  false, // 465
  false, // 466
  false, // 467
  false, // 468
  false, // 469
  false, // 470
  false, // 471
  false, // 472
  false, // 473
  false, // 474
  false, // 475
  false, // 476
  false, // 477
  false, // 478
  false, // 479
  false, // 480
  false, // 481
  false, // 482
  false, // 483
  false, // 484
  false, // 485
  false, // 486
  false, // 487
  false, // 488
  false, // 489
  false, // 490
  false, // 491
  false, // 492
  false, // 493
  false, // 494
  false, // 495
  false, // 496
  false, // 497
  false, // 498
  false, // 499
  false, // 500
  false, // 501
  false, // 502
  false, // 503
  false, // 504
  false, // 505
  false, // 506
  false, // 507
  false, // 508
  false, // 509
  false, // 510
  false, // 511
  false, // 512
  false, // 513
  false, // 514
  false, // 515
  false, // 516
  false, // 517
  false, // 518
  false, // 519
  false, // 520
  false, // 521
  false, // 522
  false, // 523
  false, // 524
  false, // 525
  false, // 526
  false, // 527
  false, // 528
  false, // 529
  false, // 530
  false, // 531
  false, // 532
  false, // 533
  false, // 534
  false, // 535
  false, // 536
  false, // 537
  false, // 538
  false, // 539
  false, // 540
  false, // 541
  false, // 542
  false, // 543
  false, // 544
  false, // 545
  false, // 546
  false, // 547
  false, // 548
  false, // 549
  false, // 550
  false, // 551
  false, // 552
  false, // 553
  false, // 554
  false, // 555
  false, // 556
  false, // 557
  false, // 558
  false, // 559
  false, // 560
  false, // 561
  false, // 562
  false, // 563
  false, // 564
  false, // 565
  false, // 566
  false, // 567
  false, // 568
  false, // 569
  false, // 570
  false, // 571
  false, // 572
  false, // 573
  false, // 574
  false, // 575
  false, // 576
  false, // 577
  false, // 578
  false, // 579
  false, // 580
  false, // 581
  false, // 582
  false, // 583
  false, // 584
  false, // 585
  false, // 586
  false, // 587
  false, // 588
  false, // 589
  false, // 590
  false, // 591
  false, // 592
  false, // 593
  false, // 594
  false, // 595
  false, // 596
  false, // 597
  false, // 598
  false, // 599
  false, // 600
  false, // 601
  false, // 602
  false, // 603
  false, // 604
  false, // 605
  false, // 606
  false, // 607
  false, // 608
  false, // 609
  false, // 610
  false, // 611
  false, // 612
  false, // 613
  false, // 614
  false, // 615
  false, // 616
  false, // 617
  false, // 618
  false, // 619
  false, // 620
  false, // 621
  false, // 622
  false, // 623
  false, // 624
  false, // 625
  false, // 626
  false, // 627
  false, // 628
  false, // 629
  false, // 630
  false, // 631
  false, // 632
  false, // 633
  false, // 634
  false, // 635
  false, // 636
  false, // 637
  false, // 638
  false, // 639
  false, // 640
  false, // 641
  false, // 642
  false, // 643
  false, // 644
  false, // 645
  false, // 646
  false, // 647
  false, // 648
  false, // 649
  false, // 650
  false, // 651
  false, // 652
  false, // 653
  false, // 654
  false, // 655
  false, // 656
  false, // 657
  false, // 658
  false, // 659
  false, // 660
  false, // 661
  false, // 662
  false, // 663
  false, // 664
  false, // 665
  false, // 666
  false, // 667
  false, // 668
  false, // 669
  false, // 670
  false, // 671
  false, // 672
  false, // 673
  false, // 674
  false, // 675
  false, // 676
  false, // 677
  false, // 678
  false, // 679
  false, // 680
  false, // 681
  false, // 682
  false, // 683
  false, // 684
  false, // 685
  false, // 686
  false, // 687
  false, // 688
  false, // 689
  false, // 690
  false, // 691
  false, // 692
  false, // 693
  false, // 694
  false, // 695
  false, // 696
  false, // 697
  false, // 698
  false, // 699
  false, // 700
  false, // 701
  false, // 702
  false, // 703
  false, // 704
  false, // 705
  false, // 706
  false, // 707
  false, // 708
  false, // 709
  false, // 710
  false, // 711
  false, // 712
  false, // 713
  false, // 714
  false, // 715
  false, // 716
  false, // 717
  false, // 718
  false, // 719
  false, // 720
  false, // 721
  false, // 722
  false, // 723
  false, // 724
  false, // 725
  false, // 726
  false, // 727
  false, // 728
  false, // 729
  false, // 730
  false, // 731
  false, // 732
  false, // 733
  false, // 734
  false, // 735
  false, // 736
  false, // 737
  false, // 738
  false, // 739
  false, // 740
  false, // 741
  false, // 742
  false, // 743
  false, // 744
  false, // 745
  false, // 746
  false, // 747
  false, // 748
  false, // 749
  false, // 750
  false, // 751
  false, // 752
  false, // 753
  false, // 754
  false, // 755
  false, // 756
  false, // 757
  false, // 758
  false, // 759
  false, // 760
  false, // 761
  false, // 762
  false, // 763
  false, // 764
  false, // 765
  false, // 766
  false, // 767
  false, // 768
  false, // 769
  false, // 770
  false, // 771
  false, // 772
  false, // 773
  false, // 774
  false, // 775
  false, // 776
  false, // 777
  false, // 778
  false, // 779
  false, // 780
  false, // 781
  false, // 782
  false, // 783
  false, // 784
  false, // 785
  false, // 786
  false, // 787
  false, // 788
  false, // 789
  false, // 790
  false, // 791
  false, // 792
  false, // 793
  false, // 794
  false, // 795
  false, // 796
  false, // 797
  false, // 798
  false, // 799
  false, // 800
  false, // 801
  false, // 802
  false, // 803
  false, // 804
  false, // 805
  false, // 806
  false, // 807
  false, // 808
  false, // 809
  false, // 810
  false, // 811
  false, // 812
  false, // 813
  false, // 814
  false, // 815
  false, // 816
  false, // 817
  false, // 818
  false, // 819
  false, // 820
  false, // 821
  false, // 822
  false, // 823
  false, // 824
  false, // 825
  false, // 826
  false, // 827
  false, // 828
  false, // 829
  false, // 830
  false, // 831
  false, // 832
  false, // 833
  false, // 834
  false, // 835
  false, // 836
  false, // 837
  false, // 838
  false, // 839
  false, // 840
  false, // 841
  false, // 842
  false, // 843
  false, // 844
  false, // 845
  false, // 846
  false, // 847
  false, // 848
  false, // 849
  false, // 850
  false, // 851
  false, // 852
  false, // 853
  false, // 854
  false, // 855
  false, // 856
  false, // 857
  false, // 858
  // last instruction
  false // no trailing comma
};

// Mapping from machine-independent opcode to boolean
const        char must_clone[] = {
  0, // Node: 0
  0, // Set: 1
  0, // RegN: 2
  0, // RegI: 3
  0, // RegP: 4
  0, // RegF: 5
  0, // RegD: 6
  0, // RegL: 7
  0, // RegFlags: 8
  0, // _last_machine_leaf: 9
  0, // AbsD: 10
  0, // AbsF: 11
  0, // AbsI: 12
  0, // AddD: 13
  0, // AddF: 14
  0, // AddI: 15
  0, // AddL: 16
  0, // AddP: 17
  0, // Allocate: 18
  0, // AllocateArray: 19
  0, // AndI: 20
  0, // AndL: 21
  0, // AryEq: 22
  0, // AtanD: 23
  1, // Binary: 24
  1, // Bool: 25
  0, // BoxLock: 26
  0, // ReverseBytesI: 27
  0, // ReverseBytesL: 28
  0, // ReverseBytesUS: 29
  0, // ReverseBytesS: 30
  0, // CProj: 31
  0, // CallDynamicJava: 32
  0, // CallJava: 33
  0, // CallLeaf: 34
  0, // CallLeafNoFP: 35
  0, // CallRuntime: 36
  0, // CallStaticJava: 37
  0, // CastII: 38
  0, // CastX2P: 39
  0, // CastP2X: 40
  0, // CastPP: 41
  0, // Catch: 42
  0, // CatchProj: 43
  0, // CheckCastPP: 44
  0, // ClearArray: 45
  0, // ConstraintCast: 46
  0, // CMoveD: 47
  0, // CMoveF: 48
  0, // CMoveI: 49
  0, // CMoveL: 50
  0, // CMoveP: 51
  0, // CMoveN: 52
  1, // CmpN: 53
  1, // CmpD: 54
  0, // CmpD3: 55
  1, // CmpF: 56
  0, // CmpF3: 57
  1, // CmpI: 58
  1, // CmpL: 59
  0, // CmpL3: 60
  0, // CmpLTMask: 61
  1, // CmpP: 62
  1, // CmpU: 63
  0, // CompareAndSwapI: 64
  0, // CompareAndSwapL: 65
  0, // CompareAndSwapP: 66
  0, // CompareAndSwapN: 67
  0, // Con: 68
  0, // ConN: 69
  0, // ConD: 70
  0, // ConF: 71
  0, // ConI: 72
  0, // ConL: 73
  0, // ConP: 74
  0, // Conv2B: 75
  0, // ConvD2F: 76
  0, // ConvD2I: 77
  0, // ConvD2L: 78
  0, // ConvF2D: 79
  0, // ConvF2I: 80
  0, // ConvF2L: 81
  0, // ConvI2D: 82
  0, // ConvI2F: 83
  0, // ConvI2L: 84
  0, // ConvL2D: 85
  0, // ConvL2F: 86
  0, // ConvL2I: 87
  0, // CosD: 88
  0, // CountedLoop: 89
  0, // CountedLoopEnd: 90
  0, // CountLeadingZerosI: 91
  0, // CountLeadingZerosL: 92
  0, // CountTrailingZerosI: 93
  0, // CountTrailingZerosL: 94
  0, // CreateEx: 95
  0, // DecodeN: 96
  0, // DivD: 97
  0, // DivF: 98
  0, // DivI: 99
  0, // DivL: 100
  0, // DivMod: 101
  0, // DivModI: 102
  0, // DivModL: 103
  0, // EncodeP: 104
  0, // ExpD: 105
  1, // FastLock: 106
  1, // FastUnlock: 107
  0, // Goto: 108
  0, // Halt: 109
  0, // If: 110
  0, // IfFalse: 111
  0, // IfTrue: 112
  0, // Initialize: 113
  0, // JProj: 114
  0, // Jump: 115
  0, // JumpProj: 116
  0, // LShiftI: 117
  0, // LShiftL: 118
  0, // LoadB: 119
  0, // LoadUB: 120
  0, // LoadUS: 121
  0, // LoadD: 122
  0, // LoadD_unaligned: 123
  0, // LoadF: 124
  0, // LoadI: 125
  0, // LoadUI2L: 126
  0, // LoadKlass: 127
  0, // LoadNKlass: 128
  0, // LoadL: 129
  0, // LoadL_unaligned: 130
  0, // LoadPLocked: 131
  0, // LoadLLocked: 132
  0, // LoadP: 133
  0, // LoadN: 134
  0, // LoadRange: 135
  0, // LoadS: 136
  0, // Lock: 137
  0, // LogD: 138
  0, // Log10D: 139
  0, // Loop: 140
  0, // Mach: 141
  0, // MachProj: 142
  0, // MaxI: 143
  0, // MemBarAcquire: 144
  0, // MemBarCPUOrder: 145
  0, // MemBarRelease: 146
  0, // MemBarVolatile: 147
  0, // MergeMem: 148
  0, // MinI: 149
  0, // ModD: 150
  0, // ModF: 151
  0, // ModI: 152
  0, // ModL: 153
  0, // MoveI2F: 154
  0, // MoveF2I: 155
  0, // MoveL2D: 156
  0, // MoveD2L: 157
  0, // MulD: 158
  0, // MulF: 159
  0, // MulHiL: 160
  0, // MulI: 161
  0, // MulL: 162
  0, // Multi: 163
  0, // NegD: 164
  0, // NegF: 165
  0, // NeverBranch: 166
  0, // Opaque1: 167
  0, // Opaque2: 168
  0, // OrI: 169
  0, // OrL: 170
  0, // PCTable: 171
  0, // Parm: 172
  0, // PartialSubtypeCheck: 173
  0, // Phi: 174
  0, // PopCountI: 175
  0, // PopCountL: 176
  0, // PowD: 177
  0, // PrefetchRead: 178
  0, // PrefetchWrite: 179
  0, // Proj: 180
  0, // RShiftI: 181
  0, // RShiftL: 182
  0, // Region: 183
  0, // Rethrow: 184
  0, // Return: 185
  0, // Root: 186
  0, // RoundDouble: 187
  0, // RoundFloat: 188
  0, // SafePoint: 189
  0, // SafePointScalarObject: 190
  0, // SCMemProj: 191
  0, // SinD: 192
  0, // SqrtD: 193
  0, // Start: 194
  0, // StartOSR: 195
  0, // StoreB: 196
  0, // StoreC: 197
  0, // StoreCM: 198
  0, // StorePConditional: 199
  0, // StoreIConditional: 200
  0, // StoreLConditional: 201
  0, // StoreD: 202
  0, // StoreF: 203
  0, // StoreI: 204
  0, // StoreL: 205
  0, // StoreP: 206
  0, // StoreN: 207
  0, // StrComp: 208
  0, // StrEquals: 209
  0, // StrIndexOf: 210
  0, // SubD: 211
  0, // SubF: 212
  0, // SubI: 213
  0, // SubL: 214
  0, // TailCall: 215
  0, // TailJump: 216
  0, // TanD: 217
  0, // ThreadLocal: 218
  0, // Unlock: 219
  0, // URShiftI: 220
  0, // URShiftL: 221
  0, // XorI: 222
  0, // XorL: 223
  0, // Vector: 224
  0, // AddVB: 225
  0, // AddVC: 226
  0, // AddVS: 227
  0, // AddVI: 228
  0, // AddVL: 229
  0, // AddVF: 230
  0, // AddVD: 231
  0, // SubVB: 232
  0, // SubVC: 233
  0, // SubVS: 234
  0, // SubVI: 235
  0, // SubVL: 236
  0, // SubVF: 237
  0, // SubVD: 238
  0, // MulVF: 239
  0, // MulVD: 240
  0, // DivVF: 241
  0, // DivVD: 242
  0, // LShiftVB: 243
  0, // LShiftVC: 244
  0, // LShiftVS: 245
  0, // LShiftVI: 246
  0, // URShiftVB: 247
  0, // URShiftVC: 248
  0, // URShiftVS: 249
  0, // URShiftVI: 250
  0, // AndV: 251
  0, // OrV: 252
  0, // XorV: 253
  0, // VectorLoad: 254
  0, // Load16B: 255
  0, // Load8B: 256
  0, // Load4B: 257
  0, // Load8C: 258
  0, // Load4C: 259
  0, // Load2C: 260
  0, // Load8S: 261
  0, // Load4S: 262
  0, // Load2S: 263
  0, // Load4I: 264
  0, // Load2I: 265
  0, // Load2L: 266
  0, // Load4F: 267
  0, // Load2F: 268
  0, // Load2D: 269
  0, // VectorStore: 270
  0, // Store16B: 271
  0, // Store8B: 272
  0, // Store4B: 273
  0, // Store8C: 274
  0, // Store4C: 275
  0, // Store2C: 276
  0, // Store4I: 277
  0, // Store2I: 278
  0, // Store2L: 279
  0, // Store4F: 280
  0, // Store2F: 281
  0, // Store2D: 282
  0, // Pack: 283
  0, // PackB: 284
  0, // PackS: 285
  0, // PackC: 286
  0, // PackI: 287
  0, // PackL: 288
  0, // PackF: 289
  0, // PackD: 290
  0, // Pack2x1B: 291
  0, // Pack2x2B: 292
  0, // Replicate16B: 293
  0, // Replicate8B: 294
  0, // Replicate4B: 295
  0, // Replicate8S: 296
  0, // Replicate4S: 297
  0, // Replicate2S: 298
  0, // Replicate8C: 299
  0, // Replicate4C: 300
  0, // Replicate2C: 301
  0, // Replicate4I: 302
  0, // Replicate2I: 303
  0, // Replicate2L: 304
  0, // Replicate4F: 305
  0, // Replicate2F: 306
  0, // Replicate2D: 307
  0, // Extract: 308
  0, // ExtractB: 309
  0, // ExtractS: 310
  0, // ExtractC: 311
  0, // ExtractI: 312
  0, // ExtractL: 313
  0, // ExtractF: 314
  0 // no trailing comma // ExtractD: 315
};
//  The following instructions can cisc-spill
//  popCountI can cisc-spill operand 1 to popCountI_mem
//  popCountL can cisc-spill operand 1 to popCountL_mem
//  cmovI_reg can cisc-spill operand 4 to cmovI_mem
//  cmovI_regU can cisc-spill operand 4 to cmovI_memU
//  cmovI_regUCF can cisc-spill operand 4 to cmovI_memUCF
//  addI_eReg can cisc-spill operand 2 to addI_eReg_mem
//  subI_eReg can cisc-spill operand 2 to subI_eReg_mem
//  mulI_eReg can cisc-spill operand 2 to mulI
//  mulI_eReg_imm can cisc-spill operand 1 to mulI_mem_imm
//  i2b can cisc-spill operand 1 to loadI2B
//  i2s can cisc-spill operand 1 to loadI2S
//  andI_eReg can cisc-spill operand 2 to andI_eReg_mem
//  orI_eReg can cisc-spill operand 2 to orI_eReg_mem
//  xorI_eReg can cisc-spill operand 2 to xorI_eReg_mem
//  addL_eReg can cisc-spill operand 2 to addL_eReg_mem
//  subL_eReg can cisc-spill operand 2 to subL_eReg_mem
//  andL_eReg can cisc-spill operand 2 to andL_eReg_mem
//  orl_eReg can cisc-spill operand 2 to orl_eReg_mem
//  xorl_eReg can cisc-spill operand 2 to xorl_eReg_mem
//  cmpXD_cc can cisc-spill operand 2 to cmpXD_ccmem
//  cmpXD_ccCF can cisc-spill operand 2 to cmpXD_ccmemCF
//  cmpXD_reg can cisc-spill operand 2 to cmpXD_regmem
//  subD_reg can cisc-spill operand 2 to subD_reg_mem
//  addD_reg can cisc-spill operand 2 to addD_reg_mem
//  addXD_reg can cisc-spill operand 2 to addXD_mem
//  subXD_reg can cisc-spill operand 2 to subXD_mem
//  mulXD_reg can cisc-spill operand 2 to mulXD_mem
//  divXD_reg can cisc-spill operand 2 to divXD_mem
//  mulD_reg can cisc-spill operand 2 to mulD_reg_mem
//  cmpX_cc can cisc-spill operand 2 to cmpX_ccmem
//  cmpX_ccCF can cisc-spill operand 2 to cmpX_ccmemCF
//  cmpX_reg can cisc-spill operand 2 to cmpX_regmem
//  addF24_reg can cisc-spill operand 2 to addF24_reg_mem
//  addF_reg can cisc-spill operand 2 to addF_reg_mem
//  addX_reg can cisc-spill operand 2 to addX_mem
//  subX_reg can cisc-spill operand 2 to subX_mem
//  mulX_reg can cisc-spill operand 2 to mulX_mem
//  divX_reg can cisc-spill operand 2 to divX_mem
//  sqrtX_reg can cisc-spill operand 1 to sqrtX_mem
//  sqrtXD_reg can cisc-spill operand 1 to sqrtXD_mem
//  addF24_reg_mem can cisc-spill operand 1 to addF24_mem_cisc
//  addF24_reg_mem_0 can cisc-spill operand 2 to addF24_mem_cisc_0
//  addF24_mem_reg can cisc-spill operand 2 to addF24_mem_cisc
//  mulF24_reg can cisc-spill operand 2 to mulF24_reg_mem
//  mulF_reg can cisc-spill operand 2 to mulF_reg_mem
//  addF_mulF_reg can cisc-spill operand 1 to addF_mulF_reg_load1
//  addF_mulF_reg_0 can cisc-spill operand 2 to addF_mulF_reg_load1_1
//  convI2L_reg can cisc-spill operand 1 to loadI2L
//  compI_eReg can cisc-spill operand 2 to compI_eReg_mem
//  compU_eReg can cisc-spill operand 2 to compU_eReg_mem
//  compP_eReg can cisc-spill operand 2 to compP_eReg_mem
//  cmovLL_reg_LTGE can cisc-spill operand 4 to cmovLL_mem_LTGE
//  cmovII_reg_LTGE can cisc-spill operand 4 to cmovII_mem_LTGE
//  cmovLL_reg_EQNE can cisc-spill operand 4 to cmovLL_mem_EQNE
//  cmovII_reg_EQNE can cisc-spill operand 4 to cmovII_mem_EQNE
//  cmovLL_reg_LEGT can cisc-spill operand 4 to cmovLL_mem_LEGT
//  cmovII_reg_LEGT can cisc-spill operand 4 to cmovII_mem_LEGT



// An array of character pointers to machine register names.
const char *Matcher::regName[REG_COUNT] = {
  "ECX",
  "EBX",
  "EBP",
  "EDI",
  "EAX",
  "EDX",
  "ESI",
  "ESP",
  "FPR0L",
  "FPR0H",
  "FPR1L",
  "FPR1H",
  "FPR2L",
  "FPR2H",
  "FPR3L",
  "FPR3H",
  "FPR4L",
  "FPR4H",
  "FPR5L",
  "FPR5H",
  "FPR6L",
  "FPR6H",
  "FPR7L",
  "FPR7H",
  "XMM0a",
  "XMM0b",
  "XMM1a",
  "XMM1b",
  "XMM2a",
  "XMM2b",
  "XMM3a",
  "XMM3b",
  "XMM4a",
  "XMM4b",
  "XMM5a",
  "XMM5b",
  "XMM6a",
  "XMM6b",
  "XMM7a",
  "XMM7b",
  "EFLAGS" // no trailing comma
};

// An array of character pointers to machine register names.
const VMReg OptoReg::opto2vm[REG_COUNT] = {
	rcx->as_VMReg(),
	rbx->as_VMReg(),
	rbp->as_VMReg(),
	rdi->as_VMReg(),
	rax->as_VMReg(),
	rdx->as_VMReg(),
	rsi->as_VMReg(),
	rsp->as_VMReg(),
	VMRegImpl::Bad(),
	VMRegImpl::Bad(),
	as_FloatRegister(0)->as_VMReg(),
	as_FloatRegister(0)->as_VMReg()->next(),
	as_FloatRegister(1)->as_VMReg(),
	as_FloatRegister(1)->as_VMReg()->next(),
	as_FloatRegister(2)->as_VMReg(),
	as_FloatRegister(2)->as_VMReg()->next(),
	as_FloatRegister(3)->as_VMReg(),
	as_FloatRegister(3)->as_VMReg()->next(),
	as_FloatRegister(4)->as_VMReg(),
	as_FloatRegister(4)->as_VMReg()->next(),
	as_FloatRegister(5)->as_VMReg(),
	as_FloatRegister(5)->as_VMReg()->next(),
	as_FloatRegister(6)->as_VMReg(),
	as_FloatRegister(6)->as_VMReg()->next(),
	xmm0->as_VMReg(),
	xmm0->as_VMReg()->next(),
	xmm1->as_VMReg(),
	xmm1->as_VMReg()->next(),
	xmm2->as_VMReg(),
	xmm2->as_VMReg()->next(),
	xmm3->as_VMReg(),
	xmm3->as_VMReg()->next(),
	xmm4->as_VMReg(),
	xmm4->as_VMReg()->next(),
	xmm5->as_VMReg(),
	xmm5->as_VMReg()->next(),
	xmm6->as_VMReg(),
	xmm6->as_VMReg()->next(),
	xmm7->as_VMReg(),
	xmm7->as_VMReg()->next(),
	VMRegImpl::Bad() // no trailing comma
	};

 OptoReg::Name OptoReg::vm2opto[ConcreteRegisterImpl::number_of_registers];

// An array of the machine register encode values
const unsigned char Matcher::_regEncode[REG_COUNT] = {
  (unsigned char)'\x1',  // ECX
  (unsigned char)'\x3',  // EBX
  (unsigned char)'\x5',  // EBP
  (unsigned char)'\x7',  // EDI
  (unsigned char)'\x0',  // EAX
  (unsigned char)'\x2',  // EDX
  (unsigned char)'\x6',  // ESI
  (unsigned char)'\x4',  // ESP
  (unsigned char)'\x0',  // FPR0L
  (unsigned char)'\x0',  // FPR0H
  (unsigned char)'\x1',  // FPR1L
  (unsigned char)'\x1',  // FPR1H
  (unsigned char)'\x2',  // FPR2L
  (unsigned char)'\x2',  // FPR2H
  (unsigned char)'\x3',  // FPR3L
  (unsigned char)'\x3',  // FPR3H
  (unsigned char)'\x4',  // FPR4L
  (unsigned char)'\x4',  // FPR4H
  (unsigned char)'\x5',  // FPR5L
  (unsigned char)'\x5',  // FPR5H
  (unsigned char)'\x6',  // FPR6L
  (unsigned char)'\x6',  // FPR6H
  (unsigned char)'\x7',  // FPR7L
  (unsigned char)'\x7',  // FPR7H
  (unsigned char)'\x0',  // XMM0a
  (unsigned char)'\x0',  // XMM0b
  (unsigned char)'\x1',  // XMM1a
  (unsigned char)'\x1',  // XMM1b
  (unsigned char)'\x2',  // XMM2a
  (unsigned char)'\x2',  // XMM2b
  (unsigned char)'\x3',  // XMM3a
  (unsigned char)'\x3',  // XMM3b
  (unsigned char)'\x4',  // XMM4a
  (unsigned char)'\x4',  // XMM4b
  (unsigned char)'\x5',  // XMM5a
  (unsigned char)'\x5',  // XMM5b
  (unsigned char)'\x6',  // XMM6a
  (unsigned char)'\x6',  // XMM6b
  (unsigned char)'\x7',  // XMM7a
  (unsigned char)'\x7',  // XMM7b
  (unsigned char)'\x8' // no trailing comma  // EFLAGS
};


//------------------Define classes derived from MachOper---------------------
MachOper  *labelOper::clone(Compile* C) const {
  return  new (C) labelOper(_label, _block_num);
}
uint labelOper::opcode() const { return LABEL; }

const RegMask *sRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *sRegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

MachOper  *methodOper::clone(Compile* C) const {
  return  new (C) methodOper(_method);
}
uint methodOper::opcode() const { return METHOD; }

const RegMask *eRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *xRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &X_REG_mask;
}

const RegMask *eAXRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EAX_REG_mask;
}

const RegMask *eBXRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EBX_REG_mask;
}

const RegMask *eCXRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ECX_REG_mask;
}

const RegMask *eDXRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EDX_REG_mask;
}

const RegMask *eDIRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EDI_REG_mask;
}

const RegMask *naxRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &NAX_REG_mask;
}

const RegMask *nadxRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &NADX_REG_mask;
}

const RegMask *ncxRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &NCX_REG_mask;
}

const RegMask *eSIRegIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ESI_REG_mask;
}

const RegMask *anyRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ANY_REG_mask;
}

const RegMask *eRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *eRegP_no_EBPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_NO_RBP_mask;
}

const RegMask *naxRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &NAX_REG_mask;
}

const RegMask *nabxRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &NABX_REG_mask;
}

const RegMask *pRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &P_REG_mask;
}

const RegMask *eAXRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EAX_REG_mask;
}

const RegMask *eBXRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EBX_REG_mask;
}

const RegMask *eCXRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ECX_REG_mask;
}

const RegMask *eSIRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ESI_REG_mask;
}

const RegMask *eDIRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EDI_REG_mask;
}

const RegMask *eBPRegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EBP_REG_mask;
}

const RegMask *eRegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &LONG_REG_mask;
}

const RegMask *eADXRegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EADX_REG_mask;
}

const RegMask *eBCXRegLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EBCX_REG_mask;
}

const RegMask *eADXRegL_low_onlyOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &EADX_REG_mask;
}

const RegMask *eFlagsRegOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask;
}

const RegMask *eFlagsRegUOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask;
}

const RegMask *eFlagsRegUCFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask;
}

const RegMask *flagsReg_long_LTGEOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask;
}

const RegMask *flagsReg_long_EQNEOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask;
}

const RegMask *flagsReg_long_LEGTOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &INT_FLAGS_mask;
}

const RegMask *regDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &DBL_REG_mask;
}

const RegMask *regDPR1Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &DBL_REG0_mask;
}

const RegMask *regDPR2Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &DBL_REG1_mask;
}

const RegMask *regnotDPR1Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &DBL_NOTREG0_mask;
}

const RegMask *regXDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &XDB_REG_mask;
}

const RegMask *regXD6Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &XDB_REG6_mask;
}

const RegMask *regXD7Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &XDB_REG7_mask;
}

const RegMask *regFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &FLT_REG_mask;
}

const RegMask *regFPR1Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &FLT_REG0_mask;
}

const RegMask *regXOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &XMM_REG_mask;
}

const RegMask *indirectOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *indOffset8Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *indOffset32Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *indOffset32XOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *indIndexOffsetOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  return &E_REG_mask;
}

const RegMask *indIndexOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  return &E_REG_mask;
}

const RegMask *indIndexScaleOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  return &E_REG_mask;
}

const RegMask *indIndexScaleOffsetOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  return &E_REG_mask;
}

const RegMask *load_long_RegPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ESI_REG_mask;
}

const RegMask *load_long_indirectOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ESI_REG_mask;
}

const RegMask *load_long_indOffset32Oper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &ESI_REG_mask;
}

const RegMask *stackSlotPOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *stackSlotIOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *stackSlotFOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *stackSlotDOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *stackSlotLOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &(Compile::current()->FIRST_STACK_mask());
}

const RegMask *indirect_win95_safeOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_mask;
}

const RegMask *indOffset8_win95_safeOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_NO_RBP_mask;
}

const RegMask *indOffset32_win95_safeOper::in_RegMask(int index) const {
  assert(0 <= index && index < 1, "index out of range");
  return &E_REG_NO_RBP_mask;
}

const RegMask *indIndexOffset_win95_safeOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  switch (index) {
  case 0: return &E_REG_NO_RBP_mask;
  case 1: return &E_REG_mask;
  }
  ShouldNotReachHere();
  return NULL;
}

const RegMask *indIndexScale_win95_safeOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  switch (index) {
  case 0: return &E_REG_NO_RBP_mask;
  case 1: return &E_REG_mask;
  }
  ShouldNotReachHere();
  return NULL;
}

const RegMask *indIndexScaleOffset_win95_safeOper::in_RegMask(int index) const {
  assert(0 <= index && index < 2, "index out of range");
  switch (index) {
  case 0: return &E_REG_NO_RBP_mask;
  case 1: return &E_REG_mask;
  }
  ShouldNotReachHere();
  return NULL;
}

//------------------Define members for classes derived from MachNode----------

void popCountINode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *popCountINode::cisc_version( int offset, Compile* C ) {
  popCountI_memNode *node = new (C) popCountI_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void popCountLNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *popCountLNode::cisc_version( int offset, Compile* C ) {
  popCountL_memNode *node = new (C) popCountL_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovI_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovI_regNode::cisc_version( int offset, Compile* C ) {
  cmovI_memNode *node = new (C) cmovI_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovI_regUNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovI_regUNode::cisc_version( int offset, Compile* C ) {
  cmovI_memUNode *node = new (C) cmovI_memUNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovI_regUCFNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovI_regUCFNode::cisc_version( int offset, Compile* C ) {
  cmovI_memUCFNode *node = new (C) cmovI_memUCFNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *addI_eRegNode::cisc_version( int offset, Compile* C ) {
  addI_eReg_memNode *node = new (C) addI_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void subI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *subI_eRegNode::cisc_version( int offset, Compile* C ) {
  subI_eReg_memNode *node = new (C) subI_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulI_eRegNode::cisc_version( int offset, Compile* C ) {
  mulINode *node = new (C) mulINode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulI_eReg_immNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulI_eReg_immNode::cisc_version( int offset, Compile* C ) {
  mulI_mem_immNode *node = new (C) mulI_mem_immNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void i2bNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_X_REG_mask;
}

// Build CISC version of this instruction
MachNode *i2bNode::cisc_version( int offset, Compile* C ) {
  loadI2BNode *node = new (C) loadI2BNode();
  node->_num_opnds = 3;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void i2sNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_X_REG_mask;
}

// Build CISC version of this instruction
MachNode *i2sNode::cisc_version( int offset, Compile* C ) {
  loadI2SNode *node = new (C) loadI2SNode();
  node->_num_opnds = 3;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void andI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *andI_eRegNode::cisc_version( int offset, Compile* C ) {
  andI_eReg_memNode *node = new (C) andI_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void orI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *orI_eRegNode::cisc_version( int offset, Compile* C ) {
  orI_eReg_memNode *node = new (C) orI_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void xorI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *xorI_eRegNode::cisc_version( int offset, Compile* C ) {
  xorI_eReg_memNode *node = new (C) xorI_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addL_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *addL_eRegNode::cisc_version( int offset, Compile* C ) {
  addL_eReg_memNode *node = new (C) addL_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void subL_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *subL_eRegNode::cisc_version( int offset, Compile* C ) {
  subL_eReg_memNode *node = new (C) subL_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void andL_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *andL_eRegNode::cisc_version( int offset, Compile* C ) {
  andL_eReg_memNode *node = new (C) andL_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void orl_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *orl_eRegNode::cisc_version( int offset, Compile* C ) {
  orl_eReg_memNode *node = new (C) orl_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void xorl_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *xorl_eRegNode::cisc_version( int offset, Compile* C ) {
  xorl_eReg_memNode *node = new (C) xorl_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmpXD_ccNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmpXD_ccNode::cisc_version( int offset, Compile* C ) {
  cmpXD_ccmemNode *node = new (C) cmpXD_ccmemNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmpXD_ccCFNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmpXD_ccCFNode::cisc_version( int offset, Compile* C ) {
  cmpXD_ccmemCFNode *node = new (C) cmpXD_ccmemCFNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmpXD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmpXD_regNode::cisc_version( int offset, Compile* C ) {
  cmpXD_regmemNode *node = new (C) cmpXD_regmemNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void subD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_DBL_REG_mask;
}

// Build CISC version of this instruction
MachNode *subD_regNode::cisc_version( int offset, Compile* C ) {
  subD_reg_memNode *node = new (C) subD_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_DBL_REG_mask;
}

// Build CISC version of this instruction
MachNode *addD_regNode::cisc_version( int offset, Compile* C ) {
  addD_reg_memNode *node = new (C) addD_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addXD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *addXD_regNode::cisc_version( int offset, Compile* C ) {
  addXD_memNode *node = new (C) addXD_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void subXD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *subXD_regNode::cisc_version( int offset, Compile* C ) {
  subXD_memNode *node = new (C) subXD_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulXD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulXD_regNode::cisc_version( int offset, Compile* C ) {
  mulXD_memNode *node = new (C) mulXD_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void divXD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *divXD_regNode::cisc_version( int offset, Compile* C ) {
  divXD_memNode *node = new (C) divXD_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_DBL_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulD_regNode::cisc_version( int offset, Compile* C ) {
  mulD_reg_memNode *node = new (C) mulD_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmpX_ccNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmpX_ccNode::cisc_version( int offset, Compile* C ) {
  cmpX_ccmemNode *node = new (C) cmpX_ccmemNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmpX_ccCFNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmpX_ccCFNode::cisc_version( int offset, Compile* C ) {
  cmpX_ccmemCFNode *node = new (C) cmpX_ccmemCFNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmpX_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmpX_regNode::cisc_version( int offset, Compile* C ) {
  cmpX_regmemNode *node = new (C) cmpX_regmemNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF24_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF24_regNode::cisc_version( int offset, Compile* C ) {
  addF24_reg_memNode *node = new (C) addF24_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF_regNode::cisc_version( int offset, Compile* C ) {
  addF_reg_memNode *node = new (C) addF_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addX_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *addX_regNode::cisc_version( int offset, Compile* C ) {
  addX_memNode *node = new (C) addX_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void subX_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *subX_regNode::cisc_version( int offset, Compile* C ) {
  subX_memNode *node = new (C) subX_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulX_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulX_regNode::cisc_version( int offset, Compile* C ) {
  mulX_memNode *node = new (C) mulX_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void divX_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *divX_regNode::cisc_version( int offset, Compile* C ) {
  divX_memNode *node = new (C) divX_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void sqrtX_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XMM_REG_mask;
}

// Build CISC version of this instruction
MachNode *sqrtX_regNode::cisc_version( int offset, Compile* C ) {
  sqrtX_memNode *node = new (C) sqrtX_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void sqrtXD_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_XDB_REG_mask;
}

// Build CISC version of this instruction
MachNode *sqrtXD_regNode::cisc_version( int offset, Compile* C ) {
  sqrtXD_memNode *node = new (C) sqrtXD_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF24_reg_memNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF24_reg_memNode::cisc_version( int offset, Compile* C ) {
  addF24_mem_ciscNode *node = new (C) addF24_mem_ciscNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF24_reg_mem_0Node::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF24_reg_mem_0Node::cisc_version( int offset, Compile* C ) {
  addF24_mem_cisc_0Node *node = new (C) addF24_mem_cisc_0Node();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF24_mem_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF24_mem_regNode::cisc_version( int offset, Compile* C ) {
  addF24_mem_ciscNode *node = new (C) addF24_mem_ciscNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulF24_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulF24_regNode::cisc_version( int offset, Compile* C ) {
  mulF24_reg_memNode *node = new (C) mulF24_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void mulF_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *mulF_regNode::cisc_version( int offset, Compile* C ) {
  mulF_reg_memNode *node = new (C) mulF_reg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF_mulF_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF_mulF_regNode::cisc_version( int offset, Compile* C ) {
  addF_mulF_reg_load1Node *node = new (C) addF_mulF_reg_load1Node();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void addF_mulF_reg_0Node::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_FLT_REG_mask;
}

// Build CISC version of this instruction
MachNode *addF_mulF_reg_0Node::cisc_version( int offset, Compile* C ) {
  addF_mulF_reg_load1_1Node *node = new (C) addF_mulF_reg_load1_1Node();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void convI2L_regNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *convI2L_regNode::cisc_version( int offset, Compile* C ) {
  loadI2LNode *node = new (C) loadI2LNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void compI_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *compI_eRegNode::cisc_version( int offset, Compile* C ) {
  compI_eReg_memNode *node = new (C) compI_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void compU_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *compU_eRegNode::cisc_version( int offset, Compile* C ) {
  compU_eReg_memNode *node = new (C) compU_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void compP_eRegNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *compP_eRegNode::cisc_version( int offset, Compile* C ) {
  compP_eReg_memNode *node = new (C) compP_eReg_memNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}

// Build short branch version of this instruction
MachNode *jmpDirNode::short_branch_version(Compile* C) {
  jmpDir_shortNode *node = new (C) jmpDir_shortNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpConNode::short_branch_version(Compile* C) {
  jmpCon_shortNode *node = new (C) jmpCon_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpLoopEndNode::short_branch_version(Compile* C) {
  jmpLoopEnd_shortNode *node = new (C) jmpLoopEnd_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpLoopEndUNode::short_branch_version(Compile* C) {
  jmpLoopEndU_shortNode *node = new (C) jmpLoopEndU_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpLoopEndUCFNode::short_branch_version(Compile* C) {
  jmpLoopEndUCF_shortNode *node = new (C) jmpLoopEndUCF_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpConUNode::short_branch_version(Compile* C) {
  jmpConU_shortNode *node = new (C) jmpConU_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpConUCFNode::short_branch_version(Compile* C) {
  jmpConUCF_shortNode *node = new (C) jmpConUCF_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}

// Build short branch version of this instruction
MachNode *jmpConUCF2Node::short_branch_version(Compile* C) {
  jmpConUCF2_shortNode *node = new (C) jmpConUCF2_shortNode();
  node->_prob = _prob;
  node->_fcnt = _fcnt;

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  return node;
}


void cmovLL_reg_LTGENode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovLL_reg_LTGENode::cisc_version( int offset, Compile* C ) {
  cmovLL_mem_LTGENode *node = new (C) cmovLL_mem_LTGENode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovII_reg_LTGENode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovII_reg_LTGENode::cisc_version( int offset, Compile* C ) {
  cmovII_mem_LTGENode *node = new (C) cmovII_mem_LTGENode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovLL_reg_EQNENode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovLL_reg_EQNENode::cisc_version( int offset, Compile* C ) {
  cmovLL_mem_EQNENode *node = new (C) cmovLL_mem_EQNENode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovII_reg_EQNENode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovII_reg_EQNENode::cisc_version( int offset, Compile* C ) {
  cmovII_mem_EQNENode *node = new (C) cmovII_mem_EQNENode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovLL_reg_LEGTNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_LONG_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovLL_reg_LEGTNode::cisc_version( int offset, Compile* C ) {
  cmovLL_mem_LEGTNode *node = new (C) cmovLL_mem_LEGTNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


void cmovII_reg_LEGTNode::use_cisc_RegMask() {
  _cisc_RegMask = &STACK_OR_E_REG_mask;
}

// Build CISC version of this instruction
MachNode *cmovII_reg_LEGTNode::cisc_version( int offset, Compile* C ) {
  cmovII_mem_LEGTNode *node = new (C) cmovII_mem_LEGTNode();

  // Copy _idx, inputs and operands to new node
  fill_new_machnode(node, C);
  // Construct operand to access [stack_pointer + offset]
  node->set_opnd_array(cisc_operand(), new (C) indOffset32Oper(offset));

  return node;
}


// Copy _idx, inputs and operands to new node
void MachNode::fill_new_machnode( MachNode* node, Compile* C) const {
  // New node must use same node index
  node->set_idx( _idx );
  // Copy machine-independent inputs
  for( uint j = 0; j < req(); j++ ) {
    node->add_req(in(j));
  }
  // Copy my operands, except for cisc position
  int nopnds = num_opnds();
  assert( node->num_opnds() == (uint)nopnds, "Must have same number of operands");
  MachOper **to = node->_opnds;
  for( int i = 0; i < nopnds; i++ ) {
    if( i != cisc_operand() ) 
      to[i] = _opnds[i]->clone(C);
  }
}

void jmpDirNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(1));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpLoopEndNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpLoopEndUNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpLoopEndUCFNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConUNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConUCFNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConUCF2Node::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpDir_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(1));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpCon_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpLoopEnd_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpLoopEndU_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpLoopEndUCF_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConU_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConUCF_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void jmpConUCF2_shortNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void cmpL_LTGENode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void cmpL_EQNENode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void cmpL_LEGTNode::label_set( Label& label, uint block_num ) {
  labelOper* oper  = (labelOper*)(opnd_array(3));
  oper->_label     = &label;
  oper->_block_num = block_num;
}
void CallStaticJavaDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallStaticJavaHandleNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallDynamicJavaDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallRuntimeDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallLeafDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

void CallLeafNoFPDirectNode::method_set( intptr_t method ) {
  ((methodOper*)opnd_array(1))->_method = method;
}

int  popCountI_memNode::reloc()   const {
  return  1;
}

int  popCountL_memNode::reloc()   const {
  return  1;
}

int  loadBNode::reloc()   const {
  return  1;
}

int  loadB2LNode::reloc()   const {
  return  1;
}

int  loadUBNode::reloc()   const {
  return  1;
}

int  loadUB2LNode::reloc()   const {
  return  1;
}

int  loadUB2L_immI8Node::reloc()   const {
  return  1;
}

int  loadSNode::reloc()   const {
  return  1;
}

int  loadS2BNode::reloc()   const {
  return  1;
}

int  loadS2LNode::reloc()   const {
  return  1;
}

int  loadUSNode::reloc()   const {
  return  1;
}

int  loadUS2BNode::reloc()   const {
  return  1;
}

int  loadUS2LNode::reloc()   const {
  return  1;
}

int  loadUS2L_immI_255Node::reloc()   const {
  return  1;
}

int  loadUS2L_immI16Node::reloc()   const {
  return  1;
}

int  loadINode::reloc()   const {
  return  1;
}

int  loadI2BNode::reloc()   const {
  return  1;
}

int  loadI2UBNode::reloc()   const {
  return  1;
}

int  loadI2SNode::reloc()   const {
  return  1;
}

int  loadI2USNode::reloc()   const {
  return  1;
}

int  loadI2LNode::reloc()   const {
  return  1;
}

int  loadI2L_immI_255Node::reloc()   const {
  return  1;
}

int  loadI2L_immI_65535Node::reloc()   const {
  return  1;
}

int  loadI2L_immINode::reloc()   const {
  return  1;
}

int  loadUI2LNode::reloc()   const {
  return  1;
}

int  loadLNode::reloc()   const {
  return  1;
}

int  loadL_volatileNode::reloc()   const {
  return  1;
}

int  loadLX_volatileNode::reloc()   const {
  return  1;
}

int  loadLX_reg_volatileNode::reloc()   const {
  return  1;
}

int  loadRangeNode::reloc()   const {
  return  1;
}

int  loadPNode::reloc()   const {
  return  1;
}

int  loadKlassNode::reloc()   const {
  return  1;
}

int  loadDNode::reloc()   const {
  return  1;
}

int  loadXDNode::reloc()   const {
  return  1;
}

int  loadXD_partialNode::reloc()   const {
  return  1;
}

int  loadXNode::reloc()   const {
  return  1;
}

int  loadFNode::reloc()   const {
  return  1;
}

int  loadA8BNode::reloc()   const {
  return  1;
}

int  loadA4SNode::reloc()   const {
  return  1;
}

int  loadA4CNode::reloc()   const {
  return  1;
}

int  load2IUNode::reloc()   const {
  return  1;
}

int  loadA2FNode::reloc()   const {
  return  1;
}

int  loadConPNode::reloc()   const {
  return  1;
}

int  loadConFNode::reloc()   const {
  return  2;
}

int  loadConXNode::reloc()   const {
  return  2;
}

int  loadConX0Node::reloc()   const {
  return  2;
}

int  loadConDNode::reloc()   const {
  return  2;
}

int  loadConXDNode::reloc()   const {
  return  2;
}

int  loadConXD0Node::reloc()   const {
  return  2;
}

int  prefetchr0Node::reloc()   const {
  return  1;
}

int  prefetchrNode::reloc()   const {
  return  1;
}

int  prefetchrNTANode::reloc()   const {
  return  1;
}

int  prefetchrT0Node::reloc()   const {
  return  1;
}

int  prefetchrT2Node::reloc()   const {
  return  1;
}

int  prefetchw0Node::reloc()   const {
  return  1;
}

int  prefetchwNode::reloc()   const {
  return  1;
}

int  prefetchwNTANode::reloc()   const {
  return  1;
}

int  prefetchwT0Node::reloc()   const {
  return  1;
}

int  prefetchwT2Node::reloc()   const {
  return  1;
}

int  storeBNode::reloc()   const {
  return  2;
}

int  storeCNode::reloc()   const {
  return  2;
}

int  storeINode::reloc()   const {
  return  2;
}

int  storeLNode::reloc()   const {
  return  2;
}

int  storeL2INode::reloc()   const {
  return  2;
}

int  storeL_volatileNode::reloc()   const {
  return  2;
}

int  storeLX_volatileNode::reloc()   const {
  return  2;
}

int  storeLX_reg_volatileNode::reloc()   const {
  return  2;
}

int  storePNode::reloc()   const {
  return  2;
}

int  storeImmINode::reloc()   const {
  return  2;
}

int  storeImmI16Node::reloc()   const {
  return  2;
}

int  storeImmPNode::reloc()   const {
  return  3;
}

int  storeImmBNode::reloc()   const {
  return  2;
}

int  storeA8BNode::reloc()   const {
  return  2;
}

int  storeA4CNode::reloc()   const {
  return  2;
}

int  storeA2INode::reloc()   const {
  return  2;
}

int  storeImmCMNode::reloc()   const {
  return  2;
}

int  storeDNode::reloc()   const {
  return  2;
}

int  storeD_roundedNode::reloc()   const {
  return  2;
}

int  storeXDNode::reloc()   const {
  return  2;
}

int  storeXNode::reloc()   const {
  return  2;
}

int  storeA2FNode::reloc()   const {
  return  2;
}

int  storeFNode::reloc()   const {
  return  2;
}

int  storeF_roundedNode::reloc()   const {
  return  2;
}

int  storeF_DroundedNode::reloc()   const {
  return  2;
}

int  storeF_immNode::reloc()   const {
  return  3;
}

int  storeX_immNode::reloc()   const {
  return  3;
}

int  cmovI_memNode::reloc()   const {
  return  1;
}

int  cmovI_memUNode::reloc()   const {
  return  1;
}

int  cmovI_memUCFNode::reloc()   const {
  return  1;
}

int  addI_eReg_memNode::reloc()   const {
  return  1;
}

int  addI_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  addI_mem_eRegNode::reloc()   const {
  return  3;
}

int  addI_mem_eReg_0Node::reloc()   const {
  return  3;
}

int  addI_mem_immNode::reloc()   const {
  return  3;
}

int  incI_memNode::reloc()   const {
  return  3;
}

int  decI_memNode::reloc()   const {
  return  3;
}

int  loadPLockedNode::reloc()   const {
  return  1;
}

int  loadLLockedNode::reloc()   const {
  return  1;
}

int  loadLX_LockedNode::reloc()   const {
  return  1;
}

int  loadLX_reg_LockedNode::reloc()   const {
  return  1;
}

int  storePConditionalNode::reloc()   const {
  return  1;
}

int  storeIConditionalNode::reloc()   const {
  return  1;
}

int  storeLConditionalNode::reloc()   const {
  return  1;
}

int  subI_eReg_memNode::reloc()   const {
  return  1;
}

int  subI_mem_eRegNode::reloc()   const {
  return  3;
}

int  mulI_mem_immNode::reloc()   const {
  return  1;
}

int  mulINode::reloc()   const {
  return  1;
}

int  mulI_0Node::reloc()   const {
  return  1;
}

int  sarI_mem_1Node::reloc()   const {
  return  3;
}

int  sarI_mem_immNode::reloc()   const {
  return  3;
}

int  andI_eReg_memNode::reloc()   const {
  return  1;
}

int  andI_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  andI_mem_eRegNode::reloc()   const {
  return  3;
}

int  andI_mem_eReg_0Node::reloc()   const {
  return  3;
}

int  andI_mem_immNode::reloc()   const {
  return  3;
}

int  orI_eReg_memNode::reloc()   const {
  return  1;
}

int  orI_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  orI_mem_eRegNode::reloc()   const {
  return  3;
}

int  orI_mem_eReg_0Node::reloc()   const {
  return  3;
}

int  orI_mem_immNode::reloc()   const {
  return  3;
}

int  xorI_eReg_memNode::reloc()   const {
  return  1;
}

int  xorI_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  xorI_mem_eRegNode::reloc()   const {
  return  3;
}

int  xorI_mem_eReg_0Node::reloc()   const {
  return  3;
}

int  xorI_mem_immNode::reloc()   const {
  return  3;
}

int  addL_eReg_memNode::reloc()   const {
  return  1;
}

int  addL_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  subL_eReg_memNode::reloc()   const {
  return  1;
}

int  andL_eReg_memNode::reloc()   const {
  return  1;
}

int  andL_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  orl_eReg_memNode::reloc()   const {
  return  1;
}

int  orl_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  xorl_eReg_memNode::reloc()   const {
  return  1;
}

int  xorl_eReg_mem_0Node::reloc()   const {
  return  1;
}

int  cmpD_0Node::reloc()   const {
  return  1;
}

int  cmpXD_ccmemNode::reloc()   const {
  return  1;
}

int  cmpXD_ccmemCFNode::reloc()   const {
  return  1;
}

int  cmpXD_regmemNode::reloc()   const {
  return  1;
}

int  subD_reg_memNode::reloc()   const {
  return  1;
}

int  addD_reg_memNode::reloc()   const {
  return  1;
}

int  addD_reg_mem_0Node::reloc()   const {
  return  1;
}

int  addD_mem_regNode::reloc()   const {
  return  3;
}

int  addD_mem_reg_0Node::reloc()   const {
  return  3;
}

int  addD_reg_imm1Node::reloc()   const {
  return  1;
}

int  addD_reg_immNode::reloc()   const {
  return  1;
}

int  addD_reg_imm_roundNode::reloc()   const {
  return  1;
}

int  addXD_immNode::reloc()   const {
  return  1;
}

int  addXD_memNode::reloc()   const {
  return  1;
}

int  addXD_mem_0Node::reloc()   const {
  return  1;
}

int  subXD_immNode::reloc()   const {
  return  1;
}

int  subXD_memNode::reloc()   const {
  return  1;
}

int  mulXD_immNode::reloc()   const {
  return  1;
}

int  mulXD_memNode::reloc()   const {
  return  1;
}

int  mulXD_mem_0Node::reloc()   const {
  return  1;
}

int  divXD_immNode::reloc()   const {
  return  1;
}

int  divXD_memNode::reloc()   const {
  return  1;
}

int  mulD_reg_immNode::reloc()   const {
  return  1;
}

int  mulD_reg_memNode::reloc()   const {
  return  1;
}

int  mulD_reg_mem_0Node::reloc()   const {
  return  1;
}

int  mulD_reg_mem_ciscNode::reloc()   const {
  return  1;
}

int  mulD_reg_mem_cisc_0Node::reloc()   const {
  return  1;
}

int  cmpF_0Node::reloc()   const {
  return  1;
}

int  cmpX_ccmemNode::reloc()   const {
  return  1;
}

int  cmpX_ccmemCFNode::reloc()   const {
  return  1;
}

int  cmpX_regmemNode::reloc()   const {
  return  1;
}

int  addX_immNode::reloc()   const {
  return  1;
}

int  addX_memNode::reloc()   const {
  return  1;
}

int  addX_mem_0Node::reloc()   const {
  return  1;
}

int  subX_immNode::reloc()   const {
  return  1;
}

int  subX_memNode::reloc()   const {
  return  1;
}

int  mulX_immNode::reloc()   const {
  return  1;
}

int  mulX_memNode::reloc()   const {
  return  1;
}

int  mulX_mem_0Node::reloc()   const {
  return  1;
}

int  divX_immNode::reloc()   const {
  return  1;
}

int  divX_memNode::reloc()   const {
  return  1;
}

int  sqrtX_memNode::reloc()   const {
  return  1;
}

int  sqrtXD_memNode::reloc()   const {
  return  1;
}

int  addF24_reg_memNode::reloc()   const {
  return  1;
}

int  addF24_reg_mem_0Node::reloc()   const {
  return  1;
}

int  addF_reg_memNode::reloc()   const {
  return  1;
}

int  addF_reg_mem_0Node::reloc()   const {
  return  1;
}

int  addF24_mem_regNode::reloc()   const {
  return  1;
}

int  addF24_mem_ciscNode::reloc()   const {
  return  2;
}

int  addF24_mem_cisc_0Node::reloc()   const {
  return  2;
}

int  addF24_mem_memNode::reloc()   const {
  return  2;
}

int  addF24_reg_immNode::reloc()   const {
  return  1;
}

int  addF_reg_immNode::reloc()   const {
  return  1;
}

int  mulF24_reg_memNode::reloc()   const {
  return  1;
}

int  mulF24_reg_mem_0Node::reloc()   const {
  return  1;
}

int  mulF_reg_memNode::reloc()   const {
  return  1;
}

int  mulF_reg_mem_0Node::reloc()   const {
  return  1;
}

int  mulF24_mem_memNode::reloc()   const {
  return  2;
}

int  mulF24_reg_immNode::reloc()   const {
  return  1;
}

int  mulF_reg_immNode::reloc()   const {
  return  1;
}

int  mulF_reg_load1Node::reloc()   const {
  return  1;
}

int  mulF_reg_load1_0Node::reloc()   const {
  return  1;
}

int  addF_mulF_reg_load1Node::reloc()   const {
  return  1;
}

int  addF_mulF_reg_load1_1Node::reloc()   const {
  return  1;
}

int  addF_mulF_reg_load1_0Node::reloc()   const {
  return  1;
}

int  addF_mulF_reg_load1_2Node::reloc()   const {
  return  1;
}

int  convI2XD_memNode::reloc()   const {
  return  1;
}

int  convI2D_memNode::reloc()   const {
  return  1;
}

int  convI2F_SSF_memNode::reloc()   const {
  return  1;
}

int  convI2F_memNode::reloc()   const {
  return  1;
}

int  Repl2F_immXF0Node::reloc()   const {
  return  1;
}

int  compI_eReg_memNode::reloc()   const {
  return  1;
}

int  testI_reg_memNode::reloc()   const {
  return  1;
}

int  compU_eReg_memNode::reloc()   const {
  return  1;
}

int  compP_eReg_immNode::reloc()   const {
  return  1;
}

int  compP_eReg_memNode::reloc()   const {
  return  1;
}

int  compP_mem_eRegNode::reloc()   const {
  return  1;
}

int  testP_regNode::reloc()   const {
  return  1;
}

int  testP_Reg_memNode::reloc()   const {
  return  1;
}

int  partialSubtypeCheck_vs_ZeroNode::reloc()   const {
  return  1;
}

int  cmovLL_mem_LTGENode::reloc()   const {
  return  1;
}

int  cmovII_mem_LTGENode::reloc()   const {
  return  1;
}

int  cmovLL_mem_EQNENode::reloc()   const {
  return  1;
}

int  cmovII_mem_EQNENode::reloc()   const {
  return  1;
}

int  cmovLL_mem_LEGTNode::reloc()   const {
  return  1;
}

int  cmovII_mem_LEGTNode::reloc()   const {
  return  1;
}

int  CallStaticJavaDirectNode::reloc()   const {
  return  1;
}

int  CallStaticJavaHandleNode::reloc()   const {
  return  1;
}

int  CallDynamicJavaDirectNode::reloc()   const {
  return  1;
}

int  CallRuntimeDirectNode::reloc()   const {
  return  1;
}

int  CallLeafDirectNode::reloc()   const {
  return  1;
}

int  CallLeafNoFPDirectNode::reloc()   const {
  return  1;
}

int  RetNode::reloc()   const {
  return  1;
}

int  TailCalljmpIndNode::reloc()   const {
  return  1;
}

int  tailjmpIndNode::reloc()   const {
  return  1;
}

int  RethrowExceptionNode::reloc()   const {
  return  1;
}

int  safePoint_pollNode::reloc()   const {
  return  1;
}


void  bytes_reverse_intNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 8888 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1741 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_cc(cbuf, (0xC8 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 8895 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  bytes_reverse_longNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1745 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int destlo = opnd_array(1)->reg(ra_,this,idx1);
    int desthi = HIGH_FROM_LOW(destlo);
    // bswap lo
    emit_opcode(cbuf, 0x0F);
    emit_cc(cbuf, 0xC8, destlo);
    // bswap hi
    emit_opcode(cbuf, 0x0F);
    emit_cc(cbuf, 0xC8, desthi);
    // xchg lo and hi
    emit_opcode(cbuf, 0x87);
    emit_rm(cbuf, 0x3, destlo, desthi);
  
#line 8918 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  bytes_reverse_unsigned_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6332 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ bswapl(opnd_array(1)->as_Register(ra_,this,idx1));
    __ shrl(opnd_array(1)->as_Register(ra_,this,idx1), 16); 
  
#line 8938 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  bytes_reverse_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6344 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ bswapl(opnd_array(1)->as_Register(ra_,this,idx1));
    __ sarl(opnd_array(1)->as_Register(ra_,this,idx1), 16); 
  
#line 8958 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  countLeadingZerosINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6360 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ lzcntl(opnd_array(0)->as_Register(ra_,this), opnd_array(1)->as_Register(ra_,this,idx1));
  
#line 8977 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  countLeadingZerosI_bsrNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6377 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    Register Rsrc = opnd_array(1)->as_Register(ra_,this,idx1);
    Label skip;
    __ bsrl(Rdst, Rsrc);
    __ jccb(Assembler::notZero, skip);
    __ movl(Rdst, -1);
    __ bind(skip);
    __ negl(Rdst);
    __ addl(Rdst, BitsPerInt - 1);
  
#line 9004 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  countLeadingZerosLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6401 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(2)->as_Register(ra_,this,idx2);
    Register Rsrc = opnd_array(1)->as_Register(ra_,this,idx1);
    Label done;
    __ lzcntl(Rdst, HIGH_FROM_LOW(Rsrc));
    __ jccb(Assembler::carryClear, done);
    __ lzcntl(Rdst, Rsrc);
    __ addl(Rdst, BitsPerInt);
    __ bind(done);
  
#line 9031 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  countLeadingZerosL_bsrNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6430 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(2)->as_Register(ra_,this,idx2);
    Register Rsrc = opnd_array(1)->as_Register(ra_,this,idx1);
    Label msw_is_zero;
    Label not_zero;
    __ bsrl(Rdst, HIGH_FROM_LOW(Rsrc));
    __ jccb(Assembler::zero, msw_is_zero);
    __ addl(Rdst, BitsPerInt);
    __ jmpb(not_zero);
    __ bind(msw_is_zero);
    __ bsrl(Rdst, Rsrc);
    __ jccb(Assembler::notZero, not_zero);
    __ movl(Rdst, -1);
    __ bind(not_zero);
    __ negl(Rdst);
    __ addl(Rdst, BitsPerLong - 1);
  
#line 9065 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  countTrailingZerosINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6458 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    Label done;
    __ bsfl(Rdst, opnd_array(1)->as_Register(ra_,this,idx1));
    __ jccb(Assembler::notZero, done);
    __ movl(Rdst, BitsPerInt);
    __ bind(done);
  
#line 9089 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  countTrailingZerosLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6481 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(2)->as_Register(ra_,this,idx2);
    Register Rsrc = opnd_array(1)->as_Register(ra_,this,idx1);
    Label msw_not_zero;
    Label done;
    __ bsfl(Rdst, Rsrc);
    __ jccb(Assembler::notZero, done);
    __ bsfl(Rdst, HIGH_FROM_LOW(Rsrc));
    __ jccb(Assembler::notZero, msw_not_zero);
    __ movl(Rdst, BitsPerInt);
    __ bind(msw_not_zero);
    __ addl(Rdst, BitsPerInt);
    __ bind(done);
  
#line 9120 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  popCountINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6506 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ popcntl(opnd_array(0)->as_Register(ra_,this), opnd_array(1)->as_Register(ra_,this,idx1));
  
#line 9139 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  popCountI_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6517 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ popcntl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9158 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  popCountLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6532 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ popcntl(opnd_array(2)->as_Register(ra_,this,idx2), opnd_array(1)->as_Register(ra_,this,idx1));
    __ popcntl(opnd_array(3)->as_Register(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
    __ addl(opnd_array(2)->as_Register(ra_,this,idx2), opnd_array(3)->as_Register(ra_,this,idx3));
  
#line 9181 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  popCountL_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6549 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    //__ popcntl($dst$$Register, $mem$$Address$$first);
    //__ popcntl($tmp$$Register, $mem$$Address$$second);
    __ popcntl(opnd_array(2)->as_Register(ra_,this,idx2), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), false));
    __ popcntl(opnd_array(3)->as_Register(ra_,this,idx3), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1) + 4, false));
    __ addl(opnd_array(2)->as_Register(ra_,this,idx2), opnd_array(3)->as_Register(ra_,this,idx3));
  
#line 9206 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadBNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6569 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movsbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9225 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadB2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6586 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movsbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ movl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), opnd_array(0)->as_Register(ra_,this)); // This is always a different register.
    __ sarl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), 7); // 24+1 MSB are already signed extended.
  
#line 9246 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUBNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6602 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movzbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9265 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUB2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6618 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movzbl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
  
#line 9286 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUB2L_immI8Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6635 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movzbl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
    __ andl(Rdst, opnd_array(2)->constant());
  
#line 9309 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadSNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6651 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movswl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9328 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadS2BNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6664 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movsbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9348 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadS2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6680 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movswl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ movl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), opnd_array(0)->as_Register(ra_,this)); // This is always a different register.
    __ sarl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), 15); // 16+1 MSB are already signed extended.
  
#line 9369 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUSNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movzwl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9388 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUS2BNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6709 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movsbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9408 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUS2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6724 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movzwl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)));
  
#line 9428 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUS2L_immI_255Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6739 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movzbl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
  
#line 9450 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUS2L_immI16Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6755 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movzwl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
    __ andl(Rdst, opnd_array(2)->constant());
  
#line 9473 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6771 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9492 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2BNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6784 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movsbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9512 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2UBNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6796 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movzbl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9532 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2SNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6808 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movswl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9552 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2USNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6820 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movzwl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 9572 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6836 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ movl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), opnd_array(0)->as_Register(ra_,this)); // This is always a different register.
    __ sarl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), 31);
  
#line 9593 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2L_immI_255Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6852 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movzbl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
  
#line 9615 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2L_immI_65535Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6867 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movzwl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
  
#line 9637 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadI2L_immINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6883 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Rdst = opnd_array(0)->as_Register(ra_,this);
    __ movl(Rdst, Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(Rdst), HIGH_FROM_LOW(Rdst));
    __ andl(Rdst, opnd_array(2)->constant());
  
#line 9660 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadUI2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6901 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movl(opnd_array(0)->as_Register(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xorl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)));
  
#line 9680 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 6919 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Address Amemlo = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), false);
    Address Amemhi = Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1) + 4, false);
    __ movl(opnd_array(0)->as_Register(ra_,this), Amemlo);
    __ movl(HIGH_FROM_LOW(opnd_array(0)->as_Register(ra_,this)), Amemhi);
  
#line 9702 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadL_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 4246 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0xDF);
    int rm_byte_opcode = 0x05;
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
    store_to_stackslot( cbuf, 0x0DF, 0x07, opnd_array(0)->disp(ra_,this,0) );
  
#line 9723 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadLX_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 4258 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // Atomic long load
      // UseXmmLoadAndClearUpper ? movsd $tmp,$mem : movlpd $tmp,$mem
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0x10 : 0x12);
      int base     = opnd_array(1)->base(ra_,this,idx1);
      int index    = opnd_array(1)->index(ra_,this,idx1);
      int scale    = opnd_array(1)->scale();
      int displace = opnd_array(1)->disp(ra_,this,idx1);
      bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), base, index, scale, displace, disp_is_oop);
    }
    { // MOVSD $dst,$tmp ! atomic long store
      emit_opcode(cbuf,0xF2);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x11);
      int base     = opnd_array(0)->base(ra_,this,idx0);
      int index    = opnd_array(0)->index(ra_,this,idx0);
      int scale    = opnd_array(0)->scale();
      int displace = opnd_array(0)->disp(ra_,this,0);
      bool disp_is_oop = opnd_array(0)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), base, index, scale, displace, disp_is_oop);
    }
  
#line 9759 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadLX_reg_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 4284 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // Atomic long load
      // UseXmmLoadAndClearUpper ? movsd $tmp,$mem : movlpd $tmp,$mem
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0x10 : 0x12);
      int base     = opnd_array(1)->base(ra_,this,idx1);
      int index    = opnd_array(1)->index(ra_,this,idx1);
      int scale    = opnd_array(1)->scale();
      int displace = opnd_array(1)->disp(ra_,this,idx1);
      bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), base, index, scale, displace, disp_is_oop);
    }
    { // MOVD $dst.lo,$tmp
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x7E);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(0)->reg(ra_,this));
    }
    { // PSRLQ $tmp,32
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x73);
      emit_rm(cbuf, 0x3, 0x02, opnd_array(2)->reg(ra_,this,idx2));
      emit_d8(cbuf, 0x20);
    }
    { // MOVD $dst.hi,$tmp
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x7E);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)));
    }
  
#line 9803 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadRangeNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 9816 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 9829 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 9842 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 9855 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadKlassNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 9868 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 9881 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*primary()*/));
  
#line 9894 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 9907 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 9915 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadXDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 9928 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 9935 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x10));
  
#line 9942 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 9955 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadXD_partialNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66));
  
#line 9968 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 9975 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x12));
  
#line 9982 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 9995 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadXNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 10008 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 10015 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x10));
  
#line 10022 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10035 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 10048 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10061 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 10069 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadA8BNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 3244 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(opnd_array(0)->as_XMMRegister(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 10083 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadA4SNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 3244 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(opnd_array(0)->as_XMMRegister(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 10097 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadA4CNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 3244 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(opnd_array(0)->as_XMMRegister(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 10111 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  load2IUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 3244 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(opnd_array(0)->as_XMMRegister(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 10125 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadA2FNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 3244 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(opnd_array(0)->as_XMMRegister(ra_,this), Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
  
#line 10139 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  leaP8Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 10152 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10165 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  leaP32Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 10178 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10191 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  leaPIdxOffNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 10204 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10217 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  leaPIdxScaleNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 10230 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10243 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  leaPIdxScaleOffNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 10256 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10269 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1991 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    emit_opcode(cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32(cbuf, opnd_array(1)->constant());
  
#line 10285 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConI0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 10298 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 10305 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1998 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    emit_opcode(cbuf, (0xB8 /*primary()*/) + opnd_array(0)->reg(ra_,this));
    
if ( opnd_array(1)->constant_is_oop() ) {
  emit_d32_reloc(cbuf, opnd_array(1)->constant(), relocInfo::oop_type, 0);
} else {
  emit_d32(cbuf, opnd_array(1)->constant());
};
  
#line 10326 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2005 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    int dst_enc = opnd_array(0)->reg(ra_,this);
    int src_con = opnd_array(1)->constantL() & 0x0FFFFFFFFL;
    if (src_con == 0) {
      // xor dst, dst
      emit_opcode(cbuf, 0x33);
      emit_rm(cbuf, 0x3, dst_enc, dst_enc);
    } else {
      emit_opcode(cbuf, (0xB8 /*primary()*/) + dst_enc);
      emit_d32(cbuf, src_con);
    }
  
#line 10350 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2020 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    int dst_enc = opnd_array(0)->reg(ra_,this) + 2;
    int src_con = ((julong)(opnd_array(1)->constantL())) >> 32;
    if (src_con == 0) {
      // xor dst, dst
      emit_opcode(cbuf, 0x33);
      emit_rm(cbuf, 0x3, dst_enc, dst_enc);
    } else {
      emit_opcode(cbuf, (0xB8 /*primary()*/) + dst_enc);
      emit_d32(cbuf, src_con);
    }
  
#line 10368 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConL0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2173 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x33 /*primary()*/));
    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 10382 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2178 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x33 /*secondary()*/));
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)), HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)));
  
#line 10390 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2053 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( is_positive_zero_float(opnd_array(1)->constantF())) {
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xEE);
    } else if( is_positive_one_float(opnd_array(1)->constantF())) {
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xE8);
    } else {
      emit_d8(cbuf, (0xD9 /*primary()*/));
      // Load immediate does not have a zero or sign extended version
      // for 8-bit immediates
      // First load to TOS, then move to dst
      emit_rm(cbuf, 0x0, 0x0, 0x5);
      emit_float_constant(cbuf, opnd_array(1)->constantF());
    }
  
#line 10416 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 10424 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConXNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 10437 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 10444 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x10));
  
#line 10451 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2070 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(0)->reg(ra_,this), 0x5);
    emit_float_constant(cbuf, opnd_array(1)->constantF());
  
#line 10459 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConX0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 10472 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x57));
  
#line 10479 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 10486 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2036 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( is_positive_zero_double(opnd_array(1)->constantD())) {
      // FLDZ
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xEE);
    } else if( is_positive_one_double(opnd_array(1)->constantD())) {
      // FLD1
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xE8);
    } else {
      emit_opcode(cbuf,0xDD);
      emit_rm(cbuf, 0x0, 0x0, 0x5);
      emit_double_constant(cbuf, opnd_array(1)->constantD());
    }
  
#line 10511 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 10519 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConXDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2080 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // UseXmmLoadAndClearUpper ? movsd(dst, con) : movlpd(dst, con)
    emit_opcode(cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode(cbuf, 0x0F);
    emit_opcode(cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    emit_rm(cbuf, 0x0, opnd_array(0)->reg(ra_,this), 0x5);
    emit_double_constant(cbuf, opnd_array(1)->constantD());
  
#line 10537 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConXD0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66));
  
#line 10550 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 10557 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x57));
  
#line 10564 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 10571 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadSSINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 10584 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10597 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadSSLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 10610 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10623 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*secondary()*/));
  
#line 10630 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 10643 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadSSPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 10656 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 10669 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadSSFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 10682 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2364 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    assert( !opnd_array(1)->disp_is_oop(), "No oops here because no relo info allowed" );
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, false);
  
#line 10695 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 10703 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadSSDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*primary()*/));
  
#line 10716 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2364 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    assert( !opnd_array(1)->disp_is_oop(), "No oops here because no relo info allowed" );
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, false);
  
#line 10729 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 10737 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchr0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  // User did not define which encode class to use.
}
uint  prefetchr0Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  prefetchrNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10761 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0d /*secondary()*/));
  
#line 10768 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10781 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchrNTANode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10794 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x18 /*secondary()*/));
  
#line 10801 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10814 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchrT0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10827 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x18 /*secondary()*/));
  
#line 10834 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x01);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10847 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchrT2Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10860 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x18 /*secondary()*/));
  
#line 10867 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x03);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10880 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchw0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  // User did not define which encode class to use.
}
uint  prefetchw0Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  prefetchwNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10904 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0D /*secondary()*/));
  
#line 10911 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x01);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10924 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchwNTANode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10937 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x18 /*secondary()*/));
  
#line 10944 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10957 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchwT0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 10970 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x18 /*secondary()*/));
  
#line 10977 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x01);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 10990 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  prefetchwT2Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 11003 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x18 /*secondary()*/));
  
#line 11010 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x03);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11023 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeBNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x88 /*primary()*/));
  
#line 11037 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11050 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeCNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*secondary()*/));
  
#line 11064 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*primary()*/));
  
#line 11071 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11084 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*primary()*/));
  
#line 11098 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11111 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*primary()*/));
  
#line 11125 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11138 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*secondary()*/));
  
#line 11145 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 11158 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeL2INode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 7494 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movl(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()), opnd_array(2)->as_Register(ra_,this,idx2));
  
#line 11178 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeL_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 11192 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = (EAX_enc);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11205 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4322 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0x0DF, 0x05, opnd_array(2)->disp(ra_,this,idx2) );
    cbuf.set_inst_mark();            // Mark start of FIST in case $mem has an oop
    emit_opcode(cbuf,0xDF);
    int rm_byte_opcode = 0x07;
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11221 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeLX_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 11236 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = (EAX_enc);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11249 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4335 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // Atomic long load
      // UseXmmLoadAndClearUpper ? movsd $tmp,[$src] : movlpd $tmp,[$src]
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0x10 : 0x12);
      int base     = opnd_array(2)->base(ra_,this,idx2);
      int index    = opnd_array(2)->index(ra_,this,idx2);
      int scale    = opnd_array(2)->scale();
      int displace = opnd_array(2)->disp(ra_,this,idx2);
      bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(3)->reg(ra_,this,idx3), base, index, scale, displace, disp_is_oop);
    }
    cbuf.set_inst_mark();            // Mark start of MOVSD in case $mem has an oop
    { // MOVSD $mem,$tmp ! atomic long store
      emit_opcode(cbuf,0xF2);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x11);
      int base     = opnd_array(1)->base(ra_,this,idx1);
      int index    = opnd_array(1)->index(ra_,this,idx1);
      int scale    = opnd_array(1)->scale();
      int displace = opnd_array(1)->disp(ra_,this,idx1);
      bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(3)->reg(ra_,this,idx3), base, index, scale, displace, disp_is_oop);
    }
  
#line 11279 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeLX_reg_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 11295 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = (EAX_enc);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11308 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4362 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // MOVD $tmp,$src.lo
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x6E);
      emit_rm(cbuf, 0x3, opnd_array(4)->reg(ra_,this,idx4), opnd_array(2)->reg(ra_,this,idx2));
    }
    { // MOVD $tmp2,$src.hi
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x6E);
      emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
    }
    { // PUNPCKLDQ $tmp,$tmp2
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x62);
      emit_rm(cbuf, 0x3, opnd_array(4)->reg(ra_,this,idx4), opnd_array(3)->reg(ra_,this,idx3));
    }
    cbuf.set_inst_mark();            // Mark start of MOVSD in case $mem has an oop
    { // MOVSD $mem,$tmp ! atomic long store
      emit_opcode(cbuf,0xF2);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x11);
      int base     = opnd_array(1)->base(ra_,this,idx1);
      int index    = opnd_array(1)->index(ra_,this,idx1);
      int scale    = opnd_array(1)->scale();
      int displace = opnd_array(1)->disp(ra_,this,idx1);
      bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(4)->reg(ra_,this,idx4), base, index, scale, displace, disp_is_oop);
    }
  
#line 11344 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storePNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*primary()*/));
  
#line 11358 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11371 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeImmINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC7 /*primary()*/));
  
#line 11385 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11398 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2195 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Output immediate
    emit_d32(cbuf, opnd_array(2)->constant());
  
#line 11406 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeImmI16Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1608 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x66);
  
#line 11420 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC7 /*primary()*/));
  
#line 11427 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11440 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2214 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Output immediate
    emit_d16(cbuf, opnd_array(2)->constant());
  
#line 11448 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeImmPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC7 /*primary()*/));
  
#line 11462 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11475 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2195 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Output immediate
    
if ( opnd_array(2)->constant_is_oop() ) {
  emit_d32_reloc(cbuf, opnd_array(2)->constant(), relocInfo::oop_type, 0);
} else {
  emit_d32(cbuf, opnd_array(2)->constant());
};
  
#line 11488 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeImmBNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC6 /*primary()*/));
  
#line 11502 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11515 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 11529 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeA8BNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3249 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()), opnd_array(2)->as_XMMRegister(ra_,this,idx2));
  
#line 11544 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeA4CNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3249 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()), opnd_array(2)->as_XMMRegister(ra_,this,idx2));
  
#line 11559 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeA2INode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3249 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()), opnd_array(2)->as_XMMRegister(ra_,this,idx2));
  
#line 11574 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeImmCMNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC6 /*primary()*/));
  
#line 11588 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11601 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 11615 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2418 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If src is FPR1, we can just FST to store it.
    // Else we need to FLD it to FPR1, then FSTP to store/pop it.
    int reg_encoding = 0x2; // Just store
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    if( opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc ) {
      reg_encoding = 0x3;  // Store & pop
      emit_opcode( cbuf, 0xD9 ); // FLD (i.e., push it)
      emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
    }
    cbuf.set_inst_mark();       // Mark start of opcode for reloc info in mem operand
    emit_opcode(cbuf,(0xDD /*primary()*/));
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11644 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeD_roundedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2418 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If src is FPR1, we can just FST to store it.
    // Else we need to FLD it to FPR1, then FSTP to store/pop it.
    int reg_encoding = 0x2; // Just store
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    if( opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc ) {
      reg_encoding = 0x3;  // Store & pop
      emit_opcode( cbuf, 0xD9 ); // FLD (i.e., push it)
      emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
    }
    cbuf.set_inst_mark();       // Mark start of opcode for reloc info in mem operand
    emit_opcode(cbuf,(0xDD /*primary()*/));
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11673 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeXDNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 11687 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 11694 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x11));
  
#line 11701 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11714 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeXNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 11728 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 11735 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x11));
  
#line 11742 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11755 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeA2FNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3249 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movq(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()), opnd_array(2)->as_XMMRegister(ra_,this,idx2));
  
#line 11770 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2418 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If src is FPR1, we can just FST to store it.
    // Else we need to FLD it to FPR1, then FSTP to store/pop it.
    int reg_encoding = 0x2; // Just store
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    if( opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc ) {
      reg_encoding = 0x3;  // Store & pop
      emit_opcode( cbuf, 0xD9 ); // FLD (i.e., push it)
      emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
    }
    cbuf.set_inst_mark();       // Mark start of opcode for reloc info in mem operand
    emit_opcode(cbuf,(0xD9 /*primary()*/));
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11799 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeF_roundedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2418 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If src is FPR1, we can just FST to store it.
    // Else we need to FLD it to FPR1, then FSTP to store/pop it.
    int reg_encoding = 0x2; // Just store
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    if( opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc ) {
      reg_encoding = 0x3;  // Store & pop
      emit_opcode( cbuf, 0xD9 ); // FLD (i.e., push it)
      emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
    }
    cbuf.set_inst_mark();       // Mark start of opcode for reloc info in mem operand
    emit_opcode(cbuf,(0xD9 /*primary()*/));
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11828 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeF_DroundedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2418 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If src is FPR1, we can just FST to store it.
    // Else we need to FLD it to FPR1, then FSTP to store/pop it.
    int reg_encoding = 0x2; // Just store
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    if( opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc ) {
      reg_encoding = 0x3;  // Store & pop
      emit_opcode( cbuf, 0xD9 ); // FLD (i.e., push it)
      emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
    }
    cbuf.set_inst_mark();       // Mark start of opcode for reloc info in mem operand
    emit_opcode(cbuf,(0xD9 /*primary()*/));
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11857 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeF_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC7 /*primary()*/));
  
#line 11871 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11884 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2200 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Output Float immediate bits
    jfloat jf = opnd_array(2)->constantF();
    int    jf_as_bits = jint_cast( jf );
    emit_d32(cbuf, jf_as_bits);
  
#line 11894 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeX_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC7 /*primary()*/));
  
#line 11908 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 11921 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2207 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Output Float immediate bits
    jfloat jf = opnd_array(2)->constantF();
    int    jf_as_bits = jint_cast( jf );
    emit_d32(cbuf, jf_as_bits);
  
#line 11931 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeSSINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2606 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0x89 /*primary()*/), opnd_array(1)->reg(ra_,this,idx1), opnd_array(0)->disp(ra_,this,0) );
  
#line 11944 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeSSPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2606 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0x89 /*primary()*/), opnd_array(1)->reg(ra_,this,idx1), opnd_array(0)->disp(ra_,this,0) );
  
#line 11957 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeSSLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*primary()*/));
  
#line 11970 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(0)->base(ra_,this,idx0);
    int index = opnd_array(0)->index(ra_,this,idx0);
    int scale = opnd_array(0)->scale();
    int displace = opnd_array(0)->disp(ra_,this,0);
    bool disp_is_oop = opnd_array(0)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 11983 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*secondary()*/));
  
#line 11990 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(0)->base(ra_,this,idx0);
    int index = opnd_array(0)->index(ra_,this,idx0);
    int scale = opnd_array(0)->scale();
    int displace = opnd_array(0)->disp(ra_,this,0) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(0)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 12003 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  membar_acquireNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  membar_acquireNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  membar_acquire_lockNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  membar_acquire_lockNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  membar_releaseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  membar_releaseNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  membar_release_lockNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  membar_release_lockNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  membar_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 7851 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ membar(Assembler::StoreLoad);
  
#line 12066 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  unnecessary_membar_volatileNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  unnecessary_membar_volatileNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  castX2PNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
void  castP2XNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2156 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    encode_Copy( cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 12097 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovI_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12114 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12121 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovI_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12138 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12145 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovI_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12162 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12175 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovI_memUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12192 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12205 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovP_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12222 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12229 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovP_reg_nonP6Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1790 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Invert sense of branch from sense of CMOV
    emit_cc( cbuf, 0x70, (opnd_array(1)->ccode()^1) );
    emit_d8( cbuf, (0x2) );
  
#line 12247 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8b /*primary()*/));
  
#line 12254 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12261 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovP_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12278 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12285 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovD_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1783 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int op = 0xDA00 + opnd_array(1)->ccode() + (opnd_array(4)->reg(ra_,this,idx4)-1);
    emit_d8(cbuf, op >> 8 );
    emit_d8(cbuf, op & 255);
  
#line 12303 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovF_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1783 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int op = 0xDA00 + opnd_array(1)->ccode() + (opnd_array(4)->reg(ra_,this,idx4)-1);
    emit_d8(cbuf, op >> 8 );
    emit_d8(cbuf, op & 255);
  
#line 12321 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovD_regSNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1790 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Invert sense of branch from sense of CMOV
    emit_cc( cbuf, 0x70, (opnd_array(1)->ccode()^1) );
    emit_d8( cbuf, (0x4) );
  
#line 12339 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(4)->reg(ra_,this,idx4) );   // FLD ST(i-1)
  
#line 12347 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xdd /*primary()*/));
  
#line 12354 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x3 /*secondary()*/), opnd_array(3)->reg(ra_,this,idx3) );
  
#line 12361 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovF_regSNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1790 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Invert sense of branch from sense of CMOV
    emit_cc( cbuf, 0x70, (opnd_array(1)->ccode()^1) );
    emit_d8( cbuf, (0x4) );
  
#line 12379 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(4)->reg(ra_,this,idx4) );
  
#line 12387 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xdd /*primary()*/));
  
#line 12394 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x3 /*secondary()*/), opnd_array(3)->reg(ra_,this,idx3) );
  
#line 12401 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovX_regSNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8076 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label skip;
    // Invert sense of branch from sense of CMOV
    __ jccb((Assembler::Condition)(opnd_array(1)->ccode()^1), skip);
    __ movflt(opnd_array(3)->as_XMMRegister(ra_,this,idx3), opnd_array(4)->as_XMMRegister(ra_,this,idx4));
    __ bind(skip);
  
#line 12427 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovXD_regSNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8094 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label skip;
    // Invert sense of branch from sense of CMOV
    __ jccb((Assembler::Condition)(opnd_array(1)->ccode()^1), skip);
    __ movdbl(opnd_array(3)->as_XMMRegister(ra_,this,idx3), opnd_array(4)->as_XMMRegister(ra_,this,idx4));
    __ bind(skip);
  
#line 12453 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovX_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8112 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label skip;
    // Invert sense of branch from sense of CMOV
    __ jccb((Assembler::Condition)(opnd_array(1)->ccode()^1), skip);
    __ movflt(opnd_array(3)->as_XMMRegister(ra_,this,idx3), opnd_array(4)->as_XMMRegister(ra_,this,idx4));
    __ bind(skip);
  
#line 12479 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  fcmovXD_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8139 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label skip;
    // Invert sense of branch from sense of CMOV
    __ jccb((Assembler::Condition)(opnd_array(1)->ccode()^1), skip);
    __ movdbl(opnd_array(3)->as_XMMRegister(ra_,this,idx3), opnd_array(4)->as_XMMRegister(ra_,this,idx4));
    __ bind(skip);
  
#line 12505 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovL_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12522 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2183 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12529 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12537 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3)), HIGH_FROM_LOW(opnd_array(4)->reg(ra_,this,idx4)));
  
#line 12544 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovL_regUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12561 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2183 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 12568 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 12576 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3)), HIGH_FROM_LOW(opnd_array(4)->reg(ra_,this,idx4)));
  
#line 12583 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x03 /*primary()*/));
  
#line 12597 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 12604 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  addI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  addI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 12630 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 12644 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  incI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1668 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x40 /*primary()*/) + opnd_array(1)->reg(ra_,this,idx1));
  
#line 12658 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  incI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 1, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 1);
}
void  leaI_eReg_immINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 12676 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2384 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base         = opnd_array(1)->reg(ra_,this,idx1);      // 0xFFFFFFFF indicates no base
    int index        = 0x04;            // 0x04 indicates no index
    int scale        = 0x00;            // 0x00 indicates no scale
    int displace     = opnd_array(2)->constant(); // 0x00 indicates no displacement
    bool disp_is_oop = false;
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12689 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  leaP_eReg_immINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8D /*primary()*/));
  
#line 12703 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2384 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base         = opnd_array(1)->reg(ra_,this,idx1);      // 0xFFFFFFFF indicates no base
    int index        = 0x04;            // 0x04 indicates no index
    int scale        = 0x00;            // 0x00 indicates no scale
    int displace     = opnd_array(2)->constant(); // 0x00 indicates no displacement
    bool disp_is_oop = false;
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12716 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  decI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1668 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x48 /*primary()*/) + opnd_array(1)->reg(ra_,this,idx1));
  
#line 12730 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  decI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 1, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 1);
}
void  addP_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x03 /*primary()*/));
  
#line 12748 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 12755 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  addP_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  addP_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 12781 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 12795 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addI_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x03 /*primary()*/));
  
#line 12809 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12822 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addI_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x03 /*primary()*/));
  
#line 12836 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12849 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addI_mem_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x01 /*primary()*/));
  
#line 12863 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12876 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addI_mem_eReg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x01 /*primary()*/));
  
#line 12890 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 12903 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addI_mem_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1674 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);
    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
  
#line 12923 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 12936 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 12950 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  incI_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFF /*primary()*/));
  
#line 12964 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 12977 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  decI_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFF /*primary()*/));
  
#line 12991 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x01);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 13004 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  checkCastPPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  checkCastPPNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  castPPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
void  castIINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
void  loadPLockedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 13042 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13055 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadLLockedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 4246 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0xDF);
    int rm_byte_opcode = 0x05;
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
    store_to_stackslot( cbuf, 0x0DF, 0x07, opnd_array(0)->disp(ra_,this,0) );
  
#line 13076 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadLX_LockedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 4258 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // Atomic long load
      // UseXmmLoadAndClearUpper ? movsd $tmp,$mem : movlpd $tmp,$mem
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0x10 : 0x12);
      int base     = opnd_array(1)->base(ra_,this,idx1);
      int index    = opnd_array(1)->index(ra_,this,idx1);
      int scale    = opnd_array(1)->scale();
      int displace = opnd_array(1)->disp(ra_,this,idx1);
      bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), base, index, scale, displace, disp_is_oop);
    }
    { // MOVSD $dst,$tmp ! atomic long store
      emit_opcode(cbuf,0xF2);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x11);
      int base     = opnd_array(0)->base(ra_,this,idx0);
      int index    = opnd_array(0)->index(ra_,this,idx0);
      int scale    = opnd_array(0)->scale();
      int displace = opnd_array(0)->disp(ra_,this,0);
      bool disp_is_oop = opnd_array(0)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), base, index, scale, displace, disp_is_oop);
    }
  
#line 13112 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadLX_reg_LockedNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 4284 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // Atomic long load
      // UseXmmLoadAndClearUpper ? movsd $tmp,$mem : movlpd $tmp,$mem
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,UseXmmLoadAndClearUpper ? 0x10 : 0x12);
      int base     = opnd_array(1)->base(ra_,this,idx1);
      int index    = opnd_array(1)->index(ra_,this,idx1);
      int scale    = opnd_array(1)->scale();
      int displace = opnd_array(1)->disp(ra_,this,idx1);
      bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
      encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), base, index, scale, displace, disp_is_oop);
    }
    { // MOVD $dst.lo,$tmp
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x7E);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(0)->reg(ra_,this));
    }
    { // PSRLQ $tmp,32
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x73);
      emit_rm(cbuf, 0x3, 0x02, opnd_array(2)->reg(ra_,this,idx2));
      emit_d8(cbuf, 0x20);
    }
    { // MOVD $dst.hi,$tmp
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x7E);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)));
    }
  
#line 13156 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storePConditionalNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2229 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( os::is_MP() )
      emit_opcode(cbuf,0xF0);         // [Lock]
  
#line 13172 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 13179 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xB1));
  
#line 13186 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13199 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeIConditionalNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2229 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( os::is_MP() )
      emit_opcode(cbuf,0xF0);         // [Lock]
  
#line 13215 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 13222 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xB1));
  
#line 13229 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13242 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  storeLConditionalNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8439 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Note: we need to swap rbx, and rcx before and after the
    //       cmpxchg8 instruction because the instruction uses
    //       rcx as the high order word of the new value to store but
    //       our register encoding uses rbx.
    __ xchgl(as_Register(EBX_enc), as_Register(ECX_enc));
    if( os::is_MP() )
      __ lock();
    __ cmpxchg8(Address::make_raw(opnd_array(1)->base(ra_,this,idx1), opnd_array(1)->index(ra_,this,idx1), opnd_array(1)->scale(), opnd_array(1)->disp(ra_,this,idx1), opnd_array(1)->disp_is_oop()));
    __ xchgl(as_Register(EBX_enc), as_Register(ECX_enc));
  
#line 13271 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compareAndSwapLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2239 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"


    // XCHG  rbx,ecx
    emit_opcode(cbuf,0x87);
    emit_opcode(cbuf,0xD9);
    // [Lock]
    if( os::is_MP() )
      emit_opcode(cbuf,0xF0);
    // CMPXCHG8 [Eptr]
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0xC7);
    emit_rm( cbuf, 0x0, 1, opnd_array(1)->reg(ra_,this,idx1) );
    // XCHG  rbx,ecx
    emit_opcode(cbuf,0x87);
    emit_opcode(cbuf,0xD9);
  
#line 13299 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2267 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int res_encoding = opnd_array(0)->reg(ra_,this);

    // MOV  res,0
    emit_opcode( cbuf, 0xB8 + res_encoding);
    emit_d32( cbuf, 0 );
    // JNE,s  fail
    emit_opcode(cbuf,0x75);
    emit_d8(cbuf, 5 );
    // MOV  res,1
    emit_opcode( cbuf, 0xB8 + res_encoding);
    emit_d32( cbuf, 1 );
    // fail:
  
#line 13317 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compareAndSwapPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2256 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // [Lock]
    if( os::is_MP() )
      emit_opcode(cbuf,0xF0);

    // CMPXCHG [Eptr]
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0xB1);
    emit_rm( cbuf, 0x0, 1, opnd_array(1)->reg(ra_,this,idx1) );
  
#line 13339 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2267 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int res_encoding = opnd_array(0)->reg(ra_,this);

    // MOV  res,0
    emit_opcode( cbuf, 0xB8 + res_encoding);
    emit_d32( cbuf, 0 );
    // JNE,s  fail
    emit_opcode(cbuf,0x75);
    emit_d8(cbuf, 5 );
    // MOV  res,1
    emit_opcode( cbuf, 0xB8 + res_encoding);
    emit_d32( cbuf, 1 );
    // fail:
  
#line 13357 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compareAndSwapINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2256 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // [Lock]
    if( os::is_MP() )
      emit_opcode(cbuf,0xF0);

    // CMPXCHG [Eptr]
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0xB1);
    emit_rm( cbuf, 0x0, 1, opnd_array(1)->reg(ra_,this,idx1) );
  
#line 13379 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2267 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int res_encoding = opnd_array(0)->reg(ra_,this);

    // MOV  res,0
    emit_opcode( cbuf, 0xB8 + res_encoding);
    emit_d32( cbuf, 0 );
    // JNE,s  fail
    emit_opcode(cbuf,0x75);
    emit_d8(cbuf, 5 );
    // MOV  res,1
    emit_opcode( cbuf, 0xB8 + res_encoding);
    emit_d32( cbuf, 1 );
    // fail:
  
#line 13397 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2B /*primary()*/));
  
#line 13411 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 13418 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  subI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  subI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x05 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 13444 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 13458 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subI_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2B /*primary()*/));
  
#line 13472 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13485 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subI_mem_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x29 /*primary()*/));
  
#line 13499 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13512 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subP_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2B /*primary()*/));
  
#line 13527 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(3)->reg(ra_,this,idx3));
  
#line 13534 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  subP_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  negI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF7 /*primary()*/));
  
#line 13552 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x03 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 13559 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  negI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  mulI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 13577 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xAF /*primary()*/));
  
#line 13584 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 13591 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  mulI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 3, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 3);
}
void  mulI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1674 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x69 /*primary()*/) | 0x02);
    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x69 /*primary()*/));
    }
  
#line 13615 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 13622 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 13636 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  loadConL_low_onlyNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2005 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    int dst_enc = opnd_array(0)->reg(ra_,this);
    int src_con = opnd_array(1)->constantL() & 0x0FFFFFFFFL;
    if (src_con == 0) {
      // xor dst, dst
      emit_opcode(cbuf, 0x33);
      emit_rm(cbuf, 0x3, dst_enc, dst_enc);
    } else {
      emit_opcode(cbuf, (0xB8 /*primary()*/) + dst_enc);
      emit_d32(cbuf, src_con);
    }
  
#line 13660 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI_imm_highNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3066 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // IMUL   EDX:EAX,$src1
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x5, opnd_array(1)->reg(ra_,this,idx1) );
    // SAR    EDX,$cnt-32
    int shift_count = ((int)opnd_array(3)->constant()) - 32;
    if (shift_count > 0) {
      emit_opcode(cbuf, 0xC1);
      emit_rm(cbuf, 0x3, 7, opnd_array(0)->reg(ra_,this) );
      emit_d8(cbuf, shift_count);
    }
  
#line 13684 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI_imm_high_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3066 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // IMUL   EDX:EAX,$src1
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x5, opnd_array(2)->reg(ra_,this,idx2) );
    // SAR    EDX,$cnt-32
    int shift_count = ((int)opnd_array(3)->constant()) - 32;
    if (shift_count > 0) {
      emit_opcode(cbuf, 0xC1);
      emit_rm(cbuf, 0x3, 7, opnd_array(0)->reg(ra_,this) );
      emit_d8(cbuf, shift_count);
    }
  
#line 13708 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI_imm_RShift_highNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3066 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // IMUL   EDX:EAX,$src1
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x5, opnd_array(1)->reg(ra_,this,idx1) );
    // SAR    EDX,$cnt-32
    int shift_count = ((int)opnd_array(3)->constant()) - 32;
    if (shift_count > 0) {
      emit_opcode(cbuf, 0xC1);
      emit_rm(cbuf, 0x3, 7, opnd_array(0)->reg(ra_,this) );
      emit_d8(cbuf, shift_count);
    }
  
#line 13732 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI_imm_RShift_high_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3066 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // IMUL   EDX:EAX,$src1
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x5, opnd_array(2)->reg(ra_,this,idx2) );
    // SAR    EDX,$cnt-32
    int shift_count = ((int)opnd_array(3)->constant()) - 32;
    if (shift_count > 0) {
      emit_opcode(cbuf, 0xC1);
      emit_rm(cbuf, 0x3, 7, opnd_array(0)->reg(ra_,this) );
      emit_d8(cbuf, shift_count);
    }
  
#line 13756 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI_mem_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1674 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x69 /*primary()*/) | 0x02);
    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x69 /*primary()*/));
    }
  
#line 13776 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13789 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 13803 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 13817 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xAF /*primary()*/));
  
#line 13824 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13837 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 13851 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xAF /*primary()*/));
  
#line 13858 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 13871 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI2LNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3092 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Basic idea: long = (long)int * (long)int
    // IMUL EDX:EAX, src
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x5, opnd_array(2)->reg(ra_,this,idx2));
  
#line 13888 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulI2L_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3092 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Basic idea: long = (long)int * (long)int
    // IMUL EDX:EAX, src
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x5, opnd_array(1)->reg(ra_,this,idx1));
  
#line 13905 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulIS_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3099 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Basic Idea:  long = (int & 0xffffffffL) * (int & 0xffffffffL)
    // MUL EDX:EAX, src
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x4, opnd_array(3)->reg(ra_,this,idx3));
  
#line 13923 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulIS_eReg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3099 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Basic Idea:  long = (int & 0xffffffffL) * (int & 0xffffffffL)
    // MUL EDX:EAX, src
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x4, opnd_array(1)->reg(ra_,this,idx1));
  
#line 13941 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3106 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Basic idea: lo(result) = lo(x_lo * y_lo)
    //             hi(result) = hi(x_lo * y_lo) + lo(x_hi * y_lo) + lo(x_lo * y_hi)
    // MOV    $tmp,$src.lo
    encode_Copy( cbuf, opnd_array(3)->reg(ra_,this,idx3), opnd_array(2)->reg(ra_,this,idx2) );
    // IMUL   $tmp,EDX
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0xAF );
    emit_rm( cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    // MOV    EDX,$src.hi
    encode_Copy( cbuf, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)) );
    // IMUL   EDX,EAX
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0xAF );
    emit_rm( cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), opnd_array(1)->reg(ra_,this,idx1) );
    // ADD    $tmp,EDX
    emit_opcode( cbuf, 0x03 );
    emit_rm( cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    // MUL   EDX:EAX,$src.lo
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x4, opnd_array(2)->reg(ra_,this,idx2) );
    // ADD    EDX,ESI
    emit_opcode( cbuf, 0x03 );
    emit_rm( cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), opnd_array(3)->reg(ra_,this,idx3) );
  
#line 13978 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulL_eReg_lhi0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8712 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movl(opnd_array(3)->as_Register(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(2)->as_Register(ra_,this,idx2)));
    __ imull(opnd_array(3)->as_Register(ra_,this,idx3), rax);
    __ mull(opnd_array(2)->as_Register(ra_,this,idx2));
    __ addl(rdx, opnd_array(3)->as_Register(ra_,this,idx3));
  
#line 14002 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulL_eReg_rhi0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8733 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movl(opnd_array(3)->as_Register(ra_,this,idx3), opnd_array(2)->as_Register(ra_,this,idx2));
    __ imull(opnd_array(3)->as_Register(ra_,this,idx3), rdx);
    __ mull(opnd_array(2)->as_Register(ra_,this,idx2));
    __ addl(rdx, opnd_array(3)->as_Register(ra_,this,idx3));
  
#line 14026 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulL_eReg_hi0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8751 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ mull(opnd_array(2)->as_Register(ra_,this,idx2));
  
#line 14046 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulL_eReg_conNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3132 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Basic idea: lo(result) = lo(src * y_lo)
    //             hi(result) = hi(src * y_lo) + lo(src * y_hi)
    // IMUL   $tmp,EDX,$src
    emit_opcode( cbuf, 0x6B );
    emit_rm( cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    emit_d8( cbuf, (int)opnd_array(2)->constantL() );
    // MOV    EDX,$src
    emit_opcode(cbuf, 0xB8 + EDX_enc);
    emit_d32( cbuf, (int)opnd_array(2)->constantL() );
    // MUL   EDX:EAX,EDX
    emit_opcode( cbuf, 0xF7 );
    emit_rm( cbuf, 0x3, 0x4, EDX_enc );
    // ADD    EDX,ESI
    emit_opcode( cbuf, 0x03 );
    emit_rm( cbuf, 0x3, EDX_enc, opnd_array(3)->reg(ra_,this,idx3) );
  
#line 14075 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  mulL_eReg_conNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 12);
}
void  divI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1626 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Full implementation of Java idiv and irem; checks for
    // special case as described in JVM spec., p.243 & p.271.
    //
    //         normal case                           special case
    //
    // input : rax,: dividend                         min_int
    //         reg: divisor                          -1
    //
    // output: rax,: quotient  (= rax, idiv reg)       min_int
    //         rdx: remainder (= rax, irem reg)       0
    //
    //  Code sequnce:
    //
    //  81 F8 00 00 00 80    cmp         rax,80000000h
    //  0F 85 0B 00 00 00    jne         normal_case
    //  33 D2                xor         rdx,edx
    //  83 F9 FF             cmp         rcx,0FFh
    //  0F 84 03 00 00 00    je          done
    //                  normal_case:
    //  99                   cdq
    //  F7 F9                idiv        rax,ecx
    //                  done:
    //
    emit_opcode(cbuf,0x81); emit_d8(cbuf,0xF8);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x80);                     // cmp rax,80000000h
    emit_opcode(cbuf,0x0F); emit_d8(cbuf,0x85);
    emit_opcode(cbuf,0x0B); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);                     // jne normal_case
    emit_opcode(cbuf,0x33); emit_d8(cbuf,0xD2);                     // xor rdx,edx
    emit_opcode(cbuf,0x83); emit_d8(cbuf,0xF9); emit_d8(cbuf,0xFF); // cmp rcx,0FFh
    emit_opcode(cbuf,0x0F); emit_d8(cbuf,0x84);
    emit_opcode(cbuf,0x03); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);                     // je done
    // normal_case:
    emit_opcode(cbuf,0x99);                                         // cdq
    // idiv (note: must be emitted by the user of this rule)
    // normal:
  
#line 14130 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF7 /*primary()*/));
  
#line 14137 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 14144 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  divI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 26, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 26);
}
void  divL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3150 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // PUSH src1.hi
    emit_opcode(cbuf, HIGH_FROM_LOW(0x50+opnd_array(1)->reg(ra_,this,idx1)) );
    // PUSH src1.lo
    emit_opcode(cbuf,               0x50+opnd_array(1)->reg(ra_,this,idx1)  );
    // PUSH src2.hi
    emit_opcode(cbuf, HIGH_FROM_LOW(0x50+opnd_array(2)->reg(ra_,this,idx2)) );
    // PUSH src2.lo
    emit_opcode(cbuf,               0x50+opnd_array(2)->reg(ra_,this,idx2)  );
    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (CAST_FROM_FN_PTR(address, SharedRuntime::ldiv) - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Restore stack
    emit_opcode(cbuf, 0x83); // add  SP, #framesize
    emit_rm(cbuf, 0x3, 0x00, ESP_enc);
    emit_d8(cbuf, 4*4);
  
#line 14177 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divModI_eReg_divmodNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1626 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Full implementation of Java idiv and irem; checks for
    // special case as described in JVM spec., p.243 & p.271.
    //
    //         normal case                           special case
    //
    // input : rax,: dividend                         min_int
    //         reg: divisor                          -1
    //
    // output: rax,: quotient  (= rax, idiv reg)       min_int
    //         rdx: remainder (= rax, irem reg)       0
    //
    //  Code sequnce:
    //
    //  81 F8 00 00 00 80    cmp         rax,80000000h
    //  0F 85 0B 00 00 00    jne         normal_case
    //  33 D2                xor         rdx,edx
    //  83 F9 FF             cmp         rcx,0FFh
    //  0F 84 03 00 00 00    je          done
    //                  normal_case:
    //  99                   cdq
    //  F7 F9                idiv        rax,ecx
    //                  done:
    //
    emit_opcode(cbuf,0x81); emit_d8(cbuf,0xF8);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x80);                     // cmp rax,80000000h
    emit_opcode(cbuf,0x0F); emit_d8(cbuf,0x85);
    emit_opcode(cbuf,0x0B); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);                     // jne normal_case
    emit_opcode(cbuf,0x33); emit_d8(cbuf,0xD2);                     // xor rdx,edx
    emit_opcode(cbuf,0x83); emit_d8(cbuf,0xF9); emit_d8(cbuf,0xFF); // cmp rcx,0FFh
    emit_opcode(cbuf,0x0F); emit_d8(cbuf,0x84);
    emit_opcode(cbuf,0x03); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);                     // je done
    // normal_case:
    emit_opcode(cbuf,0x99);                                         // cdq
    // idiv (note: must be emitted by the user of this rule)
    // normal:
  
#line 14228 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF7 /*primary()*/));
  
#line 14235 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 14242 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  divModI_eReg_divmodNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 26, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 26);
}
void  modI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1626 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Full implementation of Java idiv and irem; checks for
    // special case as described in JVM spec., p.243 & p.271.
    //
    //         normal case                           special case
    //
    // input : rax,: dividend                         min_int
    //         reg: divisor                          -1
    //
    // output: rax,: quotient  (= rax, idiv reg)       min_int
    //         rdx: remainder (= rax, irem reg)       0
    //
    //  Code sequnce:
    //
    //  81 F8 00 00 00 80    cmp         rax,80000000h
    //  0F 85 0B 00 00 00    jne         normal_case
    //  33 D2                xor         rdx,edx
    //  83 F9 FF             cmp         rcx,0FFh
    //  0F 84 03 00 00 00    je          done
    //                  normal_case:
    //  99                   cdq
    //  F7 F9                idiv        rax,ecx
    //                  done:
    //
    emit_opcode(cbuf,0x81); emit_d8(cbuf,0xF8);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x80);                     // cmp rax,80000000h
    emit_opcode(cbuf,0x0F); emit_d8(cbuf,0x85);
    emit_opcode(cbuf,0x0B); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);                     // jne normal_case
    emit_opcode(cbuf,0x33); emit_d8(cbuf,0xD2);                     // xor rdx,edx
    emit_opcode(cbuf,0x83); emit_d8(cbuf,0xF9); emit_d8(cbuf,0xFF); // cmp rcx,0FFh
    emit_opcode(cbuf,0x0F); emit_d8(cbuf,0x84);
    emit_opcode(cbuf,0x03); emit_d8(cbuf,0x00);
    emit_opcode(cbuf,0x00); emit_d8(cbuf,0x00);                     // je done
    // normal_case:
    emit_opcode(cbuf,0x99);                                         // cdq
    // idiv (note: must be emitted by the user of this rule)
    // normal:
  
#line 14297 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF7 /*primary()*/));
  
#line 14304 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 14311 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  modI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 26, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 26);
}
void  modL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // PUSH src1.hi
    emit_opcode(cbuf, HIGH_FROM_LOW(0x50+opnd_array(1)->reg(ra_,this,idx1)) );
    // PUSH src1.lo
    emit_opcode(cbuf,               0x50+opnd_array(1)->reg(ra_,this,idx1)  );
    // PUSH src2.hi
    emit_opcode(cbuf, HIGH_FROM_LOW(0x50+opnd_array(2)->reg(ra_,this,idx2)) );
    // PUSH src2.lo
    emit_opcode(cbuf,               0x50+opnd_array(2)->reg(ra_,this,idx2)  );
    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (CAST_FROM_FN_PTR(address, SharedRuntime::lrem ) - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Restore stack
    emit_opcode(cbuf, 0x83); // add  SP, #framesize
    emit_rm(cbuf, 0x3, 0x00, ESP_enc);
    emit_d8(cbuf, 4*4);
  
#line 14344 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shlI_eReg_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1 /*primary()*/));
  
#line 14358 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 14365 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  shlI_eReg_1Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  salI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1985 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf, opnd_array(2)->constant());
  
#line 14385 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  salI_eReg_immNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 3, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 3);
}
void  salI_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD3 /*primary()*/));
  
#line 14403 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 14410 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  salI_eReg_CLNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  sarI_eReg_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1 /*primary()*/));
  
#line 14428 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 14435 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  sarI_eReg_1Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  sarI_mem_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1 /*primary()*/));
  
#line 14453 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x7 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 14466 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sarI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1985 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf, opnd_array(2)->constant());
  
#line 14482 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  sarI_eReg_immNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 3, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 3);
}
void  sarI_mem_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC1 /*primary()*/));
  
#line 14500 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x7 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 14513 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 14527 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sarI_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD3 /*primary()*/));
  
#line 14541 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 14548 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  sarI_eReg_CLNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  shrI_eReg_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1 /*primary()*/));
  
#line 14566 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 14573 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  shrI_eReg_1Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  shrI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1985 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf, opnd_array(2)->constant());
  
#line 14593 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  shrI_eReg_immNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 3, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 3);
}
void  i2bNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8981 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movsbl(opnd_array(0)->as_Register(ra_,this), opnd_array(1)->as_Register(ra_,this,idx1));
  
#line 14617 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  i2bNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 3, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 3);
}
void  i2sNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 8994 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movswl(opnd_array(0)->as_Register(ra_,this), opnd_array(1)->as_Register(ra_,this,idx1));
  
#line 14641 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  i2sNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 3, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 3);
}
void  shrI_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD3 /*primary()*/));
  
#line 14659 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 14666 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  shrI_eReg_CLNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  andI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*primary()*/));
  
#line 14684 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 14691 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  andI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  andI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x04 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 14717 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 14731 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andI_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*primary()*/));
  
#line 14745 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 14758 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andI_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*primary()*/));
  
#line 14772 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 14785 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andI_mem_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x21 /*primary()*/));
  
#line 14799 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 14812 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andI_mem_eReg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x21 /*primary()*/));
  
#line 14826 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 14839 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andI_mem_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1674 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);
    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
  
#line 14859 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x4 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 14872 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 14886 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 14900 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 14907 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  orI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  orI_eReg_castP2XNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 14925 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 14932 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  orI_eReg_castP2XNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  orI_eReg_castP2X_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 14950 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(1)->reg(ra_,this,idx1));
  
#line 14957 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  orI_eReg_castP2X_0Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  orI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x01 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 14983 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 14997 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orI_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 15011 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15024 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orI_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 15038 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15051 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orI_mem_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x09 /*primary()*/));
  
#line 15065 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15078 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orI_mem_eReg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x09 /*primary()*/));
  
#line 15092 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15105 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orI_mem_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1674 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);
    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
  
#line 15125 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x1 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 15138 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 15152 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rolI_eReg_imm1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1 /*primary()*/));
  
#line 15166 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15173 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rolI_eReg_imm8Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1985 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf, opnd_array(2)->constant());
  
#line 15189 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rolI_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD3 /*primary()*/));
  
#line 15203 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15210 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rorI_eReg_imm1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1 /*primary()*/));
  
#line 15224 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15231 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rorI_eReg_imm8Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1985 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf, opnd_array(2)->constant());
  
#line 15247 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rorI_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD3 /*primary()*/));
  
#line 15261 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15268 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 15282 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 15289 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  xorI_eRegNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  xorI_eReg_im1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 9304 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

     __ notl(opnd_array(1)->as_Register(ra_,this,idx1));
  
#line 15313 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  xorI_eReg_im1Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  xorI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x06 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 15339 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 15353 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorI_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 15367 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15380 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorI_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 15394 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15407 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorI_mem_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x31 /*primary()*/));
  
#line 15421 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15434 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorI_mem_eReg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x31 /*primary()*/));
  
#line 15448 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15461 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorI_mem_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1674 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);
    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
  
#line 15481 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x6 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 15494 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 15508 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  movI_nocopyNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2156 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    encode_Copy( cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15521 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  ci2bNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2437 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // NEG $dst
    emit_opcode(cbuf,0xF7);
    emit_rm(cbuf, 0x3, 0x03, opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15537 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1616 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,(0x13));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 15545 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  ci2bNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 4);
}
void  movP_nocopyNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2156 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    encode_Copy( cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15562 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cp2bNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2437 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // NEG $dst
    emit_opcode(cbuf,0xF7);
    emit_rm(cbuf, 0x3, 0x03, opnd_array(1)->reg(ra_,this,idx1) );
  
#line 15578 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1616 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,(0x13));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 15586 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpLTMaskNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1616 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,(0x33));
    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 15601 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1616 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,(0x3B));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 15609 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2443 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // SETLT $dst
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0x9C);
    emit_rm( cbuf, 0x3, 0x4, opnd_array(0)->reg(ra_,this) );
  
#line 15619 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2437 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // NEG $dst
    emit_opcode(cbuf,0xF7);
    emit_rm(cbuf, 0x3, 0x03, opnd_array(0)->reg(ra_,this) );
  
#line 15628 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpLTMask0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1985 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf, (0x1F));
  
#line 15644 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cadd_cmpLTMaskNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2450 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int tmpReg = ECX_enc;

    // SUB $p,$q
    emit_opcode(cbuf,0x2B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
    // SBB $tmp,$tmp
    emit_opcode(cbuf,0x1B);
    emit_rm(cbuf, 0x3, tmpReg, tmpReg);
    // AND $tmp,$y
    emit_opcode(cbuf,0x23);
    emit_rm(cbuf, 0x3, tmpReg, opnd_array(3)->reg(ra_,this,idx3));
    // ADD $p,$tmp
    emit_opcode(cbuf,0x03);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), tmpReg);
  
#line 15672 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cadd_cmpLTMask_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2450 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int tmpReg = ECX_enc;

    // SUB $p,$q
    emit_opcode(cbuf,0x2B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
    // SBB $tmp,$tmp
    emit_opcode(cbuf,0x1B);
    emit_rm(cbuf, 0x3, tmpReg, tmpReg);
    // AND $tmp,$y
    emit_opcode(cbuf,0x23);
    emit_rm(cbuf, 0x3, tmpReg, opnd_array(3)->reg(ra_,this,idx3));
    // ADD $p,$tmp
    emit_opcode(cbuf,0x03);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), tmpReg);
  
#line 15700 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cadd_cmpLTMask_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2450 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int tmpReg = ECX_enc;

    // SUB $p,$q
    emit_opcode(cbuf,0x2B);
    emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(3)->reg(ra_,this,idx3));
    // SBB $tmp,$tmp
    emit_opcode(cbuf,0x1B);
    emit_rm(cbuf, 0x3, tmpReg, tmpReg);
    // AND $tmp,$y
    emit_opcode(cbuf,0x23);
    emit_rm(cbuf, 0x3, tmpReg, opnd_array(1)->reg(ra_,this,idx1));
    // ADD $p,$tmp
    emit_opcode(cbuf,0x03);
    emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), tmpReg);
  
#line 15728 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cadd_cmpLTMask_2Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2450 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int tmpReg = ECX_enc;

    // SUB $p,$q
    emit_opcode(cbuf,0x2B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
    // SBB $tmp,$tmp
    emit_opcode(cbuf,0x1B);
    emit_rm(cbuf, 0x3, tmpReg, tmpReg);
    // AND $tmp,$y
    emit_opcode(cbuf,0x23);
    emit_rm(cbuf, 0x3, tmpReg, opnd_array(3)->reg(ra_,this,idx3));
    // ADD $p,$tmp
    emit_opcode(cbuf,0x03);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), tmpReg);
  
#line 15756 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2173 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x03 /*primary()*/));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 15771 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2178 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x13 /*secondary()*/));
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
  
#line 15779 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addL_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1707 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)opnd_array(2)->constantL(); // Throw away top bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 15800 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1718 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)(opnd_array(2)->constantL() >> 32); // Throw away bottom bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with tertiary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x02 /*tertiary()*/), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 15814 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addL_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x03 /*primary()*/));
  
#line 15828 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15841 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x13 /*secondary()*/));
  
#line 15848 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(2)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 15861 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addL_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x03 /*primary()*/));
  
#line 15875 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15888 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x13 /*secondary()*/));
  
#line 15895 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 15908 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2173 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x2B /*primary()*/));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 15923 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2178 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x1B /*secondary()*/));
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
  
#line 15931 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subL_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1707 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)opnd_array(2)->constantL(); // Throw away top bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x05 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 15952 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1718 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)(opnd_array(2)->constantL() >> 32); // Throw away bottom bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with tertiary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x03 /*tertiary()*/), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 15966 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subL_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2B /*primary()*/));
  
#line 15980 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 15993 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x1B /*secondary()*/));
  
#line 16000 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(2)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16013 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  negL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3234 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0xF7);    // NEG hi
    emit_rm    (cbuf,0x3, 0x3, HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
    emit_opcode(cbuf,0xF7);    // NEG lo
    emit_rm    (cbuf,0x3, 0x3,               opnd_array(2)->reg(ra_,this,idx2) );
    emit_opcode(cbuf,0x83);    // SBB hi,0
    emit_rm    (cbuf,0x3, 0x3, HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
    emit_d8    (cbuf,0 );
  
#line 16033 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andL_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2173 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x23 /*primary()*/));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 16048 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2178 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x23 /*secondary()*/));
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
  
#line 16056 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andL_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1707 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)opnd_array(2)->constantL(); // Throw away top bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x04 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 16077 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1718 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)(opnd_array(2)->constantL() >> 32); // Throw away bottom bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with tertiary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x04 /*tertiary()*/), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 16091 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andL_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*primary()*/));
  
#line 16105 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 16118 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*secondary()*/));
  
#line 16125 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(2)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16138 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  andL_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*primary()*/));
  
#line 16152 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 16165 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x23 /*secondary()*/));
  
#line 16172 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16185 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orl_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2173 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0B /*primary()*/));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 16200 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2178 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0B /*secondary()*/));
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
  
#line 16208 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orl_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1707 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)opnd_array(2)->constantL(); // Throw away top bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x01 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 16229 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1718 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)(opnd_array(2)->constantL() >> 32); // Throw away bottom bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with tertiary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x01 /*tertiary()*/), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 16243 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orl_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 16257 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 16270 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*secondary()*/));
  
#line 16277 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(2)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16290 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  orl_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*primary()*/));
  
#line 16304 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 16317 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0B /*secondary()*/));
  
#line 16324 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16337 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorl_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2173 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x33 /*primary()*/));
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 16352 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2178 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x33 /*secondary()*/));
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)));
  
#line 16360 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorl_eReg_im1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 9632 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

     __ notl(opnd_array(1)->as_Register(ra_,this,idx1));
     __ notl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
  
#line 16381 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorl_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1707 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)opnd_array(2)->constantL(); // Throw away top bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x06 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 16402 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1718 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    int con = (int)(opnd_array(2)->constantL() >> 32); // Throw away bottom bits
    emit_opcode(cbuf, ((con >= -128) && (con <= 127)) ? ((0x81 /*primary()*/) | 0x02) : (0x81 /*primary()*/));
    // Emit r/m byte with tertiary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x06 /*tertiary()*/), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    if ((con >= -128) && (con <= 127)) emit_d8 (cbuf,con);
    else                               emit_d32(cbuf,con);
  
#line 16416 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorl_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 16430 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 16443 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*secondary()*/));
  
#line 16450 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(2)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16463 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  xorl_eReg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 16477 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 16490 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*secondary()*/));
  
#line 16497 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 16510 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shlL_eReg_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 9670 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ addl(opnd_array(1)->as_Register(ra_,this,idx1),opnd_array(1)->as_Register(ra_,this,idx1));
    __ adcl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)),HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
  
#line 16531 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shlL_eReg_2Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 9687 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ addl(opnd_array(1)->as_Register(ra_,this,idx1),opnd_array(1)->as_Register(ra_,this,idx1));
    __ adcl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)),HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
    __ addl(opnd_array(1)->as_Register(ra_,this,idx1),opnd_array(1)->as_Register(ra_,this,idx1));
    __ adcl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)),HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
  
#line 16554 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shlL_eReg_3Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 9708 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ addl(opnd_array(1)->as_Register(ra_,this,idx1),opnd_array(1)->as_Register(ra_,this,idx1));
    __ adcl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)),HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
    __ addl(opnd_array(1)->as_Register(ra_,this,idx1),opnd_array(1)->as_Register(ra_,this,idx1));
    __ adcl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)),HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
    __ addl(opnd_array(1)->as_Register(ra_,this,idx1),opnd_array(1)->as_Register(ra_,this,idx1));
    __ adcl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)),HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)));
  
#line 16579 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shlL_eReg_1_31Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2306 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int r1, r2;
    if( (0xA4 /*tertiary()*/) == 0xA4 ) { r1 = opnd_array(1)->reg(ra_,this,idx1);  r2 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    else                    { r2 = opnd_array(1)->reg(ra_,this,idx1);  r1 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,(0xA4 /*tertiary()*/));
    emit_rm(cbuf, 0x3, r1, r2);
    emit_d8(cbuf,opnd_array(2)->constant());
    emit_d8(cbuf,(0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), r1);
    emit_d8(cbuf,opnd_array(2)->constant());
  
#line 16602 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shlL_eReg_32_63Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2330 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int r1, r2;
    if( (0x4 /*secondary()*/) == 0x5 ) { r1 = opnd_array(1)->reg(ra_,this,idx1);  r2 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    else                    { r2 = opnd_array(1)->reg(ra_,this,idx1);  r1 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }

    emit_opcode( cbuf, 0x8B ); // Move r1,r2
    emit_rm(cbuf, 0x3, r1, r2);
    if( opnd_array(2)->constant() > 32 ) { // Shift, if not by zero
      emit_opcode(cbuf,(0xC1 /*primary()*/));
      emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), r1);
      emit_d8(cbuf,opnd_array(2)->constant()-32);
    }
    emit_opcode(cbuf,0x33);  // XOR r2,r2
    emit_rm(cbuf, 0x3, r2, r2);
  
#line 16628 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  salL_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2491 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // TEST shift,32
    emit_opcode(cbuf,0xF7);
    emit_rm(cbuf, 0x3, 0, ECX_enc);
    emit_d32(cbuf,0x20);
    // JEQ,s small
    emit_opcode(cbuf, 0x74);
    emit_d8(cbuf, 0x04);
    // MOV    $dst.hi,$dst.lo
    emit_opcode( cbuf, 0x8B );
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), opnd_array(1)->reg(ra_,this,idx1) );
    // CLR    $dst.lo
    emit_opcode(cbuf, 0x33);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(1)->reg(ra_,this,idx1));
// small:
    // SHLD   $dst.hi,$dst.lo,$shift
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0xA5);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    // SHL    $dst.lo,$shift"
    emit_opcode(cbuf,0xD3);
    emit_rm(cbuf, 0x3, 0x4, opnd_array(1)->reg(ra_,this,idx1) );
  
#line 16662 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  salL_eReg_CLNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 17, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 17);
}
void  shrL_eReg_1_31Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2306 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int r1, r2;
    if( (0xAC /*tertiary()*/) == 0xA4 ) { r1 = opnd_array(1)->reg(ra_,this,idx1);  r2 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    else                    { r2 = opnd_array(1)->reg(ra_,this,idx1);  r1 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,(0xAC /*tertiary()*/));
    emit_rm(cbuf, 0x3, r1, r2);
    emit_d8(cbuf,opnd_array(2)->constant());
    emit_d8(cbuf,(0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), r1);
    emit_d8(cbuf,opnd_array(2)->constant());
  
#line 16689 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shrL_eReg_32_63Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2330 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int r1, r2;
    if( (0x5 /*secondary()*/) == 0x5 ) { r1 = opnd_array(1)->reg(ra_,this,idx1);  r2 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    else                    { r2 = opnd_array(1)->reg(ra_,this,idx1);  r1 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }

    emit_opcode( cbuf, 0x8B ); // Move r1,r2
    emit_rm(cbuf, 0x3, r1, r2);
    if( opnd_array(2)->constant() > 32 ) { // Shift, if not by zero
      emit_opcode(cbuf,(0xC1 /*primary()*/));
      emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), r1);
      emit_d8(cbuf,opnd_array(2)->constant()-32);
    }
    emit_opcode(cbuf,0x33);  // XOR r2,r2
    emit_rm(cbuf, 0x3, r2, r2);
  
#line 16715 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  shrL_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2515 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // TEST shift,32
    emit_opcode(cbuf,0xF7);
    emit_rm(cbuf, 0x3, 0, ECX_enc);
    emit_d32(cbuf,0x20);
    // JEQ,s small
    emit_opcode(cbuf, 0x74);
    emit_d8(cbuf, 0x04);
    // MOV    $dst.lo,$dst.hi
    emit_opcode( cbuf, 0x8B );
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    // CLR    $dst.hi
    emit_opcode(cbuf, 0x33);
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
// small:
    // SHRD   $dst.lo,$dst.hi,$shift
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0xAD);
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), opnd_array(1)->reg(ra_,this,idx1));
    // SHR    $dst.hi,$shift"
    emit_opcode(cbuf,0xD3);
    emit_rm(cbuf, 0x3, 0x5, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
  
#line 16749 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  shrL_eReg_CLNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 17, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 17);
}
void  sarL_eReg_1_31Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2306 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int r1, r2;
    if( (0xAC /*tertiary()*/) == 0xA4 ) { r1 = opnd_array(1)->reg(ra_,this,idx1);  r2 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    else                    { r2 = opnd_array(1)->reg(ra_,this,idx1);  r1 = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)); }
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,(0xAC /*tertiary()*/));
    emit_rm(cbuf, 0x3, r1, r2);
    emit_d8(cbuf,opnd_array(2)->constant());
    emit_d8(cbuf,(0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), r1);
    emit_d8(cbuf,opnd_array(2)->constant());
  
#line 16776 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sarL_eReg_32_63Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2319 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0x8B ); // Move
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    emit_d8(cbuf,(0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
    emit_d8(cbuf,opnd_array(2)->constant()-32);
    emit_d8(cbuf,(0xC1 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    emit_d8(cbuf,31);
  
#line 16797 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sarL_eReg_CLNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2539 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // TEST shift,32
    emit_opcode(cbuf,0xF7);
    emit_rm(cbuf, 0x3, 0, ECX_enc);
    emit_d32(cbuf,0x20);
    // JEQ,s small
    emit_opcode(cbuf, 0x74);
    emit_d8(cbuf, 0x05);
    // MOV    $dst.lo,$dst.hi
    emit_opcode( cbuf, 0x8B );
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    // SAR    $dst.hi,31
    emit_opcode(cbuf, 0xC1);
    emit_rm(cbuf, 0x3, 7, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    emit_d8(cbuf, 0x1F );
// small:
    // SHRD   $dst.lo,$dst.hi,$shift
    emit_opcode(cbuf,0x0F);
    emit_opcode(cbuf,0xAD);
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), opnd_array(1)->reg(ra_,this,idx1));
    // SAR    $dst.hi,$shift"
    emit_opcode(cbuf,0xD3);
    emit_rm(cbuf, 0x3, 0x7, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
  
#line 16832 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  sarL_eReg_CLNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 18, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 18);
}
void  cmpD_cc_P6Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 16851 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDF /*primary()*/));
  
#line 16858 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x05 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 16865 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2944 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Fixup the integer flags in case comparison involved a NaN
    //
    // JNP exit (no unordered comparison, P-flag is set by NaN)
    emit_opcode( cbuf, 0x7B );
    emit_d8    ( cbuf, 0x03 );
    // MOV AH,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // SAHF
    emit_opcode( cbuf, 0x9E);
    // NOP     // target for branch to avoid branch to branch
    emit_opcode( cbuf, 0x90);
  
#line 16883 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpD_cc_P6CFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 16898 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDF /*primary()*/));
  
#line 16905 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x05 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 16912 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpD_ccNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 16927 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 16934 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x3 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 16941 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2921 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fnstsw_ax
    emit_opcode( cbuf, 0xDF);
    emit_opcode( cbuf, 0xE0);
    // test ax,0x0400
    emit_opcode( cbuf, 0x66 );   // operand-size prefix for 16-bit immediate
    emit_opcode( cbuf, 0xA9 );
    emit_d16   ( cbuf, 0x0400 );
    // // // This sequence works, but stalls for 12-16 cycles on PPro
    // // test rax,0x0400
    // emit_opcode( cbuf, 0xA9 );
    // emit_d32   ( cbuf, 0x00000400 );
    //
    // jz exit (no unordered comparison)
    emit_opcode( cbuf, 0x74 );
    emit_d8    ( cbuf, 0x02 );
    // mov ah,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // sahf
    emit_opcode( cbuf, 0x9E);
  
#line 16967 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpD_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 16982 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 16989 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE4 /*primary()*/));
  
#line 16996 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2573 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );
    emit_d8( cbuf, 0xD8 );
  
#line 17004 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2974 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fnstsw_ax();
    emit_opcode( cbuf, 0xDF);
    emit_opcode( cbuf, 0xE0);
    // sahf
    emit_opcode( cbuf, 0x9E);
    // movl(dst, nan_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::parity, exit);
    emit_opcode( cbuf, 0x7A );
    emit_d8    ( cbuf, 0x13 );
    // movl(dst, less_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::below, exit);
    emit_opcode( cbuf, 0x72 );
    emit_d8    ( cbuf, 0x0C );
    // movl(dst, equal_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 0 );
    // jcc(Assembler::equal, exit);
    emit_opcode( cbuf, 0x74 );
    emit_d8    ( cbuf, 0x05 );
    // movl(dst, greater_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 1 );
  
#line 17036 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 17051 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 17058 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x3 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 17065 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2974 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fnstsw_ax();
    emit_opcode( cbuf, 0xDF);
    emit_opcode( cbuf, 0xE0);
    // sahf
    emit_opcode( cbuf, 0x9E);
    // movl(dst, nan_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::parity, exit);
    emit_opcode( cbuf, 0x7A );
    emit_d8    ( cbuf, 0x13 );
    // movl(dst, less_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::below, exit);
    emit_opcode( cbuf, 0x72 );
    emit_d8    ( cbuf, 0x0C );
    // movl(dst, equal_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 0 );
    // jcc(Assembler::equal, exit);
    emit_opcode( cbuf, 0x74 );
    emit_d8    ( cbuf, 0x05 );
    // movl(dst, greater_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 1 );
  
#line 17097 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpXD_ccNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*primary()*/));
  
#line 17111 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 17118 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*tertiary()*/));
  
#line 17125 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 17132 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2944 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Fixup the integer flags in case comparison involved a NaN
    //
    // JNP exit (no unordered comparison, P-flag is set by NaN)
    emit_opcode( cbuf, 0x7B );
    emit_d8    ( cbuf, 0x03 );
    // MOV AH,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // SAHF
    emit_opcode( cbuf, 0x9E);
    // NOP     // target for branch to avoid branch to branch
    emit_opcode( cbuf, 0x90);
  
#line 17150 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpXD_ccCFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*primary()*/));
  
#line 17164 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 17171 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*tertiary()*/));
  
#line 17178 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 17185 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpXD_ccmemNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*primary()*/));
  
#line 17199 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 17206 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*tertiary()*/));
  
#line 17213 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 17226 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2944 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Fixup the integer flags in case comparison involved a NaN
    //
    // JNP exit (no unordered comparison, P-flag is set by NaN)
    emit_opcode( cbuf, 0x7B );
    emit_d8    ( cbuf, 0x03 );
    // MOV AH,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // SAHF
    emit_opcode( cbuf, 0x9E);
    // NOP     // target for branch to avoid branch to branch
    emit_opcode( cbuf, 0x90);
  
#line 17244 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpXD_ccmemCFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*primary()*/));
  
#line 17258 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 17265 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*tertiary()*/));
  
#line 17272 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 17285 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1954 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, 0x33);
    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 17300 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*primary()*/));
  
#line 17307 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 17314 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*tertiary()*/));
  
#line 17321 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 17328 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3007 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    Label nan, inc, done;

    __ jccb(Assembler::parity, nan);
    __ jccb(Assembler::equal,  done);
    __ jccb(Assembler::above,  inc);
    __ bind(nan);
    __ decrement(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ jmpb(done);
    __ bind(inc);
    __ increment(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ bind(done);
  
#line 17346 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpXD_regmemNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66 /*primary()*/));
  
#line 17360 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 17367 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*tertiary()*/));
  
#line 17374 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 17387 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1991 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    emit_opcode(cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32(cbuf, (0x0));
  
#line 17397 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3007 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    Label nan, inc, done;

    __ jccb(Assembler::parity, nan);
    __ jccb(Assembler::equal,  done);
    __ jccb(Assembler::above,  inc);
    __ bind(nan);
    __ decrement(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ jmpb(done);
    __ bind(inc);
    __ increment(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ bind(done);
  
#line 17415 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 17430 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17437 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17444 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subD_reg_roundNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 17459 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 17466 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17473 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2640 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 17480 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subD_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*tertiary()*/));
  
#line 17494 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17507 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17514 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17521 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  absD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 17534 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE1 /*primary()*/));
  
#line 17541 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  absXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 4162 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    address signmask_address=(address)double_signmask_pool;
    // andpd:\tANDPD  $dst,[signconst]
    emit_opcode(cbuf, 0x66);
    emit_opcode(cbuf, 0x0F);
    emit_opcode(cbuf, 0x54);
    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_d32(cbuf, (int)signmask_address);
  
#line 17560 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  negD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 17573 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE0 /*primary()*/));
  
#line 17580 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  negXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 10097 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

     __ xorpd(opnd_array(1)->as_XMMRegister(ra_,this,idx1),
              ExternalAddress((address)double_signflip_pool));
  
#line 17600 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 17615 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17622 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17629 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  addD_regNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 4);
}
void  addD_reg_roundNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 17648 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 17655 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17662 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2640 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 17669 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*tertiary()*/));
  
#line 17683 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17696 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17703 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17710 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_reg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*tertiary()*/));
  
#line 17724 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17737 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17744 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 17751 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_mem_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD));
  
#line 17765 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17778 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8));
  
#line 17785 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 17792 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2282 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();            // Mark start of opcode for reloc info in mem operand
  
#line 17799 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD));
  
#line 17806 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x03);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17819 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_mem_reg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD));
  
#line 17833 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17846 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8));
  
#line 17853 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 17860 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2282 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();            // Mark start of opcode for reloc info in mem operand
  
#line 17867 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD));
  
#line 17874 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x03);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 17887 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_reg_imm1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2036 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( is_positive_zero_double(opnd_array(2)->constantD())) {
      // FLDZ
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xEE);
    } else if( is_positive_one_double(opnd_array(2)->constantD())) {
      // FLD1
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xE8);
    } else {
      emit_opcode(cbuf,0xDD);
      emit_rm(cbuf, 0x0, 0x0, 0x5);
      emit_double_constant(cbuf, opnd_array(2)->constantD());
    }
  
#line 17913 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17920 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17927 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2036 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( is_positive_zero_double(opnd_array(2)->constantD())) {
      // FLDZ
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xEE);
    } else if( is_positive_one_double(opnd_array(2)->constantD())) {
      // FLD1
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xE8);
    } else {
      emit_opcode(cbuf,0xDD);
      emit_rm(cbuf, 0x0, 0x0, 0x5);
      emit_double_constant(cbuf, opnd_array(2)->constantD());
    }
  
#line 17953 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 17960 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 17967 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_reg_imm_roundNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2036 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( is_positive_zero_double(opnd_array(2)->constantD())) {
      // FLDZ
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xEE);
    } else if( is_positive_one_double(opnd_array(2)->constantD())) {
      // FLD1
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xE8);
    } else {
      emit_opcode(cbuf,0xDD);
      emit_rm(cbuf, 0x0, 0x0, 0x5);
      emit_double_constant(cbuf, opnd_array(2)->constantD());
    }
  
#line 17993 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 18000 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18007 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2640 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 18014 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18028 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18035 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 18042 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 18049 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addXD_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18063 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18070 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 18077 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2075 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_double_constant(cbuf, opnd_array(2)->constantD());
  
#line 18085 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addXD_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18099 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18106 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 18113 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 18126 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addXD_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18140 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18147 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 18154 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 18167 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18181 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18188 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5C));
  
#line 18195 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 18202 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subXD_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18216 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18223 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5C));
  
#line 18230 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2075 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_double_constant(cbuf, opnd_array(2)->constantD());
  
#line 18238 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subXD_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18252 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18259 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5C));
  
#line 18266 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 18279 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18293 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18300 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 18307 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 18314 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulXD_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18328 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18335 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 18342 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2075 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_double_constant(cbuf, opnd_array(2)->constantD());
  
#line 18350 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulXD_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18364 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18371 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 18378 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 18391 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulXD_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18405 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18412 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 18419 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 18432 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18446 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18453 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5E));
  
#line 18460 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 18467 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divXD_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18481 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18488 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5E));
  
#line 18495 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2075 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_double_constant(cbuf, opnd_array(2)->constantD());
  
#line 18503 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divXD_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 18517 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 18524 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5E));
  
#line 18531 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 18544 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 18559 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 18566 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18573 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  strictfp_mulD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2589 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDB );           // FLD m80real
    emit_opcode( cbuf, 0x2D );
    emit_d32( cbuf, (int)StubRoutines::addr_fpu_subnormal_bias1() );
    emit_opcode( cbuf, 0xDE );           // FMULP ST(dst), ST0
    emit_opcode( cbuf, 0xC8+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18591 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 18599 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 18606 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18613 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2597 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDB );           // FLD m80real
    emit_opcode( cbuf, 0x2D );
    emit_d32( cbuf, (int)StubRoutines::addr_fpu_subnormal_bias2() );
    emit_opcode( cbuf, 0xDE );           // FMULP ST(dst), ST0
    emit_opcode( cbuf, 0xC8+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18624 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulD_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2036 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( is_positive_zero_double(opnd_array(2)->constantD())) {
      // FLDZ
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xEE);
    } else if( is_positive_one_double(opnd_array(2)->constantD())) {
      // FLD1
      emit_opcode(cbuf,0xD9);
      emit_opcode(cbuf,0xE8);
    } else {
      emit_opcode(cbuf,0xDD);
      emit_rm(cbuf, 0x0, 0x0, 0x5);
      emit_double_constant(cbuf, opnd_array(2)->constantD());
    }
  
#line 18650 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 18657 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18664 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulD_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*tertiary()*/));
  
#line 18678 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 18691 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 18698 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18705 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulD_reg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*tertiary()*/));
  
#line 18719 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 18732 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 18739 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 18746 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulD_reg_mem_ciscNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 18760 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 18773 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18781 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 18789 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulD_reg_mem_cisc_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 18803 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 18816 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 18824 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 18832 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_mulD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18848 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(2)->reg(ra_,this,idx2));
  
#line 18858 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4205 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  src2,ST  /* DE C0+i */
    emit_opcode(cbuf, 0xDE);
    emit_opcode(cbuf, 0xC0 + opnd_array(3)->reg(ra_,this,idx3));
  
#line 18867 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addD_mulD_reg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 18883 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(3)->reg(ra_,this,idx3));
  
#line 18893 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4205 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  src2,ST  /* DE C0+i */
    emit_opcode(cbuf, 0xDE);
    emit_opcode(cbuf, 0xC0 + opnd_array(1)->reg(ra_,this,idx1));
  
#line 18902 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subD_mulD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18918 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(2)->reg(ra_,this,idx2));
  
#line 18928 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE));
  
#line 18935 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1668 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE0) + opnd_array(3)->reg(ra_,this,idx3));
  
#line 18942 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 18957 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 18964 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18971 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  strictfp_divD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2589 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDB );           // FLD m80real
    emit_opcode( cbuf, 0x2D );
    emit_d32( cbuf, (int)StubRoutines::addr_fpu_subnormal_bias1() );
    emit_opcode( cbuf, 0xDE );           // FMULP ST(dst), ST0
    emit_opcode( cbuf, 0xC8+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 18989 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 18997 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 19004 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 19011 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2597 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDB );           // FLD m80real
    emit_opcode( cbuf, 0x2D );
    emit_d32( cbuf, (int)StubRoutines::addr_fpu_subnormal_bias2() );
    emit_opcode( cbuf, 0xDE );           // FMULP ST(dst), ST0
    emit_opcode( cbuf, 0xC8+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 19022 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divD_reg_roundNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 19037 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 19044 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x6 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 19051 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2640 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 19058 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  modD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2698 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // load dst in FPR0
    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    if (opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc) {
      // fincstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF7);
      // swap src with FPR1:
      // FXCH FPR1 with src
      emit_opcode(cbuf, 0xD9);
      emit_d8(cbuf, 0xC8-1+opnd_array(2)->reg(ra_,this,idx2) );
      // fdecstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF6);
    }
  
#line 19086 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2899 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fprem must be iterative
    // :: loop
    // fprem
    emit_opcode( cbuf, 0xD9 );
    emit_opcode( cbuf, 0xF8 );
    // wait
    emit_opcode( cbuf, 0x9b );
    // fnstsw ax
    emit_opcode( cbuf, 0xDF );
    emit_opcode( cbuf, 0xE0 );
    // sahf
    emit_opcode( cbuf, 0x9E );
    // jp  ::loop
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0x8A );
    emit_opcode( cbuf, 0xF4 );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
  
#line 19111 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2870 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if (opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc) {
      // fincstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF7);
      // FXCH FPR1 with src
      emit_opcode(cbuf, 0xD9);
      emit_d8(cbuf, 0xC8-1+opnd_array(2)->reg(ra_,this,idx2) );
      // fdecstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF6);
    }
    // // following asm replaced with Pop_Reg_F or Pop_Mem_F
    // // FSTP   FPR$dst$$reg
    // emit_opcode( cbuf, 0xDD );
    // emit_d8( cbuf, 0xD8+$dst$$reg );
  
#line 19132 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 19140 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  modXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2716 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src1
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src0
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

  
#line 19174 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2899 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fprem must be iterative
    // :: loop
    // fprem
    emit_opcode( cbuf, 0xD9 );
    emit_opcode( cbuf, 0xF8 );
    // wait
    emit_opcode( cbuf, 0x9b );
    // fnstsw ax
    emit_opcode( cbuf, 0xDF );
    emit_opcode( cbuf, 0xE0 );
    // sahf
    emit_opcode( cbuf, 0x9E );
    // jp  ::loop
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0x8A );
    emit_opcode( cbuf, 0xF4 );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
  
#line 19199 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 19216 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2573 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );
    emit_d8( cbuf, 0xD8 );
  
#line 19224 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sinD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 19237 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFE /*secondary()*/));
  
#line 19244 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sinXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19268 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 19275 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFE /*secondary()*/));
  
#line 19282 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 19299 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cosD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 19312 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFF /*secondary()*/));
  
#line 19319 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cosXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19343 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 19350 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFF /*secondary()*/));
  
#line 19357 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 19374 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  tanD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 19387 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 19394 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD));
  
#line 19401 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8));
  
#line 19408 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  tanXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19432 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 19439 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 19446 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD));
  
#line 19453 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8));
  
#line 19460 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 19477 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  atanD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );   // FLD ST(i-1)
  
#line 19492 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 19499 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3 /*secondary()*/));
  
#line 19506 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0xF3 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 19513 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  atanXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19538 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 19545 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3 /*secondary()*/));
  
#line 19552 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 19569 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sqrtD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 19583 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 19590 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFA /*primary()*/));
  
#line 19597 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 19605 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  powD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2806 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x83);     // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8    (cbuf,0x08);
  
#line 19621 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 19629 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 19636 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF1));
  
#line 19643 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2830 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FPR1 holds Y*ln2(X).  Compute FPR1 = 2^(Y*ln2(X))
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xC0);  // fdup = fld st(0)          Q       Q
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xFC);  // frndint               int(Q)      Q
    emit_opcode(cbuf,0xDC); emit_opcode(cbuf,0xE9);  // fsub st(1) -= st(0);  int(Q) frac(Q)
    emit_opcode(cbuf,0xDB);                          // FISTP [ESP]           frac(Q)
    emit_opcode(cbuf,0x1C);
    emit_d8(cbuf,0x24);
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xF0);  // f2xm1                 2^frac(Q)-1
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xE8);  // fld1                  1 2^frac(Q)-1
    emit_opcode(cbuf,0xDE); emit_opcode(cbuf,0xC1);  // faddp                 2^frac(Q)
    emit_opcode(cbuf,0x8B);                          // mov rax,[esp+0]=int(Q)
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 0, false);
    emit_opcode(cbuf,0xC7);                          // mov rcx,0xFFFFF800 - overflow mask
    emit_rm(cbuf, 0x3, 0x0, ECX_enc);
    emit_d32(cbuf,0xFFFFF800);
    emit_opcode(cbuf,0x81);                          // add rax,1023 - the double exponent bias
    emit_rm(cbuf, 0x3, 0x0, EAX_enc);
    emit_d32(cbuf,1023);
    emit_opcode(cbuf,0x8B);                          // mov rbx,eax
    emit_rm(cbuf, 0x3, EBX_enc, EAX_enc);
    emit_opcode(cbuf,0xC1);                          // shl rax,20 - Slide to exponent position
    emit_rm(cbuf,0x3,0x4,EAX_enc);
    emit_d8(cbuf,20);
    emit_opcode(cbuf,0x85);                          // test rbx,ecx - check for overflow
    emit_rm(cbuf, 0x3, EBX_enc, ECX_enc);
    emit_opcode(cbuf,0x0F); emit_opcode(cbuf,0x45);  // CMOVne rax,ecx - overflow; stuff NAN into EAX
    emit_rm(cbuf, 0x3, EAX_enc, ECX_enc);
    emit_opcode(cbuf,0x89);                          // mov [esp+4],eax - Store as part of double word
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 4, false);
    emit_opcode(cbuf,0xC7);                          // mov [esp+0],0   - [ESP] = (double)(1<<int(Q)) = 2^int(Q)
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
    emit_d32(cbuf,0);
    emit_opcode(cbuf,0xDC);                          // fmul dword st(0),[esp+0]; FPR1 = 2^int(Q)*2^frac(Q) = 2^Q
    encode_RegMem(cbuf, 0x1, ESP_enc, 0x4, 0, 0, false);
  
#line 19683 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2812 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x83);     // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8    (cbuf,0x08);
  
#line 19692 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  powXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2806 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x83);     // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8    (cbuf,0x08);
  
#line 19708 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2818 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], xmm_src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19721 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2818 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], xmm_src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19734 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 19741 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF1));
  
#line 19748 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2830 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FPR1 holds Y*ln2(X).  Compute FPR1 = 2^(Y*ln2(X))
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xC0);  // fdup = fld st(0)          Q       Q
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xFC);  // frndint               int(Q)      Q
    emit_opcode(cbuf,0xDC); emit_opcode(cbuf,0xE9);  // fsub st(1) -= st(0);  int(Q) frac(Q)
    emit_opcode(cbuf,0xDB);                          // FISTP [ESP]           frac(Q)
    emit_opcode(cbuf,0x1C);
    emit_d8(cbuf,0x24);
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xF0);  // f2xm1                 2^frac(Q)-1
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xE8);  // fld1                  1 2^frac(Q)-1
    emit_opcode(cbuf,0xDE); emit_opcode(cbuf,0xC1);  // faddp                 2^frac(Q)
    emit_opcode(cbuf,0x8B);                          // mov rax,[esp+0]=int(Q)
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 0, false);
    emit_opcode(cbuf,0xC7);                          // mov rcx,0xFFFFF800 - overflow mask
    emit_rm(cbuf, 0x3, 0x0, ECX_enc);
    emit_d32(cbuf,0xFFFFF800);
    emit_opcode(cbuf,0x81);                          // add rax,1023 - the double exponent bias
    emit_rm(cbuf, 0x3, 0x0, EAX_enc);
    emit_d32(cbuf,1023);
    emit_opcode(cbuf,0x8B);                          // mov rbx,eax
    emit_rm(cbuf, 0x3, EBX_enc, EAX_enc);
    emit_opcode(cbuf,0xC1);                          // shl rax,20 - Slide to exponent position
    emit_rm(cbuf,0x3,0x4,EAX_enc);
    emit_d8(cbuf,20);
    emit_opcode(cbuf,0x85);                          // test rbx,ecx - check for overflow
    emit_rm(cbuf, 0x3, EBX_enc, ECX_enc);
    emit_opcode(cbuf,0x0F); emit_opcode(cbuf,0x45);  // CMOVne rax,ecx - overflow; stuff NAN into EAX
    emit_rm(cbuf, 0x3, EAX_enc, ECX_enc);
    emit_opcode(cbuf,0x89);                          // mov [esp+4],eax - Store as part of double word
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 4, false);
    emit_opcode(cbuf,0xC7);                          // mov [esp+0],0   - [ESP] = (double)(1<<int(Q)) = 2^int(Q)
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
    emit_d32(cbuf,0);
    emit_opcode(cbuf,0xDC);                          // fmul dword st(0),[esp+0]; FPR1 = 2^int(Q)*2^frac(Q) = 2^Q
    encode_RegMem(cbuf, 0x1, ESP_enc, 0x4, 0, 0, false);
  
#line 19788 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 19805 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  expD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2806 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x83);     // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8    (cbuf,0x08);
  
#line 19820 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 19827 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xEA));
  
#line 19834 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE));
  
#line 19841 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC9));
  
#line 19848 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2830 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FPR1 holds Y*ln2(X).  Compute FPR1 = 2^(Y*ln2(X))
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xC0);  // fdup = fld st(0)          Q       Q
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xFC);  // frndint               int(Q)      Q
    emit_opcode(cbuf,0xDC); emit_opcode(cbuf,0xE9);  // fsub st(1) -= st(0);  int(Q) frac(Q)
    emit_opcode(cbuf,0xDB);                          // FISTP [ESP]           frac(Q)
    emit_opcode(cbuf,0x1C);
    emit_d8(cbuf,0x24);
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xF0);  // f2xm1                 2^frac(Q)-1
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xE8);  // fld1                  1 2^frac(Q)-1
    emit_opcode(cbuf,0xDE); emit_opcode(cbuf,0xC1);  // faddp                 2^frac(Q)
    emit_opcode(cbuf,0x8B);                          // mov rax,[esp+0]=int(Q)
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 0, false);
    emit_opcode(cbuf,0xC7);                          // mov rcx,0xFFFFF800 - overflow mask
    emit_rm(cbuf, 0x3, 0x0, ECX_enc);
    emit_d32(cbuf,0xFFFFF800);
    emit_opcode(cbuf,0x81);                          // add rax,1023 - the double exponent bias
    emit_rm(cbuf, 0x3, 0x0, EAX_enc);
    emit_d32(cbuf,1023);
    emit_opcode(cbuf,0x8B);                          // mov rbx,eax
    emit_rm(cbuf, 0x3, EBX_enc, EAX_enc);
    emit_opcode(cbuf,0xC1);                          // shl rax,20 - Slide to exponent position
    emit_rm(cbuf,0x3,0x4,EAX_enc);
    emit_d8(cbuf,20);
    emit_opcode(cbuf,0x85);                          // test rbx,ecx - check for overflow
    emit_rm(cbuf, 0x3, EBX_enc, ECX_enc);
    emit_opcode(cbuf,0x0F); emit_opcode(cbuf,0x45);  // CMOVne rax,ecx - overflow; stuff NAN into EAX
    emit_rm(cbuf, 0x3, EAX_enc, ECX_enc);
    emit_opcode(cbuf,0x89);                          // mov [esp+4],eax - Store as part of double word
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 4, false);
    emit_opcode(cbuf,0xC7);                          // mov [esp+0],0   - [ESP] = (double)(1<<int(Q)) = 2^int(Q)
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
    emit_d32(cbuf,0);
    emit_opcode(cbuf,0xDC);                          // fmul dword st(0),[esp+0]; FPR1 = 2^int(Q)*2^frac(Q) = 2^Q
    encode_RegMem(cbuf, 0x1, ESP_enc, 0x4, 0, 0, false);
  
#line 19888 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2812 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x83);     // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8    (cbuf,0x08);
  
#line 19897 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  expXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 19921 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 19928 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xEA));
  
#line 19935 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE));
  
#line 19942 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC9));
  
#line 19949 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2830 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FPR1 holds Y*ln2(X).  Compute FPR1 = 2^(Y*ln2(X))
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xC0);  // fdup = fld st(0)          Q       Q
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xFC);  // frndint               int(Q)      Q
    emit_opcode(cbuf,0xDC); emit_opcode(cbuf,0xE9);  // fsub st(1) -= st(0);  int(Q) frac(Q)
    emit_opcode(cbuf,0xDB);                          // FISTP [ESP]           frac(Q)
    emit_opcode(cbuf,0x1C);
    emit_d8(cbuf,0x24);
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xF0);  // f2xm1                 2^frac(Q)-1
    emit_opcode(cbuf,0xD9); emit_opcode(cbuf,0xE8);  // fld1                  1 2^frac(Q)-1
    emit_opcode(cbuf,0xDE); emit_opcode(cbuf,0xC1);  // faddp                 2^frac(Q)
    emit_opcode(cbuf,0x8B);                          // mov rax,[esp+0]=int(Q)
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 0, false);
    emit_opcode(cbuf,0xC7);                          // mov rcx,0xFFFFF800 - overflow mask
    emit_rm(cbuf, 0x3, 0x0, ECX_enc);
    emit_d32(cbuf,0xFFFFF800);
    emit_opcode(cbuf,0x81);                          // add rax,1023 - the double exponent bias
    emit_rm(cbuf, 0x3, 0x0, EAX_enc);
    emit_d32(cbuf,1023);
    emit_opcode(cbuf,0x8B);                          // mov rbx,eax
    emit_rm(cbuf, 0x3, EBX_enc, EAX_enc);
    emit_opcode(cbuf,0xC1);                          // shl rax,20 - Slide to exponent position
    emit_rm(cbuf,0x3,0x4,EAX_enc);
    emit_d8(cbuf,20);
    emit_opcode(cbuf,0x85);                          // test rbx,ecx - check for overflow
    emit_rm(cbuf, 0x3, EBX_enc, ECX_enc);
    emit_opcode(cbuf,0x0F); emit_opcode(cbuf,0x45);  // CMOVne rax,ecx - overflow; stuff NAN into EAX
    emit_rm(cbuf, 0x3, EAX_enc, ECX_enc);
    emit_opcode(cbuf,0x89);                          // mov [esp+4],eax - Store as part of double word
    encode_RegMem(cbuf, EAX_enc, ESP_enc, 0x4, 0, 4, false);
    emit_opcode(cbuf,0xC7);                          // mov [esp+0],0   - [ESP] = (double)(1<<int(Q)) = 2^int(Q)
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
    emit_d32(cbuf,0);
    emit_opcode(cbuf,0xDC);                          // fmul dword st(0),[esp+0]; FPR1 = 2^int(Q)*2^frac(Q) = 2^Q
    encode_RegMem(cbuf, 0x1, ESP_enc, 0x4, 0, 0, false);
  
#line 19989 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 20006 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  log10D_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20019 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xEC));
  
#line 20026 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20033 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC9));
  
#line 20040 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20047 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF1));
  
#line 20054 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  log10XD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20067 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xEC));
  
#line 20074 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 20092 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20099 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF1));
  
#line 20106 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 20123 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  logD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20136 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xED));
  
#line 20143 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20150 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC9));
  
#line 20157 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20164 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF1));
  
#line 20171 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  logXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20184 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xED));
  
#line 20191 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2791 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );     // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );      // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);
  
#line 20209 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9));
  
#line 20216 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF1));
  
#line 20223 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 20240 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpF_cc_P6Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 20255 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDF /*primary()*/));
  
#line 20262 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x05 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20269 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2944 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Fixup the integer flags in case comparison involved a NaN
    //
    // JNP exit (no unordered comparison, P-flag is set by NaN)
    emit_opcode( cbuf, 0x7B );
    emit_d8    ( cbuf, 0x03 );
    // MOV AH,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // SAHF
    emit_opcode( cbuf, 0x9E);
    // NOP     // target for branch to avoid branch to branch
    emit_opcode( cbuf, 0x90);
  
#line 20287 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpF_cc_P6CFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 20302 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDF /*primary()*/));
  
#line 20309 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x05 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20316 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpF_ccNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 20331 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 20338 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x3 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20345 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2921 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fnstsw_ax
    emit_opcode( cbuf, 0xDF);
    emit_opcode( cbuf, 0xE0);
    // test ax,0x0400
    emit_opcode( cbuf, 0x66 );   // operand-size prefix for 16-bit immediate
    emit_opcode( cbuf, 0xA9 );
    emit_d16   ( cbuf, 0x0400 );
    // // // This sequence works, but stalls for 12-16 cycles on PPro
    // // test rax,0x0400
    // emit_opcode( cbuf, 0xA9 );
    // emit_d32   ( cbuf, 0x00000400 );
    //
    // jz exit (no unordered comparison)
    emit_opcode( cbuf, 0x74 );
    emit_d8    ( cbuf, 0x02 );
    // mov ah,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // sahf
    emit_opcode( cbuf, 0x9E);
  
#line 20371 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpF_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 20386 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 20393 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE4 /*primary()*/));
  
#line 20400 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2573 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );
    emit_d8( cbuf, 0xD8 );
  
#line 20408 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2974 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fnstsw_ax();
    emit_opcode( cbuf, 0xDF);
    emit_opcode( cbuf, 0xE0);
    // sahf
    emit_opcode( cbuf, 0x9E);
    // movl(dst, nan_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::parity, exit);
    emit_opcode( cbuf, 0x7A );
    emit_d8    ( cbuf, 0x13 );
    // movl(dst, less_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::below, exit);
    emit_opcode( cbuf, 0x72 );
    emit_d8    ( cbuf, 0x0C );
    // movl(dst, equal_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 0 );
    // jcc(Assembler::equal, exit);
    emit_opcode( cbuf, 0x74 );
    emit_d8    ( cbuf, 0x05 );
    // movl(dst, greater_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 1 );
  
#line 20440 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 20455 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 20462 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x3 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20469 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2974 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fnstsw_ax();
    emit_opcode( cbuf, 0xDF);
    emit_opcode( cbuf, 0xE0);
    // sahf
    emit_opcode( cbuf, 0x9E);
    // movl(dst, nan_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::parity, exit);
    emit_opcode( cbuf, 0x7A );
    emit_d8    ( cbuf, 0x13 );
    // movl(dst, less_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, -1 );
    // jcc(Assembler::below, exit);
    emit_opcode( cbuf, 0x72 );
    emit_d8    ( cbuf, 0x0C );
    // movl(dst, equal_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 0 );
    // jcc(Assembler::equal, exit);
    emit_opcode( cbuf, 0x74 );
    emit_d8    ( cbuf, 0x05 );
    // movl(dst, greater_result);
    emit_opcode( cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32( cbuf, 1 );
  
#line 20501 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpX_ccNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 20515 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*secondary()*/));
  
#line 20522 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 20529 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2944 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Fixup the integer flags in case comparison involved a NaN
    //
    // JNP exit (no unordered comparison, P-flag is set by NaN)
    emit_opcode( cbuf, 0x7B );
    emit_d8    ( cbuf, 0x03 );
    // MOV AH,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // SAHF
    emit_opcode( cbuf, 0x9E);
    // NOP     // target for branch to avoid branch to branch
    emit_opcode( cbuf, 0x90);
  
#line 20547 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpX_ccCFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 20561 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*secondary()*/));
  
#line 20568 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 20575 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpX_ccmemNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 20589 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*secondary()*/));
  
#line 20596 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 20609 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2944 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Fixup the integer flags in case comparison involved a NaN
    //
    // JNP exit (no unordered comparison, P-flag is set by NaN)
    emit_opcode( cbuf, 0x7B );
    emit_d8    ( cbuf, 0x03 );
    // MOV AH,1 - treat as LT case (set carry flag)
    emit_opcode( cbuf, 0xB4 );
    emit_d8    ( cbuf, 0x01 );
    // SAHF
    emit_opcode( cbuf, 0x9E);
    // NOP     // target for branch to avoid branch to branch
    emit_opcode( cbuf, 0x90);
  
#line 20627 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpX_ccmemCFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 20641 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*secondary()*/));
  
#line 20648 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 20661 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1954 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, 0x33);
    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
  
#line 20676 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 20683 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*secondary()*/));
  
#line 20690 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 20697 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3007 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    Label nan, inc, done;

    __ jccb(Assembler::parity, nan);
    __ jccb(Assembler::equal,  done);
    __ jccb(Assembler::above,  inc);
    __ bind(nan);
    __ decrement(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ jmpb(done);
    __ bind(inc);
    __ increment(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ bind(done);
  
#line 20715 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpX_regmemNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*primary()*/));
  
#line 20729 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2F /*secondary()*/));
  
#line 20736 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 20749 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1991 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Load immediate does not have a zero or sign extended version
    // for 8-bit immediates
    emit_opcode(cbuf, 0xB8 + opnd_array(0)->reg(ra_,this));
    emit_d32(cbuf, (0x0));
  
#line 20759 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3007 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    Label nan, inc, done;

    __ jccb(Assembler::parity, nan);
    __ jccb(Assembler::equal,  done);
    __ jccb(Assembler::above,  inc);
    __ bind(nan);
    __ decrement(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ jmpb(done);
    __ bind(inc);
    __ increment(as_Register(opnd_array(0)->reg(ra_,this))); // NO L qqq
    __ bind(done);
  
#line 20777 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subF24_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 20792 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20800 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 20807 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20822 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 20829 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x5 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 20836 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20851 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 20859 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 20866 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 20881 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 20888 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 20895 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 20909 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 20916 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 20923 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 20930 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addX_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 20944 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 20951 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 20958 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2070 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 20966 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addX_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 20980 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 20987 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 20994 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21007 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addX_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21021 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21028 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x58));
  
#line 21035 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21048 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21062 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21069 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5C));
  
#line 21076 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 21083 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subX_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21097 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21104 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5C));
  
#line 21111 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2070 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 21119 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subX_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21133 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21140 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5C));
  
#line 21147 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21160 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21174 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21181 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 21188 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 21195 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulX_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21209 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21216 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 21223 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2070 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 21231 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulX_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21245 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21252 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 21259 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21272 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulX_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21286 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21293 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x59));
  
#line 21300 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(2)->reg(ra_,this,idx2);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21313 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21327 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21334 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5E));
  
#line 21341 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 21348 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divX_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21362 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21369 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5E));
  
#line 21376 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2070 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 21384 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divX_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21398 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21405 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5E));
  
#line 21412 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21425 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sqrtX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21438 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21445 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x51));
  
#line 21452 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 21459 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sqrtX_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 21472 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21479 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x51));
  
#line 21486 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21499 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sqrtXD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 21512 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21519 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x51));
  
#line 21526 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 21533 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  sqrtXD_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 21546 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 21553 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x51));
  
#line 21560 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 21573 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  absF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 21586 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE1 /*primary()*/));
  
#line 21593 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  absX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 4153 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    address signmask_address=(address)float_signmask_pool;
    // andpd:\tANDPS  $dst,[signconst]
    emit_opcode(cbuf, 0x0F);
    emit_opcode(cbuf, 0x54);
    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_d32(cbuf, (int)signmask_address);
  
#line 21611 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  negF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*secondary()*/));
  
#line 21624 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE0 /*primary()*/));
  
#line 21631 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  negX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 4172 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    address signmask_address=(address)float_signflip_pool;
    // andpd:\tXORPS  $dst,[signconst]
    emit_opcode(cbuf, 0x0F);
    emit_opcode(cbuf, 0x57);
    emit_rm(cbuf, 0x0, opnd_array(1)->reg(ra_,this,idx1), 0x5);
    emit_d32(cbuf, (int)signmask_address);
  
#line 21649 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21663 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21676 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 21684 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 21691 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_reg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21705 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21718 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 21726 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 21733 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21747 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21760 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 21767 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 21774 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_reg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21788 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21801 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 21808 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 21815 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_mem_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21829 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21842 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x0 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 21850 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 21857 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_mem_ciscNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21871 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21884 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2282 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();            // Mark start of opcode for reloc info in mem operand
  
#line 21891 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 21898 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x0 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21911 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 21918 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_mem_cisc_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21932 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21945 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2282 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();            // Mark start of opcode for reloc info in mem operand
  
#line 21952 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 21959 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x0 /*secondary()*/);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 21972 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 21979 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_mem_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 21993 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22006 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2282 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();            // Mark start of opcode for reloc info in mem operand
  
#line 22013 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 22020 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x0 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22033 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22040 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF24_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22055 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2089 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x0, (0x00 /*secondary()*/), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 22065 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22072 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22087 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2089 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x0, (0x00 /*secondary()*/), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 22097 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22105 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF24_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22120 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22128 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22135 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22150 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22158 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22166 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF24_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22180 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22193 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22201 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22208 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF24_reg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22222 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22235 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22243 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22250 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22264 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22277 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22285 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22293 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF_reg_mem_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22307 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22320 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22328 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22336 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF24_mem_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22350 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22363 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2282 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();            // Mark start of opcode for reloc info in mem operand
  
#line 22370 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD8 /*primary()*/));
  
#line 22377 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x1 /*secondary()*/);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22390 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22397 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF24_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22412 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2089 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x0, (0x1 /*secondary()*/), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 22422 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22429 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22444 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2089 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x0, (0x1 /*secondary()*/), 0x5);
    emit_float_constant(cbuf, opnd_array(2)->constantF());
  
#line 22454 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22462 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF_reg_load1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22476 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22489 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22497 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22505 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  mulF_reg_load1_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*tertiary()*/));
  
#line 22519 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22532 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x1 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22540 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22548 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_mulF_reg_load1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 22563 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22576 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(2)->reg(ra_,this,idx2));
  
#line 22586 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4198 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  ST,src2  /* D8 C0+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC0 + opnd_array(3)->reg(ra_,this,idx3));
    //could use FADDP  src2,fpST  /* DE C0+i */
  
#line 22596 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22604 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_mulF_reg_load1_1Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 22619 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22632 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(3)->reg(ra_,this,idx3));
  
#line 22642 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4198 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  ST,src2  /* D8 C0+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC0 + opnd_array(1)->reg(ra_,this,idx1));
    //could use FADDP  src2,fpST  /* DE C0+i */
  
#line 22652 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22660 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_mulF_reg_load1_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 22675 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(2)->base(ra_,this,idx2);
    int index    = opnd_array(2)->index(ra_,this,idx2);
    int scale    = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22688 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(1)->reg(ra_,this,idx1));
  
#line 22698 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4198 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  ST,src2  /* D8 C0+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC0 + opnd_array(3)->reg(ra_,this,idx3));
    //could use FADDP  src2,fpST  /* DE C0+i */
  
#line 22708 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22716 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_mulF_reg_load1_2Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 22731 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(3)->base(ra_,this,idx3);
    int index    = opnd_array(3)->index(ra_,this,idx3);
    int scale    = opnd_array(3)->scale();
    int displace = opnd_array(3)->disp(ra_,this,idx3);
    bool disp_is_oop = opnd_array(3)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 22744 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(2)->reg(ra_,this,idx2));
  
#line 22754 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4198 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  ST,src2  /* D8 C0+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC0 + opnd_array(1)->reg(ra_,this,idx1));
    //could use FADDP  src2,fpST  /* DE C0+i */
  
#line 22764 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22772 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_mulF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22788 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(2)->reg(ra_,this,idx2));
  
#line 22798 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4205 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  src2,ST  /* DE C0+i */
    emit_opcode(cbuf, 0xDE);
    emit_opcode(cbuf, 0xC0 + opnd_array(3)->reg(ra_,this,idx3));
  
#line 22807 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  addF_mulF_reg_0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22823 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4191 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand was loaded from memory into fp ST (stack top)
    // FMUL   ST,$src  /* D8 C8+i */
    emit_opcode(cbuf, 0xD8);
    emit_opcode(cbuf, 0xC8 + opnd_array(3)->reg(ra_,this,idx3));
  
#line 22833 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4205 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // FADDP  src2,ST  /* DE C0+i */
    emit_opcode(cbuf, 0xDE);
    emit_opcode(cbuf, 0xC0 + opnd_array(1)->reg(ra_,this,idx1));
  
#line 22842 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  subF_divF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22858 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4211 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Operand has been loaded into fp ST (stack top)
      // FSUB   ST,$src1
      emit_opcode(cbuf, 0xD8);
      emit_opcode(cbuf, 0xE0 + opnd_array(2)->reg(ra_,this,idx2));

      // FDIV
      emit_opcode(cbuf, 0xD8);
      emit_opcode(cbuf, 0xF0 + opnd_array(3)->reg(ra_,this,idx3));
  
#line 22872 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 22880 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divF24_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22895 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2567 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0xD8 /*primary()*/));
    emit_rm(cbuf, 0x3, (0x6 /*secondary()*/), opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22903 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 22910 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  divF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(2)->reg(ra_,this,idx2) );
  
#line 22925 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDE /*primary()*/));
  
#line 22932 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x7 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 22939 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  modF24_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2698 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // load dst in FPR0
    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    if (opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc) {
      // fincstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF7);
      // swap src with FPR1:
      // FXCH FPR1 with src
      emit_opcode(cbuf, 0xD9);
      emit_d8(cbuf, 0xC8-1+opnd_array(2)->reg(ra_,this,idx2) );
      // fdecstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF6);
    }
  
#line 22967 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2899 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fprem must be iterative
    // :: loop
    // fprem
    emit_opcode( cbuf, 0xD9 );
    emit_opcode( cbuf, 0xF8 );
    // wait
    emit_opcode( cbuf, 0x9b );
    // fnstsw ax
    emit_opcode( cbuf, 0xDF );
    emit_opcode( cbuf, 0xE0 );
    // sahf
    emit_opcode( cbuf, 0x9E );
    // jp  ::loop
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0x8A );
    emit_opcode( cbuf, 0xF4 );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
  
#line 22992 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2870 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if (opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc) {
      // fincstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF7);
      // FXCH FPR1 with src
      emit_opcode(cbuf, 0xD9);
      emit_d8(cbuf, 0xC8-1+opnd_array(2)->reg(ra_,this,idx2) );
      // fdecstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF6);
    }
    // // following asm replaced with Pop_Reg_F or Pop_Mem_F
    // // FSTP   FPR$dst$$reg
    // emit_opcode( cbuf, 0xDD );
    // emit_d8( cbuf, 0xD8+$dst$$reg );
  
#line 23013 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 23020 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  modF_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2698 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // load dst in FPR0
    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    if (opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc) {
      // fincstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF7);
      // swap src with FPR1:
      // FXCH FPR1 with src
      emit_opcode(cbuf, 0xD9);
      emit_d8(cbuf, 0xC8-1+opnd_array(2)->reg(ra_,this,idx2) );
      // fdecstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF6);
    }
  
#line 23048 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2899 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fprem must be iterative
    // :: loop
    // fprem
    emit_opcode( cbuf, 0xD9 );
    emit_opcode( cbuf, 0xF8 );
    // wait
    emit_opcode( cbuf, 0x9b );
    // fnstsw ax
    emit_opcode( cbuf, 0xDF );
    emit_opcode( cbuf, 0xE0 );
    // sahf
    emit_opcode( cbuf, 0x9E );
    // jp  ::loop
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0x8A );
    emit_opcode( cbuf, 0xF4 );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
  
#line 23073 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2870 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if (opnd_array(2)->reg(ra_,this,idx2) != FPR1L_enc) {
      // fincstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF7);
      // FXCH FPR1 with src
      emit_opcode(cbuf, 0xD9);
      emit_d8(cbuf, 0xC8-1+opnd_array(2)->reg(ra_,this,idx2) );
      // fdecstp
      emit_opcode (cbuf, 0xD9);
      emit_opcode (cbuf, 0xF6);
    }
    // // following asm replaced with Pop_Reg_F or Pop_Mem_F
    // // FSTP   FPR$dst$$reg
    // emit_opcode( cbuf, 0xDD );
    // emit_d8( cbuf, 0xD8+$dst$$reg );
  
#line 23094 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 23102 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  modX_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2740 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x04);

    emit_opcode  (cbuf, 0xF3 );     // MOVSS [ESP], src1
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(2)->reg(ra_,this,idx2), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9 );      // FLD [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode  (cbuf, 0xF3 );     // MOVSS [ESP], src0
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9 );      // FLD [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

  
#line 23136 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2899 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // fprem must be iterative
    // :: loop
    // fprem
    emit_opcode( cbuf, 0xD9 );
    emit_opcode( cbuf, 0xF8 );
    // wait
    emit_opcode( cbuf, 0x9b );
    // fnstsw ax
    emit_opcode( cbuf, 0xDF );
    emit_opcode( cbuf, 0xE0 );
    // sahf
    emit_opcode( cbuf, 0x9E );
    // jp  ::loop
    emit_opcode( cbuf, 0x0F );
    emit_opcode( cbuf, 0x8A );
    emit_opcode( cbuf, 0xF4 );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
    emit_opcode( cbuf, 0xFF );
  
#line 23161 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, 0 ); //FSTP_S [ESP]

    emit_opcode  (cbuf, 0xF3 );     // MOVSS dst(xmm), [ESP]
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x10 );
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,d8 (4 or 8)
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,(0x4));
  
#line 23177 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2573 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );
    emit_d8( cbuf, 0xD8 );
  
#line 23185 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  roundFloat_mem_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2655 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int pop = 0x02;
    if (opnd_array(1)->reg(ra_,this,idx1) != FPR1L_enc) {
      emit_opcode( cbuf, 0xD9 );         // FLD    ST(i-1)
      emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
      pop = 0x03;
    }
    store_to_stackslot( cbuf, 0xD9, pop, opnd_array(0)->disp(ra_,this,0) ); // FST<P>_S  [ESP+dst]
  
#line 23204 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  roundDouble_mem_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2666 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int pop = 0x02;
    if (opnd_array(1)->reg(ra_,this,idx1) != FPR1L_enc) {
      emit_opcode( cbuf, 0xD9 );         // FLD    ST(i-1)
      emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
      pop = 0x03;
    }
    store_to_stackslot( cbuf, 0xDD, pop, opnd_array(0)->disp(ra_,this,0) ); // FST<P>_D  [ESP+dst]
  
#line 23223 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convD2X_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 4071 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x04);
    int pop = 0x02;
    if (opnd_array(1)->reg(ra_,this,idx1) != FPR1L_enc) {
      emit_opcode( cbuf, 0xD9 );       // FLD    ST(i-1)
      emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
      pop = 0x03;
    }
    store_to_stackslot( cbuf, 0xD9, pop, 0 ); // FST<P>_S  [ESP]

    emit_opcode  (cbuf, 0xF3 );        // MOVSS dst(xmm), [ESP]
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x10 );
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);            // ADD ESP,4
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x04);
    // Carry on here...
  
#line 23256 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convXD2X_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2 /*primary()*/));
  
#line 23269 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 23276 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5A /*tertiary()*/));
  
#line 23283 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 23290 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convF2D_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2677 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int pop = 0xD0 - 1; // -1 since we skip FLD
    if (opnd_array(1)->reg(ra_,this,idx1) != FPR1L_enc) {
      emit_opcode( cbuf, 0xD9 );         // FLD    ST(src-1)
      emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
      pop = 0xD8;
    }
    emit_opcode( cbuf, 0xDD );
    emit_d8( cbuf, pop+opnd_array(0)->reg(ra_,this) );      // FST<P> ST(i)
  
#line 23310 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convX2D_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 4132 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);     // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x04);

    emit_opcode  (cbuf, 0xF3 ); // MOVSS [ESP], xmm
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9 );    // FLD_S [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);     // ADD ESP,4
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x04);

    // Carry on here...
  
#line 23340 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 23348 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convX2XD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3 /*primary()*/));
  
#line 23361 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 23368 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x5A /*tertiary()*/));
  
#line 23375 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 23382 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convD2I_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 23396 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3839 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Flip to round-to-zero mode.  We attempted to allow invalid-op
    // exceptions here, so that a NAN or other corner-case value will
    // thrown an exception (but normal values get converted at full speed).
    // However, I2C adapters and other float-stack manglers leave pending
    // invalid-op exceptions hanging.  We would have to clear them before
    // enabling them and that is more expensive than just testing for the
    // invalid value Intel stores down in the corner cases.
    emit_opcode(cbuf,0xD9);            // FLDCW  trunc
    emit_opcode(cbuf,0x2D);
    emit_d32(cbuf,(int)StubRoutines::addr_fpu_cntrl_wrd_trunc());
    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x04);
    // Encoding assumes a double has been pushed into FPR0.
    // Store down the double as an int, popping the FPU stack
    emit_opcode(cbuf,0xDB);            // FISTP [ESP]
    emit_opcode(cbuf,0x1C);
    emit_d8(cbuf,0x24);
    // Restore the rounding mode; mask the exception
    emit_opcode(cbuf,0xD9);            // FLDCW   std/24-bit mode
    emit_opcode(cbuf,0x2D);
    emit_d32( cbuf, Compile::current()->in_24_bit_fp_mode()
        ? (int)StubRoutines::addr_fpu_cntrl_wrd_24()
        : (int)StubRoutines::addr_fpu_cntrl_wrd_std());

    // Load the converted int; adjust CPU stack
    emit_opcode(cbuf,0x58);       // POP EAX
    emit_opcode(cbuf,0x3D);       // CMP EAX,imm
    emit_d32   (cbuf,0x80000000); //         0x80000000
    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x07);       // Size of slow_call
    // Push src onto stack slow-path
    emit_opcode(cbuf,0xD9 );      // FLD     ST(i)
    emit_d8    (cbuf,0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2i_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Carry on here...
  
#line 23442 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convXD2I_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 23455 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 23462 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2C));
  
#line 23469 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4095 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));

    // Compare the result to see if we need to go to the slow path
    emit_opcode(cbuf,0x81);       // CMP dst,imm
    emit_rm    (cbuf,0x3,0x7,opnd_array(0)->reg(ra_,this));
    emit_d32   (cbuf,0x80000000); //         0x80000000

    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x13);       // Size of slow_call
    // Store xmm to a temp memory
    // location and push it onto stack.

    emit_opcode(cbuf,0x83);  // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf, (0x1 /*primary()*/) ? 0x8 : 0x4);

    emit_opcode  (cbuf, (0x1 /*primary()*/) ? 0xF2 : 0xF3 );   // MOVSS [ESP], xmm
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf, (0x1 /*primary()*/) ? 0xDD : 0xD9 );      // FLD [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,4
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf, (0x1 /*primary()*/) ? 0x8 : 0x4);

    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2i_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );

    // Carry on here...
  
#line 23509 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convD2L_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2584 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );   // FLD ST(i-1)
  
#line 23523 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3882 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0xD9);            // FLDCW  trunc
    emit_opcode(cbuf,0x2D);
    emit_d32(cbuf,(int)StubRoutines::addr_fpu_cntrl_wrd_trunc());
    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);
    // Encoding assumes a double has been pushed into FPR0.
    // Store down the double as a long, popping the FPU stack
    emit_opcode(cbuf,0xDF);            // FISTP [ESP]
    emit_opcode(cbuf,0x3C);
    emit_d8(cbuf,0x24);
    // Restore the rounding mode; mask the exception
    emit_opcode(cbuf,0xD9);            // FLDCW   std/24-bit mode
    emit_opcode(cbuf,0x2D);
    emit_d32( cbuf, Compile::current()->in_24_bit_fp_mode()
        ? (int)StubRoutines::addr_fpu_cntrl_wrd_24()
        : (int)StubRoutines::addr_fpu_cntrl_wrd_std());

    // Load the converted int; adjust CPU stack
    emit_opcode(cbuf,0x58);       // POP EAX
    emit_opcode(cbuf,0x5A);       // POP EDX
    emit_opcode(cbuf,0x81);       // CMP EDX,imm
    emit_d8    (cbuf,0xFA);       // rdx
    emit_d32   (cbuf,0x80000000); //         0x80000000
    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x07+4);     // Size of slow_call
    emit_opcode(cbuf,0x85);       // TEST EAX,EAX
    emit_opcode(cbuf,0xC0);       // 2/rax,/rax,
    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x07);       // Size of slow_call
    // Push src onto stack slow-path
    emit_opcode(cbuf,0xD9 );      // FLD     ST(i)
    emit_d8    (cbuf,0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2l_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Carry on here...
  
#line 23568 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convXD2L_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3997 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);      // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );  // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );     // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9);      // FLDCW  trunc
    emit_opcode(cbuf,0x2D);
    emit_d32(cbuf,(int)StubRoutines::addr_fpu_cntrl_wrd_trunc());

    // Encoding assumes a double has been pushed into FPR0.
    // Store down the double as a long, popping the FPU stack
    emit_opcode(cbuf,0xDF);      // FISTP [ESP]
    emit_opcode(cbuf,0x3C);
    emit_d8(cbuf,0x24);

    // Restore the rounding mode; mask the exception
    emit_opcode(cbuf,0xD9);      // FLDCW   std/24-bit mode
    emit_opcode(cbuf,0x2D);
    emit_d32( cbuf, Compile::current()->in_24_bit_fp_mode()
      ? (int)StubRoutines::addr_fpu_cntrl_wrd_24()
      : (int)StubRoutines::addr_fpu_cntrl_wrd_std());

    // Load the converted int; adjust CPU stack
    emit_opcode(cbuf,0x58);      // POP EAX

    emit_opcode(cbuf,0x5A);      // POP EDX

    emit_opcode(cbuf,0x81);      // CMP EDX,imm
    emit_d8    (cbuf,0xFA);      // rdx
    emit_d32   (cbuf,0x80000000); //         0x80000000

    emit_opcode(cbuf,0x75);      // JNE around_slow_call
    emit_d8    (cbuf,0x13+4);    // Size of slow_call

    emit_opcode(cbuf,0x85);      // TEST EAX,EAX
    emit_opcode(cbuf,0xC0);      // 2/rax,/rax,

    emit_opcode(cbuf,0x75);      // JNE around_slow_call
    emit_d8    (cbuf,0x13);      // Size of slow_call

    // Push src onto stack slow-path
    // Allocate a word
    emit_opcode(cbuf,0x83);      // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF2 );  // MOVSD [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xDD );     // FLD_D [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);      // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);

    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);      // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2l_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Carry on here...
  
#line 23651 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convF2I_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 23665 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3839 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Flip to round-to-zero mode.  We attempted to allow invalid-op
    // exceptions here, so that a NAN or other corner-case value will
    // thrown an exception (but normal values get converted at full speed).
    // However, I2C adapters and other float-stack manglers leave pending
    // invalid-op exceptions hanging.  We would have to clear them before
    // enabling them and that is more expensive than just testing for the
    // invalid value Intel stores down in the corner cases.
    emit_opcode(cbuf,0xD9);            // FLDCW  trunc
    emit_opcode(cbuf,0x2D);
    emit_d32(cbuf,(int)StubRoutines::addr_fpu_cntrl_wrd_trunc());
    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x04);
    // Encoding assumes a double has been pushed into FPR0.
    // Store down the double as an int, popping the FPU stack
    emit_opcode(cbuf,0xDB);            // FISTP [ESP]
    emit_opcode(cbuf,0x1C);
    emit_d8(cbuf,0x24);
    // Restore the rounding mode; mask the exception
    emit_opcode(cbuf,0xD9);            // FLDCW   std/24-bit mode
    emit_opcode(cbuf,0x2D);
    emit_d32( cbuf, Compile::current()->in_24_bit_fp_mode()
        ? (int)StubRoutines::addr_fpu_cntrl_wrd_24()
        : (int)StubRoutines::addr_fpu_cntrl_wrd_std());

    // Load the converted int; adjust CPU stack
    emit_opcode(cbuf,0x58);       // POP EAX
    emit_opcode(cbuf,0x3D);       // CMP EAX,imm
    emit_d32   (cbuf,0x80000000); //         0x80000000
    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x07);       // Size of slow_call
    // Push src onto stack slow-path
    emit_opcode(cbuf,0xD9 );      // FLD     ST(i)
    emit_d8    (cbuf,0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2i_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Carry on here...
  
#line 23711 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convX2I_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 23724 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 23731 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2C));
  
#line 23738 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 4095 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));

    // Compare the result to see if we need to go to the slow path
    emit_opcode(cbuf,0x81);       // CMP dst,imm
    emit_rm    (cbuf,0x3,0x7,opnd_array(0)->reg(ra_,this));
    emit_d32   (cbuf,0x80000000); //         0x80000000

    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x13);       // Size of slow_call
    // Store xmm to a temp memory
    // location and push it onto stack.

    emit_opcode(cbuf,0x83);  // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf, (0x0 /*primary()*/) ? 0x8 : 0x4);

    emit_opcode  (cbuf, (0x0 /*primary()*/) ? 0xF2 : 0xF3 );   // MOVSS [ESP], xmm
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf, (0x0 /*primary()*/) ? 0xDD : 0xD9 );      // FLD [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,4
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf, (0x0 /*primary()*/) ? 0x8 : 0x4);

    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2i_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );

    // Carry on here...
  
#line 23778 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convF2L_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2649 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xD9 );           // FLD    ST(i-1)
    emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
  
#line 23792 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3882 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0xD9);            // FLDCW  trunc
    emit_opcode(cbuf,0x2D);
    emit_d32(cbuf,(int)StubRoutines::addr_fpu_cntrl_wrd_trunc());
    // Allocate a word
    emit_opcode(cbuf,0x83);            // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);
    // Encoding assumes a double has been pushed into FPR0.
    // Store down the double as a long, popping the FPU stack
    emit_opcode(cbuf,0xDF);            // FISTP [ESP]
    emit_opcode(cbuf,0x3C);
    emit_d8(cbuf,0x24);
    // Restore the rounding mode; mask the exception
    emit_opcode(cbuf,0xD9);            // FLDCW   std/24-bit mode
    emit_opcode(cbuf,0x2D);
    emit_d32( cbuf, Compile::current()->in_24_bit_fp_mode()
        ? (int)StubRoutines::addr_fpu_cntrl_wrd_24()
        : (int)StubRoutines::addr_fpu_cntrl_wrd_std());

    // Load the converted int; adjust CPU stack
    emit_opcode(cbuf,0x58);       // POP EAX
    emit_opcode(cbuf,0x5A);       // POP EDX
    emit_opcode(cbuf,0x81);       // CMP EDX,imm
    emit_d8    (cbuf,0xFA);       // rdx
    emit_d32   (cbuf,0x80000000); //         0x80000000
    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x07+4);     // Size of slow_call
    emit_opcode(cbuf,0x85);       // TEST EAX,EAX
    emit_opcode(cbuf,0xC0);       // 2/rax,/rax,
    emit_opcode(cbuf,0x75);       // JNE around_slow_call
    emit_d8    (cbuf,0x07);       // Size of slow_call
    // Push src onto stack slow-path
    emit_opcode(cbuf,0xD9 );      // FLD     ST(i)
    emit_d8    (cbuf,0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2l_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Carry on here...
  
#line 23837 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convX2L_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3924 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Allocate a word
    emit_opcode(cbuf,0x83);      // SUB ESP,8
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x08);

    emit_opcode  (cbuf, 0xF3 );  // MOVSS [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9 );     // FLD_S [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9);      // FLDCW  trunc
    emit_opcode(cbuf,0x2D);
    emit_d32(cbuf,(int)StubRoutines::addr_fpu_cntrl_wrd_trunc());

    // Encoding assumes a double has been pushed into FPR0.
    // Store down the double as a long, popping the FPU stack
    emit_opcode(cbuf,0xDF);      // FISTP [ESP]
    emit_opcode(cbuf,0x3C);
    emit_d8(cbuf,0x24);

    // Restore the rounding mode; mask the exception
    emit_opcode(cbuf,0xD9);      // FLDCW   std/24-bit mode
    emit_opcode(cbuf,0x2D);
    emit_d32( cbuf, Compile::current()->in_24_bit_fp_mode()
      ? (int)StubRoutines::addr_fpu_cntrl_wrd_24()
      : (int)StubRoutines::addr_fpu_cntrl_wrd_std());

    // Load the converted int; adjust CPU stack
    emit_opcode(cbuf,0x58);      // POP EAX

    emit_opcode(cbuf,0x5A);      // POP EDX

    emit_opcode(cbuf,0x81);      // CMP EDX,imm
    emit_d8    (cbuf,0xFA);      // rdx
    emit_d32   (cbuf,0x80000000);//         0x80000000

    emit_opcode(cbuf,0x75);      // JNE around_slow_call
    emit_d8    (cbuf,0x13+4);    // Size of slow_call

    emit_opcode(cbuf,0x85);      // TEST EAX,EAX
    emit_opcode(cbuf,0xC0);      // 2/rax,/rax,

    emit_opcode(cbuf,0x75);      // JNE around_slow_call
    emit_d8    (cbuf,0x13);      // Size of slow_call

    // Allocate a word
    emit_opcode(cbuf,0x83);      // SUB ESP,4
    emit_opcode(cbuf,0xEC);
    emit_d8(cbuf,0x04);

    emit_opcode  (cbuf, 0xF3 );  // MOVSS [ESP], src
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x11 );
    encode_RegMem(cbuf, opnd_array(1)->reg(ra_,this,idx1), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0xD9 );     // FLD_S [ESP]
    encode_RegMem(cbuf, 0x0, ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);      // ADD ESP,4
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x04);

    // CALL directly to the runtime
    cbuf.set_inst_mark();
    emit_opcode(cbuf,0xE8);       // Call into runtime
    emit_d32_reloc(cbuf, (StubRoutines::d2l_wrapper() - cbuf.code_end()) - 4, runtime_call_Relocation::spec(), RELOC_IMM32 );
    // Carry on here...
  
#line 23919 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2D_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2619 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0xDB /*primary()*/), (0x0 /*secondary()*/), opnd_array(1)->disp(ra_,this,idx1) );
  
#line 23932 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 23940 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2XD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2 /*primary()*/));
  
#line 23953 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 23960 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2A /*tertiary()*/));
  
#line 23967 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 23974 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2XD_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2 /*primary()*/));
  
#line 23987 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 23994 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2A /*tertiary()*/));
  
#line 24001 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24014 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convXI2XD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 11906 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movdl(opnd_array(0)->as_XMMRegister(ra_,this), opnd_array(1)->as_Register(ra_,this,idx1));
    __ cvtdq2pd(opnd_array(0)->as_XMMRegister(ra_,this), opnd_array(0)->as_XMMRegister(ra_,this));
  
#line 24034 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2D_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDB /*primary()*/));
  
#line 24047 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 24060 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 24068 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  conv24I2F_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2619 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0xDB /*primary()*/), (0x0 /*secondary()*/), opnd_array(1)->disp(ra_,this,idx1) );
  
#line 24081 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 24089 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2F_SSFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2619 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0xDB /*primary()*/), (0x0 /*secondary()*/), opnd_array(1)->disp(ra_,this,idx1) );
  
#line 24102 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 24109 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2F_SSF_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDB /*primary()*/));
  
#line 24122 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 24135 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 24142 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2F_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2619 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0xDB /*primary()*/), (0x0 /*secondary()*/), opnd_array(1)->disp(ra_,this,idx1) );
  
#line 24155 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 24163 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2F_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDB /*primary()*/));
  
#line 24176 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 24189 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 24197 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2X_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3 /*primary()*/));
  
#line 24210 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F /*secondary()*/));
  
#line 24217 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x2A /*tertiary()*/));
  
#line 24224 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 24231 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convXI2X_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12004 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ movdl(opnd_array(0)->as_XMMRegister(ra_,this), opnd_array(1)->as_Register(ra_,this,idx1));
    __ cvtdq2ps(opnd_array(0)->as_XMMRegister(ra_,this), opnd_array(0)->as_XMMRegister(ra_,this));
  
#line 24251 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2L_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3037 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // mov $dst.lo,$src
    int dst_encoding = opnd_array(0)->reg(ra_,this);
    int src_encoding = opnd_array(1)->reg(ra_,this,idx1);
    encode_Copy( cbuf, dst_encoding  , src_encoding );
    // mov $dst.hi,$src
    encode_Copy( cbuf, HIGH_FROM_LOW(dst_encoding), src_encoding );
    // sar $dst.hi,31
    emit_opcode( cbuf, 0xC1 );
    emit_rm(cbuf, 0x3, 7, HIGH_FROM_LOW(dst_encoding) );
    emit_d8(cbuf, 0x1F );
  
#line 24273 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convI2L_reg_zexNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2156 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    encode_Copy( cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 24287 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 24294 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)), HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)));
  
#line 24301 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  zerox_longNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2156 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    encode_Copy( cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 24315 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x33 /*primary()*/));
  
#line 24322 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)), HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)));
  
#line 24329 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convL2D_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3050 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // push $src.hi
    emit_opcode(cbuf, 0x50+HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    // push $src.lo
    emit_opcode(cbuf, 0x50+opnd_array(1)->reg(ra_,this,idx1)  );
    // fild 64-bits at [SP]
    emit_opcode(cbuf,0xdf);
    emit_d8(cbuf, 0x6C);
    emit_d8(cbuf, 0x24);
    emit_d8(cbuf, 0x00);
    // pop stack
    emit_opcode(cbuf, 0x83); // add  SP, #8
    emit_rm(cbuf, 0x3, 0x00, ESP_enc);
    emit_d8(cbuf, 0x8);
  
#line 24354 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2640 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 24361 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convL2XD_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3080 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // push $src.hi
    emit_opcode(cbuf, 0x50+HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    // push $src.lo
    emit_opcode(cbuf, 0x50+opnd_array(1)->reg(ra_,this,idx1)  );
    // fild 64-bits at [SP]
    emit_opcode(cbuf,0xdf);
    emit_d8(cbuf, 0x6C);
    emit_d8(cbuf, 0x24);
    emit_d8(cbuf, 0x00);
  
#line 24382 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2764 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xDD, 0x03, 0 ); //FSTP [ESP]

    // UseXmmLoadAndClearUpper ? movsd dst,[esp] : movlpd dst,[esp]
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0xF2 : 0x66);
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, UseXmmLoadAndClearUpper ? 0x10 : 0x12);
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,8
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,0x08);
  
#line 24399 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convL2X_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3080 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // push $src.hi
    emit_opcode(cbuf, 0x50+HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    // push $src.lo
    emit_opcode(cbuf, 0x50+opnd_array(1)->reg(ra_,this,idx1)  );
    // fild 64-bits at [SP]
    emit_opcode(cbuf,0xdf);
    emit_d8(cbuf, 0x6C);
    emit_d8(cbuf, 0x24);
    emit_d8(cbuf, 0x00);
  
#line 24420 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, 0 ); //FSTP_S [ESP]

    emit_opcode  (cbuf, 0xF3 );     // MOVSS dst(xmm), [ESP]
    emit_opcode  (cbuf, 0x0F );
    emit_opcode  (cbuf, 0x10 );
    encode_RegMem(cbuf, opnd_array(0)->reg(ra_,this), ESP_enc, 0x4, 0, 0, false);

    emit_opcode(cbuf,0x83);    // ADD ESP,d8 (4 or 8)
    emit_opcode(cbuf,0xC4);
    emit_d8(cbuf,(0x8));
  
#line 24436 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convL2F_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3050 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // push $src.hi
    emit_opcode(cbuf, 0x50+HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    // push $src.lo
    emit_opcode(cbuf, 0x50+opnd_array(1)->reg(ra_,this,idx1)  );
    // fild 64-bits at [SP]
    emit_opcode(cbuf,0xdf);
    emit_d8(cbuf, 0x6C);
    emit_d8(cbuf, 0x24);
    emit_d8(cbuf, 0x00);
    // pop stack
    emit_opcode(cbuf, 0x83); // add  SP, #8
    emit_rm(cbuf, 0x3, 0x00, ESP_enc);
    emit_d8(cbuf, 0x8);
  
#line 24461 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2634 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, 0xD9, 0x03, opnd_array(0)->disp(ra_,this,0) );
  
#line 24468 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  convL2I_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2160 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    encode_Copy( cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 24481 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveF2I_stack_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 24494 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24507 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveF2I_reg_stackNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2655 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int pop = 0x02;
    if (opnd_array(1)->reg(ra_,this,idx1) != FPR1L_enc) {
      emit_opcode( cbuf, 0xD9 );         // FLD    ST(i-1)
      emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
      pop = 0x03;
    }
    store_to_stackslot( cbuf, 0xD9, pop, opnd_array(0)->disp(ra_,this,0) ); // FST<P>_S  [ESP+dst]
  
#line 24526 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveF2I_reg_stack_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 24539 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 24546 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x11));
  
#line 24553 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(0)->base(ra_,this,idx0);
    int index = opnd_array(0)->index(ra_,this,idx0);
    int scale = opnd_array(0)->scale();
    int displace = opnd_array(0)->disp(ra_,this,0);
    bool disp_is_oop = opnd_array(0)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24566 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveF2I_reg_reg_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2104 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, 0x66 );     // MOVD dst,src
    emit_opcode(cbuf, 0x0F );
    emit_opcode(cbuf, 0x7E );
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(0)->reg(ra_,this));
  
#line 24582 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveI2F_reg_stackNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2606 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    store_to_stackslot( cbuf, (0x89 /*primary()*/), opnd_array(1)->reg(ra_,this,idx1), opnd_array(0)->disp(ra_,this,0) );
  
#line 24595 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveI2F_stack_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD9 /*primary()*/));
  
#line 24608 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2364 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    assert( !opnd_array(1)->disp_is_oop(), "No oops here because no relo info allowed" );
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, false);
  
#line 24621 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2644 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 24629 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveI2F_stack_reg_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 24642 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 24649 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x10));
  
#line 24656 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24669 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveI2F_reg_reg_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2097 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, 0x66 );     // MOVD dst,src
    emit_opcode(cbuf, 0x0F );
    emit_opcode(cbuf, 0x6E );
    emit_rm(cbuf, 0x3, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
  
#line 24685 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveD2L_stack_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*primary()*/));
  
#line 24698 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24711 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x8B /*secondary()*/));
  
#line 24718 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this));  // Hi register of pair, computed from lo
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(1)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 24731 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveD2L_reg_stackNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 2666 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int pop = 0x02;
    if (opnd_array(1)->reg(ra_,this,idx1) != FPR1L_enc) {
      emit_opcode( cbuf, 0xD9 );         // FLD    ST(i-1)
      emit_d8( cbuf, 0xC0-1+opnd_array(1)->reg(ra_,this,idx1) );
      pop = 0x03;
    }
    store_to_stackslot( cbuf, 0xDD, pop, opnd_array(0)->disp(ra_,this,0) ); // FST<P>_D  [ESP+dst]
  
#line 24750 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveD2L_reg_stack_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 24763 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 24770 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x11));
  
#line 24777 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(0)->base(ra_,this,idx0);
    int index = opnd_array(0)->index(ra_,this,idx0);
    int scale = opnd_array(0)->scale();
    int displace = opnd_array(0)->disp(ra_,this,0);
    bool disp_is_oop = opnd_array(0)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24790 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveD2L_reg_reg_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2132 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // MOVD $dst.lo,$src
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x7E);
      emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(0)->reg(ra_,this));
    }
    { // PSHUFLW $tmp,$src,0x4E  (01001110b)
      emit_opcode(cbuf,0xF2);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x70);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(1)->reg(ra_,this,idx1));
      emit_d8(cbuf, 0x4E);
    }
    { // MOVD $dst.hi,$tmp
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x7E);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), HIGH_FROM_LOW(opnd_array(0)->reg(ra_,this)));
    }
  
#line 24822 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveL2D_reg_stackNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*primary()*/));
  
#line 24835 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(0)->base(ra_,this,idx0);
    int index = opnd_array(0)->index(ra_,this,idx0);
    int scale = opnd_array(0)->scale();
    int displace = opnd_array(0)->disp(ra_,this,0);
    bool disp_is_oop = opnd_array(0)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24848 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1599 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x89 /*secondary()*/));
  
#line 24855 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1));  // Hi register of pair, computed from lo
    int base  = opnd_array(0)->base(ra_,this,idx0);
    int index = opnd_array(0)->index(ra_,this,idx0);
    int scale = opnd_array(0)->scale();
    int displace = opnd_array(0)->disp(ra_,this,0) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(0)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 24868 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveL2D_stack_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xDD /*primary()*/));
  
#line 24881 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2364 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    assert( !opnd_array(1)->disp_is_oop(), "No oops here because no relo info allowed" );
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, false);
  
#line 24894 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2579 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode( cbuf, 0xDD );           // FSTP   ST(i)
    emit_d8( cbuf, 0xD8+opnd_array(0)->reg(ra_,this) );
  
#line 24902 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveL2D_stack_reg_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF2));
  
#line 24915 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 24922 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x10));
  
#line 24929 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24942 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveL2D_stack_reg_sse_partialNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x66));
  
#line 24955 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x0F));
  
#line 24962 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x12));
  
#line 24969 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(0)->reg(ra_,this);
    int base  = opnd_array(1)->base(ra_,this,idx1);
    int index = opnd_array(1)->index(ra_,this,idx1);
    int scale = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 24982 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  MoveL2D_reg_reg_sseNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 2111 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    { // MOVD $dst,$src.lo
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x6E);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(1)->reg(ra_,this,idx1));
    }
    { // MOVD $tmp,$src.hi
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x6E);
      emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
    }
    { // PUNPCKLDQ $dst,$tmp
      emit_opcode(cbuf,0x66);
      emit_opcode(cbuf,0x0F);
      emit_opcode(cbuf,0x62);
      emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(3)->reg(ra_,this,idx3));
     }
  
#line 25014 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl8B_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3254 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    encode_CopyXD(cbuf, opnd_array(0)->reg(ra_,this), opnd_array(1)->reg(ra_,this,idx1));
    __ punpcklbw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
    __ pshuflw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)), 0x00);
  
#line 25031 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl8B_eRegINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3280 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ movdl(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_Register(opnd_array(1)->reg(ra_,this,idx1)));
  
#line 25046 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3254 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    encode_CopyXD(cbuf, opnd_array(0)->reg(ra_,this), opnd_array(0)->reg(ra_,this));
    __ punpcklbw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
    __ pshuflw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)), 0x00);
  
#line 25057 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl8B_immI0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3274 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pxor(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
  
#line 25072 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl4S_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3262 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshuflw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(1)->reg(ra_,this,idx1)), 0x00);
  
#line 25087 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl4S_eRegINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3280 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ movdl(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_Register(opnd_array(1)->reg(ra_,this,idx1)));
  
#line 25102 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3262 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshuflw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)), 0x00);
  
#line 25111 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl4S_immI0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3274 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pxor(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
  
#line 25126 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl4C_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3262 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshuflw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(1)->reg(ra_,this,idx1)), 0x00);
  
#line 25141 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl4C_eRegINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3280 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ movdl(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_Register(opnd_array(1)->reg(ra_,this,idx1)));
  
#line 25156 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3262 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshuflw(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)), 0x00);
  
#line 25165 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl4C_immI0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3274 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pxor(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
  
#line 25180 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl2I_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3268 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshufd(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(1)->reg(ra_,this,idx1)), (0x00));
  
#line 25195 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl2I_eRegINode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3280 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ movdl(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_Register(opnd_array(1)->reg(ra_,this,idx1)));
  
#line 25210 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 3268 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshufd(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)), (0x00));
  
#line 25219 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl2I_immI0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3274 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pxor(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
  
#line 25234 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl2F_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3268 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshufd(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(1)->reg(ra_,this,idx1)), (0xe0));
  
#line 25249 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl2F_regXNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3268 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pshufd(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(1)->reg(ra_,this,idx1)), (0xe0));
  
#line 25264 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  Repl2F_immXF0Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 3274 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);

    __ pxor(as_XMMRegister(opnd_array(0)->reg(ra_,this)), as_XMMRegister(opnd_array(0)->reg(ra_,this)));
  
#line 25279 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  rep_stosNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xD1));
  
#line 25293 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), (ECX_enc) );
  
#line 25300 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1616 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,(0x33));
    emit_rm(cbuf, 0x3, (EAX_enc), (EAX_enc));
  
#line 25308 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF3));
  
#line 25315 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1604 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xAB));
  
#line 25322 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  string_compareNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    unsigned idx5 = idx4 + opnd_array(4)->num_edges();
    unsigned idx6 = idx5 + opnd_array(5)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12473 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ string_compare(opnd_array(1)->as_Register(ra_,this,idx1), opnd_array(3)->as_Register(ra_,this,idx3),
                      opnd_array(2)->as_Register(ra_,this,idx2), opnd_array(4)->as_Register(ra_,this,idx4), opnd_array(0)->as_Register(ra_,this),
                      opnd_array(5)->as_XMMRegister(ra_,this,idx5), opnd_array(6)->as_XMMRegister(ra_,this,idx6));
  
#line 25348 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  string_equalsNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    unsigned idx5 = idx4 + opnd_array(4)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12488 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ char_arrays_equals(false, opnd_array(1)->as_Register(ra_,this,idx1), opnd_array(2)->as_Register(ra_,this,idx2),
                          opnd_array(3)->as_Register(ra_,this,idx3), opnd_array(0)->as_Register(ra_,this), as_Register(EBX_enc),
                          opnd_array(4)->as_XMMRegister(ra_,this,idx4), opnd_array(5)->as_XMMRegister(ra_,this,idx5));
  
#line 25373 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  string_indexofNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
    unsigned idx5 = idx4 + opnd_array(4)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12503 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ string_indexof(opnd_array(1)->as_Register(ra_,this,idx1), opnd_array(3)->as_Register(ra_,this,idx3),
                      opnd_array(2)->as_Register(ra_,this,idx2), opnd_array(4)->as_Register(ra_,this,idx4), opnd_array(0)->as_Register(ra_,this),
                      opnd_array(5)->as_XMMRegister(ra_,this,idx5), as_Register(ECX_enc));
  
#line 25398 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  array_equalsNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12520 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    __ char_arrays_equals(true, opnd_array(1)->as_Register(ra_,this,idx1), opnd_array(2)->as_Register(ra_,this,idx2),
                          as_Register(ECX_enc), opnd_array(0)->as_Register(ra_,this), as_Register(EBX_enc),
                          opnd_array(3)->as_XMMRegister(ra_,this,idx3), opnd_array(4)->as_XMMRegister(ra_,this,idx4));
  
#line 25422 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25436 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 25443 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compI_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x07 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 25465 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 25479 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compI_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25493 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 25506 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  testI_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x85 /*primary()*/));
  
#line 25520 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(1)->reg(ra_,this,idx1));
  
#line 25527 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  testI_reg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF7 /*primary()*/));
  
#line 25542 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x00 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 25549 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2195 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Output immediate
    emit_d32(cbuf, opnd_array(2)->constant());
  
#line 25557 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  testI_reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x85 /*primary()*/));
  
#line 25572 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 25585 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compU_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25599 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 25606 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compU_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x07 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 25628 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      emit_d32(cbuf, opnd_array(2)->constant());
    }
  
#line 25642 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compU_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25656 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 25669 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  testU_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x85 /*primary()*/));
  
#line 25683 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(1)->reg(ra_,this,idx1));
  
#line 25690 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compP_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25704 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 25711 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compP_eReg_immNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1684 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Emit primary opcode and set sign-extend bit
    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_opcode(cbuf, (0x81 /*primary()*/) | 0x02);    }
    else {                          // If 32-bit immediate
      emit_opcode(cbuf, (0x81 /*primary()*/));
    }
    // Emit r/m byte with secondary opcode, after primary opcode.
    emit_rm(cbuf, 0x3, (0x07 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1));
  
#line 25733 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1696 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Check for 8-bit immediate, and set sign extend bit in opcode
    if ((opnd_array(2)->constant() >= -128) && (opnd_array(2)->constant() <= 127)) {
      emit_d8(cbuf, opnd_array(2)->constant());
    }
    else {                          // If 32-bit immediate
      // Output immediate
      
if ( opnd_array(2)->constant_is_oop() ) {
  emit_d32_reloc(cbuf, opnd_array(2)->constant(), relocInfo::oop_type, 0);
} else {
  emit_d32(cbuf, opnd_array(2)->constant());
};
    }
  
#line 25752 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compP_eReg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25766 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 25779 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  compP_mem_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x3B /*primary()*/));
  
#line 25793 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(1)->reg(ra_,this,idx1);
    int base  = opnd_array(2)->base(ra_,this,idx2);
    int index = opnd_array(2)->index(ra_,this,idx2);
    int scale = opnd_array(2)->scale();
    int displace = opnd_array(2)->disp(ra_,this,idx2);
    bool disp_is_oop = opnd_array(2)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 25806 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  testP_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x85 /*primary()*/));
  
#line 25820 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(1)->reg(ra_,this,idx1));
  
#line 25827 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  testP_Reg_memNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xF7 /*primary()*/));
  
#line 25841 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2374 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int rm_byte_opcode = (0x00);
    int base     = opnd_array(1)->base(ra_,this,idx1);
    int index    = opnd_array(1)->index(ra_,this,idx1);
    int scale    = opnd_array(1)->scale();
    int displace = opnd_array(1)->disp(ra_,this,idx1);
    bool disp_is_oop = opnd_array(1)->disp_is_oop(); // disp-as-oop when working with static globals
    encode_RegMem(cbuf, rm_byte_opcode, base, index, scale, displace, disp_is_oop);
  
#line 25854 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2219 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d32(cbuf,(0xFFFFFFFF));
  
#line 25861 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  minI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2394 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Compare dst,src
    emit_opcode(cbuf,0x3B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
    // jmp dst < src around move
    emit_opcode(cbuf,0x7C);
    emit_d8(cbuf,2);
    // move dst,src
    emit_opcode(cbuf,0x8B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 25883 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  maxI_eRegNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 2406 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // Compare dst,src
    emit_opcode(cbuf,0x3B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
    // jmp dst > src around move
    emit_opcode(cbuf,0x7F);
    emit_d8(cbuf,2);
    // move dst,src
    emit_opcode(cbuf,0x8B);
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2));
  
#line 25905 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  jumpXtndNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12802 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    address table_base  = __ address_table_constant(_index2label);

    // Jump to Address(table_base + switch_reg)
    InternalAddress table(table_base);
    Address index(noreg, opnd_array(1)->as_Register(ra_,this,idx1), Address::times_1);
    __ jump(ArrayAddress(table, index));
  
#line 25929 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  jmpDirNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xE9 /*primary()*/));
  
#line 25942 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1729 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(1)->label();
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 25950 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpDirNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 5, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 5);
}
void  jmpConNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1763 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 25972 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  jmpLoopEndNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1763 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 25994 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpLoopEndNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  jmpLoopEndUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1763 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 26016 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpLoopEndUNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  jmpLoopEndUCFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1763 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 26038 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpLoopEndUCFNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  jmpConUNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1763 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 26060 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConUNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  jmpConUCFNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1763 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    emit_d32(cbuf, l ? (l->loc_pos() - (cbuf.code_size()+4)) : 0);
  
#line 26082 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConUCFNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  jmpConUCF2Node::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 12927 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label* l = opnd_array(3)->label();
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), Assembler::parity);
    int parity_disp = -1;
    bool ok = false;
    if (opnd_array(1)->ccode() == Assembler::notEqual) {
       // the two jumps 6 bytes apart so the jump distances are too
       parity_disp = l ? (l->loc_pos() - (cbuf.code_size() + 4)) : 0;
    } else if (opnd_array(1)->ccode() == Assembler::equal) {
       parity_disp = 6;
       ok = true;
    } else {
       ShouldNotReachHere();
    }
    emit_d32(cbuf, parity_disp);
    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x80 /*secondary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size() + 4)) : 0;
    emit_d32(cbuf, disp);
  
#line 26125 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConUCF2Node::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 12, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 12);
}
void  partialSubtypeCheckNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1796 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Redi = as_Register(EDI_enc); // result register
    Register Reax = as_Register(EAX_enc); // super class
    Register Recx = as_Register(ECX_enc); // killed
    Register Resi = as_Register(ESI_enc); // sub class
    Label miss;

    MacroAssembler _masm(&cbuf);
    __ check_klass_subtype_slow_path(Resi, Reax, Recx, Redi,
                                     NULL, &miss,
                                     /*set_cond_codes:*/ true);
    if ((0x1 /*primary()*/)) {
      __ xorptr(Redi, Redi);
    }
    __ bind(miss);
  
#line 26156 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  partialSubtypeCheck_vs_ZeroNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1796 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Register Redi = as_Register(EDI_enc); // result register
    Register Reax = as_Register(EAX_enc); // super class
    Register Recx = as_Register(ECX_enc); // killed
    Register Resi = as_Register(ESI_enc); // sub class
    Label miss;

    MacroAssembler _masm(&cbuf);
    __ check_klass_subtype_slow_path(Resi, Reax, Recx, Redi,
                                     NULL, &miss,
                                     /*set_cond_codes:*/ true);
    if ((0x0 /*primary()*/)) {
      __ xorptr(Redi, Redi);
    }
    __ bind(miss);
  
#line 26184 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  jmpDir_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xEB /*primary()*/));
  
#line 26197 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1734 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(1)->label();
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26207 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpDir_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpCon_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1770 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26230 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpCon_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpLoopEnd_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1770 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26253 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpLoopEnd_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpLoopEndU_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1770 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26276 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpLoopEndU_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpLoopEndUCF_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1770 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26299 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpLoopEndUCF_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpConU_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1770 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26322 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConU_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpConUCF_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 1770 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label *l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size()+1)) : 0;
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    emit_d8(cbuf, disp);
  
#line 26345 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConUCF_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 2, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 2);
}
void  jmpConUCF2_shortNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 13126 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label* l = opnd_array(3)->label();
    emit_cc(cbuf, (0x70 /*primary()*/), Assembler::parity);
    int parity_disp = -1;
    if (opnd_array(1)->ccode() == Assembler::notEqual) {
      parity_disp = l ? (l->loc_pos() - (cbuf.code_size() + 1)) : 0;
    } else if (opnd_array(1)->ccode() == Assembler::equal) {
      parity_disp = 2;
    } else {
      ShouldNotReachHere();
    }
    emit_d8(cbuf, parity_disp);
    emit_cc(cbuf, (0x70 /*primary()*/), opnd_array(1)->ccode());
    int disp = l ? (l->loc_pos() - (cbuf.code_size() + 1)) : 0;
    emit_d8(cbuf, disp);
    assert(-128 <= disp && disp <= 127, "Displacement too large for short jmp");
    assert(-128 <= parity_disp && parity_disp <= 127, "Displacement too large for short jmp");
  
#line 26385 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  jmpConUCF2_shortNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 4, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 4);
}
void  cmpL3_reg_regNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
    // Define a MacroAssembler instance for use by the encoding.  The
    // name is chosen to match the __ idiom used for assembly in other
    // parts of hotspot and assumes the existence of the standard
    // #define __ _masm.
    MacroAssembler _masm(&cbuf);

#line 13187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    Label p_one, m_one, done;
    __ xorptr(opnd_array(0)->as_Register(ra_,this), opnd_array(0)->as_Register(ra_,this));
    __ cmpl(HIGH_FROM_LOW(opnd_array(1)->as_Register(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->as_Register(ra_,this,idx2)));
    __ jccb(Assembler::less,    m_one);
    __ jccb(Assembler::greater, p_one);
    __ cmpl(opnd_array(1)->as_Register(ra_,this,idx1), opnd_array(2)->as_Register(ra_,this,idx2));
    __ jccb(Assembler::below,   m_one);
    __ jccb(Assembler::equal,   done);
    __ bind(p_one);
    __ incrementl(opnd_array(0)->as_Register(ra_,this));
    __ jmpb(done);
    __ bind(m_one);
    __ decrementl(opnd_array(0)->as_Register(ra_,this));
    __ bind(done);
  
#line 26422 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpL_zero_flags_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0x85 /*primary()*/));
  
#line 26436 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
  
#line 26443 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpL_reg_flags_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3209 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // CMP    $src1.lo,$src2.lo\t! Long compare; set flags for low bits
    emit_opcode( cbuf, 0x3B );
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2) );
    // MOV    $tmp,$src1.hi
    emit_opcode( cbuf, 0x8B );
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
    // SBB   $tmp,$src2.hi\t! Compute flags for long compare
    emit_opcode( cbuf, 0x1B );
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)) );
  
#line 26466 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovLL_reg_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26483 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2183 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26490 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26498 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3)), HIGH_FROM_LOW(opnd_array(4)->reg(ra_,this,idx4)));
  
#line 26505 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovLL_mem_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26522 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 26535 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26543 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3));  // Hi register of pair, computed from lo
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(4)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 26556 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovII_reg_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26573 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26580 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovII_mem_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26597 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 26610 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovPP_reg_LTGENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26627 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26634 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpL_zero_flags_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3188 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // MOV   $tmp,$src.lo
    emit_opcode(cbuf, 0x8B);
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(1)->reg(ra_,this,idx1));
    // OR    $tmp,$src.hi
    emit_opcode(cbuf, 0x0B);
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)));
  
#line 26654 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpL_reg_flags_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3197 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // CMP    $src1.lo,$src2.lo
    emit_opcode( cbuf, 0x3B );
    emit_rm(cbuf, 0x3, opnd_array(1)->reg(ra_,this,idx1), opnd_array(2)->reg(ra_,this,idx2) );
    // JNE,s  skip
    emit_cc(cbuf, 0x70, 0x5);
    emit_d8(cbuf,2);
    // CMP    $src1.hi,$src2.hi
    emit_opcode( cbuf, 0x3B );
    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)) );
  
#line 26676 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovLL_reg_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26693 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2183 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26700 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26708 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3)), HIGH_FROM_LOW(opnd_array(4)->reg(ra_,this,idx4)));
  
#line 26715 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovLL_mem_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26732 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 26745 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26753 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3));  // Hi register of pair, computed from lo
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(4)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 26766 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovII_reg_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26783 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26790 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovII_mem_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26807 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 26820 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovPP_reg_EQNENode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26837 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26844 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpL_zero_flags_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3221 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // XOR    $tmp,$tmp
    emit_opcode(cbuf,0x33);  // XOR
    emit_rm(cbuf,0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(3)->reg(ra_,this,idx3));
    // CMP    $tmp,$src.lo
    emit_opcode( cbuf, 0x3B );
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(1)->reg(ra_,this,idx1) );
    // SBB    $tmp,$src.hi
    emit_opcode( cbuf, 0x1B );
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
  
#line 26867 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpL_reg_flags_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3209 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // CMP    $src1.lo,$src2.lo\t! Long compare; set flags for low bits
    emit_opcode( cbuf, 0x3B );
    emit_rm(cbuf, 0x3, opnd_array(2)->reg(ra_,this,idx2), opnd_array(1)->reg(ra_,this,idx1) );
    // MOV    $tmp,$src1.hi
    emit_opcode( cbuf, 0x8B );
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(2)->reg(ra_,this,idx2)) );
    // SBB   $tmp,$src2.hi\t! Compute flags for long compare
    emit_opcode( cbuf, 0x1B );
    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), HIGH_FROM_LOW(opnd_array(1)->reg(ra_,this,idx1)) );
  
#line 26890 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovLL_reg_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26907 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2183 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 26914 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26922 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2187 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3)), HIGH_FROM_LOW(opnd_array(4)->reg(ra_,this,idx4)));
  
#line 26929 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovLL_mem_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26946 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 26959 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26967 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2296 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = HIGH_FROM_LOW(opnd_array(3)->reg(ra_,this,idx3));  // Hi register of pair, computed from lo
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4) + 4;      // Offset is 4 further in memory
    assert( !opnd_array(4)->disp_is_oop(), "Cannot add 4 to oop" );
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, false/*disp_is_oop*/);
  
#line 26980 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovII_reg_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 26997 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 27004 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovII_mem_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 2;
    unsigned idx1 = 2;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 27021 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2286 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    int reg_encoding = opnd_array(3)->reg(ra_,this,idx3);
    int base  = opnd_array(4)->base(ra_,this,idx4);
    int index = opnd_array(4)->index(ra_,this,idx4);
    int scale = opnd_array(4)->scale();
    int displace = opnd_array(4)->disp(ra_,this,idx4);
    bool disp_is_oop = opnd_array(4)->disp_is_oop();
    encode_RegMem(cbuf, reg_encoding, base, index, scale, displace, disp_is_oop);
  
#line 27034 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmovPP_reg_LEGTNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 1778 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_d8(cbuf, (0x0F /*primary()*/));
    emit_cc(cbuf, (0x40 /*secondary()*/), opnd_array(1)->ccode());
  
#line 27051 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 2169 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, opnd_array(3)->reg(ra_,this,idx3), opnd_array(4)->reg(ra_,this,idx4));
  
#line 27058 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CallStaticJavaDirectNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1872 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word restore it here
    debug_only(int off0 = cbuf.code_size());
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_std()));
    }
    debug_only(int off1 = cbuf.code_size());
    assert(off1 - off0 == pre_call_FPU_size(), "correct size prediction");
  
#line 27078 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1906 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // CALL to fixup routine.  Fixup routine uses ScopeDesc info to determine
    // who we intended to call.
    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xE8 /*primary()*/));
    if ( !_method ) {
      emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                     runtime_call_Relocation::spec(), RELOC_IMM32 );
    } else if(_optimized_virtual) {
      emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                     opt_virtual_call_Relocation::spec(), RELOC_IMM32 );
    } else {
      emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                     static_call_Relocation::spec(), RELOC_IMM32 );
    }
    if( _method ) {  // Emit stub for static call
      emit_java_to_interp(cbuf);
    }
  
#line 27101 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 67 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/os_cpu/linux_x86/vm/linux_x86_32.ad"

    if( VerifyStackAtCalls ) {
      // Check that stack depth is unchanged: find majik cookie on stack
      int framesize = ra_->reg2offset_unchecked(OptoReg::add(ra_->_matcher._old_SP,-3*VMRegImpl::slots_per_word));
      if(framesize >= 128) {
        emit_opcode(cbuf, 0x81); // cmp [esp+0],0xbadb1ood
        emit_d8(cbuf,0xBC);
        emit_d8(cbuf,0x24);
        emit_d32(cbuf,framesize); // Find majik cookie from ESP
        emit_d32(cbuf, 0xbadb100d);
      }
      else {
        emit_opcode(cbuf, 0x81); // cmp [esp+0],0xbadb1ood
        emit_d8(cbuf,0x7C);
        emit_d8(cbuf,0x24);
        emit_d8(cbuf,framesize); // Find majik cookie from ESP
        emit_d32(cbuf, 0xbadb100d);
      }
      // jmp EQ around INT3
      // QQQ TODO
      const int jump_around = 5; // size of call to breakpoint, 1 for CC
      emit_opcode(cbuf,0x74);
      emit_d8(cbuf, jump_around);
      // QQQ temporary
      emit_break(cbuf);
      // Die if stack mismatch
      // emit_opcode(cbuf,0xCC);
    }
  
#line 27134 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1883 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word do it here also
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_24()));
    }
  
#line 27145 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CallStaticJavaHandleNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1872 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word restore it here
    debug_only(int off0 = cbuf.code_size());
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_std()));
    }
    debug_only(int off1 = cbuf.code_size());
    assert(off1 - off0 == pre_call_FPU_size(), "correct size prediction");
  
#line 27165 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1891 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    debug_only(int off0 = cbuf.code_size());
    MacroAssembler _masm(&cbuf);
    // RBP is preserved across all calls, even compiled calls.
    // Use it to preserve RSP in places where the callee might change the SP.
    __ movptr(rbp_mh_SP_save, rsp);
    debug_only(int off1 = cbuf.code_size());
    assert(off1 - off0 == preserve_SP_size(), "correct size prediction");
  
#line 27178 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1906 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // CALL to fixup routine.  Fixup routine uses ScopeDesc info to determine
    // who we intended to call.
    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xE8 /*primary()*/));
    if ( !_method ) {
      emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                     runtime_call_Relocation::spec(), RELOC_IMM32 );
    } else if(_optimized_virtual) {
      emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                     opt_virtual_call_Relocation::spec(), RELOC_IMM32 );
    } else {
      emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                     static_call_Relocation::spec(), RELOC_IMM32 );
    }
    if( _method ) {  // Emit stub for static call
      emit_java_to_interp(cbuf);
    }
  
#line 27201 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1901 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler _masm(&cbuf);
    __ movptr(rsp, rbp_mh_SP_save);
  
#line 27209 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 67 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/os_cpu/linux_x86/vm/linux_x86_32.ad"

    if( VerifyStackAtCalls ) {
      // Check that stack depth is unchanged: find majik cookie on stack
      int framesize = ra_->reg2offset_unchecked(OptoReg::add(ra_->_matcher._old_SP,-3*VMRegImpl::slots_per_word));
      if(framesize >= 128) {
        emit_opcode(cbuf, 0x81); // cmp [esp+0],0xbadb1ood
        emit_d8(cbuf,0xBC);
        emit_d8(cbuf,0x24);
        emit_d32(cbuf,framesize); // Find majik cookie from ESP
        emit_d32(cbuf, 0xbadb100d);
      }
      else {
        emit_opcode(cbuf, 0x81); // cmp [esp+0],0xbadb1ood
        emit_d8(cbuf,0x7C);
        emit_d8(cbuf,0x24);
        emit_d8(cbuf,framesize); // Find majik cookie from ESP
        emit_d32(cbuf, 0xbadb100d);
      }
      // jmp EQ around INT3
      // QQQ TODO
      const int jump_around = 5; // size of call to breakpoint, 1 for CC
      emit_opcode(cbuf,0x74);
      emit_d8(cbuf, jump_around);
      // QQQ temporary
      emit_break(cbuf);
      // Die if stack mismatch
      // emit_opcode(cbuf,0xCC);
    }
  
#line 27242 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1883 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word do it here also
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_24()));
    }
  
#line 27253 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CallDynamicJavaDirectNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1872 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word restore it here
    debug_only(int off0 = cbuf.code_size());
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_std()));
    }
    debug_only(int off1 = cbuf.code_size());
    assert(off1 - off0 == pre_call_FPU_size(), "correct size prediction");
  
#line 27273 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1926 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // !!!!!
    // Generate  "Mov EAX,0x00", placeholder instruction to load oop-info
    // emit_call_dynamic_prologue( cbuf );
    cbuf.set_inst_mark();
    emit_opcode(cbuf, 0xB8 + EAX_enc);        // mov    EAX,-1
    emit_d32_reloc(cbuf, (int)Universe::non_oop_word(), oop_Relocation::spec_for_immediate(), RELOC_IMM32);
    address  virtual_call_oop_addr = cbuf.inst_mark();
    // CALL to fixup routine.  Fixup routine uses ScopeDesc info to determine
    // who we intended to call.
    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xE8 /*primary()*/));
    emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                virtual_call_Relocation::spec(virtual_call_oop_addr), RELOC_IMM32 );
  
#line 27292 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 67 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/os_cpu/linux_x86/vm/linux_x86_32.ad"

    if( VerifyStackAtCalls ) {
      // Check that stack depth is unchanged: find majik cookie on stack
      int framesize = ra_->reg2offset_unchecked(OptoReg::add(ra_->_matcher._old_SP,-3*VMRegImpl::slots_per_word));
      if(framesize >= 128) {
        emit_opcode(cbuf, 0x81); // cmp [esp+0],0xbadb1ood
        emit_d8(cbuf,0xBC);
        emit_d8(cbuf,0x24);
        emit_d32(cbuf,framesize); // Find majik cookie from ESP
        emit_d32(cbuf, 0xbadb100d);
      }
      else {
        emit_opcode(cbuf, 0x81); // cmp [esp+0],0xbadb1ood
        emit_d8(cbuf,0x7C);
        emit_d8(cbuf,0x24);
        emit_d8(cbuf,framesize); // Find majik cookie from ESP
        emit_d32(cbuf, 0xbadb100d);
      }
      // jmp EQ around INT3
      // QQQ TODO
      const int jump_around = 5; // size of call to breakpoint, 1 for CC
      emit_opcode(cbuf,0x74);
      emit_d8(cbuf, jump_around);
      // QQQ temporary
      emit_break(cbuf);
      // Die if stack mismatch
      // emit_opcode(cbuf,0xCC);
    }
  
#line 27325 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1883 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word do it here also
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_24()));
    }
  
#line 27336 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CallRuntimeDirectNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1872 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word restore it here
    debug_only(int off0 = cbuf.code_size());
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_std()));
    }
    debug_only(int off1 = cbuf.code_size());
    assert(off1 - off0 == pre_call_FPU_size(), "correct size prediction");
  
#line 27356 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1813 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler masm(&cbuf);
    int start = masm.offset();
    if (UseSSE >= 2) {
      if (VerifyFPU) {
        masm.verify_FPU(0, "must be empty in SSE2+ mode");
      }
    } else {
      // External c_calling_convention expects the FPU stack to be 'clean'.
      // Compiled code leaves it dirty.  Do cleanup now.
      masm.empty_FPU_stack();
    }
    if (sizeof_FFree_Float_Stack_All == -1) {
      sizeof_FFree_Float_Stack_All = masm.offset() - start;
    } else {
      assert(masm.offset() - start == sizeof_FFree_Float_Stack_All, "wrong size");
    }
  
#line 27378 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1839 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // This is the instruction starting address for relocation info.
    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xE8 /*primary()*/));
    // CALL directly to the runtime
    emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                runtime_call_Relocation::spec(), RELOC_IMM32 );

    if (UseSSE >= 2) {
      MacroAssembler _masm(&cbuf);
      BasicType rt = tf()->return_type();

      if ((rt == T_FLOAT || rt == T_DOUBLE) && !return_value_is_used()) {
        // A C runtime call where the return value is unused.  In SSE2+
        // mode the result needs to be removed from the FPU stack.  It's
        // likely that this function call could be removed by the
        // optimizer if the C function is a pure function.
        __ ffree(0);
      } else if (rt == T_FLOAT) {
        __ lea(rsp, Address(rsp, -4));
        __ fstp_s(Address(rsp, 0));
        __ movflt(xmm0, Address(rsp, 0));
        __ lea(rsp, Address(rsp,  4));
      } else if (rt == T_DOUBLE) {
        __ lea(rsp, Address(rsp, -8));
        __ fstp_d(Address(rsp, 0));
        __ movdbl(xmm0, Address(rsp, 0));
        __ lea(rsp, Address(rsp,  8));
      }
    }
  
#line 27413 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1883 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word do it here also
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_24()));
    }
  
#line 27424 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CallLeafDirectNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1872 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word restore it here
    debug_only(int off0 = cbuf.code_size());
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_std()));
    }
    debug_only(int off1 = cbuf.code_size());
    assert(off1 - off0 == pre_call_FPU_size(), "correct size prediction");
  
#line 27444 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1813 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    MacroAssembler masm(&cbuf);
    int start = masm.offset();
    if (UseSSE >= 2) {
      if (VerifyFPU) {
        masm.verify_FPU(0, "must be empty in SSE2+ mode");
      }
    } else {
      // External c_calling_convention expects the FPU stack to be 'clean'.
      // Compiled code leaves it dirty.  Do cleanup now.
      masm.empty_FPU_stack();
    }
    if (sizeof_FFree_Float_Stack_All == -1) {
      sizeof_FFree_Float_Stack_All = masm.offset() - start;
    } else {
      assert(masm.offset() - start == sizeof_FFree_Float_Stack_All, "wrong size");
    }
  
#line 27466 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1839 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // This is the instruction starting address for relocation info.
    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xE8 /*primary()*/));
    // CALL directly to the runtime
    emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                runtime_call_Relocation::spec(), RELOC_IMM32 );

    if (UseSSE >= 2) {
      MacroAssembler _masm(&cbuf);
      BasicType rt = tf()->return_type();

      if ((rt == T_FLOAT || rt == T_DOUBLE) && !return_value_is_used()) {
        // A C runtime call where the return value is unused.  In SSE2+
        // mode the result needs to be removed from the FPU stack.  It's
        // likely that this function call could be removed by the
        // optimizer if the C function is a pure function.
        __ ffree(0);
      } else if (rt == T_FLOAT) {
        __ lea(rsp, Address(rsp, -4));
        __ fstp_s(Address(rsp, 0));
        __ movflt(xmm0, Address(rsp, 0));
        __ lea(rsp, Address(rsp,  4));
      } else if (rt == T_DOUBLE) {
        __ lea(rsp, Address(rsp, -8));
        __ fstp_d(Address(rsp, 0));
        __ movdbl(xmm0, Address(rsp, 0));
        __ lea(rsp, Address(rsp,  8));
      }
    }
  
#line 27501 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1832 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    if( VerifyFPU ) {
      MacroAssembler masm(&cbuf);
      masm.verify_FPU( -3, "Returning from Runtime Leaf call");
    }
  
#line 27511 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1883 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // If method sets FPU control word do it here also
    if( Compile::current()->in_24_bit_fp_mode() ) {
      MacroAssembler masm(&cbuf);
      masm.fldcw(ExternalAddress(StubRoutines::addr_fpu_cntrl_wrd_24()));
    }
  
#line 27522 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CallLeafNoFPDirectNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 1839 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // This is the instruction starting address for relocation info.
    cbuf.set_inst_mark();
    emit_d8(cbuf, (0xE8 /*primary()*/));
    // CALL directly to the runtime
    emit_d32_reloc(cbuf, (opnd_array(1)->method() - (int)(cbuf.code_end()) - 4),
                runtime_call_Relocation::spec(), RELOC_IMM32 );

    if (UseSSE >= 2) {
      MacroAssembler _masm(&cbuf);
      BasicType rt = tf()->return_type();

      if ((rt == T_FLOAT || rt == T_DOUBLE) && !return_value_is_used()) {
        // A C runtime call where the return value is unused.  In SSE2+
        // mode the result needs to be removed from the FPU stack.  It's
        // likely that this function call could be removed by the
        // optimizer if the C function is a pure function.
        __ ffree(0);
      } else if (rt == T_FLOAT) {
        __ lea(rsp, Address(rsp, -4));
        __ fstp_s(Address(rsp, 0));
        __ movflt(xmm0, Address(rsp, 0));
        __ lea(rsp, Address(rsp,  4));
      } else if (rt == T_DOUBLE) {
        __ lea(rsp, Address(rsp, -8));
        __ fstp_d(Address(rsp, 0));
        __ movdbl(xmm0, Address(rsp, 0));
        __ lea(rsp, Address(rsp,  8));
      }
    }
  
#line 27563 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  RetNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xC3 /*primary()*/));
  
#line 27576 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  TailCalljmpIndNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFF /*primary()*/));
  
#line 27590 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 27597 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  tailjmpIndNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
  {
#line 3822 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf,0x5A);
  
#line 27611 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1594 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_opcode(cbuf, (0xFF /*primary()*/));
  
#line 27618 "../generated/adfiles/ad_x86_32.cpp"
}
  {
#line 1759 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    emit_rm(cbuf, 0x3, (0x4 /*secondary()*/), opnd_array(1)->reg(ra_,this,idx1) );
  
#line 27625 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  CreateExceptionNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  // User did not define which encode class to use.
}
uint  CreateExceptionNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 0, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 0);
}
void  RethrowExceptionNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
  {
#line 3826 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.set_inst_mark();
    emit_opcode(cbuf, 0xE9);        // jmp    entry
    emit_d32_reloc(cbuf, (int)OptoRuntime::rethrow_stub() - ((int)cbuf.code_end())-4,
                   runtime_call_Relocation::spec(), RELOC_IMM32 );
  
#line 27652 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpFastLockNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
    unsigned idx4 = idx3 + opnd_array(3)->num_edges();
  {
#line 3361 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"


    Register objReg = as_Register(opnd_array(1)->reg(ra_,this,idx1));
    Register boxReg = as_Register(opnd_array(2)->reg(ra_,this,idx2));
    Register tmpReg = as_Register(opnd_array(3)->reg(ra_,this,idx3));
    Register scrReg = as_Register(opnd_array(4)->reg(ra_,this,idx4));

    // Ensure the register assignents are disjoint
    guarantee (objReg != boxReg, "") ;
    guarantee (objReg != tmpReg, "") ;
    guarantee (objReg != scrReg, "") ;
    guarantee (boxReg != tmpReg, "") ;
    guarantee (boxReg != scrReg, "") ;
    guarantee (tmpReg == as_Register(EAX_enc), "") ;

    MacroAssembler masm(&cbuf);

    if (_counters != NULL) {
      masm.atomic_incl(ExternalAddress((address) _counters->total_entry_count_addr()));
    }
    if (EmitSync & 1) {
        // set box->dhw = unused_mark (3)
        // Force all sync thru slow-path: slow_enter() and slow_exit()
        masm.movptr (Address(boxReg, 0), int32_t(markOopDesc::unused_mark())) ;
        masm.cmpptr (rsp, (int32_t)0) ;
    } else
    if (EmitSync & 2) {
        Label DONE_LABEL ;
        if (UseBiasedLocking) {
           // Note: tmpReg maps to the swap_reg argument and scrReg to the tmp_reg argument.
           masm.biased_locking_enter(boxReg, objReg, tmpReg, scrReg, false, DONE_LABEL, NULL, _counters);
        }

        masm.movptr(tmpReg, Address(objReg, 0)) ;          // fetch markword
        masm.orptr (tmpReg, 0x1);
        masm.movptr(Address(boxReg, 0), tmpReg);           // Anticipate successful CAS
        if (os::is_MP()) { masm.lock();  }
        masm.cmpxchgptr(boxReg, Address(objReg, 0));          // Updates tmpReg
        masm.jcc(Assembler::equal, DONE_LABEL);
        // Recursive locking
        masm.subptr(tmpReg, rsp);
        masm.andptr(tmpReg, (int32_t) 0xFFFFF003 );
        masm.movptr(Address(boxReg, 0), tmpReg);
        masm.bind(DONE_LABEL) ;
    } else {
      // Possible cases that we'll encounter in fast_lock
      // ------------------------------------------------
      // * Inflated
      //    -- unlocked
      //    -- Locked
      //       = by self
      //       = by other
      // * biased
      //    -- by Self
      //    -- by other
      // * neutral
      // * stack-locked
      //    -- by self
      //       = sp-proximity test hits
      //       = sp-proximity test generates false-negative
      //    -- by other
      //

      Label IsInflated, DONE_LABEL, PopDone ;

      // TODO: optimize away redundant LDs of obj->mark and improve the markword triage
      // order to reduce the number of conditional branches in the most common cases.
      // Beware -- there's a subtle invariant that fetch of the markword
      // at [FETCH], below, will never observe a biased encoding (*101b).
      // If this invariant is not held we risk exclusion (safety) failure.
      if (UseBiasedLocking && !UseOptoBiasInlining) {
        masm.biased_locking_enter(boxReg, objReg, tmpReg, scrReg, false, DONE_LABEL, NULL, _counters);
      }

      masm.movptr(tmpReg, Address(objReg, 0)) ;         // [FETCH]
      masm.testptr(tmpReg, 0x02) ;                      // Inflated v (Stack-locked or neutral)
      masm.jccb  (Assembler::notZero, IsInflated) ;

      // Attempt stack-locking ...
      masm.orptr (tmpReg, 0x1);
      masm.movptr(Address(boxReg, 0), tmpReg);          // Anticipate successful CAS
      if (os::is_MP()) { masm.lock();  }
      masm.cmpxchgptr(boxReg, Address(objReg, 0));           // Updates tmpReg
      if (_counters != NULL) {
        masm.cond_inc32(Assembler::equal,
                        ExternalAddress((address)_counters->fast_path_entry_count_addr()));
      }
      masm.jccb (Assembler::equal, DONE_LABEL);

      // Recursive locking
      masm.subptr(tmpReg, rsp);
      masm.andptr(tmpReg, 0xFFFFF003 );
      masm.movptr(Address(boxReg, 0), tmpReg);
      if (_counters != NULL) {
        masm.cond_inc32(Assembler::equal,
                        ExternalAddress((address)_counters->fast_path_entry_count_addr()));
      }
      masm.jmp  (DONE_LABEL) ;

      masm.bind (IsInflated) ;

      // The object is inflated.
      //
      // TODO-FIXME: eliminate the ugly use of manifest constants:
      //   Use markOopDesc::monitor_value instead of "2".
      //   use markOop::unused_mark() instead of "3".
      // The tmpReg value is an objectMonitor reference ORed with
      // markOopDesc::monitor_value (2).   We can either convert tmpReg to an
      // objectmonitor pointer by masking off the "2" bit or we can just
      // use tmpReg as an objectmonitor pointer but bias the objectmonitor
      // field offsets with "-2" to compensate for and annul the low-order tag bit.
      //
      // I use the latter as it avoids AGI stalls.
      // As such, we write "mov r, [tmpReg+OFFSETOF(Owner)-2]"
      // instead of "mov r, [tmpReg+OFFSETOF(Owner)]".
      //
      #define OFFSET_SKEWED(f) ((ObjectMonitor::f ## _offset_in_bytes())-2)

      // boxReg refers to the on-stack BasicLock in the current frame.
      // We'd like to write:
      //   set box->_displaced_header = markOop::unused_mark().  Any non-0 value suffices.
      // This is convenient but results a ST-before-CAS penalty.  The following CAS suffers
      // additional latency as we have another ST in the store buffer that must drain.

      if (EmitSync & 8192) {
         masm.movptr(Address(boxReg, 0), 3) ;            // results in ST-before-CAS penalty
         masm.get_thread (scrReg) ; 
         masm.movptr(boxReg, tmpReg);                    // consider: LEA box, [tmp-2] 
         masm.movptr(tmpReg, NULL_WORD);                 // consider: xor vs mov
         if (os::is_MP()) { masm.lock(); } 
         masm.cmpxchgptr(scrReg, Address(boxReg, ObjectMonitor::owner_offset_in_bytes()-2)) ; 
      } else 
      if ((EmitSync & 128) == 0) {                      // avoid ST-before-CAS
         masm.movptr(scrReg, boxReg) ;
         masm.movptr(boxReg, tmpReg);                   // consider: LEA box, [tmp-2]

         // Using a prefetchw helps avoid later RTS->RTO upgrades and cache probes
         if ((EmitSync & 2048) && VM_Version::supports_3dnow() && os::is_MP()) {
            // prefetchw [eax + Offset(_owner)-2]
            masm.prefetchw(Address(rax, ObjectMonitor::owner_offset_in_bytes()-2));
         }

         if ((EmitSync & 64) == 0) {
           // Optimistic form: consider XORL tmpReg,tmpReg
           masm.movptr(tmpReg, NULL_WORD) ; 
         } else { 
           // Can suffer RTS->RTO upgrades on shared or cold $ lines
           // Test-And-CAS instead of CAS
           masm.movptr(tmpReg, Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2)) ;   // rax, = m->_owner
           masm.testptr(tmpReg, tmpReg) ;                   // Locked ?
           masm.jccb  (Assembler::notZero, DONE_LABEL) ;
         }

         // Appears unlocked - try to swing _owner from null to non-null.
         // Ideally, I'd manifest "Self" with get_thread and then attempt
         // to CAS the register containing Self into m->Owner.
         // But we don't have enough registers, so instead we can either try to CAS
         // rsp or the address of the box (in scr) into &m->owner.  If the CAS succeeds
         // we later store "Self" into m->Owner.  Transiently storing a stack address
         // (rsp or the address of the box) into  m->owner is harmless.
         // Invariant: tmpReg == 0.  tmpReg is EAX which is the implicit cmpxchg comparand.
         if (os::is_MP()) { masm.lock();  }
         masm.cmpxchgptr(scrReg, Address(boxReg, ObjectMonitor::owner_offset_in_bytes()-2)) ;
         masm.movptr(Address(scrReg, 0), 3) ;          // box->_displaced_header = 3
         masm.jccb  (Assembler::notZero, DONE_LABEL) ;
         masm.get_thread (scrReg) ;                    // beware: clobbers ICCs
         masm.movptr(Address(boxReg, ObjectMonitor::owner_offset_in_bytes()-2), scrReg) ;
         masm.xorptr(boxReg, boxReg) ;                 // set icc.ZFlag = 1 to indicate success

         // If the CAS fails we can either retry or pass control to the slow-path.
         // We use the latter tactic.
         // Pass the CAS result in the icc.ZFlag into DONE_LABEL
         // If the CAS was successful ...
         //   Self has acquired the lock
         //   Invariant: m->_recursions should already be 0, so we don't need to explicitly set it.
         // Intentional fall-through into DONE_LABEL ...
      } else {
         masm.movptr(Address(boxReg, 0), 3) ;       // results in ST-before-CAS penalty
         masm.movptr(boxReg, tmpReg) ;

         // Using a prefetchw helps avoid later RTS->RTO upgrades and cache probes
         if ((EmitSync & 2048) && VM_Version::supports_3dnow() && os::is_MP()) {
            // prefetchw [eax + Offset(_owner)-2]
            masm.prefetchw(Address(rax, ObjectMonitor::owner_offset_in_bytes()-2));
         }

         if ((EmitSync & 64) == 0) {
           // Optimistic form
           masm.xorptr  (tmpReg, tmpReg) ;
         } else {
           // Can suffer RTS->RTO upgrades on shared or cold $ lines
           masm.movptr(tmpReg, Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2)) ;   // rax, = m->_owner
           masm.testptr(tmpReg, tmpReg) ;                   // Locked ?
           masm.jccb  (Assembler::notZero, DONE_LABEL) ;
         }

         // Appears unlocked - try to swing _owner from null to non-null.
         // Use either "Self" (in scr) or rsp as thread identity in _owner.
         // Invariant: tmpReg == 0.  tmpReg is EAX which is the implicit cmpxchg comparand.
         masm.get_thread (scrReg) ;
         if (os::is_MP()) { masm.lock(); }
         masm.cmpxchgptr(scrReg, Address(boxReg, ObjectMonitor::owner_offset_in_bytes()-2)) ;

         // If the CAS fails we can either retry or pass control to the slow-path.
         // We use the latter tactic.
         // Pass the CAS result in the icc.ZFlag into DONE_LABEL
         // If the CAS was successful ...
         //   Self has acquired the lock
         //   Invariant: m->_recursions should already be 0, so we don't need to explicitly set it.
         // Intentional fall-through into DONE_LABEL ...
      }

      // DONE_LABEL is a hot target - we'd really like to place it at the
      // start of cache line by padding with NOPs.
      // See the AMD and Intel software optimization manuals for the
      // most efficient "long" NOP encodings.
      // Unfortunately none of our alignment mechanisms suffice.
      masm.bind(DONE_LABEL);

      // Avoid branch-to-branch on AMD processors
      // This appears to be superstition.
      if (EmitSync & 32) masm.nop() ;


      // At DONE_LABEL the icc ZFlag is set as follows ...
      // Fast_Unlock uses the same protocol.
      // ZFlag == 1 -> Success
      // ZFlag == 0 -> Failure - force control through the slow-path
    }
  
#line 27895 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  cmpFastUnlockNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
    unsigned idx2 = idx1 + opnd_array(1)->num_edges();
    unsigned idx3 = idx2 + opnd_array(2)->num_edges();
  {
#line 3619 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"


    Register objReg = as_Register(opnd_array(1)->reg(ra_,this,idx1));
    Register boxReg = as_Register(opnd_array(2)->reg(ra_,this,idx2));
    Register tmpReg = as_Register(opnd_array(3)->reg(ra_,this,idx3));

    guarantee (objReg != boxReg, "") ;
    guarantee (objReg != tmpReg, "") ;
    guarantee (boxReg != tmpReg, "") ;
    guarantee (boxReg == as_Register(EAX_enc), "") ;
    MacroAssembler masm(&cbuf);

    if (EmitSync & 4) {
      // Disable - inhibit all inlining.  Force control through the slow-path
      masm.cmpptr (rsp, 0) ;
    } else
    if (EmitSync & 8) {
      Label DONE_LABEL ;
      if (UseBiasedLocking) {
         masm.biased_locking_exit(objReg, tmpReg, DONE_LABEL);
      }
      // classic stack-locking code ...
      masm.movptr(tmpReg, Address(boxReg, 0)) ;
      masm.testptr(tmpReg, tmpReg) ;
      masm.jcc   (Assembler::zero, DONE_LABEL) ;
      if (os::is_MP()) { masm.lock(); }
      masm.cmpxchgptr(tmpReg, Address(objReg, 0));          // Uses EAX which is box
      masm.bind(DONE_LABEL);
    } else {
      Label DONE_LABEL, Stacked, CheckSucc, Inflated ;

      // Critically, the biased locking test must have precedence over
      // and appear before the (box->dhw == 0) recursive stack-lock test.
      if (UseBiasedLocking && !UseOptoBiasInlining) {
         masm.biased_locking_exit(objReg, tmpReg, DONE_LABEL);
      }

      masm.cmpptr(Address(boxReg, 0), 0) ;            // Examine the displaced header
      masm.movptr(tmpReg, Address(objReg, 0)) ;       // Examine the object's markword
      masm.jccb  (Assembler::zero, DONE_LABEL) ;      // 0 indicates recursive stack-lock

      masm.testptr(tmpReg, 0x02) ;                     // Inflated?
      masm.jccb  (Assembler::zero, Stacked) ;

      masm.bind  (Inflated) ;
      // It's inflated.
      // Despite our balanced locking property we still check that m->_owner == Self
      // as java routines or native JNI code called by this thread might
      // have released the lock.
      // Refer to the comments in synchronizer.cpp for how we might encode extra
      // state in _succ so we can avoid fetching EntryList|cxq.
      //
      // I'd like to add more cases in fast_lock() and fast_unlock() --
      // such as recursive enter and exit -- but we have to be wary of
      // I$ bloat, T$ effects and BP$ effects.
      //
      // If there's no contention try a 1-0 exit.  That is, exit without
      // a costly MEMBAR or CAS.  See synchronizer.cpp for details on how
      // we detect and recover from the race that the 1-0 exit admits.
      //
      // Conceptually Fast_Unlock() must execute a STST|LDST "release" barrier
      // before it STs null into _owner, releasing the lock.  Updates
      // to data protected by the critical section must be visible before
      // we drop the lock (and thus before any other thread could acquire
      // the lock and observe the fields protected by the lock).
      // IA32's memory-model is SPO, so STs are ordered with respect to
      // each other and there's no need for an explicit barrier (fence).
      // See also http://gee.cs.oswego.edu/dl/jmm/cookbook.html.

      masm.get_thread (boxReg) ;
      if ((EmitSync & 4096) && VM_Version::supports_3dnow() && os::is_MP()) {
        // prefetchw [ebx + Offset(_owner)-2]
        masm.prefetchw(Address(rbx, ObjectMonitor::owner_offset_in_bytes()-2));
      }

      // Note that we could employ various encoding schemes to reduce
      // the number of loads below (currently 4) to just 2 or 3.
      // Refer to the comments in synchronizer.cpp.
      // In practice the chain of fetches doesn't seem to impact performance, however.
      if ((EmitSync & 65536) == 0 && (EmitSync & 256)) {
         // Attempt to reduce branch density - AMD's branch predictor.
         masm.xorptr(boxReg, Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2)) ;
         masm.orptr(boxReg, Address (tmpReg, ObjectMonitor::recursions_offset_in_bytes()-2)) ;
         masm.orptr(boxReg, Address (tmpReg, ObjectMonitor::EntryList_offset_in_bytes()-2)) ; 
         masm.orptr(boxReg, Address (tmpReg, ObjectMonitor::cxq_offset_in_bytes()-2)) ; 
         masm.jccb  (Assembler::notZero, DONE_LABEL) ; 
         masm.movptr(Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2), NULL_WORD) ; 
         masm.jmpb  (DONE_LABEL) ; 
      } else { 
         masm.xorptr(boxReg, Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2)) ;  
         masm.orptr(boxReg, Address (tmpReg, ObjectMonitor::recursions_offset_in_bytes()-2)) ;
         masm.jccb  (Assembler::notZero, DONE_LABEL) ; 
         masm.movptr(boxReg, Address (tmpReg, ObjectMonitor::EntryList_offset_in_bytes()-2)) ; 
         masm.orptr(boxReg, Address (tmpReg, ObjectMonitor::cxq_offset_in_bytes()-2)) ; 
         masm.jccb  (Assembler::notZero, CheckSucc) ; 
         masm.movptr(Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2), NULL_WORD) ; 
         masm.jmpb  (DONE_LABEL) ; 
      }

      // The Following code fragment (EmitSync & 65536) improves the performance of
      // contended applications and contended synchronization microbenchmarks.
      // Unfortunately the emission of the code - even though not executed - causes regressions
      // in scimark and jetstream, evidently because of $ effects.  Replacing the code
      // with an equal number of never-executed NOPs results in the same regression.
      // We leave it off by default.

      if ((EmitSync & 65536) != 0) {
         Label LSuccess, LGoSlowPath ;

         masm.bind  (CheckSucc) ;

         // Optional pre-test ... it's safe to elide this
         if ((EmitSync & 16) == 0) {
            masm.cmpptr(Address (tmpReg, ObjectMonitor::succ_offset_in_bytes()-2), 0) ;
            masm.jccb  (Assembler::zero, LGoSlowPath) ;
         }

         // We have a classic Dekker-style idiom:
         //    ST m->_owner = 0 ; MEMBAR; LD m->_succ
         // There are a number of ways to implement the barrier:
         // (1) lock:andl &m->_owner, 0
         //     is fast, but mask doesn't currently support the "ANDL M,IMM32" form.
         //     LOCK: ANDL [ebx+Offset(_Owner)-2], 0
         //     Encodes as 81 31 OFF32 IMM32 or 83 63 OFF8 IMM8
         // (2) If supported, an explicit MFENCE is appealing.
         //     In older IA32 processors MFENCE is slower than lock:add or xchg
         //     particularly if the write-buffer is full as might be the case if
         //     if stores closely precede the fence or fence-equivalent instruction.
         //     In more modern implementations MFENCE appears faster, however.
         // (3) In lieu of an explicit fence, use lock:addl to the top-of-stack
         //     The $lines underlying the top-of-stack should be in M-state.
         //     The locked add instruction is serializing, of course.
         // (4) Use xchg, which is serializing
         //     mov boxReg, 0; xchgl boxReg, [tmpReg + Offset(_owner)-2] also works
         // (5) ST m->_owner = 0 and then execute lock:orl &m->_succ, 0.
         //     The integer condition codes will tell us if succ was 0.
         //     Since _succ and _owner should reside in the same $line and
         //     we just stored into _owner, it's likely that the $line
         //     remains in M-state for the lock:orl.
         //
         // We currently use (3), although it's likely that switching to (2)
         // is correct for the future.
            
         masm.movptr(Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2), NULL_WORD) ; 
         if (os::is_MP()) { 
            if (VM_Version::supports_sse2() && 1 == FenceInstruction) { 
              masm.mfence();
            } else {
              masm.lock () ; masm.addptr(Address(rsp, 0), 0) ;
            }
         }
         // Ratify _succ remains non-null
         masm.cmpptr(Address (tmpReg, ObjectMonitor::succ_offset_in_bytes()-2), 0) ;
         masm.jccb  (Assembler::notZero, LSuccess) ;

         masm.xorptr(boxReg, boxReg) ;                  // box is really EAX
         if (os::is_MP()) { masm.lock(); }
         masm.cmpxchgptr(rsp, Address(tmpReg, ObjectMonitor::owner_offset_in_bytes()-2));
         masm.jccb  (Assembler::notEqual, LSuccess) ;
         // Since we're low on registers we installed rsp as a placeholding in _owner.
         // Now install Self over rsp.  This is safe as we're transitioning from
         // non-null to non=null
         masm.get_thread (boxReg) ;
         masm.movptr(Address (tmpReg, ObjectMonitor::owner_offset_in_bytes()-2), boxReg) ;
         // Intentional fall-through into LGoSlowPath ...

         masm.bind  (LGoSlowPath) ;
         masm.orptr(boxReg, 1) ;                      // set ICC.ZF=0 to indicate failure
         masm.jmpb  (DONE_LABEL) ;

         masm.bind  (LSuccess) ;
         masm.xorptr(boxReg, boxReg) ;                 // set ICC.ZF=1 to indicate success
         masm.jmpb  (DONE_LABEL) ;
      }

      masm.bind (Stacked) ;
      // It's not inflated and it's not recursively stack-locked and it's not biased.
      // It must be stack-locked.
      // Try to reset the header to displaced header.
      // The "box" value on the stack is stable, so we can reload
      // and be assured we observe the same value as above.
      masm.movptr(tmpReg, Address(boxReg, 0)) ;
      if (os::is_MP()) {   masm.lock();    }
      masm.cmpxchgptr(tmpReg, Address(objReg, 0)); // Uses EAX which is box
      // Intention fall-thru into DONE_LABEL


      // DONE_LABEL is a hot target - we'd really like to place it at the
      // start of cache line by padding with NOPs.
      // See the AMD and Intel software optimization manuals for the
      // most efficient "long" NOP encodings.
      // Unfortunately none of our alignment mechanisms suffice.
      if ((EmitSync & 65536) == 0) {
         masm.bind (CheckSucc) ;
      }
      masm.bind(DONE_LABEL);

      // Avoid branch to branch on AMD processors
      if (EmitSync & 32768) { masm.nop() ; }
    }
  
#line 28108 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  safePoint_pollNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
  {
#line 4401 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    cbuf.relocate(cbuf.inst_mark(), relocInfo::poll_type, 0);
    emit_opcode(cbuf,0x85);
    emit_rm (cbuf, 0x0, 0x7, 0x5);
    emit_d32(cbuf, (intptr_t)os::get_polling_page());
  
#line 28124 "../generated/adfiles/ad_x86_32.cpp"
}
}
uint  safePoint_pollNode::size(PhaseRegAlloc *ra_) const {
 assert(VerifyOops || MachNode::size(ra_) <= 6, "bad fixed size");
 return (VerifyOops ? MachNode::size(ra_) : 6);
}
void  tlsLoadPNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 1;
    unsigned idx1 = 1;
  {
#line 56 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/os_cpu/linux_x86/vm/linux_x86_32.ad"

    Register dstReg = as_Register(opnd_array(0)->reg(ra_,this));
    MacroAssembler* masm = new MacroAssembler(&cbuf);
      masm->get_thread(dstReg);
  
#line 28143 "../generated/adfiles/ad_x86_32.cpp"
}
}
void  ShouldNotReachHereNode::emit(CodeBuffer &cbuf, PhaseRegAlloc *ra_) const {
    cbuf.set_inst_mark();
    // Start at oper_input_base() and count operands
    unsigned idx0 = 5;
    unsigned idx1 = 5;
  {
#line 62 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/os_cpu/linux_x86/vm/linux_x86_32.ad"

    MacroAssembler* masm = new MacroAssembler(&cbuf);
    masm->call(RuntimeAddress(CAST_FROM_FN_PTR(address, os::breakpoint)));
  
#line 28157 "../generated/adfiles/ad_x86_32.cpp"
}
}
const MachOper* popCountI_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* popCountL_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadBNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadB2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUBNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUB2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUB2L_immI8Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadSNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadS2BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadS2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUSNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2L_immI_255Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadUS2L_immI16Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadINode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2UBNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2SNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2USNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_immI_255Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_immI_65535Node::memory_operand() const { return _opnds[1]; }
const MachOper* loadI2L_immINode::memory_operand() const { return _opnds[1]; }
const MachOper* loadUI2LNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadL_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLX_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLX_reg_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadRangeNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadPNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadKlassNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadDNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadXDNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadXD_partialNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadXNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadFNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadA8BNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadA4SNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadA4CNode::memory_operand() const { return _opnds[1]; }
const MachOper* load2IUNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadA2FNode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchr0Node::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchrNode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchrNTANode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchrT0Node::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchrT2Node::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchw0Node::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchwNode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchwNTANode::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchwT0Node::memory_operand() const { return _opnds[1]; }
const MachOper* prefetchwT2Node::memory_operand() const { return _opnds[1]; }
const MachOper* storeBNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeCNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeINode::memory_operand() const { return _opnds[1]; }
const MachOper* storeLNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeL2INode::memory_operand() const { return _opnds[1]; }
const MachOper* storeL_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeLX_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeLX_reg_volatileNode::memory_operand() const { return _opnds[1]; }
const MachOper* storePNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeImmINode::memory_operand() const { return _opnds[1]; }
const MachOper* storeImmI16Node::memory_operand() const { return _opnds[1]; }
const MachOper* storeImmPNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeImmBNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeA8BNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeA4CNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeA2INode::memory_operand() const { return _opnds[1]; }
const MachOper* storeImmCMNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeDNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeD_roundedNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeXDNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeXNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeA2FNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeFNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeF_roundedNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeF_DroundedNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeF_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeX_immNode::memory_operand() const { return _opnds[1]; }
const TypePtr *membar_acquireNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_acquireNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_acquire_lockNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_acquire_lockNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_releaseNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_releaseNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *membar_release_lockNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* membar_release_lockNode::memory_operand() const { return (MachOper*)-1; }
const MachOper* cmovI_memNode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovI_memUNode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovI_memUCFNode::memory_operand() const { return _opnds[4]; }
const MachOper* addI_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addI_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* addI_mem_eRegNode::memory_operand() const { return _opnds[1]; }
const MachOper* addI_mem_eReg_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* addI_mem_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* incI_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* decI_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadPLockedNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLLockedNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLX_LockedNode::memory_operand() const { return _opnds[1]; }
const MachOper* loadLX_reg_LockedNode::memory_operand() const { return _opnds[1]; }
const MachOper* storePConditionalNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeIConditionalNode::memory_operand() const { return _opnds[1]; }
const MachOper* storeLConditionalNode::memory_operand() const { return _opnds[1]; }
const MachOper* subI_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* subI_mem_eRegNode::memory_operand() const { return _opnds[1]; }
const MachOper* mulI_mem_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* mulINode::memory_operand() const { return _opnds[2]; }
const MachOper* mulI_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* sarI_mem_1Node::memory_operand() const { return _opnds[1]; }
const MachOper* sarI_mem_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* andI_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* andI_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* andI_mem_eRegNode::memory_operand() const { return _opnds[1]; }
const MachOper* andI_mem_eReg_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* andI_mem_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* orI_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* orI_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* orI_mem_eRegNode::memory_operand() const { return _opnds[1]; }
const MachOper* orI_mem_eReg_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* orI_mem_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* xorI_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* xorI_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* xorI_mem_eRegNode::memory_operand() const { return _opnds[1]; }
const MachOper* xorI_mem_eReg_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* xorI_mem_immNode::memory_operand() const { return _opnds[1]; }
const MachOper* addL_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addL_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* subL_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* andL_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* andL_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* orl_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* orl_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* xorl_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* xorl_eReg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* cmpXD_ccmemNode::memory_operand() const { return _opnds[2]; }
const MachOper* cmpXD_ccmemCFNode::memory_operand() const { return _opnds[2]; }
const MachOper* cmpXD_regmemNode::memory_operand() const { return _opnds[2]; }
const MachOper* subD_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addD_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addD_reg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* addD_mem_regNode::memory_operand() const { return _opnds[1]; }
const MachOper* addD_mem_reg_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* addXD_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addXD_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* subXD_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulXD_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulXD_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* divXD_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulD_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulD_reg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* mulD_reg_mem_ciscNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulD_reg_mem_cisc_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* cmpX_ccmemNode::memory_operand() const { return _opnds[2]; }
const MachOper* cmpX_ccmemCFNode::memory_operand() const { return _opnds[2]; }
const MachOper* cmpX_regmemNode::memory_operand() const { return _opnds[2]; }
const MachOper* addX_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addX_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* subX_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulX_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulX_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* divX_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* sqrtX_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* sqrtXD_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* addF24_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addF24_reg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* addF_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* addF_reg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* addF24_mem_regNode::memory_operand() const { return _opnds[1]; }
const TypePtr *addF24_mem_ciscNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* addF24_mem_ciscNode::memory_operand() const { return (MachOper*)-1; }
const TypePtr *addF24_mem_cisc_0Node::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* addF24_mem_cisc_0Node::memory_operand() const { return (MachOper*)-1; }
const TypePtr *addF24_mem_memNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* addF24_mem_memNode::memory_operand() const { return (MachOper*)-1; }
const MachOper* mulF24_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulF24_reg_mem_0Node::memory_operand() const { return _opnds[1]; }
const MachOper* mulF_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* mulF_reg_mem_0Node::memory_operand() const { return _opnds[1]; }
const TypePtr *mulF24_mem_memNode::adr_type() const { return TypePtr::BOTTOM; }
const MachOper* mulF24_mem_memNode::memory_operand() const { return (MachOper*)-1; }
const MachOper* mulF_reg_load1Node::memory_operand() const { return _opnds[1]; }
const MachOper* mulF_reg_load1_0Node::memory_operand() const { return _opnds[2]; }
const MachOper* addF_mulF_reg_load1Node::memory_operand() const { return _opnds[1]; }
const MachOper* addF_mulF_reg_load1_1Node::memory_operand() const { return _opnds[2]; }
const MachOper* addF_mulF_reg_load1_0Node::memory_operand() const { return _opnds[2]; }
const MachOper* addF_mulF_reg_load1_2Node::memory_operand() const { return _opnds[3]; }
const MachOper* convI2XD_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* convI2D_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* convI2F_SSF_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* convI2F_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* compI_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* testI_reg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* compU_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* compP_eReg_memNode::memory_operand() const { return _opnds[2]; }
const MachOper* compP_mem_eRegNode::memory_operand() const { return _opnds[2]; }
const MachOper* testP_Reg_memNode::memory_operand() const { return _opnds[1]; }
const MachOper* cmovLL_mem_LTGENode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovII_mem_LTGENode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovLL_mem_EQNENode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovII_mem_EQNENode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovLL_mem_LEGTNode::memory_operand() const { return _opnds[4]; }
const MachOper* cmovII_mem_LEGTNode::memory_operand() const { return _opnds[4]; }


const bool Matcher::has_match_rule(int opcode) {
  assert(_last_machine_leaf < opcode && opcode < _last_opcode, "opcode in range");
  return _hasMatchRule[opcode];
}

const bool Matcher::_hasMatchRule[_last_opcode] = {
    false,  // Node
    false,  // Set
    false,  // RegN
    false,  // RegI
    false,  // RegP
    false,  // RegF
    false,  // RegD
    false,  // RegL
    false,  // RegFlags
    false,  // _last_machine_leaf
    true ,  // AbsD
    true ,  // AbsF
    false,  // AbsI
    true ,  // AddD
    true ,  // AddF
    true ,  // AddI
    true ,  // AddL
    true ,  // AddP
    false,  // Allocate
    false,  // AllocateArray
    true ,  // AndI
    true ,  // AndL
    true ,  // AryEq
    true ,  // AtanD
    true ,  // Binary
    true ,  // Bool
    false,  // BoxLock
    true ,  // ReverseBytesI
    true ,  // ReverseBytesL
    true ,  // ReverseBytesUS
    true ,  // ReverseBytesS
    false,  // CProj
    true ,  // CallDynamicJava
    false,  // CallJava
    true ,  // CallLeaf
    true ,  // CallLeafNoFP
    true ,  // CallRuntime
    true ,  // CallStaticJava
    true ,  // CastII
    true ,  // CastX2P
    true ,  // CastP2X
    true ,  // CastPP
    false,  // Catch
    false,  // CatchProj
    true ,  // CheckCastPP
    true ,  // ClearArray
    false,  // ConstraintCast
    true ,  // CMoveD
    true ,  // CMoveF
    true ,  // CMoveI
    true ,  // CMoveL
    true ,  // CMoveP
    false,  // CMoveN
    false,  // CmpN
    true ,  // CmpD
    true ,  // CmpD3
    true ,  // CmpF
    true ,  // CmpF3
    true ,  // CmpI
    true ,  // CmpL
    true ,  // CmpL3
    true ,  // CmpLTMask
    true ,  // CmpP
    true ,  // CmpU
    true ,  // CompareAndSwapI
    true ,  // CompareAndSwapL
    true ,  // CompareAndSwapP
    false,  // CompareAndSwapN
    false,  // Con
    false,  // ConN
    true ,  // ConD
    true ,  // ConF
    true ,  // ConI
    true ,  // ConL
    true ,  // ConP
    true ,  // Conv2B
    true ,  // ConvD2F
    true ,  // ConvD2I
    true ,  // ConvD2L
    true ,  // ConvF2D
    true ,  // ConvF2I
    true ,  // ConvF2L
    true ,  // ConvI2D
    true ,  // ConvI2F
    true ,  // ConvI2L
    true ,  // ConvL2D
    true ,  // ConvL2F
    true ,  // ConvL2I
    true ,  // CosD
    false,  // CountedLoop
    true ,  // CountedLoopEnd
    true ,  // CountLeadingZerosI
    true ,  // CountLeadingZerosL
    true ,  // CountTrailingZerosI
    true ,  // CountTrailingZerosL
    true ,  // CreateEx
    false,  // DecodeN
    true ,  // DivD
    true ,  // DivF
    true ,  // DivI
    true ,  // DivL
    false,  // DivMod
    true ,  // DivModI
    false,  // DivModL
    false,  // EncodeP
    true ,  // ExpD
    true ,  // FastLock
    true ,  // FastUnlock
    true ,  // Goto
    true ,  // Halt
    true ,  // If
    false,  // IfFalse
    false,  // IfTrue
    false,  // Initialize
    false,  // JProj
    true ,  // Jump
    false,  // JumpProj
    true ,  // LShiftI
    true ,  // LShiftL
    true ,  // LoadB
    true ,  // LoadUB
    true ,  // LoadUS
    true ,  // LoadD
    false,  // LoadD_unaligned
    true ,  // LoadF
    true ,  // LoadI
    true ,  // LoadUI2L
    true ,  // LoadKlass
    false,  // LoadNKlass
    true ,  // LoadL
    false,  // LoadL_unaligned
    true ,  // LoadPLocked
    true ,  // LoadLLocked
    true ,  // LoadP
    false,  // LoadN
    true ,  // LoadRange
    true ,  // LoadS
    false,  // Lock
    true ,  // LogD
    true ,  // Log10D
    false,  // Loop
    false,  // Mach
    false,  // MachProj
    true ,  // MaxI
    true ,  // MemBarAcquire
    false,  // MemBarCPUOrder
    true ,  // MemBarRelease
    true ,  // MemBarVolatile
    false,  // MergeMem
    true ,  // MinI
    true ,  // ModD
    true ,  // ModF
    true ,  // ModI
    true ,  // ModL
    true ,  // MoveI2F
    true ,  // MoveF2I
    true ,  // MoveL2D
    true ,  // MoveD2L
    true ,  // MulD
    true ,  // MulF
    false,  // MulHiL
    true ,  // MulI
    true ,  // MulL
    false,  // Multi
    true ,  // NegD
    true ,  // NegF
    false,  // NeverBranch
    false,  // Opaque1
    false,  // Opaque2
    true ,  // OrI
    true ,  // OrL
    false,  // PCTable
    false,  // Parm
    true ,  // PartialSubtypeCheck
    false,  // Phi
    true ,  // PopCountI
    true ,  // PopCountL
    true ,  // PowD
    true ,  // PrefetchRead
    true ,  // PrefetchWrite
    false,  // Proj
    true ,  // RShiftI
    true ,  // RShiftL
    false,  // Region
    true ,  // Rethrow
    true ,  // Return
    false,  // Root
    true ,  // RoundDouble
    true ,  // RoundFloat
    true ,  // SafePoint
    false,  // SafePointScalarObject
    false,  // SCMemProj
    true ,  // SinD
    true ,  // SqrtD
    false,  // Start
    false,  // StartOSR
    true ,  // StoreB
    true ,  // StoreC
    true ,  // StoreCM
    true ,  // StorePConditional
    true ,  // StoreIConditional
    true ,  // StoreLConditional
    true ,  // StoreD
    true ,  // StoreF
    true ,  // StoreI
    true ,  // StoreL
    true ,  // StoreP
    false,  // StoreN
    true ,  // StrComp
    true ,  // StrEquals
    true ,  // StrIndexOf
    true ,  // SubD
    true ,  // SubF
    true ,  // SubI
    true ,  // SubL
    true ,  // TailCall
    true ,  // TailJump
    true ,  // TanD
    true ,  // ThreadLocal
    false,  // Unlock
    true ,  // URShiftI
    true ,  // URShiftL
    true ,  // XorI
    true ,  // XorL
    false,  // Vector
    false,  // AddVB
    false,  // AddVC
    false,  // AddVS
    false,  // AddVI
    false,  // AddVL
    false,  // AddVF
    false,  // AddVD
    false,  // SubVB
    false,  // SubVC
    false,  // SubVS
    false,  // SubVI
    false,  // SubVL
    false,  // SubVF
    false,  // SubVD
    false,  // MulVF
    false,  // MulVD
    false,  // DivVF
    false,  // DivVD
    false,  // LShiftVB
    false,  // LShiftVC
    false,  // LShiftVS
    false,  // LShiftVI
    false,  // URShiftVB
    false,  // URShiftVC
    false,  // URShiftVS
    false,  // URShiftVI
    false,  // AndV
    false,  // OrV
    false,  // XorV
    false,  // VectorLoad
    false,  // Load16B
    true ,  // Load8B
    false,  // Load4B
    false,  // Load8C
    true ,  // Load4C
    false,  // Load2C
    false,  // Load8S
    true ,  // Load4S
    false,  // Load2S
    false,  // Load4I
    true ,  // Load2I
    false,  // Load2L
    false,  // Load4F
    true ,  // Load2F
    false,  // Load2D
    false,  // VectorStore
    false,  // Store16B
    true ,  // Store8B
    false,  // Store4B
    false,  // Store8C
    true ,  // Store4C
    false,  // Store2C
    false,  // Store4I
    true ,  // Store2I
    false,  // Store2L
    false,  // Store4F
    true ,  // Store2F
    false,  // Store2D
    false,  // Pack
    false,  // PackB
    false,  // PackS
    false,  // PackC
    false,  // PackI
    false,  // PackL
    false,  // PackF
    false,  // PackD
    false,  // Pack2x1B
    false,  // Pack2x2B
    false,  // Replicate16B
    true ,  // Replicate8B
    false,  // Replicate4B
    false,  // Replicate8S
    true ,  // Replicate4S
    false,  // Replicate2S
    false,  // Replicate8C
    true ,  // Replicate4C
    false,  // Replicate2C
    false,  // Replicate4I
    true ,  // Replicate2I
    false,  // Replicate2L
    false,  // Replicate4F
    true ,  // Replicate2F
    false,  // Replicate2D
    false,  // Extract
    false,  // ExtractB
    false,  // ExtractS
    false,  // ExtractC
    false,  // ExtractI
    false,  // ExtractL
    false,  // ExtractF
    false   // ExtractD
};


bool Matcher::stack_direction() const { return false; }

int Compile::sync_stack_slots() const { return 1; }

uint Matcher::stack_alignment_in_bytes() { return StackAlignmentInBytes; }

OptoReg::Name Matcher::return_addr() const { return OptoReg::stack2reg(- 1 +
              round_to(1+VerifyStackAtCalls+
              Compile::current()->fixed_slots(),
              (StackAlignmentInBytes/wordSize))); }

uint Compile::in_preserve_stack_slots() { return 2+VerifyStackAtCalls; }

uint Compile::out_preserve_stack_slots() { return SharedRuntime::out_preserve_stack_slots(); }

uint Compile::varargs_C_out_slots_killed() const { return 0; }

void Matcher::calling_convention(BasicType *sig_bt, VMRegPair *regs, uint length, bool is_outgoing) {

#line 4517 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // No difference between ingoing/outgoing just pass false
    SharedRuntime::java_calling_convention(sig_bt, regs, length, false);
  
#line 28714 "../generated/adfiles/ad_x86_32.cpp"

}

void Matcher::c_calling_convention(BasicType *sig_bt, VMRegPair *regs, uint length) {

#line 4529 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    // This is obviously always outgoing
    (void) SharedRuntime::c_calling_convention(sig_bt, regs, length);
  
#line 28725 "../generated/adfiles/ad_x86_32.cpp"

}

OptoRegPair Matcher::return_value(int ideal_reg, bool is_outgoing) {

#line 4551 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    assert( ideal_reg >= Op_RegI && ideal_reg <= Op_RegL, "only return normal values" );
    static int lo[Op_RegL+1] = { 0, 0, OptoReg::Bad, EAX_num,      EAX_num,      FPR1L_num,    FPR1L_num, EAX_num };
    static int hi[Op_RegL+1] = { 0, 0, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, FPR1H_num, EDX_num };
    if( ideal_reg == Op_RegD && UseSSE>=2 )
      return OptoRegPair(XMM0b_num,XMM0a_num);
    if( ideal_reg == Op_RegF && UseSSE>=1 )
      return OptoRegPair(OptoReg::Bad,XMM0a_num);
    return OptoRegPair(hi[ideal_reg],lo[ideal_reg]);
  
#line 28742 "../generated/adfiles/ad_x86_32.cpp"

}

OptoRegPair Matcher::c_return_value(int ideal_reg, bool is_outgoing) {

#line 4535 "/home/bbrown/src/openjdk/openjdk6_test/hotspot/src/cpu/x86/vm/x86_32.ad"

    assert( ideal_reg >= Op_RegI && ideal_reg <= Op_RegL, "only return normal values" );
    static int lo[Op_RegL+1] = { 0, 0, OptoReg::Bad, EAX_num,      EAX_num,      FPR1L_num,    FPR1L_num, EAX_num };
    static int hi[Op_RegL+1] = { 0, 0, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, OptoReg::Bad, FPR1H_num, EDX_num };

    // in SSE2+ mode we want to keep the FPU stack clean so pretend
    // that C functions return float and double results in XMM0.
    if( ideal_reg == Op_RegD && UseSSE>=2 )
      return OptoRegPair(XMM0b_num,XMM0a_num);
    if( ideal_reg == Op_RegF && UseSSE>=2 )
      return OptoRegPair(OptoReg::Bad,XMM0a_num);

    return OptoRegPair(hi[ideal_reg],lo[ideal_reg]);
  
#line 28763 "../generated/adfiles/ad_x86_32.cpp"

}

OptoReg::Name Matcher::inline_cache_reg() { return OptoReg::Name(EAX_num); }

const RegMask &Matcher::inline_cache_reg_mask() { return INLINE_CACHE_REG_mask; }

int Matcher::inline_cache_reg_encode() { return _regEncode[inline_cache_reg()]; }

OptoReg::Name Matcher::interpreter_method_oop_reg() { return OptoReg::Name(EBX_num); }

const RegMask &Matcher::interpreter_method_oop_reg_mask() { return INTERPRETER_METHOD_OOP_REG_mask; }

int Matcher::interpreter_method_oop_reg_encode() { return _regEncode[interpreter_method_oop_reg()]; }

OptoReg::Name Matcher::interpreter_frame_pointer_reg() { return OptoReg::Name(EBP_num); }

const RegMask &Matcher::interpreter_frame_pointer_reg_mask() { return INTERPRETER_FRAME_POINTER_REG_mask; }

OptoReg::Name Matcher::c_frame_pointer() const { return OptoReg::Name(ESP_num); }

// Number of callee-save + always-save registers
int  Matcher::number_of_saved_registers() {
  return 0;
};

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
