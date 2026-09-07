#include <stdio.h>
#include <stdlib.h>
#include "includes/map.h"

int main(int qargs, char **args) {
    Map* map = malloc(sizeof(Map));
    map->entries = malloc(1 * sizeof(Entry));
    map->size = 0;
    map->capacity = 1;

    addEntry(map, "key1", 10);
    addEntry(map, "key2", 20);

    for(int i = 0; i < map->size; i++) {
        printf("Entry %d: Name = %s, Value = %d\n", i, map->entries[i].name, map->entries[i].value);
    }

    free(map->entries);
    free(map);

    return 0;
}