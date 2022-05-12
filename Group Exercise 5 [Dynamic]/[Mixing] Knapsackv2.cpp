#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int knapsack(int numberOfBag, int totalWeight, const int* weightList, const int* valueList, int* optimalKnapsack) {
    // initialize main table
    int** mainTable = new int*[numberOfBag];
    for(int i = 0; i < numberOfBag; ++i) {
        mainTable[i] = new int[totalWeight + 1];
    }

    // base case
    for(int i = 0; i < numberOfBag; ++i) {
        mainTable[i][0] = 0; 
    }
    for(int j = 0; j < totalWeight + 1; ++j) {
        if(weightList[0] <= j) {
            mainTable[0][j] = valueList[0];
        } else {
            mainTable[0][j] = 0;
        }
    }

    // filling the values
    for(int i = 1; i < numberOfBag; ++i) {
        for(int j = 0; j < totalWeight + 1; ++j) {
            if(j >= weightList[i] && mainTable[i - 1][j - weightList[i]] + valueList[i] > mainTable[i - 1][j]) {
                mainTable[i][j] = mainTable[i - 1][j - weightList[i]] + valueList[i];
            } else {
                mainTable[i][j] = mainTable[i - 1][j];
            }
        }
    }

    
    // backtracking for finding optimal knapsack
    vector<int> selection1;
    int knapsackChecker = mainTable[numberOfBag - 1][totalWeight];
    int i = numberOfBag - 1; // 5
    int j = totalWeight; // 10
    //int actualWeight 
    while(i != 0 && j > 0) {
        if(knapsackChecker != mainTable[i - 1][j]) {
            knapsackChecker = mainTable[i - 1][j - weightList[i]];
            j = j - weightList[i];
            optimalKnapsack[i] = 1;
            //optimalKnapsack[i] = 1;
        } else {
            knapsackChecker = mainTable[i - 1][j];
        }
        i--;
    }
    
    if(knapsackChecker != 0) {
        optimalKnapsack[0] = 1;
    }

    // vector for bin selection
    vector <int> selection;
    int bin_choice_arr[numberOfBag];
    for(int i = 0; i < numberOfBag; ++i) {
        if(optimalKnapsack[i] == 1) {
            if(i != numberOfBag - 1) {
                selection.push_back(i+1);
            } else {
                selection.push_back(i+1);
            }
        }
    }
    /* for debug -->
    for (int x : selection) {
        cout << x << std::endl;
    }
    */

    for (int i = 0; i < numberOfBag; ++i) {
        bin_choice_arr[i] = 0;
    }

    for (int i = 0; i < numberOfBag; ++i) {
        for (int j : selection) {
            if (i == j - 1) {
                bin_choice_arr[i] = 1;
                ++i;
            }
        }
    }
    /* for debug -->
    for (int i = 0; i < numberOfBag; ++i) {
        cout << bin_choice_arr[i] << " ";
    }
    */

    // TunaCSE ==> show Value Table
    cout << "\n---> Knapsack Prompt:" << endl;
    /* create an empty row
    for (int i = 0; i <= numberOfBag; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;
    for (int i = 0; i <= numberOfBag; ++i) {
        printf("|       ");
    }
    cout << "|" << endl;

    */
        for (int i = 0; i <= numberOfBag; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;

        // fill the values to the table
        // item
    printf("|item#  |");
    for (int i = 0; i < numberOfBag; ++i) {
        printf("  %-4d |", i + 1); 
    }

    cout << endl;
        for (int i = 0; i <= numberOfBag; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;

    // weight
    printf("|weight |");
    for (int i = 0; i < numberOfBag; ++i) {
        printf("  %-4d |", weightList[i]); 
    }
    
    cout << endl;
        for (int i = 0; i <= numberOfBag; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;


    // value
    printf("|value  |");
    for (int i = 0; i < numberOfBag; ++i) {
        printf("  %-4d |", valueList[i]); 
    }
    
    cout << endl;
        for (int i = 0; i <= numberOfBag; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;

    // bin choice?
    printf("|pick?  |");
    for (int i = 0; i < numberOfBag; ++i) {
        printf("  %-4d |", bin_choice_arr[i]); 
    }
    
    cout << endl;
        for (int i = 0; i <= numberOfBag; ++i) {
        printf("+-------");
    }
    cout << "+" << endl;




    printf("\n\n");


    // -->debug
    /* uncomment to show the table of DP algorithms
    cout << setw(4);
    for (int i = 0; i < numberOfBag; ++i) {
        for (int j = 0; j < totalWeight + 1; ++j) {
            cout << mainTable[i][j] << " " << setw(4) ; 
        }
        cout << endl;
    }
    printf("\n\n"); 
    */

    // delete main table
    int result = mainTable[numberOfBag - 1][totalWeight];
    for(int i = 0; i < numberOfBag; ++i) {
        delete[] mainTable[i];
    }
    delete[] mainTable;

    return result;
}

// ============== Main function ================
int main() {
    cout << "==========[start]==========" << endl;

    // input
    int numberOfBag = 7;
    int totalWeight = 10;
    int weightList[numberOfBag] = {3, 2, 6, 1, 7, 4, 8};
    int valueList[numberOfBag] = {7, 10, 2, 3, 2, 6, 100};
    int optimalKnapsack[numberOfBag];
    for(int i = 0; i < numberOfBag; ++i) {
        optimalKnapsack[i] = 0;
    }

    // process
    int result = knapsack(numberOfBag, totalWeight, weightList, valueList, optimalKnapsack);

    


    // output
    cout << "The result (Possible Max value) is: " << result << endl;
    cout << "Optimal knapsack --> item# : ";
    for(int i = 0; i < numberOfBag; ++i) {
        if(optimalKnapsack[i] == 1) {
                cout << i + 1 << "  ";
        }
    }

    cout << "\n===========[end]===========" << endl;
    return 0;
}