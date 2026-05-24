def Criba(n) -> str:
    a = [True] * (n + 1)
    s = ""
    a[0] = False
    a[1] = False
    for i in range(n + 1):
        if a[i] == True:
            s += str(i) + " "
            j = i * i
            while j <= n:
                a[j] = False
                j += i
    if a[n]:
        print("Primo.")
    else:
        print("No primo.")
    return s
if __name__ == "__main__":
    print(Criba(int(input("Dé el número.\n"))))