#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

//declare to use in sort_pairs
typedef struct{
        int winner;
        int loser;
        int strength;
}strength;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

void bubbleSort(strength arr[], int n);
bool createCycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0 ; i < candidate_count ; i++){
        if (strcmp(candidates[i], name) == 0){
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int before = ranks[i];  // gets the candidate at the current higher preference
            int after  = ranks[j];  // gets the candidate at the lower preference

            preferences[before][after]++; // record that "before" is preferred over "after" by incrementing their pair count
        }
    }
    return;
}


// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;

    for(int i = 0 ; i < candidate_count ; i++){
        for(int j = i + 1 ; j < candidate_count ; j++){     //just need to this elements to compare:  0 (1)(2)
                                                                                                //   (1) 0 (1)  and this for iterate only in non-diagonal elements,
            int winner = 0;                                                                     //   (0)(1) 0   also compare with otherside elements. resulting in the pairs
            int loser = 0;

            if(preferences[i][j] == preferences[j][i]){         //if has equals preferences number, has no winner or loser. So get the next j iterate
                continue;
            }else if(preferences[i][j] > preferences[j][i]){
                winner = i;
                loser = j;                                      //determines the candidate index of winner and loser in pair
            }else if(preferences[i][j] < preferences[j][i]){
                winner = j;
                loser = i;
            }

            pairs[pair_count].winner = winner;
            pairs[pair_count].loser = loser;
            pair_count++;

        }
    }
    //for(int i = 0 ; i < pair_count ; i++){
    //    printf("\n%i : \n winner: %i", i , pairs[i].winner);         //if you want to see the pairs(used to debug)
    //    printf("loser: %i\n", pairs[i].loser);
    //}
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    strength stg[pair_count];

    for(int i = 0 ; i < pair_count ; i++){

        int winnerIndex = pairs[i].winner;
        int loserIndex = pairs[i].loser;

        stg[i].winner = winnerIndex;
        stg[i].loser = loserIndex;

        stg[i].strength = preferences[winnerIndex][loserIndex] - preferences[loserIndex][winnerIndex];
    }

    bubbleSort(stg, pair_count);

    for(int i = 0 ; i < pair_count ; i++){

        pairs[i].winner = stg[i].winner;
        pairs[i].loser = stg[i].loser;
    }


    // if want to see the final results in pairs[]:
    //printf("\nArray pairs[] reordenado:\n");
    //for (int i = 0; i < pair_count; i++) {
    //   int w = pairs[i].winner;
    //    int l = pairs[i].loser;
    //    int s = preferences[w][l] - preferences[l][w];
    //    printf("  [%2d] winner=%2d  loser=%2d  strength=%3d\n",
    //        i,
    //        w,
    //        l,
    //        s);
    //}

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i = 0 ; i < pair_count ; i++){
        if(createCycle(pairs[i].winner, pairs[i].loser ) == false){
            locked[pairs[i].winner][pairs[i].loser] = true;       //if has not a cycle in actual graph "locked", set this node in a directed graph true
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    //to determine the winner, i'll search who is the candidate that hasn't no true in his locked column. meaning that he is a source
    for(int i = 0 ; i < candidate_count ; i++){
        for(int j = 0 ; j < candidate_count ; j++){
            if(locked[j][i] == true){
                break;
            }
            if(j == (candidate_count - 1) ){ //if is the last column and not break. thats a source and too the winner

                printf("\nThe winner of election is :\n   %s\n",candidates[i]);
            }
        }
    }
    return;
}


// ________________________________________________________Functions used in others functions____________________________________________________________


//used in sort pairs. Used bubble sort bcs is easier to implements and don't has enogth length to use a complex algorithm
void bubbleSort(strength arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].strength < arr[j + 1].strength) {         //compare the stregnth of victory in pair(biggest first)
                strength temp = arr[j];                         // Swap if they are in the wrong order
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


bool createCycle(int winner, int loser){
    if(winner == loser) return true;               //base case, in case that return into the original winner leaving from losers path
                                                   //(means that has a cycle, in case of reach the original winner)
    for(int i = 0 ; i < candidate_count ; i++){
        if(locked[loser][i] == true){              //get all the losers paths and calls createCycle again with his losers
            if(createCycle(winner,i) == true){     // until(or not) reach the original winner, who always be passed as first element.
                return true;                       // allowing to reach all the way in all paths in locked until reach (or not) the source winner to detect a cycle
            }
        }
    }

    return false;                                   // if travel all the paths don't reach the original winner, thats not a cycle!
}
