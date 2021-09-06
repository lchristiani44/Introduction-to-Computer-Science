#include <cs50.h>
#include <stdio.h>
#include <ctype.h> // isalpha, islower, isupper, tolower, toupper functions
#include <string.h> // strlen function

// Points assigned to each letter of the alphabet

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int get_index(char c);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1); // ABAJO SE DESARROLLA ESTA FUNCION. RECORDAR SIEMPRE 'LLAMARLA' ANTES.
    int score2 = compute_score(word2);

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

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int total = 0;
    for (int i = 0; i < strlen(word); i++) // Barrido letra por letra de la palabra
    {
        char c = word[i];
        if (!isalpha(c))
        {
            total += POINTS[get_index(c)]; // LA FUNCION get_index ASIGNA A CADA LETRA DE LA PALABRA LA UBICACION QUE LE CORRESPONDE EN POINTS[]. EJEMPLO: SE ASIGNA 0 (POSICION 1) PARA A y 2 (POSICION 3) PARA C.
        }
        else
        {
            total += 0;
        }
    }
    return total;
}

int get_index(char c) // tolower convierte mayusculas en minusculas!
{
    return tolower(c) - 'a'; // 'a' es lo mismo que poner 97. Se le asigna el valor a cada caracter de la palabra segun el orden alfabetico y el codigo ASCII. Ejemplo: para d(100) - a(97) = 3 (recodar que 3 significa posicion 4).
}