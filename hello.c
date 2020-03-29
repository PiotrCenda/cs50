#include <stdio.h>
#include <cs50.h>
int main(void)
{
    string imie;
    imie = get_string("Twoje imie to: ");
    printf("hello, %s\n", imie);
}
