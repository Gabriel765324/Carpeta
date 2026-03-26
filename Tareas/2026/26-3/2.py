s = input("Dé la palabra.\n")
b = input("Dé una letra.\n")
r = 0
if len(b) != 1:
    print(":(")
else:
    for x in s:
        r += int(x == b)
    print("Hay", r, "copia(s) de", b, "en la palabra.")