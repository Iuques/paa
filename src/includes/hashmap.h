#ifndef HASHMAP_H
#define HASHMAP_H

#include "vectormap.h"

typedef struct HashMap {
    VectorMap** buckets;
    int size;
    int capacity;
} HashMap;

HashMap* buildHashMap();

int hash(char* key);

void addEntryHashMap(HashMap* map, char* name, int value);

void doubleCapacityNowPlusUltraMegaBlasterHashMap(HashMap* map);

Entry* searchEntryHashMap(HashMap* map, char* name);

void removeEntryHashMap(HashMap* map, char* name);

#endif