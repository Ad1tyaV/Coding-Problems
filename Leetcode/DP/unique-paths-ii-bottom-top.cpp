// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
        
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                
        int rc = obstacleGrid.size();
        int cc = obstacleGrid[0].size();
        
        if(obstacleGrid[rc-1][cc-1])
            return 0;                
        
        vector<vector<unsigned long int>> dp(rc+1, vector<unsigned long int>(cc+1,0));
        
        dp[rc-1][cc-1] = 1;
                
        for(int i=rc-1;i>=0;i--){
            
            for(int j=cc-1;j>=0;j--){
                
               if(i==rc-1 && j==cc-1)
                   continue;
               
                if(obstacleGrid[i][j])
                    continue;
                
               dp[i][j] = dp[i][j+1] + dp[i+1][j];                
                
            }
            
        }
       
        return dp[0][0];
                
    }
};
