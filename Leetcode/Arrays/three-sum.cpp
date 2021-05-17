/*
https://leetcode.com/problems/3sum/
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size()==0 || nums.size()==1)
            return {};
        
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        
        for(int i=0;i<nums.size()-2; i++){
            
            int first = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            
            while(left<right){
                
                if(nums[left]+nums[right]==-first){
                    ans.insert({first, nums[left], nums[right]});
                    left++;
                    right--;
                }
                else{                    
                    if(nums[left]+nums[right]>-first){
                        right--;
                    }
                    else{
                        left++;
                    }                    
                }                                
            }
            
        }
        return {ans.begin(), ans.end()};
    }
};
