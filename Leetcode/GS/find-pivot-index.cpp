/*
https://leetcode.com/problems/find-pivot-index/submissions/
*/

class Solution {
public:
           
    int pivotIndex(vector<int>& nums) {
        
        vector<int> prefix;
        
        for(int i=0;i<nums.size(); i++){            
            prefix.push_back(i==0?nums[i]:nums[i]+prefix[prefix.size()-1]);            
        }
        
        int left = 0;
        int right = nums.size()-1;
        
        int ls = 0;
        int rs = prefix[right]-prefix[left];
        
        if(ls==rs)
            return 0;
        
        for(int i=1;i<nums.size();i++){
            
            int pivot = i;
            
            int leftsum = prefix[pivot-1];
            int rightsum = prefix[right]-prefix[pivot];
            
            if(leftsum==rightsum)
                return pivot;
            
            
        }
        
        
        return -1;
    }
};
