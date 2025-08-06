#include "helpers.h"
#include <math.h> // to use round() in sepia

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0 ; i < height ; i++){//for each pixel in image, convert to a average of his colors (to provide tons between white and black)
        for(int j = 0 ; j < width ; j++){

                                  //using 16 bits instead of "BYTE" to previne overflow
            uint16_t average = 0; // for example, if all rgb was 255(11111111) sum all of then will pass the 8 bits from "BYTE"
                                  //so we use 16 bits to previne, considerer that the maximum is 765(1011111101) with 10 bits (all 3 values as 255).

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
    for(int i = 0 ; i < height ; i++){//for each pixel in image, apply the formula to each color
        for(int j = 0 ; j < width ; j++){

            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalGreen = image[i][j].rgbtGreen;    //set the original colors to variables to multiply in sepia formula(just to comfort, but can also use directly in formula)
            BYTE originalBlue = image[i][j].rgbtBlue;

            //sepia formula:
            int sepiaRed = round((0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue));
            int sepiaGreen = round((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue)); //provided in the exercise statement
            int sepiaBlue = round((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue));  //used "round" to get the rounded integer (as asked in exercise statement)

            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;  //check if any value exceed 255 (max value to a color index)
            if (sepiaBlue > 255) sepiaBlue = 255;


            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;      //set after formula color to this pixel
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
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
    for(int i = 0 ; i < height ; i++){//for each pixel in image, convert to a average of his adjacents (and his) values
        for(int j = 0 ; j < width ; j++){

            //looklike the grayscale logic, but instead of used same average to every color, each color has his own changes:

            uint16_t averageB = 0; //using 16 bits instead of "BYTE" to previne overflow
            uint16_t averageG = 0; // for example, if all rgb was 255(11111111) sum all of then will pass the 8 bits from "BYTE"
            uint16_t averageR = 0; //so we use 16 bits to previne, considerer that the maximum is 2.295(100011110111) with 12 bits (all 9 values as 255).


            int usedAdjacents = 0; //to save the number of used adjacents to use in average calculation

            //actual term
            //       x   y   z
            //       a  (#)  b          "#" is the actual term
            //       c   d   e
            averageB += image[i][j].rgbtBlue;
            averageG += image[i][j].rgbtGreen;
            averageR += image[i][j].rgbtRed;
            usedAdjacents++;


            //Three Adjacents Above
            //      (x) (y) (z)
            //       a   #   b          "#" is the actual term
            //       c   d   e
            for(int k = -1; k <= 1 ; k++){
                if( (i-1 >= 0) && (j+k >= 0) && (j+k < width)){
                    averageB += image[i-1][j+k].rgbtBlue;
                    averageG += image[i-1][j+k].rgbtGreen;
                    averageR += image[i-1][j+k].rgbtRed;
                    usedAdjacents++;
                }
            }

            //Three Adjacents Under
            //       x   y   z
            //       a   #   b          "#" is the actual term [i][j]
            //      (c) (d) (e)
            for(int k = -1; k <= 1 ; k++){
                if( (i+1 < height) && (j+k >= 0) && (j+k < width)){
                    averageB += image[i+1][j+k].rgbtBlue;
                    averageG += image[i+1][j+k].rgbtGreen;
                    averageR += image[i+1][j+k].rgbtRed;
                    usedAdjacents++;
                }
             }


            //left side
            //       x   y   z
            //      (a)  #   b          "#" is the actual term [i][j]
            //       c   d   e
             if((j-1 >= 0)){
                    averageB += image[i][j-1].rgbtBlue;
                    averageG += image[i][j-1].rgbtGreen;
                    averageR += image[i][j-1].rgbtRed;
                    usedAdjacents++;
            }

            //right side
            //       x   y   z
            //       a   #  (b)          "#" is the actual term [i][j]
            //       c   d   e
             if((j+1 < width)){
                    averageB += image[i][j+1].rgbtBlue;
                    averageG += image[i][j+1].rgbtGreen;
                    averageR += image[i][j+1].rgbtRed;
                    usedAdjacents++;
            }


            averageB /= usedAdjacents;
            averageG /= usedAdjacents;      //get the average with usedAdjacents (the ones who was valids)
            averageR /= usedAdjacents;

            image[i][j].rgbtBlue = averageB;
            image[i][j].rgbtGreen = averageG;     // set the color to the actual term
            image[i][j].rgbtRed = averageR;
        }
    }

    return;
}
