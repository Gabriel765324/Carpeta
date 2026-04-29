Promedio = 0
n = 0
Notas = 2
while Notas >= 0:
    Notas = float(input("Da la nota.\n"))
    Promedio += Notas
    n += 1
print((Promedio - Notas) / (n - 1), "es el promedio.")