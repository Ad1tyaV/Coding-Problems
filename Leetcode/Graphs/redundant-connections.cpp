/*
https://leetcode.com/problems/redundant-connection/
*/
class Solution {
public:
    
    int findParent(vector<int> sets, int element){                
        
        if(sets[element]<0)
            return element;
        
        return findParent(sets, sets[element]);
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> sets(1001, -1);
        
        for(vector<int> edge:edges){
            
            
            int first = findParent(sets, edge[0]);                                    
            int second = findParent(sets, edge[1]);
                 
            
            if(sets[first]==-1 && sets[second]==-1){
                
                sets[edge[0]]=-2;
                sets[edge[1]] = edge[0];
                
            }
            else{
                
                if(first>second){
                    
                    sets[second] = sets[first] + sets[second];
                    sets[first] = second;
                    sets[edge[0]] = second;
                    
                } 
                else if(first<second){
                    
                    sets[first] = sets[first] + sets[second];
                    sets[second] = first;
                    sets[edge[1]] = first;
                }
                else{ //Cycle exists
                    
                    return {edge[0], edge[1]};
                }
                
            }
            
            
        }
        return {};
    }
};
