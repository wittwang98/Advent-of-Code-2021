#include <vector>
#include <fstream>
#include <iostream>
#include "readfile.h"
#include <math.h>

using namespace std;

int main() 
{
    vector<string> logdata = readfile("input.txt");
    
    string allData{};
    for (string x : logdata)
        allData += x;

    int spacing{logdata[0].size()};

    int gammaNumber{0};
    int epsilonNumber{0};

    int bitPos{0};

    for (bitPos; bitPos< spacing; bitPos++)
    {
        int temp{0};
        for (int specificIndex{0}; specificIndex < allData.size(); specificIndex += spacing)
        {   
            temp += (allData.at(specificIndex+bitPos)-48);
        }

        if (temp < 0.5*logdata.size())
        {
            epsilonNumber += pow(2, (spacing-bitPos-1));
        }
        else
        {
            gammaNumber += pow(2, (spacing-bitPos-1));
        }
    }
    cout << "Epsilon: " << epsilonNumber << endl << "Gamma: " << gammaNumber << endl
    << "Power consumption: " << (epsilonNumber*gammaNumber) << endl;
    return 0;
}