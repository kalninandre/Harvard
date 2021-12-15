def main():

    # Calls the function that gets the card number
    card_number = get_card_number()

    # Converts the card number to a string that will be used later in the code to define the card flag
    card_flag = str(card_number)

    # Some important local variables that will store both sum values
    sum_pairs = 0
    sum_odds = 0

    for i in range(0, len(card_number)):

        last_digit = (int(card_number) % 10)
        card_number = (int(card_number) / 10)

        if (i % 2 != 0):
            last_digit = last_digit * 2

            if last_digit >= 10:
                result = 0

                for digit in str(last_digit):
                    result += int(digit)

                sum_odds += result

            else:
                sum_odds += int(last_digit)

        elif (i % 2 == 0):
            sum_pairs += int(last_digit)

    sum_total = sum_pairs + sum_odds

    # Checks if the last digit of total sum is equal to 0
    if (sum_total % 10) == 0:

        if card_flag[0:2] in ['34', '37'] and (len(card_flag) == 15):
            print('AMEX')

        elif (card_flag[0] == '4') and (len(card_flag) in [14, 16]):
            print('VISA')

        elif (card_flag[0] == '5') and (card_flag[1] in ['1', '2', '3', '4', '5']) and (len(card_flag) == 16):
            print('MASTERCARD')

        else:
            print('INVALID')

    else:
        print('INVALID')


def get_card_number():

    while True:
        n = str(input('Number: '))

        if n.isnumeric():
            if int(n) > 0:
                break
    return n


if __name__ == '__main__':
    main()