//
//  main.cpp
//  template
//
//  Created by Priyanka Nagulapally on 06.08.20.
//  Copyright © 2020 Priyanka Nagulapally. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int gen_random(int min, int max, int count) //range : generate random numbers in the range [min, max)
{
    static bool first = true;
    if (first) 
    {
        srand(time(NULL) + count); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

class Bingo {
public:
    Bingo(string name): name_{name} {};
    void BingoCards();                             // to generate the Bingo card 
    void get_bingoCard();
    bool checkBingoCard(int cutOff);                    // fucntion to cut of number from the Bingocard 
    int check_if_BINGO();

private:
    string name_;
    string word = "00000";
    vector<int> numbersCalled_;                                 // numbers that have already been called
    int bingoCard_[5][5];
};

int Bingo::check_if_BINGO()
{
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) 
    {
        int count = 0;
        for (j = 0; j < 5; j++)
            count += bingoCard_[i][j];
        if (count == 0)
            word[i] = '1';
            // cout << "\nRow " << i << " done";
    }
    if (word == "11111")
    {
        cout << "BINGO!" << " by " << name_;
        return 1;
    }
    else
        return 0;
}

bool Bingo::checkBingoCard(int cutOff)
{
    int i = 0, j = 0, check_var = 0;
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++) 
        {
            if (bingoCard_[i][j] == cutOff)
            {
                bingoCard_[i][j] = 0;
                check_var = check_if_BINGO();
                // cout << cutOff << " at " << i << ", " << j << endl;
            }
            if (check_var == 1)
                return true;
        }
    }
    if (check_var == 0)
        return false;
    // if (flag == 0)
    //     return false;
}

void Bingo::get_bingoCard()
{
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++) 
        {
            cout << bingoCard_[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Bingo::BingoCards() {
    int val = 0, it_count = 0, i = 0;
    int start = 1;
    int min = 0, max = 0;
    
    for (i = 0; i < 5; i++) 
    {
        vector<int> arr;
        min = start;
        max = start + 14;
        while (arr.size() != 5)
        {
            it_count++;
            val = gen_random(min, max, it_count+i);
            if (count(arr.begin(), arr.end(), val))
                continue;
            else
                arr.emplace_back(val);
            // bingoCard_[i][arr.size()-1] = val;
            bingoCard_[arr.size()-1][i] = val;
        }
        start = start + 15;
    }
    bingoCard_[2][2] = 0;
 }


void generateNumbers(Bingo& b1, Bingo& b2)
{
    vector<int> nums_generated;
    int total = 75, i = 0, gen_val = 0;
    bool isWinner1, isWinner2;
    while (int(nums_generated.size()) != total)
    {
        i++;
        gen_val = gen_random(1, 75, i*2);
        if (count(nums_generated.begin(), nums_generated.end(), gen_val))
            continue;
        else
        {
            nums_generated.emplace_back(gen_val);
            isWinner1 = b1.checkBingoCard(gen_val);
        }
    }
}



int main()
{
    Bingo bingo1{"priyanka"}, bingo2{"shrinivas"};
    bingo1.BingoCards();
    bingo1.get_bingoCard();
    cout << "\n";
    bingo2.BingoCards();
    bingo2.get_bingoCard();
    generateNumbers(bingo1, bingo2);
    cout << endl;
}
