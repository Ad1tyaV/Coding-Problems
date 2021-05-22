/*

https://leetcode.com/problems/course-schedule/

*/

class Solution {
public:
    
    int WHITE = 0;
    int GREY = 1;
    int BLACK = 2;       
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        if(numCourses==0 || numCourses==1 || prerequisites.size()==0)
            return true;
        
        vector<int> colors(numCourses, WHITE);
        
        vector<vector<int>> adjList(numCourses, vector<int>());
        
        
        for(int i=0; i<prerequisites.size(); i++){            
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);            
        }
        stack<int> stackCourses;
        for(int course = 0; course < numCourses; course++){
            
            if(colors[course]==WHITE){
                
                colors[course] = GREY;
                stackCourses.push(course);
                while(!stackCourses.empty()){
                    
                    int top = stackCourses.top();
                    int count = 0;
                    
                    for(int neighbour:adjList[top]){
                        
                        if(colors[neighbour]==GREY)
                            return false;
                        
                        if(colors[neighbour]==BLACK){
                            count++;
                        }
                        else{
                            stackCourses.push(neighbour);
                            colors[neighbour] = GREY;
                            break;
                        }
                        
                    }
                    
                    if(count==adjList[top].size()){
                        stackCourses.pop();
                        colors[top] = BLACK;
                    }
                    
                }
                
            }
            
        }
        return true;
    }
};
