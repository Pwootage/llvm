//===-- PwisaMachineFunctionInfo.h - Private data used for Pwisa --*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Pwisa specific subclass of MachineFunctionInfo.
//
//===----------------------------------------------------------------------===//

#ifndef PWISA_MACHINE_FUNCTION_INFO_H
#define PWISA_MACHINE_FUNCTION_INFO_H

#include "PwisaConfig.h"

#include "llvm/ADT/StringMap.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/CodeGen/PseudoSourceValue.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/ValueMap.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"
#include <map>
#include <string>
#include <utility>

namespace llvm {

/// \brief A class derived from PseudoSourceValue that represents a GOT entry
/// resolved by lazy-binding.
    class PwisaCallEntry : public PseudoSourceValue {
    public:
        explicit PwisaCallEntry(const StringRef &N);
        explicit PwisaCallEntry(const GlobalValue *V);
        bool isConstant(const MachineFrameInfo *) const override;
        bool isAliased(const MachineFrameInfo *) const override;
        bool mayAlias(const MachineFrameInfo *) const override;

    private:
        void printCustom(raw_ostream &O) const override;
#ifndef NDEBUG
        std::string Name;
        const GlobalValue *Val;
#endif
    };

/// PwisaFunctionInfo - This class is derived from MachineFunction private
/// Pwisa target-specific information for each MachineFunction.
    class PwisaFunctionInfo : public MachineFunctionInfo {
    public:
        PwisaFunctionInfo(MachineFunction& MF)
                : MF(MF),
                  VarArgsFrameIndex(0),
                  MaxCallFrameSize(0)
        {}

        ~PwisaFunctionInfo();

        int getVarArgsFrameIndex() const { return VarArgsFrameIndex; }
        void setVarArgsFrameIndex(int Index) { VarArgsFrameIndex = Index; }

    private:
        virtual void anchor();

        MachineFunction& MF;

        /// VarArgsFrameIndex - FrameIndex for start of varargs area.
        int VarArgsFrameIndex;

        unsigned MaxCallFrameSize;

        /// PwisaCallEntry maps.
        StringMap<const PwisaCallEntry *> ExternalCallEntries;
        ValueMap<const GlobalValue *, const PwisaCallEntry *> GlobalCallEntries;
    };

} // end of namespace llvm


#endif // PWISA_MACHINE_FUNCTION_INFO_H


