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

using namespace std;

bool isEven(int number);
int sumNumbers(int number);
bool isPrime(unsigned int number);
bool nbreArmstrong(unsigned int number);

int main(){

    return EXIT_SUCCESS;
}

bool isEven(int number) {
    return (number % 2 == 0);
}

int sumNumbers(int number){
    unsigned int            sum             = 0;
    unsigned int            split           = 10;
    const unsigned int      DIGITS_COUNT    = floor(log10(number) + 1);

    //Add each digit to the sum
    for(int i = 1; i <= DIGITS_COUNT; ++i){
        sum += number%split;
        number = number/10;
    }

    return sum;
}

bool isPrime(unsigned int number){
    bool result = true;

    //0 and 1 aren't prime numbers
    if (number == 0 || number == 1) {
        return false;
    }
    //For every other number
    else {
        //Check if divisible by another
        for (int i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                result = false;
                break;
            }
        }
    }

    return result;
}

bool nbreArmstrong(unsigned int number){
    unsigned int    result          = 0;
    int             tmp             = number;
    int             currentDigit;

    //For every digit in the number
    while (tmp != 0) {
        //Take the last digit of the number
        currentDigit = tmp % 10;

        //Add this number^3 to the result
        result += pow(currentDigit, 3);

        //Remove last digit
        tmp = tmp / 10;
    }

    return (result == number);

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
    //Put both to lower and check the values
    return (char)tolower(userInput) == (char)tolower(YES);
}

int random(int minValue, int maxValue){
    srand (time(0));

    return rand() % maxValue + minValue;;
}
