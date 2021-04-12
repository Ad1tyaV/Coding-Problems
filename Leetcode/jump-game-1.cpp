class Solution {
public:
   
    
    bool canJump(vector<int>& nums) {
       
        if(nums.size()==1) return true;
        
        int index = 0;
        int n = nums.size();
        int lastIndex = nums.size()-1;     
        
        
        for(int i = lastIndex-1; i>-1;i--){
                        
            
            if((nums[i] + i)>=lastIndex){                                
                lastIndex = i;                
                if(i==0) return true;
            }
            
        }
            return false;               
    }
};
