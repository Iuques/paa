#include "includes/vectormap.h"
#include "includes/entry.h"
#include <stdlib.h>
#include <string.h>

void addEntryVectorMap(VectorMap* map, char* name, int value) {
    if(map == NULL) return;

    if(map->size == map->capacity) {
        doubleCapacityNowPlusUltraMegaBlasterVectorMap(map);
    }

    map->entries[map->size] = buildEntry(name, value);
    map->size++;
}


void doubleCapacityNowPlusUltraMegaBlasterVectorMap(VectorMap* map) {
    if(map == NULL) return;

    int newCapacity = map->capacity > 0 ? map->capacity * 2 : 10;
    Entry* newEntry = realloc(map->entries, newCapacity * sizeof(*newEntry));

    if(newEntry == NULL) return;

    map->entries = newEntry;
    map->capacity = newCapacity;
}

Entry* searchEntryVectorMap(VectorMap* map, char* name) {
    if(map == NULL || name == NULL) return NULL;

    for(int i = 0; i < map->size; i++) {
        if(strcmp(map->entries[i].name, name) == 0) {
            return &map->entries[i];
        }
    }

    return NULL;
}

void removeEntryVectorMap(VectorMap* map, char* name) {
    if(map == NULL || name == NULL) return;

    for(int i = 0; i < map->size; i++) {
        if(strcmp(map->entries[i].name, name) == 0) {
            for(int j = i; j < map->size - 1; j++) {
                map->entries[j] = map->entries[j + 1];
            }
            map->size--;
            return;
        }
    }
}