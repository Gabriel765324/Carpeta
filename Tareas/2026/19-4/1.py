print("Celsius  Farenheit")
for x in range(0, 101, 10):
    print(str(x) + " °C " + (" " * (4 - len(str(x)))), str(x * 9 // 5 + 32) + " °F")