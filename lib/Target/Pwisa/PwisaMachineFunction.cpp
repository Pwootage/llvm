//===-- PwisaMachineFunctionInfo.cpp - Private data used for Pwisa --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "PwisaMachineFunction.h"

#include "PwisaInstrInfo.h"
#include "PwisaSubtarget.h"
#include "llvm/IR/Function.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

bool FixGlobalBaseReg;

// class PwisaCallEntry.
PwisaCallEntry::PwisaCallEntry(const StringRef &N) {
#ifndef NDEBUG
    Name = N;
    Val = nullptr;
#endif
}

PwisaCallEntry::PwisaCallEntry(const GlobalValue *V) {
#ifndef NDEBUG
    Val = V;
#endif
}

bool PwisaCallEntry::isConstant(const MachineFrameInfo *) const {
    return false;
}

bool PwisaCallEntry::isAliased(const MachineFrameInfo *) const {
    return false;
}

bool PwisaCallEntry::mayAlias(const MachineFrameInfo *) const {
    return false;
}

void PwisaCallEntry::printCustom(raw_ostream &O) const {
    O << "PwisaCallEntry: ";
#ifndef NDEBUG
    if (Val)
        O << Val->getName();
    else
        O << Name;
#endif
}

PwisaFunctionInfo::~PwisaFunctionInfo() {
    for (StringMap<const PwisaCallEntry *>::iterator
                 I = ExternalCallEntries.begin(), E = ExternalCallEntries.end(); I != E;
         ++I)
        delete I->getValue();

    for (const auto &Entry : GlobalCallEntries)
        delete Entry.second;
}



void PwisaFunctionInfo::anchor() { }


