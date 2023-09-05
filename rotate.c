#include "rotate.h"

void RotateImageCustom(unsigned char* inputImage, unsigned char* outputImage, int windowWidth, int windowHeight, double angle)
{
    double angleRadians = -angle * M_PI / 180.0; // Convert to radians and negate the angle
    double cosValue = cos(angleRadians);
    double sinValue = sin(angleRadians);

    for (int i = 0; i < windowHeight; i++)
    {
        for (int j = 0; j < windowWidth; j++)
        {
            int centerX = windowWidth / 2;
            int centerY = windowHeight / 2;

            double originalX = cosValue * (j - centerX) - sinValue * (i - centerY) + centerX;
            double originalY = sinValue * (j - centerX) + cosValue * (i - centerY) + centerY;

            if (originalX >= 0 && originalX < windowWidth && originalY >= 0 && originalY < windowHeight)
            {
                int roundedX = (int)(originalX + 0.5);
                int roundedY = (int)(originalY + 0.5);

                for (int channel = 0; channel < 3; channel++)
                {
                    outputImage[(i * windowWidth + j) * 3 + channel] = inputImage[(roundedY * windowWidth + roundedX) * 3 + channel];
                }
            }
        }
    }
}
