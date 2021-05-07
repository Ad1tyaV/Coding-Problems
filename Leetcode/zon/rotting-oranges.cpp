/*
https://leetcode.com/problems/rotting-oranges/
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0;i<grid.size();i++){            
            for(int j=0;j<grid[i].size();j++){                
                if(grid[i][j]==2){                       
                    q.push({0, {i,j}});                    
                }                
            }            
        }
        
        int ts = 0;
        
        while(!q.empty()){
            
           
            pair<int, pair<int, int>> temp =  q.front();
            q.pop();
            
            ts = temp.first;
            
            
            
            int x = (temp.second.first);
            int y = (temp.second.second);
            
            
            
            // top
            
            if(x-1>=0){
                
                if(grid[x-1][y]==1){
                    grid[x-1][y] = 2;
                    q.push({ts+1, {x-1, y}});
                }
                
            }
            
            //bottom
            
            if(x+1<grid.size()){
                
                if(grid[x+1][y]==1){
                    grid[x+1][y] = 2;
                    q.push({ts+1, {x+1, y}});
                }
                
            }
            
            //left
            
            if(y-1>=0){
                
                if(grid[x][y-1]==1){
                    grid[x][y-1] = 2;
                    q.push({ts+1, {x, y-1}});
                }
                
            }
            
            //right
            
            if(y+1<grid[0].size()){
                
                if(grid[x][y+1]==1){
                    grid[x][y+1] = 2;
                    q.push({ts+1, {x, y+1}});
                }
                
            }
            
            
        }
        
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){                
                if(grid[i][j]==1)
                    return -1;                
            }
        }
        
        return ts;
    }
};
