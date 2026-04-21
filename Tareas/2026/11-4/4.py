x = float(input("Dé x.\n"))
x /= 10
if x - float(int(x)) >= 0.5:
    x = int(x + 1)
else:
    x = int(x)
x *= 10
for i in range(x, -1, -10):
    print(i, end = " ")