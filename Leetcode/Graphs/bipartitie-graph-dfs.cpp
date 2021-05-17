class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        int n = graph.size();
        vector<bool> visited(n, false);
        stack<int> st;
        unordered_map<int, int> color_map; // 1-> blue, 2-> red
        
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                
                st.push(i);
                color_map[i] = 1;
                
                while(!st.empty()){
                    
                    int top = st.top();
                    
                    //Check neighbours
                    int count = 0;
                    
                    for(int neighbour:graph[top]){
                                                                            
                        if(color_map[neighbour]==0){
                            color_map[neighbour] = color_map[top]==1?2:1;
                        }
                        else if(color_map[top] == color_map[neighbour]){
                            return false;
                        }
                            
                        if(!visited[neighbour]){    
                            visited[neighbour] = true;
                            st.push(neighbour);
                            break;
                        }
                        else{
                            count++;
                        }                        
                    }
                    
                    if(count==graph[top].size())
                        st.pop();
                    
                    
                }
                
                
            }
            
        }
        
        
        return true;
        
    }
};
