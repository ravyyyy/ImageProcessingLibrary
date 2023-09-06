#include "rgbtograyscale.h"

void ConvertImage(unsigned char* input, unsigned char* output, int width, int height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            unsigned char red = input[(j * width + i) * 3];
            unsigned char green = input[(j * width + i) * 3 + 1];
            unsigned char blue = input[(j * width + i) * 3 + 2];

            output[j * width + i] = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);
        }
    }
}