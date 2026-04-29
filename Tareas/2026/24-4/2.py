a = int(input("Dé un número.\n"))
b = int(input("Dé un número.\n"))
if a % b == 0 or b % a == 0:
    print("Uno es múltiplo del otro.")
else:
    print("Ninguno es múltiplo del otro.")