s = input("Dé el nombre de la institución.\n").split()
for i in s:
    if ord(i[0]) >= ord("A") and ord(i[0]) <= ord("Z"):
        print(i[0], end = "")