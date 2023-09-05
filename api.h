#ifndef API_H
#define API_H

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

Image* CreateGradientImage(int width, int height, int columnsNumber);

Image* CreateSiemensStar(int width, int height, int radius, int linesNumber);

void FreeImage(Image* image);

#endif