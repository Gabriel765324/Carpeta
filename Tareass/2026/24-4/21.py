p = 0
for i in range(25):
    e = int(input("Dé la edad.\n"))
    if e < 1 or e > 3:
        print("Fuera de rango.\n")
        exit(0)
    p += 6 // e
print(p)