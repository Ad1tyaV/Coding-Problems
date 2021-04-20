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

// https://leetcode.com/problems/n-ary-tree-level-order-traversal

class Solution {
public:
    
    vector<vector<int>> sol;
    
    void findSol(Node* root, int track){
        
        if(root){
            
            if(!sol.size()){                
                sol.push_back({root->val});
            }
            else{
                
               if(sol.size()==track){
                   sol.push_back({});
                   sol[track].push_back(root->val);
               }
               else{
                   sol[track].push_back(root->val);
               }              
            }
             for(Node* temp:root->children){
                   if(temp)
                       findSol(temp, track+1);
             }
            
        }
        else return;
        
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        findSol(root, 0);
        
        return sol;
    }
};
