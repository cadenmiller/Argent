#include "result.h"

const char* arResultToString(ArResult result)
{
    switch (result)
    {
        case ARGENT_SUCCESS: return "No error.";
        case ARGENT_FAILURE: return "Generic failure.";
    }
}