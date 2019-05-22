#include "cii/mem.h"
#include "redblackbst.h"
#include <stdio.h>

int
key_compare_func (void *x, void *y)
{
    if (*(int *) x < *(int *) y)
        return -1;
    else if (*(int *) x > *(int *) y)
        return 1;
    else
        return 0;
}

int
main (void)
{
    int    i;
    int    size;
    int    n_letters = 5;
    char * letters   = "abcde";
    char * c;
    int    keys[] = { 0, 1, 2, 3, 4 };
    void **tree_keys;

    RedBlackBST tree = redblackbst_new (&key_compare_func);
    for (i = 0; i < n_letters; i++) {
        redblackbst_put (tree, (keys + i), (letters + i));
    }

    size = redblackbst_size (tree);
    printf ("there are %i keys in tree\n", size);
    for (i = 0; i < n_letters; i++) {
        c = redblackbst_get (tree, &i);
        printf ("k=%i, v=%c\n", i, *c);
    }

    tree_keys = Mem_calloc (size, sizeof (void *), __FILE__, __LINE__);
    redblackbst_keys (tree, tree_keys);
    printf ("the keys are:\n");
    for (i = 0; i < size; i++) {
        printf ("%i\n", *(int *) *(tree_keys + i));
    }

    Mem_free (tree_keys, __FILE__, __LINE__);
    redblackbst_free (tree);

    return 0;
}
