#ifndef API_H
#define API_H

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

typedef enum {
    SUCCESS = 0,
    ERROR = -1,
    INVALID_PARAMETERS = -2,
    INVALID_TYPE = -3
} AllocationStatus;

typedef enum {
    RGB = 0,
    Grayscale = 1,
    Invalid = -1
} ImageType;

/**
 * @file
 */


int32_t AllocImage(Image** image, int width, int height, ImageType type);

/**
 * @brief Deallocate memory associated with an Image structure.
 *
 * This function frees the memory allocated for an `Image` structure, including its
 * data array, to prevent memory leaks. It checks for null pointers to ensure safe
 * deallocation.
 *
 * @param image Pointer to the `Image` structure to be deallocated.
 *
 * @note It is essential to call this function when an `Image` structure is no longer
 *       needed to release the allocated memory properly.
 *
 * @see Image, AllocImage, AllocImageGrayscale
 */
void FreeImage(Image* image);

/**
 * @brief Create a Siemens Star image.
 *
 * This function generates a Siemens Star image, which is a pattern consisting of
 * radiating lines from a central point, often used in image processing for testing
 * and calibration purposes.
 *
 * @param width The width of the Siemens Star image to create.
 * @param height The height of the Siemens Star image to create.
 * @param radius The radius of the central circle from which lines radiate.
 * @param linesNumber The number of lines to draw in the Siemens Star pattern.
 *
 * @return A pointer to the dynamically allocated Siemens Star image (`Image*`) if
 *         memory allocation and image creation were successful. If there was an
 *         error during memory allocation or image creation, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the Siemens
 *       Star image using the `FreeImage` function when it is no longer needed to
 *       prevent memory leaks.
 *
 * @see Image, AllocImage, FreeImage
 */
Image* CreateSiemensStar(int width, int height, int radius, int linesNumber);

/**
 * @brief Create a Gradient Image.
 *
 * This function generates a gradient image consisting of vertical columns of varying
 * intensity, often used for testing and visualization purposes.
 *
 * @param width The width of the gradient image to create.
 * @param height The height of the gradient image to create.
 * @param columnsNumber The number of vertical columns in the gradient.
 *
 * @return A pointer to the dynamically allocated gradient image (`Image*`) if memory
 *         allocation and image creation were successful. If there was an error during
 *         memory allocation or image creation, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the gradient
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImage, FreeImage
 */
Image* CreateGradientImage(int width, int height, int columnsNumber);

/**
 * @brief Rotate an image by a specified angle in degrees.
 *
 * This function rotates an input image by a specified angle in degrees. 
 * It creates a new image to store the rotated result and returns a pointer
 * to it.
 *
 * @param input A pointer to the input image (`Image*`) to be rotated.
 * @param width The width of the input image.
 * @param height The height of the input image.
 * @param degrees The angle in degrees by which to rotate the image.
 *
 * @return A pointer to the dynamically allocated rotated image (`Image*`) if memory
 *         allocation and rotation were successful. If there was an error during memory
 *         allocation or rotation, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the rotated
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImage, FreeImage
 */
Image* RotateImageCustomDegrees(Image* input, int width, int height, int degrees);

/**
 * @brief Rotate an image by a specified angle in degrees (incomplete).
 *
 * This function attempts to rotate an input image by a specified angle in degrees using
 * a custom algorithm. It creates a new image to store the rotated result and returns a
 * pointer to it. Please note that this implementation is marked as "incomplete" and may
 * not produce accurate results.
 *
 * @param input A pointer to the input image (`Image*`) to be rotated.
 * @param width The width of the input image.
 * @param height The height of the input image.
 * @param degrees The angle in degrees by which to rotate the image.
 *
 * @return A pointer to the dynamically allocated rotated image (`Image*`) if memory
 *         allocation and rotation were successful. If there was an error during memory
 *         allocation or rotation, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the rotated
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImage, FreeImage
 */
Image* RotateImageCustomDegreesIncomplete(Image* input, int width, int height, int degrees);

/**
 * @brief Rotate a specific image by a specified angle in degrees.
 *
 * This function rotates an input image by a specified angle in degrees. 
 * It creates a new image to store the rotated result and returns a pointer
 * to it.
 *
 * @param input A pointer to the input image (`Image*`) to be rotated.
 * @param width The width of the input image.
 * @param height The height of the input image.
 * @param degrees The angle in degrees by which to rotate the image.
 *
 * @return A pointer to the dynamically allocated rotated image (`Image*`) if memory
 *         allocation and rotation were successful. If there was an error during memory
 *         allocation or rotation, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the rotated
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImage, FreeImage
 */
