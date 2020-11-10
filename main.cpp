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

/*-------------------------------------------------------------------------------
 * PROTOTYPES
 -------------------------------------------------------------------------------*/
void            optionIsEven();
void            optionSumDigits();
void            optionIsPrime();
void            optionNbArmstrong();
void            optionBuffer();
void            optionTrigo();
void            optionRandom();
unsigned int    askUserForInput_uint(string question, unsigned int min, unsigned int max);
int             askUserForInput_int(string question, int min, int max);
double          askUserForInput_double(string question, double min, double max);
void            displayMenu();

int main() {
    bool    repeat          = true;
    int     menuChoice;

    do {
        /*
         * DISPLAY MENU
         */
        displayMenu();

        /*
         * USER INPUT
         */
        menuChoice = askUserForInput_int("\nYour choice ", 0, 7);

        /*
         * FEATURES
         */
        switch (menuChoice) {
            case 0:
                repeat = !answerYes("Would you like to quit ", 'y', 'n');
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
                optionNbArmstrong();
                break;
            case 5:
                optionRandom();
                break;
            case 6:
                optionBuffer();
                break;
            case 7:
                optionTrigo();
                break;
            default:
                break;
        }

    } while (repeat);

    return EXIT_SUCCESS;
}

/*-------------------------------------------------------------------------------
 * FEATURES
 -------------------------------------------------------------------------------*/
void optionIsEven() {
    unsigned int number;

    /*
     * USER INPUT
     */
    number = askUserForInput_uint("Enter a value ", 0, 1000);

    /*
     * PRINT WHETHER IT'S PRIME OR NOT
     */
    cout << number;
    if (isEven(number)) {
        cout << " is even" << endl;
    } else {
        cout << " is not even" << endl;
    }
}

void optionSumDigits() {
    unsigned int    number;
    int             result;

    /*
     * USER INPUT
     */
    number = askUserForInput_uint("Enter a value ", 0, 1000);

    /*
     * DO THE OPERATION
     */
    result = sumDigits(number);

    /*
     * PRINT THE RESULT
     */
    cout << "The sum of all digits in " << number << " = " << result << endl;
}

void optionIsPrime() {
    unsigned int min;
    unsigned int max;

    /*
     * USER INPUT
     */
    min = askUserForInput_uint("- Start: ", 0, 1000);
    max = askUserForInput_uint("- End  : ", min, 1000);

    /*
     * PRINT PRIME NUMBERS
     */
    for (unsigned int i = min; i <= max; ++i) {
        if (isPrime(i)) {
            cout << "The number " << i << " is prime" << endl;
        }
    }
}

void optionNbArmstrong() {
    unsigned int min;
    unsigned int max;

    /*
     * USER INPUT
     */
    min = askUserForInput_uint("- Start: ", 0, 1000);
    max = askUserForInput_uint("- End  : ", min, 1000);

    /*
     * PRINT ARMSTRONG NUMBERS
     */
    for (unsigned int i = min; i <= max; ++i) {
        if (nbArmstrong(i)) {
            cout << "The number " << i << " is an Armstrong number" << endl;
        }
    }

}

void optionBuffer() {
    char    smallestLowerLetter;
    char    biggestUpperLetter;
    string  sentence;

    /*
     * GET SENTENCE FROM USER
     */
    cout << "Enter a sentence:";
    getline(cin, sentence);

    /*
     * DO THE OPERATION
     */
    int nbChar = buffer(sentence, smallestLowerLetter, biggestUpperLetter);

    /*
     * PRINT THE RESULT
     */
    if (smallestLowerLetter != '\0') {
        cout << "The smallest lower letter: " << smallestLowerLetter << endl;
    }
    if (biggestUpperLetter != '\0') {
        cout << "The biggest upper letter: " << biggestUpperLetter << endl;
    }

    cout << "Number of characters: " << nbChar << endl;
}

void optionTrigo() {
    double angle;
    double sine;
    double cosine;
    double tangent;

    /*
     * USER INPUT
     */
    angle = askUserForInput_double("Enter an angle in degree ", 0 , 360);

    /*
     * DO THE OPERATION
     */
    trigo(angle, sine, cosine, tangent);

    /*
     * PRINT THE RESULT
     */
    cout << setprecision(6)
         << "sin(" << angle << ") = " << sine << endl
         << "cos(" << angle << ") = " << cosine << endl
         << "tan(" << angle << ") = " << tangent << endl;
}

void optionRandom(){
    for(int i = 0; i < 10; ++i){
        cout << random(0, 50) << endl;
    }
}

/*-------------------------------------------------------------------------------
 * INPUT FUNCTIONS
 -------------------------------------------------------------------------------*/
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
            cout << "Input error" << endl;
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
            cout << "Input error" << endl;
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
            cout << "Input error" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (userInput < min || userInput > max);

    return userInput;
}

/*-------------------------------------------------------------------------------
 * DISPLAY FUNCTIONS
 -------------------------------------------------------------------------------*/
void displayMenu(){
    /*
     * DISPLAY THE MENU
     */
    cout << "\nOptions"                 << endl
         << "1   Is even"               << endl
         << "2   Sum digits"            << endl
         << "3   Prime number"          << endl
         << "4   Armstrong's number"    << endl
         << "5   Random"                << endl
         << "6   Buffer"                << endl
         << "7   Trigo"                 << endl
         << "0   Quit"                  << endl;
}
