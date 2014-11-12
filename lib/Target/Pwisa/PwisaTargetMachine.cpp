//===-- PwisaTargetMachine.cpp - Define TargetMachine for Pwisa -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about Pwisa target spec.
//
//===----------------------------------------------------------------------===//

#include "PwisaTargetMachine.h"
#include "Pwisa.h"
//#include "PwisaSubtarget.h"
#include "llvm/PassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

#define DEBUG_TYPE "pwisa"

extern "C" void LLVMInitializePwisaTarget() {
    // Register the target.
    //- Big endian Target Machine
    RegisterTargetMachine<PwisaTargetMachine> X(ThePwisaTarget);
    //- Little endian Target Machine
}

// 32-bit pointer/ABI/alignment
// The stack is always 8 byte aligned
// On function prologue, the stack is created by decrementing
// its pointer. Once decremented, all references are done with positive
// offset from the stack/frame pointer, using StackGrowsUp enables
// an easier handling.
// Using CodeModel::Large enables different CALL behavior.
PwisaTargetMachine::
PwisaTargetMachine(const Target &T, StringRef TT,
        StringRef CPU, StringRef FS, const TargetOptions &Options,
        Reloc::Model RM, CodeModel::Model CM,
        CodeGenOpt::Level OL)
        : LLVMTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL),
          Subtarget(nullptr), DefaultSubtarget(TT, CPU, FS, RM, this) {
    Subtarget = &DefaultSubtarget;
    initAsmInfo();
}

//void PwisaTargetMachine::anchor() { }

//PwisaTargetMachine::
//PwisaTargetMachine(const Target &T, StringRef TT,
//        StringRef CPU, StringRef FS, const TargetOptions &Options,
//        Reloc::Model RM, CodeModel::Model CM,
//        CodeGenOpt::Level OL)
//        : PwisaTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL) {}

namespace {
/// Pwisa Code Generator Pass Configuration Options.
    class PwisaPassConfig : public TargetPassConfig {
    public:
        PwisaPassConfig(PwisaTargetMachine *TM, PassManagerBase &PM)
                : TargetPassConfig(TM, PM) {}

        PwisaTargetMachine &getPwisaTargetMachine() const {
            return getTM<PwisaTargetMachine>();
        }

        const PwisaSubtarget &getPwisaSubtarget() const {
            return *getPwisaTargetMachine().getSubtargetImpl();
        }
    };
} // namespace

TargetPassConfig *PwisaTargetMachine::createPassConfig(PassManagerBase &PM) {
    return new PwisaPassConfig(this, PM);
}


