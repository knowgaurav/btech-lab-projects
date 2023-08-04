if __name__ == "__main__":
    str = input("Enter the string: ")
    words = str.split()
    dict = {}
    for i in str:
        dict[i] = str.count(i)

    # print(dict)
    print("\nFrequency of characters are: ")
    for i in dict:
        if(dict[i] <= 1):
            print(f"'{i}' occurs '{dict[i]}' time")
        else:
            print(f"'{i}' occurs '{dict[i]}' times")

    print(f"\nTotal no. of words = {len(words)}")
