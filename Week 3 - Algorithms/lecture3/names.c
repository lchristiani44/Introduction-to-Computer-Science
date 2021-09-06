#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"}; // ordenados alfabeticamente

    for (int i = 0; i < 7; i++) // WE KNOW IN ADVANCE THAT THERE ARE 7 NAMES
    {
        // IN C WE CAN'T USE == TO COMPARE STRINGS. WE CAN DO IT FOR INTS AND CHARS.

        // WE CAN USE get_string SO THE USER CAN CHOOSE THE NAME HE WANT TO FIND.

        if (strcmp(names[i], "Ron") == 0) // STR COMPARE USING ASCII. THE STRING NEEDS TO BE EQUAL LETTER BY LETTER.
                                          // WE NEED TO COMPARE THE VALUE THAT WE RECIEVE FROM strcmp. 0 MEANS MATCH.
        {
            printf("Found\n");
            return 0; // COMMAND TO QUITE/EXIT THE PROGRAM THAT WORKS CORRECTLY
        }
    }
    printf("Not found\n");
    return 1; // EXIT THE PROGRAM AND RETURN FALSE (ANY OTHER VALUE DIFFERENT THAT 0)
}