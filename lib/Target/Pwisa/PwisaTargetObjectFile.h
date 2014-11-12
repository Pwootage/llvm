//===-- llvm/Target/PwisaTargetObjectFile.h - Pwisa Object Info -*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_PWISA_TARGETOBJECTFILE_H
#define LLVM_TARGET_PWISA_TARGETOBJECTFILE_H

#include "PwisaConfig.h"

#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

namespace llvm {

    class PwisaTargetObjectFile : public TargetLoweringObjectFileELF {
        const MCSection *SmallDataSection;
        const MCSection *SmallBSSSection;
    public:

        void Initialize(MCContext &Ctx, const TargetMachine &TM) override;

    };
}; // end namespace llvm


#endif

