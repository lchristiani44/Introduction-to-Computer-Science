#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    printf("%p\n", s); // s is just a var pointing (pointer )to the first char of string s!
    printf("%p\n", t); // t is just a var pointing (pointer )to the first char of string t!
}