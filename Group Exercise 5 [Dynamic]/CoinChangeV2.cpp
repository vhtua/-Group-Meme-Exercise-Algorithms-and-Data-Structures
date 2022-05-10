#define INF numeric_limits<int>::max()

#include <bits/stdc++.h>

using namespace std;

void coinChange(int* coinSupply, int arraySize, int value)
{
    int M[value + 1];
    M[0] = 0;

    int S[value + 1];
    S[0] = 0;

    int i, j;
    for (i = 1; i <= value; ++i)
    {
        int min = INF;
        int coin = 0;

        for (j = 1; j <= arraySize; ++j)
        {
            if (i >= coinSupply[j])
            {
                if ((1 + M[i - coinSupply[j]]) < min)
                {
                    min = 1 + M[i - coinSupply[j]];
                    coin = j;
                }
            }
        }

        M[i] = min;
        S[i] = coin;
    }

    cout << "Minimum coin(s): " << M[value] << endl;
    cout << "We need: " << endl;

    int temp = value;

    while (temp > 0)
    {
        printf("%d\n", coinSupply[S[temp]]);
        temp = temp - coinSupply[S[temp]];
    }
}

int main()
{
    int coinSupply[] = { 0, 1, 10, 20, 25, 50, 100 };

    coinChange(coinSupply, 6, 482);

    return 0;
}