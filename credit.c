#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int suma, sumap, suman, dlugosc, poczatek;
    long numer, temp;
    numer = get_long("Number: ");
    temp = numer;
    dlugosc = 0;
    sumap = 0;
    suman = 0;

    while (numer > 0)
    {
        dlugosc++;

        if (dlugosc % 2 == 0)
        {
            sumap += numer % 10;
        }
        else
        {
            suman += numer % 10;
        }

        numer = numer / 10;
    }

    poczatek = temp / (10 * (dlugosc - 2));

    if (dlugosc % 2 == 0)
    {
        suma = sumap + suman * 2;
    }
    else
    {
        suma = suman + sumap * 2;
    }

    if ((dlugosc == 15 || dlugosc == 16 || dlugosc == 13) && suma % 10 == 0)
    {
        if (dlugosc == 15 && (poczatek == 34 || poczatek == 37))
        {
            printf("AMEX\n");
        }
        else if (poczatek % 10 == 4 && (dlugosc == 13 || dlugosc == 16))
        {
            printf("VISA\n");
        }
        else if (dlugosc == 16 && (poczatek == 51 || poczatek == 52 || poczatek == 53 || poczatek == 54 || poczatek == 55))
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

    return 0;
}
