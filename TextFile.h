#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile
{
    const string FILE_NAME;

    public:
    TextFile(string FILENAME) : FILE_NAME(FILENAME) {};
    string getFileName();
    bool checkIfFileIsEmpty();
};

#endif
