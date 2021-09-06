#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    else if (argc == 2)
    {
        //SOLO PARA CORROBORAR EL ALGORITMO
        for (int i = 0; i < 26; i++)
        {
        printf("%i-", (int) argv[1][i]);
        }

        printf("\n");//

        int key_lowercases[26];

        int key_uppercases[26];

        for (int i = 0; i < 26; i++)
        {
            if (islower(argv[1][i]))
            {
                key_lowercases[i] = (int) argv[1][i];
                key_uppercases[i] = (int) argv[1][i] - 32;
            }

            else if (isupper(argv[1][i]))
            {
                key_lowercases[i] = (int) argv[1][i] + 32;
                key_uppercases[i] = (int) argv[1][i];
            }
        }

        //SOLO PARA CORROBORAR EL ALGORITMO
        for (int i = 0; i < 26; i++)
        {
            printf("%i-", key_lowercases[i]);
        }

        printf("\n");

        for (int i = 0; i < 26; i++)
        {
            printf("%i-", key_uppercases[i]);
        }

        printf("\n");//

        string plaintext = get_string("plaintext: ");

        int new_plaintext[strlen(plaintext)];

        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (islower(plaintext[i]))
            {
                new_plaintext[i] = (int) plaintext[i] - 97;
            }

            else if (isupper(plaintext[i]))
            {
                new_plaintext[i] = (int) plaintext[i] - 65;
            }

            else
            {
                new_plaintext[i] = (int) plaintext[i];
            }

        }

        //SOLO PARA CORROBORAR EL ALGORITMO
        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%i-", new_plaintext[i]);
        }

        printf("\n");//

        int ciphertext[strlen(plaintext)];

        for (int i = 0; i < strlen(plaintext); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (!isalpha(plaintext[i]))
                {
                    ciphertext[i] = new_plaintext[i];
                }

                else if (isupper(plaintext[i]) && new_plaintext[i] == j)
                {
                    ciphertext[i] = key_uppercases[j];
                }

                else if (islower(plaintext[i]) && new_plaintext[i] == j)
                {
                    ciphertext[i] = key_lowercases[j];
                }

            }
        }

        printf("ciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", (char) ciphertext[i]);
        }

        printf("\n");

        return 0;
    }
}