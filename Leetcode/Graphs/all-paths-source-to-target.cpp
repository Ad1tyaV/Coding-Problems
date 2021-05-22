/*

https://leetcode.com/problems/all-paths-from-source-to-target/

*/
class Solution {
public:
    
    vector<vector<int>> ans;
    
    void getPath(vector<vector<int>> graph, int src, int destination, vector<int> track){
        
        track.push_back(src);
        
        
        if(src == destination){
            
            ans.push_back(track);
            
        }
            
            
        for(int neighbour:graph[src]){
                        
            getPath(graph, neighbour, destination, track);
            
        }
                        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
                        
        getPath(graph, 0, graph.size()-1, {});        
        
        return ans;
        
    }
};
