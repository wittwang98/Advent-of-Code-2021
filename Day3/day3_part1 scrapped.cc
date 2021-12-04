#include <vector>
#include <fstream>
#include <iostream>
#include "readfile.h"

using namespace std;

char bitFrequency(vector<char> const& bits, bool mostCommon)
{
    int ones{};
    for (char x : bits)
        ones++;

    if (mostCommon)
    {
        if (ones > bits.size())
        {
            return '1';
        }
        return '0';
    }
    if (ones < bits.size())
    {
        return '1';
    }
    return '0';  
}

int main() 
{
    vector<char> firstBit{};
    vector<char> secondBit{};
    vector<char> thirdBit{};
    vector<char> fourthBit{};
    vector<char> fifthBit{};

    vector<string> logdata = readfile("input.txt");

    for (string x : logdata)
    {
        firstBit.push_back(x.at(0));
        secondBit.push_back(x.at(1));
        thirdBit.push_back(x.at(2));
        fourthBit.push_back(x.at(3));
        fifthBit.push_back(x.at(4));
    }

    //gamma
    vector<char> firstGammaBit{bitFrequency(firstBit, true)};
    vector<char> secondGammaBit{bitFrequency(secondBit, true)};
    vector<char> thirdGammaBit{bitFrequency(thirdBit, true)};
    vector<char> fourthGammaBit{bitFrequency(fourthBit, true)};
    vector<char> fifthGammaBit{bitFrequency(fifthBit, true)};

    //epsilon
    vector<char> firstEpsilonBit{bitFrequency(firstBit, false)};
    vector<char> secondEpsilonBit{bitFrequency(secondBit, false)};
    vector<char> thirdEpsilonBit{bitFrequency(thirdBit, false)};
    vector<char> fourthEpsilonBit{bitFrequency(fourthBit, false)};
    vector<char> fifthEpsilonBit{bitFrequency(fifthBit, false)};

    
    for (int i{0}; i < logdata.size(); i++)
    {
        string temp{};
        temp+=(firstEpsilonBit[0]);
        temp+=(secondEpsilonBit[0]);
        temp+=(thirdEpsilonBit[0]);
        temp+=(fourthEpsilonBit[0]);
        temp+=(fifthEpsilonBit[0]);

        
    }
    
    

    return 0;


}

