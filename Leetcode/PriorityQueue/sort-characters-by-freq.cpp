//https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        string ans="";
        
        for(int i=0;i<s.length();i++){            
            mp[s[i]]++;            
        }
        
        for(map<char,int>::iterator it=mp.begin();it!=mp.end();++it){            
            pq.push({it->second, it->first});            
        }
        
        while(pq.size()){
            
            pair<int, char> temp = pq.top();
            
            while(temp.first){                
                ans+=temp.second;
                temp.first--;
            }
            pq.pop();            
        }
        return ans;
    }
};
