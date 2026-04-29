a = int(input("Dé un número.\n"))
b = int(input("Dé un número.\n"))
if a <= 0 or b <= 0:
    print("Fuera de rango.")
    exit(0)
s = 0
for i in range(b):
    s += a
print(s)