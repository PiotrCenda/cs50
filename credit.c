#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int suma, sumap, dlugosc, poczatek, a;
    long numer, temp;
    numer = get_long("Number: ");
    temp = numer;
    dlugosc = 0;
    sumap = 0;
    suma = 0;

    while (numer > 0)
    {
        dlugosc++;
        numer = numer / 10;
    }

    numer = temp;

    for (a = 0; a < dlugosc; a++)
    {
        if (a == dlugosc - 2)
        {
            poczatek = numer;
        }

        if (a % 2 == 1)
        {
            if (numer % 10 > 4)
            {
                suma = suma + 1 + (numer % 5) * 2;
            }
            else
            {
                suma += (numer % 10) * 2;
            }
        }
        else
        {
            suma += numer % 10;
        }
        numer = numer / 10;
    }

    if ((dlugosc == 15 || dlugosc == 16 || dlugosc == 13) && suma % 10 == 0)
    {
        if (dlugosc == 15 && (poczatek == 34 || poczatek == 37))
        {
            printf("AMEX\n");
        }
        else if (poczatek / 10 == 4 && (dlugosc == 13 || dlugosc == 16))
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
