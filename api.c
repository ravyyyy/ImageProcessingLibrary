#include <stdlib.h>

#include "api.h"
#include "drawstar.h"
#include "drawgradient.h"
#include "rotate90.h"
#include "rotate.h"
#include "rotateincomplete.h"
#include "rotatebilinear.h"
#include "sobelhorizontal.h"
#include "rgbtograyscale.h"
#include "sobelvertical.h"
#include "sobel.h"

void FreeImage(Image* image)
{
    if (image != NULL)
    {
        if (image->data != NULL)
        {
            free(image->data);
        }

        free(image);
    }
}

Image* CreateGradientImage(int width, int height, int columnsNumber)
{
    Image* gradientImage = malloc(sizeof(Image));
    gradientImage->width = width;
    gradientImage->height = height;
    gradientImage->data = malloc(width * height * 3);

    DrawGradient(gradientImage->data, width, height, columnsNumber);

    return gradientImage;
}