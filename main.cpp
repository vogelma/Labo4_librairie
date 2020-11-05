/*-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Maëlle Vogel
Date creation  : <jj.mm.aaaa>
Description    : <à compléter>
Remarque(s)    : <à compléter>
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n');
using namespace std;
int main() {

    cout << "Presser ENTER pour quitter";
    EMPTY_BUFFER
    return EXIT_SUCCESS;
}