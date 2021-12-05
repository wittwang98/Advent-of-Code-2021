#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector<string> readfile(string const& fileName)
{
    vector<string> information;
    fstream file;
    file.open(fileName, ios::in);

    if (file.is_open())
    {   
        string line;
        while (getline(file, line))
        {
            information.push_back(line);
        }
        file.close();
    }

    return information;
};