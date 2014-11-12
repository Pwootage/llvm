//===-- PwisaISelLowering.h - Pwisa DAG Lowering Interface ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that Pwisa uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#ifndef PWISAISELLOWERING_H
#define PWISAISELLOWERING_H

#include "PwisaConfig.h"

#include "Pwisa.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/IR/Function.h"
#include "llvm/Target/TargetLowering.h"
#include <deque>

namespace llvm {
    namespace PwisaISD {
        enum NodeType {
            // Start the numbering from where ISD NodeType finishes.
                    FIRST_NUMBER = ISD::BUILTIN_OP_END,

            // Jump and link (call)
                    JmpLink,

            // Tail call
                    TailCall,

            // Get the Higher 16 bits from a 32-bit immediate
                    Hi,
            // Get the Lower 16 bits from a 32-bit immediate
                    Lo,

            // Handle gp_rel (small data/bss sections) relocation.
                    GPRel,

            // Thread Pointer
                    ThreadPointer,

            // Return
                    Ret,

            // DivRem(u)
                    DivRem,
            DivRemU,

            Wrapper,
            DynAlloc,

            Sync
        };
    }

    //===--------------------------------------------------------------------===//
    // TargetLowering Implementation
    //===--------------------------------------------------------------------===//
    class PwisaFunctionInfo;
    class PwisaSubtarget;

    class PwisaTargetLowering : public TargetLowering  {
    public:
        explicit PwisaTargetLowering(PwisaTargetMachine &TM,
                const PwisaSubtarget &STI);

        static const PwisaTargetLowering *create(PwisaTargetMachine &TM,
                const PwisaSubtarget &STI);


        /// getTargetNodeName - This method returns the name of a target specific
        //  DAG node.
        const char *getTargetNodeName(unsigned Opcode) const override;


    protected:


        /// ByValArgInfo - Byval argument information.
        struct ByValArgInfo {
            unsigned FirstIdx; // Index of the first register used.
            unsigned NumRegs;  // Number of registers used for this argument.
            unsigned Address;  // Offset of the stack area used to pass this argument.

            ByValArgInfo() : FirstIdx(0), NumRegs(0), Address(0) {}
        };


    protected:
        // Subtarget Info
        const PwisaSubtarget &Subtarget;

    private:


#if 0
    // Create a TargetConstantPool node.
    SDValue getTargetNode(ConstantPoolSDNode *N, EVT Ty, SelectionDAG &DAG,
                          unsigned Flag) const;
#endif



        // Lower Operand specifics
        SDValue lowerGlobalAddress(SDValue Op, SelectionDAG &DAG) const;
        SDValue lowerJumpTable(SDValue Op, SelectionDAG &DAG) const;






        //- must be exist even without function all
        SDValue
                LowerFormalArguments(SDValue Chain,
                CallingConv::ID CallConv, bool IsVarArg,
                const SmallVectorImpl<ISD::InputArg> &Ins,
                SDLoc dl, SelectionDAG &DAG,
                SmallVectorImpl<SDValue> &InVals) const override;




        SDValue LowerReturn(SDValue Chain,
                CallingConv::ID CallConv, bool IsVarArg,
                const SmallVectorImpl<ISD::OutputArg> &Outs,
                const SmallVectorImpl<SDValue> &OutVals,
                SDLoc dl, SelectionDAG &DAG) const override;


    };
    const PwisaTargetLowering *
            createPwisaTargetLowering(PwisaTargetMachine &TM, const PwisaSubtarget &STI);
}


#endif // PWISAISELLOWERING_H

