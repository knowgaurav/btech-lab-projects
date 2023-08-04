def combine_files(file_name1, file_name2, dest_file):
    with open(file_name1, 'r') as file_obj1:
        with open(file_name2, 'r') as file_obj2:
            with open(dest_file, 'w') as dest_file_obj:
                lines1 = file_obj1.readlines()
                lines2 = file_obj2.readlines()
                dest_file_obj.writelines(lines1 + lines2)


def createFile(file_name, data):
    file_obj = open(file_name, 'w')
    file_obj.write(data+"\n")
    file_obj.close()


def readFile(file_name):
    try:
        file_obj = open(file_name, 'r')
        data = file_obj.read()
        print(data, end="")
        file_obj.close()
    except:
        print("File not found!")


name1 = "src1.txt"
name2 = "src2.txt"
dest = "dest.txt"

createFile(name1, "Writing in the first file!!")
createFile(name2, "Creating and writing in the second file!!")

readFile(name1)
readFile(name2)

combine_files(name1, name2, dest)
readFile(dest)
