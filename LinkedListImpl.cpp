// Author / s : Noah Torres
// Roster Number / s : 56
// Group Number : n/a
// Programming Assignment Number 4 //
// Spring 2019 - CS 3358 - 252 //
// Due Date : 03/27/19
// Instructor: Husain Gholoom. //
// Program deals with linked lists
// Run the program it creates 4 lists
// list_1 & list _2 are created
// list_3 = list_1 + list_2
// list_4 is list_3 with duplicate values removed
// displays list after each manipulation
// displays number of elements






#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <list>

using namespace std;

class NumberList{
    
private:
    struct ListNode // the node data type
    {
        int value; // data
        ListNode *next; // ptr to next node
        
    };//end ListNode
    
    ListNode *head; //the list head
    
public:
    NumberList();
    
    void appendNode(int);
    void deleteDup();
    void displayList();
    void insertAtBeginning(int);
    int numElements();
    void deleteBeg();
    void deleteEnd();
    void reverse();
    
};//end NumberList

NumberList::NumberList(){
    head = NULL;
}//end NumberList

void NumberList::appendNode(int num){
    
    ListNode *newNode; //to point to the new mode
    
    //Create a new node and store the date in it
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    
    //if empty, make head point to new node
    if(!head)
        head = newNode;
    else {
        ListNode *nodePtr; //to move through the list
        nodePtr = head; //initialize to start of list
        
        //traverse list to find last node
        while (nodePtr->next){ //it's not last
            nodePtr = nodePtr->next; //make it pt to next
        }//end while
        
        //now nodePtr pts to last node
        //make last node point to newNode
        nodePtr->next = newNode;
        
    }//end else
    
    
}//end appendNode


void NumberList::deleteDup(){
    ListNode *ptr1, *ptr2, *dup;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;                            //sets ptr1 to ptr2
        while (ptr2->next != NULL) {
            if (ptr1->value == ptr2->next->value){
                dup = ptr2->next;               //sets dup to ptr2 link
                ptr2->next = ptr2->next->next;  //sets ptr2 link to the next link
                delete(dup);
            }
            else{
                ptr2 = ptr2->next;      //sets ptr2 to ptr2 link
            }
        }
        ptr1 = ptr1->next;      //sets sptr1 to ptr1 link
    }
}

void NumberList::displayList(){
    
    ListNode *nodePtr; //ptr to traverse the list
    
    //start nodePtr at the head of the list
    nodePtr = head;
    
    //while nodePtr pts to something (not NULL), continue
    while (nodePtr){
        
        //Display the value in the current node
        cout<<nodePtr->value<<" ";
        
        //move to the next node
        nodePtr = nodePtr->next;
        
    }//end while
    
    cout << endl;
    
    
}//end displayList

void NumberList::insertAtBeginning(int num){
    ListNode *nodePtr;
    
    nodePtr = (struct ListNode *)malloc(sizeof(nodePtr));
    
    if (nodePtr == NULL){
        cout << "cant";
    }
    else{
        nodePtr->value = num;   //sets nodePtr value to value given
        nodePtr->next = head;   //sets nodePtr link to first position
        head = nodePtr;         //sets head to nodePtr
    }
}

int NumberList::numElements(){
    int count = 0;
    ListNode *nodePtr;
    nodePtr = head;
    while (nodePtr){
        count++;        //increments count
        nodePtr = nodePtr->next; //sets ptr to next link
    }
    return count;
}

void NumberList::deleteBeg(){
    ListNode *nodePtr;
    nodePtr = head;     //sets nodePtr to head
    head = head->next;  //sets head to heads link
    free(nodePtr);
}

void NumberList::deleteEnd(){
    ListNode *nodePtr, *prev;
    nodePtr = head;     //sets nodePtr to head
    while (nodePtr->next != NULL){
        prev = nodePtr;     //sets prev to nodePtr
        nodePtr = nodePtr->next;        //sets nodePtr to nodePtr link
    }
    prev->next = NULL;  //sets prev link to null
    free(nodePtr);
}

void NumberList::reverse(){
    ListNode *current = head;
    ListNode *prev = NULL, *next = NULL;
    
    while (current != NULL)
    {
        // Store next
        next = current->next;
        
        // Reverse current node's pointer
        current->next = prev;
        
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}

int main(){
    
    NumberList list_1, list_2, list_3, list_4;
    
    srand((unsigned)time(0));
    
    int random = 0; // initializes random variable
    
    for(int i = 0; i < 15; i++){
        random = rand()%((25 - 0) + 1); //sets random to be inclusive 0-25
        list_1.appendNode(random);      //creats list
        list_3.appendNode(random);
        list_4.appendNode(random);
        
        
    }//end for
    
    for(int i = 0; i < 15; i++){
        
        random = rand()%((25 - 0) + 1);   //sets random to be inclusive 0-25
        list_2.appendNode(random);        //creates list
        list_3.appendNode(random);
        list_4.appendNode(random);
        
    }//end for
    
    cout << "Welcome to my Singly LL Program" << endl;
    
    cout<<"List 1:\n";
    list_1.displayList();
    
    cout<<endl;
    
    cout<<"\nList 2:\n";
    list_2.displayList();
    
    cout<<endl;
    
    cout<<"\nList 3: (list 1 + list 2)\n";
    list_3.displayList();
    
    cout << endl;
    
    cout << "List 4: (no duplicates)" << endl;
    list_4.deleteDup();
    list_4.displayList();
    
    
    cout << endl;
    
    list_4.appendNode(88);
    list_4.appendNode(99);
    
    list_4.insertAtBeginning(200);
    list_4.insertAtBeginning(100);
    
    cout << "List 4 with insertions: " << endl;
    list_4.displayList();
    
    int numElem = list_4.numElements();     //num elements function called
    cout << endl << "List 4 has " << numElem << " elements" << endl << endl;
    
    list_4.deleteBeg();
    list_4.deleteEnd();
    
    
    cout << "Deleted first and last element: " << endl;
    list_4.displayList();
    
    cout << endl << "List 4 backwards: " << endl;
    list_4.reverse();
    list_4.displayList();
    
    cout << endl << "This Simple LL program is implemented by :\nNoah Torres - March 27th, 2019" << endl;
    return 0;
    
}//end main
