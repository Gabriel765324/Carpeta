a = int(input("Dé el inicio.\n"))
b = int(input("Dé el final.\n"))
a += a % 2
for x in range(a, b + 1, 2):
    print(x)