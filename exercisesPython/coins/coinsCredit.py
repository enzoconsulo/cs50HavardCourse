def main():
    number = input("Number:")

    firstDigits = int(number[0]) * 10 + int(number[1])

    if(len(number) == 15 and (firstDigits == 34 or firstDigits == 37)):
        cardType = "American Express"
        valid = luhn(number)

    elif(len(number) == 13 and int(number[0]) == 4):
        cardType = "Visa"
        valid = luhn(number)

    elif(len(number) == 16):
        if(int(number[0]) == 4):
            cardType = "Visa"
            valid = luhn(number)
        elif(firstDigits in (51,52,53,54,55)):
            cardType = "Mastercard"
            valid = luhn(number)
        else:
            valid = False

    else:
        valid = False

    if(valid == False):
        cardType = "Invalid"

    print(cardType)



def luhn(card):
    tmp = 0
    sum = 0
    for i in range(len(card)-1 , 0 ,2):
        tmp = int(card[i]) * 2
        if(tmp >= 10):
            sum += tmp // 10
            sum += tmp % 10
        else:
            sum += tmp

    for i in range(len(card), 0, 2):
        sum += int(card[i])

    print(sum)
    if(sum % 10 == 0):
        return True
    else:
        return False

main()
