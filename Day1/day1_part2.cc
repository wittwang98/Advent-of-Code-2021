#include <vector>
#include <fstream>
#include <iostream>
#include "readfile.h"

using namespace std;

int main() 
{

    vector<int> depthData = readfile("input.txt");
    int t = 0;
    for (int b = 1; b < (depthData.size()-2); b++)
    {
        if ((depthData[b] +  depthData[b+1] + depthData[b+2]) 
        > (depthData[b-1] + depthData[b] + depthData[b+1]))
        {
            t++;
        }
    }

    cout << t << endl;

    return 0;


}

