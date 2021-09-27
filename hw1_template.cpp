#include <iostream>
using namespace std;
class Array {

public:
    // please implement the following six member functions 
    void Set(int key, int index);  // assign "key" to "x[index]"
    int* Get();                    // return pointer to a copy of array x 
                                   // must be a copy, not x itself 
    void Sort_Bubble();            // bubble sort array x
    void Sort_Insertion();         // insertion sort array x                     
    int Search_Linear(int key);    // linear search of "key" in the array
                                   // if success, return index of key 
                                   // if fail, return -1 
    int Search_Binary(int key);    // binary search of "key" in the array
                                   // if success, return index of key 
                                   // if fail, return -1 
private:
    int x[10];                     // array size is fixed to 10 
};

int main()
{
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
    int* temp;

    if (operationChoice == 1)
    {
        temp = A.Get();
        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ' ';   // outputs are separated by tabs 
        }
    }
    else if (operationChoice == 2)
    {
        A.Sort_Bubble();
        temp = A.Get();
        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ' ';   // outputs are separated by tabs 
        }
    }
    else if (operationChoice == 3)
    {
        A.Sort_Insertion();
        temp = A.Get();
        for (int i = 0; i < 10; i++) {
            cout << temp[i] << ' ';   // outputs are separated by tabs 
        }
    }
    else if (operationChoice == 4)
    {
        cin >> SearchKey;
        IndexKey = A.Search_Linear(SearchKey);
        cout << IndexKey << endl;
    }
    else if (operationChoice == 5)
    {
        cin >> SearchKey;
        A.Sort_Bubble();
        IndexKey = A.Search_Binary(SearchKey);
        cout << IndexKey << endl;
    }
    else
    {
        cout << "Enter a valid choice";
    }
    return 0;
}
