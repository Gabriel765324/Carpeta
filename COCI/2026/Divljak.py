n = int(input())
a = []
Respuestas = []
Rango = range(n)
for i in Rango:
    s = input()
    a.append(s)
    Respuestas.append(0)
q = int(input())
while q > 0:
    Consulta = input().split()
    if Consulta[0] == "1":
        for i in Rango:
            if a[i] in Consulta[1]:
                Respuestas[i] += 1
    else:
        print(Respuestas[int(Consulta[1]) - 1])
    q -= 1