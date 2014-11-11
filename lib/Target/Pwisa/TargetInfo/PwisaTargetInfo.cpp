//===-- PwisaTargetInfo.cpp - Pwisa Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Pwisa.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::ThePwisaTarget;

extern "C" void LLVMInitializePwisaTargetInfo() {
    RegisterTarget<Triple::pwisa,
    /*HasJIT=*/true> X(ThePwisaTarget, "pwisa", "Pwisa");
}

