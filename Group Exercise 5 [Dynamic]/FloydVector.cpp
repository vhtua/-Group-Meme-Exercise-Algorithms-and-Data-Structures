#include <iostream>
#include <algorithm>
#include <vector>
#include <PrintTable.h>

#define V 4
#define INF 999999

using namespace std;

void floyd(vector<vector<int>> graph)
{
    vector<vector<int>> result(V, vector<int>(V, 0));
    vector<vector<int>> path(V, vector<int>(V, 0));

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            result[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (result[i][k] + result[k][j] < result[i][j])
                {
                    result[i][j] = result[i][k] + result[k][j];
                    path[i][j] = k + 1;
                }
            }
        }
    }

    cout << "Result:" << endl;

    printTable(result, V, V, 10);

    cout << endl << endl;

    cout << "The path graph:" << endl;

    printTable(path, V, V, 10);
}

int main()
{
    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }

    cout << "The original matrix:" << endl;

    printTable(graph, V, V, 10);

    cout << endl << endl;

    floyd(graph);

    return 0;
}