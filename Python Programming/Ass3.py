# file1 = open("file.txt", 'a')
# s = "Writing into the file"
# file1.write(s)
# # file.close()

# file2 = open("file.txt", 'rt')
# file2.seek(0)
# print(file2.read())

# file1.close()
# file2.close()


from typing import IO


def writeFile(file_name):
    file = open(file_name, 'w+')
    file_input = input("Enter the content of the file: ")
    file.write(file_input)
    file.close()


def readFile(file_name):
    try:
        file = open(file_name)
        print(file.read())
        file.close()
    except IOError:
        print("File doesn't exist.")


def appendFile(file_name):
    try:
        file = open(file_name, 'a')
        str = input("Enter the content: ")
        file.writelines(f" {str}")
        file.close()
    except:
        print("File doesn't exist")


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Create File")
    print("2. Append File")
    print("3. Read File")
    print("4. To exit\n")


if __name__ == "__main__":
    menu()

    while(1):
        ch = int(input("Enter the operation: "))
        if(ch == 0):
            menu()
        elif(ch == 1):
            file_name = input("Enter the file name: ")
            writeFile(file_name)
            print("\n")
        elif(ch == 2):
            appendFile(file_name)
            print("\n")
        elif(ch == 3):
            readFile(file_name)
            print("\n")
        elif(ch == 4):
            exit()
        else:
            print("Invalid Input!")
