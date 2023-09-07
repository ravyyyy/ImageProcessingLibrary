#ifndef API_H
#define API_H

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

void AllocImage(Image* image, int width, int height);
void FreeImage(Image* image);

Image* CreateSiemensStar(int width, int height, int radius, int linesNumber);
Image* CreateGradientImage(int width, int height, int columnsNumber);
Image* RotateImageCustomDegrees(Image* input, int width, int height, int degrees);
Image* RotateImageCustomDegreesIncomplete(Image* input, int width, int height, int degrees);
Image* RotateImageCustomFile(Image* input, int width, int height, int degrees);

#endif