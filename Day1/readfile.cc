#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "readfile.h"

using namespace std;

vector<int> readfile(string const& fileName)
{
    vector<int> information;
    fstream file;
    file.open(fileName, ios::in);

    if (file.is_open())
    {   
        string line;
        while (getline(file, line))
        {
            information.push_back(stoi(line));
        }
        file.close();
    }

    return information;
};