//===-- PwisaSubtarget.cpp - Pwisa Subtarget Information ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Pwisa specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "PwisaMachineFunction.h"
#include "Pwisa.h"
#include "PwisaRegisterInfo.h"
#include "PwisaSubtarget.h"

#include "PwisaTargetMachine.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "pwisa-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "PwisaGenSubtargetInfo.inc"

extern bool FixGlobalBaseReg;

/// Select the Pwisa CPU for the given triple and cpu name.
static StringRef selectPwisaCPU(Triple TT, StringRef CPU) {
    if (CPU.empty() || CPU == "generic") {
        if (TT.getArch() == Triple::pwisa)
            CPU = "Pwisa32I";
    }
    return CPU;
}

void PwisaSubtarget::anchor() { }

static std::string computeDataLayout(const PwisaSubtarget &ST) {
    std::string Ret = "";

    //Little endian
    Ret += "e";

    Ret += "-m:m";

    Ret += "-p:32:32";

    // 8 and 16 bit integers only need no have natural alignment, but try to
    // align them to 32 bits. 64 bit integers have natural alignment.
    Ret += "-i8:8:32-i16:16:32-i64:64";

    // 32 bit registers are always available and the stack is at least 64 bit
    // aligned.
    Ret += "-n32-S64";

    return Ret;
}

PwisaSubtarget::PwisaSubtarget(const std::string &TT, const std::string &CPU,
        const std::string &FS,
        Reloc::Model _RM,
        PwisaTargetMachine *_TM) :
        PwisaGenSubtargetInfo(TT, CPU, FS),
        PwisaABI(UnknownABI), RM(_RM), TM(_TM), TargetTriple(TT),
        DL(computeDataLayout(initializeSubtargetDependencies(CPU, FS, TM))),
        TSInfo(DL), InstrInfo(PwisaInstrInfo::create(*this)),
        FrameLowering(PwisaFrameLowering::create(*this)),
        TLInfo(PwisaTargetLowering::create(*TM, *this)) {

    // Assert exactly one ABI was chosen.
    assert(PwisaABI != UnknownABI);
    assert(((getFeatureBits() & Pwisa::FeatureP32) != 0) == 1);

}

PwisaSubtarget &
PwisaSubtarget::initializeSubtargetDependencies(StringRef CPU, StringRef FS,
        const TargetMachine *TM) {
    std::string CPUName = selectPwisaCPU(TargetTriple, CPU);

    if (CPUName == "help")
        CPUName = "Pwisa32I";

    PwisaArchVersion = Pwisa32I;

    PwisaABI = P32;

    // Parse features string.
    ParseSubtargetFeatures(CPUName, FS);
    // Initialize scheduling itinerary for the specified CPU.
    InstrItins = getInstrItineraryForCPU(CPUName);

    return *this;
}

