//===-- PwisaSelectionDAGInfo.cpp - Pwisa SelectionDAG Info ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the PwisaSelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#include "PwisaSelectionDAGInfo.h"

#include "PwisaTargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "pwisa-selectiondag-info"

PwisaSelectionDAGInfo::PwisaSelectionDAGInfo(const DataLayout &DL)
        : TargetSelectionDAGInfo(&DL) {}

PwisaSelectionDAGInfo::~PwisaSelectionDAGInfo() {
}


