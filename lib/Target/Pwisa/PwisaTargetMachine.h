//===-- PwisaTargetMachine.h - Define TargetMachine for Pwisa ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Pwisa specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef PWISATARGETMACHINE_H
#define PWISATARGETMACHINE_H

#include "PwisaConfig.h"

#include "PwisaSubtarget.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class formatted_raw_ostream;

    class PwisaTargetMachine : public LLVMTargetMachine {
        PwisaSubtarget *Subtarget;
        PwisaSubtarget DefaultSubtarget;

    public:
        PwisaTargetMachine(const Target &T, StringRef TT, StringRef CPU,
                StringRef FS, const TargetOptions &Options,
                Reloc::Model RM, CodeModel::Model CM,
                CodeGenOpt::Level OL);

        const TargetFrameLowering *getFrameLowering() const {
            return getSubtargetImpl()->getFrameLowering();
        }
        const PwisaSubtarget *getSubtargetImpl() const override {
            if (Subtarget)
                return Subtarget;
            return &DefaultSubtarget;
        }
        const InstrItineraryData* getInstrItineraryData() const {
            return getSubtargetImpl()->getInstrItineraryData();
        }
        const PwisaRegisterInfo *getRegisterInfo()  const {
            return getSubtargetImpl()->getRegisterInfo();
        }
        const PwisaTargetLowering *getTargetLowering() const {
            return getSubtargetImpl()->getTargetLowering();
        }
        const DataLayout *getDataLayout() const {
            return getSubtargetImpl()->getDataLayout();
        }
        const PwisaSelectionDAGInfo* getSelectionDAGInfo() const {
            return getSubtargetImpl()->getSelectionDAGInfo();
        }
        /// Reset the subtarget for the Pwisa target.
        void resetSubtarget(MachineFunction *MF);

        // Pass Pipeline Configuration
        virtual TargetPassConfig *createPassConfig(PassManagerBase &PM);
    };
} // End llvm namespace

#endif

