a = int(input("Dé un número.\n"))
b = int(input("Dé un número mayor.\n"))
if a >= b:
    print(":(")
else:
    for x in range(a, b + 1):
        print(x)