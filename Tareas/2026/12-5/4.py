def Contar(a, x) -> int:
    c = 0
    for i in a:
        c += int(float(i) == x)
    return c
if __name__ == "__main__":
    print(Contar(input("Dé la lista separada por espacios.\n").split(), float(input("¿Qué número se debe buscar?\n"))))