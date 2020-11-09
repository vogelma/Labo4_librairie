/*-----------------------------------------------------------------------------------
Filename      : librairie.cpp
Authors       : Maëlle Vogel and Valentin Chételat
Creation date : 05.11.2020
Description   : <à compléter>
Comments      : <à compléter>
Compiler      : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <limits>
#include <iomanip>

#include "librairie.h"

using namespace std;

void optionIsEven();
void optionSumDigits();
void optionIsPrime();
void optionNbreArmstrong();
void optionBuffer();
void optionTrigo();
unsigned int askUserForInput_uint(string question, unsigned int min, unsigned int max);
int askUserForInput_int(string question, int min, int max);
double askUserForInput_double(string question, double min, double max);

int main() {
    bool repeat = true;
    int W = 3;

    do {
        int userChoose;

        //show menu
        cout << "\nOptions" << endl
             << "1   is even" << endl
             << "2   sum digits" << endl
             << "3   prime number" << endl
             << "4   Armstrong's number" << endl
             << "5   random" << endl
             << "6   buffer" << endl
             << "7   trigo" << endl
             << "0   quit" << endl;

        cout << "\nYour choose [0 - 7]:";

        cin >> userChoose;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (userChoose) {
            case 0:
                repeat = !answerYes("Would you like to quit [y - n]?", 'y', 'n');
                break;
            case 1:
                optionIsEven();
                break;
            case 2:
                optionSumDigits();
                break;
            case 3:
                optionIsPrime();
                break;
            case 4:
                optionNbreArmstrong();
                break;
            case 5:

                break;
            case 6:
                optionBuffer();
                break;
            case 7:
                optionTrigo();
                break;

        }

    } while (repeat);


}

void optionIsEven() {
    unsigned int number;

    number = askUserForInput_uint("Enter a value ", 0, 1000);

    cout << number;
    if (isEven(number)) {
        cout << " is an even value" << endl;
    } else {
        cout << " is not an even value" << endl;
    }

}

void optionSumDigits() {
    unsigned int result;
    unsigned int number;
    number = askUserForInput_uint("Enter a value ", 0, 1000);
    result = sumDigits(number);
    cout << "The sum of all digits in " << number << " = " << result << endl;
}

void optionIsPrime() {
    unsigned int min;
    unsigned int max;
    min = askUserForInput_uint("- start: ", 0, 1000);
    max = askUserForInput_uint("- end  : ", min, 1000);

    for (int i = min; i <= max; ++i) {
        if (isPrime(i)) {
            cout << "the number " << i << " is prime" << endl;
        }
    }
}

void optionNbreArmstrong() {
    unsigned int min;
    unsigned int max;
    min = askUserForInput_uint("- start: ", 0, 1000);
    max = askUserForInput_uint("- end  : ", min, 1000);

    for (int i = min; i <= max; ++i) {
        if (nbreArmstrong(i)) {
            cout << "the number " << i << " is an Armstrong number" << endl;
        }
    }

}

void optionBuffer() {
    char smallestLowerLetter;
    char biggestUpperLetter;
    string sentence;

    cout << "Enter a sentence:";
    getline(cin, sentence);

    int nbChar = buffer(sentence, smallestLowerLetter, biggestUpperLetter);

    if (smallestLowerLetter != '\0') {
        cout << "The smallest lower letter: " << smallestLowerLetter << endl;
    }
    if (biggestUpperLetter != '\0') {
        cout << "The biggest upper letter: " << biggestUpperLetter << endl;
    }

    cout << "Number of characters: " << nbChar;

}

void optionTrigo() {
    double sinus;
    double cosinus;
    double tangent;

    double angle;

    angle = askUserForInput_double("Enter an angle in degree: ", 0 , 360);
    trigo(angle, sinus, cosinus, tangent);

    cout << setprecision(6)
    << "sin(" << angle << ") = " << sinus << endl
    << "cos(" << angle << ") = " << cosinus << endl
    << "tan(" << angle << ") = " << tangent << endl;
}

int askUserForInput_int(string question, int min, int max) {
    int userInput;

    /*
     *  GET USER INPUT
     */
    do {

        cout << question << "[" << min << "-" << max << "] :";
        cin >> userInput;

        if (cin.fail()) {
            cin.clear();
            cout << "wrong input" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (userInput < min || userInput > max);

    return userInput;
}

unsigned int askUserForInput_uint(string question, unsigned int min, unsigned int max) {
    unsigned int userInput;

    /*
     *  GET USER INPUT
     */
    do {

        cout << question << "[" << min << "-" << max << "] :";
        cin >> userInput;

        if (cin.fail()) {
            cin.clear();
            cout << "wrong input" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (userInput < min || userInput > max);

    return userInput;
}

double askUserForInput_double(string question, double min, double max) {
    double userInput;

    /*
     *  GET USER INPUT
     */
    do {

        cout << question << "[" << min << "-" << max << "] :";
        cin >> userInput;

        if (cin.fail()) {
            cin.clear();
            cout << "wrong input" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (userInput < min || userInput > max);

    return userInput;
}
