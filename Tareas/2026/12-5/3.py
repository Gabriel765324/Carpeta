def Validar(n) -> str:
    m = 0
    cn = n
    while cn > 0:
        m = 10 * m + cn % 10
        cn //= 10
    if n == m:
        return "Es capicúa."
    else:
        return "No es capicúa."
if __name__ == "__main__":
    print(Validar(int(input("Dé el número.\n"))))