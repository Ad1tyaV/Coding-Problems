/*
https://leetcode.com/problems/delete-and-earn/
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];        
                        
        unordered_map<int, int> counter;
        int max_element = INT_MIN;
        
        for(int element:nums){
            max_element = max(max_element, element);
            counter[element]++;
        }
        
        vector<int> dp(max_element+1, 0);
        
        dp[0] = 0;
        dp[1] = counter[1];
        
        for(int i=2; i<=max_element; i++){            
            dp[i] = max(dp[i-2] + (i*counter[i]), dp[i-1]);            
        }
                     
        return dp[max_element];
    }
};
