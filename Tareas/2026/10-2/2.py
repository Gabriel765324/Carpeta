a = input("Escribe el nombre del primer producto.\n")
b = float(input("Escribe el precio por kilogramo del primer producto.\n"))
c = float(input("Escribe la cantidad de kilogramos que compraste del primer producto.\n"))
d = input("Escribe el nombre del segundo producto.\n")
e = float(input("Escribe el precio por kilogramo del segundo producto.\n"))
f = float(input("Escribe la cantidad de kilogramos que compraste del segundo producto.\n"))
g = input("Escribe el nombre del tercer producto.\n")
h = float(input("Escribe el precio por kilogramo del tercer producto.\n"))
i = float(input("Escribe la cantidad de kilogramos que compraste del tercer producto.\n"))
t1 = max(len(a), len(d), len(g), len("Nombre")) + 1
t2 = max(len(str(b)), len(str(e)), len(str(h)), len("Precio por kilogramo")) + 1
t3 = max(len(str(c)), len(str(f)), len(str(i)), len("Cantidad de kilogramos comprada")) + 1
print("Nombre" + (" " * (t1 - len("Nombre"))) + "Precio por kilogramo" + (" " * (t2 - len("Precio por kilogramo"))) + "Cantidad de kilogramos comprada" + (" " * (t3 - len("Cantidad de kilogramos comprada"))) + "Precio")
print(a + (" " * (t1 - len(a))) + str(b) + (" " * (t2 - len(str(b)))) + str(c) + (" " * (t3 - len(str(c)))) + str(b * c))
print(d + (" " * (t1 - len(d))) + str(e) + (" " * (t2 - len(str(e)))) + str(f) + (" " * (t3 - len(str(f)))) + str(e * f))
print(g + (" " * (t1 - len(g))) + str(h) + (" " * (t2 - len(str(h)))) + str(i) + (" " * (t3 - len(str(i)))) + str(h * i))
print((" " * (t1 + t2 + t3 - 6)) + "Total " + str(b * c + e * f + h * i))