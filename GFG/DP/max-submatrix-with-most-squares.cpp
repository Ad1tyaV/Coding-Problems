/*
https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/
*/

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        vector<vector<int>> check(n+1, vector<int>(m+1, 0));
        int maximum_squares = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(mat[i-1][j-1]){
                    check[i][j] = min(check[i-1][j], min(check[i][j-1], check[i-1][j-1])) + 1;
                    maximum_squares = max(maximum_squares, check[i][j]);
                }
                
                
            }
        }
        
        
        return maximum_squares;
    }
};
