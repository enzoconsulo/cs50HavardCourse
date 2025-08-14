from cs50 import get_float

change = -1
while change < 0:
    change = get_float("Change owed: ")

change = round(change*100)

for i in [25,10,5,1]:
    if change >= i:
        quantity = change // i
        print(f"{i/100} : {quantity}")
        change -= quantity * i
