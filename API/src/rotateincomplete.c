#include "rotateincomplete.h"

void RotateImageCustomIncomplete(unsigned char* inputImage, unsigned char* outputImage, int windowWidth, int windowHeight, double angle)
{
    double angleRadians = angle * M_PI / 180.0; // convert to radians
    double cosValue = cos(angleRadians);
    double sinValue = sin(angleRadians);

    for (int i = 0; i < windowHeight; i++)
    {
        for (int j = 0; j < windowWidth; j++)
        {
            for (int channel = 0; channel < 3; channel++)
            {
                int newX = (int)(cosValue * (j - windowWidth / 2) - sinValue * (i - windowHeight / 2) + windowWidth / 2);
                int newY = (int)(sinValue * (j - windowWidth / 2) + cosValue * (i - windowHeight / 2) + windowHeight / 2);

                if (newX >= 0 && newX < windowWidth && newY >= 0 && newY < windowHeight)
                {
                    outputImage[(newY * windowWidth + newX) * 3 + channel] = inputImage[(i * windowWidth + j) * 3 + channel];
                }
            }
        }
    }
}