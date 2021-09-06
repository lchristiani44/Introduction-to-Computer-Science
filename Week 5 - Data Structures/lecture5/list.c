#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (void)
{
    node *list = NULL; // IF WE DON'T ASSIGN A VALUE LIKE NULL THEN IS GARBAGE MEMORY. THIS IS NOT RECOMMENDED FOR POINTERS.

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n->number = 1;
    n->next = NULL;
    list = n; // THE LIST POINT AT VALUE n.

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n->number = 2;
    n->next = NULL;
    list->next = n; // this is to store the address of the new node n!

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next) // the loop point at the first point in the list and keeps updating into the next field until reach NULL.
    {
        printf("%i\n", tmp->number);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp; // tmp variable to look one step ahead to make sure not to free memory too soon!
    }

}