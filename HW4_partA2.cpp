#include <iostream>
using namespace std;

// In this project, implement an AVL tree with one function
// -- AVL_Insert: insert a new node into AVL tree
//
// In the main function, we will insert 10 nodes into AVL
// Then, we will enumarate these nodes based on in-order traverse
// The enumeration function has been implemented for you
//
// Some functions are provided. You don't have to use them.

class Node {

public:

    int SID = 0;

    Node* left = NULL;

    Node* right = NULL;

    Node* parent = NULL;

    int balanceFactor = 0;

    int height = -1;

};


int depth(Node* ptr) { // measure depth of a node

    int counter = 0;

    while (ptr->parent != NULL) {

        ptr = ptr->parent;

        counter++;
    }

    return counter;
}


void enumerate(Node* ptr) { // in-order traverse

    if (ptr->left != NULL) {

        enumerate(ptr->left);

    }
    cout << ptr->SID << ' ';

    if (ptr->right != NULL) {

        enumerate(ptr->right);
    }
}


int isRoot(Node* ptr) { // check if node is root or not

    if (ptr->parent == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


int isLeaf(Node* ptr) { // check if node is leaf or not

    if (ptr->left == NULL && ptr->right == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}


Node* insert(Node* root, Node* x) { // insert a node to a tree with root

    if (root == NULL) {

        root = x;
    }
    else {

        if (x->SID <= root->SID) {

            root->left = insert(root->left, x);
        }
        else {
            root->right = insert(root->right, x);
        }
    }

    return root;
}


int findmax(Node* root) { // find max node from a tree with root

    if (root->right == NULL) {

        return root->SID;
    }
    else {

        return findmax(root->right);
    }
}

Node* rotation_counterclock(Node* root) { // rotate tree at root counter clockwise

    Node* temp = root->right;

    if (root->right->left != NULL) {

        root->right = root->right->left;
    }

    temp->left = root;

    root = temp;

    return root;
}

class AVL {

public:

    Node* GetRoot(){
        return root;
    } // return root node pointer; not really used in testing

    void AVL_Enumerate(); // enumerate nodes based on in-order traverse

    void AVL_Insert(Node* x){
        root = insert(root, x); //insert the new node and update root

        Node* focusNode = x;
        int leftNodeHeight;
        int rightNodeHeight;

        while(focusNode != NULL){   //update the height of all of x's parents
            if(focusNode->right == NULL) {
                rightNodeHeight = -1;
            }
            else{
                rightNodeHeight = focusNode->right->height;
            }
            if(focusNode->left == NULL){
                leftNodeHeight = -1;
            }
            else{
                leftNodeHeight = focusNode->left->height;
            }

            focusNode->height = 1 + std::max(rightNodeHeight, leftNodeHeight);
            focusNode->balanceFactor = focusNode->left->height - focusNode->right->height;

            //if the node is now unbalanced, re-balance it
            if(focusNode->balanceFactor > 1 || focusNode->balanceFactor < -1){
                

            }
            focusNode = focusNode->parent;  //update all parent's heights
        }
        //height updated

        //update balances of all parent nodes



    } // insert a new node x into AVL tree

private:

    Node* root = NULL;
};



void enumerate(Node* ptr);

void AVL::AVL_Enumerate() {

    enumerate(root);
}


int main()
{
    Node tmp[10];

    for (int i = 0; i < 10; i++) {

        cin >> tmp[i].SID;
    }

    AVL x;

    for (int i = 0; i < 10; i++) {

        x.AVL_Insert(&tmp[i]);
    }

    int operationChoice;

    cin >> operationChoice;

    if (operationChoice == 1) { // enumerate key

        x.AVL_Enumerate();
    }
    else {

        cout << "Enter a valid choice";
    }

    return 0;
}

