// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;



int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t *header = malloc(HEADER_SIZE);              //alloc on memory heap HEADER_SIZE elements of type uint8_t


    /*for (int i = 0; i < HEADER_SIZE; i++) {           //-> example for making one per one read and write of each byte on headersize:
                                                        //read 1 by 1 and write 1 per 1 too;
        fread(&header[i], sizeof(uint8_t), 1, input);   //its necessary to use "&header[i]" because you want to passa the pointer from each element from header
    }                                                   // (different to the another type under, that you pass only the first address and the size to copy)

    for(int i = 0 ; i < HEADER_SIZE; i++){
        fwrite(&header[i] , sizeof(uint8_t), 1, output);
    }
     */

    fread(header, sizeof(uint8_t), HEADER_SIZE, input); //here, different from above, you copy all the uint8_t elements in a length of HEADER_SIZE
                                                        // starting on addres header (pointer) to header[43] in this case


    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);//and than write the HEADER_SIZE length of uint8_t elements to output file

    int16_t buffer;

    while(fread(&buffer , sizeof(int16_t), 1, input)){
        buffer = buffer*factor;                           //here is the same in both. Bcs you must change byte per byte using the factor
        fwrite(&buffer , sizeof(int16_t) , 1 , output);   //    and you can't modify all in the same time(or at least i don't know how haha)
    }

    // Close files
    free(header);                                         //free the heap memory allocated
    
    fclose(input);
    fclose(output);
}
