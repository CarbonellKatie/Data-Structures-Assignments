#include <iostream>

using namespace std;

class Array {

public:
    // please implement the following six member functions 
    void Set(int key, int index) {  // assign "key" to "x[index]"
        x[index] = key;
    }

    int *Get() {    // return pointer to a copy of array x
        static int y[10];
        for (int i = 0; i < 10; i++) {
            y[i] = x[i];
        }
        //}
        return y;
    }


    // must be a copy, not x itself
    void Sort_Bubble() {     // bubble sort array x
        int counter = 1;
        while (counter > 0) {
            counter = 0;
            for (int i = 0; i < 9; i++) {
                if (x[i] > x[i + 1]) {      //if element on left is greater than element on right, swap 2 elements
                    int temp = x[i];    //temp variable so element at x[i] is not lost
                    x[i] = x[i + 1];
                    x[i + 1] = temp;
                    counter++;
                }
            }
        }


    }

    void Sort_Insertion() {  // insertion sort array x
        for (int i = 1; i < 10; i++) {
            int key = x[i];
            int j = i - 1;

            while (j >= 0) {
                if (key < x[j]) {     //if element on left has a lesser value than the one on the right, swap them
                    int temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
                j--;        //decrement j to compare next element
            }
        }
    }

    int Search_Linear(
            int key) {   // linear search of "key" in the array || if success, return index of key || if fail, return -1
        for (int i = 0; i < 10; i++) {
            if (x[i] == key) {
                return i;
            }
        }
        return -1;

    }

    int Search_Binary(
            int key) {     // binary search of "key" in the array | if success, return index of key | if fail, return -1
        //sort the list first, requirement for binary search
        Sort_Bubble();

        int min = 0;    //min index, index of first element
        int max = 9;    //max index, index of last element
        // = 5
        int midpoint;
        while (max >= min) {
            midpoint = (max + min) / 2;

            if (x[midpoint] == key) {
                return midpoint;
            } else if (key < x[midpoint]) {
                max = midpoint - 1;
            } else if (key > x[midpoint]) {
                min = midpoint + 1;
            }
        }
        return -1;

    }
//create array
private:
    int x[10];                     // array size is fixed to 10 
};

int main() {
    Array A;

    int InputKey, operationChoice, SearchKey, IndexKey;
    int i = 0;
    while (i < 10) {
        cin >> InputKey;             // Reads the input numbers from the console
        A.Set(InputKey, i);
        i++;
    }


    // if operationChoice = 1, directly output elements in A 
    // if operationChoice = 2, sort elements in A by bubble sort and output result 
    // if operationChoice = 3, sort elements in A by insertion sort and output result 
    // if operationChoice = 4, apply linear search to search for "SearchKey" in A
    // if operationChoice = 5, first apply bubble sort on A, then apply binary search to search for "SearchKey" in A
    cin >> operationChoice;
    int *temp;

    if (operationChoice == 1) {
        temp = A.Get();
        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ' ';   // outputs are separated by tabs 
        }
    } else if (operationChoice == 2) {
        A.Sort_Bubble();
        temp = A.Get();
        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ' ';   // outputs are separated by tabs 
        }
    } else if (operationChoice == 3) {
        A.Sort_Insertion();
        temp = A.Get();
        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ' ';   // outputs are separated by tabs 
        }
    } else if (operationChoice == 4) {
        cin >> SearchKey;
        IndexKey = A.Search_Linear(SearchKey);
        cout << IndexKey << endl;
    } else if (operationChoice == 5) {
        cin >> SearchKey;
        A.Sort_Bubble();
        IndexKey = A.Search_Binary(SearchKey);
        cout << IndexKey << endl;
    } else {
        cout << "Enter a valid choice";
    }
    return 0;
}
