
class cmp{
    
    public:
     bool operator()(pair<int, string> p1, pair<int, string> p2){
        
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        else
            return p1.first<p2.first;
                    
    }    
    
};

class Solution {
public:
           
    
    vector<string> topKFrequent(vector<string>& words, int k) {
                
        priority_queue<pair<int, string>, vector<pair<int, string>> , cmp> pq;
        map<string, int> mp;
        vector<string> ans;
        
        for(string word : words){            
            mp[word]++;            
        }
                        
        for(map<string, int>::iterator it = mp.begin();it!=mp.end();++it){                        
            pq.push({it->second, it->first});                        
        }
        
        
        while(k--){
            
            pair<int, string> temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
            
        }
                        
        return ans;
        
    }
};
