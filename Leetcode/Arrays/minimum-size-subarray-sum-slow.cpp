/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int right = 0;
        int sum = 0;
        int min_length = INT_MAX;
        
        while(sum<target && right<nums.size()){
            sum+=nums[right];
            right++;            
        }
        
        if(sum<target)
            return 0;
                
        min_length = min(min_length, right);        
        right--;
        
        while(right<nums.size()){
            
            if(sum>target){                
                min_length = min(min_length, right-left+1);
                sum-=nums[left];
                left++;
            }
            if(sum==target){                
                min_length = min(min_length, right-left+1);                
                if(right==nums.size()-1)
                    break;
                right++;
                sum+=nums[right];
            }
            if(sum<target){                
                //Expand rightwards
                if(right==nums.size()-1)
                    break;                    
                right++;
                sum+=nums[right];               
            }
            
            
        }
                
        return min_length;
    }
};
