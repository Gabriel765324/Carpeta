def Contar(s) -> int:
    c = 0
    for i in s:
        if i in "aoeui":
            c += 1
    return c
if __name__ == "__main__":
    print(Contar(input("Dé un palabra.\n")))