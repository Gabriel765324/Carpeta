m = 0
a = 0
pe = 0
pa = 0
n = int(input("Dé el número de alumnos.\n"))
for i in range(n):
    Edad = float(input("Dé la edad.\n"))
    Altura = float(input("Dé la altura en centímetros.\n"))
    pe += Edad / n
    pa += Altura / n
    if Edad > 18:
        m += 1
    if Altura > 1.75:
        a += 1
print(f"Edad promedio: {pe}.\nAltura promedio: {pa}.\nMayores de 18 años: {m}.\nMiden más que 1.75 centímetros: {a}.")