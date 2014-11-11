//===-- PwisaRegisterInfo.td - Pwisa Register defs ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the Pwisa register file
//===----------------------------------------------------------------------===//


// We have banks of 32 registers each.
class PwisaReg<string n> : Register<n> {
  field bits<5> Num;
  let Namespace = "Pwisa";
}

// Pwisa CPU Registers
class PwisaGPRReg<bits<5> num, string n> : PwisaReg<n> {
  let Num = num;
}

// Pwisa CPU Special Registers
//class PwisaSPRReg<bits<5> num, string n> : PwisaReg<n> {
//  let Num = num;
//}

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//
// The register string, such as "9" or "gp" will show on "llvm-objdump -d"
let Namespace = "Pwisa" in {
  // General Purpose Registers
  def PZ   : PwisaGPRReg<0,  "pz">,    DwarfRegNum<[0]>;
  def P0   : PwisaGPRReg<1,  "p0">,    DwarfRegNum<[1]>;
  def P1   : PwisaGPRReg<2,  "p1">,    DwarfRegNum<[2]>;
  def P2   : PwisaGPRReg<3,  "p2">,    DwarfRegNum<[3]>;
  def P3   : PwisaGPRReg<4,  "p3">,    DwarfRegNum<[4]>;
  def P4   : PwisaGPRReg<5,  "p4">,    DwarfRegNum<[5]>;
  def P5   : PwisaGPRReg<6,  "p5">,    DwarfRegNum<[6]>;
  def P6   : PwisaGPRReg<7,  "p6">,    DwarfRegNum<[7]>;
  def P7   : PwisaGPRReg<8,  "p7">,    DwarfRegNum<[8]>;
  def RV   : PwisaGPRReg<9,  "rv">,    DwarfRegNum<[9]>;
  def R10  : PwisaGPRReg<10, "10">,    DwarfRegNum<[10]>;
  def R11  : PwisaGPRReg<11, "11">,    DwarfRegNum<[11]>;
  def R12  : PwisaGPRReg<12, "12">,    DwarfRegNum<[12]>;
  def R13  : PwisaGPRReg<13, "13">,    DwarfRegNum<[13]>;
  def R14  : PwisaGPRReg<14, "14">,    DwarfRegNum<[14]>;
  def R15  : PwisaGPRReg<15, "15">,    DwarfRegNum<[15]>;
  def R16  : PwisaGPRReg<16, "16">,    DwarfRegNum<[16]>;
  def R17  : PwisaGPRReg<17, "17">,    DwarfRegNum<[17]>;
  def R18  : PwisaGPRReg<18, "18">,    DwarfRegNum<[18]>;
  def R19  : PwisaGPRReg<19, "19">,    DwarfRegNum<[19]>;
  def R20  : PwisaGPRReg<20, "20">,    DwarfRegNum<[20]>;
  def R21  : PwisaGPRReg<21, "21">,    DwarfRegNum<[21]>;
  def R22  : PwisaGPRReg<22, "22">,    DwarfRegNum<[22]>;
  def R23  : PwisaGPRReg<23, "23">,    DwarfRegNum<[23]>;
  def R24  : PwisaGPRReg<24, "24">,    DwarfRegNum<[24]>;
  def R25  : PwisaGPRReg<25, "25">,    DwarfRegNum<[25]>;
  def R26  : PwisaGPRReg<26, "26">,    DwarfRegNum<[26]>;
  def R27  : PwisaGPRReg<27, "27">,    DwarfRegNum<[27]>;
  def LR   : PwisaGPRReg<28, "lr">,    DwarfRegNum<[28]>;
  def FP   : PwisaGPRReg<29, "fp">,    DwarfRegNum<[29]>;
  def SP   : PwisaGPRReg<30, "sp">,    DwarfRegNum<[30]>;
  def PC   : PwisaGPRReg<31, "pc">,    DwarfRegNum<[31]>;
}

//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

def CPURegs : RegisterClass<"Pwisa", [i32], 32, (add
  // Reserved
  PZ,
  // Return Values and Arguments
  P0, P1, P2, P3, P4, P5, P6, P7, RV,
  // Not preserved across procedure calls
  R10, R11, R12, R13, R14, R15, R16, R17, R18, R19,
  // Callee save
  R20, R21, R22, R23, R24, R25, R26, R27,
  // Reserved
  LR, FP, SP, PC
  )>;

// Status Registers class
//def SR   : RegisterClass<"Pwisa", [i32], 32, (add SW)>;

// Special Registers class
//def SPR  : RegisterClass<"Pwisa", [i32], 32, (add EPC)>;

