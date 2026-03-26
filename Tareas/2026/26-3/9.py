p = input("Dé la palabra.\n")
c = input("Dé la palabra por reemplazar.\n")
i = 0
for x in range(len(p)):
    if x >= i:
        if i + len(c) <= len(p) and p[i: i + len(c)] == c:
            print("*", end = "")
            i += len(c)
        else:
            print(p[x], end = "")
            i += 1