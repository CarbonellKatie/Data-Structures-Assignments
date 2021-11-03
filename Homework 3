#include <iostream>
using namespace std;


class Student {

public:

    int SID = 0;

    float GPA = 0;

    Student* ptr = NULL;
};


class HashTable {

public:

    int Insert(Student* y) { // insert a student x based on x.SID
        // return 1 if insertion is successful
        // return -1 if insertion fails (e.g. table full)
        int key = hash(y->SID);
        while(key != -1){

            //check if we can put the student in the slot it is designed to go to
            if (x[key] == NULL) {    //if we find an empty slot at the key where there is no existing chain, place student there
                x[key] = y;
                return 1;
            } else if (x[key]->ptr == NULL) { //if there is one more spot left in the chain, append the student to the end of chain
                x[key]->ptr = y;
                return 1;

                //check if there is an overflow array for this space if this chain is full
            } else {
                if (link[key] == -1) {  //if the overflow chain does not exist, search for the next available slot to make one
                    for (int i = key; i < 5; i++) {      //linear probing to find next empty slot
                        if (x[i] == NULL) {
                            link[key] = i;  //key is still the original index we were trying to put it at
                            x[i] = y; //add the student to the empty slot as the first Node in the new chain
                            return 1;
                        }
                    }
                    return -1;  //we could not find an empty slot, impossible to insert
                } else {  //if link[key] != -1  // if there is an overflow chain created //link[key] = 3
                    //insert(Student y, )
                    key = link[key];    //go through method again and check if we can put it anywhere at this new key
                    //if this array has an overflow, we will go to it
                }
            }
            }
        }
        

    float Search(int key);  // search for a student with SID=key in the table
    // return GPA if student is found
    // return -1 if student is not found

    int Remove(int key);   // remove a student with SID=key from the table
    // return 1 if student is found and removed
    // return -1 if student is not found

    void Enumerate();  // enumerate all numbers, already implemented for you

private:

    Student* x[5] = {NULL, NULL, NULL, NULL, NULL}; // array of student pointers

    int link[5] = {-1,-1,-1,-1,-1}; // link array, all initialized to -1

    int Counter[5] = {0, 0, 0, 0, 0};

    int hash(int key); // hash function, already implemented for you

};

int HashTable::hash(int key) {

    return key % 2;
}

void HashTable::Enumerate() {

    Student* temp;

    for (int i = 0; i < 5; i++) {

        temp = x[i];

        while (temp != NULL) {       // print the chain

            cout << temp->SID << ' ';

            temp = temp->ptr;
        }

        cout << link[i] << '\n';  // last number is the corresponding link value, then change line
        // so, basically, each line for one chain + corresponding link
    }

}

int main()
{
    HashTable table;

    for (int i = 0; i < 10; i++) {
        Student* x = new Student;
        cin >> x->SID >> x->GPA;
        x->ptr = NULL;
        table.Insert(x);
    }

    int operationChoice, SearchKey, RemoveKey;

    cin >> operationChoice >> SearchKey >> RemoveKey;

    if (operationChoice == 1) {

        table.Enumerate();
    }
    else if (operationChoice == 2) {

        cout << table.Search(SearchKey);
    }
    else if (operationChoice == 3) {

        table.Remove(RemoveKey);
        table.Enumerate();

    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}

}
