l = ['id', 'name', 'course']

s1 = [1, 'Gaurav', 'B.Tech']
s2 = [2, 'Gaurav Singh', 'B.Tech IT']

s3 = [s1, s2]

ls = []
ls.append(list(zip(l, s1)))
ls.append(list(zip(l, s2)))

print(ls)
