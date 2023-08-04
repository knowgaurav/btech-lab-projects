# if __name__ == '__main__':
#     str = input("Enter the string: ")

#     print("Characters of the string are: ")
#     set1 = set(str)
#     for i in set1:
#         print(f'{i}', end=' ')

#     if(str.isalpha()):
#         if(not str.isupper()):
#             print(f"\n\nUppercase of {str} = {str.upper()}")
#         if(not str.islower()):
#             print(f"Lowercase of {str} = {str.lower()}")
#     else:
#         print("\nCannot perform string operations.")

#     str1 = input("\nEnter the string for concatination: ")
#     print(f"{str} + {str1} = {str+' '+str1}")

# n = 5

# for row in range(1, n+1):
#     for star in range(1, row+1):
#         print("*", end='')
#     print()

n = 13

for i in range(2, n):
    if(n % i == 0):
        print("Not a prime")
        break
else:
    print("Prime")