void RotateImageCustomFile(Image* input, Image* output, int angle);

/**
 * @brief Rotate an image using bilinear interpolation.
 *
 * This function rotates an input image by a specified angle in degrees using bilinear
 * interpolation. It creates a new image to store the rotated result and returns a pointer
 * to it.
 *
 * @param input A pointer to the input image (`Image*`) to be rotated.
 * @param width The width of the input image.
 * @param height The height of the input image.
 * @param degrees The angle in degrees by which to rotate the image.
 *
 * @return A pointer to the dynamically allocated rotated image (`Image*`) if memory
 *         allocation and rotation were successful. If there was an error during memory
 *         allocation or rotation, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the rotated
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImage, FreeImage
 */
void RotateBilinear(Image* input, Image* output, int angle);

/**
 * @brief Apply the Sobel horizontal edge detection filter to an image.
 *
 * This function applies the Sobel horizontal edge detection filter to the input image
 * and generates an output grayscale image highlighting horizontal edges. It creates a
 * new image to store the result and returns a pointer to it.
 *
 * @param input A pointer to the input image (`Image*`) on which the filter is applied.
 * @param width The width of the input image.
 * @param height The height of the input image.
 *
 * @return A pointer to the dynamically allocated grayscale image (`Image*`) if memory
 *         allocation and filtering were successful. If there was an error during memory
 *         allocation or filtering, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the grayscale
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImageGrayscale, FreeImage
 */
void ApplySobelHorizontalImage(Image* input, Image* output);

/**
 * @brief Convert a color image to grayscale.
 *
 * This function converts a color image to grayscale by applying the luminance conversion
 * formula. It creates a new grayscale image to store the result and returns a pointer
 * to it.
 *
 * @param input A pointer to the input color image (`Image*`) to be converted.
 * @param width The width of the input image.
 * @param height The height of the input image.
 *
 * @return A pointer to the dynamically allocated grayscale image (`Image*`) if memory
 *         allocation and conversion were successful. If there was an error during memory
 *         allocation or conversion, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the grayscale
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImageGrayscale, FreeImage
 */
void ApplyConvertImage(Image* input, Image* output);

/**
 * @brief Apply the Sobel vertical edge detection filter to an image.
 *
 * This function applies the Sobel vertical edge detection filter to the input image and
 * generates an output grayscale image highlighting vertical edges. It creates a new image
 * to store the result and returns a pointer to it.
 *
 * @param input A pointer to the input image (`Image*`) on which the filter is applied.
 * @param width The width of the input image.
 * @param height The height of the input image.
 *
 * @return A pointer to the dynamically allocated grayscale image (`Image*`) if memory
 *         allocation and filtering were successful. If there was an error during memory
 *         allocation or filtering, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the grayscale
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImageGrayscale, FreeImage
 */
void ApplySobelVerticalImage(Image* input, Image* output);

/**
 * @brief Apply the Sobel edge detection filter to an image.
 *
 * This function applies the Sobel edge detection filter to the input image and generates
 * an output grayscale image highlighting edges. It creates a new image to store the result
 * and returns a pointer to it.
 *
 * @param input A pointer to the input image (`Image*`) on which the filter is applied.
 * @param width The width of the input image.
 * @param height The height of the input image.
 *
 * @return A pointer to the dynamically allocated grayscale image (`Image*`) if memory
 *         allocation and filtering were successful. If there was an error during memory
 *         allocation or filtering, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the grayscale
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImageGrayscale, FreeImage
 */
void ApplySobelImage(Image* input, Image* output);

/**
 * @brief Apply a median filter to an image.
 *
 * This function applies a median filter to the input image, which helps reduce noise and
 * preserve edges. It creates a new grayscale image to store the result and returns a
 * pointer to it.
 *
 * @param[in] input A pointer to the input image (`Image*`) on which the median filter is
 *              applied.
 * @param width The width of the input image.
 * @param height The height of the input image.
 *
 * @return A pointer to the dynamically allocated grayscale image (`Image*`) if memory
 *         allocation and filtering were successful. If there was an error during memory
 *         allocation or filtering, it returns `NULL`.
 *
 * @note The caller is responsible for freeing the memory allocated for the grayscale
 *       image using the `FreeImage` function when it is no longer needed to prevent
 *       memory leaks.
 *
 * @see Image, AllocImageGrayscale, FreeImage
 */
void Median(Image* input, Image* output);

#endif