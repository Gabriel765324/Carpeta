def Salida(n) -> str:
    s = ""
    for i in range(1, 13):
        s += f"{n} * {i} = {i * n}\n"
    return s
if __name__ == "__main__":
    print(Salida(int(input("Dé el número.\n"))))