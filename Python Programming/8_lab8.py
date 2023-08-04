details = ['ID', 'Name', 'Education']
persons = []

n = int(input("Enter the number of entries: "))

for i in range(0, n):
    i = int(input("ID: "))
    p = input("Name: ")
    e = input('Education: ')
    persons.append([i, p, e])

ls_of_tuples = []

for i in persons:
    ls = list(zip(details, i))
    ls_of_tuples.append(ls)


print("\nList of tuples is: ", ls_of_tuples)

d = {}

for i in ls_of_tuples:
    d_temp = dict(i[1:])
    d[i[0]] = d_temp

print("Dictionary of Students is: ", d)

print("\nSearch Dictionary for student info:")
id = int(input("ID: "))
print(f"Student details are: {d.get(('ID', id))}")
