/*
209. Minimum Size Subarray Sum
https://leetcode.com/problems/minimum-size-subarray-sum/
Sliding Window
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int left = 0;
        int right = 0;
        int total_sum = 0;
        int sum = 0;
        int window_size = INT_MIN;
        
        
        for(int num:nums){
            total_sum+=num;
        }
        
        int target = total_sum-x;
        
        while(sum<target && right<nums.size()){
            sum+=nums[right];
            right++;
        }
        
        if(sum==target)
            window_size = max(window_size, right-left);
        
        right--;
        
        while(right<nums.size()){
                        
            
            if(sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum<target){
                
                if(right+1>=nums.size())
                    break;
                
                right++;
                sum+=nums[right];                
                
                
            }
            if(sum==target){
                window_size = max(window_size, right-left+1);                
                if(right==nums.size()-1)
                    break;
                right++;
                sum+=nums[right];
            }
                
            
        }
        
        return window_size==INT_MIN?-1:nums.size()-window_size;
        
    }
};
