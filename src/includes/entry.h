#ifndef ENTRY_H
#define ENTRY_H

typedef struct Entry {
    char* name;
    int value;
} Entry;

Entry buildEntry(char* name, int value);

#endif