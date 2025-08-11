#include <stdio.h>

int main(){

    int coins25 = 0;
    int coins10 = 0;
    int coins5 = 0;
    int coins1 = 0;

    float change = -1;

    while(change <0){
        printf("Change ammount: ");
        scanf("%f", &change);
    }

    change = change*100;


    if(change >=25){
        coins25 += change/25;
        change -= coins25 * 25;
    }

    if(change >=10){
        coins10 += change/10;
        change -= coins10 * 10;
    }

    if(change >=5){
        coins5 += change/5;
        change -= coins5 * 5;
    }

    if (change >= 1){
        coins1 += change/1;
        change -= coins1;
    }


    printf("25 coins: %i \n 10 coins: %i \n 5 coins: %i \n 1 coins: %i \n",coins25,coins10,coins5,coins1);

    return 0;
}
