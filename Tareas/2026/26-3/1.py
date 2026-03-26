s = input("Dé la palabra.\n")
v = 0
a = ["a", "e", "i", "o", "u"]
for x in s:
    v += int(x in a)
print("Hay", v, "vocales.")