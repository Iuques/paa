#ifndef MAP_H
#define MAP_H

typedef struct Entry {
    char* name;
    int value;
} Entry;

typedef struct Map {
    Entry* entries;
    int size;
    int capacity;
} Map;

Map* buildMap();

void addEntry(Map* map, char* name, int value);

void doubleCapacityNowPlusUltraMegaBlaster(Map* map);

Entry* searchEntry(Map* map, char* name);

void removeEntry(Map* map, char* name);

#endif