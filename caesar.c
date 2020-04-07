#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string s = argv[1], slowo;
    int key = atoi(s), n = strlen(s), pom;

    for (int i = 0; i < n; i++)
    {
        if (s[i] < 48 || s[i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    slowo = get_string("plaintext:  ");
    n = strlen(slowo);
    printf("ciphertext: ");

    for (int i = 0; i < n; i++)
    {
        if (slowo[i] >= 65 && slowo[i] <= 90)
        {
            pom = (slowo[i] - 65 + key) % 26;
            printf("%c", 65 + pom);
        }

        else if (slowo[i] >= 97 && slowo[i] <= 122)
        {
            pom = (slowo[i] - 97 + key) % 26;
            printf("%c", 97 + pom);
        }

        else
        {
            printf("%c", slowo[i]);
        }
    }

    printf("\n");
    return 0;
}