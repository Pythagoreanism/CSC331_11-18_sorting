#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void printArray(int[], int);
void initArray(int[], int);
int* selectionSort(int[], int);
int* insertionSort(int[], int);
int* heapSort(int[], int);
int* mergeSort(int[], int);
int* quickSort(int[], int);


int main(int argc, char* argv[]) {
    srand(time(NULL)); // Initialize random seed

    const int SIZE = 10;
    int myArray[SIZE]; // Initializes array elements to 0

    initArray(myArray, SIZE);
    printArray(myArray, SIZE);

    return 0;
}


void printArray(int arr[], int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << i + 1 << ": " << arr[i] << endl;
    }
}

void initArray(int arr[], int size) {
    for (unsigned int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
    }
}