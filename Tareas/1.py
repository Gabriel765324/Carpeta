import DFS
a = int(input("Escribe el número de líneas que quieres recorrer.\n"))
b = input("¿Cuál es el color de la primera línea que vas a recorrer?\n")
c = input("¿Cuál es el color de la última línea que vas a recorrer?\n")
print(f"Para llegar de la línea {b} a la línea {c}, el costo del boleto será de: {3 + 2 * (a - 1)}.")