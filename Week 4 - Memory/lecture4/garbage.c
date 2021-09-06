#include <stdio.h>

int main (void)
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", scores[i]); // HERE WE DON'T INITIALIZE THE VALUES FOS SCORES SO THE PROGRAM WILL RETURN RANDOM VALUES.
    }
}