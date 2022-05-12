#include <iostream>

using namespace std;

int coinChange(int coinNumber, int totalValue, const int* dCoin, int* optimalCoin) {
    // initialize main table
    int** mainTable = new int*[coinNumber];
    for(int i = 0; i < coinNumber; ++i) {
        mainTable[i] = new int[totalValue + 1];
    }

    // base case
    for(int i = 0; i < coinNumber; ++i) {
        mainTable[i][0] = 0;
    }

    // filling the values
    for(int i = 0; i < coinNumber; ++i) {
        int currentCoin = dCoin[i];
        for(int j = 1; j < totalValue + 1; ++j) {
            if(i == 0) {
                mainTable[i][j] = j;
            } else if(j < currentCoin) {
                mainTable[i][j] = mainTable[i - 1][j];
            } else {
                mainTable[i][j] = (mainTable[i - 1][j] < mainTable[i][j - currentCoin] + 1)? mainTable[i - 1][j] : mainTable[i][j - currentCoin] + 1; 
            }
        }
    }

    /*
    for(int i = 0; i < coinNumber; ++i) {
        for(int j = 0; j < totalValue + 1; ++j) {
            cout << mainTable[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
    */

    // backtracking for optimal coin
    int coinChecker = mainTable[coinNumber - 1][totalValue];
    int counter = coinChecker;
    int i = coinNumber - 1;
    int j = totalValue;
    while(counter != 0) {
        if(j == 1) {
            optimalCoin[0]++;
            break;
        }
        if(coinChecker == mainTable[i - 1][j]) {
            i--;
            coinChecker = mainTable[i][j];
        }
        if(coinChecker == mainTable[i][j - dCoin[i]] + 1) {
            coinChecker = mainTable[i][j - dCoin[i]];
            j -= dCoin[i];
            optimalCoin[i]++;
            counter--;
        }
    }

    // delete main table
    int result = mainTable[coinNumber - 1][totalValue];
    for(int i = 0; i < coinNumber; ++i) {
        delete[] mainTable[i];
    }
    delete[] mainTable;

    return result;
}

int main() {
    cout << "==========[start]==========" << endl;

    // input
    int coinNumber = 6;
    int totalValue = 276;
    int dCoin[coinNumber] = {1, 10, 20, 25, 50, 100};
    /*
    for (int i = 0; i < coinNumber; ++i)
    {
        cin >> dCoin[i];
    }
    */
    int* optimalCoin = new int[coinNumber];
    for(int i = 0; i < coinNumber; ++i) {
        optimalCoin[i] = 0;
    }

    // process
    int result = coinChange(coinNumber, totalValue, dCoin, optimalCoin);

    // output
    cout << "Minimum number of coins: " << result << endl;
    cout << "Optimal coin(s) for a total value of " << totalValue << " is:" << endl;
    for(int i = 0; i < coinNumber; ++i) {
        if(optimalCoin[i] != 0) {
            cout << '\t' <<  optimalCoin[i] << " coin(s) of value " << dCoin[i] << endl;
        }
    }

    // delete optimalCoin[]
    delete[] optimalCoin;

    cout << "===========[end]===========" << endl;
    return 0;
}