a = []
c = [0, 0, 0]
for i in range(20):
    x = int(input("Dé un número.\n"))
    if x > 0:
        c[2] += 1
    elif x == 0:
        c[1] += 1
    else:
        c[0] += 1
    a.append(x.copy())
print("Hay", c[0], "números negativos,", c[1], "números 0 y", c[2], "números positivos.")
a.sort()
print(a)