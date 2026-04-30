n = int(input("Dé un número.\n"))
s = [" "] * (n * 2 - 1)
cn = n
n -= 1
e = 0
for i in range(cn):
    s[n] = "*"
    s[n + e] = "*"
    n -= 1
    e += 2
    for j in s:
        print(j, end = "")
    print("")