def Separar(a) -> list:
    A = []
    R = []
    for i in a:
        if float(i) >= 51:
            A.append(i)
        else:
            R.append(i)
    print(f"Hay {len(A)} aprobado(s) y {len(R)} reprobado(s).")
    return [A, R]
if __name__ == "__main__":
    a = Separar(input("Dé la lista separada por espacios.\n").split())
    print(f"Notas de aprobado(s): {a[0]}.")
    print(f"Notas de reprobado(s): {a[1]}.")