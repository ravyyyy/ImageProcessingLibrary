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

void AllocImage(Image* image, int width, int height)
{
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);
}

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
    
    if (gradientImage == NULL) 
    {
        return NULL;
    }

    AllocImage(gradientImage, width, height);

    if (gradientImage->data == NULL)
    {
        free(gradientImage);
        return NULL;
    }

    DrawGradient(gradientImage->data, width, height, columnsNumber);

    return gradientImage;
}

Image* CreateSiemensStar(int width, int height, int radius, int linesNumber)
{
    Image* siemensStar = malloc(sizeof(Image));

    if (siemensStar == NULL)
    {
        return NULL;
    }

    AllocImage(siemensStar, width, height);

    if (siemensStar->data == NULL)
    {
        free(siemensStar);
        return NULL;
    }

    DrawStar(siemensStar->data, width, height, radius, linesNumber);

    return siemensStar;
}

Image* RotateImageCustomDegrees(Image* input, int width, int height, int degrees)
{
    Image* output = malloc(sizeof(Image));

    if (output == NULL)
    {
        return NULL;
    }

    AllocImage(output, width, height);

    if (output->data == NULL)
    {
        free(output);
        return NULL;
    }

    RotateImageCustom(input->data, output->data, width, height, degrees);

    return output;
}

Image* RotateImageCustomDegreesIncomplete(Image* input, int width, int height, int degrees)
{
    Image* output = malloc(sizeof(Image));

    if (output == NULL)
    {
        return NULL;
    }

    AllocImage(output, width, height);

    if (output->data == NULL)
    {
        free(output);
        return NULL;
    }

    RotateImageCustomIncomplete(input->data, output->data, width, height, degrees);

    return output;
}