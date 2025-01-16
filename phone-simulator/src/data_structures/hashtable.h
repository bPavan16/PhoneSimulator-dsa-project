#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Entry
{
    char *key;
    void *value;
    struct Entry *next;
} Entry;

typedef struct Hashtable
{
    Entry **entries;
} Hashtable;

Hashtable *create_table();
void free_table(Hashtable *table);
unsigned int hash(const char *key);
void insert(Hashtable *table, const char *key, void *value);
void *search(Hashtable *table, const char *key);
void delete(Hashtable *table, const char *key);

#endif // HASHTABLE_H