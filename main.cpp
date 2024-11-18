#include <iostream>
using namespace std;


void printArray(int[], int);
int* selectionSort(int[], int);
int* insertionSort(int[], int);
int* heapSort(int[], int);
int* mergeSort(int[], int);
int* quickSort(int[], int);


int main(int argc, char* argv[]) {
    const int SIZE = 10;
    int myArray[SIZE] = { 1, 4, 5, 1, 34, 60 };

    printArray(myArray, SIZE);

    return 0;
}


void printArray(int arr[], int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << i + 1 << ": " << arr[i] << endl;
    }
}