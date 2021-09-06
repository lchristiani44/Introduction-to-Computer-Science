#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card_number;
    card_number = get_long("Card number: ");

    // VISA
    long x = (card_number - card_number % 1000000000000) / 1000000000000;
    long y = (card_number - card_number % 1000000000000000) / 1000000000000000;
    if(x == 4 || y == 4)
    {
        // Tarjeta de 13 digitos
        if(x == 4)
        {
            int aa = card_number % 10;
            long xa = (card_number - aa) / 10;
            int ab = xa % 10;
            long xb = (xa - ab) / 10;
            // Repetir segun digitos de la tarjeta
            // Hacer el calculo
            // Imprimir VISA si cumple, sino INVALID
            printf("%i\n", aa);
            printf("%i\n", ab);
            printf("VISA\n");
        }
        // Tarjeta de 16 digitos
        else if(y == 4)
        // En este caso es necesario porque VISA puede tener 13 o 16 digitos
        {

        }
    }

    // AMEX
    long w = (card_number - card_number % 10000000000000) / 10000000000000;
    if(w == 34 || w == 37)
    {
        printf("AMEX\n");
    }

    // MASTERCARD
    long z = (card_number - card_number % 100000000000000) / 100000000000000;
    if(z == 51 || z == 52 || z == 53 || z == 54 || z == 55)
    {
        printf("MASTERCARD\n");
    }

    // INVALID
    if(x != 4 && y != 4 && w != 34 && w != 37 && z != 51 && z != 52 && z != 53 && z != 54 && z != 55)
    {
        printf("INVALID\n");
    }
}