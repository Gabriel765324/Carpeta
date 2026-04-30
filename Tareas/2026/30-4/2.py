o = input("¿Qué operación hará?\n")
x = float(input("¿Cuál es la cantidad de radianes?\n"))
v = 0
if o.lower() == "cos":
    for i in range(22):
        cx = x ** (2 * i)
        for j in range(i * 2):
            cx /= j + 1
        v += ((-1) ** i) * cx
    print(v)
if o.lower() in ["sin", "sen"]:
    for i in range(22):
        cx = x ** (2 * i + 1)
        for j in range(i * 2 + 1):
            cx /= j + 1
        v += ((-1) ** i) * cx
    print(v)