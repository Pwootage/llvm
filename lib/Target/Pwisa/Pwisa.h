//===-- Piwsa.h - Top-level interface for Pwisa representation --*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM Pwisa back-end.
//
//===----------------------------------------------------------------------===//

#ifndef TARGET_PWISA_H
#define TARGET_PWISA_H

#include "PwisaConfig.h"
#include "MCTargetDesc/PwisaMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class PwisaTargetMachine;
    class FunctionPass;

    FunctionPass *createPwisaISelDag(PwisaTargetMachine &TM);

}

#endif

