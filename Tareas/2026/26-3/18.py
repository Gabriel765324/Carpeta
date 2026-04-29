n = int(input("Dé un número.\n"))
Bien = n > 1
for x in range(2, int(n ** 0.5) + 1):
    Bien = Bien and n % x != 0
if Bien:
    print("Primo.")
else:
    print("No primo.")