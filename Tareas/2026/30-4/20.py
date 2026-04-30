Promedios = [0, 0, 0, 0, 0]
Promedio = 0
for i in range(5):
    for j in range(4):
        Promedios[i] += float(input(f"Dé el stock del producto número {i + 1} del almacén número {j + 1}.\n")) / 4
    Promedio += Promedios[i] / 5
print(f"Los promedios de stock por producto son {Promedios} y el promedio de stock por producto es {Promedio}.")