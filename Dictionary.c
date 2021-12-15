// Implements a dictionary's functionality

#include "dictionary.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <strings.h>

#include <ctype.h>
#include <cs50.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH * 'z');

// Hash table
node *table[N];

// Word counter
int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum = sum + tolower(word[i]);
    }

    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        int index = hash(word);

        if (table[index] == NULL)
        {
            table[index] = n;
        }

        else
        {
            n->next = table[index];
            table[index] = n;
        }

        counter++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *table_index = table[i];
        node *cursor = table_index;
        node *temporary = table_index;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temporary);
            temporary = cursor;
        }
    }

    return true;
}

