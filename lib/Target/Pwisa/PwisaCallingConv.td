//===- PwisaCallingConv.td - Calling Conventions for Pwisa -*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for Pwisa architecture.
//===----------------------------------------------------------------------===//

/// CCIfSubtarget - Match if the current subtarget has a feature F.
//class CCIfSubtarget<string F, CCAction A>:
//  CCIf<!strconcat("State.getTarget().getSubtarget<PwisaSubtarget>().", F), A>;


//===----------------------------------------------------------------------===//
// Pwisa ABI Calling Convention
//===----------------------------------------------------------------------===//

def CC_PwisaABI : CallingConv<[
  // Promote i8/i16 arguments to i32.
  CCIfType<[i8, i16], CCPromoteToType<i32>>,

  // Integer and float arguments are passed in param registers.
  CCIfType<[i32, f32], CCAssignToReg<[P0, P1, P2, P3, P4, P5, P6, P7]>>,

  // Integer and float values get stored in stack slots that are 4 bytes in
  // size and 4-byte aligned.
  CCIfType<[i32, f32], CCAssignToStack<4, 4>>
]>;


//===----------------------------------------------------------------------===//
// Pwisa Calling Convention Dispatch
//===----------------------------------------------------------------------===//

def CC_Pwisa : CallingConv<[
  CCDelegateTo<CC_PwisaABI>
]>;



def CSR_P32 : CalleeSavedRegs<(add LR, FP, R20, R21, R22, R23, R24, R25, R26, R27)>;


