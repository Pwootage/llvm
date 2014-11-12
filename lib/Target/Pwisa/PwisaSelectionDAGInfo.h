//===-- PwisaSelectionDAGInfo.h - Pwisa SelectionDAG Info -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the Pwisa subclass for TargetSelectionDAGInfo.
//
//===----------------------------------------------------------------------===//

#ifndef PWISASELECTIONDAGINFO_H
#define PWISASELECTIONDAGINFO_H

#include "PwisaConfig.h"

#include "llvm/Target/TargetSelectionDAGInfo.h"

namespace llvm {

    class PwisaTargetMachine;

    class PwisaSelectionDAGInfo : public TargetSelectionDAGInfo {
    public:
        explicit PwisaSelectionDAGInfo(const DataLayout &DL);
        ~PwisaSelectionDAGInfo();
    };

}


#endif

