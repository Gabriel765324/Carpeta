a = float(input("Escribe la nota del primer examen.\n"))
b = float(input("Escribe la nota del segundo examen.\n"))
c = float(input("Escribe la nota del tercer examen.\n"))
d = input("¿El usuario sabe python?\n")
aceptado = a > 50 and b >= 80 and c > 60 and d == "si"
reconsiderar = b >= 80 and d == "si" and not aceptado
print(aceptado, reconsiderar)