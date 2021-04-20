//
//  author : noah torres
//  serial number : 56
//  group number : n/a
//  due date : 2-2-19
//  Programming Assignment #2
//  Spring 2019 - CS 3358 - 252
//  Instructor : Husain Gholoom
//
//
//  The program allows the user to either encrypt or decrypt
//  The user then enters a key
//  The encrypted/decrypted message is diplayed
//
//
//
//
//  Created by Noah Torres on 2/13/19.
//  Copyright © 2019 Noah Torres. All rights reserved.

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

string decryptFunction(string message);
string encryptFunction(string message);
string toUpper(string message);
bool validateAction(string reply);
bool validateKey(int key);
void displayVector(vector<vector<char> > matrix);

int main() {
    
    cout << "Welcome to Cryptography" << endl << endl;
    
    bool mainLoop = true; // controls main loop
    
    while (mainLoop != false){
        string reply;
        
        cout << "What would you like to do to a message? (encrypt, decrypt, exit)" << endl;
        
        cout << "Enter your choice : ";
        
        cin >> reply;
        
        reply = toUpper(reply); // capitalizes reply
        
        bool validAction = validateAction(reply);
        
        if (validAction == false){
            continue;
        }
        
        if (reply == "ENCRYPT"){
            string message; // will hold message user inputs
            
            string encryptedMessage; // will hold encrypted message that is returned
            
            cout << endl << "Enter your message:" << endl;
            
            cin.ignore();
            
            getline(cin, message); // reads whole line
            
            encryptedMessage = encryptFunction(message); // calls encryption method
            
            if (encryptedMessage == ""){
                continue;
            }
            
            cout << endl << "Your translated text is:" << endl;
            
            cout << encryptedMessage << endl << endl;
        }
        
        else if (reply == "DECRYPT"){
            string message; // will hold message user inputs
            
            string decryptedMessage;  // will hold decrypted message that is returned
            
            cout << endl <<"Enter your message:" << endl;
            
            cin.ignore();
            
            getline(cin, message); //reads whole line
            
            decryptedMessage = decryptFunction(message); // calls decryption method
            
            if (decryptedMessage == ""){
                continue;
            }
            
            cout << endl << "Your translated text is:" << endl;
            
            cout << decryptedMessage << endl << endl;
        }
        
        else {
            mainLoop = false;
        }
    }
    
    cout << endl << "Noah Torres Security Systems" << endl;
    cout << "2-25-2019" << endl;
    
    return 0;
}

string encryptFunction(string message){
    int key;    //int val for key
    
    string encryptedMessage; // empty string
    
    vector <char> messageVector; // empty vector that will hold message
    
    message = toUpper(message); // capitalizes message
    
    for (int i = 0; i < message.length(); i++){ // populates vector with message
        messageVector.push_back(message.at(i));
    }
    
    cout << "Enter the key number (1-35)" << endl;
    
    cin >> key;
    
    bool validKey = validateKey(key); //determines if key is valid
    
    if (validKey == false){
        return "";
    }
    
    vector <char> vec; // initializes vector
    
    //puts all capital letters in vector
    for (int i = 65; i < 91; i++){
        char asciiChar = char(i);
        vec.push_back(asciiChar);
    }
    
    //puts num 0-9 in vector
    for (int i = 48; i < 58; i++){
        char asciiChar = char(i);
        vec.push_back(asciiChar);
    }
    
    //creates 2D vector
    vector< vector<char> > TwoDVector(2, vec);
    
    //changes 2nd row of vector by key
    for (int i = 1; i < 2; i++){
        for (int j = 0; j < 36; j++){
            TwoDVector[i][j] = vec[j + key];
        }
    }
    
    //finishes creating matrix
    int count = 0;
    
    for (int i = 1; i < 2; i++){
        for (int j = 36 - key; j < 36; j++){
            TwoDVector[i][j] = vec[count];
            count++;
        }
    }
    
    //prints matrix
    //displayVector(TwoDVector);
    
    int index = 0; //index used for message
    
    //encryption algorithm
    while (index < messageVector.size()){
        char messageChar = char(messageVector[index]); // gets ascii value of char
        for (int j = 0; j < 36; j++){
            if (isspace(messageChar)){ // tests for spaces and includes them
                encryptedMessage += ' ';
                index++;
                break;
            }
            else if (messageChar == TwoDVector[0][j]){ // appends encrypted row to encrypted message
                encryptedMessage += TwoDVector[1][j];
                index++;
                break;
            }
        }
    }
    
    //encryptedMessage = toLower(encryptedMessage); // lowercase encrypted message
    
    return encryptedMessage;
}

string decryptFunction(string message){
    int key; //int val for key
    
    string decryptedMessage; // empty string
    
    vector <char> vectorMessage; // empty vector
    
    message = toUpper(message); // capitalizes message
    
    for (int i = 0; i < message.length(); i++){ // populates vector with message
        vectorMessage.push_back(message.at(i));
    }
    
    cout << "Enter the key number (1-35)" << endl;
    
    cin >> key;
    
    bool validKey = validateKey(key);
    
    if (validKey == false){
        return "";
    }
    
    vector <char> vec; // initializes vector
    
    //pupulates uppercase alphabet
    for (int i = 65; i < 91; i++){
        char asciiChar = char(i);
        vec.push_back(asciiChar);
    }
    
    //poulates numbers 0-9
    for (int i = 48; i < 58; i++){
        char asciiChar = char(i);
        vec.push_back(asciiChar);
    }
    
    //creates 2D vector
    vector< vector<char> > TwoDVector(2, vec);
    
    //changes 2 row by key
    for (int i = 1; i < 2; i++){
        for (int j = 0; j < 36; j++){
            TwoDVector[i][j] = vec[j + key];
        }
    }
    
    //finishes row 2
    int count = 0;
    
    for (int i = 1; i < 2; i++){
        for (int j = 36 - key; j < 36; j++){
            TwoDVector[i][j] = vec[count];
            count++;
        }
    }
    
    //displayVector(TwoDVector); // displays 2d vector
    
    //decryption algorithm
    int index = 0;
    
    while (index < vectorMessage.size()){
        char messageChar = char(vectorMessage[index]); // gets ascii value of char
        for (int j = 0; j < 36; j++){
            if (isspace(messageChar)){ //tests for spaces and includes them
                decryptedMessage += ' ';
                index++;
                break;
            }
            else if (messageChar == TwoDVector[1][j]){
                decryptedMessage += TwoDVector[0][j]; // appends decrypted row to encrypted message
                index++;
                break;
            }
        }
    }
    
    //decryptedMessage = toLower(decryptedMessage); // lowercase decrypted message
    
    return decryptedMessage;
}


string toUpper(string message){
    string upper;
    for (int i = 0; i < message.length(); i++){
        if (message.at(i) >= 97 && message.at(i) <= 122){
            upper += message.at(i) - 32;
        }
        else
            upper += message.at(i);
    }
    return upper;
}

void displayVector(vector<vector<char> > matrix){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 36; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool validateAction(string reply){
    if (reply == "DECRYPT" || reply == "ENCRYPT" || reply == "EXIT"){
        return true;
    }
    else
        cout << "Invalid action" << endl << endl;
    return false;
}

bool validateKey(int key){
    if (key > 35 || key < 0){
        cout << endl << "Invalid Key Number" << endl << endl;
        return false;
    }
    else
        return true;
}
