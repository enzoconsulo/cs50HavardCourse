#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
const int BLOCK = 512;

int main(int argc, char *argv[])
{

    if(argc != 2){
        printf("Usage: ./recover filename");
        return 1;
    }

    FILE *cardMemory = fopen(argv[1] , "r");            //open file typed in prompt
    if(cardMemory == NULL){
        printf("Error opening folder");                 //exception treatment to error in opening folder
        return 2;
    }

    BYTE *buffer = malloc(BLOCK);                       //alloc a buffer of size of 512(BLOCK) size

    char *filename = malloc(8);                          // create a string from filename ("###.jpeg" , 7 characters + 1 "/0" = 8)

    FILE *img = NULL;                                    //declare before starting read the file, to start making jpgs only when found the first one in file

    int i = 0;                                           //just initializing, can also use a for(int i = 0 ; fread(buffer , sizeof(BYTE), BLOCK, cardMemory) ; i++) but is incremented only if is a new jpg readed
    bool firstJpeg = false;

    size_t bytes_read;
    while((bytes_read = fread(buffer , sizeof(BYTE), BLOCK, cardMemory)) == BLOCK){ //read the content from cardMemory file until the file ending (verify if readed a exacly block to avoid catching thrash values from memory)

        if((buffer[0] == 0xff)
                && (buffer[1] == 0xd8)
                && (buffer[2] == 0xff)                                  //verify if is a jpeg format
                && ((buffer[3] & 0xf0) == 0xe0)){

            //is a jpeg
            if(firstJpeg == true)i++;                                   //discard first case to increment for next jpgs
            firstJpeg = true;

            sprintf(filename, "%03i.jpg", i);                //creates a name to file(new jpg)

             img = fopen(filename, "w");                //creates a new img file
             if(img == NULL){
                printf("Error opening folder");
                return 2;                   //exception treatment to error in opening folder
             }

            fwrite(buffer, sizeof(BYTE), BLOCK, img);   //write the first block into new img file

        }else{
            //is not a jpeg(or is the next block from one)
            if(img != NULL)
            fwrite(buffer, sizeof(BYTE), BLOCK, img);   //add next block until reach another jpg
        }

    }


    free(buffer);
    free(filename);
}
