/*
https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1
*/

class Solution{
public:

    bool checkRowCol(vector<vector<int>> matrix, int row, int col){
        
        for(int i=0; i<9; i++){
            
            if(i==row)
                continue;
                
            if(matrix[i][col]==matrix[row][col])
                return false;
            
        }
        
        for(int i=0; i<9; i++){
            
            if(i==col)
                continue;
                
            if(matrix[row][i]==matrix[row][col])
                return false;
            
        }
        
        return true;
        
    }

    bool isValidPos(vector<vector<int>> matrix, int row, int col){
        
        int square_x = (row/3) * 3;
        int square_y = (col/3) * 3;
        
        for(int i=square_x; i<square_x+3; i++){
            
            for(int j=square_y; j<square_y+3; j++){
                
                if(i==row && j==col)
                    continue;
                
                if(matrix[row][col]==matrix[i][j])
                    return false;
                
            }
            
        }
        
        return checkRowCol(matrix, row, col);
        
    }

    int isValid(vector<vector<int>> matrix){
        
        for(int row=0; row<matrix.size(); row++){
            
            for(int col=0; col<matrix[0].size(); col++){
                
                if(matrix[row][col]!=0){
                    
                    if(!isValidPos(matrix, row, col))
                        return 0;
                    
                }
                
                
            }
            
        }
        
        return 1;
        
    }
};
