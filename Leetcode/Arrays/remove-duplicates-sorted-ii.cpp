/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count = 1;
        
        for(int i=1; i<nums.size(); i++){
            
           if(nums[i]==nums[i-1]){
               count++;
               if(count>=3){
                   nums.erase(nums.begin()+i);
                   count-=1;
                   i--; //Resetting index, as we deleted element.
               }
           }
           else{               
               count = 1; //Resetting count, as we saw new element.
           }
            
        }
        
        return nums.size();
    }
};
