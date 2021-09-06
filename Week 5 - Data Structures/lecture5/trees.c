#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right; // both are a pointer to a struct node
}
node;

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number) // -> follow the pointer of tree
    {
        return search(tree->left, number);
    }
    else if (number > tree->number) // -> follow the pointer of tree
    {
        return search(tree->right, number);
    }
    else if (number == tree->number) // also works JUST else!
    {
        return true;
    }
}