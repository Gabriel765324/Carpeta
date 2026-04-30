i = int(input("Dé un número.\n"))
j = int(input("Dé un número.\n"))
if i > j:
    exit(0)
while i <= j:
    n = str(i)
    Mal = True
    while Mal:
        Mal = False
        n = str(n)
        for k in range(len(n)):
            if n[k] != n[len(n) - k - 1]:
                Mal = True
                break
        if not Mal:
            print(n)
            break
        nn = 0
        d = 1
        for k in range(len(n)):
            nn += (int(n[k]) + int(n[len(n) - k - 1])) * d
            d *= 10
        n = nn
    i += 1