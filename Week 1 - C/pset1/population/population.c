#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);

    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < start_size);

    int years = 0;

    if (end_size > start_size)
    {
        do
        {
            start_size = start_size + round(start_size / 3) - round(start_size / 4);
            years += 1;
        }
        while (start_size <= end_size);
    }

    printf("Years: %i\n", years);
}