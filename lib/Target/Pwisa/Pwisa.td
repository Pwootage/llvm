//===-- Pwisa.td - Describe the Mips Target Machine --------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the Pwisa target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Target-specific stuff
//===----------------------------------------------------------------------===//

include "PwisaRegisterInfo.td"
include "PwisaSchedule.td"
include "PwisaInstrInfo.td"

def PwisaInstrInfo : InstrInfo;

def Pwisa : Target {
  let InstructionSet = PwisaInstrInfo;
}
