#include <iostream>
//Katherine Carbonell Assignment #1
using namespace std;

class Array {

public:

    //function to set the value of an element of x at a certain index
    void Set(int key, int index) {  // assign "key" to "x[index]"
        x[index] = key;
    }

    int *Get() {    // return pointer to a copy of array x
        static int y[10];   //create a new array named y that will be a copy of x
        for (int i = 0; i < 10; i++) {      //copy values from x over to y
            y[i] = x[i];
        }
        return y;   //return y, which is a copy of x
    }



    void Sort_Bubble() {     // bubble sort array x
        int counter = 1;    //counter used to determine if an element has been swapped in this round
        while (counter > 0) {   //if counter has been incremented, the sorting is not complete, so continue
            counter = 0;        //reset counter each pass
            for (int i = 0; i < 9; i++) {       //iterate through every element of the array, excluding the last element
                                                //last element will be accessed using x[i+1]
                if (x[i] > x[i + 1]) {      //if element on left is greater than element on right, swap 2 elements
                    int temp = x[i];    //temp variable so element at x[i] is not lost
                    x[i] = x[i + 1];
                    x[i + 1] = temp;
                    counter++;          //increment counter if 2 values were swapped
                }
            }
        }
    }

    void Sort_Insertion() {  // insertion sort array x
        for (int i = 1; i < 10; i++) {      //iterate through all elements in the array x
            int key = x[i];                 //set key equal to the element at that index
            int j = i - 1;                  //j will be the index of the value right before the key

            while (j >= 0) {                //while j is within the bounds of x
                if (key < x[j]) {     //if element on left has a lesser value than the one on the right, swap them
                    int temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
                j--;        //decrement j to compare next element
            }
        }
    }

    int Search_Linear(int key) {   // linear search of "key" in the array || if success, return index of key || if fail, return -1
        for (int i = 0; i < 10; i++) {  //iterate through all elements of x
            if (x[i] == key) {          //if you find x at the index you are looking at, return the index number
                return i;
            }
        }
        return -1;      //if key is not found in the array, return -1

    }

    int Search_Binary(int key) {     // binary search of "key" in the array | if success, return index of key | if fail, return -1
        //sort the list first, binary search requires the list to be sorted
        Sort_Bubble();

        int min = 0;    //min index, index of first element
        int max = 9;    //max index, index of last element

        int midpoint;
        while (max >= min) {
            midpoint = (max + min) / 2; //compute midpoint by taking average of max & min (round down using int division)

            if (x[midpoint] == key) {   //if you find the key at the midpoint, return the index of midpoint
                return midpoint;
            } else if (key < x[midpoint]) {     //if the key is less than the value at midpoint, adjust the search area
                max = midpoint - 1;             //to everything below the midpoint
            } else if (key > x[midpoint]) {     //if the key is greater than the value at midpoint, adjust the search area
                min = midpoint + 1;             //to everything above the midpoint
            }
        }
        return -1;  //if key not found in array, return -1

    }
//create private array as member of this Array class
private:
    int x[10];                     // array size is fixed to 10 
};

int main() {
    Array A;

    //fill A with values read in from user input
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
