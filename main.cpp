//
//  main.cpp
//  template
//
//  Created by Priyanka Nagulapally on 06.08.20.
//  Copyright © 2020 Priyanka Nagulapally. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
class Bingo {
public:
    int BingoNumbers();
    void BingoCards(int tmp2[][5]);
    bool checkBingoCards(bool** tmp2);
};

int Bingo::BingoNumbers() {
    return 0;
}

void Bingo::BingoCards(int bingoCard[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bingoCard[i][j] = 1;
        }
    }

 }

bool Bingo::checkBingoCards(bool** tmp2) {
    return NULL;
}


int main()
{
   Bingo bingo;
   int tmp = bingo.BingoNumbers();
   std::cout << tmp << "\n";

    //to generate space for bingo card
    int bingoCard[5][5];

    //to get the bingo card;
    bingo.BingoCards(bingoCard);
    //to print bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << bingoCard[i][j] << " ";
        }
        std::cout << "\n";
    }
L2:
    //check method checkBingoCards
    bool** bingoCardWinner;
    //generate cards of non winner
    bool** bingoCardFailed;
    bingoCardFailed = new bool* [5];
    for (int i = 0; i < 5; i++)
    {
        bingoCardFailed[i] = new bool[5];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bingoCardFailed[i][j] = true;
        }
    }
    bingoCardFailed[0][2] = false;
    bingoCardFailed[4][4] = false;

    bool isWinner = bingo.checkBingoCards(bingoCardFailed);

    if (isWinner) std::cout << "Winner\n";
    else std::cout << "Non-Winner\n";
}
