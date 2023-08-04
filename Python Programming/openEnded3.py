def checkAsc(l):
    i = 0
    while(i < len(l)-1):
        if(l[i] <= l[i+1]):
            i += 1
        else:
            return False
    return True


n = int(input("Enter number of elements: "))

lst = []

print("\nEnter elements of the list: ")
for i in range(0, n):
    ele = int(input())
    lst.append(ele)

flag = checkAsc(lst)

if(flag):
    print("\nList is already sorted")
else:
    lst.sort()
    print("\nList is not sorted, sorted list is:", lst)
