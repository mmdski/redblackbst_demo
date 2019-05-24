#include "chartable.h"
#include "cii/mem.h"
#include <stdio.h>

void
print_items (CharTable table);

void
print_message (CharTable table);

void
free_table (CharTable table);

int
main (void)
{
    int i;
    int index[] = { 10, 1, 0, 9, 2, 3, 7, 4, 8, 6, 11, 5 };
    int n_chars = 12;

    /*           11 */
    /* 012345678901 */
    /* hello world! */
    char message[] = { 'd', 'e', 'h', 'l', 'l', 'l',
                       'o', 'o', 'r', 'w', '!', ' ' };

    int  over_items = 5;
    int  over_idx[] = { 6, 7, 8, 9, 10 };
    char over_msg[] = { 't', 'o', 'o', 't', 's' };

    int del_items = 6;
    int del_idx[] = { 9, 6, 5, 8, 10, 7 };

    CharTable table = chartable_new ();

    for (i = 0; i < n_chars; i++) {
        chartable_put (table, index[i], message[i]);
    }

    print_items (table);
    print_message (table);

    for (i = 0; i < over_items; i++) {
        chartable_put (table, over_idx[i], over_msg[i]);
    }

    print_items (table);
    print_message (table);

    for (i = 0; i < del_items; i++) {
        chartable_delete (table, del_idx[i]);
    }

    print_items (table);
    print_message (table);

    chartable_delete (table, 4);
    chartable_put (table, 3, 'p');
    chartable_put (table, 9, 'e');
    chartable_put (table, 5, ' ');
    chartable_put (table, 7, 'm');

    print_items (table);
    print_message (table);

    free_table (table);

    return 0;
}

void
print_items (CharTable table)
{
    int  i;
    int  k;
    int  size;
    char v;
    int *keys;

    size = chartable_size (table);
    keys = chartable_keys (table);
    printf ("n = %i\n", size);
    for (i = 0; i < size; i++) {
        k = keys[i];
        v = chartable_get (table, k);
        printf ("k = %i\tv = %c\n", k, v);
    }
    Mem_free (keys, __FILE__, __LINE__);
}

void
print_message (CharTable table)
{
    int  i;
    int  size;
    int *keys;
    char c;

    size = chartable_size (table);
    keys = chartable_keys (table);
    for (i = 0; i < size; i++) {
        c = chartable_get (table, keys[i]);
        printf ("%c", c);
    }
    printf ("\n");
    Mem_free (keys, __FILE__, __LINE__);
}

void
free_table (CharTable table)
{
    int  i;
    int *keys;
    int  size;

    size = chartable_size (table);
    keys = chartable_keys (table);
    for (i = 0; i < size; i++) {
        chartable_delete (table, keys[i]);
    }
    chartable_free (table);
    Mem_free (keys, __FILE__, __LINE__);
    table = NULL;
}
