/*

https://leetcode.com/problems/find-all-anagrams-in-a-string/

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> mp;
        unordered_map<char, int> bkup;
        vector<int> ans;
        
        int window = p.length();
        int left = 0;
        
        for(int i = left;i<window;i++){            
            mp[s[i]]++;            
        }
        
        
        
        while(left+window<=s.length()){
            
            bkup = mp;
            
            for(char character:p){
                
                if(mp[character]==0)
                    break;
                
                if(mp[character]==1){
                    mp.erase(character);
                    continue;
                }                
                mp[character]--;
            }
            
            if(mp.empty()){
                ans.push_back(left);
            }
            
            mp = bkup;            
            if(mp[s[left]]==1)
                mp.erase(s[left]);
            else
                mp[s[left]]--;
            
            if(left+window<s.length())
                mp[s[left+window]]++;
            
            left++;
        }

        return ans;
    }
};
