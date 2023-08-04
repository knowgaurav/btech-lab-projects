def fibGen(n):
    a, b = 0, 1
    if n < 0:
        print("Invalid Input")
    elif (n == 0):
        print(a)
    elif (n == 1):
        print(b)
    else:
        i = 1
        while(i <= n):
            print(a, end=" ")
            c = a+b
            a = b
            b = c
            i += 1


def factGen(n):
    fact = 1
    for i in range(2, n+1):
        fact *= i

    print("Factorial of", n, "is:", fact, end="")

# 4th Practical


def fib(n):
    if(n == 1):
        return 0
    if(n == 2):
        return 1
    return fib(n-1)+fib(n-2)


def fact(n):
    if(n == 0 or n == 1):
        return 1
    return n*fact(n-1)


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Generate Fibonacci")
    print("2. Generate Factorial")
    print("3. To exit\n")


menu()
while(1):
    ch = int(input("Enter the operation: "))
    if(ch == 0):
        menu()
    elif(ch == 1):
        n = int(input("\nEnter the number till which fibonacci series is required: "))
        if(n <= 0):
            print("Input should be greater than zero!", end="")
        else:
            print(f"Fibonacci Series is: ", end=" ")
            for i in range(1, n+1):
                print(fib(i), end=" ")

        print("\n")
    elif(ch == 2):
        f = int(input("\nEnter the number of which factorial is required: "))
        if(f < 0):
            print("Input should be greater than zero!", end="")
        else:
            print("Factorial of", f, "is:", fact(f), end=" ")

        print("\n")
    elif(ch == 3):
        exit()
    else:
        print("Invalid Input!")
