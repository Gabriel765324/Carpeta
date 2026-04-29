Lista = [0, 0, 0]
Lista[0] = float(input("Dé un número.\n"))
Lista[1] = float(input("Dé un número.\n"))
Lista[2] = float(input("Dé un número.\n"))
if Lista[0] == Lista[1] or Lista[1] == Lista[2] or Lista[2] == Lista[0]:
    print("No es válido.")
    exit(0)
for i in range(2):
    for j in range(1, 3):
        if Lista[j - 1] < Lista[j]:
            Lista[j] += Lista[j - 1]
            Lista[j - 1] = Lista[j] - Lista[j - 1]
            Lista[j] -= Lista[j - 1]
print(Lista)