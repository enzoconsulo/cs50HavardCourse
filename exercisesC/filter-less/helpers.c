#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0 ; i < height ; i++){//for each pixel in image, convert to a average of his colors (to provide tons between white and black)
        for(int j = 0 ; j < width ; j++){

                                  //using 16 bits instead of "byte" to previne overflow
            uint16_t average = 0; // for example, if all rgb was 255(11111111) sum all of then will pass the 8 bits from "BYTE"
                                  //so we use 16 bits to previne, considerer that the maximum is 765(1011111101) with 10 bits (all values 255).

            average += image[i][j].rgbtBlue;
            average += image[i][j].rgbtGreen;    //sum into average all colors of this pixel
            average += image[i][j].rgbtRed;

            average /= 3;                        //divide for 3 to get a proportional black and white tone

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;     // set this proportional tone to all colors in this pixel
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0 ; i < height ; i++){      //for each pixel in image
        for(int j = 0 ; j < width/2 ; j++){ // considering that is a mutual change, "j" only want to traverse to te middle the vector

            RGBTRIPLE temp = image[i][j];         //put the image of the left(consider width/2) pixel in a temp variable

            image[i][j] = image[i][width-j];      // set the left pixel with the right pixel

            image[i][width-j] = temp;             // set the right pixel with left value(that was before added to temp)
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
