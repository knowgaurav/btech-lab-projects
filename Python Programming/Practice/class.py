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

        while(s >= 60):
            s -= 60
            m += 1

        while(m >= 60):
            m -= 60
            h += 1

        while(h >= 24):
            h %= 24

        total = Time(h, m, s)
        return total

    def print_time(self):
        print(f"{self.hour}:{self.min}:{self.sec}")


curr_time = datetime.datetime.now()
hour = curr_time.hour
min = curr_time.minute
sec = curr_time.second

curr_time = Time(hour, min, sec)
curr_time.print_time()

bread_time = Time(3, 10, 0)
bread_time.print_time()

total_time = curr_time.add_time(bread_time)
total_time.print_time()
