#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "functions.h"
using namespace std;


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
