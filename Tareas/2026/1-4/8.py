Saldo = float(input("Dé el saldo inicial.\n"))
while Saldo > 0:
    Retiro = float(input("Da el valor a retirar.\n"))
    Saldo -= Retiro
    if Saldo < 0:
        print("No se puede por falta de saldo.")
        Saldo += Retiro
    else:
        print("Se pudo hacer el retiro.")