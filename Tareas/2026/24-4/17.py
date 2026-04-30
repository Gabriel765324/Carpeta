n = int(input("Dé un número.\n"))
s = 0
for i in range(1, n):
    s += i * int(n % i == 0)
if s == n:
    print("Perfecto.")
else:
    print("No perfecto.")