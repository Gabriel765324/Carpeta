Saldo = 2
while Saldo > 0:
    Retiro = float(input("Da el valor a retirar.\n"))
    Saldo -= Retiro
    if Saldo < 0:
        print("No se puede.")
    else:
        print("Se pudo.")