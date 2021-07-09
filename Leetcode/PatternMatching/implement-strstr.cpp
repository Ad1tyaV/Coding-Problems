/*

https://leetcode.com/problems/implement-strstr/

Using KMP Algorithm

Space Complexity  = O(M) where M is the length of subpattern
Time Complexity = O(N + M) where N is the length of main Pattern

*/

class Solution {
public:
    
    vector<int> prefixTable(string needle){
        
        vector<int> prefix_table(needle.size(), -1);
                        
        int pivot = 0;
        int pointer = 1;
        
        while(pointer<needle.size()){
            
            if(needle[pivot]==needle[pointer]){
                prefix_table[pointer] = pivot;
                pivot++;
                pointer++;
            }
            else{
                
                if(pivot>0){
                    pivot = prefix_table[pivot-1] + 1;
                }
                else{
                    pointer++;
                }
                
                
            }
            
        }
        
        // for(int k:prefix_table){
        //     cout<<k<<"\t";
        // }
        // cout<<endl;
        
        return prefix_table;
    }
    
    int strStr(string haystack, string needle) {
     
       if(!needle.size())
           return 0;
        
        vector<int> prefix_table = prefixTable(needle);
        
        
        int second = 0;
        int start = 0;
        
        while(start<haystack.size() && second<needle.size()){
            
            
            if(haystack[start]==needle[second]){
                while(start<haystack.size() && second<needle.size() && (haystack[start]==needle[second])){
                    start++;
                    second++;
                }                
                if(second==needle.size()){
                    return start-second;
                }
            }
            else{
                
                if(second>0){
                    second = prefix_table[second-1] + 1;                    
                }
                else{
                    second = 0;
                    start++;
                }
                
            }
        }
        
        
        return -1;
    }
};
