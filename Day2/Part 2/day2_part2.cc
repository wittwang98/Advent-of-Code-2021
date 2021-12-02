#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include "readfile.h"
#include <numeric>

using namespace std;

vector<int> horizontal;
vector<int> vertical;

int main() 
{
    horizontal.push_back(0);
    vertical.push_back(0);
    readfile("input.txt", horizontal, vertical);

    cout << "Horizontal:  " << accumulate(horizontal.begin(), horizontal.end(), 0) <<
    " Vertical: " << accumulate(vertical.begin(), vertical.end(), 0) << " Multiplied: " 
    << accumulate(horizontal.begin(), horizontal.end(), 0) * accumulate(vertical.begin(), vertical.end(), 0) << endl;

    return 0;
}