print("Celsius  Farenheit")
for x in range(0, 101, 10):
    print(str(x) + (" " * (8 - len(str(x)))), x * 9 // 5 + 32)