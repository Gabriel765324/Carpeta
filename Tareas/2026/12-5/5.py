def Menor(a) -> float:
    c = float(a[0])
    for i in a:
        if float(i) < float(c):
            c = float(i)
    return c
def Mayor(a) -> float:
    c = float(a[0])
    for i in a:
        if float(i) > float(c):
            c = float(i)
    return c
if __name__ == "__main__":
    a = input("Dé la lista separada por espacios.\n").split()
    print(Menor(a), Mayor(a))