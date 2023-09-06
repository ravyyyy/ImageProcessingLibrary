#include "sobel.h"

void ApplySobel(unsigned char* input, unsigned char* output, int width, int height)
{
    int sobelKernelVertical[3][3] = {{-1, -2, -1},
                                     {0, 0, 0},
                                     {1, 2, 1}};

    int sobelKernelHorizontal[3][3] = {{-1, 0, 1},
                                       {-2, 0, 2},
                                       {-1, 0, 1}};

    for (int y = 1; y < height - 1; y++)
    {
        for (int x = 1; x < width - 1; x++)
        {
            int sumVertical = 0;
            int sumHorizontal = 0;

            for (int ky = -1; ky <= 1; ky++)
            {
                for (int kx = -1; kx <= 1; kx++)
                {
                    int pixelOffset = (y + ky) * width + (x + kx);
                    int kernelValueVertical = sobelKernelVertical[ky + 1][kx + 1];
                    int kernelValueHorizontal = sobelKernelHorizontal[ky + 1][kx + 1];

                    sumVertical += input[pixelOffset] * kernelValueVertical;
                    sumHorizontal += input[pixelOffset] * kernelValueHorizontal;
                }
            }

            int outputOffset = y * width + x;

            output[outputOffset] = sqrt(sumVertical * sumVertical + sumHorizontal * sumHorizontal);
        }
    }
}
