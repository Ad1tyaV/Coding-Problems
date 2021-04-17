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
// https://leetcode.com/problems/binary-tree-level-order-traversal

class Solution {
public:
    vector<vector<int>> ans;    
    
    void findSol(TreeNode* temp, int track){
        
        if(temp){
            
            if(!track)
                ans.push_back({temp->val});
            else{
                if(track==ans.size()){
                    ans.push_back({temp->val});
                }
                else{
                    ans[track].push_back(temp->val);
                }
            }                        
                
            findSol(temp->left, track+1);
            findSol(temp->right, track+1);
        }
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        findSol(root, 0);
        
        return ans;
        
    }
};
