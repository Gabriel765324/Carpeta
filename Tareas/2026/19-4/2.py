Per_metro = 0
Primero = True
x0 = 0
y0 = 0
xn = 0
yn = 0
while True:
    x = input("Dé la coordenada en x.\n")
    if len(x) == 0:
        Per_metro += ((x0 - xn) ** 2 + (y0 - yn) ** 2) ** 0.5
        break
    y = float(input("Dé la coordenada en y.\n"))
    x = float(x)
    if Primero:
        x0 = x
        y0 = y
        Primero = False
    else:
        Per_metro += ((x - xn) ** 2 + (y - yn) ** 2) ** 0.5
    xn = x
    yn = y
print("El perímetro total es", str(Per_metro) + ".")