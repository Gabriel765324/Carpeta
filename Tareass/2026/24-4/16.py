import secrets
n = secrets.randbelow(51)
print("Estoy pensando un número entre 0 y 50.")
i = 0
d = 50
for x in range(1, 6):
    v = float((input("Intento " + str(x) + ".\n").split())[1])
    if float(n) == v:
        print("Felicidades, adivinaste el número.")
        exit(0)
    if v > n:
        d = v
    else:
        i = v
    print("El número está entre", i, "y", str(d) + ".")
print("Fallaste, el número era", str(n) + ".")