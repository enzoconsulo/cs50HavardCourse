#include <stdio.h>

int main(){

    int height = -1;

    while(height <= 0 || height > 8){
        printf("Height : ");
        scanf("%i", &height);
    }

    for (int i = 0 ; i<height+1 ; i++){

        for(int j=0; j<height-i;j++){
            printf(" ");              //Spaces to left piramid
        }

        for(int j=0; j<i ; j++){
            printf("#");               // left piramid
        }
        printf(" ");

        for(int j=0; j<i ; j++){
            printf("#");               // right piramid
        }

        printf("\n");
    }
}


