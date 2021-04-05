class Solution {
public:
    map<string,pair<int,int>> mp;
    map<pair<pair<int,int>,int>,int> mp2;
    pair<int,int> count(string s){
        
        int z=0;
        int o=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') z++;
            else o++;
        }
        mp[s] = pair<int,int>{z,o};
        return mp[s];
    }
    
    int check(vector<string> str, pair<int,int> target, int index){
        
       
        if(index==str.size()) return 0;
        
        if(target.first==0 && target.second==0) return 0;
        
        if(mp2.find({{target.first, target.second},index})!=mp2.end()){
            return mp2[{{target.first, target.second},index}];
        }
        
        pair<int,int> ret;
        
        if(mp.find(str[index])==mp.end())        
             ret = count(str[index]);
        else            
            ret = mp[str[index]];        
        
        int first = 0;
        int second = 0;
        if(ret.first <= target.first && ret.second <= target.second ){
            first = check(str,pair<int,int>{target.first-ret.first, target.second-ret.second}, index+1) + 1;
        }
        
        second = check(str, target, index+1);
        mp2[{{target.first, target.second},index}] = max(first, second);        
        return mp2[{{target.first, target.second},index}];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        return check(strs,pair<int,int>{m,n}, 0);
    }
};
