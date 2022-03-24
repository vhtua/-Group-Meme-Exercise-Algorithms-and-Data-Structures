#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

// prototype functions
void generate_arr(int arr[], int length);
void output(int arr[], int length);


// insertion sort
void insertion_sort(int arr[], int n);

// merge sort
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);

// quicksort
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

//comment


// ==================== MAIN WORKSPACE ==================================================

int main() {
    int length = 50;
    int choice = 0;
    printf("Enter the length (the number of elements) for the array: ");
    cin >> length;
    int arr[length];
    generate_arr(arr, length);

    // show the initial (unsorted) array
    cout << "\n" << "The unsorted array: " << endl;
        output(arr, length); //-->
    putchar('\n');
    // auto length = sizeof(arr) / sizeof(arr[0]);
    //printf("\nEnter the number corresponding to one type of sorting:\n")
    //cout << "(1) Insertion Sort" << endl << "(2) Merge Sort" << endl << "(3) Quick Sort" << endl;
    //cout << "Your choice is (1, 2, 3)? : ";
    //cin >> choice;
    do {
        printf("\nEnter the number corresponding to one type of sorting to test its running time:\n");
        cout << "(1) Insertion Sort" << endl << "(2) Merge Sort" << endl << "(3) Quick Sort" << endl;
        cout << "Your choice is (1, 2, 3)? : ";
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3) 
            cout << "Undefined choice. Please try again!";
        
        
        } while (choice != 1 && choice != 2 && choice != 3);
        
    if (choice == 1) {
        auto start = high_resolution_clock::now();
            insertion_sort(arr, length);                      
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\n" << "The sorted array: " << endl;
        output(arr, length);
        cout << "\n\nexecution time: "<< duration.count() * pow(10, -3) << " ms" << endl;
        printf("\n or %0.10lf ms", duration.count() * pow(10, -3));
        }
    else if (choice == 2) {
        auto start = high_resolution_clock::now();
                       
            merge_sort(arr, 0, length - 1);
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "\n" << "The sorted array: " << endl;
        output(arr, length);
        cout << "\n\nexecution time: "<< duration.count() * pow(10, -3) << " ms" << endl;
        printf("\n or %0.10lf ms", duration.count() * pow(10, -3));
        }
        else if (choice == 3) {
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, length - 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "\n" << "The sorted array: " << endl;
            output(arr, length);
            cout << "\n\nexecution time: "<< duration.count() * pow(10, -3) << " ms" << endl;
            printf("\n or %0.10lf ms", duration.count() * pow(10, -3));
        }

    // show results
//  cout << "\n" << "The sorted array: " << endl;
        //output(arr, length);
    //cout << "\n\nexecution time: "<< duration.count() * pow(10, -3) << " ms" << endl;
//  printf("\n or %0.10lf ms", duration.count() * pow(10, -3));

    return 0;
}

// ====================================

void generate_arr(int arr[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (10000 + 1);          // return natural numbers within [0, n]
    }
}


void insertion_sort(int arr[], int size) {
    for (int step = 1; step < size; step++) {
    int key = arr[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }

}


// ======================================================================
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i, j, k;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }

        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ======================================================================

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ==============================================================

void output(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
}