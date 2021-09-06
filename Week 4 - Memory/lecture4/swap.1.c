#include <stdio.h>

void swap(int a, int b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y); // calling swap function
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// THIS WONT WORK BECAUSE WE ARE JUST COPYING THE VALUES IN NEW PIECES OF MEMORY. WE NEED TO POINT a AND b TO THE ADDRESS OF x ADN y.

// SWAP NEED TO GO TO THE ORIGINAL ADDRESSES. SO a AND b SHOULD BE POINTERS (8 bytes of memory each)