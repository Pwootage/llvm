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
}


