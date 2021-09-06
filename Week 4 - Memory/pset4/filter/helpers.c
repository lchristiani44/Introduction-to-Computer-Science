#include "helpers.h"
#include <math.h>
#include <stdint.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgb_avrg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);

            image[i][j].rgbtBlue = rgb_avrg;
            image[i][j].rgbtGreen = rgb_avrg;
            image[i][j].rgbtRed = rgb_avrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393000 * image[i][j].rgbtRed + .769000 * image[i][j].rgbtGreen + .189000 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349000 * image[i][j].rgbtRed + .686000 * image[i][j].rgbtGreen + .168000 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272000 * image[i][j].rgbtRed + .534000 * image[i][j].rgbtGreen + .131000 * image[i][j].rgbtBlue);

            if (sepiaRed > 255.000)
            {
                image[i][j].rgbtRed = 255.000;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }


            if (sepiaGreen > 255.000)
            {
                image[i][j].rgbtGreen = 255.000;
            }
            else
            {

                image[i][j].rgbtGreen = sepiaGreen;
            }


            if (sepiaBlue > 255.000)
            {
                image[i][j].rgbtBlue = 255.000;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        BYTE  tempBlue;
        BYTE  tempGreen;
        BYTE  tempRed;
    } __attribute__((__packed__))
    RGBTEMP;

    RGBTEMP temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].tempBlue = image[i][width - j - 1].rgbtBlue;
            temp[i][j].tempGreen = image[i][width - j - 1].rgbtGreen;
            temp[i][j].tempRed = image[i][width - j - 1].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].tempBlue;
            image[i][j].rgbtGreen = temp[i][j].tempGreen;
            image[i][j].rgbtRed = temp[i][j].tempRed;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE extd[height][width];
    // extd = image; IS NOT NECESSARY!

    image[0][0].rgbtBlue = round((extd[0][0].rgbtBlue + extd[0][1].rgbtBlue + extd[1][0].rgbtBlue + extd[1][1].rgbtBlue) / 4.00);
    image[0][0].rgbtGreen = round((extd[0][0].rgbtGreen + extd[0][1].rgbtGreen + extd[1][0].rgbtGreen + extd[1][1].rgbtGreen) / 4.00);
    image[0][0].rgbtRed = round((extd[0][0].rgbtRed + extd[0][1].rgbtRed + extd[1][0].rgbtRed + extd[1][1].rgbtRed) / 4.00);

    image[height - 1][width - 1].rgbtBlue = round((extd[height - 1][width - 1].rgbtBlue + extd[height - 1][width - 1].rgbtBlue + extd[height - 1][width].rgbtBlue + extd[height][width - 1].rgbtBlue) / 4.00);
    image[height - 1][width - 1].rgbtGreen = round((extd[height - 1][width - 1].rgbtGreen + extd[height - 1][width - 1].rgbtGreen + extd[height - 1][width].rgbtGreen + extd[height][width - 1].rgbtGreen) / 4.00);
    image[height - 1][width - 1].rgbtRed = round((extd[height - 1][width - 1].rgbtRed + extd[height - 1][width - 1].rgbtRed + extd[height - 1][width].rgbtRed + extd[height][width - 1].rgbtRed) / 4.00);

    for (int j = 1; j < width - 1; j++)
    {
        image[0][j].rgbtBlue = round((extd[0][j].rgbtBlue + extd[0][j - 1].rgbtBlue + extd[1][j - 1].rgbtBlue + extd[1][j].rgbtBlue + extd[1][j + 1].rgbtBlue + extd[0][j + 1].rgbtBlue) / 6.00);
        image[0][j].rgbtGreen = round((extd[0][j].rgbtGreen + extd[0][j - 1].rgbtGreen + extd[1][j - 1].rgbtGreen + extd[1][j].rgbtGreen + extd[1][j + 1].rgbtGreen + extd[0][j + 1].rgbtGreen) / 6.00);
        image[0][j].rgbtRed = round((extd[0][j].rgbtRed + extd[0][j - 1].rgbtRed + extd[1][j - 1].rgbtRed + extd[1][j].rgbtRed + extd[1][j + 1].rgbtRed + extd[0][j + 1].rgbtRed) / 6.00);

        image[height - 1][j].rgbtBlue = round((extd[height - 1][j].rgbtBlue + extd[height - 1][j - 1].rgbtBlue + extd[height - 2][j - 1].rgbtBlue + extd[height - 2][j].rgbtBlue + extd[height - 2][j + 1].rgbtBlue + extd[height - 1][j + 1].rgbtBlue) / 6.00);
        image[height - 1][j].rgbtGreen = round((extd[height - 1][j].rgbtGreen + extd[height - 1][j - 1].rgbtGreen + extd[height - 2][j - 1].rgbtGreen + extd[height - 2][j].rgbtGreen + extd[height - 2][j + 1].rgbtGreen + extd[height - 1][j + 1].rgbtGreen) / 6.00);
        image[height - 1][j].rgbtRed = round((extd[height - 1][j].rgbtRed + extd[height - 1][j - 1].rgbtRed + extd[height - 2][j - 1].rgbtRed + extd[height - 2][j].rgbtRed + extd[height - 2][j + 1].rgbtRed + extd[height - 1][j + 1].rgbtRed) / 6.00);
    }

    for (int i = 1; i < height - 1; i++)
    {
        image[i][0].rgbtBlue = round((extd[i][0].rgbtBlue + extd[i - 1][0].rgbtBlue + extd[i - 1][1].rgbtBlue + extd[i][1].rgbtBlue + extd[i + 1][0].rgbtBlue + extd[i + 1][1].rgbtBlue) / 6.00);
        image[i][0].rgbtGreen = round((extd[i][0].rgbtGreen + extd[i - 1][0].rgbtGreen + extd[i - 1][1].rgbtGreen + extd[i][1].rgbtGreen + extd[i + 1][0].rgbtGreen + extd[i + 1][1].rgbtGreen) / 6.00);
        image[i][0].rgbtRed = round((extd[i][0].rgbtRed + extd[i - 1][0].rgbtRed + extd[i - 1][1].rgbtRed + extd[i][1].rgbtRed + extd[i + 1][0].rgbtRed + extd[i + 1][1].rgbtRed) / 6.00);

        image[i][width - 1].rgbtBlue = round((extd[i][width - 1].rgbtBlue + extd[i - 1][width - 1].rgbtBlue + extd[i - 1][width - 2].rgbtBlue + extd[i][width - 2].rgbtBlue + extd[i + 1][width - 2].rgbtBlue + extd[i + 1][width - 1].rgbtBlue) / 6.00);
        image[i][width - 1].rgbtGreen = round((extd[i][width - 1].rgbtGreen + extd[i - 1][width - 1].rgbtGreen + extd[i - 1][width - 2].rgbtGreen + extd[i][width - 2].rgbtGreen + extd[i + 1][width - 2].rgbtGreen + extd[i + 1][width - 1].rgbtGreen) / 6.00);
        image[i][width - 1].rgbtRed = round((extd[i][width - 1].rgbtRed + extd[i - 1][width - 1].rgbtRed + extd[i - 1][width - 2].rgbtRed + extd[i][width - 2].rgbtRed + extd[i + 1][width - 2].rgbtRed + extd[i + 1][width - 1].rgbtRed) / 6.00);
    }


    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
        image[i][j].rgbtBlue = round((extd[i][j].rgbtBlue + extd[i - 1][j - 1].rgbtBlue + extd[i - 1][j].rgbtBlue + extd[i - 1][j + 1].rgbtBlue + extd[i][j - 1].rgbtBlue + extd[i][j].rgbtBlue + extd[i][j + 1].rgbtBlue + extd[i + 1][j - 1].rgbtBlue + extd[i + 1][j].rgbtBlue + extd[i + 1][j + 1].rgbtBlue) / 10.00);
        image[i][j].rgbtGreen = round((extd[i][j].rgbtGreen + extd[i - 1][j - 1].rgbtGreen + extd[i - 1][j].rgbtGreen + extd[i - 1][j + 1].rgbtGreen + extd[i][j - 1].rgbtGreen + extd[i][j].rgbtGreen + extd[i][j + 1].rgbtGreen + extd[i + 1][j - 1].rgbtGreen + extd[i + 1][j].rgbtGreen + extd[i + 1][j + 1].rgbtGreen) / 10.00);
        image[i][j].rgbtRed = round((extd[i][j].rgbtRed + extd[i - 1][j - 1].rgbtRed + extd[i - 1][j].rgbtRed + extd[i - 1][j + 1].rgbtRed + extd[i][j - 1].rgbtRed + extd[i][j].rgbtRed + extd[i][j + 1].rgbtRed + extd[i + 1][j - 1].rgbtRed + extd[i + 1][j].rgbtRed + extd[i + 1][j + 1].rgbtRed) / 10.00);
        }
    }

    return;
}
