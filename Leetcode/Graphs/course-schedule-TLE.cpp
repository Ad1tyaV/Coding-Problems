class Solution {
public:
    
    int WHITE = 0;
    int GREY = 1;
    int BLACK = 2;
    
    bool dfs(int course, vector<int> &colors,vector<vector<int>> courses){
        
        colors[course] = GREY;
        
        for(int neighbour:courses[course]){
            
            if(colors[neighbour]==GREY)
                return true;
            
            if(colors[neighbour]==WHITE){
                bool isCycle = dfs(neighbour, colors, courses);
                if(isCycle)
                    return true;
            }
            
        }
        
        colors[course] = BLACK;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        if(numCourses==0 || numCourses==1 || prerequisites.size()==0)
            return true;
        
        vector<int> colors(numCourses, WHITE);
        
        vector<vector<int>> adjList(numCourses, vector<int>());
        
        
        for(int i=0; i<prerequisites.size(); i++){            
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);            
        }
        
        for(int course = 0; course < numCourses; course++){
            
            if(colors[course]==WHITE){
                
                bool ans = dfs(course, colors, adjList);
                if(ans) // there is a cycle
                    return false;
                
            }
            
        }
        return true;
    }
};
