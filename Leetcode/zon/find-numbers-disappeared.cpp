
/*

  https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int p=1;
        for(int i=0;i<nums.size();){
            
            if(p!=nums[i]){
                
                ans.push_back(p);
            }
            
            while(i< nums.size() && nums[i]==p)
                i++;
            p++;
            
        }
        while(p<=nums.size()){
            ans.push_back(p);
            p++;
        }
        
        //cout<<"p="<<p<<endl;
        return ans;
    }
};
