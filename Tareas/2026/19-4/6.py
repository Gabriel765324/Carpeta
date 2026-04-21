a = []
c = [0, 0, 0]
for i in range(20):
    x = float(input("Dé un número.\n"))
    if x > 0:
        c[2] += 1
    elif x == 0:
        c[1] += 1
    else:
        c[0] += 1
    a.append(x)
print("Hay", c[0], "números negativos,", c[1], "números 0 y", c[2], "números positivos.")
for i in range(20):
    for j in range(19):
        if a[j] > a[j + 1]:
            Intercambiador = a[j]
            a[j] = a[j + 1]
            a[j + 1] = Intercambiador
print(a)