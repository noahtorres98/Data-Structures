// Serial Number : 56
//
// Author : Noah Torres
// Due Date :
// Programming Assignment Number 6
//
// Spring 2019 - CS 3358 - 252
//
// Instructor: Husain Gholoom.
//
//  Program creates a char array if the size is a positive integer
// Then a function prints the array
// Another function performs a sequential search
// Another function performs a selectoin sort
// Another function perfroms a insertion sort
// The last function performs a quick sort but tends to bug out
// I was not able to finish the last two functions

#include <iostream>
#include<ctime>
#include <chrono>
using namespace std;

void displayBeginning();
bool validate(int num);
void printArray(char array[], int size);
void sequentialSearch(char array[], int size, int count);
void selectionSort(char array[], int size);
void insertionSort(char array[], int size);
void quickSortMiddle(char array[], int left, int right, int size, int count);

int main() {
    int size;
    displayBeginning();
    cout << endl << "Enter the size of the array : ";
    cin >> size;
    if (validate(size)){
        cout << endl;
        char charArray[size];
        srand((unsigned)time(0));
        for (int i = 0; i < size; i++){
            int num = (rand() % (126 - 33 + 1)) + 33;   //generates random number from ascii chars 33-126
            charArray[i] = num;
        }
        int firstNum = charArray[0];        // firs num of array is stored
        int lastNum = charArray[size - 1];  //last num of array is stored
        cout << "Array elements are : ";
        printArray(charArray,size);
        cout << endl;
        std::chrono::time_point<std::chrono::system_clock> start, end;
        
        start = std::chrono::system_clock::now();
        cout << endl << "Sequential Search" << endl << endl;
        cout << "Searching for 80" << endl << endl;
        
        sequentialSearch(charArray, size, 0);
        
        
        end = std::chrono::system_clock::now();
        
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::time_t start_time = std::chrono::system_clock::to_time_t(start);
        
        std::cout << "Start Time : " << std::ctime(&start_time);
        std::cout << "End Time : " << std::ctime(&end_time);
        
        cout << "Actual CPU Clock Time : ";
        std::cout << elapsed_seconds.count() << "s\n";
        
        
        
        selectionSort(charArray, size);
        insertionSort(charArray, size);
        cout << endl << "Quick Sort - Next to the middle element as a pivot : " << endl << endl;
        
        std::chrono::time_point<std::chrono::system_clock> start2, end2;
        
        start2 = std::chrono::system_clock::now();       //setes up the timer function
        quickSortMiddle(charArray, firstNum, lastNum, size, 0);
        end2 = std::chrono::system_clock::now();     //end of the timer
        
        std::chrono::duration<double> elapsed_seconds2 = end2 - start2;    //subtracts end - start time to find elapsed time
        std::time_t end_time2 = std::chrono::system_clock::to_time_t(end2);       // stores end to end time and casts time
        std::time_t start_time2 = std::chrono::system_clock::to_time_t(start2);   //stores start to start time and casts as time
        
        std::cout << "Start Time : " << std::ctime(&start_time2);
        std::cout << "End Time : " << std::ctime(&end_time2);
        
        cout << "Actual CPU Clock Time : ";
        std::cout << elapsed_seconds2.count() << "s\n";
        
    }
    else{
        cout << " *** Error - Invalid input - Size must be > 0 ***" << endl;
    }
    cout << endl <<"Benchmark Algorithm Implemented by : Noah, Torres \n4 - 24 - 2019" << endl;
    return 0;
}

void printArray(char array[], int size){
    for (int i = 0; i < 20; i++){
        if (i == size){
            break;
        }
        cout << array[i] << " ";
    }
    cout << endl;
}
void sequentialSearch(char array[], int size, int count){
    int num = 0;
    char tempArray[size];
    bool flag = false;
    for (int b = 0; b < size; b++){ //creates temp array
        tempArray[b] = array[b];
    }
    
    if (count > size){
        num++;
        if (array[count] == 80){
            flag = true;
        }
        else{
            sequentialSearch(array, size, count + 1);
        }
    }
    
    if (flag){
        cout << "Char 80 was found" << endl;
    }
    else
        cout << "80 was not found" << endl;
    cout << "Total Number of Comparisons : " << size << endl;
    cout << "Array Elements : ";
    printArray(tempArray, size);
}

