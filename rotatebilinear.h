#include <math.h>

/**
 * @brief Rotates an image represented as an array of unsigned char pixels by a specified angle using bilinear interpolation.
 * 
 * @param inputImage A pointer to the input image.
 * @param outputImage A pointer to the output image where the rotated image will be stored.
 * @param windowWidth The width of the canvas.
 * @param windowHeight The height of the canvas.
 * @param angle The angle rotation in degrees.
 */

void RotateImageBilinear(unsigned char* inputImage, unsigned char* outputImage, int windowWidth, int windowHeight, double angle);