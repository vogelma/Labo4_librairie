#ifndef LABO_04_LIBRAIRIE_LIBRAIRIE_H
#define LABO_04_LIBRAIRIE_LIBRAIRIE_H

#include <string>

bool    isEven          (const unsigned int NUMBER);
int     sumDigits       (unsigned int number);
bool    isPrime         (const unsigned int NUMBER);
bool    nbArmstrong     (const unsigned int NUMBER);
int     buffer          (std::string& bufferToIterate,
                         char& smallestLowerLetter,
                         char& biggestUpperLetter);
void    trigo           (const double ANGLE,
                         double& sine,
                         double& cosine,
                         double& tangent);
bool    answerYes       (const std::string QUESTION,
                         const char YES,
                         const char NO);
int     random          (const int MINIMUM,
                         const int MAXIMUM);

#endif //LABO_04_LIBRAIRIE_LIBRAIRIE_H
