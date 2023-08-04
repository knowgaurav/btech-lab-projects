# import random


# def fact(n):
#     if(n == 0 or n == 1):
#         return 1
#     return n*fact(n-1)


# def factGen(n):
#     fact = 1
#     while(n > 1):
#         fact *= n
#         n -= 1

#     return fact


# def fact2(n):
#     fact = 1
#     for i in range(2, n):
#         fact = fact*(i)
#     return fact


# fib_list = [0, 1]


# # def fib(n):
# #     for i in range(2, n):
# #         fib_list.append(fib_list[i-1]+fib_list[i-2])

# #     for i in fib_list:
# #         print(f"{i}", end=" ")


# def fib(n):
#     for i in range(2, n):
#         fib_list.append(fib_list[i-1]+fib_list[i-2])

#     for i in fib_list:
#         print(f"{i}", end=" ")


# n = int(input("Enter a number: "))

# if(n < 0):
#     print("Please enter a positive integer!")
# else:
#     print(f"Factorial of {n}: {fact(n)}, {fact(n)}, {factGen(n)}")
#     print(f"First {n} Fibonacci numbers are:", end=" ")
#     fib(n)

# l1 = [9064, "Gaurav Singh", "B.Tech IT", 5]
# t1 = (9064, "Gaurav Singh", "B.Tech IT", 5)
# d1 = {"Roll no.": 9064, "Name": "Gaurav Singh",
#       "Course": "B.Tech IT", "Semester": 5}

# print("\n\nRoll number =", l1[0])
# print("Name =", l1[1])
# print("Course =", t1[2])
# print("Semester =", d1["Semester"])

# t2 = ("Name", "Course", "Roll Number")
# l2 = ["Gaurav Singh", "B.Tech IT", 9064]

# # print(zip(t2, l2))

# # print(t2.count("Name"))
# # print(t1-t2)


# u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# l = "abcdefghijklmnopqrstuvwxyz"
# d = "0123456789"
# s = "~!@#$%^&*()_"


# def pass_gen(n):
#     password = []
#     password.append(random.choice(u))
#     password.append(random.choice(l))
#     password.append(random.choice(d))
#     password.append(random.choice(s))

#     rem = u+l+d+s

#     while(len(password) < n):
#         password.append(random.choice(rem))

#     random.shuffle(password)

#     return "".join(password)


# str_pass = pass_gen(12)
# print("Your password is:", str_pass)
# print("Your password is:", list(str_pass))

# # Check Palindrome
# num = int(input("Enter a number: "))
# rev = 0
# temp = num

# while(num > 0):
#     rev = (rev*10) + (num % 10)
#     num //= 10

# if temp == rev:
#     print("Number is palindrome")
# else:
#     print("Number is not palindrome")

# str = "My name is Gaurav Singh"
# print(str.split())
# print(str.upper().isupper())
# print(str.lower().islower())
# print("Gaurav"[::-1])

from typing import IO


def write_file(file_name, str):
    with open(file_name, 'w') as f:
        f.write(str)


def read_file(file_name):
    try:
        f = open(file_name)
        content = f.read()
        print(content)
        f.close()
    except IOError:
        print("File doesn't exists!")


write_file('viva.txt', "Writing into the file!")
read_file('viva.txt')
