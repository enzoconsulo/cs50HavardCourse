#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertString(char *str,char key[]);
char formula(char c, char key[]);

int main(int argc, char *argv[]){   //change from "string" of cs50.h to "char *" to be more indepent of this library
    char s[27];
    char *keyPrompt;                //pointer to "string" start

    if(argc == 2){
        keyPrompt = argv[1];
    }else{
        printf("Usage: ./substitution key\n");
        return 1;                           //handling possible exception
    }

    char key[26];
    int i;
    for(i=0; keyPrompt[i] != '\0'; i++){
        if(!isalpha(keyPrompt[i])){
            printf("Key must contain only alphabetic characters\n");
            return 1;                        //handling possible exception
        }

        for(int j = 0; j < 26 ; j++){
            if(key[j] == keyPrompt[i]){
                 printf("Key must not contain repeated characters\n");   //i know for into a while is ugly to implements, but i need to traverse the key array to found repeatable chars
                 return 1;                        //handling possible exception
            }
        }

        key[i] = keyPrompt[i];      //here i can do only the verification and after use directly the keyPrompt as key,
                                    // but atributted to "key" for better visualization

    }

    if(i!= 26){
        printf("Key must contain exacly 26 characters\n");
        return 1;                                 //handling possible exception
    }

    printf("PlainText: ");
    fgets(s,sizeof(s),stdin);

    convertString(s,key);

    printf("CipherText: %s",s);

}

void convertString(char *str,char key[]){
    for(int i = 0, n = strlen(str); i < n ; i++){
        str[i] = formula(str[i],key);               //loop to read all the string, converting each of those characters
    }
}

char formula(char c, char key[]){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z') ){
        int lowerCase = 0;

        if(c >= 'a' && c <= 'z'){
            c = c - 'a';
            lowerCase = 1;
        }else{                              //get index from 0 to 25 in alphabet
            c = c - 'A';
            lowerCase = 0;
        }

        char newletter = key[(int) c];    //modulo of (c + key) , to get the values in case of past 'z'/25

        if(lowerCase == 1){
            newletter = tolower(newletter);
        }else{                              //convert back to original lower or upper
            newletter = toupper(newletter);
        }

        return newletter;


    }
    return c;
}
