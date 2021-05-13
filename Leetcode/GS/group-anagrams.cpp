/*
https://leetcode.com/problems/group-anagrams/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        map<string, vector<string>> st;
        vector<vector<string>> ans;
        
        for(string p:strs){
            string temp;
            temp = p;
            sort(p.begin(), p.end());
            st[p].push_back(temp);
        }
        
        for(auto it = st.begin(); it!=st.end(); it++){
            vector<string> sk;
            for(string temp:it->second){
                sk.push_back(temp);                
            }
            ans.push_back(sk);            
        }
     
        return ans;
    }
};
