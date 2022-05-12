#include <iostream>
#include <vector>

using namespace std;

bool checkInBin(int node, vector<int>& bin) {
	for(int i = 0; i < bin.size(); ++i) {
		if(node == bin[i]) {
			return true;
		}
	}
	return false;
}

int findMinPosition(vector<int>& candidateValue) {
	int minValue = 1000;
	int minPosition = -1;
	int i = 0;
	while(i < candidateValue.size()) {
		if(minValue > candidateValue[i] && candidateValue[i] != -1) {
			minValue = candidateValue[i];
			minPosition = i;
		}
		i++;
	}
	return minPosition;
}

void dijkstra_shortestPath(vector<vector<int>>& baseMatrix, int numberOfNodes, int startingNode, vector<int>& result) {
	// set up candidateSet vector
	vector<int> candidateSet;
	int i = 0;
	while(startingNode != i + 1) {
		candidateSet.push_back(i + 1);
		i++;
	}
	int index = i;
	i++;
	while(index < numberOfNodes - 1) {
		candidateSet.push_back(i + 1);
		i++;
		index++;
	}

	// set up candidateValue vector
	vector<int> candidateValue;
	i = 0;
	while(startingNode != i + 1) {
		candidateValue.push_back(baseMatrix[startingNode - 1][i]);
		i++;
	}
	index = i;
	i++;
	while(index < numberOfNodes - 1) {
		candidateValue.push_back(baseMatrix[startingNode - 1][i]);
		i++;
		index++;
	}

	// set up bin vector
	vector<int> bin;

	// process
	int counter = numberOfNodes - 2;
	while(counter > 0) {
		// v = some element of C minimizing candidateValue[v]
		int currentStep = findMinPosition(candidateValue);
		// candidateSet[] = candidateSet[] / {v}
		bin.push_back(candidateSet[currentStep]);
		candidateSet[currentStep] = -1;
		// for each w in candidateSet[] do
		for(int i = 0; i < numberOfNodes - 1; ++i) {
			if(candidateSet[i] != -1 && checkInBin(candidateSet[i], bin) == false) {
				int a = candidateValue[i];
				int temp = bin.size() - 1;
				int b = candidateValue[currentStep] + baseMatrix[bin[temp] - 1][candidateSet[i] - 1];
				if(a > b) {
					candidateValue[i] = b;
				}
			}
		}
		// adding the least value to result
		int test = bin[bin.size() - 1] - 1;
		result[bin[bin.size() - 1] - 1] = candidateValue[currentStep];
		candidateValue[currentStep] = -1;
		// a new step
		counter--;
	}

	// find the last point that does not used
	int lastValue = 0;
	for(int i = 0; i < numberOfNodes; ++i) {
		if(result[i] == -1) {
			lastValue = i;
			break;
		}
	}
	// adding the last value to the last point
	for(int i = 0; i < numberOfNodes - 1; ++i) {
		if(candidateValue[i] != -1) {
			result[lastValue] = candidateValue[i];
			break;
		}
	}
	// erase the startingPoint
	for(int i = 0; i < numberOfNodes; ++i) {
		if(result[i] == 0) {
			result.erase(result.begin() + i);
			break;
		}
	}
}


int main() {
	cout << "=====[start]=====" << endl;

	// input
	int numberOfNodes;
	int startingNode;
	cin >> numberOfNodes >> startingNode;

	vector<vector<int>> baseMatrix(numberOfNodes);
	for(int i = 0; i < numberOfNodes; ++i) {
		baseMatrix[i] = vector<int> (numberOfNodes);
		for(int j = 0; j < numberOfNodes; ++j) {
			cin >> baseMatrix[i][j];
		}
	}

	// set up result vector
	vector<int> result(numberOfNodes);
	for(int i = 0; i < numberOfNodes; ++i) {
		if(i + 1 == startingNode) {
			result[i] = 0;
		} else {
			result[i] = -1;
		}
	}

	// process
	dijkstra_shortestPath(baseMatrix, numberOfNodes, startingNode, result);
	
	// output
	for(int i = 0; i < numberOfNodes - 1; ++i) {
		cout << result[i] << '\t';
	}
	cout << endl;

	cout << "======[end]======" << endl;
	return 0;
}