#include "rotate90.h"

void RotateImage(unsigned char* inputImage, unsigned char* outputImage, int windowWidth, int windowHeight)
{
    for (int i = 0; i < windowWidth; ++i)
    {
        for (int j = 0; j < windowHeight; ++j)
        {
            outputImage[(i * windowHeight + j) * 3] = inputImage[((windowHeight - j - 1) * windowWidth + i) * 3];
            outputImage[(i * windowHeight + j) * 3 + 1] = inputImage[((windowHeight - j - 1) * windowWidth + i) * 3 + 1];
            outputImage[(i * windowHeight + j) * 3 + 2] = inputImage[((windowHeight - j - 1) * windowWidth + i) * 3 + 2];
        }
    }
}