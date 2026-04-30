n = int(input("Dé un número.\n"))
print("*" * n)
for i in range(1, n - 1):
    print("*" + " " * (n - 2) + "*")
if n > 1:
    print("*" * n)