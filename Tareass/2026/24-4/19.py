a = int(input("Dé el dividendo.\n"))
b = int(input("Dé el divisor.\n"))
q = 0
if b == 0:
    print(":(")
    exit(0)
while a >= b:
    a -= b
    q += 1
print("Cociente:", q)
print("Residuo:", a)