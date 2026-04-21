s = input("Dé la cadena.\n")
Bien = True
for i in range(len(s) // 2):
    Bien = Bien and s[i] == s[len(s) - i - 1]
if Bien:
    print("Es palíndroma.")
else:
    print("No es palíndroma.")