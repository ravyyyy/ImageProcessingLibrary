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
    
    FILE* rawFile;
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
        printf("4. Rotate with custom degrees (incomplete)\n");
        printf("5. Rotate a specified input\n");
        printf("6. Rotate with custom degrees using bilinear interpolation\n");
        printf("7. Rotate downloaded input\n");
        printf("8. Sobel filter horizontal\n");
        printf("9. Convert RGB input to Grayscale\n");
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

                rawFile = fopen("siemens_star.raw", "wb");

                if (rawFile == NULL) 
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    return 1;
                }

                fwrite(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                fclose(rawFile);

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

                rawFile = fopen("gradient.raw", "wb");
                if (rawFile == NULL)
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    return 1;
                }

                fwrite(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                FreeImage(input);
                fclose(rawFile);

                break;
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

                //AllocImage(input, windowWidth, windowHeight);

                if (choiceCustom == 1)
                {
                    rawFile = fopen("gradient.raw", "rb");

                    if (rawFile == NULL)
                    {
                        printf("File could not be opened!");
                        return 1;
                    }

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                    output = RotateinputCustomDegrees(input, windowWidth, windowHeight, degrees);
                }
                else
                {
                    rawFile = fopen("siemens_star.raw", "rb");

                    if (rawFile == NULL)
                    {
                        printf("File could not be opened!");
                        return 1;
                    }

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                    output = RotateinputCustomDegrees(input, windowWidth, windowHeight, degrees);
                }

                inputFile = fopen("rotated_input_custom.raw", "wb");
                if (inputFile == NULL)
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    FreeImage(output);
                    fclose(inputFile);
                    return 1;
                } 

                fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                fclose(inputFile);

                free(input->data);
                FreeImage(output);

                break;
            case 4:
                printf("ROTATE CUSTOM (incomplete)\n\n");
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

                //AllocImage(input, windowWidth, windowHeight);

                if (choiceCustom == 1)
                {
                    rawFile = fopen("gradient.raw", "rb");

                    if (rawFile == NULL)
                    {
                        printf("File could not be opened!");
                        return 1;
                    }

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                    output = RotateinputCustomDegreesIncomplete(input, windowWidth, windowHeight, degrees);                    
                }
                else
                {
                    rawFile = fopen("siemens_star.raw", "rb");

                    if (rawFile == NULL)
                    {
                        printf("File could not be opened!");
                        return 1;
                    }

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);

                    output = RotateinputCustomDegreesIncomplete(input, windowWidth, windowHeight, degrees);
                }

                inputFile = fopen("rotated_input_custom_incomplete.raw", "wb");
                if (inputFile == NULL)
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    FreeImage(output);
                    fclose(inputFile);
                    return 1;
                } 

                fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                fclose(inputFile);

                free(input->data);
                FreeImage(output);

                break;
            case 5:
                printf("ROTATE CUSTOM input\n\n");
                printf("Enter name of file: ");
                scanf("%s", fileName);
    
                printf("Enter the degrees: ");
                scanf("%d", &degrees);

                printf("Enter width of input: ");
                scanf("%d", &windowWidth);
                printf("Enter height of input: ");
                scanf("%d", &windowHeight);

                inputFile = fopen(fileName, "rb");
                if (inputFile == NULL)
                {
                    printf("input file could not be opened!");
                    return 1;
                }

                //AllocImage(input, windowWidth ,windowHeight);
                fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);

                fclose(inputFile);

                output = RotateinputCustomFile(input, windowWidth, windowHeight, degrees);

                FILE* rawFile = fopen("rotated_input_custom2.raw", "wb");

                if (rawFile == NULL)
                {
                    printf("File could not be opened!");
                    FreeImage(input);
                    FreeImage(output);
                    return 1;
                } 

                fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                fclose(rawFile);

                free(input->data);
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

                //AllocImage(input, windowWidth, windowHeight);
                if (input->data == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                if (choiceCustom == 1)
                {
                    inputFile = fopen("gradient.raw","rb");

                    if (inputFile == NULL)
                    {
                        printf("File can not be opened!");
                        return 1;
                    }

                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }
                else
                {
                    inputFile = fopen("siemens_star.raw", "rb");

                    if (inputFile == NULL)
                    {
                        printf("File can not be opened!");
                        return 1;
                    }
                    
                    fread(input->data, sizeof(unsigned char), windowWidth * windowHeight * 3, inputFile);
                }

                output = RotateBilinear(input, windowWidth, windowHeight, degrees);

                rawFile = fopen("rotate_bilinear.raw", "wb");

                if (rawFile == NULL)
                {
                    printf("File can not be opened!");
                    FreeImage(output);
                    return 1;
                }

                fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                fclose(rawFile);

                free(input->data);
                FreeImage(output);

                break;
            case 7:
                printf("ROTATE DOWNLOADED input\n\n");

                printf("Enter name of file: ");
                scanf("%s", fileName);

                printf("Enter the degrees: ");
                scanf("%d", &degrees);
                
                printf("Enter width of input: ");
                scanf("%d", &windowWidth);
                printf("Enter height of input: ");
                scanf("%d", &windowHeight);

                //AllocImage(input, windowWidth, windowHeight);
                if (input->data == NULL)
                {
                    printf("Memory allocation failed!");
                    return 1;
                }

                inputFile = fopen(fileName, "rb");
                if (inputFile == NULL)
                {
                    printf("File could not be opened!");
                    free(input->data);
                    return 1;
                }

                output = RotateBilinear(input, windowWidth, windowHeight, degrees);

                rawFile = fopen("rotate_bilinear_custom.raw", "wb");

                if (rawFile == NULL)
                {
                    printf("File can not be opened!");
                    FreeImage(output);
                    return 1;
                }
                
                fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                fclose(rawFile);

                free(input->data);
                FreeImage(output);

                break;*/
            case 8:
                printf("SOBEL FILTER HORIZONTAL\n\n");

                ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

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

                AllocImage(&output, windowWidth, windowHeight, type);
                ApplySobelHorizontalImage(input, output);

                rawFile = fopen("sobel_horizontal.raw", "wb");
                CheckFile(rawFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, rawFile);
                }
                
                fclose(rawFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 9:
                printf("CONVERT RGB TO GRAYSCALE\n\n");

                ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

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

                AllocImage(&output, windowWidth, windowHeight, type);
                ApplyConvertImage(input, output);

                rawFile = fopen("grayscaleimg.raw", "wb");
                CheckFile(rawFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, rawFile);
                }
                
                fclose(rawFile);

                FreeImage(input);
                FreeImage(output);

                break;
            case 10:
                printf("SOBEL FILTER VERTICAL\n\n");

                ReadWindow(fileName, &windowWidth, &windowHeight, &inputTypeChoice);

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

                AllocImage(&output, windowWidth, windowHeight, type);
                ApplySobelVerticalImage(input, output);

                rawFile = fopen("sobel_vertical.raw", "wb");
                CheckFile(rawFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, rawFile);
                }
                
                fclose(rawFile);

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

                AllocImage(&output, windowWidth, windowHeight, type);
                ApplySobelImage(input, output);

                rawFile = fopen("sobel.raw", "wb");
                CheckFile(rawFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, rawFile);
                }
                
                fclose(rawFile);

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

                AllocImage(&output, windowWidth, windowHeight, type);
                Median(input, output);

                rawFile = fopen("median_filter.raw", "wb");
                CheckFile(rawFile, &input, &output);

                if (type == RGB)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight * 3, rawFile);
                }
                else if (type == Grayscale)
                {
                    fwrite(output->data, sizeof(unsigned char), windowWidth * windowHeight, rawFile);
                }
                fclose(rawFile);

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