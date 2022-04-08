#include <iostream>
#include <vector>

using namespace std;

int knapsack(int numberOfBag, int totalWeight, int weightList[], int valueList[], int* optimalKnapsack[]) {
    int** mainTable = new int*[numberOfBag];
    for(int i = 0; i < numberOfBag; ++i) {
        mainTable[i] = new int[totalWeight + 1];
    }

    for(int i = 0; i < numberOfBag; ++i) {
        mainTable[i][0] = 0; 
    }
    for(int j = 0; j < totalWeight + 1; ++j) {
        if(weightList[0] <= j) {
            mainTable[0][j] = valueList[0];
        } else {
            mainTable[0][j] = 0;
        }
    }
    for(int i = 1; i < numberOfBag; ++i) {
        for(int j = 0; j < totalWeight + 1; ++j) {
            if(j >= weightList[i] && mainTable[i - 1][j - weightList[i]] + valueList[i] > mainTable[i - 1][j]) {
                mainTable[i][j] = mainTable[i - 1][j - weightList[i]] + valueList[i];
            } else {
                mainTable[i][j] = mainTable[i - 1][j];
            }
        }
    }
    
    int knapsackChecker = mainTable[numberOfBag - 1][totalWeight];
    int i = numberOfBag - 1; // 5
    int j = totalWeight; // 10
    while(i != 0) {
        if(knapsackChecker != mainTable[i - 1][j]) {
            knapsackChecker = mainTable[i - 1][j - weightList[i]];
            (*optimalKnapsack)[i] = 1;
        } else {
            knapsackChecker = mainTable[i - 1][j];
        }
        i--;
    }
    if(knapsackChecker != 0) {
        (*optimalKnapsack)[0] = 1;
    }

    int result = mainTable[numberOfBag - 1][totalWeight];
    for(int i = 0; i < numberOfBag; ++i) {
        delete[] mainTable[i];
    }
    delete[] mainTable;
    return result;
}

int main() {
    cout << "==========[start]==========" << endl;

    int numberOfBag = 6;
    int totalWeight = 10;
    int weightList[numberOfBag] = {3, 2, 6, 1, 7, 4};
    int valueList[numberOfBag] = {7, 10, 2, 3, 2, 6};
    int* optimalKnapsack[numberOfBag];
    for(int i = 0; i < numberOfBag; ++i) {
        (*optimalKnapsack)[i] = 0;
    }

    int result = knapsack(numberOfBag, totalWeight, weightList, valueList, optimalKnapsack);

    cout << "The result is: " << result << endl;
    cout << "Optimal knapsack: {";
    for(int i = 0; i < numberOfBag; ++i) {
        if((*optimalKnapsack)[i] == 1) {
            if(i != numberOfBag - 1) {
                cout << i + 1 << ", ";
            } else {
                cout << i + 1 << "}" << endl;
            }
        }
    }

    cout << "==========[start]==========" << endl;
    return 0;
}