def Contar(s) -> float:
    c = 0
    for i in s:
        c += float(i)
    return c
if __name__ == "__main__":
    n = int(input("¿Cuántos números quiere ingresar?\n"))
    print(Contar(input("Dé los números separados por espacios.\n").split()))