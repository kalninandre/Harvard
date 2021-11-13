#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
    int height = get_height();

    int i = 1;

    while (i <= height)
    {
        int dot = (height - i);

        while (dot > 0)
        {
            printf(" ");
            dot--;
        }

        int line_right = 1;

        while (line_right <= i)
        {
            printf("#");
            line_right++;
        }

        printf("  ");

        int line_left = 1;

        while (line_left <= i)
        {
            printf("#");
            line_left++;
        }

        i++;
        printf("\n");
    }

}

int get_height(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

