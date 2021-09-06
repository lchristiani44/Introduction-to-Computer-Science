#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int cents;
    int rest;
    int q=25;
    int d=10;
    int n=5;
    int p=1;
    do
    {
        dollars=get_float("Change owed:");
        cents=round(dollars*100);
    }
    while(dollars<=0);

    if(cents>=q)
    {
        rest=cents%q;
        if(rest==0)
        {
            int qcoins=cents/q;
            printf("%i\n", qcoins);
        }
        else if(rest>=10)
        {
            int qcoins=(cents-rest)/q;
            int rest2=rest%d;
            if(rest2==0)
            {
                int dcoins=rest/d;
                printf("%i\n", qcoins+dcoins);
            }
            else if(rest2>=5)
            {
                int dcoins=(rest-rest2)/d;
                int rest3=rest2%n;
                if(rest3==0)
                {
                    int ncoins=rest2/n;
                    printf("%i\n", qcoins+dcoins+ncoins);
                }
                else if(rest3>=1)
                {
                    int ncoins=(rest2-rest3)/n;
                    int pcoins=rest3;
                    printf("%i\n", qcoins+dcoins+ncoins+pcoins);
                }
            }
            else if(rest2<5)
            {
                int dcoins=(rest-rest2)/d;
                int pcoins=rest2;
                printf("%i\n",qcoins+dcoins+pcoins);
            }
        }
        else if(5<=rest&&rest<10)
        {
            int qcoins=(cents-rest)/q;
            int rest2=rest%n;
            if(rest2==0)
            {
                int ncoins=rest/n;
                printf("%i\n", qcoins+ncoins);
            }
            else
            {
                int pcoins=rest-rest2;
                printf("%i\n", qcoins+1+pcoins);
            }
        }
        else if(rest<5)
        {
            int qcoins=(cents-rest)/q;
            int pcoins=rest;
            printf("%i\n", qcoins+pcoins);
        }
    }
    if(d<=cents&&cents<q)
    {
        rest=cents%d;
        if(rest==0)
        {
            int dcoins=cents/d;
            printf("%i\n", dcoins);
        }
        else if(rest>=5)
        {
            int dcoins=(cents-rest)/d;
            int rest2=rest%n;
            if(rest2==0)
            {
                int ncoins=rest/n;
                printf("%i\n", dcoins+ncoins);
            }
            else
            {
                printf("%i\n", 2+rest2);
            }
        }
        else if(rest<5)
        {
            int dcoins=(cents-rest)/d;
            printf("%i\n", dcoins+rest);
        }
    }
    if(n<=cents&&cents<d)
    {
        rest=cents%n;
        printf("%i\n",1+rest);
    }
    if(cents<n)
    {
        printf("%i\n",cents);
    }
}