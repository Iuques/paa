#include "includes/file.h"
#include <stdio.h>
#include <stdlib.h>

void readFile(Map* map) {
    if(map == NULL) return;

    FILE* file = fopen(FILE_IN_NAME, "r");
    if(file == NULL) return;

    char name[1024];
    int value;

    while(fscanf(file, "%999s %d", name, &value) == 2) {
        addEntry(map, name, value);
    }

    fclose(file);
}

void writeFile(Map* map) {
    if(map == NULL) return;

    FILE* file = fopen(FILE_OUT_NAME, "w");
    if(file == NULL) return;

    for(int i = 0; i < map->size; i++) {
        fprintf(file, "%s %d\n", map->entries[i].name, map->entries[i].value);
    }

    fclose(file);
}