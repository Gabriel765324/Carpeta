a = int(input("Escribe un año.\n"))
bisiesto = a % 400 == 0 or (a % 4 == 0 and a % 100 != 0)
print(bisiesto)