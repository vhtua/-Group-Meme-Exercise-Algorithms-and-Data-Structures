#include <iostream>
#include<bits/stdc++.h>
#include <string>

using namespace std;

// Count every possible way
// int count(const int *supply, int distinctCoin, int value)
// {
//     if (value == 0) { return 1; }
// 
//     if (value < 0 || distinctCoin < 0) { return 0; }
// 
//     if (value > 0 && distinctCoin <= 0) { return 0; }
// 
//     return count(supply, distinctCoin, value - supply[distinctCoin - 1]) + count(supply, distinctCoin - 1, value);
// }

// Recursion
// int minCoinChange(const int *supply, int distinctCoin, int value)
// {
//     if (value == 0) { return 0; }
// 
//     int result = INT_MAX;
// 
//     for (int i = 0; i < distinctCoin; i++)
//     {
//         if (supply[i] <= value)
//         {
//             int temp = minCoinChange(supply, distinctCoin, value - supply[i]);
// 
//             if (temp != result && temp + 1 < result)
//             {
//                 result = temp + 1;
//             }
//         }
//     }
// 
//     if (result == INT_MAX) { return -1; }
// 
//     else { return result; }
// }

// DP Approach
int minCoinChange(const int *supply, int distinctCoin, int value)
{
    if (value == 0) { return 0; }

    int table[value + 1];
    table[0] = 0;

    for (int i = 1; i < value + 1; i++)
    {
        table[i] = INT_MAX;
    }

    for (int i = 1; i < value + 1; i++)
    {
        for (int j = 0; j < distinctCoin; j++)
        {
            if (supply[j] <= i)
            {
                int currentCount = table[i - supply[j]] + 1;

                if (currentCount != INT_MAX && currentCount < table[i])
                {
                    table[i] = currentCount;
                }
            }
        }
    }

    if (table[value] == INT_MAX) { return -1; }
    else { return table[value]; }
}

int main()
{
    int supply[6] = { 1, 10, 20, 25, 50, 100 };
    int distinctCoin = 6;
    int value = 281;

    cout << "The minimum numbers of coins required is: ";
    cout << minCoinChange(supply, distinctCoin, value) << " coin(s)" << endl;

    system("pause");
    return 0;
}