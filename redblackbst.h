#ifndef REDBLACKBST_INCLUDED
#define REDBLACKBST_INCLUDED
#include <stdbool.h>

typedef int (*KeyCompareFunc) (const void *x, const void *y);

typedef struct RedBlackBST *RedBlackBST;

typedef struct {
    void *key;
    void *value;
} Item;

extern RedBlackBST
redblackbst_new (KeyCompareFunc compare_func);

extern void
redblackbst_free (RedBlackBST tree);

extern void
redblackbst_free_item (Item *item);

extern int
redblackbst_size (RedBlackBST tree);

extern void *
redblackbst_min_key (RedBlackBST tree);

extern void *
redblackbst_max_key (RedBlackBST tree);

extern Item *
redblackbst_get (RedBlackBST tree, const void *key);

extern void
redblackbst_put (RedBlackBST tree, const void *key, void *value);

extern bool
redblackbst_contains (RedBlackBST tree, const void *key);

extern void
redblackbst_delete (RedBlackBST tree, const void *key);

extern void
redblackbst_keys (RedBlackBST tree, void **keys);

#endif
