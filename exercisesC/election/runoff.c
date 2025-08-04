#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0 ; i<candidate_count ; i++){           //for each candidate in election

        if(strcmp(candidates[i].name,name) == 0){        //compare name typed with each candidate in election

            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for(int i = 0 ; i<voter_count ; i++){                 //line of matrix preferences

        for(int j=0 ; j<candidate_count ; j++){           //column of matrix preferences

            int candidateIndex = preferences[i][j];       //for each voter, transverse all preference candidates until find a non-eliminated candidate

            if(candidates[candidateIndex].eliminated == false){

                candidates[candidateIndex].votes++;         //if wasn't eliminated, increments votes count
                break;
            }
        }

    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int minVotesToWin = (voter_count/2) + 1;                //gets the min quantity to win the election (more than half)
    for(int i = 0 ; i < candidate_count ;i++){

        if (candidates[i].votes >= minVotesToWin){          //compare if is bigger or equal the min quantity to win the election

            printf("\n\nWinner is %s\n",candidates[i].name);
            printf("Results:");
            for(int x = 0; x<candidate_count ; x++){

                if(candidates[x].eliminated == false){
                    printf("\n%s : %i", candidates[x].name , candidates[x].votes);
                }else{
                    printf("\n%s : ELIMINATED\n", candidates[x].name);
                }

            }
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minVotes;

    for(int i = 0 ; i < candidate_count ; i++){

        if(candidates[i].eliminated == false){
            minVotes = candidates[i].votes;       //just for initialize minVotes with a value, should only need to be non-eliminated value
            break;                                //next step will compare with others non-eliminated candidates, so whatever the value, should only be valid
        }
    }

    for(int i = 0 ; i < candidate_count ; i++){

        if(candidates[i].votes < minVotes && candidates[i].eliminated == false){
            minVotes = candidates[i].votes;        //make a loop into the candidates and define the minimal votes number of non-eliminated candidates
        }
    }

    return minVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for(int i = 0 ; i<candidate_count ; i++){                                   //loop to determinate if every valid candidate have the same number of votes
        if (candidates[i].votes != min && candidates[i].eliminated == false){   //(bcs of the function min, to be a tie, the remaining candidates at least will have "min" number of votes)
            return false;                                                       //if hasn't, thats not a tie, than return false.
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for(int i = 0 ; i < candidate_count ; i++){
        if(candidates[i].votes == min){                  //if some(s) candidate(s) has the min of votes, set his stats eliminated to true
            candidates[i].eliminated = true;
        }
    }
    return;
}
