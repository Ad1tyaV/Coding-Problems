/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// https://leetcode.com/problems/n-ary-tree-postorder-traversal

class Solution {
public:
    
        
    
    vector<int> postorder(Node* root) {
        
       
        if(root==NULL) return {};
        
        stack<Node*> s1;
        stack<Node*> s2;
        vector<int> ans;
        
        s1.push(root);
        
        while(!s1.empty()){
            
            Node* temp;
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            
            for(Node* child:temp->children){
                if(child)
                    s1.push(child);
            }            
            
        }
        
        while(!s2.empty()){
            //cout<<s2.top()->val<<"\t";
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        // cout<<"\n";
        
        return ans;
    }
};
