class Time:
    def __init__(self, h, m, s):
        self.hour = h
        self.min = m
        self.sec = s

    def add_time(self, b_t):
        h = self.hour + b_t.hour
        m = self.min + b_t.min
        s = self.sec + b_t.sec

        if s >= 60:
            s = s-60
            m = m+1

        if m >= 60:
            m = m-60
            h = h+1

        if h >= 24:
            h = 0

        total = Time(h, m, s)
        return total

    def print_time(self):
        print(f"{self.hour}:{self.min}:{self.sec}")


def menu():
    print("Operations: ")
    print("0. Menu")
    print("1. Create File")
    print("2. Append File")
    print("3. Read File")
    print("7. To exit\n")


if __name__ == "__main__":
    menu()

    while(1):
        print("Enter the current time (24Hr Format): ")
        h = int(input("Enter Hours: "))
        m = int(input("Enter Mins: "))
        s = int(input("Enter Seconds: "))

        if(h > 24 or m > 60 or s > 60):
            current_time = Time(h, m, s)

        print("Enter the amount of time to take bread: ")
        h = int(input("Enter Hours: "))
        m = int(input("Enter Mins: "))
        s = int(input("Enter Seconds: "))
        bread_time = Time(0, 15, 60)

        ready_time = current_time.add_time(bread_time)
        print(f"Bread would be ready by: ", end="")
        ready_time.print_time()
