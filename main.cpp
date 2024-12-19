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
void mergeSort(int[], int, int);
void merge(int[], int, int, int, int);
void heapSort(int[], int);
void heapify(int[], int, int);
void quickSort(int[], int, int);
int split(int[], int, int);


int main(int argc, char* argv[]) {
    srand(time(NULL)); // Initialize random seed
    const int SIZE = 30;
    int myArray[SIZE]; // Initializes array elements to 0

    initArray1(myArray, SIZE);
    printArray(myArray, SIZE);
 // selectionSort(myArray, SIZE);
 // insertionSort(myArray, SIZE);
 // mergeSort(myArray, 0, SIZE);
 // heapSort(myArray, SIZE);
    quickSort(myArray, 0, SIZE);
    cout << "\nAfter sort\n" << endl;
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
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size + 1; i++) {

        // Search for minimum within unsorted section
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }

        }
        
        // Swap
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
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
        // Comparisons
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
    }

    delete[] temp;
}
void heapSort(int arr[], int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(arr, i, size - 1);
    }
    
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        // Swap
        heapify(arr, 0, i - 1);
    }
}
void heapify(int arr[], int first, int last) {
    int max = 2 * first + 1;

    if (max <= last) {
        // Comparison
        if (max < last && arr[max + 1] > arr[max]) {
            // Comparison
            max += 1;
        }
        if (arr[max] > arr[first]) {
            // Comparison
            // Swap
            swap(arr[max], arr[first]);
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
        // Comparison
        if (arr[i] < pivot) {
            pivotPosition++;
            swap(arr[pivotPosition], arr[i]);
            // Swap
        }
    }
    swap(arr[pivotPosition], arr[first]);
    // Swap
    
    return pivotPosition;
}