#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "readfile.h"
#include <math.h>
#include <string>
#include <numeric>

using namespace std;

int control(vector<vector<int>> const& boards);

int main() 
{
    vector<string> bingo = readfile("input.txt");
    int controlReturn{};
    string unformattedDraw = bingo[0];
    bingo.erase(bingo.begin());

    vector<int> drawnNumbers{};

    stringstream ss(unformattedDraw);

    while (ss.good())
    {
        string a{};
        getline(ss, a, ',');
        drawnNumbers.push_back(stoi(a));
    }

    vector<vector<int>> boards{};
    vector<int> board{};
    for (string b : bingo)
    {   

        if (b != "")
        {
            stringstream bb(b);

            while (bb.good())
            {
                string a{};
                getline(bb, a, ' ');
                if (a == "")
                {
                    getline(bb, a, ' ');
                }
                board.push_back(stoi(a));
            }
        }
        else{
            boards.push_back(board);
            board.clear();
        }
    }

    int lastDrawn{};
    for (int a : drawnNumbers)
    {
        for (vector<int> b : boards)
        {
            for (int c : b){
                if (c == a)
                {
                    lastDrawn = a;
                    c = 0;
                }
            }
        }
        controlReturn = control(boards);
        if (controlReturn != -1)
        {
            goto aWinner;
        }
    }

aWinner:
    int unmarkedsum = accumulate(boards[controlReturn].begin(), boards[controlReturn].end(), 0);
    cout << unmarkedsum*lastDrawn << endl;
    return 0;
}

int control(vector<vector<int>> const& boards)
{
    int boardNumber{};
    int spacing = sqrt(boards[0].size());
    for (vector<int> i : boards)
    {
        int rowBingo{};
        int columnBingo{};
        for (int b = 0; b < spacing; b++)
        {
            rowBingo = accumulate((i.begin()+(b*spacing)), (i.begin()+b*spacing+spacing), 0);
            if (rowBingo == 0)
            {
                return boardNumber;
            }
            for (int t = 0; t < spacing; t++)
            {
                columnBingo += i[b*t+t];
            }
        }

        boardNumber++;
    }
    return -1;
}