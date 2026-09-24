#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

int main(void) {
    HashMap* map = buildHashMap();
    assert(map != NULL);
    assert(map->size == 0);
    assert(map->capacity > 0);

    addEntryHashMap(map, "alpha", 10);
    addEntryHashMap(map, "beta", 20);
    addEntryHashMap(map, "gamma", 30);

    assert(map->size == 3);

    Entry* found = searchEntryHashMap(map, "beta");
    assert(found != NULL);
    assert(strcmp(found->name, "beta") == 0);
    assert(found->value == 20);

    assert(searchEntryHashMap(map, "missing") == NULL);

    removeEntryHashMap(map, "beta");
    assert(map->size == 2);
    assert(searchEntryHashMap(map, "beta") == NULL);

    addEntryHashMap(map, "alpha", 99);
    found = searchEntryHashMap(map, "alpha");
    assert(found != NULL);
    assert(found->value == 99);

    int hash_alpha = hash("alpha");
    int hash_beta = hash("beta");
    assert(hash_alpha != -1);
    assert(hash_beta != -1);
    assert(hash_alpha != hash_beta);

    for (int i = 0; i < 100; i++) {
        char* key = malloc(32);
        snprintf(key, 32, "item-%d", i);
        addEntryHashMap(map, key, i);
    }

    assert(map->size >= 102);
    assert(searchEntryHashMap(map, "item-99") != NULL);

    for (int i = 0; i < 100; i++) {
        char* key = malloc(32);
        snprintf(key, 32, "item-%d", i);

        Entry* entry = searchEntryHashMap(map, key);

        assert(entry != NULL);
        assert(strcmp(entry->name, key) == 0);
        assert(entry->value == i);

        removeEntryHashMap(map, key);
        assert(searchEntryHashMap(map, key) == NULL);
        free(key);
    }

    assert(map->size == 2);

    printf("hashmap tests: ok\n");
    return 0;
}
