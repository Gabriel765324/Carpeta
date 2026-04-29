Fechas = input("Dé la primera fecha.\n") + "/"
Fechas += input("Dé la segunda fecha.\n")
Lista = [["", "", ""], ["", "", ""]]
i = 0
j = 0
for x in Fechas:
    if x == "/":
        j += 1
        if j == 3:
            j = 0
            i += 1
    else:
        Lista[i][j] += x
i = int(Lista[0][0]) + int(Lista[0][1]) * 30 + int(Lista[0][2]) * 30 * 12
j = int(Lista[1][0]) + int(Lista[1][1]) * 30 + int(Lista[1][2]) * 30 * 12
print("La diferencia en días es", str(j - i) + ".")