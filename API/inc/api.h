#ifndef API_H
#define API_H

/**
 * @file
 */

/**
 * @struct Image
 * @brief Represents an image with its width, height, and pixel data.
 */
typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

/**
 * @enum AllocationStatus
 * @brief Represents the possible allocation status codes.
 * 
 * This enum defines various status codes that can be returned when performing memory allocation operations.
 * - `SUCCESS`: The operation was successful.
 * - `ERROR`: An error occurred during the operation.
 * - `INVALID_PARAMETERS`: The provided parameters are invalid.
 * - `INVALID_TYPE`: The specified type is invalid.
 */
typedef enum {
    SUCCESS = 0,
    ERROR = -1,
    INVALID_PARAMETERS = -2,
    INVALID_TYPE = -3
} AllocationStatus;

/**
 * @enum ImageType
 * @brief Represents the possible types of images.
 * 
 * This enum defines different image types that can be used to classify images.
 * - `RGB`: Represents a color image in RGB format.
 * - `Grayscale`: Represents a grayscale image.
 * - `Invalid`: Indicates an invalid or unknown image type.
 */
typedef enum {
    RGB = 0,
    Grayscale = 1,
    Invalid = -1
} ImageType;

int32_t AllocImage(Image** image, int width, int height, ImageType type);

void FreeImage(Image* image);

Image* CreateSiemensStar(int width, int height, int radius, int linesNumber);

Image* CreateGradientImage(int width, int height, int columnsNumber);

void RotateImageCustomDegrees(Image* input, Image* output, int degrees);

void RotateImageCustomDegreesIncomplete(Image* input, Image* output, int degrees);

void RotateImageCustomFile(Image* input, Image* output, int angle);

void RotateBilinear(Image* input, Image* output, int angle);

void ApplySobelHorizontalImage(Image* input, Image* output);

void ApplyConvertImage(Image* input, Image* output);

void ApplySobelVerticalImage(Image* input, Image* output);

void ApplySobelImage(Image* input, Image* output);

void Median(Image* input, Image* output);

#endif