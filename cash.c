#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int wynik = 0;
    float zlote = get_float("Change owed: ");
    int grosze = round(zlote * 100);

    if (grosze >= 25)
    {
        wynik += grosze / 25;
        grosze = grosze % 25;
    }
    if (grosze >= 10)
    {
        wynik += grosze/10;
        grosze = grosze % 10;
    }
    if (grosze >= 5)
    {
        wynik += grosze / 5;
        grosze = grosze % 5;
    }
    
    wynik += grosze;

    printf("%i\n", wynik);

    return 0;
}

