#ifndef FUNCTIONS_H
#define FUNCTIONS_H


// GLOBAL COUNTERS DECLARATIONS
extern int swaps;
extern int comparisons;

// Function declarations
void printArray(int[], int);
int* initArray1(int); // a. Completely random
int* initArray2(int); // b. Almost sorted in ascending order
int* initArray3(int); // c. Almost reversed similar to b.
int* initArray4(int); // d. Sorted except last 10%
void selectionSort(int[], int);
void insertionSort(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int, int);
void heapSort(int[], int);
void heapify(int[], int, int);
void quickSort(int[], int, int);
int split(int[], int, int);


#endif