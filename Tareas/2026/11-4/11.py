n = int(input("Dé n.\n"))
s = 0
for i in range(0, n):
    if (i + s) % 3 == 0:
        s += 1
    print(i + s, end = " ")