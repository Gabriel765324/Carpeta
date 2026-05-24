def Factorial(n) -> int:
    if n < 0:
        return 2222 / 0
    if n in [1, 0]:
        return 1
    return Factorial(n - 1) * n
if __name__ == "__main__":
    print(Factorial(int(input("Dé el número.\n"))))