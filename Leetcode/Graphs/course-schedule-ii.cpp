/*
https://leetcode.com/problems/course-schedule-ii/
*/
class Solution {
public:
    
    int WHITE = 0;
    int GREY = 1;
    int BLACK = 2;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> colorMap(numCourses, WHITE);
        vector<bool> visited(numCourses, false);
        vector<int> topologicalOrder;
        
        stack<int> courseStack;
        
        for(vector<int> prerequisite:prerequisites){
            
            adjList[prerequisite[0]].push_back(prerequisite[1]);
            
        }
        
        for(int i=0; i< numCourses; i++){
            
            if(!visited[i]){
                
                visited[i] = true;
                colorMap[i] = GREY;
                courseStack.push(i);
                
                
                while(!courseStack.empty()){
                                        
                    
                    int top = courseStack.top();
                    int visitedNeighbours = 0;    
                    //Check Neighbours
                    for(int neighbour:adjList[top]){
                        
                      
                        if(colorMap[neighbour]==GREY)
                            return {};
                        if(colorMap[neighbour]==WHITE){
                            
                            colorMap[neighbour] = GREY;
                            if(!visited[neighbour]){
                                visited[neighbour] = true;
                                courseStack.push(neighbour);
                                break;
                            }
                            
                        }
                        else                          
                            visitedNeighbours++;                            
                        
                        
                    }
                    
                    if(visitedNeighbours==adjList[top].size()){                        
                        topologicalOrder.push_back(courseStack.top());
                        colorMap[courseStack.top()]=BLACK;
                        courseStack.pop();
                    }
                    
                }
                
            }
            
        }
                
        
        return topologicalOrder;
    }
};
