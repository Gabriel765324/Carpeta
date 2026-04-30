a = 25000000
b = 19900000
i = 0
d = 50
m = d
while i < d + 1:
    p = (i + d) // 2
    if a * (1.02 ** p) < b * (1.03 ** p):
        d = p - 1
        m = p
    else:
        i = p + 1
    print(i, d, p, m)
print(f"La ciudad B superará a la ciudad A en algún momento de {m + 2022}.")