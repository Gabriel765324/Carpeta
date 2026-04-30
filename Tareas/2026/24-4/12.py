p = float(input("Dé el precio.\n"))
d = float(input("Dé la cantidad de dinero entregada.\n"))
p -= d
p *= 10
r = 0
a = [50, 10, 5, 2, 1]
for i in a:
    r += p // i
    p %= i
if p > 0:
    print("No se puede.")
else:
    print(int(r))