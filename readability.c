#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string tekst = get_string("Text: ");
    int slowa = 0, litery = 0, zdania = 0;

    for (int i = 0, n = strlen(tekst); i < n; i++)
    {
        if ((tekst[i] >= 65 && tekst[i] <= 90) || (tekst[i] >= 97 && tekst[i] <= 122))
        {
            litery++;
        }
        else if (tekst[i] == 32)
        {
            slowa++;
        }
        else if (tekst[i] == 33 || tekst[i] == 63 || tekst[i] == 46)
        {
            if (i == n - 1)
            {
                slowa++;
            }
            zdania++;
        }
    }

    float L = 100 * (float) litery / (float) slowa;
    float S = 100 * (float) zdania / (float) slowa;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}