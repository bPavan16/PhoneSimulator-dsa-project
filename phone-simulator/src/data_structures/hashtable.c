#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TABLE_SIZE 100

typedef struct Entry
{
    char *key;
    void *value;
    struct Entry *next;
} Entry;

typedef struct Hashtable
{
    Entry **table;
} Hashtable;

Hashtable *create_table()
{
    Hashtable *hashtable = malloc(sizeof(Hashtable));
    hashtable->table = malloc(sizeof(Entry *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

unsigned int hash(const char *key)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

void insert(Hashtable *hashtable, const char *key, void *value)
{
    unsigned int index = hash(key);
    Entry *new_entry = malloc(sizeof(Entry));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = hashtable->table[index];
    hashtable->table[index] = new_entry;
}

void *search(Hashtable *hashtable, const char *key)
{
    unsigned int index = hash(key);
    Entry *entry = hashtable->table[index];
    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

void delete(Hashtable *hashtable, const char *key)
{
    unsigned int index = hash(key);
    Entry *entry = hashtable->table[index];
    Entry *prev = NULL;
    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            if (prev == NULL)
            {
                hashtable->table[index] = entry->next;
            }
            else
            {
                prev->next = entry->next;
            }
            free(entry->key);
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

void free_table(Hashtable *hashtable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Entry *entry = hashtable->table[i];
        while (entry != NULL)
        {
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashtable->table);
    free(hashtable);
}