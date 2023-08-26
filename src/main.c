#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"

int main(int argc, char** argv)
{
    printf("This is a test of Argent!\n");

    ArGfxInitInfo graphicsInfo = {
        .api = ARGENT_GRAPHICS_API_OPENGL
    };

    int result = 0;

    result = arGfxInit(&graphicsInfo);

    if (result != ARGENT_SUCCESS)
    {
        printf("%s", arResultToString(result));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}