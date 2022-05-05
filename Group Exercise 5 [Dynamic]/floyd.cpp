#include <iostream>
#include <algorithm>

using namespace std;

void floyd_alg(int **matrix, int numberOfnode) {
	for (int k = 0; k < numberOfnode; ++k) {
		for (int i = 0; i < numberOfnode; ++i) {
			for (int j = 0; j < numberOfnode; ++j) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	//return result;
}

int** shortest_path(int **matrix, int numberOfnode) {
	// initialize the result matrix to 0
	int** result = new int* [numberOfnode];

	for (int i = 0; i < numberOfnode; ++i) {
		result[i] = new int [numberOfnode];
	}

	for (int i = 0; i < numberOfnode; ++i) {
		for (int j = 0; j < numberOfnode; ++j) {
			result[i][j] = 0;
		}
	}

	// for debug --> cout << "Running SP?\n";

	// execution the alg
	for (int k = 0; k < numberOfnode; ++k) {
		//--> for debug cout << "Running loop k?";
		for (int i = 0; i < numberOfnode; ++i) {
			for (int j = 0; j < numberOfnode; ++j) {
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					// for debug --> cout << "< yes?" << endl;
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					result[i][j] = k;
					cout << "Debug --> shortest:\n";
					cout << k << " ";
				}
			}
		}
	}

	


	// for debug (show the value of the matrix) -->
	/*
	for (int i = 0; i < numberOfnode; ++i) {
		for (int j = 0; j < numberOfnode; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return result;
}

void showMatrix(int** matrix, int length) {
	cout << "\n\n";
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void cleanMem(int** matrix, int length) {
	for (int i = 0; i < length; ++i) {
		delete[] matrix[i];
	}   
	delete[] matrix;
}



// ======== Main function =======
int main() {
	int numberOfnode;
	cin >> numberOfnode;

	int** matrix = new int* [numberOfnode];

	for (int i = 0; i < numberOfnode; ++i) {
		matrix[i] = new int [numberOfnode];
	}

	for (int i = 0; i < numberOfnode; ++i) {
		for (int j = 0; j < numberOfnode; ++j) {
			cin >> matrix[i][j];
		}
	}

	// find the matrix D4
	floyd_alg(matrix, numberOfnode);
	showMatrix(matrix, numberOfnode);

	// find the final matrix 
	int** shortest = new int* [numberOfnode];

	for (int i = 0; i < numberOfnode; ++i) {
		shortest[i] = new int [numberOfnode];
	}

	for (int i = 0; i < numberOfnode; ++i) {
		for (int j = 0; j < numberOfnode; ++j) {
			shortest[i][j] = 0;
		}
	}

	shortest = shortest_path(matrix, numberOfnode);
	showMatrix(shortest, numberOfnode);
	



	// clean the memory
	cleanMem(matrix, numberOfnode);
	cleanMem(shortest, numberOfnode);

	cout << "Successfully Compiled!!!";
	return 0;
}



// sample input
/* inputf.in

4
0 5 20 10
50 0 15 5
30 35 0 15
15 20 5 0

 */