#include "includes/entry.h"

Entry buildEntry(char* name, int value) {
    return (Entry){.name = name, .value = value};
}