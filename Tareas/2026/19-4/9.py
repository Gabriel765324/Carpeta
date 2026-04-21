s = input("Dé el número en binario.\n")
x = 0
Dos = 1
Bien = True
for i in range(len(s)):
    if s[len(s) - i - 1] not in ["0", "1"]:
        Bien = False
        print("No es binario.")
        break
    if s[len(s) - i - 1] == "1":
        x += Dos
    Dos *= 2
if Bien:
    print(x)