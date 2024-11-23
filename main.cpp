#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void printArray(int[], int);
void initArray1(int[], int); // a. Completely random
void initArray2(int[], int); // b. Almost sorted in ascending order
void initArray3(int[], int); // c. Almost reversed similar to b.
void initArray4(int[], int); // d. Sorted except last 10%
void selectionSort(int[], int);
void insertionSort(int[], int);
void heapSort(int[], int);
void mergeSort(int[], int);
void quickSort(int[], int);


int main(int argc, char* argv[]) {
    srand(time(NULL)); // Initialize random seed
    const int SIZE = 30;
    int myArray[SIZE]; // Initializes array elements to 0

    initArray1(myArray, SIZE);
    printArray(myArray, SIZE);


    return 0;
}


void printArray(int arr[], int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << i + 1 << ": " << arr[i] << endl;
    }
}
void initArray1(int arr[], int size) {
    for (unsigned int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
    }
}
void initArray2(int arr[], int size) {
    int next = 0;

    for (unsigned int i = 0; i < size; i++) { // Fill array w/ randomly incremented numbers
        next = next + ((rand() % 5) + 1); // Not incrementing too much
        arr[i] = next;
    }

    for (unsigned int i = 0; i < size * .1; i++) { // Make 10% random
        arr[rand() % size + 1] = rand() % 1024; // Make random element random
    }
}
void initArray3(int arr[], int size) {
    int next = 0;

    for (int i = size - 1; i >= 0; i--) { // Fill array w/ randomly incremented numbers
        next = next + ((rand() % 5) + 1); // Not incrementing too much
        arr[i] = next;
    }

    for (unsigned int i = 0; i < size * .1; i++) {
        arr[rand() % size + 1] = rand() % 1024;
    }
}
void initArray4(int arr[], int size) {
    int next = 0;

    for (unsigned int i = 0; i < size; i++) {
        next = next + ((rand() % 5) + 1);
        arr[i] = next;
    }

    for (unsigned int i = size - (size * .1); i < size; i++) {
        arr[i] = rand() % 1024;
    }
}