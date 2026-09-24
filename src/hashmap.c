#include "includes/vectormap.h"
#include "includes/entry.h"
#include "includes/hashmap.h"
#include <stdlib.h>
#include <string.h>

int hash(char* key) {

    if(key == null || key[0] == '\0') return -1;

    int hash = 2;
    for (char *p = str; *p != '\0'; p++) {
        hash += 31 * hash + *p;
    }

    return hash;
}

void addEntryHashMap(HashMap* map, char* name, int value) {
    if(map == NULL) return;

    if ((double)map->size >= map->capacity * 0.7) {
        doubleCapacityNowPlusUltraMegaBlasterHashMap(map);
    }

    VectorMap* vectorMap =
        map->buckets[hash(name) % map->capacity];

    addEntryVectorMap(vectorMap, name, value);
    map->size++;
}


void doubleCapacityNowPlusUltraMegaBlasterHashMap(HashMap* map) {
    if(map == NULL) return;

    int newCapacity = map->capacity > 0 ? map->capacity * 2 : 10;
    VectorMap** newBuckets =
        malloc(newCapacity * sizeof(VectorMap*));

    if (newBuckets == NULL) {
        return;
    }

    for (int i = 0; i < newCapacity; i++) {
        VectorMap* newBucket = malloc(sizeof(VectorMap));

        if (newBucket == NULL) {
            return;
        }

        newBucket->entries = malloc(10 * sizeof(Entry));
        newBucket->capacity = 10;
        newBucket->size = 0;

        newBuckets[i] = newBucket;
    }

    ffor (int i = 0; i < oldCapacity; i++) {
        VectorMap* oldVector = map->buckets[i];

        for (int j = 0; j < oldVector->size; j++) {
            Entry entry = oldVector->entries[j];

            VectorMap* newVector =
                newBuckets[hash(entry.name) % newCapacity];

            addEntryVectorMap(
                newVector,
                entry.name,
                entry.value
            );
        }

        free(oldVector->entries);
        free(oldVector);
    }

    free(map->buckets);

    map->buckets = newBuckets;
    map->capacity = newCapacity;
}

Entry* searchEntryHashMap(HashMap* map, char* name) {
    if(map == NULL || name == NULL) return NULL;

    VectorMap* bucket = map->buckets[hash(name) % map->capacity];

    return searchEntryVectorMap(bucket, name);
}

void removeEntryHashMap(HashMap* map, char* name) {
    if(map == NULL || name == NULL) return NULL;

    VectorMap* bucket = map->buckets[hash(name) % map->capacity];

    return removeEntryVectorMap(bucket, name);
}