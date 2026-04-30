Promedios = [0, 0, 0]
for i in range(3):
    for j in range(5):
        Promedios[i] += float(input(f"Dé la temperatura número {j + 1} de la ciudad número {i + 1}.\n")) / 5
print(f"Los promedios de temperaturas por ciudad son {Promedios}.")