#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "vectormap.h"

int main(void) {
    VectorMap* map = buildVectorMap();
    assert(map != NULL);
    assert(map->size == 0);
    assert(map->capacity >= 10);

    addEntryVectorMap(map, "alpha", 10);
    addEntryVectorMap(map, "beta", 20);
    addEntryVectorMap(map, "gamma", 30);

    assert(map->size == 3);

    Entry* found = searchEntryVectorMap(map, "beta");
    assert(found != NULL);
    assert(strcmp(found->name, "beta") == 0);
    assert(found->value == 20);

    Entry* missing = searchEntryVectorMap(map, "missing");
    assert(missing == NULL);

    removeEntryVectorMap(map, "beta");
    assert(map->size == 2);
    assert(searchEntryVectorMap(map, "beta") == NULL);

    found = searchEntryVectorMap(map, "alpha");
    assert(found != NULL);
    assert(found->value == 10);

    for (int i = 0; i < 25; i++) {
        char key[32];
        snprintf(key, sizeof(key), "k%d", i);
        addEntryVectorMap(map, key, i * 10);
    }

    assert(map->size == 27);
    assert(map->capacity >= 32);
    assert(searchEntryVectorMap(map, "k24") != NULL);

    printf("vectormap tests: ok\n");
    return 0;
}
