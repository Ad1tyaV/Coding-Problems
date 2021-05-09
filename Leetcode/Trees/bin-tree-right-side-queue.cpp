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
class Solution {
public:
    
   
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root)
            return {};
        
        if(root->left==NULL && root->right==NULL)
            return {root->val};
        
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, vector<TreeNode*>> mp;
        
        q.push({root, 0});
        
        while(q.size()){
            
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            mp[temp.second].push_back(temp.first);
            
            
            if(temp.first && temp.first->left)
                q.push({temp.first->left, temp.second+1});
            if(temp.first && temp.first->right)
                q.push({temp.first->right, temp.second+1});             
            
            
        }
        
        for(auto it = mp.begin(); it!=mp.end(); it++){            
            int m = (it->second)[(it->second).size()-1]->val;            
            ans.push_back(m);
        }
        
        return ans;
    }
};
