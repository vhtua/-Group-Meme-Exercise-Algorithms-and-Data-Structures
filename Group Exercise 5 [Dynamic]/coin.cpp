#include <iostream>

using namespace std;

int coinChange(int coinNumber, int totalValue, const int* dCoin) {
    int** mainTable = new int*[coinNumber];
    for(int i = 0; i < coinNumber; ++i) {
        mainTable[i] = new int[totalValue + 1];
    }

    for(int i = 0; i < coinNumber; ++i) {
        mainTable[i][0] = 0;
    }

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
    int result = mainTable[coinNumber - 1][totalValue];
    
    for(int i = 0; i < coinNumber; ++i) {
        delete[] mainTable[i];
    }
    delete[] mainTable;
    
    return result;
}

int main() {
    cout << "==========[start]==========" << endl;

    int coinNumber = 6;
    int totalValue = 281;
    int dCoin[coinNumber] = {1, 10, 20, 25, 50, 100};

    cout << "Minimum number of coins: " << coinChange(coinNumber, totalValue, dCoin) << endl;

    cout << "===========[end]===========" << endl;
    return 0;
}