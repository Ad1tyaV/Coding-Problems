class Solution {
public:
    map<int,bool> mp;
    vector<int> glob;
    vector<int> mem;
    
    int _find(int i){
        
        if(mem[i]!=-1) return mem[i];
        if(mp[i]) return 0;
        
        mp[i] = true;        
        return mem[i] = _find(glob[i]) + 1;                
    }
    
    int arrayNesting(vector<int>& nums) {
       
        mem.assign(nums.size()+1, -1);    
        glob = nums;
        int max = INT_MIN;
        
        for(int i=0;i<nums.size();i++){                        
            
            if(mem[i]==-1){
                int temp = _find(i);
                if(temp>max)
                    max = temp;
            }
        }
        
        return max;
        
    }
};
