c = int(input("Dé la clave.\n"))
m = float(input("Dé el costo de la materia prima.\n"))
if c < 1 or c > 6:
    print("No es una clave.")
    exit(0)
v = float(1)
if c == 1:
    v += 1.8 + 1.28
elif c == 2:
    v += 1.85 + 1.3
elif c == 3:
    v += 1.75 + 1.35
elif c == 4:
    v += 1.75 + 1.28
elif c == 5:
    v += 1.8 + 1.3
else:
    v += 1.85 + 1.35
v -= 2
v *= 1.45
print("El precio es", str(v * m) + ".")