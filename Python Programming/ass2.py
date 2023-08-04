# # # Question 1
pin = int(input("Enter your PIN: "))

if(pin >= 1000 and pin <= 9999):
    print("Valid PIN")
else:
    print("Invalid PIN")

# # # Question 2
# runs = int(input("Enter the batsmen score: "))

# if(runs >= 100):
#     print("He has scored a century")
# else:
#     print("He has not scored a century!")

# # # Question 3
# code = int(input("Enter the item code:"))

# if(code == 100):
#     print("Discount = 10%")
# elif (code == 101):
#     print("Discount = 15%")
# elif(code == 102):
#     print("Discount = 5%")
# elif(code == 103):
#     print("Discount = 12%")
# else:
#     print("Invalid Code!")

# # # Question 4
# age = int(input("Enter your age:"))
# if(age >= 18):
#     print("Valid Voter")
# else:
#     print("Not a valid voter!")

# # # Question 5
# num1 = int(input("Enter 1st Number: "))
# num2 = int(input("Enter 2nd Number: "))

# print("\nAddtion of", num1, "and", num2, "=", num1+num2)
# print("Subtraction of", num1, "and", num2, "=", num1-num2)
# print("Remainder of", num1, "/", num2, "=", num1 % num2)
# print("Quotient of", num1, "/", num2, "=", num1/num2, "(Normal Division)")
# print("Quotient of", num1, "/", num2, "=", num1//num2, "(Integer Division)")
# print("Multiplication of", num1, "*", num2, "=", num1*num2)

# # # Question 4
# name = input("Enter you name: ")
# age = int(input("Enter your age: "))
# salary = float(input("Enter your salary: "))

# da = 0.1*salary
# hra = 0.1*salary

# print("Total Salary  =", (salary+da+hra))

# # Question 5
# print("Gaurav Singh"*10)


# def wordCount():
#     try:
#         file = open("new.txt", 'r')
#         str = file.read()
#         words = str.split()
#         print(words)

#         count = 0

#         for i in range(len(words)):
#             for j in range(i, len(words)):
#                 if(words[j] == words[i]):
#                     count += 1
#     except:
#         print("File not found")
