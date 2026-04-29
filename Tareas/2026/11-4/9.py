n = int(input("Dé n.\n"))
s = float(0)
for i in range(0, n):
    s += (i + 1) ** (-1)
print("La suma es", str(s) + ".")