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

/*
 * Name         : isEven
 * Description  : Check whether a number is even or odd
 * Argument(s)  : const unsigned int NUMBER : The number to test
 * Return       : bool
 *                true if the number is even
 *                false if it's odd
 */
bool isEven(const unsigned int NUMBER) {
    return (NUMBER % 2 == 0);
}

/*
 * Name         : sumDigits
 * Description  : Sum all the digits of a given number and return the result
 * Argument(s)  : unsigned int number : The number for which to add all the digits
 * Return       : int : The result of the sum
 */
int sumDigits(unsigned int number){
    int            sum             = 0;
    int            split           = 10;
    const int      DIGITS_COUNT    = (int)floor(log10(number) + 1);

    //Add each digit to the sum
    for(int i = 1; i <= DIGITS_COUNT; ++i){
        sum += number%split;
        number = number/10;
    }

    return sum;
}

/*
 * Name         : isPrime
 * Description  : Check whether a number is prime or not
 * Argument(s)  : const unsigned int NUMBER : The number to check
 * Return       : bool
 *                true is the number is prime
 *                false if it's not
 */
bool isPrime(const unsigned int NUMBER){
    //0 and 1 aren't prime numbers
    if (NUMBER == 0 || NUMBER == 1) {
        return false;
    }
        //For every other number
    else {
        //Check if divisible by another
        for (unsigned int i = 2; i <= NUMBER / 2; ++i) {
            if (NUMBER % i == 0) {
                return false;
            }
        }
    }

    return true;
}

/*
 * Name         : nbArmstrong
 * Description  : Check whether a number is an Armstrong number or not
 * Argument(s)  : const unsigned int NUMBER : The number to check
 * Return       : bool
 *                true if the number is an Armstrong number
 *                false if it's not
 */
bool nbArmstrong(const unsigned int NUMBER){
    unsigned int    result          = 0;
    unsigned int    tmp             = NUMBER;
    unsigned int    currentDigit;

    //For every digit in the number
    while (tmp != 0) {
        //Take the last digit of the number
        currentDigit = tmp % 10;

        //Add this number^3 to the result
        result += (unsigned int)pow(currentDigit, 3);

        //Remove last digit
        tmp = tmp / 10;
    }

    return (result == NUMBER);
}

/*
 * Name         : buffer
 * Description  : Return the smallest lower letter and the biggest upper letter
 *                found in the buffer.
 * Argument(s)  : string& bufferToIterate    : Ref. to The buffer in which we should find the letters
 *                char& smallestLowerLetter  : Reference to the char variable where the
 *                                             smallest lower letter will be stored
 *                char& biggestUpperLetter   : Reference to the char variable where the
 *                                             biggest upper letter will be stored
 * Return       : int
 *                The number of characters checked
 */
int buffer(string& bufferToIterate, char& smallestLowerLetter, char& biggestUpperLetter){
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

/*
 * Name         : trigo
 * Description  : For a given angle, calculate the sine, cosine and tangent
 * Argument(s)  : const double ANGLE    : Angle in degree
 *                double& sine          : Reference to the double variable where sine will be stored
 *                double& cosine        : Reference to the double variable where cosine will be stored
 *                double& tangent       : Reference to the double variable where tangent will be stored
 * Return       : void
 */
void trigo(const double ANGLE, double& sine, double& cosine, double& tangent){
    sine      = sin(ANGLE * (M_PI / 180));
    cosine    = cos(ANGLE * (M_PI / 180));
    tangent   = tan(ANGLE * (M_PI / 180));
}

/*
 * Name         : answerYes
 * Description  : Print a question and verify if the user answered by yes or no
 *                The characters representing the yes/no are can be changed
 * Argument(s)  : const string& QUESTION    : The question to ask
 *                const char YES            : The character representing a "yes"
 *                const char NO             : The character representing a "no"
 * Return       : bool
 *                true if the user answered by yes
 *                false if the user answered by no
 */
bool answerYes(const string QUESTION, const char YES, const char NO){
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

/*
 * Name         : random
 * Description  : Return a random value in a range
 * Argument(s)  : const int MINIMUM    : minimum value included in the range
 *                const int MAXIMUM    : maximum value included in the range
 * Return       : int
 *                Random value in the range [MINIMUM; MAXIMUM]
 */
int random(const int MINIMUM, const int MAXIMUM){
    static bool hasToInit = true;

    if (hasToInit){
        srand((unsigned)time(nullptr));
        hasToInit = false;
    }
    return std::rand() % MAXIMUM + MINIMUM;
}
