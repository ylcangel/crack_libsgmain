def put_unconditional_branch1(source, destination):
    offset = (destination - source - 4) >> 1
    if offset > 2097151 or offset < -2097152:
        raise RuntimeError("Invalid offset")
    if offset > 1023 or offset < -1024:
        instruction1 = 0xf000 | ((offset >> 11) & 0x7ff)
        instruction2 = 0xb800 | (offset & 0x7ff)
        PatchWord(source, instruction1)
        PatchWord(source + 2, instruction2)
    else:
        instruction = 0xe000 | (offset & 0x7ff)
        PatchWord(source, instruction)

# ea = here()
def patch1(ea):
    ea0 = ea
    if Word(ea) == 0xb503: #PUSH {R0,R1,LR}
        ea1 = ea + 6
        if Word(ea + 2) == 0xbf00: #NOP
            ea1 += 2
        offset = Dword(ea1)
        put_unconditional_branch1(ea, (ea1 + offset) & 0xffffffff)
        ea0 = ea1 - ea0
    else:
        print "Unable to detect first instruction"
        
    return ea0


code_start = 0xb110 # JNI_OnLoad
code_end = 0x886e0
while (code_start <= code_end):
    flag = patch1(code_start)
    if (flag == 8) :
        code_start = code_start + 8
    else:
        code_start = code_start + 1
