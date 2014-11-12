
set(LLVM_TARGET_DEFINITIONS Pwisa.td)

# Generate PwisaGenRegisterInfo.inc and PwisaGenInstrInfo.inc which included by
#  your hand code C++ files. 
# PwisaGenRegisterInfo.inc came from PwisaRegisterInfo.td, PwisaGenInstrInfo.inc
#  came from PwisaInstrInfo.td.
tablegen(LLVM PwisaGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM PwisaGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM PwisaGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM PwisaGenCallingConv.inc -gen-callingconv)
tablegen(LLVM PwisaGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM PwisaGenMCPseudoLowering.inc -gen-pseudo-lowering)

# PwisaCommonTableGen must be defined
add_public_tablegen_target(PwisaCommonTableGen)

# PwisaCodeGen should match with LLVMBuild.txt PwisaCodeGen
add_llvm_target(PwisaCodeGen
  PwisaInstrInfo.cpp
  PwisaISelLowering.cpp
  PwisaFrameLowering.cpp
  PwisaMachineFunction.cpp
  PwisaRegisterInfo.cpp
  PwisaSubtarget.cpp
  PwisaTargetMachine.cpp
  PwisaTargetObjectFile.cpp
  PwisaSelectionDAGInfo.cpp
  )

# Should match with "subdirectories =  MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)

