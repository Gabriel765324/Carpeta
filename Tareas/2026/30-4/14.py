Lista = [1]
n = int(input("Dé un número.\n"))
for i in range(n):
    print(Lista)
    Nuevo = [1]
    for i in range(len(Lista)):
        Nuevo.append(Lista[i])
        if i + 1 < len(Lista):
            Nuevo[len(Nuevo) - 1] += Lista[i + 1]
    Lista = Nuevo.copy()