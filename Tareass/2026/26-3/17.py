a = int(input("Dé un número.\n"))
b = int(input("Dé un número mayor.\n"))
if a >= b:
    print(":(")
else:
    a += 1 - a % 2
    for x in range(a, b + 1, 2):
        print(x)