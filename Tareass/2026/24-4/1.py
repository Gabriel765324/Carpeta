a = float(input("¿Cuál es el término cuadrático?\n"))
b = float(input("¿Cuál es el término lineal?\n"))
c = float(input("¿Cuál es el término independiente?\n"))
b *= -1
if b ** 2 - 4 * a * c < 0:
    print("Las soluciones son complejas.")
else:
    print((b + (b ** 2 - 4 * a * c) ** 0.5) / 2 / a, (b - (b ** 2 - 4 * a * c) ** 0.5) / 2 / a)