#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int ammountOfLetters(string text);
int ammountOfSentences(string text);
int ammountOfWords(string text);
int calculateIndex(int letters, int sentences, int words);

int main(void){
    char s[1000]; //limite de 1000 caracteres
    printf("Text: ");
    fgets(s,sizeof(s),stdin);

    /*printf("\n%i",ammountOfLetters(s));
    printf("\n%i",ammountOfSentences(s));  just to see values when constructed the program
    printf("\n%i",ammountOfWords(s));*/

    int index = calculateIndex(ammountOfLetters(s),ammountOfSentences(s),ammountOfWords(s));
    if(index == 0){
        printf("Before Grade 1\n");
    }else if(index >=16){
        printf("Grade 16+\n");
    }else{
        printf("Grade: %i\n",index);
    }

}

int ammountOfLetters(string text){
    int counter = 0;
    for(int i = 0 ; text[i] != '\0' ; i++){
        if(isalpha(text[i])){
            counter++;
        }
    }
    return counter;
}

int ammountOfSentences(string text){
    int counter = 0;
    for(int i = 0 ; text[i] != '\0' ; i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            counter++;
        }
    }
    return counter;
}

int ammountOfWords(string text){
    int counter = 1; //consider the last word would not have space, so starting in 1 to count it
    for(int i = 0 ; text[i] != '\0' ; i++){
        if(text[i] == ' '){
            counter++;
        }
    }
    return counter;
}

int calculateIndex(int letters, int sentences, int words){

    float averageLetters = letters/(float)words;        //need to convert atleast 1 int to get the result in float
    averageLetters *= 100;                              //get average letters per words in percent

    float averageSentences = sentences/(float)words;    //need to convert atleast 1 int to get the result in float
    averageSentences *= 100;                            //get average sentences per words in percent

    float index = (0.0588 * averageLetters) - (0.296 * averageSentences) - 15.8;

    if(index > 0){
        index += 0.5;  //using the criterion | (x).5 = (x+1) and (x).4 = (x) | to round
    }else{
        return 0;
    }
    return (int)index;   //convert to integer, discarding post point values(valid bcs did the step above)
}
