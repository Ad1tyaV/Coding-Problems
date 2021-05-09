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
 
 https://leetcode.com/problems/binary-tree-right-side-view/
 
 */


class Solution {
public:
    
    map<int, vector<int>> mp;
    
    void order(TreeNode* root, int level){
        
        if(root){
            mp[level].push_back(root->val);
            order(root->left, level+1);
            order(root->right, level+1);            
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        order(root, 0);
        for(auto it = mp.begin(); it!=mp.end(); it++){            
            ans.push_back((it->second)[(it->second).size()-1]);            
        }
     
        return ans;
    }
};
