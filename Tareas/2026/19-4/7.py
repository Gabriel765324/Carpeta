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
print("Porcentaje de niños:", str(len(n) / Total) + "%.")
print("Porcentaje de adolescentes:", str(len(a) / Total) + "%.")
print("Porcentaje de adultos:", str(len(A) / Total) + "%.")
print("Porcentaje de adultos mayores:", str(len(AM) / Total) + "%.")
print("Edad(es) de niños:", n)
print("Edad(es) de adolescentes:", a)
print("Edad(es) de adultos:", A)
print("Edad(es) de adultos mayores:", AM)