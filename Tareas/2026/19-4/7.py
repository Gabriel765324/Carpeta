n = []
a = []
A = []
AM = []
while True:
    x = int(input("Dé la edad.\n"))
    if x <= 0:
        break
    if 1 <= x and x <= 11:
        n.append(x)
    if 12 <= x and x <= 17:
        a.append(x)
    if 18 <= x and x <= 59:
        A.append(x)
    if x >= 60:
        AM.append(x)
Total = (len(n) + len(a) + len(A) + len(AM)) / 100
if Total == 0:
    Total += 1
print("Porcentaje de niños:", str(len(n) / Total) + "%.")
print("Porcentaje de adolescentes:", str(len(a) / Total) + "%.")
print("Porcentaje de adultos:", str(len(A) / Total) + "%.")
print("Porcentaje de adultos mayores:", str(len(AM) / Total) + "%.")
print("Edades de niños: ", n)
print("Edades de adolescentes: ", a)
print("Edades de adultos: ", A)
print("Edades de adultos mayores: ", AM)