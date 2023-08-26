#ifndef ARGENT_RESULT_H
#define ARGENT_RESULT_H

#include "argent_stdint.h"

// Generic result values.
#define ARGENT_SUCCESS 1
#define ARGENT_FAILURE 0

typedef ArS32 ArResult;

const char* arResultToString(ArResult result);

#endif // ARGENT_RESULT_H