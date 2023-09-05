#include "sobelhorizontal.h"
#include <math.h>

void ApplySobelHorizontal(unsigned char* input, unsigned char* output, int width, int height)
{
    int sobelKernel[3][3] = {{-1, 0, 1},
                             {-2, 0, 2},
                             {-1, 0, 1}};

    for (int y = 1; y < height - 1; y++)
    {
        for (int x = 1; x < width - 1; x++)
        {
            int sum = 0;

            for (int ky = -1; ky <= 1; ky++)
            {
                for (int kx = -1; kx <= 1; kx++)
                {
                    int pixelOffset = (y + ky) * width + (x + kx);
                    int kernelValue = sobelKernel[ky + 1][kx + 1];

                    sum += input[pixelOffset] * kernelValue;
                }
            }

            int outputOffset = y * width + x;

            output[outputOffset] = sqrt(sum * sum);
        }
    }
}
