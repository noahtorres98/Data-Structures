// Author : Noah Torres //
// Serial number : 56 //
// Group Number: n/a//
// Due Date :   3/6/19
// Programming Assignment Number 3
// Spring 2019 - CS 3358 - Section Number //
// Instructor: Husain Gholoom. //
//
//
//
//
//
//
// user assigns value to instance of class int
// menu is displayed and user enters a char in order to call a function
// output of function is displayed
// program terminates
//
//
//  main.cpp
//  asg3
//
//  Created by Noah Torres on 2/25/19.
//  Copyright © 2019 Noah Torres. All rights reserved.
//


void displayMenu();
bool validateAction(char reply);
bool validateNumber(int num);
bool validateYesOrNo(char ch);


#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


class myInt {
private:            // private data
    int number;
public:             //public functions
    myInt(int num);
    void isMultiple();
    void isSumOddEven();
    void squareRoot();
    void primeNumber();
    void perfectNumber();
};

void myInt::isMultiple() {        //prints to the screen mulitiples of 7,11, 13
    int count = -1;   //counts number of multiples
    
    cout << endl << number << " is: " << endl;
    
    if (number == 0){
        cout << "Not a multiple of anything" << endl;
        return;
    }
    
    if (number % 7 == 0){
        cout << "A multiple of 7" << endl;
        count++;
    }
    
    if (number % 11 == 0){
        cout << "A mutltiple of 11" << endl;
        count++;
    }
    
    if (number % 13 == 0){
        cout << "A multiple of 13" << endl;
        count++;
    }
    
    if (count == -1){
        cout << "Not a multiple of anything" << endl;
    }
}

void myInt::isSumOddEven(){
    int num = 0;            //stores digits of number into num
    int tempNumber = number; //creates new var tempNumber which holds value of number
    while (tempNumber){
        num += tempNumber % 10; //put value digit by digit
        tempNumber /= 10;   //shifts value
    }
    
    cout << endl;
    
    if (num % 2 == 0){
        cout << number << " sum of digits is even." << endl;
    }
    else
        cout << number << " sum of digits is odd." << endl;
}

void myInt::squareRoot(){
    double sqRt = sqrt(number); // sqrt funciton
    cout.precision(3);              // formats to two decimal places
    cout << endl << "Square root value of " << number << " is : " << sqRt << endl;
}

void myInt::primeNumber(){
    bool isPrime = true;    //bool val for isPrime
    
    cout << endl;
    
    if (number == 0){
        cout << number << ": is not prime" << endl << endl;
        return;
    }
    
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    }
    
    if (isPrime) {
        cout << number << " : is a prime number." << endl;
    }
    else {
        cout << number << " : is not a prime number." << endl;
    }
    cout << endl;
}

void myInt::perfectNumber() {
    int num = 0;        //hold value of number
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            num = num + i;      //adds i to value of num
        }
    }
    
    if (num == number * 2) {
        cout << number << " : is a perfect number." << endl;
    }
    else {
        cout << number << " : is not a perfect number." << endl;
    }
    
    cout << endl;
}

myInt::myInt(int num) {
    number = num;       //sets num to varbiable number
}

int main() {
    int value;
    
    char reply;     //holds reply to menu choice
    
    bool mainLoop = true;       //controls mainloop of program
    
    cout << "Welcome to my Integer Manipulations Program." << endl << endl;
    
    while (mainLoop == true) {
        
        cout << "Enter positive value for your number" << endl;
        
        cin >> value; // holds value of number
        
        while (validateNumber(value) != true){
            cout << "Value must be positive." << endl << "Enter another value." << endl;
            
            cin >> value;   // if value is invalid program asks again
        }
        
        myInt i(value);       //creates object int with value given
        
        displayMenu();      // displays menu
        
        cout << "Choose an option (enter a char)." << endl;
        
        cin >> reply;
        
        reply = toupper(reply);
        
        while (validateAction(reply) != true){      // checks for valid reply
            cin >> reply;
            reply = toupper(reply);
        }
        
        if (reply == 'A') {
            i.isMultiple();         //calls is multiple function
        }
        
        else if (reply == 'B'){     //calls is sum odd or even function
            i.isSumOddEven();
        }
        
        else if (reply == 'C') {       // calls square root function
            i.squareRoot();
        }
        
        else if (reply == 'D') {       // calls primr number function
            i.primeNumber();
        }
        
        else if (reply == 'E') {        //calls perfect number function
            i.perfectNumber();
        }
        
        else if (reply == 'F') {        //calls all functions
            i.isMultiple();
            i.isSumOddEven();
            i.squareRoot();
            i.primeNumber();
            i.perfectNumber();
        }
        
        else if (reply == 'Z') {    //exits program
            mainLoop = false;
            break;
        }
        
        char action;
        
        cout << "Would you like to re-run the program again" << endl << "Enter Y or N --->  ";
        
        cin >> action;
        
        while (validateYesOrNo(action) != true){        //validates if user enters y or n
            cin >> action;
        }
        
        action = toupper(action);
        
        if (action == 'N'){
            mainLoop = false;       //mainloop is false so program will end
        }
        cout << endl;
    }
    
    
    cout << "This program is implemented by Noah Torres." << endl << "March - 2019" << endl << endl;
    return 0;
}

void displayMenu() {
    cout << "Menu" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "  A. Is it a multiple of 7, 11, or 13." << endl;
    cout << "  B. Is the sum of its digits odd or even." << endl;
    cout << "  C. What is the square root value." << endl;
    cout << "  D. Is it a prime number." << endl;
    cout << "  E. Is it a perfect number (The sum of the factors\n     of a perfect number is equal to the number itself\n     for example : 1 + 2 + 4 + 7 + 14 = 28 , so 28 is\n     a perfect number " << endl;
    cout << "  F. All of the above." << endl;
    cout << "  Z. Exit" << endl;
    cout << "-----------------------------------------------------------" << endl << endl;
    
}

bool validateAction(char reply){
    reply = toupper(reply);
    if (reply == 'A' || reply == 'B' || reply == 'C' || reply == 'D' || reply == 'E' || reply == 'F' || reply == 'Z') {
        return true;
    }
    else
        cout << "Invalid option. Enter another char." << endl;
    return false;
}

bool validateNumber(int num){
    if (num < 0){
        return false;
    }
    else
        return true;
}

bool validateYesOrNo(char ch){
    ch = toupper(ch);
    if (ch == 'Y' || ch == 'N'){
        return true;
    }
    else
        cout << endl << "Error *** Invalid choice - Must enter y|Y or n|N" << endl << endl;
        cout << "Would you like to re-run the program again" << endl << "Enter Y or N --->  ";
        return false;
}
