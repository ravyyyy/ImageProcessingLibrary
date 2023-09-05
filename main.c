#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "api.h"

#include "drawstar.h"
#include "rotate90.h"
#include "rotate.h"
#include "rotateincomplete.h"
#include "rotatebilinear.h"
#include "sobelhorizontal.h"
#include "rgbtograyscale.h"
#include "sobelvertical.h"
#include "sobel.h"

int main() // introducere argc, argv
{
    Image* image;

    int windowWidth;
    int windowHeight;
    int starRadius;
    int linesNumber;
    int columnsNumber;
    bool isMenuOpen = true;
    int userChoice;
    unsigned char* gradient = NULL;
    unsigned char* star = NULL;

    while(isMenuOpen)
    {
        printf("MENU:\n");
        printf("1. Draw a Siemens Star\n");
        printf("2. Draw a Gradient\n");
        printf("3. Rotate an image by 90 degrees to the right\n");
        printf("4. Rotate with custom degrees\n");
        printf("5. Rotate with custom degrees (incomplete)\n");
        printf("6. Rotate a specified image\n");
        printf("7. Rotate with custom degrees using bilinear interpolation\n");
        printf("8. Rotate downloaded image\n");
        printf("9. Sobel filter horizontal\n");
        printf("10. Convert RGB image to Grayscale\n");
        printf("11. Sobel filter vertical\n");
        printf("12. Full Sobel filter\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        switch(userChoice)
        {
            case 1:
                printf("SIEMENS STAR\n\n");
                printf("Enter the width: ");
                scanf("%d", &windowWidth);
                printf("Enter the height: ");
                scanf("%d", &windowHeight);
                printf("Enter the radius: ");
                scanf("%d", &starRadius);
                printf("Enter the number of lines: ");
                scanf("%d", &linesNumber);
                printf("\n");

                star = (unsigned char*)malloc(windowWidth * windowHeight * 3);
                if (star == NULL) 
                {
                    printf("Memory allocation failed for siemens star!");
                    return 1;
                }

                DrawStar(star, windowWidth, windowHeight, starRadius, linesNumber);

                FILE* rawFile = fopen("siemens_star.raw", "wb");
                if (rawFile == NULL) 
                {
                    printf("File could not be opened!");
                    free(star);
                    return 1;
                }

                fwrite(star, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                fclose(rawFile);

                //free(star);
                break;
            case 2:
                printf("GRADIENT\n\n");
                printf("Enter the width: ");
                scanf("%d", &windowWidth);
                printf("Enter the height: ");
                scanf("%d", &windowHeight);
                printf("Enter the number of columns: ");
                scanf("%d", &columnsNumber);

                image = CreateGradientImage(windowWidth, windowHeight, columnsNumber);

                if (image == NULL) 
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                FILE* rawFile2 = fopen("gradient.raw", "wb");
                if (rawFile2 == NULL)
                {
                    printf("File could not be opened!");
                    FreeImage(image);
                    return 1;
                }

                fwrite(image->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile2);

                FreeImage(image);
                fclose(rawFile2);

                break;
            case 3:
                printf("ROTATE BY 90 DEGREES\n\n");
                printf("1. Siemens star\n");
                printf("2. Gradient\n");
                printf("Choose the image you want to rotate: ");
                int choice;
                scanf("%d", &choice);

                printf("Enter width of image: ");
                scanf("%d", &windowWidth);
                printf("Enter height of image: ");
                scanf("%d", &windowHeight);

                unsigned char* rotatedImage = (unsigned char*)malloc(windowWidth * windowHeight * 3);
                if (rotatedImage == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                if (choice == 1)
                {
                    RotateImage(star, rotatedImage, windowWidth, windowHeight);

                    FILE* rotatedFile = fopen("rotated_image.raw", "wb");
                    if (rotatedFile == NULL)
                    {
                        printf("File could not be opened!");
                        free(star);
                        free(rotatedImage);
                        return 1;
                    } 

                    fwrite(rotatedImage, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFile);
                    fclose(rotatedFile);

                    free(star);
                    free(rotatedImage);
                }
                else
                {
                    RotateImage(gradient, rotatedImage, windowWidth, windowHeight);

                    FILE* rotatedFile = fopen("rotated_image.raw", "wb");
                    if (rotatedFile == NULL)
                    {
                        printf("File could not be opened!");
                        free(gradient);
                        free(rotatedImage);
                        return 1;
                    } 

                    fwrite(rotatedImage, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFile);
                    fclose(rotatedFile);

                    free(gradient);
                    free(rotatedImage);
                }

                break;
            case 4:
                printf("ROTATE CUSTOM\n\n");
                printf("Enter the degrees: ");
                int degrees;
                scanf("%d", &degrees);
                printf("1. Siemens star\n");
                printf("2. Gradient\n");
                printf("Choose the image you want to rotate: ");
                int choiceCustom;
                scanf("%d", &choiceCustom);

                printf("Enter width of image: ");
                scanf("%d", &windowWidth);
                printf("Enter height of image: ");
                scanf("%d", &windowHeight);

                unsigned char* rotatedImageCustom = (unsigned char*)malloc(windowWidth * windowHeight * 3);
                if (rotatedImageCustom == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                if (choiceCustom == 1)
                {
                    RotateImageCustom(star, rotatedImageCustom, windowWidth, windowHeight, degrees);

                    FILE* rotatedFileCustom = fopen("rotated_image_custom.raw", "wb");
                    if (rotatedFileCustom == NULL)
                    {
                        printf("File could not be opened!");
                        free(star);
                        free(rotatedImageCustom);
                        return 1;
                    } 

                    fwrite(rotatedImageCustom, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFileCustom);
                    fclose(rotatedFileCustom);

                    free(star);
                    free(rotatedImageCustom);
                }
                else
                {
                    RotateImageCustom(gradient, rotatedImageCustom, windowWidth, windowHeight, degrees);

                    FILE* rotatedFileCustom = fopen("rotated_image_custom.raw", "wb");
                    if (rotatedFileCustom == NULL)
                    {
                        printf("File could not be opened!");
                        free(gradient);
                        free(rotatedImageCustom);
                        return 1;
                    } 

                    fwrite(rotatedImageCustom, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFileCustom);
                    fclose(rotatedFileCustom);

                    free(gradient);
                    free(rotatedImageCustom);
                }

                break;
            case 5:
                printf("ROTATE CUSTOM (incomplete)\n\n");
                printf("Enter the degrees: ");
                int degreesIncomplete;
                scanf("%d", &degreesIncomplete);
                printf("1. Siemens star\n");
                printf("2. Gradient\n");
                printf("Choose the image you want to rotate: ");
                int choiceCustomIncomplete;
                scanf("%d", &choiceCustomIncomplete);

                printf("Enter width of image: ");
                scanf("%d", &windowWidth);
                printf("Enter height of image: ");
                scanf("%d", &windowHeight);

                unsigned char* rotatedImageCustomIncomplete = (unsigned char*)malloc(windowWidth * windowHeight * 3);
                if (rotatedImageCustomIncomplete == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                if (choiceCustomIncomplete == 1)
                {
                    RotateImageCustomIncomplete(star, rotatedImageCustomIncomplete, windowWidth, windowHeight, degreesIncomplete);

                    FILE* rotatedFileCustomIncomplete = fopen("rotated_image_custom_incomplete.raw", "wb");
                    if (rotatedFileCustomIncomplete == NULL)
                    {
                        printf("File could not be opened!");
                        free(star);
                        free(rotatedImageCustomIncomplete);
                        return 1;
                    } 

                    fwrite(rotatedImageCustomIncomplete, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFileCustomIncomplete);
                    fclose(rotatedFileCustomIncomplete);

                    free(star);
                    free(rotatedImageCustomIncomplete);
                }
                else
                {
                    RotateImageCustomIncomplete(gradient, rotatedImageCustomIncomplete, windowWidth, windowHeight, degreesIncomplete);

                    FILE* rotatedFileCustomIncomplete = fopen("rotated_image_custom_incomplete.raw", "wb");
                    if (rotatedFileCustomIncomplete == NULL)
                    {
                        printf("File could not be opened!");
                        free(gradient);
                        free(rotatedFileCustomIncomplete);
                        return 1;
                    } 

                    fwrite(rotatedImageCustomIncomplete, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFileCustomIncomplete);
                    fclose(rotatedFileCustomIncomplete);

                    free(gradient);
                    free(rotatedImageCustomIncomplete);
                }

                break;
            case 6:
                printf("ROTATE CUSTOM IMAGE\n\n");
                printf("Enter name of file: ");
                char fileName[100];
                scanf("%s", fileName);
    
                printf("Enter the degrees: ");
                int degreesCustom2;
                scanf("%d", &degreesCustom2);

                printf("Enter width of image: ");
                scanf("%d", &windowWidth);
                printf("Enter height of image: ");
                scanf("%d", &windowHeight);

                unsigned char* rotatedImageCustom2 = (unsigned char*)malloc(windowWidth * windowHeight * 3);
                if (rotatedImageCustom2 == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                FILE* imageFile = fopen(fileName, "rb");
                if (imageFile == NULL)
                {
                    printf("Image file could not be opened!");
                    free(rotatedImageCustom2);
                    return 1;
                }
    
                fread(rotatedImageCustom2, sizeof(unsigned char), windowWidth * windowHeight * 3, imageFile);

                fclose(imageFile);

                RotateImageCustom(rotatedImageCustom2, rotatedImageCustom2, windowWidth, windowHeight, degreesCustom2);

                FILE* rotatedFileCustom2 = fopen("rotated_image_custom2.raw", "wb");
                if (rotatedFileCustom2 == NULL)
                {
                    printf("File could not be opened!");
                    free(rotatedImageCustom2);
                    return 1;
                } 

                fwrite(rotatedImageCustom2, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedFileCustom2);
                fclose(rotatedFileCustom2);

                free(rotatedImageCustom2);
                break;
            case 7:
                printf("ROTATE WITH BILINEAR INTERPOLATION\n\n");
                printf("Enter the degrees: ");
                int degreesBilinear;
                scanf("%d", &degreesBilinear);
                printf("1. Siemens star\n");
                printf("2. Gradient\n");
                printf("Choose the image you want to rotate: ");
                int choiceBilinear;
                scanf("%d", &choiceBilinear);

                printf("Enter width of image: ");
                scanf("%d", &windowWidth);
                printf("Enter height of image: ");
                scanf("%d", &windowHeight);

                unsigned char* rotatedImageBilinear = (unsigned char*)malloc(windowWidth * windowHeight * 3);
                if (rotatedImageBilinear == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                if (choiceBilinear == 1)
                {
                    RotateImageBilinear(star, rotatedImageBilinear, windowWidth, windowHeight, degreesBilinear);

                    FILE* rotatedImageBilinearFile = fopen("rotated_image_bilinear.raw", "wb");
                    if (rotatedImageBilinearFile == NULL)
                    {
                        printf("File could not be opened!");
                        free(star);
                        free(rotatedImageBilinearFile);
                        return 1;
                    } 

                    fwrite(rotatedImageBilinear, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedImageBilinearFile);
                    fclose(rotatedImageBilinearFile);

                    free(star);
                    free(rotatedImageBilinear);
                }
                else
                {
                    RotateImageBilinear(gradient, rotatedImageBilinear, windowWidth, windowHeight, degreesBilinear);

                    FILE* rotatedImageBilinearFile = fopen("rotated_image_bilinear.raw", "wb");
                    if (rotatedImageBilinearFile == NULL)
                    {
                        printf("File could not be opened!");
                        free(gradient);
                        free(rotatedImageBilinear);
                        return 1;
                    } 

                    fwrite(rotatedImageBilinear, sizeof(unsigned char), windowWidth * windowHeight * 3, rotatedImageBilinearFile);
                    fclose(rotatedImageBilinearFile);

                    free(gradient);
                    free(rotatedImageBilinear);
                }

                break;
            case 8:
                printf("ROTATE DOWNLOADED IMAGE\n\n");

                int imWidth = 875;
                int imHeight = 652;

                unsigned char* im = (unsigned char*)malloc(imWidth * imHeight * 3);
                if (im == NULL)
                {
                    printf("Memory allocation failed!");
                    free(im);
                    return 1;
                }

                FILE* imF = fopen("example.raw", "rb");
                if (imF == NULL)
                {
                    printf("File could not be opened!");
                    free(im);
                    fclose(imF);
                    return 1;
                }

                fread(im, sizeof(unsigned char), imWidth * imHeight * 3, imF);
                fclose(imF);

                unsigned char* im2 = (unsigned char*)malloc(imWidth * imHeight * 3);
                if (im2 == NULL)
                {
                    printf("Memory allocation failed!");
                    free(im2);
                    return 1;
                }

                FILE* imF2 = fopen("example2.raw", "wb");
                if (imF2 == NULL)
                {
                    printf("File could not be opened!");
                    free(im2);
                    fclose(imF2);
                    return 1;
                }

                RotateImageBilinear(im, im2, imWidth, imHeight, 720);

                fwrite(im2, sizeof(unsigned char), imWidth * imHeight * 3, imF2);
                fclose(imF2);

                free(im);
                free(im2);

                break;
            case 9:
                printf("SOBEL FILTER HORIZONTAL\n\n");

                int imgWidth = 875;
                int imgHeight = 652;

                unsigned char* img = (unsigned char*)malloc(imgWidth * imgHeight);
                if (img == NULL)
                {
                    printf("Memory allocation failed!");
                    free(img);
                    return 1;
                }

                FILE* imgF = fopen("grayscaleimg.raw", "rb");
                if (imgF == NULL)
                {
                    printf("File could not be opened!");
                    free(img);
                    fclose(imgF);
                    return 1;
                }

                fread(img, sizeof(unsigned char), imgWidth * imgHeight, imgF);
                fclose(imgF);

                unsigned char* img2 = (unsigned char*)malloc(imgWidth * imgHeight);
                if (img2 == NULL)
                {
                    printf("Memory allocation failed!");
                    free(img2);
                    return 1;
                }

                FILE* imgF2 = fopen("sobelhorizontal.raw", "wb");
                if (imgF2 == NULL)
                {
                    printf("File could not be opened!");
                    free(img2);
                    fclose(imgF2);
                    return 1;
                }

                ApplySobelHorizontal(img, img2, imgWidth, imgHeight);

                fwrite(img2, sizeof(unsigned char), imgWidth * imgHeight, imgF2);
                fclose(imgF2);

                free(img);
                free(img2);

                break;
            case 10:
                printf("CONVERT RGB TO GRAYSCALE\n\n");

                int imageWidth = 875;
                int imageHeight = 652;

                unsigned char* ima = (unsigned char*)malloc(imageWidth * imageHeight * 3);
                if (ima == NULL)
                {
                    printf("Memory allocation failed!");
                    free(ima);
                    return 1;
                }

                FILE* imaF = fopen("example.raw", "rb");
                if (imaF == NULL)
                {
                    printf("File could not be opened!");
                    free(ima);
                    fclose(imaF);
                    return 1;
                }

                fread(ima, sizeof(unsigned char), imageWidth * imageHeight * 3, imaF);
                fclose(imaF);

                unsigned char* ima2 = (unsigned char*)malloc(imageWidth * imageHeight);
                if (ima2 == NULL)
                {
                    printf("Memory allocation failed!");
                    free(ima2);
                    return 1;
                }

                FILE* imaF2 = fopen("grayscaleimg.raw", "wb");
                if (imaF2 == NULL)
                {
                    printf("File could not be opened!");
                    free(ima2);
                    fclose(imaF2);
                    return 1;
                }

                ConvertImage(ima, ima2, imageWidth, imageHeight);

                fwrite(ima2, sizeof(unsigned char), imageWidth * imageHeight, imaF2);
                fclose(imaF2);

                free(ima);
                free(ima2);

                break;
            case 11:
                printf("SOBEL FILTER VERTICAL\n\n");

                int imagWidth = 875;
                int imagHeight = 652;

                unsigned char* imag = (unsigned char*)malloc(imagWidth * imagHeight);
                if (imag == NULL)
                {
                    printf("Memory allocation failed!");
                    free(imag);
                    return 1;
                }

                FILE* imagF = fopen("grayscaleimg.raw", "rb");
                if (imagF == NULL)
                {
                    printf("File could not be opened!");
                    free(imag);
                    fclose(imagF);
                    return 1;
                }

                fread(imag, sizeof(unsigned char), imagWidth * imagHeight, imagF);
                fclose(imagF);

                unsigned char* imag2 = (unsigned char*)malloc(imagWidth * imagHeight);
                if (imag2 == NULL)
                {
                    printf("Memory allocation failed!");
                    free(imag2);
                    return 1;
                }

                FILE* imagF2 = fopen("sobelvertical.raw", "wb");
                if (imagF2 == NULL)
                {
                    printf("File could not be opened!");
                    free(imag2);
                    fclose(imagF2);
                    return 1;
                }

                ApplySobelVertical(imag, imag2, imagWidth, imagHeight);

                fwrite(imag2, sizeof(unsigned char), imagWidth * imagHeight, imagF2);
                fclose(imagF2);

                free(imag);
                free(imag2);

                break;
            case 12:
                printf("FULL SOBEL FILTER\n\n");

                int imaggWidth = 875;
                int imaggHeight = 652;

                unsigned char* imagg = (unsigned char*)malloc(imaggWidth * imaggHeight);
                if (imagg == NULL)
                {
                    printf("Memory allocation failed!");
                    free(imagg);
                    return 1;
                }

                FILE* imaggF = fopen("grayscaleimg.raw", "rb");
                if (imaggF == NULL)
                {
                    printf("File could not be opened!");
                    free(imagg);
                    fclose(imaggF);
                    return 1;
                }

                fread(imagg, sizeof(unsigned char), imaggWidth * imaggHeight, imaggF);
                fclose(imaggF);

                unsigned char* imagg2 = (unsigned char*)malloc(imaggWidth * imaggHeight);
                if (imagg2 == NULL)
                {
                    printf("Memory allocation failed!");
                    free(imagg2);
                    return 1;
                }

                FILE* imaggF2 = fopen("sobel.raw", "wb");
                if (imaggF2 == NULL)
                {
                    printf("File could not be opened!");
                    free(imagg2);
                    fclose(imaggF2);
                    return 1;
                }

                ApplySobel(imagg, imagg2, imaggWidth, imaggHeight);

                fwrite(imagg2, sizeof(unsigned char), imaggWidth * imaggHeight, imaggF2);
                fclose(imaggF2);

                free(imagg);
                free(imagg2);

                break;
            case 0:
                isMenuOpen = false;
                printf("Goodbye!");

                break;
            default:
                printf("Invalid choice! Please try again.\n\n");

                break;
        }
    }

    return 0;
}