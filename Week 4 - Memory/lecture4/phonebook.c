#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); // FILE (MAYUS) is a data type in c that represents a file. 'a': append (add) mode to open the file
    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number); // fprintf PRINT TO A FILE (in this case, phonebook.csv), NOT TO A SCREEN LIKE printf (the first argument is the pointer to the file)

    fclose(file);
}