#include <stdio.h>
#include <math.h>

int validCreditCard(int totalDigits,int digit[]);
void printCardFlag(int digit[],int totalDigits);

int main(){

    long ccNumber = 0;

    printf("Type the number of credit card: ");
    scanf("%ld",&ccNumber);


    long aux = ccNumber;
    int totalDigits = 0;

    while(aux != 0){
        aux = aux / 10;                         //count total of digits
        totalDigits += 1;
    }

    int digit[20];
    long divisor = 1;
    for(int i = 0 ; i<totalDigits ; i++){
        digit[i] = (ccNumber / divisor) % 10;  //create a vector with each card number in each possition
        divisor *= 10;
    }

    printCardFlag(digit,totalDigits);

    if(validCreditCard(totalDigits,digit) == 1){
        printf("Valid credit card");
    }else{
        printf("inValid credit card");
    }

    printf("\n");

    return 0;
}

int validCreditCard(int totalDigits,int digit[]){
    int sum = 0;
    for(int i = 1 ; i<totalDigits ; i = i+2){
        int temp = (digit[i]*2);
        if(temp > 9){
            sum += (temp/10);
            sum += (temp%10);
        }else{
            sum += temp;
        }
        sum += digit[i-1];
    }

    int lastDigit = sum%10;

    if(lastDigit == 0)return 1;
    return 0;
}

void printCardFlag(int digit[],int totalDigits){

    int ccFlag=0;
    ccFlag +=(digit[totalDigits-1] * 10);
    ccFlag += digit[totalDigits-2];

    if(ccFlag == 55 || ccFlag == 54 || ccFlag == 53 || ccFlag == 52 ||ccFlag == 51){
        printf("Mastercard \n");
    }else if(ccFlag == 34 || ccFlag == 37){
        printf("American Express\n");
    }else if(ccFlag/10 == 4){
        printf("Visa\n");
    }else{
        printf("Invalid card flag\n");
    }
}
