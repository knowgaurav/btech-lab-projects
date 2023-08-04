

# str = "Twinkle, twinkle, little star, How I wonder what you are! Up above the world so high, Like a diamond in the sky. Twinkle, twinkle, little star, How I wonder what you are"

# print("Twinkle, twinkle, little star, \n\tHow I wonder what you are! \n\t\tUp above the world so high, \n\t\tLike a diamond in the sky. \nTwinkle, twinkle, little star, \n\tHow I wonder what you are!")

# from datetime import datetime, date
# current_time = datetime.now().strftime("%H:%M:%S")
# current_date = date.today()
# print(f"Current date and time:\n{current_date} {current_time}")

# file_name = input("Enter the file name: ")
# print(file_name[file_name.find(".")+1:])

# color_list = ["Red", "Green", "White", "Black"]
# print("First Color = ", color_list[0])
# print("Last Color = ", color_list[-1])

# n = input("Enter a number: ")
# print("Output = ", int(n) + int(n*2) + int(n*3))

# import calendar
# m = int(input("Enter the month: "))
# print(calendar.month(2021, m))

# from datetime import date
# d1 = date(2014, 7, 11)
# d2 = date(2014, 7, 2)

# print("Days passed = ", (d1-d2).days)

# num = int(input("Enter a number: "))
# if num > 17:
#     print(abs(17-num)*2)
# else:
#     print(17-num)

# num1 = int(input("Enter the 1st number: "))
# num2 = int(input("Enter the 2md number: "))
# num3 = int(input("Enter the 3rd number: "))

# if (num1 == num2 and num2 == num3):
#     print(num1*9)
# else:
#     print(num1+num2+num3)

# vowels = ['a', 'e', 'i', 'o', 'u']
vowels = "aeiou"
char = input("Enter a letter: ")

if vowels.find(char) != -1:
    print("Input is a vowel")
else:
    print("Input is consonant")
