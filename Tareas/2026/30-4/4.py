n = int(input("Dé un número.\n"))
for i in range(n):
    for j in range(n):
        print((i + j + 1) % 2, end = " ")
    print("")