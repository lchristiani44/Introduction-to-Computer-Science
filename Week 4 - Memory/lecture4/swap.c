#include <stdio.h>

void swap(int *a, int *b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y); // calling swap function
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b; // GO TO a AND PUT WHATEVER IS AT b!
    *b = tmp;
}

// SWAP NEED TO GO TO THE ORIGINAL ADDRESSES. SO a AND b SHOULD BE POINTERS (8 bytes of memory each)