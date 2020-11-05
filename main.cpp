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