/*

https://leetcode.com/problems/sort-array-by-increasing-frequency

*/
class Solution {
public:
   
    class cmp{
        
        public:
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            
            if(p1.second==p2.second)
                return p1.first<p2.first;
            
            return p1.second>p2.second;
            
        }
        
    };
    
    
    vector<int> frequencySort(vector<int>& nums) {
        
        map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<int> ans;
        
        
        for(int n:nums){
            mp[n]++;
        }
        
        for(auto it = mp.begin(); it!=mp.end(); it++){
            pq.push({it->first, it->second});
        }
        
        while(pq.size()){
            
            pair<int, int> temp;
            temp = pq.top();
            while(temp.second--){
                ans.push_back(temp.first);
            }
            pq.pop();
        }
        
        
        return ans;
    }
};
