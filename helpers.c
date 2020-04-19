#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float mean;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mean = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            mean = round(mean / 3);
            image[i][j].rgbtBlue = mean;
            image[i][j].rgbtGreen = mean;
            image[i][j].rgbtRed = mean;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(0.189 * image[i][j].rgbtBlue + 0.769 * image[i][j].rgbtGreen + 0.393 * image[i][j].rgbtRed);
            sepiaGreen = round(0.168 * image[i][j].rgbtBlue + 0.686 * image[i][j].rgbtGreen + 0.349 * image[i][j].rgbtRed);
            sepiaBlue = round(0.131 * image[i][j].rgbtBlue + 0.534 * image[i][j].rgbtGreen + 0.272 * image[i][j].rgbtRed);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int r, b, g;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (int) width / 2; j++)
        {
            b = image[i][j].rgbtBlue;
            g = image[i][j].rgbtGreen;
            r = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = b;
            image[i][width - j - 1].rgbtGreen = g;
            image[i][width - j - 1].rgbtRed = r;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    float meanR, meanB, meanG, number;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            number = 0;
            meanR = 0;
            meanB = 0;
            meanG = 0;

            for (int y = -1; y <= 1; y++)
            {
                for (int x = -1; x <= 1; x++)
                {
                    if (i + y >= 0 && i + y < height && j + x >= 0 && j + x < width)
                    {
                        number++;
                        meanR = meanR + copy[i][j].rgbtRed;
                        meanB = meanB + copy[i][j].rgbtBlue;
                        meanG = meanG + copy[i][j].rgbtGreen;
                    }
                }
            }

            image[i][j].rgbtBlue = round(meanB / number);
            image[i][j].rgbtGreen = round(meanG / number);
            image[i][j].rgbtRed = round(meanR / number);

        }
    }

    return;
}
