n0 = input("Dé el primer nombre.\n")
n1 = input("Dé el segundo nombre.\n")
n2 = input("Dé el tercer nombre.\n")
e0 = float(input("Dé la primera edad.\n"))
e1 = float(input("Dé la segunda edad.\n"))
e2 = float(input("Dé la tercera edad.\n"))
m = e0
if e1 < m:
    m = e1
if e2 < m:
    m = e2
if m == e0 and m != e1 and m != e2:
    print(n0, e0)
elif m == e1 and m != e0 and m != e2:
    print(n1, e1)
elif m == e2 and m != e0 and m != e1:
    print(n2, e2)
else:
    print("Hay un empate.")