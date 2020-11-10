/*-----------------------------------------------------------------------------------
Filename      : librairie.cpp
Authors       : Maëlle Vogel and Valentin Chételat
Creation date : 05.11.2020
Description   : <à compléter>
Comments      : <à compléter>
Compiler      : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#include "librairie.h"

using namespace std;

/*-------------------------------------------------------------------------------
 * PROTOTYPES
 -------------------------------------------------------------------------------*/
bool isNegative(int value);

/*-------------------------------------------------------------------------------
 * LIBRARY FUNCTIONS
 -------------------------------------------------------------------------------*/
bool    isEven          (const int NUMBER) {
    //In case the value is negative we take the absolute value
    if(isNegative(NUMBER))
        return ((abs(NUMBER) % 2) == 0);
    else
        return (NUMBER % 2 == 0);
}

int     sumDigits       (int number){
    int            sum             = 0;
    int            split           = 10;
    const int      DIGITS_COUNT    = (int)floor(log10(number) + 1);

    //In case the value is negative we take the absolute value
    if(isNegative(number))
        number = abs(number);

    //Add each digit to the sum
    for(int i = 1; i <= DIGITS_COUNT; ++i){
        sum += number%split;
        number = number/10;
    }

    return sum;
}

bool    isPrime         (int number){
    //In case the value is negative we take the absolute value
    if(isNegative(number))
        number = abs(number);

    //0 and 1 aren't prime numbers
    if (number == 0 || number == 1) {
        return false;
    }
        //For every other number
    else {
        //Check if divisible by another
        for (unsigned int i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
    }

    return true;
}

bool    nbArmstrong     (int number){
    int    result          = 0;
    int    tmp             = (number < 0) ? abs(number) : number; //If <0 then take absolute value
    int    currentDigit;

    //For every digit in the number
    while (tmp != 0) {
        //Take the last digit of the number
        currentDigit = tmp % 10;

        //Add this number^3 to the result
        result += (int)pow(currentDigit, 3);

        //Remove last digit
        tmp = tmp / 10;
    }

    return (result == number);
}

int     buffer          (string& bufferToIterate, char& smallestLowerLetter, char& biggestUpperLetter){
    int counter = 0;

    smallestLowerLetter     = '\0';
    biggestUpperLetter      = '\0';

    for(int i = 0; i < bufferToIterate.size(); ++i){
        ++counter;

        //If it's not a letter then we skip
        if(!isalpha(bufferToIterate[i])){
            continue;
        }

        //In case of lower letter
        if(islower(bufferToIterate[i])){
            //If it's the first lower letter
            if(smallestLowerLetter == '\0'){
                smallestLowerLetter = bufferToIterate[i];
            }

            //Check if current letter is smaller than the previous "smallest letter"
            if(bufferToIterate[i] < smallestLowerLetter){
                smallestLowerLetter = bufferToIterate[i];
            }
        }

        //In case of upper letter
        if(isupper(bufferToIterate[i])){
            //If it's the first upper letter
            if(biggestUpperLetter == '\0'){
                biggestUpperLetter = bufferToIterate[i];
            }

            //Check if current letter is bigger than the previous "biggest letter"
            if(bufferToIterate[i] > biggestUpperLetter){
                biggestUpperLetter = bufferToIterate[i];
            }
        }
    }

    return counter;
}

void    trigo           (const double ANGLE, double& sine, double& cosine, double& tangent){
    sine      = sin(ANGLE * (M_PI / 180));
    cosine    = cos(ANGLE * (M_PI / 180));
    tangent   = tan(ANGLE * (M_PI / 180));
}

bool    answerYes       (const string QUESTION, const char YES, const char NO){
    char userInput;

    /*
     *  GET USER INPUT
     */
    do{
        cout << QUESTION << "[" << YES << "/" << NO << "] :";
        cin >> userInput;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while(!(tolower(userInput) == (char)tolower(YES)|| tolower(userInput) == (char)tolower(NO)));

    /*
     *  DETERMINE WHETHER TO RETURN TRUE OR FALSE
     */
    //Put both to lower and check the values
    return (char)tolower(userInput) == (char)tolower(YES);
}

int     random          (const int MINIMUM, const int MAXIMUM){
    static bool hasToInit = true;

    if (hasToInit){
        srand((unsigned)time(nullptr));
        hasToInit = false;
    }
    return std::rand() % MAXIMUM + MINIMUM;
}

/*-------------------------------------------------------------------------------
 * INTERNAL FUNCTIONS
 -------------------------------------------------------------------------------*/
bool isNegative(int value){
    return (value < 0);
}
