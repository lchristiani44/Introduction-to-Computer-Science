#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main (void)
{
    char *s = get_string("s: ");

    char *t = s; // HERE WE ARE COPYING THE ADDRESS. IS THIS THE RIGHT WAY TO COPY ONE STRING INTO ANOTHER?

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}