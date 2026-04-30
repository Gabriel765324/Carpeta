Fechas = input("Dé la primera fecha.\n") + "/" + input("Dé la segunda fecha.\n")
Lista = [["", "", ""], ["", "", ""]]
i = 0
for x in Fechas:
    if x in "/-":
        i += 1
    else:
        Lista[i // 3][i % 3] += x
print(f"La diferencia en días es {int(Lista[1][0]) + int(Lista[1][1]) * 30 + int(Lista[1][2]) * 30 * 12 - int(Lista[0][0]) - int(Lista[0][1]) * 30 - int(Lista[0][2]) * 30 * 12}.")