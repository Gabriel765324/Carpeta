def Intersecci_n(a, b) -> list:
    r = []
    for x in a:
        if x in b and x not in r:
            r.append(x)
    return r
if __name__ == "__main__":
    print(Intersecci_n(input("Dé la lista separada por espacios.\n").split(), input("Dé la segunda lista separada por espacios.\n").split()))