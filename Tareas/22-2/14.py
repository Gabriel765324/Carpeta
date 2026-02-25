r = float(input("Dé el rendimiento.\n"))
d = float(input("Dé la distancia recorrida.\n"))
v = float(input("Dé el precio da cada galón en dólares.\n"))
if r <= 20 or r >= 40 or d <= 5000 or d >= 10000 or v <= 6 or v >= 7:
    print("Algún dato no está en el rango especificado por el enunciado.")
    exit(0)
print("El rendimiento en kilómetros por litro es de", r / 2.352, "y costó", ((r * 1.60934 * (d ** -1)) ** -1) * v * 6.96, "bolivianos con el cambio oficial.")