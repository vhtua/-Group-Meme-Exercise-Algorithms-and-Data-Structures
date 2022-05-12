#define INF 999999

#include <iostream>
#include <limits>
#include <algorithm>
#include <PrintTable.h>

using namespace std;

void floyd(int** graph, int v)
{
	int** result = new int* [v];
	for (int i = 0; i < v; ++i)
	{
		result[i] = new int[v];
	}

	int** path = new int* [v];
	for (int i = 0; i < v; ++i)
	{
		path[i] = new int[v]();
	}

	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			result[i][j] = graph[i][j];
		}
	}

	//for (int k = 0; k < v; ++k)
	//{
	//	for (int i = 0; i < v; ++i)
	//	{
	//		for (int j = 0; j < v; ++j)
	//		{
	//			result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
	//		}
	//	}
	//}

	for (int k = 0; k < v; ++k)
	{
		for (int i = 0; i < v; ++i)
		{
			for (int j = 0; j < v; ++j)
			{
				if (result[i][k] + result[k][j] < result[i][j])
				{
					result[i][j] = result[i][k] + result[k][j];
					path[i][j] = k + 1;
				}
			}
		}
	}

	printTable(result, v, v, 10);

	cout << endl << endl;

	cout << "The path graph:" << endl;

	printTable(path, v, v, 10);

	// Free allocated memory
	for (int i = 0; i < v; ++i)
	{
		delete[] result[i];
		result[i] = nullptr;
	}
	delete[] result;
	result = nullptr;

	for (int i = 0; i < v; ++i)
	{
		delete[] path[i];
		path[i] = nullptr;
	}
	delete[] path;
	path = nullptr;
}

int main()
{
	int vertex = 4;

	int** graph = new int* [vertex];
	for (int i = 0; i < vertex; ++i)
	{
		graph[i] = new int[vertex];
	}

	for (int i = 0; i < vertex; ++i)
	{
		for (int j = 0; j < vertex; ++j)
		{
			cin >> graph[i][j];
		}
	}

	cout << "The original matrix:" << endl;

	printTable(graph, vertex, vertex, 10);

	cout << endl << endl;

	cout << "Result:" << endl;

	floyd(graph, vertex);

	// Free allocated memory
	for (int i = 0; i < vertex; ++i)
	{
		delete[] graph[i];
		graph[i] = nullptr;
	}
	delete[] graph;
	graph = nullptr;

	return 0;
}