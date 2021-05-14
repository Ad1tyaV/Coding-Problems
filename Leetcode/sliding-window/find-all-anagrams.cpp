/*

https://leetcode.com/problems/find-all-anagrams-in-a-string

*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        
        unordered_map<char, int> p1;
        
        vector<int> ans;
        
        for(char m:p){
            p1[m]++;
        }        
       
        for(int i=0; i<s.length(); i++){
                               
            bool flag = true;
            p1[s[i]]--;
            if(i>=p.length()){                
                p1[s[i-p.length()]]++;
            }
            
            for(auto it = p1.begin(); it!=p1.end(); it++){                
                
                
                if(it->second!=0){
                    flag = false;
                    break;
                }
                
            }
            
            if(flag)
                ans.push_back(i-(p.length()-1));
            
        }
        
        return ans;
    }
};