void selectionSort(char array[], int size){
    char tempArray[size];
    for (int b = 0; b < size; b++){ // creates temp array
        tempArray[b] = array[b];
    }
    cout << endl << endl << "Selection Sort : " << endl << endl;
    int i = 0; // start at 0
    int min;
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    start = std::chrono::system_clock::now();
    
    for (i; i < size; i++){ // selectoin sort algorithm
        min = i;
        for (int j = i + 1; j < size; j++){
            if (tempArray[j] < tempArray[min]){
                min = j;        //stores smallest element which is j
            }
        }
        if (i != min){
            int swap = tempArray[i];    // element to swap
            tempArray[i] = tempArray[min];     //sets element at i to min
            tempArray[min] = swap;  //sets min to elemet to swap
        }
    }
    
    end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    
    std::cout << "Start Time : " << std::ctime(&start_time);
    std::cout << "End Time : " << std::ctime(&end_time);
    
    cout << "Actual CPU Clock Time : ";
    std::cout << elapsed_seconds.count() << "s\n";
    
    cout << "Total number of Swaps : " << min << endl;
    cout << "Sorted Elements : ";
    printArray(tempArray, size);
}

void insertionSort(char array[], int size){
    char tempArray[size];
    for (int b = 0; b < size; b++){ // creates temp array
        tempArray[b] = array[b];
    }
    cout << endl << endl << "Insertion Sort" << endl << endl;
    int j;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    int count = 0;      //stars at zero
    start = std::chrono::system_clock::now();
    for (int i = 1; i < size - 1; i++){ // insertion sort algorthim
        int value = tempArray[i];   // sets value to idex of for loop
        j = i - 1;  // j set to index - 1
        while (j >= 0 && tempArray[j] > value){
            tempArray[j + 1] = tempArray[j];    //element in j+1 = set to element behind it
            j = j - 1;  //decrements j
            count++;
        }
        tempArray[j + 1] = value; // temp array at the element in front of j is set to value
    }
    end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    
    std::cout << "Start Time : " << std::ctime(&start_time);
    std::cout << "End Time : " << std::ctime(&end_time);
    
    cout << "Actual CPU Clock Time : ";
    std::cout << elapsed_seconds.count() << "s\n";
    cout << "Total Number of Comparisons : " << count << endl;
    cout << "Sorted Elements : ";
    printArray(tempArray, size);
}

void quickSortMiddle(char array[], int left, int right, int size, int count){
    char tempArray[size];
    for (int b = 0; b < size; b++){ // creates temp array
        tempArray[b] = array[b];
    }
    
    try{
        
        int i = left, j = right; // sets i and j to first and last num respectively
        int tmp;
        int pivot = tempArray[(left + right) / 2];  // sets pivot to middle number
        
        while (i <= j){
            while (tempArray[i] < pivot)
                i++;
            
            while (tempArray[j] > pivot)
                j--;
            
            if (i <= j){
                tmp = tempArray[i];     // sets tmp to temp array and index
                tempArray[i] = tempArray[j];    // tmp array at j is set to i
                tempArray[j] = tmp; // swaps tmp to j
                i++;
                j--;
            }
        };
        
        if (left < j)
            quickSortMiddle(tempArray, left, j, size, count + 1);
        
        if (i < right)
            quickSortMiddle(tempArray, i, right, size, count + 1);
        
        
        printArray(tempArray, size);
        cout << "Total Nmber of Recursive Calls : " << count << endl;
    }catch(...){
        cout << "you encountered one a bug that i did not quite figure out" << endl;
    }
}

void displayBeginning(){
    cout << "Searching / Sorting Benchmark" << endl << endl;
    cout << "Using a random number generator, we are creating an array of n\nelements of type char then performing the following :" << endl << endl;
    cout << "  1. Displaying the first 20 numbers." << endl << endl;
    cout << "  2. Using recursion, Searching for an element in the array using\n     sequential search and at the end displaying number of comparisons\n     it makes." << endl << endl;
    cout << "  3. Sort the original array using Selection Sort and at the end\n     display the number of swaps it makes. " << endl << endl;
    cout << "  4. Sorting the array using insertion Sort and at the end\n     displaying the number of comparisons it makes. " << endl << endl;
    cout << "  5. Sorting the array using Quick Sort and at the end displaying\n     the number of recursion calls it makes. Using the next to the\n     middle value as a pivot value." << endl << endl;
    cout << "  6. Sorting the same array using Quick Sort and at the end\n     displaying the number of recursion calls it makes. Using the \n     first value as a pivot value." << endl << endl;
    cout << "  7. Sorting the same array using Quick Sort and at the end\n     displaying the number of recursion calls it makes. Using the \n     last value as a pivot value." << endl << endl;
    cout << "  8. For each of the preceding steps ( 2 thru 7 ), calculating and\n     printing the CPU time before each step starts and after each\n     completed step then calculating actual CPU time for the\n     completion of each step." << endl;
}

bool validate(int num){
    if (num > 0){
        return true;
    }
    else
        return false;
}
