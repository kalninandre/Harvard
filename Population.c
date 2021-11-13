#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 1;

    while (n <= 8)
    {
        n = get_int("What's the population size number? \n");
    }

    int end = get_int("What's the expected population size? \n");

    while (end < n)
    {
        end = get_int("What's the expected population size? \n");
    }

    int year = 0;

    if (n == end)
    {
        printf("Years: %i \n", year);
    }

    else
    {
        while (n < end && n != end)
        {

            int gain = (n / 3);
            int loss = (n / 4);

            n = (n + gain - loss);

            year++;

        }

        printf("Years: %i\n", year);

    }

}