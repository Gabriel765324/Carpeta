a = input("Dé la lista.\n").split()
k = float(input("Dé el valor de referencia.\n"))
c = 0
for x in a:
    c += int(float(x) > k)
print("La respuesta es", str(c) + ".")