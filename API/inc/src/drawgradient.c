#include "drawgradient.h"

#define PI 3.14159

void DrawGradient(unsigned char* gradient, int windowWidth, int windowHeight, int columnsNumber)
{
    int sectorWidth = windowWidth / columnsNumber; // Calculates the width of each column.

    for (int i = 0; i < windowWidth; ++i) 
    {
        int colIndex = i / sectorWidth;

        for (int j = 0; j < windowHeight; ++j) 
        {
            int hue = (int)(((float)colIndex * 360.0 / columnsNumber) + 0.5) % 360; // Hue value for the current pixel.

            float intensity = 1.0f - ((float)j / windowHeight) * ((float)j / windowHeight); // Intensity of the color based on the vertical position.

            float red = (1 + cos(hue * PI / 180.0)) * 0.5f * intensity;
            float green = (1 + cos((hue - 120) * PI / 180.0)) * 0.5f * intensity;
            float blue = (1 + cos((hue - 240) * PI / 180.0)) * 0.5f * intensity;

            int pixelIndex = (j * windowWidth + i) * 3;
            gradient[pixelIndex] = (unsigned char)(red * 255.0);
            gradient[pixelIndex + 1] = (unsigned char)(green * 255.0);
            gradient[pixelIndex + 2] = (unsigned char)(blue * 255.0);
        }
    }
}