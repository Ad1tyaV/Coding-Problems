/*
  https://leetcode.com/problems/zigzag-conversion/
*/

class Solution {
public:

    string convert(string s, int numRows) {
         
        int stringPointer = 0;        
        vector<char> ans[numRows];        
        int rowPointer = 0;
        int colPointer = 0;
        
        string total;
        
        while(stringPointer<s.size()){
            
          
            while(stringPointer<s.size() && rowPointer<=numRows-1){         
                
                ans[rowPointer].push_back(s[stringPointer]);                
                rowPointer++;
                stringPointer++;
                
            }
            
            rowPointer = numRows - 2;
            colPointer++;
            
            while(stringPointer<s.size() && rowPointer>0){
      
                ans[rowPointer].push_back(s[stringPointer]);
                                
                rowPointer--;
                colPointer++;
                stringPointer++;
                
            }            
            rowPointer = 0;            
 
        }
        
        for(int index = 0; index<numRows; index++){

            for(char temp: ans[index]){             
                total.push_back(temp);
            }

        }
        
        
        
        
        return total;

                
        
    }
};
