p = input("Dé la palabra.\n")
Bien = True
for x in range(len(p) // 2):
    Bien = Bien and p[x] == p[len(p) - 1 - x]
if Bien:
    print("Palíndromo.")
else:
    print("No palíndromo.")