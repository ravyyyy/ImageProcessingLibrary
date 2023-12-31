#include <stdlib.h>
#include <stdint.h>

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
#include "medianfilter.h"

int32_t AllocImage(Image** image, int width, int height, ImageType type)
{
    if (width < 1 || height < 1 || width > 3840 || height > 2160)
    {
        return INVALID_PARAMETERS;
    }

    *image = malloc(sizeof(Image));
    if (*image == NULL)
    {
        return ERROR;
    }

    (*image)->width = width;
    (*image)->height = height;

    

    if (type == RGB)
    {
        (*image)->data = malloc(width * height * 3);
    }
    else if (type == Grayscale)
    {
        (*image)->data = malloc(width * height);
    }
    else
    {
        return INVALID_TYPE;
    }
    
    if ((*image)->data == NULL)
    {
        free(image);
        return ERROR;
    }

    return SUCCESS;
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

Image* CreateSiemensStar(int width, int height, int radius, int linesNumber)
{
    Image* siemensStar = malloc(sizeof(Image));

    if (siemensStar == NULL)
    {
        return NULL;
    }

    AllocImage(&siemensStar, width, height, RGB);

    if (siemensStar->data == NULL)
    {
        free(siemensStar);
        return NULL;
    }

    DrawStar(siemensStar->data, width, height, radius, linesNumber);

    return siemensStar;
}

Image* CreateGradientImage(int width, int height, int columnsNumber)
{
    Image* gradientImage = malloc(sizeof(Image));
    
    if (gradientImage == NULL) 
    {
        return NULL;
    }

    AllocImage(&gradientImage, width, height, RGB);

    if (gradientImage->data == NULL)
    {
        free(gradientImage);
        return NULL;
    }

    DrawGradient(gradientImage->data, width, height, columnsNumber);

    return gradientImage;
}

void RotateImageCustomDegrees(Image* input, Image* output, int degrees)
{
    RotateImageCustom(input->data, output->data, output->width, output->height, degrees);
}

void RotateImageCustomDegreesIncomplete(Image* input, Image* output, int angle)
{
    RotateImageCustomIncomplete(input->data, output->data, output->width, output->height, angle);
}

void RotateImageCustomFile(Image* input, Image* output, int angle)
{
    RotateImageCustom(input->data, output->data, output->width, output->height, angle);
}

void RotateBilinear(Image* input, Image* output, int angle)
{
    RotateImageBilinear(input->data, output->data, output->width, output->height, angle);
}

void ApplySobelHorizontalImage(Image* input, Image* output)
{
    ApplySobelHorizontal(input->data, output->data, output->width, output->height);
}

void ApplyConvertImage(Image* input, Image* output)
{
    ConvertImage(input->data, output->data, output->width, output->height);
}

void ApplySobelVerticalImage(Image* input, Image* output)
{
    ApplySobelVertical(input->data, output->data, output->width, output->height);
}

void ApplySobelImage(Image* input, Image* output)
{
    ApplySobel(input->data, output->data, output->width, output->height);
}

void Median(Image* input, Image* output)
{
    MedianFilter(input->data, output->data, output->width, output->height);
}