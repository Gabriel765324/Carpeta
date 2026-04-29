x = int(input("Dé x.\n"))
while x > 5:
    print(x, end = " ")
    s = x // 2 + 3
    if s == x:
        x = -22
    else:
        x = s