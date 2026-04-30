for i in range(8):
    for j in range(i + 2):
        print(j + 1, end = "")
    for j in range(i + 1, 0, -1):
        print(j, end = "")
    print("")