#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct readfile
{
    bool direction;
    int change;
};


int numbermod(char& a, int b)
{
    if (a == 'u')
    {
        return -b;
    }
    else
    {
        return b;
    }
};

int readfile(string const& fileName, vector<int>& horizontal, vector<int>& vertical)
{
    fstream file;
    file.open(fileName, ios::in);

    if (file.is_open())
    {   
        string line;
        while (getline(file, line))
        {
            char t = line[0];
            if (t == 'f')
            {
                horizontal.push_back(stoi(line.substr(line.find(' '), -1)));
            }
            else{
                int temp = numbermod(t, stoi(line.substr(line.find(' '), -1)));
                vertical.push_back(temp);
            }
        }
        file.close();
    }

    return 0;
};