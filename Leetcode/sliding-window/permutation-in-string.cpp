/*
https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length())
            return false;
        
        
        unordered_map<char, int> mp;
        
        for(char p:s1){
            mp[p]++;
        }
             
        
        for(int i=0;i<s2.length();i++){
            bool flag = true;
            mp[s2[i]]--;
            
            if(i>=s1.length()){                
                mp[s2[i-s1.length()]]++;                
            }
            
            for(auto it = mp.begin(); it!=mp.end(); it++){     
                
                if(it->second!=0){                    
                    flag = false;
                    break;                    
                }                                    
            }
            
            if(flag)
                return true;
            
            
        }
        
        return false;
        
    }
};
