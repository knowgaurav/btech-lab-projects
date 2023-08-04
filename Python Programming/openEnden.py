import random

l = "abcdefghijklmnopqrstuvwxyz"
u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
n = "0123456789"
s = "!@#$%^&*()_."


def random_password_generator():
    password = []
    password.append(random.choice(l))
    password.append(random.choice(u))
    password.append(random.choice(n))
    password.append(random.choice(s))
    rem = l+u+n+s

    for i in range(4, 12):
        password.append(random.choice(rem))

    random.shuffle(password)
    p = ""
    return p.join(password)


print(f"Your secure password is: {random_password_generator()}")
