class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        for(int i=0; i<k; i++){
            
            int temp = nums[0];
            for(int i=0; i<nums.size(); i++){
                
                int shift = (i+1)%nums.size();
                int temp2 = nums[shift];
                nums[shift] = temp;
                temp = temp2;
                
            }
            
        }
        
    }
};
