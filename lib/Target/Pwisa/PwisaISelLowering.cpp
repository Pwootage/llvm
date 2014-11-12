//===-- PwisaISelLowering.cpp - Pwisa DAG Lowering Implementation ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that Pwisa uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//
#include "PwisaISelLowering.h"

#include "PwisaMachineFunction.h"
#include "PwisaTargetMachine.h"
#include "PwisaTargetObjectFile.h"
#include "PwisaSubtarget.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "pwisa-lower"




#if 0
SDValue PwisaTargetLowering::getTargetNode(ConstantPoolSDNode *N, EVT Ty,
                                          SelectionDAG &DAG,
                                          unsigned Flag) const {
  return DAG.getTargetConstantPool(N->getConstVal(), Ty, N->getAlignment(),
                                   N->getOffset(), Flag);
}
#endif

const char *PwisaTargetLowering::getTargetNodeName(unsigned Opcode) const {
    switch (Opcode) {
        case PwisaISD::JmpLink:           return "PwisaISD::JmpLink";
        case PwisaISD::TailCall:          return "PwisaISD::TailCall";
        case PwisaISD::Hi:                return "PwisaISD::Hi";
        case PwisaISD::Lo:                return "PwisaISD::Lo";
        case PwisaISD::GPRel:             return "PwisaISD::GPRel";
        case PwisaISD::Ret:               return "PwisaISD::Ret";
        case PwisaISD::DivRem:            return "PwisaISD::DivRem";
        case PwisaISD::DivRemU:           return "PwisaISD::DivRemU";
        case PwisaISD::Wrapper:           return "PwisaISD::Wrapper";
        default:                         return NULL;
    }
}

const PwisaTargetLowering *
llvm::createPwisaTargetLowering(PwisaTargetMachine &TM,
        const PwisaSubtarget &STI) {
    return new PwisaTargetLowering(TM, STI);
}

PwisaTargetLowering::PwisaTargetLowering(PwisaTargetMachine &TM,
        const PwisaSubtarget &STI)
        : TargetLowering(TM, new PwisaTargetObjectFile()), Subtarget(STI) {

}

const PwisaTargetLowering *PwisaTargetLowering::create(PwisaTargetMachine &TM,
        const PwisaSubtarget &STI) {
    return llvm::createPwisaTargetLowering(TM, STI);
}



//===----------------------------------------------------------------------===//
//  Lower helper functions
//===----------------------------------------------------------------------===//


//===----------------------------------------------------------------------===//
//  Misc Lower Operation implementation
//===----------------------------------------------------------------------===//

#include "PwisaGenCallingConv.inc"

//===----------------------------------------------------------------------===//
//             Formal Arguments Calling Convention Implementation
//===----------------------------------------------------------------------===//

/// LowerFormalArguments - transform physical registers into virtual registers
/// and generate load operations for arguments places on the stack.
SDValue
PwisaTargetLowering::LowerFormalArguments(SDValue Chain,
        CallingConv::ID CallConv,
        bool IsVarArg,
        const SmallVectorImpl<ISD::InputArg> &Ins,
        SDLoc DL, SelectionDAG &DAG,
        SmallVectorImpl<SDValue> &InVals)
const {

    return Chain;
}

//===----------------------------------------------------------------------===//
//               Return Value Calling Convention Implementation
//===----------------------------------------------------------------------===//


SDValue
PwisaTargetLowering::LowerReturn(SDValue Chain,
        CallingConv::ID CallConv, bool IsVarArg,
        const SmallVectorImpl<ISD::OutputArg> &Outs,
        const SmallVectorImpl<SDValue> &OutVals,
        SDLoc DL, SelectionDAG &DAG) const {
    return DAG.getNode(PwisaISD::Ret, DL, MVT::Other,
            Chain, DAG.getRegister(Pwisa::LR, MVT::i32));
}


















