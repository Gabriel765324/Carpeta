Aproximaci_n = 3
for x in range(15):
    print(str(x + 1) + "° aproximación: " + str(Aproximaci_n) + ".")
    Aproximaci_n = Aproximaci_n + ((-1) ** x) * 4 / ((2 * (x + 1)) * (2 * (x + 1) + 1) * (2 * (x + 1) + 2))