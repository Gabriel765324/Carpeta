s = float(100)
for i in range(0, 24):
    print(s, end = " ")
    if i % 2 == 1:
        s -= 20
    else:
        s *= 1.05
print("\nNo lo logró.")