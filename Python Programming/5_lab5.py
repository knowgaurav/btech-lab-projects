# list = ['h', 'e', 'l', 'l', 'o']

# str = ""
# for i in range(0, len(list)):
#     str += list[i]

# print("String =", str)

# Practical 5
# lst = []

# n = int(input("Enter the number of characters: "))
# print("Enter the characters: ")

# for i in range(0, n):
#     j = input()[0]
#     lst.append(j)

# str = ""
# for i in range(0, len(lst)):
#     str += lst[i]


# print("\nEntered list is:", lst)
# print("String using for loop:", str)
# print("String using join function:", "".join(lst))

# 2nd Question
marks = int(input("Enter your score: "))

if(marks >= 0):
    if(marks > 90):
        print("Grade is S")
    elif(marks > 80):
        print("Grade is A")
    elif(marks > 70):
        print("Grade is B")
    elif(marks > 60):
        print("Grade is C")
    elif(marks > 50):
        print("Grade is D")
    elif(marks == 50):
        print("Grade is E")
    else:
        print("Grade is U")
else:
    print("Marks should be greater than zero!")
