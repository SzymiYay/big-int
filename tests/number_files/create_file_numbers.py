import random

f = open("numbers.txt", "w")

for _ in range(10000):
    f.write(f"{random.randint(-10000000000000000000000, 10000000000000000000000)} {random.randint(-10000000000000000000000, 10000000000000000000000)}\n")

f.close()