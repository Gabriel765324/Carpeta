print("  ", end = "")
for i in range(1, 11):
    if i < 10:
        print("   ", i, end = "")
    else:
        print("  ", i)
for i in range(1, 11):
    if(i == 10):
        print(i, end = " ")
    else:
        print("", i, end = " ")
    for j in range(1, 11):
        print(" " * (3 - len(str(i * j))), i * j, end = " ")
    print("")