/*

$ g++ -std=c++0x foldable-tree.cpp -o isFoldable
$ ./isFoldable
Tree is foldable

*/

#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* invert(Node* root){

    if(root){

        if(root->left==NULL && root->right==NULL) // If happens to be leaf
            return root;

        Node* leftChild = root->left;
        Node* rightChild = root->right;

        root->left = invert(rightChild);
        root->right = invert(leftChild);

        return root;

    }

    return NULL;
    
}

bool areSame(Node* root, Node* secondRoot){

    if(root==NULL && secondRoot==NULL)
        return true;

    if(root && secondRoot){
                
        return areSame(root->left, secondRoot->left) && areSame(root->right, secondRoot->right);

    }

    return false;

}

Node* deepCopy(Node* root){

    if(root){

        Node* copiedNode = new Node(root->data);

        if(root->left){
            copiedNode->left = deepCopy(root->left);
        }

        if(root->right){
            copiedNode->right = deepCopy(root->right);
        }

        return copiedNode;
        
    }

    return NULL;
}


int main(){

    //This Tree is foldable!
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(15);
    root->left->right = new Node(9);
    root->right->left = new Node(11);

    // This tree is foldable
    // Node* root = new Node(10);
    // root->left = new Node(7);
    // root->right = new Node(15);
    // root->left->left = new Node(9);
    // root->right->right = new Node(11);
    
    //This Tree is not foldable
    // Node* root = new Node(10);
    // root->left = new Node(7);
    // root->right = new Node(15);
    // root->left->left = new Node(5);
    // root->right->left = new Node(11);

  

    if(areSame(root, invert(deepCopy(root))))
        cout<<"Tree is foldable\n";
    else
        cout<<"Tree is not foldable\n";
    

    return 0;
}
