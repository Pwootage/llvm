set(LLVM_TARGET_DEFINITIONS Pwisa.td)

# Generate PwisaGenRegisterInfo.inc and PwisaGenInstrInfo.inc which included by
#  your hand code C++ files.
# PwisaGenRegisterInfo.inc came from PwisaRegisterInfo.td, PwisaGenInstrInfo.inc
#  came from PwisaInstrInfo.td.
tablegen(LLVM PwisaGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM PwisaGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM PwisaGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM PiwsaGenMCPseudoLowering.inc -gen-pseudo-lowering)

# PwisaCommonTableGen must be defined
add_public_tablegen_target(PiwsaCommonTableGen)

# PwisaCodeGen should match with LLVMBuild.txt PwisaCodeGen
add_llvm_target(PwisaCodeGen
  PwisaTargetMachine.cpp
  )

# Should match with "subdirectories =  MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)

