/*-----------------------------------------------------------------------------------
Filename      : main.cpp
Authors       : Maëlle Vogel and Valentin Chételat
Creation date : 05.11.2020
Description   : The programme will display a menu with multiple options. Each option has
                its own action. This action is described in the librairie.h file.
                The user is asked to choose between:
                    1 show if a number is even
                    2 show the sum of the digits of a number
                    3 show the prime numbers in a range
                    4 show the Armstrong numbers in a range
                    5 look for the smallest lower and biggest upper letters in the string
                    6 show the cosine, sine and tangent of an angle
                    7 generate random numbers in a range
                    8 quit the program
Comments      :
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
    int number;

    /*
     * USER INPUT
     */
    number = askUserForInput_int("Enter a value ", 0, 1000);

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
    int             number;
    int             result;

    /*
     * USER INPUT
     */
    number = askUserForInput_int("Enter a value ", 0, 1000);

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
    int min;
    int max;

    /*
     * USER INPUT
     */
    min = askUserForInput_int("- Start: ", 0, 1000);
    max = askUserForInput_int("- End  : ", min, 1000);

    /*
     * PRINT PRIME NUMBERS
     */
    for (int i = min; i <= max; ++i) {
        if (isPrime(i)) {
            cout << "The number " << i << " is prime" << endl;
        }
    }
}

void optionNbArmstrong() {
    int min;
    int max;

    /*
     * USER INPUT
     */
    min = askUserForInput_int("- Start: ", 0, 1000);
    max = askUserForInput_int("- End  : ", min, 1000);

    /*
     * PRINT ARMSTRONG NUMBERS
     */
    for (int i = min; i <= max; ++i) {
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
    int min;
    int max;
    int nbreTime;
    int nbreRnd;

    /*
     * USER INPUT
     */
    min = askUserForInput_int("- Start: ", -100, 100);
    max = askUserForInput_int("- End  : ", min, 100);
    nbreTime = askUserForInput_int("- nbre : ", 0, 100);

    cout << "this are the random value [" << min << " - " << max << "]:" << endl;

    for(int i = 1; i <= nbreTime; ++i){
        nbreRnd = random(min, max);

        cout << nbreRnd;

        if(i != nbreTime){
            cout << ", ";
        }

    }
    cout << endl;
}

/*-------------------------------------------------------------------------------
 * INPUT FUNCTIONS
 -------------------------------------------------------------------------------*/
int askUserForInput_int(string question, int min, int max) {
    bool    repeat;
    int     userInput;

    /*
     *  GET USER INPUT
     */
    do {
        repeat = false;

        cout << question << "[" << min << " - " << max << "] :";
        cin >> userInput;


        if (cin.fail() || userInput < min || userInput > max) {
            cout << "Input error" << endl;
            repeat = true;

            if(cin.fail())
                cin.clear();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (repeat);

    return userInput;
}

double askUserForInput_double(string question, double min, double max) {
    bool    repeat;
    double  userInput;

    /*
     *  GET USER INPUT
     */
    do {
        repeat = false;

        cout << question << "[" << min << " - " << max << "] :";
        cin >> userInput;

        if (cin.fail() || userInput < min || userInput > max) {
            cout << "Input error" << endl;
            repeat = true;

            if(cin.fail())
                cin.clear();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (repeat);

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
