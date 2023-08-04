def sublist(l1, l2):
    l3 = []
    for i in range(0, len(l1)):
        l3.append(l1[i]-l2[i])
    return l3


def getInput(l, n):
    for i in range(0, n):
        ele = int(input())
        l.append(ele)


l1 = []
l2 = []

n = int(input("Enter number of elements of lists: "))

print("\nEnter the elements of list 1:")
getInput(l1, n)
print("\nEnter the elements of list 2:")
getInput(l2, n)

print("\nlist 1 - list 2 = ", end="")
print(sublist(l1, l2))

# if(len(l1) == len(l2)):
# print(sublist(l1, l2))
# else:
#     print("Both the lists should be of same size")
