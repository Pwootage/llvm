//===-- PwisaRegisterInfo.h - Pwisa Register Information Impl ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Pwisa implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef PWISAREGISTERINFO_H
#define PWISAREGISTERINFO_H

#include "PwisaConfig.h"

#include "Pwisa.h"
#include "llvm/Target/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "PwisaGenRegisterInfo.inc"

namespace llvm {
    class PwisaSubtarget;
    class TargetInstrInfo;
    class Type;

    struct PwisaRegisterInfo : public PwisaGenRegisterInfo {
        const PwisaSubtarget &Subtarget;

        PwisaRegisterInfo(const PwisaSubtarget &Subtarget);

        /// getRegisterNumbering - Given the enum value for some register, e.g.
        /// Pwisa::LR, return the number that it corresponds to (e.g. 14).
        static unsigned getRegisterNumbering(unsigned RegEnum);

        /// Code Generation virtual methods...
        const uint16_t *getCalleeSavedRegs(const MachineFunction* MF = 0) const;
        const uint32_t *getCallPreservedMask(CallingConv::ID) const;

        BitVector getReservedRegs(const MachineFunction &MF) const;

        /// Stack Frame Processing Methods
        void eliminateFrameIndex(MachineBasicBlock::iterator II,
                int SPAdj, unsigned FIOperandNum,
                RegScavenger *RS = nullptr) const override;

        /// Debug information queries.
        unsigned getFrameRegister(const MachineFunction &MF) const;

        /// Return GPR register class.
        const TargetRegisterClass *intRegClass(unsigned Size) const;
    };

} // end namespace llvm


#endif

