#include <iostream>
#include <stack>
using namespace std;

// --------------------------------------------------------------
// --------------------------------------------------------------
// the 'Node' and 'SList' classes are fixed
// please do not modify them (except adding new member functions)
// please add your implementation of the member functions
// the 'Enumeration' function has been implemented for you
// for the 'Insert' function, you probably want to dynamically allocate memory for a newly inserted node
// --------------------------------------------------------------
// --------------------------------------------------------------

class Node { // "Node" class; each node is a student described by SID

public:

    int SID = 0;
    Node* ptr = NULL;   //pointer to next node?
};


class SList { // singly linked list class; each node is an 'Node' object

public:

    SList() {       //constructor for Singly Linked List
        head = NULL;
    }

    Node* GetList(){    // return head pointer of the list
        return head;
    }

    void Enumerate();  // print all elements in the list, from head to tail, separately by a single space ' '

    int Search(int key) {  // search for 'key' in the list;
        // if found, return index of the node (starting from 0)
        // if not found, return -1
        Node* current = head;  //set current = to the first node in the singly Linked List
        int index = 0;
        while(current != NULL){
            if(current->SID == key){       //current is a pointer, so to get the SID we must use ->
                return index;
            }

            current = current->ptr;   //set current = to the node's pointer to the next node
            index++;
        }
        return -1;

    }
    void Insert(int key) {  // insert key at the end of the list
        //traverse entire list until you reach last node
        if(head == NULL){
            Node* newHead = new Node();
            newHead -> SID = key;
            head = newHead;
            //cout<< "here";
            return;
        }

        Node* current = head;
        while(current->ptr != NULL){
            current = current->ptr;
        }
        Node* next = new Node();    //dynamically allocating memory
        next->SID = key;
        current->ptr = next;

    }

    void Remove(int key) { // if key is in the list, remove it
        // otherwise, do nothing
        Node* temp = head;
        int index = Search(key);
        if(index == -1){    //if key was not found, return and do nothing
            return;
        }
        for(int i = 0; i <= index; i++){
            Node* prev;

            if(index == 0){     //if we are deleting the first node in the list, just remove it and set head to next node
                head = temp->ptr;
                delete temp;
            }

            if(i == index - 1){
                prev = temp;
            }

            else if(i == index){
                //could cause issues if next node is null?
                prev->ptr = temp->ptr;      //reassign the pointer of the Node that comes before the one we are removing
                delete temp;                //delete the targeted node
                return;
            }

            temp = temp->ptr;
        }
    }
    void Reverse() { // reverse the list (tip: you can use stack)
        stack<Node*> stack;          //create the stack
        Node* temp = head;

        while(temp != NULL){        //put all nodes in the stack
            stack.push(temp);
            temp = temp->ptr;
        }

        SList y;
        y.head = stack.top();
        stack.pop();    //make the top node the head and remove it from the stack
        Node* currentYNode = y.head;

        while(stack.empty() == false){
            currentYNode -> ptr = stack.top();
            currentYNode = currentYNode -> ptr;
            stack.pop();
        }
        currentYNode -> ptr = NULL;
        head = y.head;
    }
    // add any other public member functions as you like
    // ......
    // ......

private:
    Node* head;  // head pointer of the list
};

void SList::Enumerate() { // enumeration function, implemented for you

    Node* temp = head;

    while (temp != NULL) {

        cout << temp->SID << ' ';
        temp = temp->ptr;
    }
};

// --------------------------------------------------------------
// --------------------------------------------------------------
// the following merge function is only for your reference
// you don't have to use recursion
// --------------------------------------------------------------
// --------------------------------------------------------------

 //Node* MergeSort(Node* ptr) {  // merge sort (recursive implementation)
    // input head pointer of a singly linked list
    // output head pointer of the sorted linked list


    // Step 1. split the list into two sub-lists
    // ..........
    // ..........
    // assume ptr1 is head of 1st sublist
    // assume ptr2 is head of 2nd sublit


    // Step 2. sort each sublist by calling the MergeSort
    // ptr1 = MergeSort(ptr1);
    // ptr2 = MergeSort(ptr2);


    // Step 3. merge the sorted sublists into a sorted list
    // ......
    // ......
    // you can define a function for that, or implement it directly here


    // step 4. return the head pointer of the sorted list
    // Node* head = ......;
    // return head;
//}


int main()
{
    SList x;
    //cout << "heree";
    int operationChoice, Key2Search, Key2Remove, Key2Insert;

    int InputKey;
    int i = 0, y= 0;
    while (i < 10) {
        cin >> InputKey;
        x.Insert(InputKey);
        i++;
    }

    cin >> operationChoice ;

    if (operationChoice == 1)
    {
        Node* head = x.GetList();
        cout << head->SID;
    }
    else if (operationChoice == 2)
    {
        cin >> Key2Search;
        y = x.Search(Key2Search);
        cout << y;
    }
    else if (operationChoice == 3)
    {
        cin >> Key2Insert;
        x.Insert(Key2Insert);
        x.Enumerate();
    }
    else if (operationChoice == 4)
    {
        cin >> Key2Remove;
        x.Remove(Key2Remove);
        x.Enumerate();
    }
    else if (operationChoice == 5)
    {
        x.Reverse();
        x.Enumerate();
    }
    /*else if (operationChoice == 6)
    {
        Node *sorted_list = MergeSort(x.GetList());

        while (sorted_list != NULL) {

            cout << sorted_list->SID << ' ';

            sorted_list = sorted_list->ptr;
        }
    }
     */
    else
    {
        cout << "Enter a valid choice";
    }
    return 0;

}

