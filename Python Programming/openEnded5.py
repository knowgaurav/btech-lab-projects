n = int(input("Enter number of elements: "))

lst = []

print("\nEnter elements of the list: ")
for i in range(0, n):
    ele = input()
    lst.append(ele)

new_lst = list(set(lst))

print("\nBefore removing duplicate items:", lst)
print("After removing duplicate items:", new_lst)
