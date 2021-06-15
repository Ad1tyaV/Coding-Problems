/*

https://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/

*/
#include<iostream>
#include<set>
#include<vector>
#include<queue>

using namespace std;

struct Node{

    int value;
    Node* left;
    Node* right;

    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

};


set<Node*> tracker;

void traverse(Node* root, int k){

    queue<pair<Node*, vector<Node*>>> q;
    q.push({root, {root}});

    while(!q.empty()){

        pair<Node*, vector<Node*>> top = q.front();
        q.pop();
        Node* currentNode = top.first;
        vector<Node*> currentPath = top.second;

        //Leaf Check
        if(currentNode->left==NULL && currentNode->right==NULL){
            // cout<<"for leaf - "<<currentNode->value<<"\n-----------------------------------------\n";
            // for(auto it = currentPath.begin(); it!=currentPath.end(); it++){
            //     cout<<(*it)->value<<"\t";
            // }
            // cout<<endl;            
            
            if(currentPath.size()  >= k+1){
                
                tracker.insert(currentPath[currentPath.size()-k-1]);

            }
        }

        if(currentNode->left){

            currentPath.push_back(currentNode->left);
            q.push({ currentNode->left, currentPath});
            currentPath.pop_back();

        }

        if(currentNode->right){
            
            currentPath.push_back(currentNode->right);
            q.push({ currentNode->right, currentPath});

        }

    }

}

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->left->right = new Node(8);

    
    traverse(root, 1);
    // cout<<tracker.size()<<endl;
    for(auto it = tracker.begin(); it!=tracker.end(); it++){
        cout<<(*it)->value<<"\t";
    }
    cout<<endl;


    return 0;
}
