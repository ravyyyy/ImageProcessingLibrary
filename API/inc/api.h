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

/**
 * @brief Allocate memory for an image structure and initialize it.
 *
 * This function allocates memory for an `Image` structure and initializes its
 * width, height, and pixel data based on the specified parameters. It also
 * performs checks for valid parameters and memory allocation errors.
 *
 * @param[out] image A pointer to an `Image` pointer that will hold the allocated image.
 * @param[in] width The width of the image in pixels.
 * @param[in] height The height of the image in pixels.
 * @param[in] type The type of the image (RGB or Grayscale).
 *
 * @return - `SUCCESS` if memory allocation and initialization were successful.
 *         - `ERROR` if a memory allocation error occurred.
 *         - `INVALID_PARAMETERS` if the provided width or height is invalid.
 *         - `INVALID_TYPE` if the specified image type is invalid.
 */
int32_t AllocImage(Image** image, int width, int height, ImageType type);

/**
 * @brief Deallocate memory for an Image structure.
 *
 * This function deallocates the memory associated with an `Image` structure,
 * including its pixel data. It ensures proper cleanup and prevents memory leaks.
 *
 * @param[in] image A pointer to the `Image` structure to be deallocated.
 *                  The function sets this pointer to NULL after deallocation.
 */
void FreeImage(Image* image);

/**
 * @brief Create a Siemens star image.
 *
 * This function creates a Siemens star image with the specified width, height,
 * radius, and number of lines. It allocates memory for the image structure and
 * its pixel data, draws the star on the image, and returns the created image.
 * 
 * @param[in] width The width of the Siemens star image in pixels.
 * @param[in] height The height of the Siemens star image in pixels.
 * @param[in] radius The radius of the star in pixels.
 * @param[in] linesNumber The number of lines in the star.
 *
 * @return A pointer to the created Siemens star image.
 *         If memory allocation fails or an error occurs during image creation,
 *         NULL is returned.
 */
Image* CreateSiemensStar(int width, int height, int radius, int linesNumber);

/**
 * @brief Create a gradient image with multiple columns.
 *
 * This function creates a gradient image with the specified width, height, and
 * the number of columns. It allocates memory for the image structure and its
 * pixel data, generates a gradient in the image with the specified number of
 * columns, and returns the created gradient image.
 * 
 * @param[in] width The width of the gradient image in pixels.
 * @param[in] height The height of the gradient image in pixels.
 * @param[in] columnsNumber The number of gradient columns in the image.
 *
 * @return A pointer to the created gradient image.
 *         If memory allocation fails or an error occurs during image creation,
 *         NULL is returned.
 */
Image* CreateGradientImage(int width, int height, int columnsNumber);

/**
 * @brief Rotate an image by a specified angle in degrees.
 *
 * This function rotates the input image by the specified angle in degrees and
 * stores the result in the output image. The rotation is performed
 * counter-clockwise.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the rotated image will be stored.
 * @param[in] degrees The angle in degrees by which the image should be rotated.
 */
void RotateImageCustomDegrees(Image* input, Image* output, int degrees);

/**
 * @brief Rotate an image by a specified angle in radians (incomplete).
 *
 * This function rotates an image represented by `inputImage` by the specified
 * angle in radians and stores the result in `outputImage`. The rotation is
 * performed counter-clockwise. Note that this function is marked as incomplete
 * and may have limited or incomplete functionality.
 * 
 * @param[in] inputImage A pointer to the input image data.
 * @param[out] outputImage A pointer to the output image data where the rotated image will be stored.
 * @param[in] windowWidth The width of the image.
 * @param[in] windowHeight The height of the image.
 * @param[in] angle The angle in radians by which the image should be rotated.
 */
void RotateImageCustomDegreesIncomplete(Image* input, Image* output, int degrees);

/**
 * @brief Rotate an image by a specified angle in degrees (from file).
 *
 * This function rotates the input image by the specified angle in degrees and
 * stores the result in the output image. The rotation is performed
 * counter-clockwise. It uses an external file for the rotation calculation.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the rotated image will be stored.
 * @param[in] angle The angle in degrees by which the image should be rotated.
 */
void RotateImageCustomFile(Image* input, Image* output, int angle);

/**
 * @brief Rotate an image using bilinear interpolation by a specified angle in degrees.
 *
 * This function rotates the input image by the specified angle in degrees using
 * bilinear interpolation and stores the result in the output image. The rotation
 * is performed counter-clockwise.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the rotated image will be stored.
 * @param[in] angle The angle in degrees by which the image should be rotated.
 */
void RotateBilinear(Image* input, Image* output, int angle);

/**
 * @brief Apply the Sobel horizontal edge detection filter to an image.
 *
 * This function applies the Sobel horizontal edge detection filter to the input image
 * and stores the result in the output image. It enhances horizontal edges in the image.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the filtered image will be stored.
 */
void ApplySobelHorizontalImage(Image* input, Image* output);

/**
 * @brief Convert an RGB image to grayscale.
 *
 * This function converts the input RGB image to grayscale and stores the
 * result in the output image. It uses the formula: grayscale = 0.299 * R + 0.587 * G + 0.114 * B.
 * 
 * @param[in] input A pointer to the input RGB image.
 * @param[out] output A pointer to the output grayscale image where the converted image will be stored.
 */
void ApplyConvertImage(Image* input, Image* output);

/**
 * @brief Apply the Sobel vertical edge detection filter to an image.
 *
 * This function applies the Sobel vertical edge detection filter to the input image
 * and stores the result in the output image. It enhances vertical edges in the image.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the filtered image will be stored.
 */
void ApplySobelVerticalImage(Image* input, Image* output);

/**
 * @brief Apply the Sobel edge detection filter to an image.
 *
 * This function applies the Sobel edge detection filter to the input image
 * and stores the result in the output image. It enhances edges in the image
 * by considering both horizontal and vertical edges.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the filtered image will be stored.
 */
void ApplySobelImage(Image* input, Image* output);

/**
 * @brief Apply a median filter to an image.
 *
 * This function applies a median filter to the input image and stores the result
 * in the output image. The median filter is used for noise reduction.
 * 
 * @param[in] input A pointer to the input image.
 * @param[out] output A pointer to the output image where the filtered image will be stored.
 */
void Median(Image* input, Image* output);

#endif