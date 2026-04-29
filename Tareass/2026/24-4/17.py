n = int(input("Dé un número.\n"))
s = 0
for i in range(1, n):
    if n % i == 0:
        s += i
if s == n:
    print("Perfecto.")
else:
    print("No perfecto.")