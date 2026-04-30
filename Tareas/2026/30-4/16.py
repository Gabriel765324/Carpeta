Promedios = [0, 0, 0, 0, 0]
for i in range(5):
    for j in range(3):
        Promedios[i] += float(input(f"Dé la nota número {j + 1} del estudiante número {i + 1}.\n")) / 3
print(f"Los promedios son {Promedios}.")