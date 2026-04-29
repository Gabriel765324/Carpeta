i = int(input("Dé i.\n"))
x = int(input("Dé x.\n"))
while i <= x:
    print(i, end = " ")
    if i % 2 == 0:
        i += 1
    else:
        i *= 2
print(i)