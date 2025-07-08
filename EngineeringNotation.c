//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function Prototypes
void engineeringNotationConverter(double userNumber);
char prefixSymbol(int exponentCounter);

int main(void){
    double userNumber = 0.00; //A number from the user
    int userContinueStatus; //1 to continue, 0 to end the program
    bool keepConverting = true; //Hold the boolean value if the program should keep convertin numbers

    while(keepConverting){
        printf("Enter a positive number to be converted to engineering notation: "); //The user enters their number
        scanf("%lf", &userNumber);
        puts("");

        printf("Your converted number is:\n");
        engineeringNotationConverter(userNumber); //Will call the function for conversion, and print the result
        puts(""); //Puts a new line for spacing purposes

        do{
            printf("Do you want to convert another number?\nEnter 1 to continue, or enter 0 to end the program: ");
            scanf("%d", &userContinueStatus); //Determines if the user wants to contine or end the program
            puts("");
        }while(userContinueStatus != 0 && userContinueStatus != 1);  //While the user has not entered a correct number, it will keep requesting a proper input

        if(userContinueStatus == 0){
            keepConverting = false; //Ends the program
        }
        else{
            keepConverting = true; //The conversion continues
        }        
    }
    printf("The program has ended\n"); //Program has ended
    return 0;
}

void engineeringNotationConverter(double userNumber){
    double engNotationNumber = userNumber; //Will hold the value of the converted number,
    int exponentCount = 0; //Will hold the value of the exponent of the converted number
    bool inUpperOutsideRange = false; //True represents that engNotationNumber is above 999, False represents it is between 0 and 1

    if(engNotationNumber < 0){
        printf("Negative numbers are not accepted!\n");
        return;
    }

    if (engNotationNumber == 0){ 
        printf("No conversion required: 0\n"); 
        return;
    }

    if((engNotationNumber >= 1 && engNotationNumber < 1000)){ //If the user's number is already in engineering notation, then exit the function
        printf("No conversion required: %lf\n", engNotationNumber);
        return; //Empty return to exit this function
    }

    if(engNotationNumber > 999){
        inUpperOutsideRange = true; //In the upper outside range, which starts at 1000, otherwise it is in the lower outside range, which is in between 0 and 1
    }

    if(inUpperOutsideRange){
        while(engNotationNumber > 999){ //Above the upper limit of 999
            engNotationNumber /= 10; //Divides it to bring it in the range of 1 - 999
            exponentCount++; //Increase exponent count
        }

        while(exponentCount % 3 != 0 ){ //While the exponent is not a multiple of 3
            engNotationNumber /= 10; //Continue to divide
            exponentCount++; //Increase exponent count
        }
    }

    else{
        while(engNotationNumber < 1){ //In the lower outside range
            engNotationNumber *= 10; //Multiplies it to bring it in the range of 1 - 999
            exponentCount--; //Decrease exponent count
        }
    
        while(exponentCount % 3 != 0 ){ //While the exponent is not a multiple of 3
            engNotationNumber *= 10; //Continue to multiply
            exponentCount--; //Decrease exponent count
        }
    }

    if(prefixSymbol(exponentCount) == ' '){ //Number entered is outside of prefixSymbol range of +24 to -24
        printf("%.3lf times 10^%d \n", engNotationNumber, exponentCount); //Prints the number in Engineering Notation in the format of a number times 10 to the power of the exponent
    }
    else{
        printf("%.3lf times 10^%d or %.3lf %c\n", engNotationNumber, exponentCount, engNotationNumber, prefixSymbol(exponentCount)); //Same format as the if, as well as the number with the corresponding prefix
    }
}

char prefixSymbol(int exponentCount){
    char prefixChar;
    switch(exponentCount){
        case 24:
            prefixChar = 'Y'; //Yotta
            break;
        case 21:
            prefixChar = 'Z'; //Zetta
            break;
        case 18:
            prefixChar = 'E'; //Exa
            break;
        case 15:
            prefixChar = 'P'; //Peta
            break;
        case 12:
            prefixChar = 'T'; //Tera
            break;
        case 9:
            prefixChar = 'G'; //Giga
            break;
        case 6:
            prefixChar ='M'; //Mega
            break;
        case 3:
            prefixChar = 'k'; //Kilo
            break;
        case -3:
            prefixChar = 'm'; //Milli
            break;
        case -6:
            prefixChar = 'u'; //Micro (µ)
            break;
        case -9:
            prefixChar = 'n'; //Nano
            break;
        case -12:
            prefixChar = 'p'; //Pico
            break;
        case -15:
            prefixChar = 'f'; //Femto
            break;
        case -18:
            prefixChar = 'a'; //Atto
            break;
        case -21:
            prefixChar = 'z'; //Zepto
            break;
        case -24:
            prefixChar = 'y'; //Yocto
            break;
        default:
            prefixChar = ' '; //Out of range
    }
    return prefixChar;
}
