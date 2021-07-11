/*

  https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

*/

set<string> paths;
vector<vector<bool>> visited;
bool solutionExists;

void recurse(int x, int y, int n, string path, vector<vector<int>> board){
        
    
    if(x==n-1 && y==n-1){
        // paths.push_back(path);
        paths.insert(path);
        solutionExists = true;
        return;
    }
    
    unordered_map<char, pair<int, int>> directions;
    directions['R'] = {0, 1};
    directions['L'] = {0, -1};
    directions['U'] = {-1, 0};
    directions['D'] = {1, 0};
    
    for(auto iterator = directions.begin(); iterator!=directions.end(); iterator++){
        
        
        pair<int, int> direction = iterator->second;
        
        int x_offset = direction.first;
        int y_offset = direction.second;
        
        int new_X = x+x_offset;
        int new_Y = y+y_offset;
        
        if(new_X <0 || new_X >=n )
            continue;
            
        if(new_Y<0 || new_Y>=n)
            continue;
        
        if(board[new_X][new_Y]!=0 && !visited[new_X][new_Y]){
            path.push_back(iterator->first);
            visited[new_X][new_Y] = true;
            recurse(new_X, new_Y, n, path, board);
            visited[new_X][new_Y] = false;
            path.pop_back();
        }
        else
            continue;
        
    }
    
    return;
    
}

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        if(m[0][0]==0)
            return {"-1"};
        paths = {};
        visited[0][0] = true;
        solutionExists = false;
        recurse(0, 0, n, "", m);
        
        if(!solutionExists)
            return {"-1"};
        
        return {paths.begin(), paths.end()};
    }
};
