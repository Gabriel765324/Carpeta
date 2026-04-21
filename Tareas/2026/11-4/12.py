n = int(input("Dé n.\n"))
v0 = 0
v1 = 0
v2 = 0
v3 = 0
v4 = 0
v5 = 0
for i in range(0, n):
    print(v0, end = " ")
    if i == 0:
        v1 = -4
    if i == 1:
        v2 = 16
    if i == 2:
        v3 = -52
    if i == 3:
        v4 = 160
    if i == 4:
        v5 = -484
    v4 += v5
    v3 += v4
    v2 += v3
    v1 += v2
    v0 += v1