/*-----------------------------------------------------------------------------------
Filename      : librairie.h
Authors       : Maëlle Vogel and Valentin Chételat
Creation date : 05.11.2020
Description   : <à compléter>
Comments      : <à compléter>
Compiler      : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/

#ifndef LABO4_LIBRAIRIE_LIBRAIRIE_H
#define LABO4_LIBRAIRIE_LIBRAIRIE_H

bool isEven(int number);
int sumNumbers(int number);
bool isPrime(unsigned int number);
bool nbreArmstrong(unsigned int number);
int buffer(string bufferToIterate, char& smallestLowerLetter, char& biggestUpperLetter);
void trigo(double deg, double& sinus, double& cosinus, double& tangent);
bool answerYes(string question, const char YES, const char NO);
int random(int minValue, int maxValue);

#endif //LABO4_LIBRAIRIE_LIBRAIRIE_H
