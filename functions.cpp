#include "functions.h"
#include <iostream>
#include <random>
using namespace std;


// GLOBAL VARIABLES DEFINITIONS
int swaps = 0;
int comparisons = 0;


// Function definitions
void printArray(int arr[], int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << i + 1 << ": " << arr[i] << endl;
    }
}
int* initArray1(int size) {
    int* arrPtr = new int[size];

    random_device rd; // Seed
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1024); // Range 0 - 1024

    for (int i = 0; i < size; i++) {
        arrPtr[i] = dis(gen);
    }

    return arrPtr;
}
int* initArray2(int size) {
    int* arrPtr = new int[size];
    int next = 0;

    for (int i = 0; i < size; i++) { // Generate an increasing sequence
        next += (rand() % 5) + 1; // Increment small random amounts
        arrPtr[i] = next;
    }

    // Randomize 10% of the array
    int randomElements = size / 10; // 10% of size
    for (int i = 0; i < randomElements; i++) {
        int randomIndex = rand() % size; // Valid index
        arrPtr[randomIndex] = rand() % 1024; // Replace with random value
    }

    return arrPtr;
}
int* initArray3(int size) {
    int* arrPtr = new int[size];
    int next = 0;

    for (int i = size - 1; i >= 0; i--) { // Generate a decreasing sequence
        next += (rand() % 5) + 1; // Decrement small random amounts
        arrPtr[i] = next;
    }

    // Randomize 10% of the array
    int randomElements = size / 10; // 10% of size
    for (int i = 0; i < randomElements; i++) {
        int randomIndex = rand() % size; // Valid index
        arrPtr[randomIndex] = rand() % 1024; // Replace with random value
    }

    return arrPtr;
}
int* initArray4(int size) {
    int* arrPtr = new int[size];
    int next = 0;

    for (int i = 0; i < size; i++) {
        next += (rand() % 5) + 1;
        arrPtr[i] = next;
    }

    int startIndex = size - (size / 10); // Integer division for 10%
    for (int i = startIndex; i < size; i++) {
        arrPtr[i] = rand() % 1024; // Replace with random value
    }

    return arrPtr;
}
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size + 1; i++) {
        // Search for minimum within unsorted section
        int min = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
        swap(arr[min], arr[i]);
        swaps++;
    }
}
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps++;
        }
        comparisons++;
        arr[j + 1] = key;
    }
}
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, middle + 1, end);
    }
}
void merge(int arr[], int sl, int el, int sr, int er) {
    int* temp = new int[er + 1];
    int i = sl;
    int j;
    int save = sl;

    while (sl <= el && sr <= er) {
        comparisons++;
        if (arr[sl] < arr[sr]) {
            temp[i++] = arr[sl++];
        }
        else {
            temp[i++] = arr[sr++];
        }
    }

    while (sl <= el) {
        temp[i++] = arr[sl++];
    }
    while (sr <= er) {
        temp[i++] = arr[sr++];
    }

    for (j = save; j <= er; j++) {
        arr[j] = temp[j];
        swaps++;
    }

    delete[] temp;
}
void heapSort(int arr[], int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(arr, i, size - 1);
    }
    
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swaps++;
        heapify(arr, 0, i - 1);
    }
}
void heapify(int arr[], int first, int last) {
    int max = 2 * first + 1;

    if (max <= last) {
        comparisons++;
        if (max < last && arr[max + 1] > arr[max]) {
            max += 1;
        }
        comparisons++;
        if (arr[max] > arr[first]) {
            swap(arr[max], arr[first]);
            swaps++;
            heapify(arr, max, last);
        }
    }
}
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int position = split(arr, start, end);
        quickSort(arr, start, position - 1);
        quickSort(arr, position + 1, end);
    }
}
int split(int arr[], int first, int last) {
    int pivotPosition = first;
    int pivot = arr[first];

    for (int i = first + 1; i <= last; i++) {
        comparisons++;
        if (arr[i] < pivot) {
            pivotPosition++;
            swap(arr[pivotPosition], arr[i]);
            swaps++;
        }
    }
    swap(arr[pivotPosition], arr[first]);
    swaps++;
    
    return pivotPosition;
}