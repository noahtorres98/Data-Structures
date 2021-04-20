// Serial Number : xxxxxxxxx //
// Author : Noah Torres
// Due Date : 04/08/19
// Programming Assignment Number 5 //
// Spring 2019 - CS 3358 - 252 //
// Instructor: Husain Gholoom. //
// program takes int to create an array with randmon elements ranging from 10 - 375


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

bool validateSize(int);
void reverse(int array[], int size);
void squareValue(int target ,int value);
void power(int lastNum, int powerNum);
void prime(int array[], int size, int begin);
using namespace std;

int main() {
    cout << "*** Welcome to My Recursion APP ***" << endl << endl;
    
    int size;
    cout << "Enter The array size. ( Must be >= 5 ) ->  ";
    cin >> size;
    if (validateSize(size)){
        int numArray[size];
        int firstNum, lastNum;
        srand((unsigned)time(0));
        for (int i = 0; i < size; i++){
            int num = (rand() % (375 - 10 + 1)) + 10;       //genereates random number from 10 - 375
            numArray[i] = num;      //appends num to numArray
        }
        firstNum = numArray[0];     //sets lastNum to first number in numArray
        lastNum = numArray[size-1]; //sets lastNum to last number in numArray
        cout << endl << "The generated array is : ";
        for (int i = 0; i < size; i++){
            cout << numArray[i] << " ";
        }
        cout << endl << endl << "Reversed Array is : ";
        reverse(numArray, size);
        
        cout << endl << endl << "Table of square values 1 - " << firstNum << endl << endl;
        cout << "N     N Sqaured" << endl;
        squareValue(firstNum, 1);
        
        cout << endl << "Power function:" << endl;
        cout << lastNum << " raised to the 2nd power is: ";
        power(lastNum, 2);
        
        cout << endl << endl << "Is It Prime :" << endl << endl;
        prime(numArray, size, 0);
    }
    else{
        cout << endl <<"Invalid arrays size. Size must >= 5." << endl;
    }
    
    cout << endl;
    cout << "Noah Torres - Tweak Programming Director \nApril 2019" << endl;
    return 0;
}

void reverse(int array[], int size){
    if (size > 0){
        reverse(array + 1, size - 1);
        cout << array[0] << " ";
    }
}

void squareValue(int target, int value){
    if (value <= target){
        cout << value << "     " << value * value << endl;
        squareValue(target, value + 1);
    }
}

void power(int lastNum, int powerNum){
    if (powerNum < 3){
        cout << lastNum * lastNum;
        power(lastNum, powerNum + 1);
    }
}

void prime(int array[], int size, int begin){
    if (begin < size){
        int i;
        bool isPrime = true;        //initializes isPrime to true
        for (i = 2; i <= array[begin] / 2; ++i){
            if (array[begin] % i == 0){
                isPrime = false;    //sets isPrime to false
                break;
            }
        }
        if (isPrime){
            cout << "The number " << array[begin] << " is Prime" << endl;
            prime(array, size, begin + 1);
        }
        else{
            cout << "The number " << array[begin] << " is Not Prime" << endl;
            prime(array, size, begin + 1);
        }
    }
}

bool validateSize(int size){
    if (size < 5){
        return false;
    }
    else
        return true;
}
