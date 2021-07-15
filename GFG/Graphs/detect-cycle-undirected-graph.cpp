/*
  
  https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph
  Detect cycle in an undirected graph
  
*/

class Solution 
{
    public:
    vector<int> parents;
    
    
    set<pair<int, int>> visited;
    
    int findParent(int vertex){
        
        if(parents[vertex]<0)
            return vertex;
        
        return findParent(parents[vertex]);
        
    }
    
    bool unify(int source, int destination){
        
        int sourceParent = findParent(source);
        int destinationParent = findParent(destination);
        
   
        
        if(sourceParent==destinationParent)
            return true;
        
        if(parents[sourceParent]<=parents[destinationParent]){
            
            parents[sourceParent] += parents[destinationParent];
            parents[destinationParent] = sourceParent;
            
        }
        else{
            
            parents[destinationParent] += parents[sourceParent];
            parents[sourceParent] = destinationParent;
            
        }
        
        return false;
        
    }
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[]){
	    
	   
	    parents = vector<int>(V, -1);
	    visited = vector<vector<bool>>(V, vector<bool>(V, false));
	   
	    
	    for(int vertex=0; vertex < V; vertex++){
	        
	        int source = vertex;
	        
	        for(int destination: adj[source]){
	            
	            if(visited.find({source, destination})==visited.end()){
	                
	                visited.insert({source, destination});
	                visited.insert({destination, source});
    	            if(unify(source, destination))
    	                return true;
	            }

	            
	        }
	        
	        
	    }
	    
	    
	   return false;
	}
};
