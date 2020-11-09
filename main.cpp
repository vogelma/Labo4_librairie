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
#include <limits>
#include <iomanip>

#include "librairie.h"

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n');
using namespace std;

int main() {


    cout << "Presser ENTER pour quitter";
    EMPTY_BUFFER
    return EXIT_SUCCESS;
}

int askUserForInput_int(string question, int min, int max){
    int userInput;

    /*
     *  GET USER INPUT
     */
    do{
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << question << "[" << min << "-" << max << "] :";
        cin >> userInput;

    }while(userInput < min || userInput > max || cin.fail());

    return userInput;
}

unsigned int askUserForInput_uint(string question, unsigned int min, unsigned int max){
    unsigned int userInput;

    /*
     *  GET USER INPUT
     */
    do{
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << question << "[" << min << "-" << max << "] :";
        cin >> userInput;

    }while(userInput < min || userInput > max || cin.fail());

    return userInput;
}

double askUserForInput_double(string question, double min, double max){
    double userInput;

    /*
     *  GET USER INPUT
     */
    do{
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << question << "[" << min << "-" << max << "] :";
        cin >> userInput;

    }while(userInput < min || userInput > max || cin.fail());

    return userInput;
}
