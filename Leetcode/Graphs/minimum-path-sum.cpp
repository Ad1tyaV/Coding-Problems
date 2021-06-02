/*
https://leetcode.com/problems/minimum-path-sum/
*/
class Solution {
public:
    
    struct comparator{
        
        public:
            bool operator()(pair<int, pair<int, int>> first_pair, pair<int, pair<int, int>> second_pair){                                    
            return first_pair.first>second_pair.first;            
        }
        
    };
    
   
    int minPathSum(vector<vector<int>>& grid) {
        
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comparator> nextShortestNeighbour; // Storing pairs of distance and their co-ordinates(pair<int, int>{x,y})
        
        bool visited[grid.size()][grid[0].size()];        
        int distances[grid.size()][grid[0].size()];
                
        //Initializing visited to false and distances to max
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                visited[i][j] = false; 
                distances[i][j] = INT_MAX;
            }
        }
        
		//starting from zero
        nextShortestNeighbour.push({grid[0][0], {0, 0}});        
        visited[0][0] = true;
        distances[0][0] = grid[0][0];
        
        
        while(nextShortestNeighbour.size()){
            
            pair<int, pair<int, int>> top = nextShortestNeighbour.top();
            nextShortestNeighbour.pop();
            // visited[{0, 0}] = true;            
            int x = top.second.first;
            int y = top.second.second;
            
            
            //Check Neighbours
            
            //Check bottom
            if(x+1<grid.size() && y<grid[0].size()){                                
                if(!visited[x+1][y]){
                    visited[x+1][y] = true;
                    distances[x+1][y] = min(grid[x+1][y] + top.first, distances[x+1][y]);
                    nextShortestNeighbour.push({distances[x+1][y], {x+1, y}});                                
                }
            }
            
            //Check right
            if(x<grid.size() && y+1<grid[0].size()){                                
                if(!visited[x][y+1]){
                    visited[x][y+1] = true;
                    distances[x][y+1] = min(grid[x][y+1] + top.first, distances[x][y+1]);                
                    nextShortestNeighbour.push({distances[x][y+1], {x, y+1}});                                
                }
            }
            
        }
      
        return distances[grid.size()-1][grid[0].size()-1];
        
    }
};
