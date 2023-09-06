#include <math.h>

/**
 * @file
 * @brief Iterating over each pixel, calculates it's new position after rotation and copies the pixel value from the original image,
 * to the rotated image if the new position is within bounds.
 * 
 * @param inputImage A pointer to the input image.
 * @param outputImage A pointer to the output image.
 * @param windowWidth The width of the canvas.
 * @param windowHeight The height of the canvas.
 * @param angle The rotation angle in degrees.
 */

void RotateImageCustom(unsigned char* inputImage, unsigned char* outputImage, int windowWidth, int windowHeight, double angle);