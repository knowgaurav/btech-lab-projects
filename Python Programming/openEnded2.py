import random
fibArr = [0, 1]
factArr = [1, 1]


def fib():
    for i in range(2, 10):
        fibArr.append(fibArr[i-1]+fibArr[i-2])


def fact():
    for i in range(2, 10):
        factArr.append(i*factArr[i-1])


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Register")
    print("2. Guess Fibonacci")
    print("3. Guess Factorial")
    print("4. Show Score")
    print("5. To exit\n")


fib()
fact()
menu()


class user:
    def __init__(self, username='guest'):
        self.uname = username
        self.score = 0

    def getInfo(self):
        return (self.uname, self.score)

    def updateScore(self):
        self.score += 1


def appendFile(u):
    file = open('users.txt', 'a')
    str1 = str(u.uname) + " " + str(u.score)
    file.writelines(f"\n{str1}")
    file.close()


while(1):
    ch = int(input("Enter the operation: "))
    if(ch == 0):
        menu()
    elif(ch == 1):
        uname = input("Enter your username: ")
        u = user(uname)

        print("\n")
    elif(ch == 2):
        num = random.randint(1, 10)
        guess = int(input(f"Enter guess for the {num} fibonacci: "))
        if (guess == fibArr[num-1]):
            u.updateScore()
            print("Correct Guess!")
        else:
            print(f"Wrong Guess! Correct Guess is: {fibArr[num-1]}")

        print("\n")
    elif(ch == 3):
        num = random.randint(1, 6)
        guess = int(input(f"Enter your Factorial Guess for number {num}: "))
        if (guess == factArr[num]):
            u.updateScore()
            print("Correct Guess!")
        else:
            print(f"Wrong Guess! Correct Guess is: {factArr[num]}")

        print("\n")
    elif(ch == 4):
        print(f"{u.getInfo()[0]}, your current score is: {u.getInfo()[1]}")
        print("\n")
    elif(ch == 5):
        appendFile(u)
        print("Thanks for playing!")
        exit()
    else:
        print("Invalid Input!")
