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
                        meanR = meanR + copy[i + y][j + x].rgbtRed;
                        meanB = meanB + copy[i + y][j + x].rgbtBlue;
                        meanG = meanG + copy[i + y][j + x].rgbtGreen;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height + 2][width + 2];
    float GxR, GxB, GxG, GyR, GyB, GyG, tempx, tempy;

    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
            {
                copy[i][j].rgbtBlue = 0;
                copy[i][j].rgbtGreen = 0;
                copy[i][j].rgbtRed = 0;
            }
            else
            {
                copy[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
                copy[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
                copy[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
            }
        }
    }

    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            GxR = 0;
            GxB = 0;
            GxG = 0;
            GyR = 0;
            GyB = 0;
            GyG = 0;

            for (int y = -1; y <= 1; y++)
            {
                for (int x = -1; x <= 1; x++)
                {
                    tempx = x;
                    tempy = y;
                    
                    if (y == 0)
                    {
                        tempx = tempx * 2;
                    }
                    
                    if (x == 0)
                    {
                        tempy = tempy * 2;
                    }
                    
                    GxR = GxR + tempx * copy[i + y][j + x].rgbtRed;
                    GxB = GxB + tempx * copy[i + y][j + x].rgbtBlue;
                    GxG = GxG + tempx * copy[i + y][j + x].rgbtGreen;
                    
                    GyR = GyR + tempy * copy[i + y][j + x].rgbtRed;
                    GyB = GyB + tempy * copy[i + y][j + x].rgbtBlue;
                    GyG = GyG + tempy * copy[i + y][j + x].rgbtGreen;
                
                }
            }
            
            GxR = GxR / 9;
            GxB = GxB / 9;
            GxG = GxG / 9;
                    
            GyR = GyR / 9;
            GyB = GyB / 9;
            GyG = GyG / 9;
            

            image[i - 1][j - 1].rgbtBlue = round(sqrt(GxB * GxB + GyB * GyB));
            image[i - 1][j - 1].rgbtGreen = round(sqrt(GxG * GxG + GyG * GyG));
            image[i - 1][j - 1].rgbtRed = round(sqrt(GxR * GxR + GyR * GyR));
            
            if (image[i - 1][j - 1].rgbtBlue > 255)
            {
                image[i - 1][j - 1].rgbtBlue = 255;
            }
            if (image[i - 1][j - 1].rgbtGreen > 255)
            {
                image[i - 1][j - 1].rgbtGreen = 255;
            }
            if (image[i - 1][j - 1].rgbtRed > 255)
            {
                image[i - 1][j - 1].rgbtRed = 255;
            }

        }
    }

    return;
}
