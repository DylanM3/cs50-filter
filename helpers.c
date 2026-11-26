#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            float pixelRed = image[i][j].rgbtRed;
            float pixelGreen = image[i][j].rgbtGreen;
            float pixelBlue = image[i][j].rgbtBlue;

            float rounding = (pixelRed + pixelGreen + pixelBlue) / 3.0;

            int averagePixel = round(rounding);

            // Update pixel values
            image[i][j].rgbtRed = averagePixel;
            image[i][j].rgbtGreen = averagePixel;
            image[i][j].rgbtBlue = averagePixel;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            float pixelRed = image[i][j].rgbtRed;
            float pixelGreen = image[i][j].rgbtGreen;
            float pixelBlue = image[i][j].rgbtBlue;

            float sepiaRed = (0.393 * pixelRed) + (0.769 * pixelGreen) + (0.189 * pixelBlue);
            float sepiaGreen = (0.349 * pixelRed) + (0.686 * pixelGreen) + (0.168 * pixelBlue);
            float sepiaBlue = (0.272 * pixelRed) + (0.534 * pixelGreen) + (0.131 * pixelBlue);

            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);

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

            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempWidth = width;
    int middle = width / 2;

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        tempWidth = width;

        for (int j = 0; j < tempWidth; j++)
        {
            if (tempWidth > middle)
            {
                tempWidth--;

                // Swap pixels
                RGBTRIPLE tempHolder = image[i][j];
                image[i][j] = image[i][tempWidth];
                image[i][tempWidth] = tempHolder;
            }
            else
            {
                break;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    RGBTRIPLE pixels[height][width];

    float surroundingPixels = 0;

    float totalRed = 0;
    float totalGreen = 0;
    float totalBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) // Iterate Height
    {
        for (int j = 0; j < width; j++) // Iterate Width
        {
            for (int k = i - 1; k < i + 2; k++) // Iterate 3 Rows
            {
                for (int l = j - 1; l < j + 2; l++) // Iterate 3 Columns
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        pixels[k][l] = image[k][l];

                        // Increase total RGB
                        totalRed += copy[k][l].rgbtRed;
                        totalGreen += copy[k][l].rgbtGreen;
                        totalBlue += copy[k][l].rgbtBlue;

                        surroundingPixels++;
                    }
                }
            }
            // Average Calculation
            float averageRed = totalRed / surroundingPixels;
            float averageGreen = totalGreen / surroundingPixels;
            float averageBlue = totalBlue / surroundingPixels;

            // Round Averages
            int finalRed = round(averageRed);
            int finalGreen = round(averageGreen);
            int finalBlue = round(averageBlue);

            // Update Pixels
            image[i][j].rgbtRed = finalRed;
            image[i][j].rgbtGreen = finalGreen;
            image[i][j].rgbtBlue = finalBlue;

            // Reset Variables
            totalRed = 0;
            totalGreen = 0;
            totalBlue = 0;
            surroundingPixels = 0;
        }
    }
}
