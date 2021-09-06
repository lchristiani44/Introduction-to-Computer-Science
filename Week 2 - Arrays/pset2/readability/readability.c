#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string Text;
    Text = get_string("Text: ");

    int length = strlen(Text);

    int letters = 0;

    for (int i = 0; i < length; i++)
    {
        if( ( (int) Text[i] >= 65 && (int) Text[i] <= 90) || ( (int) Text[i] >= 97 && (int) Text[i] <= 122) )

        letters += 1;

    }

    int words = 1;

    for (int i = 0; i < length; i++)
    {
        if ( (int) Text[i] == 32 && (int) Text[i + 1] >= 33 && (int) Text[i + 1] <= 126 )

        words += 1;

    }

    printf("%i Word(s)\n", words);

    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        if ( (int) Text[i] == 33 || (int) Text[i] == 46 || (int) Text[i] == 63)

        sentences += 1;

    }

    float L = 100 * letters / words;

    float S = 100 * sentences / words;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    printf("Index %f: \n", index);

    int rounded_index = round(index);

    if (index < 1)

        printf("Before Grade 1\n");

        else if(index >= 16)

            printf("Grade 16+\n");

        else

            printf("Grade %i\n", rounded_index);

}
