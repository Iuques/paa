#ifndef FILE_H
#define FILE_H

#include "entry.h"

#define FILE_IN_NAME "input.txt"
#define FILE_OUT_NAME "output.txt"

void readFile(Entry* entries);

void writeFile(Entry* entries);

#endif