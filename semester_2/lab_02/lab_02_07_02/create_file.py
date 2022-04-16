import random

with open("my_data.txt", "w") as file:
    n = 100
    file.write(str(n) + '\n')
    for elem in range(n):
        num = random.randint(0, n)
        file.write(str(num) + '\n')
