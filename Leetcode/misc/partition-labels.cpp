#include<vector>
#include<set>
#include<string>
#include<map>
#include <any>


using namespace std;

class cmp{
    public:
    bool operator()(pair<char, pair<int, int>> p1, pair<char, pair<int, int>> p2){
        
        return (p1.second.first < p2.second.first);
        
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        map<char, pair<int, int>> mp;
        vector<pair<int, int>> track;
        for(int i=0;i< S.length(); i++){
            
            if(mp.find(S[i])==mp.end()){                
                mp[S[i]] = {i, i};                
            }
            else{
                mp[S[i]] = {mp[S[i]].first, i};
            }
            
        }
                
        set<pair<int, int>> st;
        for(auto it = mp.begin(); it!=mp.end(); it++){
           
            st.insert(it->second);
        }
        
        
        
        track.push_back(*st.begin());

        st.erase(st.begin());
        
        // for(auto it = st.begin(); it!=st.end(); it++){
        while(!st.empty()){
            
            auto it = st.begin();
            pair<int, int> &xy = track[track.size()-1];
            
            //Overlap exists!
            if(xy.second >= (it->first)){
                xy.second = max(xy.second, (it->second));    
                st.erase(it);
            }
            else{ //No Overlap     
                
                // track.push_back(any_cast<pair<int, int>>(it));
                track.push_back(*it);
                st.erase(it);                
            }
                        
        }
        
        vector<int> ranges;
        
        for(auto it = track.begin(); it!=track.end(); it++){
            ranges.push_back(it->second-it->first+1);
        }
        
        return ranges;
    }
};
