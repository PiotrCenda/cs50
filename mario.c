#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int wys = 0;

    do
    {
        wys = get_int("Height: ");
    }
    while(wys>8 || wys<1);

    int i, j;

    for(i = 0; i < wys; i++)
    {
        for(j = 0; j < wys + i + 1; j++)
        {
            if((j >= wys - i - 1 && j <= wys) || j >= wys)
            {
                printf("#");
            }
            else if(j != wys - 1)
            {
                printf(" ");
            }
            if(j == wys - 1)
            {
                printf("  ");
            }
        }
        
        printf("\n");
    }
}
