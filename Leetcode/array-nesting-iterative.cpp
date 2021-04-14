/*
https://leetcode.com/problems/array-nesting
*/
class Solution {
public:
    map<int,bool> mp;
    vector<int> glob;
    vector<int> mem;
    
    
    
    int arrayNesting(vector<int>& nums) {
       
        mem.assign(nums.size()+1, -1);    
        glob = nums;
        int max = INT_MIN;
        
        for(int i=0;i<nums.size();i++){                        
            
           
		   int ptr = i;
		   int count= 0;
           if(mem[i]==-1) {
               do{		                
                    mp[ptr] = true;
                    ptr = nums[ptr];                
                    count++;
                    mem[ptr] = count;
               }while(!mp[ptr]);

               mem[i] = count;
               if(mem[i]>max) max = mem[i];
           }        
           
        }
        
		
		
		
        return max;
        
    }
};
