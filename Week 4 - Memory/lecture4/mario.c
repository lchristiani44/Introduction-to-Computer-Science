#include <stdio.h>
#include <cs50.h>

void draw(int h);

int main (void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int h)
{
    if (h == 0)
    {
        return; // TO AVOID draw FUNCTION CALL ITSELF SEVERAL TIMES AND GET A SEGMENTATION FAULT.
    }

    draw(h - 1);

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}