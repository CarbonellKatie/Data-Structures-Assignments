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

    if (root == NULL) {     //if the tree is empty, insert the node as the root of the tree

        root = x;
    }
    else {

        if (x->SID <= root->SID) {

            root->left = insert(root->left, x);
            //root->left->parent = root;  //test
        }
        else {
            root->right = insert(root->right, x);
            //root->right->parent = root; //test
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

Node* rotateRight(Node* root){      //rotate the tree clockwise
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
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

        if(isRoot(focusNode)){ return; }
        while(focusNode != nullptr){   //update the height of all of x's parents

            focusNode->height = updateHeight(focusNode);
            focusNode->balanceFactor = getBalance(focusNode);

            int balance = focusNode->balanceFactor;
            //if the node is now unbalanced, re-balance it
            if(balance > 1 ){  //left heavy tree
                if(getBalance(focusNode->left) >= 0){   //if the tree is left heavy and if the left tree is left heavy
                    focusNode = rotateRight(focusNode);
                }
                else{       //if it is the left right case
                    focusNode->left = rotation_counterclock(root->left);
                    focusNode = rotateRight(focusNode);
                }
            }
            if(balance < -1){  //right heavy tree
                if(getBalance(focusNode->right) <= 0){
                    focusNode = rotation_counterclock(focusNode);
                }
                else{
                    focusNode->right = rotateRight(focusNode->right);
                    focusNode = rotation_counterclock(focusNode);
                }
            }
            focusNode = focusNode->parent;  //update all parent's heights
        }
        //height updated

        //update balances of all parent nodes

    } // insert a new node x into AVL tree

    int getBalance(Node* focusNode){
        if(focusNode == NULL){
            return 0;
        }
        return (updateHeight(focusNode->left) - updateHeight(focusNode->right));
        //return focusNode->left->height - focusNode->right->height;
    }

    int updateHeight(Node* focusNode){
        if(focusNode == NULL){      //height of a Null node is -1
            return -1;
        }
        int leftNodeHeight;
        int rightNodeHeight;

        if(focusNode->right == NULL) {  //null node = height of -1
            rightNodeHeight = -1;
        }
        else{
            rightNodeHeight = focusNode->right->height;     //if focusNode has a right child, find its height
        }
        if(focusNode->left == NULL){    //repeat for left child
            leftNodeHeight = -1;
        }
        else{
            leftNodeHeight = focusNode->left->height;
        }

        //height of focusNode is 1 greater than the height of its longest subtree
        return(1 + std::max(rightNodeHeight, leftNodeHeight));

    }

private:

    Node* root = NULL;
};



//void enumerate(Node* ptr);

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

