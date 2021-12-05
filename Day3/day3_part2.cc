#include <vector>
#include <fstream>
#include <iostream>
#include "readfile.h"
#include <math.h>

using namespace std;

string oxOrCo(string& allData, int const& spacing, int bitPos, vector<string>logdata, bool ox)
{
    string finalString{};
    for (bitPos; bitPos< spacing; bitPos++)
    {
        int temp{0};
        for (int specificIndex{0}; specificIndex < allData.size(); specificIndex += spacing)
        {   
            temp += (allData.at(specificIndex+bitPos)-48);
        }

        if (ox)
        {
            if (temp >= 0.5*logdata.size())
            {
                finalString.append("1");
            }
            else{
                finalString.append("0");
            }
        }
        else{
            if (temp <= 0.5*logdata.size())
            {
                finalString.append("0");
            }
            else{
                finalString.append("1");
            }
        }
    }
    return finalString;
}


int main() 
{
    vector<string> logdata = readfile("test.txt");
    
    string allData{};
    for (string x : logdata)
        allData += x;

    int gammaNumber{0};
    int epsilonNumber{0};
    int bitPos{0};
    int spacing{logdata[0].size()};

    vector<string> oxCopy = logdata;
    vector<string> COCopy = logdata;
    cout << oxCopy.size() << endl << COCopy.size() << endl;
    //oxygen
    int i{0};
    string OxygenRemoval = oxOrCo(allData, spacing, bitPos, logdata, true);
    string oxData{};
    cout << OxygenRemoval << " ";
    for (char a : OxygenRemoval)
    {
        i++;
        int t{0};
        for (string e : oxCopy)
        {
            if (oxCopy.size() == 1)
            {
                goto oxValFound;
            }
            if (e[i] == a)
            {
                oxCopy.erase(oxCopy.begin()+t);
                t++;
            }
        }
        cout << OxygenRemoval << "hej ";
        for (string x : oxCopy)
            oxData += x;
        OxygenRemoval = oxOrCo(oxData, spacing, bitPos, oxCopy, true);
    }
oxValFound:
    cout << endl << endl;
    //co2
    i = 0;
    string COremoval = oxOrCo(allData, spacing, bitPos, logdata, false);
    string COData{};
    cout << COremoval << " ";
    for (char a : COremoval)
    {
        i++;
        int t{0};
        for (string e : COCopy)
        {
            if (COCopy.size() == 1)
            {
                goto COValFound;
            }
            if (e[i] == a)
            {
                COCopy.erase(COCopy.begin()+t);
                t++;
            }
        }
        cout << COremoval << " hej";
        for (string x : COCopy)
            COData += x;
        COremoval = oxOrCo(COData, spacing, bitPos, COCopy, false);
    }
COValFound:  
    cout << oxCopy[0]<< endl << COCopy[0] << endl;
    return 0;
}