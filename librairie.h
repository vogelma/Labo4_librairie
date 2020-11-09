#ifndef LABO_04_LIBRAIRIE_LIBRAIRIE_H
#define LABO_04_LIBRAIRIE_LIBRAIRIE_H

#include <string>

bool    isEven              (unsigned int number);
int     sumDigits           (unsigned int number);
bool    isPrime             (unsigned int number);
bool    nbreArmstrong       (unsigned int number);
int     buffer              (std::string& bufferToIterate,
                             char& smallestLowerLetter,
                             char& biggestUpperLetter);
void    trigo               (const double deg,
                             double& sinus,
                             double& cosinus,
                             double& tangent);
bool    answerYes           (const std::string question,
                             const char YES,
                             const char NO);
int     random              (const int minValue,
                             const int maxValue);

#endif //LABO_04_LIBRAIRIE_LIBRAIRIE_H
