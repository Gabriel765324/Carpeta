n = int(input("Dé el número entero no negativo.\n"))
if n < 0:
    print(":(")
else:
    print("La respuesta es", str(n * (n + 1) * (2 * n + 1) // 6) + ".")