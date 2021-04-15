class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
       unsigned long int *dp;
       dp = new unsigned long int[amount+1];
        
        for(int i=1;i<=amount;i++){
            dp[i] = INT_MAX;
        }
        
       dp[0] = 0;
        
       for(int i=1;i<=amount;i++){           
           for(int coin:coins){
            
               if(coin<=i){
                   dp[i] = min(dp[i-coin]+1, dp[i]);
               }
               
           }           
       }
      
        
        return dp[amount]==INT_MAX?-1:dp[amount];        
    }
};
