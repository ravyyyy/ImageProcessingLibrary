#include "drawstar.h"

void DrawStar(unsigned char* star, int windowWidth, int windowHeight, int starRadius, int linesNumber)
{
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    for (int y = 0; y < windowHeight; y++) {
        for (int x = 0; x < windowWidth; x++) {
            int pixelIndex = (y * windowWidth + x) * 3;

            int dx = x - centerX;
            int dy = y - centerY;
            double distance = sqrt(dx * dx + dy * dy); // Euclidean distance.

            if (distance <= starRadius) {
                double angle = atan2(dy, dx); // Direction from the center to the current pixel.
                angle += M_PI; // Adjustment to ensure that the angle falls within the range of 0 to 2pi (0 to 360 degrees).
                int sectorIndex = (int)(angle / (2 * M_PI / linesNumber)) % linesNumber; // The normalized angle is divided into equally spaced sectors.
                // filtru median
                // transformari, affine, perspective

                star[pixelIndex] = (sectorIndex % 2) ? 0 : 255;
                star[pixelIndex + 1] = (sectorIndex % 2) ? 0 : 255;
                star[pixelIndex + 2] = (sectorIndex % 2) ? 0 : 255;
            } else {
                star[pixelIndex] = 255;
                star[pixelIndex + 1] = 255;
                star[pixelIndex + 2] = 255;
            }
        }
    }
}