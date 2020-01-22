#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string loadLine();
    static string conversionIntToString(int number);
    static string replaceFirstLetterWithCapitalLetterAndRestLowercase(string text);
    static int conversionStringToInt(string number);
    static string downloadNumber(string text, int characterPosition);
    static char loadCharacter();
    static int loadIntiger();
};

#endif
