//===-- PwisaFrameLowering.h - Define frame lowering for Pwisa --*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//
//===----------------------------------------------------------------------===//
#ifndef PWISA_FRAMEINFO_H
#define PWISA_FRAMEINFO_H

#include "PwisaConfig.h"

#include "Pwisa.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
    class PwisaSubtarget;

    class PwisaFrameLowering : public TargetFrameLowering {
    protected:
        const PwisaSubtarget &STI;

    public:
        explicit PwisaFrameLowering(const PwisaSubtarget &sti)
               // : TargetFrameLowering(StackGrowsDown, sti.stackAlignment(), 0, sti.stackAlignment()),
                //TODO: "error: member access into incomplete type 'const llvm::PwisaSubtarget'"
                : TargetFrameLowering(StackGrowsDown, 8, 0, 8),

                  STI(sti) {
        }

        static const PwisaFrameLowering *create(const PwisaSubtarget &ST);

        bool hasFP(const MachineFunction &MF) const override;

        void emitPrologue(MachineFunction &MF) const override;

        void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
    };

/// Create PwisaFrameLowering objects.
    const PwisaFrameLowering *createPwisaFrameLowering(const PwisaSubtarget &ST);

} // End llvm namespace


#endif


