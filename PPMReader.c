#include <stdio.h>
#include <string.h>
#include "PPMReader.h"

/* Pixel struct to manage pixel colors */
typedef struct {
    unsigned int limit, r, g, b;
} Pixel;

/* Read a PPM image to a Pixel array */
struct Pixel *readPPMImage(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *fileType;
    fscanf(file, " %s", fileType);

    if (strcmp(fileType, "P6") != 0) return 0;

    int width, height, limit;
    fscanf(file, " %d %d %d", &width, &height, &limit);

    Pixel imgArray[width][height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if(feof(file)) break;
            unsigned int r, g, b;
            fscanf(file, " %d %d %d", &r, &g, &b);
            Pixel pixel;
            pixel.limit = limit;
            pixel.r = r > limit ? limit : r;
            pixel.g = g > limit ? limit : g;
            pixel.b = b > limit ? limit : b;
            imgArray[x][y] = pixel;
        }
    }

    fclose(file);

    return imgArray;
}

/* Test file loading */
int main(void) {
    printf("test");
    readPPMImage("icon.ppm");
}