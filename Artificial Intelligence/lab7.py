print('WAP in python to develop for NAND gate, NOR gate, NOT gate and XOR gate\n')


def NOT(a):
    if a == 0:
        return 1
    elif a == 1:
        return 0


def NAND(a, b):
    if a == b == 1:
        return 0
    else:
        return 1


def NOR(a, b):
    if a == b == 0:
        return 1
    else:
        return 0


def XOR(a, b):
    if a != b:
        return 1
    else:
        return 0


print('Following are the Logic GATES for two input only( a,b )\n')
print('0 for False and 1 for True\n')
print("NAND Gate")
for a in range(2):
    for b in range(2):
        print('a = ', a, "b = ", b, "a NAND b = ", NAND(a, b))
print("NOR Gate")
for a in range(2):
    for b in range(2):
        print('a = ', a, "b = ", b, "a NOR b = ", NOR(a, b))
print("XOR Gate")
for a in range(2):
    for b in range(2):
        print('a = ', a, "b = ", b, "a XOR b = ", XOR(a, b))
print("NOT Gate")
for a in range(2):
    print('a = ', a, "a NOT = ", NOT(a))
