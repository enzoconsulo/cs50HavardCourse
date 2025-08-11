#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void){
    char p1[50];
    char p2[50];

    printf("Player 1: ");
    scanf("%s",p1);
    printf("Player 2: ");
    scanf("%s",p2);

    int score1 = compute_score(p1);
    int score2 = compute_score(p2);


    printf("------------------\n");
    if(score1 > score2){
        printf("Player 1 wins! \n Points: \n ->Player 1: %i\n ->Player 2: %i\n",score1,score2);
    }else if (score1 < score2){
        printf("Player 2 wins! \n Points: \n ->Player 1: %i\n ->Player 2: %i\n",score1,score2);
    }else{
        printf("Draw! \n Points: \n ->Player 1: %i\n ->Player 2: %i\n",score1,score2);
    }
}

int compute_score(string word){
    int sum = 0;

    for(int i = 0, n = strlen(word) ; i < n ; i++){
        if(isalpha(word[i])){
            word[i] = tolower(word[i]);
            int pointIndex = word[i]-'a';  // can put into brackets under, but defining here to better visualization
            sum += POINTS[pointIndex];
        }
    }
    return sum;
}
