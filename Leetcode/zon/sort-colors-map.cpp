class Solution {
public:
    void sortColors(vector<int>& nums) {
                
        
        if(nums.size()==0 || nums.size()==1)
            return;
        map<int, int> mp;
        vector<int> ans;
        
        for(int num : nums){        
            mp[num]++;            
        }
        
        
        for(map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
            
            auto val = it;
            while(val->second--){
                ans.push_back(val->first);
            }
            
        }
        
        nums = ans;
        
    }
};
