//===-- PwisaInstrInfo.cpp - Pwisa Instruction Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Pwisa implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "PwisaInstrInfo.h"

#include "PwisaTargetMachine.h"
#include "PwisaMachineFunction.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "PwisaGenInstrInfo.inc"
#include "PwisaInstrInfo.h"
#include "PwisaRegisterInfo.h"

// Pin the vtable to this file.
void PwisaInstrInfo::anchor() {}

PwisaInstrInfo::PwisaInstrInfo(const PwisaSubtarget &STI)
        :  Subtarget(STI), RI(STI) {}

const PwisaRegisterInfo &PwisaInstrInfo::getRegisterInfo() const {
    return RI;
}

const PwisaInstrInfo *llvm::createPwisaInstrInfo(const PwisaSubtarget &STI) {
    return new PwisaInstrInfo(STI);
}

const PwisaInstrInfo *PwisaInstrInfo::create(PwisaSubtarget &STI) {
    return llvm::createPwisaInstrInfo(STI);
}




