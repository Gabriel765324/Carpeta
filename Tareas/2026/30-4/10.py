n = int(input("Dé un número.\n"))
for i in range(n):
    for j in range(n * i + 1, n * (i + 1) + 1):
        print(j, end = " ")
    print("")