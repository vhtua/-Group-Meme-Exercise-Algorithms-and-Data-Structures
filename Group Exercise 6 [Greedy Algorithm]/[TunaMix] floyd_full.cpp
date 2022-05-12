#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAXN 100
// Infinite value for array
const int INF = 1e7;

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];
int graph1[MAXN][MAXN];
// Initializing the distance and
// Next array
void initialise(int V, vector<vector<int>> &graph) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			dis[i][j] = graph[i][j];

			// No edge between node i and j
			if (graph[i][j] == INF || graph[i][j] == 999)
				Next[i][j] = -1;
			else
				Next[i][j] = j;
		}
	}
}

// Function construct the shortest path between u and v
vector<int> constructPath(int u, int v) {
	// If there's no path between node u and v, simply return an empty array
	if (Next[u][v] == -1)
		return {};

	// Storing the path in a vector
	vector<int> path = { u };
	while (u != v) {
		u = Next[u][v];
		path.push_back(u);
	}

	return path;
}
// Broken Back Tracking v1
vector<vector<int>> constructShortestMatrix(int V, vector<vector<int>> arr) {
	vector<vector<int>> result(V , vector<int> (V));	// create a 2D vector with size n x n

	for (int i = 0; i < V; ++i) {
		for(int j = 0; j < V; ++j) {
			result[i][j] = 0;
		}
	}

	for (int k = 0; k < V; ++k) {
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					result[i][j] = k + 1;

				}
			}
		}
	}

	return result; 
}


// Standard Floyd Warshall Algorithm with little modification Now if we find that dis[i][j] > dis[i][k] + dis[k][j] then we modify next[i][j] = next[i][k]
void floydWarshall(int V) {
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {

				// We cannot travel through edge that doesn't exist
				if (dis[i][k] == INF || dis[k][j] == INF)
					continue;

				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					Next[i][j] = Next[i][k];
				}
			}
		}
	}
}

// Print the shortest path
void printPath(vector<int>& path) {
	int n = path.size();
	for (int i = 0; i < n - 1; i++)
		cout << path[i] + 1 << " -> ";
	cout << path[n - 1] + 1 << endl;
}


void showMatrix(vector<vector<int>> m, int V) {
	cout << setw(4);
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < (int) m[i].size(); ++j) {
			cout << m[i][j] << " " << setw(4);
		}
		cout << endl;
	}
	cout << "======================" << endl;
}

void show2DArray(int arr[][MAXN], int V) {
	cout << setw(4);
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			cout << arr[i][j] << " " << setw(4);
		}
		cout << endl;
	}
	cout << "======================" << endl;
}



// ====== MAIN FUNCTION =======
int main() {

	int V = 5;
	//vector<vector<int>> graph(V , vector<int> (V));
	/*
		= { { 0, 3, INF, 7 },
			{ 8, 0, 2, INF },
			{ 5, INF, 0, 1 },
			{ 2, INF, INF, 0 } };
	*/

	/*
	for (int i = 0; i < V; ++i) {
		for(int j = 0; j < V; ++j) {
			cin >> graph[i][j];
		}
	}
	*/
	/*
	vector<vector<int>> graph	= { { 0, 5, INF, INF },
									{ 50, 0, 15, 5 },
									{ 30, INF, 0, 15 },
									{ 15, INF, 5, 0 } };
	*/
	//x y z t s
	vector<vector<int>> graph = { 	{0, INF, 4, INF, INF},
									{9, 0, 2, 3, INF},
									{6, INF, 0, INF, 7},
									{1, 2, INF, 0, INF},
									{INF, 5, INF, 10, 0} };

	cout << "\n\n======================\n";
	cout << "Execution of Floyd Alg: " << endl;

	initialise(V, graph);
	floydWarshall(V);
	show2DArray(dis, V);

	cout << "Shortest Matrix: " << endl;

	vector<int> path;


	//show2DArray(dis, V);
	//show2DArray(Next, V);
	showMatrix(constructShortestMatrix(V, graph), V); 


	cout << "Shortest path from s to x: "; // 5 - 1
	path = constructPath(4, 0);
	printPath(path);


	cout << "Shortest path from s to y: ";
	path = constructPath(4, 1);
	printPath(path);


	cout << "Shortest path from s to z: ";
	path = constructPath(4, 2);
	printPath(path);


	cout << "Shortest path from s to t: ";
	path = constructPath(4, 3);
	printPath(path);

	return 0;
}


/*
sample input

0 5 999 999
50 0 15 5
30 999 0 15
15 999 5 0


 */