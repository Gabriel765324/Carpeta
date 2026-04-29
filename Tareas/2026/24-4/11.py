a = int(input("Dé un número.\n"))
b = int(input("Dé un número.\n"))
if a < b:
    for i in range(a, b + 1):
        print(i, end = " ")
else:
    for i in range(a, b - 1, -1):
        print(i, end = " ")