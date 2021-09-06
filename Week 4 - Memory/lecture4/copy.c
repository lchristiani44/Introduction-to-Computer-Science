#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1); // how many bytes of memory do you want to ask the computer for?

    if (t == NULL) // NULL REPRESENTS THE ABSENCE OF ADDRESS.
    {
        return 1; // IF A PROGRAM REQUIRE A LOT OF MEMORY, WE NEED TO BE SURE THAT t HAS A VALID ADDRESS.
    }

    int n = strlen(s);

    for (int i = 0; i <= n; i++) // i <= n because of \0 (null character).
    {
        t[i] = s[i]; //equivalent to write *(t + i) = *(s + 1)
    }

    t[0] = toupper(t[0]); // or *t = topper(*t)

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); // FREE MEMORY TO REUSE SPACE. TAKES AS INPUT WHATEVER THE OUTPUT OF malloc WAS.
}