#include <cs50.h>
#include <stdio.h>

int main(void) // MAIN FUNCTION ALWAYS RETURN AN INTEGER
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0}; // no need to specify the size of the array
    //linear search
    for (int i = 0; i < 7; i++) // WE KNOW IN ADVANCE THAT THERE ARE 7 NUMBERS
    {
        if (numbers[i] == 0)
        {
            printf("Found\n");
            return 0; // COMMAND TO QUITE/EXIT THE PROGRAM THAT WORKS CORRECTLY
        }
    }
    printf("Not found\n");
    return 1; // EXIT THE PROGRAM AND RETURN FALSE (ANY OTHER VALUE DIFFERENT THAT 0)
}