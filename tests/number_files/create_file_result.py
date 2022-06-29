f = open("numbers.txt", "r")
g = open("result.txt", "w")

for line in f:
    list_of_numbers = line.split(" ")
    g.write(f"{int(list_of_numbers[0]) * int(list_of_numbers[1])}\n")


f.close()
g.close()