/*
  
  https://leetcode.com/problems/number-of-provinces/
  
*/

class Solution {
public:
    
    vector<int> parentVector;
    
    int findParent(int index){
        
        if(parentVector[index]<0)
            return index;
        
        return findParent(parentVector[index]);
        
    }
    
    void unionNodes(int fromNode, int toNode){
        
        int fromNodeParent = findParent(fromNode);
        int toNodeParent = findParent(toNode);
        
        if(fromNodeParent!=toNodeParent){
            
            
            if(parentVector[fromNodeParent] >= parentVector[toNodeParent]){
                
                parentVector[fromNodeParent]+=parentVector[toNodeParent];
                parentVector[toNodeParent] = fromNodeParent;
                
            }
            else{
                
                parentVector[toNodeParent] += parentVector[fromNodeParent];
                parentVector[fromNodeParent] = toNodeParent;
                
            }
            
        }
        
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        parentVector = vector<int>(isConnected.size()+1, -1);
        
        for(int row = 0; row<isConnected.size(); row++){
            
            for(int col=0; col<isConnected[0].size(); col++){
                
                if(row==col)
                    continue;
                
                if(isConnected[row][col]){
                    
                    unionNodes(row+1, col+1);
                    
                }
                
            }
            
        }
        
        int number_of_provinces = 0;
        
        for(int i=1; i<parentVector.size(); i++){
            
            if(parentVector[i]<0)
                number_of_provinces++;            
            
        }
        
        return number_of_provinces;
    }
};
