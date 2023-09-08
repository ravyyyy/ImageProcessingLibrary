#include "medianfilter.h"

unsigned char MedianF(unsigned char arr[]) 
{
    for (int i = 0; i < 9 - 1; i++) {
        for (int j = 0; j < 9 - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                unsigned char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr[4];
}

void MedianFilter(unsigned char* input, unsigned char* output, int width, int height) 
{
    for (int y = 1; y < height - 1; y++)
    {
        for (int x = 1; x < width - 1; x++) 
        {
            unsigned char neighborhood[9];

            int index = 0;
            for (int j = -1; j <= 1; j++) 
            {
                for (int i = -1; i <= 1; i++) 
                {
                    neighborhood[index] = input[(y + j) * width + (x + i)];
                    index++;
                }
            }

            output[y * width + x] = MedianF(neighborhood);
        }
    }
}