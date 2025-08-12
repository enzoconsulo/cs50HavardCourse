// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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
    return false;
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

    int indexLetter;                              //declare here to use in all the elements on loop

    while(fscanf(input, "%s", word) != EOF){      //read the file until find "EOF" : end of file. word by word(LENGTH+1)

        node *n = malloc(sizeof(node));           //allocates a new node in memory
        if(n == NULL){                            //if had an error, return false to indicate a failed "load"

            fclose(input);                        //remenbering to close if "break" the loop and don't reach the fclose in the end
            return false;
        }

        strcpy(n->word, word);                    //copy the string in word to word field in node "n"

        indexLetter = hash(word);                 //apply the hashcode function

        if(table[indexLetter] == NULL){
            n->next = NULL;                       //if is the first element in this table[index] add it and set his "next" field to NULL
            table[indexLetter] = n;

        }else{                                    //if wasn't the first element in this table[index]

            n->next = table[indexLetter];         //set "next" field on node to actual element index on table
            table[indexLetter] = n;               //set the table[index] pointer to "n" node

        }

    }

    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
