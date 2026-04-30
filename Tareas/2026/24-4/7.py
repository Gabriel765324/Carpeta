n = int(input("Dé la cantidad de ventas.\n"))
v = 0
d = 0
for i in range(n):
    k = float(input("Dé el valor de la venta.\n"))
    v += k
    if k < 100:
        d += k
    elif k >= 500:
        d += k * 0.92
    else:
        d += k * 0.95
print(f"Total: {v}.\nTotal con descuento: {d}.")