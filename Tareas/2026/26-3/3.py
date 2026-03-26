s = input("Dé una palabra.\n")
for x in range(len(s)):
    print(s[len(s) - x - 1], end = "")