s = 0
c = 0
while True:
    n = int(input("Dé un número.\n"))
    if n <= 0:
        print(s / c)
        exit(0)
    s += n
    c += 1
    print(s, c)