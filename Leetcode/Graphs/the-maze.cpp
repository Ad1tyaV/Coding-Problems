/*
https://leetcode.com/problems/the-maze
*/
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        queue<pair<int, int>> q; 
        map<pair<int, int>, bool> visited;
        q.push({start[0], start[1]});
        visited[{start[0], start[1]}] = true;
        
        
        while(q.size()){
                                    
            pair<int, int> xy = q.front();
            q.pop();
            
            if(xy.first==destination[0] && xy.second==destination[1])
                return true;
            
            pair<int, int> temp;
            temp = xy;
            //Go up till we hit wall
            int down = 1;
            while(xy.first-down>=0 && maze[xy.first-down][xy.second]!=1 && xy.second>=0 && xy.second<maze[0].size()){
                down++;
            }
            if(!visited[{xy.first-(down-1), xy.second}]){
                q.push({xy.first-(down-1), xy.second});
                visited[{xy.first-(down-1), xy.second}] = true;
            }
            
            xy = temp;
            
            // Go down till we hit
            int up = 1;
            while(xy.first+up<maze.size() && maze[xy.first+up][xy.second]!=1 && xy.second>=0 && xy.second<maze[0].size()){
                up++;
            }      
            if(!visited[{xy.first+(up-1), xy.second}]){
                visited[{xy.first+(up-1), xy.second}] = true;
                q.push({xy.first+(up-1), xy.second});
            }
                                    
            xy = temp;
            //Go right till we hit wall            
            int right = 1;
            while(xy.second+right<maze[0].size() && maze[xy.first][xy.second+right]!=1 && xy.first>=0 && xy.first<maze.size()){
                right++;
            }   
            if(!visited[{xy.first, xy.second+right-1}]){
                visited[{xy.first, xy.second+right-1}] = true;
                q.push({xy.first, xy.second+right-1});
            }
            
            xy = temp;
            int left = 1;
            //Go left till we hit the wall
            while(xy.second-left>=0 && maze[xy.first][xy.second-left]!=1 && xy.first>=0 && xy.second<maze[0].size()){
                left++;
            }
            if(!visited[{xy.first, xy.second-(left-1)}]){
                visited[{xy.first, xy.second-(left-1)}] = true;
                q.push({xy.first, xy.second-(left-1)});
            }
            
                        
        }
        
        
        return false;
    }
};
