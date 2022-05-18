#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

#define V 8

int minKey(int key[], bool mstSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 

void printMST(int parent[], int graph[V][V]) {
    cout<<"Edge \tWeight\n";
    cout<<(char)97<<" - "<< "/" <<" \t"<<graph[0][parent[0]]<<" \n";
    for (int i = 1; i < V; i++)
        //cout<<(parent[i] <<" - "<< i <<" \t"<<graph[i][parent[i]]<<" \n";
        cout<<(char)(i + 97)<<" - "<<(char)(parent[i] + 97)<<" \t"<<graph[i][parent[i]]<<" \n";


    for (int i = 0; i <= V; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;

    // fill the values to the table
    // values
    printf("|V      |");
    for (int i = 0; i < V; ++i) {
        printf("  %-4c |", i + 97); 
    }

    cout << endl;
        for (int i = 0; i <= V; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;

    // array K
    printf("|k      |");
    for (int i = 0; i < V; ++i) {
        printf("  %-4d |", graph[i][parent[i]]); 
    }

    cout << endl;
        for (int i = 0; i <= V; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;


    //array p
    printf("|p      |");
    printf("  nill |");
    for (int i = 1; i < V; ++i) {
        printf("  %-4c |", parent[i] + 97); 
    }

    cout << endl;
        for (int i = 0; i <= V; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;

}


void printArrtoAscii(int parent[]) {
    cout << endl;
    cout << "/" << setw(4);
    for (int i = 1; i < V; ++i) {
        cout << (char) (parent[i] + 97) << "  " << setw(4);
    }
}
 

// Main alg
void primMST(int graph[V][V]) {
    // Array to store constructed MST
    int parent[V];
     
    // Key values used to pick minimum weight edge in cut
    int key[V];
     
    // To represent set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // print the constructed MST
    printMST(parent, graph);
    //printArrtoAscii(parent);

}


 
// Driver code
int main() {
    int graph[V][V] = { {0,12,5,4,0,0,0,0},
                        {12,0,9,11,0,0,0,0},
                        {5,9,0,2,2,4,0,0},
                        {4,11,2,0,7,0,1,0},
                        {0,0,2,7,0,0,3,0},
                        {0,0,4,0,0,0,8,1},
                        {0,0,0,1,3,8,0,0},
                        {0,0,0,0,0,1,0,0}   };



 
    // Print the solution
    primMST(graph);
 
    return 0;
}
 



/*
sample code

0	12	5	4	999	999	999	999
12	0	9	11	999	999	999	999
5	9	0	2	2	4	999	999
4	11	2	0	7	999	1	999
999	999	2	7	0	999	3	999
999	999	4	999	999	0	8	1
999	999	999	1	3	8	0	999b
999	999	999	999	999	1	999	0



0	12	5	4	0	0	0	0
12	0	9	11	0	0	0	0
5	9	0	2	2	4	0	0
4	11	2	0	7	0	1	0
0	0	2	7	0	0	3	0
0	0	4	0	0	0	8	1
0	0	0	1	3	8	0	0
0	0	0	0	0	1	0	0

{{0,12,5,4,0,0,0,0},
{12,0,9,11,0,0,0,0},
{5,9,0,2,2,4,0,0},
{4,11,2,0,7,0,1,0},
{0,0,2,7,0,0,3,0},
{0,0,4,0,0,0,8,1},
{0,0,0,1,3,8,0,0},
{0,0,0,0,0,1,0,0}}



 */