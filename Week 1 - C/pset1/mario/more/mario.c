#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Pyramid Size: ");
    }
    while(n<1||n>8);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i+j<=n)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for(int k=1;k<=n;k++)
        {
            if(i>=k)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
