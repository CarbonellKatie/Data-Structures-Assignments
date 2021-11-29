//
// Created by carbo on 11/29/2021.
//
#include <iostream>
#include <vector>
using namespace std;

// In this project, implement a minimum heap using vector
//
// Implement two functions
// -- insert(int key): insert a new key into the heap
// -- remove(): remove the root key from the heap
//
// In the main function, we will first input 10 keys into the heap
// Then, we will enumarate them from the vector
// The enumeration function has been implemented for you
//

class heap {

public:
    void enumerate(); // enumerate all elements in the heap

    void insert(int key) { // insert a new key into the heap vector
    if(x.size() == 0){
        x.push_back(key);
    }
    else {
        x.push_back(key);
        rebalanceHeap(x.size() - 1);
    }
    }

    void rebalanceHeap(int keyIndex) {    //rebalance heap after key is placed at the back of the vector
        if(keyIndex == 0){
            return;
        }
        int parentIndex = getParentIndex(keyIndex);
        if(parentIndex < 0){
            return;
        }
        if (x[keyIndex] < x[parentIndex]) {  //if the key is less than its parent
            swap(keyIndex, parentIndex);
        }
        rebalanceHeap(parentIndex);
    }

    void swap(int index1, int index2){
        int temp = x[index2];
        x[index2] = x[index1];
        x[index1] = temp;
    }

        void remove() { // remove root key from the heap
           if(x.size() == 0){
               return;
           }
            else if(x.size() == 1){
                x.clear();
                return;
            }
            else{
                x[0] = x[x.size() - 1];     //replace the root with the last value in the vector
                x.pop_back();
                removeAndShiftHeap(0);
            }
        }

        void removeAndShiftHeap(int currKey){       //currkey = 0

        int leftChildIdx = getLeftChildIndex(currKey);
        int rightChildIdx = getRightChildIndex(currKey);

            if(leftChildIdx > x.size() - 1 && rightChildIdx > x.size() - 1){    //if this is a leaf node
                return;
            }
            else if(rightChildIdx > x.size() - 1) {  //if the node only has a left child
                if (x[leftChildIdx] < x[currKey]) { //if left child is less than current key
                    swap(currKey, leftChildIdx);    //swap the current key and the left child
                    removeAndShiftHeap(leftChildIdx);   //current key is now at position leftChildIdx, call method again to continue to balance key
                }
            }
            else {      //if this key has two children, swap the key with its smallest child (if the child is smaller than key)

                int minChildIndex;  //find the smallest child of this node
                if(x[leftChildIdx] < x[rightChildIdx]){
                    minChildIndex = leftChildIdx;
                }
                else{
                    minChildIndex = rightChildIdx;
                }
                if(x[minChildIndex] < x[currKey]){
                    swap(minChildIndex, currKey);
                    removeAndShiftHeap(minChildIndex);
                }
            }
            return;
    }

        int getParentIndex(int index) {
            return (index - 1) / 2;
        }
        int getRightChildIndex(int index) {
            return 2 * index + 2;
        }
        int getLeftChildIndex(int index) {
            return 2 * index + 1;
        }


private:
    vector<int> x;
};

void heap::enumerate() {

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << ' ';
    }
}

int main()
{
    int tmp[10];

    for (int i = 0; i < 10; i++) {

        cin >> tmp[i];
    }

    heap x;
    for (int i = 0; i < 10; i++) {
        x.insert(tmp[i]);
    }

    int operationChoice;

    cin >> operationChoice ;

    if (operationChoice == 1) { // enumerate key

        x.enumerate();
    }
    else if (operationChoice == 2) { // remove the smallest element from the heap and update the heap
        x.remove();
        x.enumerate();
    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}



