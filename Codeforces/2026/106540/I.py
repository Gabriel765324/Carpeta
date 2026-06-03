def Junto(s: str) -> bool:
    if s.isdecimal():
        return True
    if s in "{} ^_":
        return True
    if s.isalpha():
        return True
    return False
def Resolver(s: str) -> bool:
    #print(s)
    n = len(s)
    if s[0] == " " or s[n - 1] == " ":
        #print("Espacios extra.")
        return False
    Especiales = "!?.,;$#^{}_=+* "
    for i in s:
        if i not in Especiales and not i.isalnum():
            #print("Caracter no válido.")
            return False
    for i in range(1, n - 1):
        if s[i] == " " and " " in (s[i - 1] + s[i + 1]):
            #print("Espacios seguidos.")
            return False
        if s[i].isdecimal() and (not Junto(s[i - 1]) or not Junto(s[i + 1])):
            #print(f"Número entre caracteres no válidos {i} {s[i]}.")
            return False
        if s[i] == "0" and s[i + 1].isdecimal() and not s[i - 1].isdecimal():
            #print("0 a la izquierda.")
            return False
    if n >= 2 and s[0] == "0" and s[1].isdecimal():
        #print("0 a la izquierda.")
        return False
    a = s.split()
    for x in a:
        Validar = ""
        Empezar = [False] * (len(x) + 4)
        for i in range(len(x)):
            if Empezar[i] and not x[i].isdecimal() and x[i] != "}":
                #print("Exponente o lo que sea que se llame lo otro que no es número.")
                return False
            if Empezar[i] and x[i] == "{":
                #print("Empezar llaves entre llaves.")
                return False
            if Empezar[i] and x[i] != "}":
                Validar += x[i]
            if x[i] == "{" and (i == 0 or x[i - 1] not in "^_"):
                #print("Llave sin _ o ^.")
                return False
            if x[i] in "_^":
                if i == len(x) - 1:
                    #print("Empezar _ o ^ al final.")
                    return False
                if x[i + 1] != "{":
                    #print("_ o ^ sin llaves.")
                    return False
                if len(Validar) > 0:
                    #print("Validar no está vacío y se está empezando _ o ^.")
                    return False
                j = i - 1
                while True:
                    if j < 0:
                        break
                    if x[j] == " ":
                        break
                    if not x[j].isalnum():
                        #print("La cadena antes de _ o ^ no es válida.")
                        return False
                    j -= 1
                Empezar[i + 2] = True
            if x[i] == "}" and Empezar[i] == False:
                #print("Cerrar llaves sin empezar.")
                return False
            if x[i] == "}":
                Empezar[i] = False
                if not Validar.isdecimal():
                    #print(f"Cadena entre llaves no válida. {x} {i} {x[i]} {Validar}")
                    return False
                if "." in Validar or "," in Validar:
                    #print("Cadena entre llaves con decimales.")
                    return False
                Validar = ""
            if Empezar[i]:
                Empezar[i + 1] = True
        if len(Validar) > 0:
            #print("Cadena entre llaves sin terminar.")
            return False
    return True
if __name__ == "__main__":
    n = int(input())
    Bien = True
    for i in range(n):
        #print(i)
        if not Resolver(input()):
            print("Validation failed")
            exit(0)
    print("Ok")