/*
https://www.geeksforgeeks.org/add-greater-values-every-node-given-bst/
*/

vector<int> elements;

void inorder(Node* root){
    
    if(root){
        inorder(root->left);
        elements.push_back(root->data);
        inorder(root->right);
    }
    
}

Node* arrayToBst(vector<int> prefix, int left, int right){
    
    if(left<=right){
        
        int mid = (left+right)/2;
        Node* root = new Node(prefix[mid]);
        root->left = arrayToBst(prefix, left, mid-1);
        root->right = arrayToBst(prefix, mid+1, right);
        
        return root;
    }
    
    return NULL;
    
}

// modify the BST and return its root
Node* modify(Node *root){
    // Your code here
  
    elements = {};

    inorder(root);
    vector<int> prefix_sum(elements.size(), 0);
    
    prefix_sum[elements.size()-1] = *elements.rbegin();
    
    
    for(int index = elements.size()-2; index>=0; index--){
        
        prefix_sum[index] = elements[index] + prefix_sum[index+1];
        
    }
    
    return arrayToBst(prefix_sum, 0, prefix_sum.size()-1);
    
}
