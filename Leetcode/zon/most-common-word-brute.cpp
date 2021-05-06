/*

  https://leetcode.com/problems/most-common-word/

*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        
        map<string, int> mp;
        set<string> ban_set;
        
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        
        for(string ban:banned){
            ban_set.insert(ban);
        }
                

        string word = "";
        for(int i=0;i<paragraph.length();i++){
            
            
            
            if(paragraph[i]=='!' || paragraph[i]=='?' || paragraph[i]==',' || paragraph[i]=='\'' || paragraph[i]==',' || paragraph[i]==';' || paragraph[i]=='.' || paragraph[i]==' '){
                
                if(ban_set.find(word)==ban_set.end()){
                    mp[word]++;                    
                }

                word="";
            }
            else{
                
                word+=paragraph[i];
                
            }
                
            
        }
                
        if(word!="")
            mp[word]++;            
                
        priority_queue<pair<int, string>> pq;
        
        for(map<string, int>::iterator it = mp.begin(); it!=mp.end();it++){
            
            
                
            if((it->first).length()==0);
            else
                pq.push({it->second, it->first});            
        }
        
        if(pq.size())
            return pq.top().second;
        

        
        return "";
    }
};
