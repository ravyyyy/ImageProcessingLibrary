#include "rotatebilinear.h"

void RotateImageBilinear(unsigned char* inputImage, unsigned char* outputImage, int windowWidth, int windowHeight, double angle)
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

            if (originalX >= 0 && originalX < windowWidth - 1 && originalY >= 0 && originalY < windowHeight - 1)
            {
                int x0 = (int)originalX;
                int x1 = x0 + 1;
                int y0 = (int)originalY;
                int y1 = y0 + 1;

                double dx = originalX - x0;
                double dy = originalY - y0;

                for (int channel = 0; channel < 3; channel++)
                {
                    // Bilinear interpolation
                    double interpolatedValue = 
                        (1.0 - dx) * (1.0 - dy) * inputImage[(y0 * windowWidth + x0) * 3 + channel] +
                        dx * (1.0 - dy) * inputImage[(y0 * windowWidth + x1) * 3 + channel] +
                        (1.0 - dx) * dy * inputImage[(y1 * windowWidth + x0) * 3 + channel] +
                        dx * dy * inputImage[(y1 * windowWidth + x1) * 3 + channel];

                    outputImage[(i * windowWidth + j) * 3 + channel] = (unsigned char)interpolatedValue;
                }
            }
        }
    }
}
