n = int(input("Dé el número.\n"))
if n <= 0 or n > 9999:
    print("Fuera de rango.")
    exit(0)
s = ""
Lista = [["I̅X̅", "V̅I̅I̅I̅", "V̅I̅I̅", "V̅I̅", "V̅", "I̅V̅", "MMM", "MM", "M", ""], ["CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", ""], ["XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X", ""], ["IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I", ""]]
p = 3
while n > 0:
    s = Lista[p][9 - n % 10] + s
    p -= 1
    n //= 10
print(s)