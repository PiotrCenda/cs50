// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5618;

// Hash table
node *table[N];
int dict_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int i = hash(word);

    node *cursor = table[i];

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
    char litery[2];
    litery[0] = tolower(word[0]);
    litery[1] = tolower(word[1]);

    if (strlen(word) < 3)
    {
        return 0;
    }
    else if (strlen(word) > 10)
    {
        return 5617;
    }
    else
    {
        int i, j;
        i = (int) litery[0] - 97;
        j = (int) litery[1];
        if (j != 39)
        {
            j = j - 96;
        }
        else
        {
            j = 27;
        }

        return (strlen(word) - 3) * 702 + i * 27 + j;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file_pointer = fopen(dictionary, "r");

    if (file_pointer == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char current_word[LENGTH + 1];

    while (fscanf(file_pointer, "%s", current_word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, current_word);
        n->next = NULL;

        unsigned int i = hash(current_word);

        if (table[i] != NULL)
        {
            n->next = table[i];

        }

        table[i] = n;

        dict_size++;
    }

    fclose(file_pointer);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = table[i];

            while (cursor != NULL)
            {
                node *tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }

        }
    }

    return true;
}
