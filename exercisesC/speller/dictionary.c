// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char wordLowerCase[LENGTH + 1];
    strcpy(wordLowerCase, word);                           //need to cpy the string word bcs is a const and cannot modify directly

    for(int i = 0; wordLowerCase[i] != '\0' ; i++){
        wordLowerCase[i] = tolower(wordLowerCase[i]);      //get lower case to use in hash(all the words in dictionary is in lowercase, so, doing that none hashcode will be diffent bcs of a different case, independently of hash function logic)
    }


    int index = hash(wordLowerCase);        //hash the word to get the exacly index that was deposit the dictionary word.
                                            //(if does't exist this word in dictionary. probably will get a random index)
                                            //            (but whatever, this will not found the word anyway)

    node *n = table[index];                 //creates a node to iterate through a bucket in table. And set his pointer to first element on this bucket

    while(n != NULL){
        if (strcmp(wordLowerCase, n->word) == 0){
            return true;                            //if found, return true
        }

        n = n->next;                                //if isn't this element, get the next one
    }

    return false;                                   //if none element is equal in this bucket, return false
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (word[0]) - 'a'; //initial model just to see( ordering by alphabet index 0-26)
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input = fopen(dictionary , "r");
    if(input == NULL){                            //reads the dictionary file. passed in parameter
        return false;                             //if had an error, return false to indicate a failed "load"
    }

    char word[LENGTH + 1];                        //declares a buffer to store readed words

    int index;                                    //declare here to use in all the elements on loop

    while(fscanf(input, "%s", word) != EOF){      //read the file until find "EOF" : end of file. word by word(LENGTH+1)

        node *n = malloc(sizeof(node));           //allocates a new node in memory
        if(n == NULL){                            //if had an error, return false to indicate a failed "load"

            fclose(input);                        //remenbering to close if "break" the loop and don't reach the fclose in the end
            return false;
        }

        strcpy(n->word, word);                    //copy the string in word to word field in node "n"

        index = hash(word);                       //apply the hashcode function

        if(table[index] == NULL){
            n->next = NULL;                       //if is the first element in this table[index] add it and set his "next" field to NULL
            table[index] = n;

        }else{                                    //if wasn't the first element in this table[index]

            n->next = table[index];               //set "next" field on node to actual element index on table
            table[index] = n;                     //set the table[index] pointer to "n" node

        }

    }

    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
int getDeep(node *n);                               //declares identifier to getDeep function that is in the bottom

unsigned int size(void)
{
    bool load = false;                              //using a bool variable to determine if is loaded

    for(int i = 0 ; i < N ; i++){
        if(table[i] != NULL){
            load = true;                            //if any element of hash table was not empty, set load to true(indicating that is loaded)
        }
    }

    if(load == false){
        return 0;                                   //if wasn't found any bucket in table, is empty. return 0
    }

    int totalSize = 0;

    for(int i = 0 ; i < N ; i++){
        totalSize += getDeep(table[i]);             //calculates the total size of dictionary(elements in each hash table index)
    }

    return totalSize;                               //return the size
}

// Unloads dictionary from memory, returning true if successful, else false
void freeBucket(node *n);
bool unload(void)
{
    // TODO
    for(int i = 0 ; i < N ; i++){
        freeBucket(table[i]);                       //thats no error to treat here, i dont know why they asked to return false
    }

    return true;
}

/*int getDeep(node *n){

    int sum = 0;

    if(n == NULL){
        return 0;                               //in theory is the same big O of the function under. But i'll maintain
    }else{                                                          the second function to see results
        int x = getDeep(n->next);
        sum +=(x+1);
        return sum;
    }
}
*/
int getDeep(node *n){

    int sum = 0;
    if (n == NULL){
        return 0;
    }
                                                    //basiclly this recursive function acts verifying the actual node is NULL (that indicats the end)
    node *tmp = n->next;                            // and if the next node for actual is NULL
                                                    // by the way, if wasn't found the NULL node. call another function to the 3rd node
    if(tmp == NULL){                                // considering that doesn't matter the values from nodes(words) to calculate the size, we can just search 2 by 2 elements until found NULL
        return 1;                                   // *observation: this trick to return 0 or 1 is bcs analysing 2 by 2 elements, we can found on the first element or second
    }else{                                          //                and to get a sucessfull sum, we need to treat this. (likely adding odd or even to the last sum value)
        int x = getDeep(tmp->next);
        sum +=(x+2);
        return sum;
    }
}

void freeBucket(node *n){
    node *tmp;

    while(n != NULL){
        tmp = n;
        n = n->next;
        free(tmp);
    }
}

