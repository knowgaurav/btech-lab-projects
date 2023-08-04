print("<--- Python Assignment --->\n")


def isPrime(n):
    # Checking if num is greater than 1 or not
    if (n <= 1):
        print("Number is not prime.")
    else:
        # Iterating from 2 to floor value of divsion of n by 2
        for i in range(2, n//2):
            if (n % i) == 0:
                print("Number is not prime, smallest prime divisor is: ", i)
                break

    print("Number is Prime!")


num = int(input("Enter the number: "))
isPrime(num)
