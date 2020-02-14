from idaapi import *
import idc
import idautils

def put_unconditional_branch(source, destination):
    offset = (destination - source - 4) >> 1
    if offset > 2097151 or offset < -2097152:
        raise RuntimeError("Invalid offset")
    if offset > 1023 or offset < -1024:
        instruction1 = 0xf000 | ((offset >> 11) & 0x7ff)
        instruction2 = 0xb800 | (offset & 0x7ff)
        patch_word(source, instruction1)
        patch_word(source + 2, instruction2)
    else:
        instruction = 0xe000 | (offset & 0x7ff)
        patch_word(source, instruction)

ea = here()
if Word(ea) == 0xb503: #PUSH {R0,R1,LR}
    ea1 = ea + 2
    if Word(ea1) == 0xbf00: #NOP
        ea1 += 2
    if GetOpType(ea1, 0) == 1 and GetOperandValue(ea1, 0) == 0 and GetOpType(ea1, 1) == 2:
        index = Dword(GetOperandValue(ea1, 1))
        print "index =", hex(index)
        ea1 += 2
        if GetOpType(ea1, 0) == 7:
            table = GetOperandValue(ea1, 0) + 4
        elif GetOpType(ea1, 1) == 2:
            table = GetOperandValue(ea1, 1) + 4
        else:
            print "Wrong operand type on", hex(ea1), "-", GetOpType(ea1, 0), GetOpType(ea1, 1)
            table = None
        if table is None:
            print "Unable to find table"
        else:
            print "table =", hex(table)
            offset = Dword(table + (index << 2))
            put_unconditional_branch(ea, table + offset)
    else:
        print "Unknown code", GetOpType(ea1, 0), GetOperandValue(ea1, 0), GetOpType(ea1, 1) == 2
else:
    print "Unable to detect first instruction"