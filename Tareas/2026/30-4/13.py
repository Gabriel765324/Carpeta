n = int(input("Dé un número.\n"))
if n % 2 == 0:
    print("No es impar.\n")
    exit(0)
s = [" "] * n
Luego = []
cn = n // 2 + 1
ccn = n // 2
e = 0
for i in range(cn):
    s[ccn] = "*"
    s[ccn + e] = "*"
    Luego.append(s.copy())
    ccn -= 1
    e += 2
    for j in s:
        print(j, end = "")
    print("")
for i in range(len(Luego) - 2, -1, -1):
    for j in Luego[i]:
        print(j, end = "")
    print("")