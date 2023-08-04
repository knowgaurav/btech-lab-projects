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
        file.writelines(f"\n{str}")
        file.close()
    except:
        print("File doesn't exist")


def countLines(file_name):
    line_count = 0
    with open(file_name) as file:
        for line in file:
            if line != "\n":
                line_count += 1

    return line_count


def compareWordCount(file1, file2):
    f1 = {}
    f2 = {}
    words = []
    with open(file1) as file:
        data = file.read()
        words = data.split()
        for word in words:
            if f1.get(word) == None:
                f1[word] = 1
            else:
                f1[word] += 1

    words = []
    with open(file2) as file:
        data = file.read()
        words = data.split()
        for word in words:
            if f2.get(word) == None:
                f2[word] = 1
            else:
                f2[word] += 1

    # for i in f1:
    #     print(i, f1[i])

    # print("\n")

    # for j in f2:
    #     print(j, f2[j])

    for i in f1:
        for j in f2:
            if i == j and f1[i] > f2[i]:
                return (i, 1)
            elif i == j and f1[i] < f2[i]:
                return (j, 2)

    return None


def combineFiles(dest, s1, s2):
    try:
        comb = open(dest, 'a')
        with open(s1) as source1:
            data = source1.read()
            comb.writelines(f"\n{data}")

        with open(s2) as source2:
            data = source2.read()
            comb.writelines(f"\n{data}")

        print(f"Combined Output File Generated - '{dest}', successfully!")
    except:
        print("File doesn't exist")


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Create File")
    print("2. Append File")
    print("3. Read File")
    print("4. Combine Files")
    print("5. Count Lines")
    print("6. Compare Word Count")
    print("7. To exit\n")


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
            file_name = input("Enter the file name: ")
            appendFile(file_name)
            print("\n")
        elif(ch == 3):
            file_name = input("Enter the file name: ")
            readFile(file_name)
            print("\n")
        elif(ch == 4):
            file1 = input("Enter the source 1 name: ")
            file2 = input("Enter the source 2 name: ")
            dest = input("Enter the destination name: ")
            combineFiles(dest, file1, file2)
            print("\n")
        elif(ch == 5):
            file_name = input("Enter the file name: ")
            print(
                f"No. of Lines in file '{file_name}' is: {countLines(file_name)}")
            print("\n")
        elif(ch == 6):
            file1 = input("Enter the name of file 1: ")
            file2 = input("Enter the name of file 2: ")
            ans = compareWordCount(file1, file2)
            if ans == None:
                print("No word found")
            else:
                print(f"Word '{ans[0]}' has come more times in File {ans[1]}")
            print("\n")
        elif(ch == 7):
            exit()
        else:
            print("Invalid Input!")
