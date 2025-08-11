#include <stdio.h>

int main(){

    int initialPopulation = 0;
    while(initialPopulation < 8){
        printf("Start size: ");
        scanf("%i",&initialPopulation);
    }

    int finalPopulation = 0;
    while(finalPopulation < initialPopulation){
        printf("End size: ");
        scanf("%i",&finalPopulation);
    }

    int years = 0;
    int population = initialPopulation;

    while(population < finalPopulation){
        int growthByYear = population/3;
        int deadByYear = population/4;

        int totalgrowth = growthByYear - deadByYear;

        population += totalgrowth;

        years++;
    }


    printf("Years : %i\n",years);


}
