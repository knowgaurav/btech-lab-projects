# l = []

# n = int((input("Enter how many element you wish to enter: ")))

# i = 0
# while(i < n):
#     ele = input(f"Element {i} = ")
#     l.append(ele)
#     i += 1

# key = input("Enter the key to find: ")

# if key.isdigit():
#     key = int(key)

# start = int(input("Enter the start index: "))
# end = int(input("Enter the end index: "))

# if(start < 0 or end > len(l)):
#     print("Invalid Index")
# else:
#     print("The element is present at index: ", l.index(key))

l = []
def find_index(l, k, s, e):
    try:
        return l.index(key, s, e)
    except ValueError:
        return None


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Initialize List")
    print("2. Search")
    print("3. Clear List")
    print("4. Print List")
    print("5. To exit\n")


menu()
while(1):
    ch = int(input("Enter the operation: "))
    if(ch == 0):
        menu()
    elif(ch == 1):
        n = int((input("\nEnter how many element you wish to enter: ")))

        i = 0
        while(i < n):
            ele = input(f"Element {i} = ")
            if ele.isdigit():
                ele = int(ele)
            l.append(ele)
            i += 1

    elif(ch == 2):
        key = input("\nEnter the key to find: ")

        if key.isdigit():
            key = int(key)

        start = int(input("Enter the start index: "))
        end = int(input("Enter the end index: "))

        if(start < 0 or end > n-1):
            print("Invalid Index")
        else:
            indx = find_index(l, key, start, end+1)
            if(indx == None):
                print("Element not found")
            else:
                print("Element found @ index:", indx)

    elif(ch == 3):
        l.clear()
    elif(ch == 4):
        print("The list is: ", l)
        print("\nIndex\tElement")
        for i in range(0, len(l)):
            print(f'{i}\t{l[i]}')
    elif(ch == 5):
        exit()
    else:
        print("Invalid Input!")

    print()
