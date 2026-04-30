n = int(input("Dé el número de obreros.\n"))
t = float(input("¿Cuánto es la tarifa?\n")) * 0.95
p = 0
for i in range(n):
    h = float(input("¿Cuántas horas trabajó?\n"))
    if h <= 40:
        p += h * t
        print(f"El pago es {h * t}.")
    else:
        p += (40 + (h - 40) * 2) * t
        print(f"El pago es {(40 + (h - 40) * 2) * t}.")
print(f"Pago total: {p}.")
print(f"Dinero retenido: {p * 0.05 / 0.95}.")