; RUN: llc -march=r600 -mcpu=bonaire < %s | FileCheck -check-prefix=CI -check-prefix=FUNC %s
; RUN: llc -march=r600 -mcpu=SI < %s | FileCheck -check-prefix=SI -check-prefix=FUNC %s

declare double @llvm.floor.f64(double) nounwind readnone
declare <2 x double> @llvm.floor.v2f64(<2 x double>) nounwind readnone
declare <3 x double> @llvm.floor.v3f64(<3 x double>) nounwind readnone
declare <4 x double> @llvm.floor.v4f64(<4 x double>) nounwind readnone
declare <8 x double> @llvm.floor.v8f64(<8 x double>) nounwind readnone
declare <16 x double> @llvm.floor.v16f64(<16 x double>) nounwind readnone

; FUNC-LABEL: {{^}}ffloor_f64:
; CI: v_floor_f64_e32

; SI: s_bfe_u32 [[SEXP:s[0-9]+]], {{s[0-9]+}}, 0xb0014
; SI: s_add_i32 s{{[0-9]+}}, [[SEXP]], 0xfffffc01
; SI: s_lshr_b64
; SI: s_not_b64
; SI: s_and_b64
; SI-DAG: s_and_b32 s{{[0-9]+}}, s{{[0-9]+}}, 0x80000000
; SI-DAG: cmp_lt_i32
; SI: cndmask_b32
; SI: cndmask_b32
; SI: cmp_gt_i32
; SI: cndmask_b32
; SI: cndmask_b32
; SI: cmp_lt_f64
; SI: cndmask_b32
; SI: cmp_ne_i32
; SI: cndmask_b32
; SI: cndmask_b32
; SI: v_add_f64
define void @ffloor_f64(double addrspace(1)* %out, double %x) {
  %y = call double @llvm.floor.f64(double %x) nounwind readnone
  store double %y, double addrspace(1)* %out
  ret void
}

; FUNC-LABEL: {{^}}ffloor_v2f64:
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
define void @ffloor_v2f64(<2 x double> addrspace(1)* %out, <2 x double> %x) {
  %y = call <2 x double> @llvm.floor.v2f64(<2 x double> %x) nounwind readnone
  store <2 x double> %y, <2 x double> addrspace(1)* %out
  ret void
}

; FIXME-FUNC-LABEL: {{^}}ffloor_v3f64:
; FIXME-CI: v_floor_f64_e32
; FIXME-CI: v_floor_f64_e32
; FIXME-CI: v_floor_f64_e32
; define void @ffloor_v3f64(<3 x double> addrspace(1)* %out, <3 x double> %x) {
;   %y = call <3 x double> @llvm.floor.v3f64(<3 x double> %x) nounwind readnone
;   store <3 x double> %y, <3 x double> addrspace(1)* %out
;   ret void
; }

; FUNC-LABEL: {{^}}ffloor_v4f64:
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
define void @ffloor_v4f64(<4 x double> addrspace(1)* %out, <4 x double> %x) {
  %y = call <4 x double> @llvm.floor.v4f64(<4 x double> %x) nounwind readnone
  store <4 x double> %y, <4 x double> addrspace(1)* %out
  ret void
}

; FUNC-LABEL: {{^}}ffloor_v8f64:
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
define void @ffloor_v8f64(<8 x double> addrspace(1)* %out, <8 x double> %x) {
  %y = call <8 x double> @llvm.floor.v8f64(<8 x double> %x) nounwind readnone
  store <8 x double> %y, <8 x double> addrspace(1)* %out
  ret void
}

; FUNC-LABEL: {{^}}ffloor_v16f64:
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
; CI: v_floor_f64_e32
define void @ffloor_v16f64(<16 x double> addrspace(1)* %out, <16 x double> %x) {
  %y = call <16 x double> @llvm.floor.v16f64(<16 x double> %x) nounwind readnone
  store <16 x double> %y, <16 x double> addrspace(1)* %out
  ret void
}
