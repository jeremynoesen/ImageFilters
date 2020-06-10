#include <stdio.h>
#include <string.h>

/* Color struct to manage pixel colors */
typedef struct {
    int limit, r, g, b;
} Color;

/* Read a PPM image to a Color array */
int *readPPMImage(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *fileType = "";
    fscanf(file, "%s", fileType);

    if (strcmp(fileType, "P6") != 0) return 0;

    int width, height, limit;
    fscanf(file, " %d %d %d", &width, &height, &limit);

    Color imgArray[width][height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r, g, b;
            fscanf(file, " %d %d %d", &r, &g, &b);
            Color color;
            color.r = r;
            color.g = g;
            color.b = b;
            color.limit = limit;
            imgArray[x][y] = color;
        }
    }

    fclose(fileType);

    return imgArray;
}