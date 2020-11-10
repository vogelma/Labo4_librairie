#ifndef LABO_04_LIBRAIRIE_LIBRAIRIE_H
#define LABO_04_LIBRAIRIE_LIBRAIRIE_H

#include <string>

/*
 * Name         : isEven
 * Description  : Check whether a number is even or odd
 * Argument(s)  : const int NUMBER : The number to test
 * Return       : bool
 *                true if the number is even
 *                false if it's odd
 */
bool isEven(const int NUMBER);

/*
 * Name         : sumDigits
 * Description  : Sum all the digits of a given number and return the result
 * Argument(s)  : int number : The number for which to add all the digits
 * Return       : int : The result of the sum
 */
int sumDigits(int number);

/*
 * Name         : isPrime
 * Description  : Check whether a number is prime or not
 * Argument(s)  : int number : The number to check
 * Return       : bool
 *                true is the number is prime
 *                false if it's not
 */
bool isPrime(int number);

/*
 * Name         : nbArmstrong
 * Description  : Check whether a number is an Armstrong number or not
 * Argument(s)  : int number : The number to check
 * Return       : bool
 *                true if the number is an Armstrong number
 *                false if it's not
 */
bool nbArmstrong(int number);

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
int buffer(std::string& bufferToIterate, char& smallestLowerLetter, char& biggestUpperLetter);

/*
 * Name         : trigo
 * Description  : For a given angle, calculate the sine, cosine and tangent
 * Argument(s)  : const double ANGLE    : Angle in degree
 *                double& sine          : Reference to the double variable where sine will be stored
 *                double& cosine        : Reference to the double variable where cosine will be stored
 *                double& tangent       : Reference to the double variable where tangent will be stored
 * Return       : void
 */
void trigo(const double ANGLE, double& sine, double& cosine, double& tangent);

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
bool answerYes(const std::string QUESTION, const char YES, const char NO);

/*
 * Name         : random
 * Description  : Return a random value in a range
 * Argument(s)  : const int MINIMUM    : minimum value included in the range
 *                const int MAXIMUM    : maximum value included in the range
 * Return       : int
 *                Random value in the range [MINIMUM; MAXIMUM]
 */
int random(const int MINIMUM, const int MAXIMUM);

#endif //LABO_04_LIBRAIRIE_LIBRAIRIE_H
