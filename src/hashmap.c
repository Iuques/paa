#include "includes/hashmap.h"
#include <stdlib.h>
#include <string.h>

HashMap* buildHashMap(void) {
    HashMap* map = malloc(sizeof(HashMap));
    if (map == NULL) {
        return NULL;
    }

    map->capacity = 10;
    map->size = 0;
    map->buckets = calloc((size_t)map->capacity, sizeof(VectorMap*));

    if (map->buckets == NULL) {
        free(map);
        return NULL;
    }

    for (int i = 0; i < map->capacity; i++) {
        map->buckets[i] = buildVectorMap();
    }

    return map;
}

int hash(char* key) {
    if (key == NULL || key[0] == '\0') {
        return -1;
    }

    unsigned long hash_value = 5381;
    for (const unsigned char* p = (const unsigned char*)key; *p != '\0'; p++) {
        hash_value = ((hash_value << 5) + hash_value) + *p;
    }

    return (int)(hash_value & 0x7fffffffUL);
}

void addEntryHashMap(HashMap* map, char* name, int value) {
    if (map == NULL || name == NULL) {
        return;
    }

    if ((double)map->size >= map->capacity * 0.7) {
        doubleCapacityNowPlusUltraMegaBlasterHashMap(map);
    }

    VectorMap* vectorMap = map->buckets[hash(name) % map->capacity];
    if (vectorMap == NULL) {
        return;
    }

    Entry* existing = searchEntryVectorMap(vectorMap, name);
    if (existing != NULL) {
        existing->value = value;
        return;
    }

    addEntryVectorMap(vectorMap, name, value);
    map->size++;
}

void doubleCapacityNowPlusUltraMegaBlasterHashMap(HashMap* map) {
    if (map == NULL) {
        return;
    }

    int oldCapacity = map->capacity;
    int newCapacity = map->capacity > 0 ? map->capacity * 2 : 10;
    VectorMap** newBuckets = calloc((size_t)newCapacity, sizeof(VectorMap*));

    if (newBuckets == NULL) {
        return;
    }

    for (int i = 0; i < newCapacity; i++) {
        newBuckets[i] = buildVectorMap();
    }

    for (int i = 0; i < oldCapacity; i++) {
        VectorMap* oldVector = map->buckets[i];
        if (oldVector == NULL) {
            continue;
        }

        for (int j = 0; j < oldVector->size; j++) {
            Entry entry = oldVector->entries[j];
            VectorMap* newVector = newBuckets[hash(entry.name) % newCapacity];
            addEntryVectorMap(newVector, entry.name, entry.value);
        }

        free(oldVector->entries);
        free(oldVector);
    }

    free(map->buckets);
    map->buckets = newBuckets;
    map->capacity = newCapacity;
}

Entry* searchEntryHashMap(HashMap* map, char* name) {
    if (map == NULL || name == NULL || map->capacity <= 0) {
        return NULL;
    }

    VectorMap* bucket = map->buckets[hash(name) % map->capacity];
    if (bucket == NULL) {
        return NULL;
    }

    return searchEntryVectorMap(bucket, name);
}

void removeEntryHashMap(HashMap* map, char* name) {
    if (map == NULL || name == NULL || map->capacity <= 0) {
        return;
    }

    VectorMap* bucket = map->buckets[hash(name) % map->capacity];
    if (bucket == NULL) {
        return;
    }

    Entry* found = searchEntryVectorMap(bucket, name);
    if (found == NULL) {
        return;
    }

    removeEntryVectorMap(bucket, name);
    if (map->size > 0) {
        map->size--;
    }
}