#include <cs50.h>
#include <stdio.h>
#include <ctype.h> // isalpha, islower, isupper, tolower, toupper functions
#include <string.h> // strlen function

// Points assigned to each letter of the alphabet

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score1(string word1);

int compute_score2(string word2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score1(word1); // ABAJO SE DESARROLLA ESTA FUNCION. RECORDAR SIEMPRE 'LLAMARLA' ANTES.
    int score2 = compute_score2(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Score 1: %i\n", score1);
        printf("Score 2: %i\n", score2);
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Score 1: %i\n", score1);
        printf("Score 2: %i\n", score2);
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Score 1: %i\n", score1);
        printf("Score 2: %i\n", score2);
        printf("Tie!\n");
    }
}

int compute_score1(string word1)
{
    // TODO: Compute and return score for string
    int total1 = 0;
    for (int i = 0; i < strlen(word1); i++) // Barrido letra por letra de la palabra
    {
        char c = word1[i];
        if (!isalpha(c))
        {
            int posicion = tolower(c) - 'a';
            total1 += POINTS[posicion]; // LA FUNCION get_index ASIGNA A CADA LETRA DE LA PALABRA LA UBICACION QUE LE CORRESPONDE EN POINTS[]. EJEMPLO: SE ASIGNA 0 (POSICION 1) PARA A y 2 (POSICION 3) PARA C.
        }
        else
        {
            total1 += 0;
        }
    }
    return total1;
}

int compute_score2(string word2)
{
    // TODO: Compute and return score for string
    int total2 = 0;
    for (int i = 0; i < strlen(word2); i++) // Barrido letra por letra de la palabra
    {
        char c = word2[i];
        if (!isalpha(c))
        {
            total2 += POINTS[tolower(c) - 'a']; // LA FUNCION get_index ASIGNA A CADA LETRA DE LA PALABRA LA UBICACION QUE LE CORRESPONDE EN POINTS[]. EJEMPLO: SE ASIGNA 0 (POSICION 1) PARA A y 2 (POSICION 3) PARA C.
        }
        else
        {
            total2 += 0;
        }
    }
    return total2;
}