#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Recursion Approach
int minCoinChangeRec(const int *supply, int distinctCoin, int value)
{
    if (value == 0) { return 0; }

    int result = INT_MAX;

    for (int i = 0; i < distinctCoin; i++)
    {
        if (supply[i] <= value)
        {
            int temp = minCoinChangeRec(supply, distinctCoin, value - supply[i]) + 1;

            if (temp != INT_MAX && temp < result)
            {
                result = temp;
            }
        }
    }

    if (result == INT_MAX) { return 0; }

    else { return result; }
}

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

    for (int i = 0; i < value + 1; i++)
    {
        if (table[i] < 0)
        {
            table[i] = 0;
        }
    }

    if (table[value] == INT_MAX) { return 0; }
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