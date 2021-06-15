/*

  https://leetcode.com/problems/longest-substring-without-repeating-characters/
  Longest Substring Without Repeating Characters


*/

int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0 || s.length()==1)
            return s.length();
        
        if(s.length()==2)
            return s[0]==s[1]?1:2;
                
        
        int start = 0;
        int end = 0;
        // vector<int> counter(26, 1);
        unordered_map<char, int> counter;
        int longestLength = INT_MIN;
        
        
        while(end<s.length()){
            
            if(counter.find(s[end])==counter.end())
                counter[s[end]] = 1;
            
            counter[s[end]]--;
            // cout<<"s[end]="<<s[end]<<" counter[s[end]]="<<counter[s[end]]<<endl;
            
            if(counter[s[end]]<0){
                // cout<<"inside if=>"<<start<<","<<end<<endl;
                while(start<end && s[start]!=s[end]){
                    counter[s[start]]++;
                    // cout<<"start="<<start<<" s[start]="<<s[start]<<" and counter[s[start]] = "<<counter[s[start]]<<endl;
                    start++;                    
                }
                counter[s[start]]++;
                start++;                
            }
            
            // cout<<start<<","<<end<<"=>"<<counter.size()<<endl;
            
            // printMap(counter);
            
            longestLength = max(longestLength, end-start+1);
            
            end++;
                        
        }
        
        return longestLength!=INT_MIN?longestLength:1;
        
    }
};
