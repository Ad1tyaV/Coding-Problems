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
https://leetcode.com/problems/binary-tree-level-order-traversal-ii
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        
        q1.push(root);
        
        
        while(true){
            
            if(q1.empty() && q2.empty())
                break;
            
            vector<int> t;            
            while(!q1.empty()){
                
                TreeNode* temp = q1.front();                
                t.push_back(temp->val);
                q1.pop();
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
                
            }
            ans.push_back(t);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
