Lista = [1, 0, 1, 0, 1, 0, -8, 27, -53, 63]
n = int(input("Dé un número.\n"))
Tomar = 0
if n <= 0:
    exit(0)
n -= 1
print(1, end = " ")
for i in range(n):
    for j in range(Tomar, -1, -1):
        Lista[j] += Lista[j + 1]
    Tomar += 1
    if Tomar >= 8:
        Tomar = 8
    print(Lista[0], end = " ")