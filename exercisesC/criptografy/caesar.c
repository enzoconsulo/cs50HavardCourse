#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertString(char *str,int key);
char formula(char c, int key);

int main(int argc, char *argv[]){   //change from "string" of cs50.h to "char *" to be more indepent of this library
    char s[50];
    char *keyPrompt;                //pointer to "string"

    if(argc == 2){
        keyPrompt = argv[1];
    }else{
        printf("Usage: ./caesar key\n");
        return 1;                           //handling possible exception
    }

    int key = 0, i=0;
    while (keyPrompt[i] != '\0'){
        if(!isdigit(keyPrompt[i])){
            printf("Usage: ./caesar key\n");
            return 1;                        //handling possible exception
        }
        key = key * 10 + (keyPrompt[i] - '0');         //converting char to integer
        i++;
    }

    printf("PlainText: ");
    fgets(s,sizeof(s),stdin);

    convertString(s,key);

    printf("CipherText: %s",s);

}

void convertString(char *str,int key){
    for(int i = 0, n = strlen(str); i < n ; i++){
        str[i] = formula(str[i],key);               //loop to read all the string, converting each of those characters
    }
}

char formula(char c, int key){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z') ){
        int lowerCase = 0;

        if(c >= 'a' && c <= 'z'){
            c = c - 'a';
            lowerCase = 1;
        }else{                              //get index from 0 to 25 in alphabet
            c = c - 'A';
            lowerCase = 0;
        }

        char newletter = (c + key) % 26;    //modulo of (c + key) , to get the values in case of past 'z'/25

        if(lowerCase == 1){
            newletter += 'a';
        }else{                              //convert back in ascii
            newletter += 'A';
        }

        return newletter;
    }
    return c;
}
