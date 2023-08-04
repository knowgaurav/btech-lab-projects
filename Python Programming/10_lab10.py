import datetime


class Time:
    def __init__(self, h, m, s):
        self.hour = h
        self.min = m
        self.sec = s

    def add_time(self, b_t):
        h = self.hour + b_t.hour
        m = self.min + b_t.min
        s = self.sec + b_t.sec

        while s >= 60:
            s = s-60
            m = m+1

        while m >= 60:
            m = m-60
            h = h+1

        while h >= 24:
            h = h % 24

        total = Time(h, m, s)
        return total

    def print_time(self):
        print(f"{self.hour}:{self.min}:{self.sec}")


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Order Now")
    print("2. Schedule Order")
    print("3. To exit\n")


if __name__ == "__main__":
    menu()
    while(1):
        ch = int(input("Enter the operation: "))
        if(ch == 0):
            menu()
            print("\n")
        elif(ch == 1):
            current_time = datetime.datetime.now()
            h = current_time.hour
            m = current_time.minute
            s = current_time.second
            current_time = Time(h, m, s)
            print(f"Current Time is: ", end="")
            current_time.print_time()

            # bread_time = Time(0, 30, 0)
            print("\nEnter the amount of time to make bread: ")
            h = int(input("Enter Hours: "))
            m = int(input("Enter Mins: "))
            s = int(input("Enter Seconds: "))

            bread_time = Time(h, m, s)
            ready_time = current_time.add_time(bread_time)
            print(f"\nBread would be ready by: ", end="")
            ready_time.print_time()
            print("\n")
        elif(ch == 2):
            print("\nEnter the order time (24Hr Format): ")
            h = int(input("Enter Hours: "))
            m = int(input("Enter Mins: "))
            s = int(input("Enter Seconds: "))

            if(h >= 24 or m >= 60 or s >= 60):
                print("Invalid Time. Please enter correct time.")
            else:
                current_time = Time(h, m, s)

                print("\nEnter the amount of time to make bread: ")
                h = int(input("Enter Hours: "))
                m = int(input("Enter Mins: "))
                s = int(input("Enter Seconds: "))
                bread_time = Time(h, m, s)

                ready_time = current_time.add_time(bread_time)
                print(f"\nBread would be ready by: ", end="")
                ready_time.print_time()
            print("\n")
        elif(ch == 3):
            exit()
        else:
            print("Invalid Input!\n")
