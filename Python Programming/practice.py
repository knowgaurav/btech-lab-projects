# def compare_two_files():
#     f1 = open('file1.txt', 'r')
#     f2 = open('file2.txt', 'r')
#     f3 = open('file3.txt', 'w')

#     d1 = f1.readlines()
#     d2 = f2.readlines()

#     if(len(d1) == len(d2)):
#         for i in range(0, len(d1)):
#             j = int(d1[i])
#             k = int(d2[i])
#             if(j > k):
#                 f3.write(str(j)+">"+str(k)+"\n")
#             else:
#                 f3.write(str(j)+"<"+str(k)+"\n")
#         print("Comparison completed successfully!")
#     else:
#         print("Files can't be compared. Unequal size!")
#     f1.close()
#     f2.close()
#     f3.close()


# compare_two_files()

from os import read


with open('file1.txt', 'r') as f:
    # data = f.readline()
    # data = f.readline()
    # data = f.readline()
    # data = f.readlines()
    # if data == '\n':
    #     break
    # else:
    # print(data)
    str = " "
    while str:
        str = f.readline()
        print(str)
    f.seek(0)
    while True:
        s = f.readline()
        if s == '':
            break
        else:
            print(s)
