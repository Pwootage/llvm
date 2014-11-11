//===-- PwisaMCTargetDesc.h - Pwisa Target Descriptions ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Pwisa specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef PWISAMCTARGETDESC_H
#define PWISAMCTARGETDESC_H

#include "PwisaConfig.h"
#include "llvm/Support/DataTypes.h"

namespace llvm {
class Target;

extern Target ThePwisaTarget;

} // End llvm namespace

// Defines symbolic names for Pwisa registers.  This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "PwisaGenRegisterInfo.inc"

// Defines symbolic names for the Pwisa instructions.
#define GET_INSTRINFO_ENUM
#include "PwisaGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "PwisaGenSubtargetInfo.inc"

#endif

