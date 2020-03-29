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
        for(j = 0; j < wys; j++)
        {
            if(j >= wys - i - 1)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        
        printf("\n");
    }
}
