/*-----------------------------------------------------------------------------------
Filename      : librairie.cpp
Authors       : Maëlle Vogel and Valentin Chételat
Creation date : 05.11.2020
Description   : <à compléter>
Comments      : <à compléter>
Compiler      : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "librairie.h"

using namespace std;

bool isEven(int number) {
    bool response = false;

    if (!(number % 2)) {
        response = true;
    }

    return response;
}

int sumNumbers(int number){
    int sum = 0;
    int split = 10;
    int nbrDigit = floor(log10(number) + 1);

    for(int i = 1; i <= nbrDigit; ++i){
        sum += number%split;
        number = number/10;
    }

    return sum;
}

bool isPrime(int number){
    bool result = true;
    int min = 2;
    int divider = min;
    double max = sqrt(number);

    //Check if number is divisible by another
    while(divider <= max){
        if(!(number%divider)){
            result = false;
            break;
        }
        ++divider;
    }
    return result;
}

int buffer(string bufferToIterate, char& smallestLowerLetter, char& biggestUpperLetter){
    int counter             = 0;

    smallestLowerLetter     = 'z'; //Any other lower letter will be smaller
    biggestUpperLetter      = 'A'; //Any other upper letter will be bigger

    for(unsigned int i = 0; i < bufferToIterate.size(); ++i){
        //If it's not a letter then we skip
        if(!isalpha(bufferToIterate[i])){
            break;
        }

        //In case of lower letter
        if(islower(bufferToIterate[i])){
            //Check if current letter is smaller than the previous "smallest letter"
            if(bufferToIterate[i] < smallestLowerLetter){
                smallestLowerLetter = bufferToIterate[i];
            }
        }

        //In case of upper letter
        if(isupper(bufferToIterate[i])){
            //Check if current letter is bigger than the previous "biggest letter"
            if(bufferToIterate[i] > biggestUpperLetter){
                biggestUpperLetter = bufferToIterate[i];
            }
        }

        ++counter;
    }

    return counter;
}

void trigo(double deg, double& sinus, double& cosinus, double& tangent){
    sinus      = sin(deg);
    cosinus    = cos(deg);
    tangent    = tan(deg);
}

bool answerYes(string question, const char YES, const char NO){
    char userInput;

    /*
     *  GET USER INPUT
     */
    do{
        cout << question;
        cin >> userInput;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while(!(tolower(userInput) == (char)tolower(YES)|| tolower(userInput) == (char)tolower(NO)));

    /*
     *  DETERMINE WHETHER TO RETURN TRUE OR FALSE
     */
     if((char)tolower(userInput) == (char)tolower(YES)){
        return true;
     }else{
        return false;
     }
}
