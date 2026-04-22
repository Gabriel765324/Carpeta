s = input("Dé el número en binario.\n")
x = 0
Dos = 1
for i in range(len(s)):
    if s[len(s) - i - 1] not in ["0", "1"]:
        print("No es binario.")
        exit(0)
    if s[len(s) - i - 1] == "1":
        x += Dos
    Dos *= 2
print(x)