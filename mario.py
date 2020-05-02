from cs50 import get_int

n  = get_int("Heigth: ")

while n < 1 or n > 8:
    n  = get_int("Heigth: ")

for i in range(1, n + 1):
    print(" " * (n - i) + "#" * i + " " + "#" * i)