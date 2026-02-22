e = float(input("Dé la edad.\n"))
p = float(input("Dé el promedio.\n"))
print("La beca es de", end = " ")
if e > 18:
    if p >= 9:
        print(2000, end = " ")
    elif p >= 7.5:
        print(1000, end = " ")
    elif p >= 6:
        print(500, end = " ")
    else:
        print(0, end = " ")
else:
    if p >= 9:
        print(3000, end = " ")
    elif p >= 8:
        print(2000, end = " ")
    elif p >= 6:
        print(100, end = " ")
    else:
        print(0, end = " ")
print("bolivianos.")