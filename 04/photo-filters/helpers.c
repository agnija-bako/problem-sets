#include "helpers.h"
#include "math.h"

//Apply different filters to images

//SOLUTION

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int value;
    float sum;
    //Loop through the image array to select every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Calculate the average value of red/green/blue on every pixel
            sum = image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen;
            float average = sum / 3;
            value = round(average);

            //Set that value of red, green and blue in the given pixel to the average
            image[i][j].rgbtRed = value;
            image[i][j].rgbtGreen = value;
            image[i][j].rgbtBlue = value;
        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    RGBTRIPLE first;
    RGBTRIPLE last;
    int i;
    int j;
    // Loop through image array to select every pixel in the image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            // Move all the pixels in the width from end of the array to the begining
            first = image[i][j];
            last = image[i][(width - 1) - j];

            temp[i][j] = first;
            first = last;
            image[i][j] = first;
            last = temp[i][j];
            image[i][(width - 1) - j] = last;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float sumRed = 0;
    float sumGreen = 0;
    float sumBlue = 0;
    int averageRed;
    int averageGreen;
    int averageBlue;
    int count = 0;
    RGBTRIPLE temp[height][width];

    //Loop thorugh the image array to select every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Loop through all the neihgboring pixels as long as they don't go over the edges
            for (int n = i - 1; n <= i + 1; n++)
            {
                if (n < 0 ||  n > height - 1)
                {
                    continue;
                }
                else
                {
                    for (int z = j - 1; z <= j + 1; z++)
                    {
                        if (z < 0  || z > width - 1)
                        {
                            continue;
                        }

                        //Save the sum of all edges for red/green/blue
                        else
                        {
                            sumRed = sumRed + image[n][z].rgbtRed;
                            sumGreen = sumGreen + image[n][z].rgbtGreen;
                            sumBlue = sumBlue + image[n][z].rgbtBlue;
                            count = count + 1;
                        }
                    }
                }
            }

            //Calculate the averages
            float avrg_r = sumRed / count;
            averageRed = round(avrg_r);
            float avrg_g = sumGreen / count;
            averageGreen = round(avrg_g);
            float avrg_b = sumBlue / count;
            averageBlue = round(avrg_b);

            //Set the averages to the temporary array to save the values but not modify the original array
            temp[i][j].rgbtRed = averageRed;
            temp[i][j].rgbtGreen = averageGreen;
            temp[i][j].rgbtBlue = averageBlue;

            //Reset the sum variables and count
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            count = 0;
        }
    }

    //Loop through every pixel of the image and apply the values from the temporary array
    for (int x = 0; x < height; x ++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtRed = temp[x][y].rgbtRed;
            image[x][y].rgbtGreen = temp[x][y].rgbtGreen;
            image[x][y].rgbtBlue = temp[x][y].rgbtBlue;

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int new_red_x;
    int new_green_x;
    int new_blue_x;
    int new_red_y;
    int new_green_y;
    int new_blue_y;
    int Gx [3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy [3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int x = 0;
    int y = 0;
    double sum_red_x = 0;
    double sum_green_x = 0;
    double sum_blue_x = 0;
    double sum_red_y = 0;
    double sum_green_y = 0;
    double sum_blue_y = 0;
    float result_red;
    float result_green;
    float result_blue;
    RGBTRIPLE temp[height][width];
    //Loop through every pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Loop through the surrounding pixels of the current pixel
            for (int n = i - 1; n <= i + 1; n++)
            {
                for (int z = j - 1; z <= j + 1; z++)
                {
                    //Locate any pixel that is on the edge and set it to 0
                    if (n < 0 ||  n > height - 1)
                    {
                        new_red_x = 0;
                        new_green_x = 0;
                        new_blue_x = 0;
                        y = y + 1;
                        continue;
                    }

                    if (z < 0  || z > width - 1)
                    {
                        new_red_x = 0;
                        new_green_x = 0;
                        new_blue_x = 0;
                        y = y + 1;
                        continue;
                    }

                    else
                    {
                        //Calculate new red/green/blue for Gx
                        new_red_x = Gx[x][y] * image[n][z].rgbtRed;
                        new_green_x = Gx[x][y] * image[n][z].rgbtGreen;
                        new_blue_x = Gx[x][y] * image[n][z].rgbtBlue;

                        //Calculate new red/green/blue for Gy
                        new_red_y = Gy[x][y] * image[n][z].rgbtRed;
                        new_green_y = Gy[x][y] * image[n][z].rgbtGreen;
                        new_blue_y = Gy[x][y] * image[n][z].rgbtBlue;

                        y = y + 1;

                    }

                    //Calculate rgbtRed/green/blue Gx sum
                    sum_red_x = sum_red_x + new_red_x;
                    sum_green_x = sum_green_x + new_green_x;
                    sum_blue_x = sum_blue_x + new_blue_x;

                    //Calculate rgbtRed/green/blue Gy sum
                    sum_red_y = sum_red_y + new_red_y;
                    sum_green_y = sum_green_y + new_green_y;
                    sum_blue_y = sum_blue_y + new_blue_y;


                }

                x = x + 1;
                y = 0;
            }

            //Calculate final value for rgbtRed/green/blue
            result_red = sqrtf(pow(sum_red_x, 2) + pow(sum_red_y, 2));
            result_green = sqrtf(pow(sum_green_x, 2) + pow(sum_green_y, 2));
            result_blue = sqrtf(pow(sum_blue_x, 2) + pow(sum_blue_y, 2));

            int round_red = round(result_red);
            int round_green = round(result_green);
            int round_blue = round(result_blue);

            //Make sure the value is not higher than 255
            if (round_red > 255)
            {
                round_red = 255;
            }

            if (round_green > 255)
            {
                round_green = 255;
            }

            if (round_blue > 255)
            {
                round_blue = 255;
            }

            //Assign it to a temporary array to not corrupt upcoming data
            temp[i][j].rgbtRed = round_red;
            temp[i][j].rgbtGreen = round_green;
            temp[i][j].rgbtBlue = round_blue;


            x = 0;
            sum_red_x = 0;
            sum_green_x = 0;
            sum_blue_x = 0;

            sum_red_y = 0;
            sum_green_y = 0;
            sum_blue_y = 0;
        }
    }


    //Loop through every pixel of the image and apply the values from the temporary array
    for (int m = 0; m < height; m ++)
    {
        for (int l = 0; l < width; l++)
        {
            image[m][l].rgbtRed = temp[m][l].rgbtRed;
            image[m][l].rgbtGreen = temp[m][l].rgbtGreen;
            image[m][l].rgbtBlue = temp[m][l].rgbtBlue;

        }
    }
    return;
}
