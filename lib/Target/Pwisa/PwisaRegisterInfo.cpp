//===-- PwisaRegisterInfo.cpp - Pwisa Register Information -== ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Pwisa implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "pwisa-reg-info"

#include "PwisaRegisterInfo.h"

#include "Pwisa.h"
#include "PwisaSubtarget.h"
#include "PwisaMachineFunction.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

#define GET_REGINFO_TARGET_DESC
#include "PwisaGenRegisterInfo.inc"

using namespace llvm;

PwisaRegisterInfo::PwisaRegisterInfo(const PwisaSubtarget &ST)
        : PwisaGenRegisterInfo(Pwisa::LR), Subtarget(ST) {}

//===----------------------------------------------------------------------===//
// Callee Saved Registers methods
//===----------------------------------------------------------------------===//
/// Pwisa Callee Saved Registers
// In PwisaCallConv.td,
// llc create CSR_O32_SaveList and CSR_O32_RegMask from above defined.
const uint16_t* PwisaRegisterInfo::
getCalleeSavedRegs(const MachineFunction *MF) const
{
    return CSR_P32_SaveList;
}

const uint32_t*
PwisaRegisterInfo::getCallPreservedMask(CallingConv::ID) const
{
    return CSR_P32_RegMask;
}

// pure virtual method
BitVector PwisaRegisterInfo::
getReservedRegs(const MachineFunction &MF) const {
    static const uint16_t ReservedCPURegs[] = {
            Pwisa::PZ, Pwisa::SP, Pwisa::LR, Pwisa::PC
    };
    BitVector Reserved(getNumRegs());
    typedef TargetRegisterClass::iterator RegIter;

    for (unsigned I = 0; I < array_lengthof(ReservedCPURegs); ++I)
        Reserved.set(ReservedCPURegs[I]);



    return Reserved;
}

//eliminateFrameIndex {
//- If no eliminateFrameIndex(), it will hang on run.
// pure virtual method
// FrameIndex represent objects inside a abstract stack.
// We must replace FrameIndex with an stack/frame pointer
// direct reference.
void PwisaRegisterInfo::
eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
        unsigned FIOperandNum, RegScavenger *RS) const {
}
//}

// pure virtual method
unsigned PwisaRegisterInfo::
getFrameRegister(const MachineFunction &MF) const {
    return Pwisa::FP;
}

const TargetRegisterClass * PwisaRegisterInfo::intRegClass(unsigned Size) const {
    return &Pwisa::CPURegsRegClass;
}


