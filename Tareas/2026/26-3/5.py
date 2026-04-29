a = input("Dé la lista.\n").split()
M = int(a[0])
m = int(a[0])
for x in a:
    if int(x) < m:
        m = int(x)
    if int(x) > M:
        M = int(x)
print("Menor:", str(m) + ".\nMayor:", str(M) + ".")