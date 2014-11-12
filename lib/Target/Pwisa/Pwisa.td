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
include "PwisaCallingConv.td"

def PwisaInstrInfo : InstrInfo;

def Pwisa : Target {
  let InstructionSet = PwisaInstrInfo;
}

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, Cpu0GenericItineraries, Features>;

def FeaturePwisa32I     : SubtargetFeature<"pwisa32I", "PwisaArchVersion",
                                "Pwisa32I", "Pwisa32I ISA Support">;
def FeatureP32          : SubtargetFeature<"p32", "PwisaABI", "P32",
                                "Enable p32 ABI">;

def : Proc<"Pwisa32I",  [FeaturePwisa32I, FeatureP32]>;
