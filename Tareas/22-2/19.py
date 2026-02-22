a = float(input("Dé el precio.\n"))
if a >= 200:
    a *= 0.85
    d = 15
elif a > 100:
    a *= 0.88
    d = 12
elif a < 100:
    a *= 0.9
    d = 10
else:
    d = 0
print("El costo es", a, "bolivianos y el descuento es", str(d) + "%.")