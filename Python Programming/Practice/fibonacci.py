def fib(n):
    a = 0
    b = 1
    z = 0
    while(z <= n):
        print(z)
        a = b
        b = z
        z = a+b


def factorial(n):
    fact = 1
    while(n > 1):
        fact *= n
        n = n-1

    print(fact)


fib(10)

a = 10
b = 20

print(a, b)

(a, b) = (b, a)

print(a, b)

factorial(5)
