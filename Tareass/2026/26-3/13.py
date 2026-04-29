n = int(input("Dé el número entero no negativo.\n"))
if n < 0:
    print(":(")
else:
    f = 1
    for x in range(2, n + 1):
        f *= x
    print(str(n) + "! =", f)