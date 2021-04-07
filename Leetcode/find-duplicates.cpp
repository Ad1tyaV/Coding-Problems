class Solution {
public:
    int findDuplicate(vector<int>& nums) {
                
        int slowptr=0;
        int fastptr=0;
       
        //Phase-1
        
        do{                        
            slowptr=nums[slowptr];
            fastptr=nums[nums[fastptr]];            
        }while(slowptr!=fastptr);
        
        //Phase-2
        fastptr=0;
        while(slowptr!=fastptr){
            slowptr=nums[slowptr];
            fastptr=nums[fastptr];
        }
        
    
            
        return slowptr;
    }
};
