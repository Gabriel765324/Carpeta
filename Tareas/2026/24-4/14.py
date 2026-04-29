n = int(input("Dé el número de gallinas.\n"))
s = 0
for i in range(n):
    p = float(input("¿Cuál es el peso?\n"))
    a = float(input("¿Cuál es la altura?\n"))
    h = float(input("¿Cuántos huevos puso?\n"))
    s += p * a / h / n
print("La calidad promedio es", str(s) + ".")