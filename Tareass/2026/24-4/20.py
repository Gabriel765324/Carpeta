n = int(input("Dé un número.\n"))
o = 1
x = 0
s = 0
e = 2
while o < (n + 1) * (n + 2) // 2:
    s += 2 * x + 1
    x += 1
    if x == o:
        print(s, end = " ")
        o += e
        e += 1
        s = 0