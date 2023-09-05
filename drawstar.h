/**
   @file
 * @brief This method is used to draw a star-like pattern on a canvas. The pattern is created by calculating the distance of each pixel
 * from the center of the canvas and comparing to a given 'starRadius'. If the distance is within the specified radius, 
 * the pixel is part of the star pattern; otherwise, it's set to a background color.
 * 
 * @param star A pointer to the pixel data of the canvas.
 * @param windowWidth The width of the canvas.
 * @param windowHeight The height of the canvas.
 * @param starRadius The radius within which the star pattern is drawn.
 * @param linesNumber The number of lines (arms) the star should have.
 */

void DrawStar(unsigned char* star, int windowWidth, int windowHeight, int starRadius, int linesNumber);