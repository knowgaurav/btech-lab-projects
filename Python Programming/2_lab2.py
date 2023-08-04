# 2nd Practical
print("Python Lab Practical - 6/8/21\n")

# Calculating SI using funtion


def calSI(p, r, t):
    return (p*r*t)/100


p = float(input("Enter the prinicipal amount (Rs.): "))
t = float(input("Enter the time period (Years): "))
r = float(input("Enter the rate of interest (%): "))

# si = (p*r*t)/100
si = calSI(p, r, t)

print("\nThe SI of amount Rs.",
      p, "with an interest rate of",
      r, "% for time period", t, "years is: Rs.", si)
print("Total Amount to be Paid after", t, "years is Rs.", si+p)
