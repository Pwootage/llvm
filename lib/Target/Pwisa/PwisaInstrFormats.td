//===-- PwisaInstrFormats.td - Pwisa Instruction Formats ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Describe Pwisa instruction formats
//
//  CPU INSTRUCTION FORMATS
//
//  opcode  - operation code.
//  ra      - dst reg, only used on 3 regs instr.
//  rb      - src reg.
//  rc      - src reg (on a 3 reg instr).
//  cx      - immediate
//
//===----------------------------------------------------------------------===//

class Format<bits<2> val> {
  bits<2> Value = val;
}

def Frm0      : Format<0>;
def Frm1      : Format<1>;
def Frm2      : Format<2>;
def Frm3      : Format<3>;

// Generic Pwisa Format
class PwisaInst<dag outs, dag ins, string asmstr, list<dag> pattern,
               InstrItinClass itin, Format f>: Instruction
{
  field bits<32> Inst;
  Format Form = f;

  let Namespace = "Pwisa";

  let Size = 4;

  bits<6> Opcode = 0;

  // Top 6 bits are the 'opcode' field
  let Inst{31-26} = Opcode;

  let OutOperandList = outs;
  let InOperandList  = ins;

  let AsmString   = asmstr;
  let Pattern     = pattern;
  let Itinerary   = itin;

  //
  // Attributes specific to Pwisa instructions...
  //
  bits<2> FormBits = Form.Value;

  // TSFlags layout should be kept in sync with PwisaInstrInfo.h.
  let TSFlags{1-0}   = FormBits;

  let DecoderNamespace = "Pwisa";

  field bits<32> SoftFail = 0;
}




//===----------------------------------------------------------------------===//
// Form 0 instruction class in Pwisa : <OOOO OOII IIII IIII IIII IIII IIII IIII>
//===----------------------------------------------------------------------===//

class F0<bits<6> op, dag outs, dag ins, string asmstr,
         list<dag> pattern, InstrItinClass itin>:
      PwisaInst<outs, ins, asmstr, pattern, itin, Frm0>
{
  bits<26> immed;

  let Opcode = op;

  let Inst{25-0} = immed;
}

//===----------------------------------------------------------------------===//
// Form 1 instruction class in Pwisa : <OOOO OODD DDDA AAAA BBBB BSSS IIII IIII>
//===----------------------------------------------------------------------===//

class F1<bits<6> op, bits<3> sub, dag outs, dag ins, string asmstr, list<dag> pattern,
         InstrItinClass itin>: PwisaInst<outs, ins, asmstr, pattern, itin, Frm1>
{
  bits<5>  rd;
  bits<5>  ra;
  bits<5>  rb;
  bits<8>  imm;

  let Opcode = op;

  let Inst{25-21} = rd;
  let Inst{20-16} = ra;
  let Inst{15-11} = rb;
  let Inst{10-8}  = sub;
  let Inst{7-0}   = imm;
}

//===----------------------------------------------------------------------===//
 // Form 2 instruction class in Pwisa : <OOOO OODD DDDA AAAA IIII IIII IIII IIII>
 //===----------------------------------------------------------------------===//

 class F2<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern,
          InstrItinClass itin>: PwisaInst<outs, ins, asmstr, pattern, itin, Frm2>
 {
   bits<5>   rd;
   bits<5>   ra;
   bits<16>  imm;

   let Opcode = op;

   let Inst{25-21} = rd;
   let Inst{20-16} = ra;
   let Inst{15-0}   = imm;
 }

//===----------------------------------------------------------------------===//
// Form 3 instruction class in Pwisa : <OOOO OODD DDDI IIII IIII IIII IIII IIII>
//===----------------------------------------------------------------------===//

class F3<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern,
         InstrItinClass itin>: PwisaInst<outs, ins, asmstr, pattern, itin, Frm3>
{
  bits<5>   rd;
  bits<21>  imm;

  let Opcode = op;

  let Inst{25-21} = rd;
  let Inst{20-0}  = imm;
}


