#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int player_score(string word);

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word_player_1 = get_string("Player 1: ");
    string word_player_2 = get_string("Player 2: ");

    // Computes players score
    int score_player_1 = player_score(word_player_1);
    int score_player_2 = player_score(word_player_2);

    // Defines a win or tie
    if (score_player_1 > score_player_2)
    {
        printf("Player 1 Wins!\n");
    }

    else if (score_player_1 < score_player_2)
    {
        printf("Player 2 Wins!\n");
    }

    else
    {
        printf("Tie!\n");
    }
}

// Validates the string and computes the score
int player_score(string word)
{
    int sum = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Transmutes all words to lowercase
        word[i] = tolower(word[i]);

        int letter_value = POINTS[(word[i] - 97)];

        if (word[i] >= 'a' && word[i] <= 'z')
        {
            sum += letter_value;
        }
    }
    return sum;
}