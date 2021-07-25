/*
https://leetcode.com/problems/perfect-squares/
*/
class Solution {
public:        
    
    int numSquares(int n) {
        
        vector<int> check;
        
        for(int number = 1; number*number<=n; number++){            
            check.push_back(number*number);            
        }
        
        
        unsigned int* dp;
        dp = new unsigned int[n+1];
        
        dp[0] = 0;
        
        for(int index = 1; index<=n; index++){
            dp[index] = INT_MAX;
        }
        
        
        for(int index = 1; index<=n; index++){            
            for(int value: check){
                
                if(value<=index){                    
                    dp[index] = min(dp[index], dp[index-value]+1);                    
                }
                                
            }            
        }
        
     
        
        return dp[n];
        
    }
};
