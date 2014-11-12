//===-- PwisaInstrInfo.h - Pwisa Instruction Information --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Pwisa implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef PWISAINSTRUCTIONINFO_H
#define PWISAINSTRUCTIONINFO_H

#include "PwisaConfig.h"

#include "Pwisa.h"
#include "PwisaRegisterInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Target/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "PwisaGenInstrInfo.inc"

namespace llvm {

    class PwisaInstrInfo : public PwisaGenInstrInfo {
        void anchor();
        const PwisaRegisterInfo RI;
    protected:
        const PwisaSubtarget &Subtarget;
    public:
        explicit PwisaInstrInfo(const PwisaSubtarget &STI);

        static const PwisaInstrInfo *create(PwisaSubtarget &STI);

        /// getRegisterInfo - TargetInstrInfo is a superset of MRegister info.  As
        /// such, whenever a client has an instance of instruction info, it should
        /// always be able to get register info as well (through this method).
        ///
        const PwisaRegisterInfo &getRegisterInfo() const;


    };
    const PwisaInstrInfo* createPwisaInstrInfo(const PwisaSubtarget &STI);
}


#endif

