/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/
class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        if(!root)
            return 0;
        
        if(root->left==NULL && root->right==NULL)
            return root->val;
        
        stack<pair<TreeNode*, int>> treeStack;
        unordered_map<TreeNode*, bool> visited;
        
        treeStack.push({root, root->val});
        visited[root] = true;
        int answer = 1;
        
        while(!treeStack.empty()){
            
            pair<TreeNode*, int> top;
            top = treeStack.top();
            
            int visitedChildren = 0;
            
            if(top.first->left==NULL && top.first->right==NULL)
                treeStack.pop();
            
            if((top.first)->left){  
                if(!visited[(top.first)->left]){
                    visited[(top.first)->left] = true;
                    if((top.first)->left->val >= top.second)
                        answer++;
                    
                    treeStack.push({top.first->left, max(top.second, top.first->left->val)});                         
                    continue;
                }
                else
                    visitedChildren ++;
            }
            
            if((top.first)->right){
                
                if(!visited[top.first->right]){
                    visited[top.first->right] = true;
                    if(top.first->right->val >= top.second)
                        answer++;
                    
                    treeStack.push({top.first->right, max(top.second, top.first->right->val)});
                    continue;
                }
                else
                    visitedChildren ++;
                
            }
            
            
            if(visitedChildren==2)
                treeStack.pop();            
            else if(visitedChildren==1){
                if(visited[top.first->right] && !visited[top.first->left])
                    treeStack.pop();
                else if(visited[top.first->left] && !visited[top.first->right])
                    treeStack.pop();
            }
            
        }
        
        return answer;
    }
};
