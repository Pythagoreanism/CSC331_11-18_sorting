#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


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

int swaps = 0;
int comparisons = 0;

int main(int argc, char* argv[]) {
    srand(time(NULL)); // Initialize random seed
    const int SIZE_SMALL = 128;
    const int SIZE_LARGE = 1024;
    int size = 0;
    int* p = nullptr; // To hold array during runtime
    char userOpt = '\0'; // User option
    const char QUIT_OPT = 'Q'; // Sentinel

    do {
        userOpt = '\0'; // Reset

        cout << "\n**********MENU**********"   << endl;
        cout << "1: Create an array"           << endl;
        cout << "2: Print your array"          << endl;
        cout << "3: Test a sorting algorithm"  << endl;
        cout << "Q: Quit Program"              << endl;
        cout << "Choose option: ";
        cin >> userOpt;

        switch (userOpt) {
            case '1': // Create an array menu
                do {
                    cout << "\n*****Create an Array*****"                           << endl;
                    cout << "S: Set size of array to 128 elements"                  << endl;
                    cout << "L: Set size of array to 1024 elements"                 << endl;
                    cout << "Current array size: " << size                          << endl;
                    cout << "----------------------------------------------------"  << endl;
                    cout << "1: Initialize array completely random"                 << endl;
                    cout << "2: Initialize array almost sorted in ascending order"  << endl;
                    cout << "3: Initialize array almost sorted in descending order" << endl;
                    cout << "4: Initialize array sorted except last 10%"            << endl;
                    cout << "Q: Quit Create an Array Menu"                          << endl;
                    cout << "Choose option: ";
                    cin >> userOpt;

                    switch (userOpt) {
                        case 'S':
                            size = SIZE_SMALL;
                            break;
                            
                        case 'L':
                            size = SIZE_LARGE;
                            break;

                        case '1':
                            if (size != 0) {
                                //delete[] p;
                                p = initArray1(size);
                                cout << "Array initialized successfully:" << endl;
                                printArray(p, size);
                            }
                            else {
                                cout << "Select a size first!" << endl;
                            }
                            break;

                        case '2':
                            if (size != 0) {
                                //delete[] p;
                                p = initArray2(size);
                                cout << "Array initialized successfully:" << endl;
                                printArray(p, size);
                            }
                            else {
                                cout << "Select a size first!" << endl;
                            }
                            break;

                        case '3':
                            if (size != 0) {
                                //delete[] p;
                                p = initArray3(size);
                                cout << "Array initialized successfully:" << endl;
                                printArray(p, size);
                            }
                            else {
                                cout << "Select a size first!" << endl;
                            }
                            break;

                        case '4':
                            if (size != 0) {
                                //delete[] p;
                                p = initArray4(size);
                                cout << "Array initialized successfully:" << endl;
                                printArray(p, size);
                            }
                            else {
                                cout << "Select a size first!" << endl;
                            }
                            break;

                        case 'Q':
                            cout << "Exiting Array Menu" << endl;
                            break;

                        default:
                            cerr << "ERROR: Invalid input in  Create an Array Menu" << endl;
                            break;

                    }
                } while (userOpt != QUIT_OPT);
                userOpt = '\0'; // Reset user option after exiting sub-menu
                break;
            
            case '2': // Print array
                if (p == nullptr) {
                    cout << "Create an array first!" << endl;
                }
                else {
                    printArray(p, size);
                }
                break;

            case '3': // Testing algorithm menu
                do {
                    cout << "\n****Test Sorting Algorithm****" << endl;
                    cout << "1: Test Selection Sort"           << endl;
                    cout << "2: Test Insertion Sort"           << endl;
                    cout << "3: Test Merge Sort"               << endl;
                    cout << "4: Test Heap Sort"                << endl;
                    cout << "5: Test Quick Sort"               << endl;
                    cout << "Q: Quit Sorting Menu"             << endl;
                    cout << "Choose option: ";
                    cin >> userOpt;

                    switch (userOpt) {
                        case '1': // Selection Sort
                            if (p != nullptr) {
                                selectionSort(p, size);
                                cout << "Array succesfully sorted with Selection Sort" << endl;
                                cout << "\nArray after sort" << endl;
                                printArray(p, size);
                                cout << "Number of swaps: " << swaps << endl;
                                cout << "Number of comparisons: " << comparisons << endl;
                                swaps = 0;
                                comparisons = 0;
                            }
                            else {
                                cout << "Create an array first!" << endl;
                            }
                            break;
                        
                        case '2': // Insertion Sort
                            if (p != nullptr) {
                                insertionSort(p, size);
                                cout << "Array succesfully sorted with Insertion Sort" << endl;
                                cout << "\nArray after sort" << endl;
                                printArray(p, size);
                                cout << "Number of swaps: " << swaps << endl;
                                cout << "Number of comparisons: " << comparisons << endl;
                                swaps = 0;
                                comparisons = 0;
                            }
                            else {
                                cout << "Create an array first!" << endl;
                            }
                            break;
                        
                        case '3': // Merge sort
                            if (p != nullptr) {
                                mergeSort(p, 0, size - 1);
                                cout << "Array succesfully sorted with Merge Sort" << endl;
                                cout << "\nArray after sort" << endl;
                                printArray(p, size);
                                cout << "Number of swaps: " << swaps << endl;
                                cout << "Number of comparisons: " << comparisons << endl;
                                swaps = 0;
                                comparisons = 0;
                            }
                            else {
                                cout << "Create an array first!" << endl;
                            }
                            break;
                        
                        case '4': // Heap sort
                            if (p != nullptr) {
                                heapSort(p, size);
                                cout << "Array succesfully sorted with Heap Sort" << endl;
                                cout << "\nArray after sort" << endl;
                                printArray(p, size);
                                cout << "Number of swaps: " << swaps << endl;
                                cout << "Number of comparisons: " << comparisons << endl;
                                swaps = 0;
                                comparisons = 0;
                            }
                            else {
                                cout << "Create an array first!" << endl;
                            }
                            break;
                        
                        case '5': // Quick sort
                            if (p != nullptr) {
                                quickSort(p, 0, size -1);
                                cout << "Array succesfully sorted with Quick Sort" << endl;
                                cout << "\nArray after sort" << endl;
                                printArray(p, size);
                                cout << "Number of swaps: " << swaps << endl;
                                cout << "Number of comparisons: " << comparisons << endl;
                                swaps = 0;
                                comparisons = 0;
                            }
                            else {
                                cout << "Create an array first!" << endl;
                            }
                            break;
                        
                        case 'Q':
                            cout << "Exiting Testing Algorithm Menu" << endl;
                            break;

                        default:
                            cerr << "ERROR: Invalid input in Create an Sorting Menu" << endl;
                            break;

                    }
                } while (userOpt != QUIT_OPT);
                userOpt = '\0'; // Reset user option after exiting sub-menu
                break;
                
            case 'Q': // Exit program
                cout << "Exiting Main Menu..." << endl;
                break;

            default:
                cerr << "ERROR: Invalid input in Main Menu" << endl;
                break;

        }

    } while (userOpt != QUIT_OPT);
    
    cout << "Exiting program..." << endl;
    delete[] p;
    p = nullptr;


    return 0;
}


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