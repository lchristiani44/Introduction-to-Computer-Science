#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name; // FIELDS OF THE DATA TYPE
    string number;
}
person; // DATA TYPE NAME

int main(void)
{
    person people[2]; //SIZE OF THE ARRAY, QUANTITY OF NAMES or NUMBERS

    people[0].name = "Brian";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}