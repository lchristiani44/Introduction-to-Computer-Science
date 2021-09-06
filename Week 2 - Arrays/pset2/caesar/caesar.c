#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
// funcion atoi() para convertir string en int

int main(int argc, string argv[])
// argv[0] is ./caesar and argv[1] is the key
// usar la funcion isdigit()
{
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argc == 2 && !isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else if (argc == 2)
    {

        int k = atoi(argv[1]) % 26;

        string plaintext = get_string("plaintext: ");

        int ciphertext[strlen(plaintext)];

        for(int i = 0; i < strlen(plaintext); i++)
        {

            if (islower(plaintext[i]))
                // conviene usar la funcion isalpha(), isupper() and islower()
            {
                ciphertext[i] = (int) plaintext[i] + k;

                if (islower((char) ciphertext[i]))
                {
                    ciphertext[i] = ciphertext[i];
                }

                else
                {
                    ciphertext[i] = (int) plaintext[i] + k - 26;
                }

            }

            else if (isupper(plaintext[i]))
            {
                ciphertext[i] = (int) plaintext[i] + k;

                if (isupper((char) ciphertext[i]))
                {
                    ciphertext[i] = ciphertext[i];
                }

                else
                {
                    ciphertext[i] = (int) plaintext[i] + k - 26;
                }
            }

            else
            {

                ciphertext[i] = (int) plaintext[i];
            }

        }

        printf("\nciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", (char) ciphertext[i]);
        }

        printf("\n");
        return 0;
    }

}