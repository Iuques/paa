#include "includes/vectormap.h"
#include <stdlib.h>
#include <string.h>

VectorMap* buildVectorMap(void) {
    VectorMap* map = malloc(sizeof(VectorMap));
    if (map == NULL) {
        return NULL;
    }

    map->capacity = 10;
    map->size = 0;
    map->entries = malloc((size_t)map->capacity * sizeof(Entry));

    if (map->entries == NULL) {
        free(map);
        return NULL;
    }

    return map;
}

void addEntryVectorMap(VectorMap* map, char* name, int value) {
    if (map == NULL || name == NULL) {
        return;
    }

    if (map->size == map->capacity) {
        doubleCapacityNowPlusUltraMegaBlasterVectorMap(map);
    }

    map->entries[map->size] = buildEntry(name, value);
    map->size++;
}

void doubleCapacityNowPlusUltraMegaBlasterVectorMap(VectorMap* map) {
    if (map == NULL) {
        return;
    }

    int newCapacity = map->capacity > 0 ? map->capacity * 2 : 10;
    Entry* newEntries = realloc(map->entries, (size_t)newCapacity * sizeof(Entry));

    if (newEntries == NULL) {
        return;
    }

    map->entries = newEntries;
    map->capacity = newCapacity;
}

Entry* searchEntryVectorMap(VectorMap* map, char* name) {
    if (map == NULL || name == NULL) {
        return NULL;
    }

    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->entries[i].name, name) == 0) {
            return &map->entries[i];
        }
    }

    return NULL;
}

void removeEntryVectorMap(VectorMap* map, char* name) {
    if (map == NULL || name == NULL) {
        return;
    }

    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->entries[i].name, name) == 0) {
            for (int j = i; j < map->size - 1; j++) {
                map->entries[j] = map->entries[j + 1];
            }
            map->size--;
            return;
        }
    }
}