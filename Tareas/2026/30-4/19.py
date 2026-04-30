Promedios = [0, 0, 0]
for i in range(3):
    for j in range(4):
        Promedios[i] += float(input(f"Dé el precio número {j + 1} de la sucursal número {i + 1}.\n")) / 4
print(f"Los promedios de precios por sucursal son {Promedios}.")