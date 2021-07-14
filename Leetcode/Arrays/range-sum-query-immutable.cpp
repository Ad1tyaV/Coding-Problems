/*
Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/
*/

class NumArray {
public:
    
    vector<int> nums;
    vector<int> prefix_sum;
    
    void computePrefixSum(){
        
        for(int i=0; i<nums.size(); i++){
            
            if(!i){
                this->prefix_sum.push_back(nums[i]);
            }
            else{
                this->prefix_sum.push_back(nums[i]+this->prefix_sum[this->prefix_sum.size()-1]);
            }
            
        }
        
    }
    
    NumArray(vector<int>& nums) {
        
        this->nums = nums;
        computePrefixSum();
    }
    
    int sumRange(int left, int right) {
        
        if(left==0)
            return this->prefix_sum[right];
        
        return prefix_sum[right] - prefix_sum[left-1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
