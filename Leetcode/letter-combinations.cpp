class Solution {
public:
    map<int, string> store = {{2,"abc"},{3,"def"},{4,"ghi"},{5, "jkl"},{6, "mno"},{7, "pqrs"},{8, "tuv"},{9, "wxyz"}};
    vector<string> ans;
    void findSolution(string digits, int n, int index, string track){
        
        
        if(index>n) return;
        
        if(index==n){
            ans.push_back(track);
            return;
        }
        
        for(char st:store[digits[index]-'0']){   
            
            track+=st;            
            findSolution(digits, n, index+1,track);    
            track.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        int n = digits.length();
        
        if(!n) return {};
        
        findSolution(digits, n,0, "");
        
        return ans;
    }
};
