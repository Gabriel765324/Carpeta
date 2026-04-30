a = int(input("Dé el dividendo.\n"))
b = int(input("Dé el divisor.\n"))
q = 0
if b == 0:
    print(":(")
    exit(0)
s = 0
e = 0
if a < 0:
    s += 1
    a = -a
    e = 1
if b < 0:
    s += 1
    b = -b
while a >= b:
    a -= b
    q += 1
print(f"Cociente: {q * ((-1) ** s)}.\nResiduo: {a * ((-1) ** e)}.")