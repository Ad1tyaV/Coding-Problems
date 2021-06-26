/*
  https://leetcode.com/problems/next-permutation/submissions/
  https://www.youtube.com/watch?v=LuLCLgMElus
*/
class Solution {
public:
    
    void swap(int &a, int &b){
        
        int temp = a;
        a = b;
        b = temp;
        
    }
    
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size()==1)
            return;
        
        if(nums.size()==2){
            if(nums[0]==nums[1])
                return;
            nums = {nums[1], nums[0]};
            return;           
                        
        }
        
        int index = nums.size()-2;
        
        while(index>=0){
            if(nums[index]<nums[index+1]){
                break;                
            }
            index--;
        }
        
        if(index<0){
            sort(nums.begin(), nums.end());
            return;
        }
        
        int j = nums.size()-1;
        
        for(; j>index; j--){
            
            if(nums[index]<nums[j]){
                break;
            }
            
        }
                
        
        swap(nums[index], nums[j]);
        
        partial_sort(nums.begin()+index+1, nums.end(), nums.end());
        
        
    }
};
