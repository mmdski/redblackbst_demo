#include "chartable.h"
#include "cii/assert.h"
#include "cii/mem.h"
#include "redblackbst.h"

struct CharTable {
    RedBlackBST tree;
};

int
chartable_compare_key (const void *x, const void *y)
{
    int x_value = *(const int *) x;
    int y_value = *(const int *) y;

    if (x_value < y_value)
        return -1;
    else if (x_value > y_value)
        return 1;
    else
        return 0;
}

CharTable
chartable_new (void)
{
    CharTable table;
    NEW (table);
    table->tree = redblackbst_new (&chartable_compare_key);

    return table;
}

void
chartable_free (CharTable table)
{
    redblackbst_free (table->tree);
    FREE (table);
}

void
chartable_put (CharTable table, int key, char value)
{
    int * bst_key;
    char *bst_value = Mem_alloc (sizeof (char), __FILE__, __LINE__);

    *bst_value = value;

    Item *item = redblackbst_get (table->tree, &key);
    if (item) {
        bst_key = item->key;
        Mem_free (item->value, __FILE__, __LINE__);
        redblackbst_free_item (item);
    } else {
        bst_key  = Mem_alloc (sizeof (int), __FILE__, __LINE__);
        *bst_key = key;
    }

    redblackbst_put (table->tree, bst_key, bst_value);
}

char
chartable_get (CharTable table, int key)
{
    char  c;
    Item *item = redblackbst_get (table->tree, &key);
    c          = *(char *) item->value;
    redblackbst_free_item (item);
    return c;
}

void
chartable_delete (CharTable table, int key)
{
    if (!redblackbst_contains (table->tree, &key) ||
        chartable_size (table) == 0)
        return;
    Item *item = redblackbst_get (table->tree, &key);
    redblackbst_delete (table->tree, &key);
    Mem_free (item->key, __FILE__, __LINE__);
    Mem_free (item->value, __FILE__, __LINE__);
    redblackbst_free_item (item);
}

int
chartable_size (CharTable table)
{
    return redblackbst_size (table->tree);
}

int *
chartable_keys (CharTable table)
{
    int    i;
    int    size     = redblackbst_size (table->tree);
    int *  keys     = Mem_calloc (size, sizeof (int), __FILE__, __LINE__);
    void **bst_keys = Mem_calloc (size, sizeof (void *), __FILE__, __LINE__);

    redblackbst_keys (table->tree, bst_keys);

    for (i = 0; i < size; i++)
        *(keys + i) = *(int *) *(bst_keys + i);

    Mem_free (bst_keys, __FILE__, __LINE__);
    return keys;
}
