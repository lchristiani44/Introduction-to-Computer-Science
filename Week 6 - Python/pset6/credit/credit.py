from cs50 import get_string, get_int
import sys

card_number = get_string("Number: ")

if len(card_number) == 15:
    if int(card_number[0:2]) == 34 or int(card_number[0:2]) == 37:
        # digits1 = [None] * len(card_number) # [None] * k crea una lista de k elementos todos None
        digits1 = []

        for i in range(1, len(card_number), 2):
            # digits1[i] = int(card_number[i]) * 2
            digits1.append(int(card_number[i]) * 2)

        tmp = []
        for number in digits1:
            for digit in str(number):
                tmp.append(int(digit)) # to append the individual digits!

        sum1 = sum(tmp) # I should sum the individual digits!

        digits2 = []

        for i in range(0, len(card_number) + 1, 2):
            digits2.append(int(card_number[i]))

        sum2 = sum(digits2) # OK

        sum3 = sum1 + sum2
        if sum3 % 2 == 0:
            print("AMEX")
            sys.exit(0)

elif len(card_number) == 16:
    if int(card_number[0:2]) == 51 or int(card_number[0:2]) == 52 or int(card_number[0:2]) == 53 or int(card_number[0:2]) == 54 or int(card_number[0:2]) == 55:
        # digits1 = [None] * len(card_number) # [None] * k crea una lista de k elementos todos None
        digits1 = []

        for i in range(0, len(card_number), 2):
            # digits1[i] = int(card_number[i]) * 2
            digits1.append(int(card_number[i]) * 2)

        tmp = []
        for number in digits1:
            for digit in str(number):
                tmp.append(int(digit)) # to append the individual digits!

        sum1 = sum(tmp) # I should sum the individual digits!

        digits2 = []

        for i in range(1, len(card_number) + 1, 2):
            digits2.append(int(card_number[i]))

        sum2 = sum(digits2) # OK

        sum3 = sum1 + sum2
        if sum3 % 2 == 0:
            print("MASTERCARD")
            sys.exit(0)

    elif int(card_number[0]) == 4:
        # digits1 = [None] * len(card_number) # [None] * k crea una lista de k elementos todos None
        digits1 = []

        for i in range(0, len(card_number), 2):
            # digits1[i] = int(card_number[i]) * 2
            digits1.append(int(card_number[i]) * 2)

        tmp = []
        for number in digits1:
            for digit in str(number):
                tmp.append(int(digit)) # to append the individual digits!

        sum1 = sum(tmp) # I should sum the individual digits!

        digits2 = []

        for i in range(1, len(card_number) + 1, 2):
            digits2.append(int(card_number[i]))

        sum2 = sum(digits2) # OK

        sum3 = sum1 + sum2
        if sum3 % 2 == 0:
            print("VISA")
            sys.exit(0)

elif len(card_number) == 13:
    if int(card_number[0]) == 4:
        # digits1 = [None] * len(card_number) # [None] * k crea una lista de k elementos todos None
        digits1 = []

        for i in range(1, len(card_number), 2):
            # digits1[i] = int(card_number[i]) * 2
            digits1.append(int(card_number[i]) * 2)

        tmp = []
        for number in digits1:
            for digit in str(number):
                tmp.append(int(digit)) # to append the individual digits!

        sum1 = sum(tmp) # I should sum the individual digits!

        digits2 = []

        for i in range(0, len(card_number) + 1, 2):
            digits2.append(int(card_number[i]))

        sum2 = sum(digits2) # OK

        sum3 = sum1 + sum2
        if sum3 % 2 == 0:
            print("VISA")
            sys.exit(0)
else:
        print("INVALID")
        sys.exit(1)