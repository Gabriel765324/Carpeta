n = int(input("Dé el número de obreros.\n"))
t = float(input("¿Cuánto es la tarifa?\n")) * 0.95
p = 0
for i in range(n):
    h = float(input("¿Cuántas horas trabajó?\n"))
    if h <= 40:
        p += h * t
        print("El pago es", str(h * t) + ".")
    else:
        p += (40 + (h - 40) * 2) * t
        print("El pago es", str((40 + (h - 40) * 2) * t) + ".")
print("Pago total:", p)
print("Dinero retenido:", p * 0.05 / 0.95)