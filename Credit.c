#include <stdio.h>
#include <cs50.h>

long get_number(void);

long get_reverse_number(long card_number);

int main(void)
{
    long card_number = get_number();

    long reverse_card_number = get_reverse_number(card_number);
    int first_digit = (reverse_card_number % 10);
    int second_digit = ((reverse_card_number % 100) / 10);

    int last_digit;

    int i = 0;

    int sum_pairs = 0;
    int sum_odds = 0;
    int sum_total = 0;

    do
    {
    last_digit = (card_number % 10);

    card_number = (card_number / 10);

    if (i % 2 != 0)
    {
        last_digit = last_digit * 2;

        if (last_digit >= 10)
        {
            int memory = 0;

            for (int counter = 0; counter <= 2; counter++)
            {
            memory = last_digit % 10;
            sum_pairs += memory;
            last_digit /= 10;
            }
        }

        else
        {
            sum_pairs += last_digit;
        }
    }

    else
    {
        sum_odds += last_digit;
    }

    i++;

    }
    while (card_number != 0);

    sum_total = (sum_pairs + sum_odds);

    if (sum_total % 10 == 0)
    {
        if (first_digit == 3 && (second_digit == 4 || second_digit == 7) && i == 15)
        {
            printf("AMEX\n");
        }

        else if (first_digit == 4 && (i == 13 || i == 16))
        {
            printf("VISA\n");
        }

        else if (first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5) && i == 16)
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    long n;

    do
    {
        n = get_long("Number: ");
    }
    while (n <= 0);

    return n;
}

long get_reverse_number(long card_number)
{
   int last_digit_reverse;

   long inverse = 0;

    do
    {
        last_digit_reverse = card_number % 10;
        inverse = (inverse * 10) + last_digit_reverse;
        card_number /= 10;
    }
    while (card_number != 0);

    return inverse;
}