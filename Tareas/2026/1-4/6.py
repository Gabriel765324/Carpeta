a = 1
while a != 2.22222222:
    a = float(input("Adivina un número.\n"))
    if a != 2.22222222:
        if a < 2.22222222:
            print("Más alto.")
        else:
            print("Más bajo.")
print("Bien.")