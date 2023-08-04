# num1 = int(input("Enter the first number: "))
# num2 = int(input("Enter the second number: "))

# print(f"\nBefore swapping: num1 = {num1} and num2 = {num2}")

# temp = num1
# num1 = num2
# num2 = temp

# print(f"After swapping: num1 = {num1} and num2 = {num2}")


# def triangleArea(b, h):
#     area = 0.5*b*h
#     return area


# base = int(input("Enter the base of the triangle: "))
# height = int(input("Enter the height of the triangle: "))

# print("\nArea of the triangle is:", triangleArea(base, height))

# year = int(input('Enter a year: '))

# if year % 4 == 0:
#     if year % 100 == 0:
#         if year % 400 == 0:
#             print(f'Year {year} is a leap year')
#         else:
#             print(f'Year {year} is not a leap year')
#     else:
#         print(f'Year {year} is a leap year')
# else:
#     print(f'Year {year} is not a leap year')

num = int(input('Please enter a number: '))

num_copy = num
rev = 0
while num > 0:
    mod = num % 10
    rev = rev * 10 + mod
    num = num // 10

print(f'The reverse of number {num_copy} is {rev}')
