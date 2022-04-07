#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Data declaration
const int items = 5;
int total_Weight = 10;
int weight[items] = {6, 5, 4, 2, 2};
int value[items] = {6, 3, 5, 4, 6};


// recursive method
int Knapsack(int items, int total_Weight) {
    if (items == 1) 
        return (total_Weight < weight[items]) ? 0 : value[0];
    if (total_Weight < weight[items])
        return Knapsack(items - 1, total_Weight);

    return max(Knapsack(items - 1, total_Weight), Knapsack(items - 1, total_Weight - weight[items]));
}

// DP Method
int Knapsack_DP(int weight[], int value[], int items, int total_Weight) {
    // create the 2d dynamic table
    int **Knapsack_table = new int* [items];
    for (int i = 0; i < total_Weight; ++i) {
        Knapsack_table[i] = new int[total_Weight];
    }

    // base cases
    for (int i = 0; i < items; ++i) {
        Knapsack_table[i][0] = 0;
    }

    for (int j = 0; j < total_Weight; ++j) {
        if (weight[0] <= j) {
            Knapsack_table[0][j] = value[0];
        }
        else {
            Knapsack_table[0][j] = 0;
        }
    }

    for (int i = 1; i < items; ++i) {
        for (int j = 1; j <= total_Weight; ++j) {
            if (j >= weight[i] && Knapsack_table[i - 1][j - weight[i]] + value[i] > Knapsack_table[i - 1][j])
        }
    }


    return 1;
}


// Main function
int main() {
    cout << Knapsack(items, total_Weight);



    return 0;
}