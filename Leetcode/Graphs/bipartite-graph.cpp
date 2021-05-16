/*
  https://leetcode.com/problems/is-graph-bipartite/
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        if(graph.size()==1)
            return 1;
        
        int n = graph.size();
        
        queue<int> q;
        vector<bool> visited(n, 0);        
        map<int, int> color_map;
        
        
       
        for(int i=0;i<n;i++){
            
            if(!visited[i]){                
                q.push(i);
                visited[i] = true;
                color_map[i] = 1;
                
                while(!q.empty()){
                    
                    int front = q.front();
                    q.pop();
                    
                    //Check neighbours
                    for(int num:graph[front]){
                        
                        if(color_map[num]==0){                            
                            color_map[num] = color_map[front]==1?2:1;
                        }
                        else{
                            if(color_map[front]==color_map[num])
                                return false;                            
                        }
                        
                        if(!visited[num]){  
                            visited[num] = true;
                            q.push(num);                            
                        }
                        
                    }
                    
                    
                }
                
                
            }
        
        }
               
        return true;
    }
};
