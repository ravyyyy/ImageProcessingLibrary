#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "API/inc/api.h"

ImageType ReadWindow(char fileName[], int* windowWidth, int* windowHeight, int* inputTypeChoice)
{
    printf("Enter name of file: ");
    scanf("%s", fileName);
                
    printf("Enter width of input: ");
    scanf("%d", windowWidth);
    printf("Enter height of input: ");
    scanf("%d", windowHeight);
                
    printf("Enter type of input (0 for RGB, 1 for Grayscale): ");
    scanf("%d", inputTypeChoice);
                
    if (*inputTypeChoice == 0) 
    {
        return RGB;
    }
    else if (*inputTypeChoice == 1) 
    {
        return Grayscale;
    } 
    printf("Invalid input type choice!");
    return Invalid;
}

int CheckFile(FILE* file, Image** input, Image** output)
{
    if (file == NULL)
    {
        printf("File can not be opened!");
        FreeImage((*input));
        FreeImage((*output));
        fclose(file);
        return 1;
    }

    return 0;
}

int main()
{
    Image* input = NULL;
    Image* output = NULL;

    int windowWidth;
    int windowHeight;
    int starRadius;
    int linesNumber;
    int columnsNumber;
    int userChoice;
    int degrees;
    int choiceCustom;
    int inputTypeChoice;

    bool isMenuOpen = true;
    
    FILE* outputFile;
    FILE* inputFile;

    char fileName[100];
    
    ImageType type;
    AllocationStatus status;

    while(isMenuOpen)
    {
        printf("MENU:\n");
        printf("1. Draw a Siemens Star\n");
        printf("2. Draw a Gradient\n");
        printf("3. Rotate with custom degrees\n");
        printf("4. Rotate Gradient OR Siemens Star (incomplete)\n");
        printf("5. Rotate a specified image\n");
        printf("6. Rotate with custom degrees using bilinear interpolation\n");
        printf("7. Rotate downloaded image\n");
        printf("8. Sobel filter horizontal\n");
        printf("9. Convert RGB image to Grayscale\n");
        printf("10. Sobel filter vertical\n");
        printf("11. Full Sobel filter\n");
        printf("12. Median filter\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        switch(userChoice)
        {
            /*case 1:
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

                input = CreateSiemensStar(windowWidth, windowHeight, starRadius, linesNumber);

                if (input == NULL) 
                {
                    printf("Memory allocation failed for siemens star!");
                    return 1;
                }

                outputFile = fopen("siemens_star.raw", "wb");

                if (outputFile == NULL) 
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    return 1;
                }

                fwrite(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);

                fclose(outputFile);

                break;
            case 2:
                printf("GRADIENT\n\n");
                printf("Enter the width: ");
                scanf("%d", &windowWidth);
                printf("Enter the height: ");
                scanf("%d", &windowHeight);
                printf("Enter the number of columns: ");
                scanf("%d", &columnsNumber);

                input = CreateGradientinput(windowWidth, windowHeight, columnsNumber);

                if (input == NULL) 
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                outputFile = fopen("gradient.raw", "wb");
                if (outputFile == NULL)
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    return 1;
                }

                fwrite(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);

                FreeImage(input);
                fclose(outputFile);

                break;*/
            case 3:
                printf("ROTATE CUSTOM\n\n");
                printf("Enter the degrees: ");
                scanf("%d", &degrees);
                printf("1. Gradient\n");
                printf("2. Siemens star\n");
                printf("Choose the input you want to rotate: ");
                scanf("%d", &choiceCustom);

                printf("Enter width of input: ");
                scanf("%d", &windowWidth);
                printf("Enter height of input: ");
                scanf("%d", &windowHeight);

                printf("Enter type of input (0 for RGB, 1 for Grayscale): ");
                scanf("%d", &inputTypeChoice);

                status = AllocImage(&input, windowWidth, windowHeight, inputTypeChoice);

                if (choiceCustom == 1)
                {
                    inputFile = fopen("gradient.raw","rb");
                    CheckFile(inputFile, &input, &output);

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else
                {
                    inputFile = fopen("siemens_star.raw", "rb");
                    CheckFile(inputFile, &input, &output);
                    
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }

                status = AllocImage(&output, windowWidth, windowHeight, inputTypeChoice);
                RotateImageCustomDegrees(input, output, degrees);

                outputFile = fopen("rotate_custom_degrees.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (choiceCustom == 1)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 4:
                printf("ROTATE Gradient OR Siemens Star (incomplete)\n\n");
                printf("Enter the degrees: ");
                scanf("%d", &degrees);
                printf("1. Gradient\n");
                printf("2. Siemens star\n");
                printf("Choose the input you want to rotate: ");
                scanf("%d", &choiceCustom);

                printf("Enter width of input: ");
                scanf("%d", &windowWidth);
                printf("Enter height of input: ");
                scanf("%d", &windowHeight);

                printf("Enter type of input (0 for RGB, 1 for Grayscale): ");
                scanf("%d", &inputTypeChoice);

                status = AllocImage(&input, windowWidth, windowHeight, inputTypeChoice);

                if (choiceCustom == 1)
                {
                    inputFile = fopen("gradient.raw","rb");
                    CheckFile(inputFile, &input, &output);

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else
                {
                    inputFile = fopen("siemens_star.raw", "rb");
                    CheckFile(inputFile, &input, &output);
                    
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }

                status = AllocImage(&output, windowWidth, windowHeight, inputTypeChoice);
                RotateImageCustomDegreesIncomplete(input, output, degrees);

                outputFile = fopen("rotate_incomplete.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (choiceCustom == 1)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 5:
                printf("ROTATE CUSTOM IMAGE\n\n");
                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);
                printf("Enter the degrees: ");
                scanf("%d", &degrees);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);

                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                RotateImageCustomFile(input, output, degrees);

                outputFile = fopen("rotate_custom_image.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 6:
                printf("ROTATE WITH BILINEAR INTERPOLATION\n\n");
                printf("Enter the degrees: ");
                scanf("%d", &degrees);
                printf("1. Gradient\n");
                printf("2. Siemens Star\n");
                printf("Choose the input you want to rotate: ");
                scanf("%d", &choiceCustom);

                printf("Enter width of input: ");
                scanf("%d", &windowWidth);
                printf("Enter height of input: ");
                scanf("%d", &windowHeight);

                printf("Enter type of input (0 for RGB, 1 for Grayscale): ");
                scanf("%d", &inputTypeChoice);

                status = AllocImage(&input, windowWidth, windowHeight, inputTypeChoice);

                if (choiceCustom == 1)
                {
                    inputFile = fopen("gradient.raw","rb");
                    CheckFile(inputFile, &input, &output);

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else
                {
                    inputFile = fopen("siemens_star.raw", "rb");
                    CheckFile(inputFile, &input, &output);
                    
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }

                status = AllocImage(&output, windowWidth, windowHeight, inputTypeChoice);
                RotateBilinear(input, output, degrees);

                outputFile = fopen("rotate_bilinear_grayscale_or_siemens_star.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (choiceCustom == 1)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 7:
                printf("ROTATE DOWNLOADED Image\n\n");

                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);
                printf("Enter the angle for rotation: ");
                scanf("%d", &degrees);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);

                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                RotateBilinear(input, output, degrees);

                outputFile = fopen("downloaded_image_rotated.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 8:
                printf("SOBEL FILTER HORIZONTAL\n\n");

                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);

                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                ApplySobelHorizontalImage(input, output);

                outputFile = fopen("sobel_horizontal.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 9:
                printf("CONVERT RGB TO GRAYSCALE\n\n");

                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);
                
                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                ApplyConvertImage(input, output);

                outputFile = fopen("grayscaleimg.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 10:
                printf("SOBEL FILTER VERTICAL\n\n");

                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);

                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                ApplySobelVerticalImage(input, output);

                outputFile = fopen("sobel_vertical.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 11:
                printf("FULL SOBEL FILTER\n\n");

                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);
                
                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                ApplySobelImage(input, output);

                outputFile = fopen("sobel.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 12:
                printf("MEDIAN FILTER\n\n");

                type = ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

                inputFile = fopen(fileName, "rb");
                CheckFile(inputFile, &input, &output);

                status = AllocImage(&input, windowWidth, windowHeight, type);

                if (type == RGB)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else if (type == Grayscale)
                {
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight, inputFile);
                }
                fclose(inputFile);

                status = AllocImage(&output, windowWidth, windowHeight, type);
                Median(input, output);

                outputFile = fopen("median_filter.raw", "wb");
                CheckFile(outputFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, outputFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, outputFile);
                }
                fclose(outputFile);

                FreeImage(input);
                FreeImage(output);

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