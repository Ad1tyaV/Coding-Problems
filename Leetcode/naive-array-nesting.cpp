/*
https://leetcode.com/problems/array-nesting/
*/
class Solution {
public:
    map<int,bool> mp;
    int arrayNesting(vector<int>& nums) {
       
        vector<int> ans;
        int n = nums.size();
        int ptr;
        int count = 0;
        int index = 0;
        int max_count = -1;
        
       for(int i=0;i<nums.size();i++){
           
           mp.clear();
           ptr = nums[i];           
           
           do{               
               mp[ptr] = true;
               ptr = nums[ptr];               
               count++;
           }while(!mp[ptr]);
           
           if(max_count<count){               
               max_count = count;                    
           }
           count = 0;
           
       }
                        
        
        return max_count;
    }
};
