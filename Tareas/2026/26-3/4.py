a = input("Dé la lista.\n").split()
s = float(0)
for x in range(len(a)):
    s += int(a[x])
print("La suma es", str(s) + ".")