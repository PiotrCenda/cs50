#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string s = argv[1], slowo;
    int n = strlen(s), pom;

    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    for(int k = 0; k < n; k++)
    {
        if ((s[k] < 65 || s[k] > 90) && (s[k] < 97 || s[k] > 122))
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
            pom = slowo[i] - 65;
            printf("%c", toupper(s[pom]));
        }

        else if (slowo[i] >= 97 && slowo[i] <= 122)
        {
            pom = slowo[i] - 97;
            printf("%c", tolower(s[pom]));
        }

        else
        {
            printf("%c", slowo[i]);
        }
    }

    printf("\n");
    return 0;
}