a = int(input("Dé un número.\n"))
if a < 0:
    a += a % 2
    for x in range(a, 1, 2):
        print(x)
else:
    for x in range(0, a + 1, 2):
        print(x)