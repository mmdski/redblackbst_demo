#ifndef CHARTABLE_INCLUDED
#define CHARTABLE_INCLUDED

typedef struct CharTable *CharTable;

extern CharTable
chartable_new (void);

extern void
chartable_free (CharTable table);

extern void
chartable_put (CharTable table, int key, char value);

extern char
chartable_get (CharTable table, int key);

extern void
chartable_delete (CharTable table, int key);

extern int
chartable_size (CharTable table);

extern int *
chartable_keys (CharTable table);

#endif
