height = input("What is the height: ")

intHeight = int(height)

for i in range(0, intHeight):
    print((intHeight - i + 1) * " ", end="")
    print((i + 1) * "#")
