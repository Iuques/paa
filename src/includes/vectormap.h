#ifndef VECTORMAP_H
#define VECTORMAP_H

#include "entry.h"

typedef struct VectorMap {
    Entry* entries;
    int size;
    int capacity;
} VectorMap;

VectorMap* buildVectorMap();

void addEntryVectorMap(VectorMap* map, char* name, int value);

void doubleCapacityNowPlusUltraMegaBlasterVectorMap(VectorMap* map);

Entry* searchEntryVectorMap(VectorMap* map, char* name);

void removeEntryVectorMap(VectorMap* map, char* name);

#endif