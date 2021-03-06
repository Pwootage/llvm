//===-- PwisaSubtarget.h - Define Subtarget for the Pwisa -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Pwisa specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef PWISASUBTARGET_H
#define PWISASUBTARGET_H

#include "PwisaConfig.h"

#include "PwisaFrameLowering.h"
#include "PwisaISelLowering.h"
#include "PwisaInstrInfo.h"
#include "PwisaSelectionDAGInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/MC/MCInstrItineraries.h"
#include "llvm/Target/TargetSubtargetInfo.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "PwisaGenSubtargetInfo.inc"


//namespace
namespace llvm {
    class StringRef;

    class PwisaTargetMachine;

    class PwisaSubtarget : public PwisaGenSubtargetInfo {
        void anchor();

    public:

        enum PwisaABIEnum {
            UnknownABI, P32
        };

    protected:
        enum PwisaArchEnum {
            Pwisa32I
        };

        // Pwisa architecture version
        PwisaArchEnum PwisaArchVersion;

        // Pwisa supported ABIs
        PwisaABIEnum PwisaABI;

        InstrItineraryData InstrItins;

        // Relocation Model
        Reloc::Model RM;


        PwisaTargetMachine *TM;

        Triple TargetTriple;

        const DataLayout DL; // Calculates type size & alignment
        const PwisaSelectionDAGInfo TSInfo;
        std::unique_ptr<const PwisaInstrInfo> InstrInfo;
        std::unique_ptr<const PwisaFrameLowering> FrameLowering;
        std::unique_ptr<const PwisaTargetLowering> TLInfo;

    public:
        bool isABI_P32() const { return PwisaABI == P32; }

        unsigned getTargetABI() const { return PwisaABI; }

        /// This constructor initializes the data members to match that
        /// of the specified triple.
        PwisaSubtarget(const std::string &TT, const std::string &CPU,
                const std::string &FS, Reloc::Model _RM,
                PwisaTargetMachine *_TM);

        //- Vitual function, must have
        /// ParseSubtargetFeatures - Parses features string setting specified
        /// subtarget options.  Definition of function is auto generated by tblgen.
        void ParseSubtargetFeatures(StringRef CPU, StringRef FS);

        bool isLittle() const { return true; }

        bool abiUsesSoftFloat() const { return false; };

        const InstrItineraryData* getInstrItineraryData() const { return &InstrItins; }

        unsigned stackAlignment() const { return 8; }

        PwisaSubtarget &initializeSubtargetDependencies(StringRef CPU, StringRef FS,
                const TargetMachine *TM);

        const PwisaSelectionDAGInfo *getSelectionDAGInfo() const { return &TSInfo; }
        const DataLayout *getDataLayout() const { return &DL; }
        const PwisaInstrInfo *getInstrInfo() const { return InstrInfo.get(); }
        const TargetFrameLowering *getFrameLowering() const {
            return FrameLowering.get();
        }
        const PwisaRegisterInfo *getRegisterInfo() const {
            return &InstrInfo->getRegisterInfo();
        }
        const PwisaTargetLowering *getTargetLowering() const { return TLInfo.get(); }
    };
} // End llvm namespace


#endif

