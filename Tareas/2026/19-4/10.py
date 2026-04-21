x = int(input("Dé el número.\n"))
s = ""
while x > 0:
    if x % 2 == 1:
        s = "1" + s
    else:
        s = "0" + s
    x //= 2
print(s)