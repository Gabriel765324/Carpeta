n = int(input("Dé el número.\n"))
n = str(n)
s = 0
for i in n:
    if i == "-":
        continue
    s += ord(i)
s -= 48 * len(n)
i = 2
if s < 2:
    print("No.")
    exit(0)
while i * i <= s:
    if s % i == 0:
        print("No.")
        exit(0)
    i += 1
print("Sí.")