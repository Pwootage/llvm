# RUN: llvm-mc %s -arch=mips -mcpu=mips32r2 | FileCheck %s -check-prefix=ASM
#
# RUN: llvm-mc %s -arch=mips -mcpu=mips32r2 -mattr=+o32 -filetype=obj -o -| \
# RUN:  llvm-objdump -d -r -arch=mips - | \
# RUN:    FileCheck %s -check-prefix=OBJ-O32

# RUN: llvm-mc %s -arch=mips64 -mcpu=mips64r2 -mattr=-n64,+n32 -filetype=obj -o -| \
# RUN:  llvm-objdump -d -r -arch=mips - | \
# RUN:    FileCheck %s -check-prefix=OBJ-N32

# RUN: llvm-mc %s -arch=mips64 -mcpu=mips64r2 -mattr=+n64 -filetype=obj -o -| \
# RUN:  llvm-objdump -d -r -arch=mips - | \
# RUN:    FileCheck %s -check-prefix=OBJ-N64

# ASM:    .text
# ASM:    .option pic2
# ASM:    .set noreorder
# ASM:    .cpload $25
# ASM:    .set reorder

# OBJ-O32:    .text
# OBJ-O32:    lui $gp, 0
# OBJ-O32: R_MIPS_HI16 _gp_disp
# OBJ-O32:    addiu $gp, $gp, 0
# OBJ-O32: R_MIPS_LO16 _gp_disp
# OBJ-O32:    addu $gp, $gp, $25

# OBJ-N32:     .text
# OBJ-N32-NOT: lui   $gp, 0
# OBJ-N32-NOT: addiu $gp, $gp, 0
# OBJ-N32-NOT: addu  $gp, $gp, $25

# OBJ-N64:     .text
# OBJ-N64-NOT: lui   $gp, 0
# OBJ-N64-NOT: addiu $gp, $gp, 0
# OBJ-N64-NOT: addu  $gp, $gp, $25

        .text
        .option pic2
        .set noreorder
        .cpload $25
        .set reorder
