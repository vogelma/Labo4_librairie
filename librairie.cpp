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

int sumNumber(int number){
    int sum;
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

void trigo(double deg, double* sinus, double* cosinus, double* tangent){
    *sinus      = sin(deg);
    *cosinus    = cos(deg);
    *tangent    = tan(deg);
}
