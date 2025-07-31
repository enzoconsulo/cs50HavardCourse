#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const int MAX = 3;

typedef struct {
    char *name;
    int votes;
}candidate;

int main(void){
    //candidate candidates[MAX];
    //for(int i = 0 ; i<MAX ; i++){
    // scanf("%s",candidates[i].name);
    // candidates[i].votes = 0;
    //}
    candidate candidates[MAX];  //adding manually to go faster in debug, to be right to the logic delete this and use code above
    candidates[0].name = "Alice"; candidates[0].votes = 0;
    candidates[1].name = "Bob"; candidates[1].votes = 0;
    candidates[2].name = "Charlie"; candidates[2].votes = 0;

    int electors = 0;
    printf("Number of electors: ");
    scanf("%i",&electors);

    printf("\n -Candidates: \n");
    for(int i = 0 ; i < MAX; i++){
        printf("%s \n",candidates[i].name);//print name from all candidates
    }

    for(int i = 0 ; i<electors ; i++){
        char name[20];
        printf("-Vote %i :",i+1);          //read candidate from user
        scanf("%19s",name);

        bool found = false;
        for(int j = 0 ; j < MAX ; j++){
            if(strcmp(name,candidates[j].name) == 0){
                candidates[j].votes++;      //search for candidate typed in valid candidates
                found = true;
                break;
            }
        }

        if(!found){
            printf("Candidate not found! Type again...\n");  //back to loop to retipe
            i--;
        }
    }

    int winnerIndex = 0, previousVoteNumber = 0;
    printf("\nResults:");
    for(int i = 0 ; i<MAX ; i++){
        printf("\n >%s : %i",candidates[i].name,candidates[i].votes);
        if(previousVoteNumber < candidates[i].votes){
            winnerIndex = i;                          //getting most voted candidate based on number of votes. Putting his index in winnerIndex
            previousVoteNumber = candidates[i].votes;
        }
    }

    bool draw = false;
    for(int i = 0 ; i<MAX ; i++){
        if(candidates[winnerIndex].votes == candidates[i].votes && winnerIndex != i){
            draw = true;                              //verifying if someone have the same number of votes from the winner. To set a draw
        }
    }

    if(draw){
        printf("\n\n         Draw!\n          \n");
        return 0;
    }
    printf("\n\n         Winner:\n          %s\n",candidates[winnerIndex].name);

}
