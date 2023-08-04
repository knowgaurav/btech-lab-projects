def NOT(a):
    if a == 1:
        return 0
    else:
        return 1


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


print("Following are the tables for Logic Gates of two inputs: ")

print("\nNAND Gate:")
print("A\tB\tNAND")
for a in range(2):
    for b in range(2):
        print(f"{a}\t{b}\t{NAND(a,b)}")

print("\nNOR Gate:")
print("A\tB\tNOR")
for a in range(2):
    for b in range(2):
        print(f"{a}\t{b}\t{NOR(a,b)}")

print("\nXOR Gate:")
print("A\tB\tNOR")
for a in range(2):
    for b in range(2):
        print(f"{a}\t{b}\t{XOR(a,b)}")

print("\nNOT Gate:")
print("A\tNOT")
for a in range(2):
    print(f"{a}\t{NOT(a)}")
