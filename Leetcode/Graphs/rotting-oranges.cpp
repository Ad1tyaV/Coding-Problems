/*

  https://leetcode.com/problems/rotting-oranges/
  

*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<pair<int, int>> rottenOrangesTrack;        
        
        int row = grid.size();
        int col = grid[0].size();
        
        int freshOranges = 0;
        int minutesElapsed = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                
                if(grid[i][j]==2){
                    rottenOrangesTrack.push_back({i, j});
                }
                else if(grid[i][j]==1){
                    freshOranges++;
                }
                
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
                
        
        while(freshOranges>0 && rottenOrangesTrack.size()){
            
            vector<pair<int, int>> newRottenOrangesTrack;
            
            
            while(rottenOrangesTrack.size()){
                
                pair<int, int> startPoint = *rottenOrangesTrack.begin();
                rottenOrangesTrack.erase(rottenOrangesTrack.begin());
                
                for(pair<int, int> direction: directions){
                    
                    int new_X = startPoint.first+direction.first;
                    int new_Y = startPoint.second+direction.second;
                    
                    if(new_X>=row || new_X<0) //Out of Row Bounds
                        continue;                    
                    if(new_Y>=col || new_Y<0) //Out of Col Bounds
                        continue;
                    
                    if(grid[new_X][new_Y]==1){
                        grid[new_X][new_Y] = 2;
                        freshOranges--;
                        newRottenOrangesTrack.push_back({new_X, new_Y});
                    }
                    
                    
                }
            }
            
            rottenOrangesTrack = newRottenOrangesTrack;                                    
            minutesElapsed++;
        }
        
        
        return freshOranges!=0?-1:minutesElapsed;
    }
};
