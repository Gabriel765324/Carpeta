Promedios = [0, 0, 0, 0]
Promedio = 0
for i in range(4):
    for j in range(7):
        Promedios[i] += float(input(f"Dé la venta número {j + 1} de la semana número {i + 1}.\n")) / 7
    Promedio += Promedios[i] / 4
print(f"Los promedios por semana son {Promedios} y el promedio diario es {Promedio}.")