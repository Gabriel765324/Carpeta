n = int(input("Dé n.\n"))
a0 = 0
a1 = 0
for i in range(0, n):
    print(a1, end = " ")
    if a0 + a1 == 0:
        a1 = 1
    else:
        a1 += a0
        a0 = a1 - a0