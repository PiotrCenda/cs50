#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int wys = 0;
    do{
        wys = get_int("Height: ");
    }while(wys>8 || wys<1);

    int i, j, k;

    for(i=1; i<wys+1; i++)
    {
        for(j=0; j<(wys*2); j++)
        {
            if((j>=wys-i && j<=wys) || (j<=wys+i-1 && j>=wys))
            {
                printf("#");
            }
            else if(j!=wys-1)
            {
                printf(" ");
            }
            if(j==wys-1)
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
