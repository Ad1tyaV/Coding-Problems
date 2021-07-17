/*
https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1/
*/

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital){
        
        vector<pair<int, int>> infectedPatients;
        
        int safePatients = 0;
        
        for(int row = 0; row<hospital.size(); row++){
            for(int col = 0; col<hospital[0].size(); col++){
                if(hospital[row][col]==2){
                    infectedPatients.push_back({ row, col });
                }
                else if(hospital[row][col]==1){
                    
                    safePatients++;
                }
            }
        }
        
        int time_taken = 0;
        
        while(safePatients>0 && infectedPatients.size()>0){
        
            vector<pair<int, int>> fresh_infections;
        
            for(pair<int, int> infectedWard: infectedPatients){
                
                int x = infectedWard.first;
                int y = infectedWard.second;
                queue<pair<int, int>> patientQueue;
                
                patientQueue.push({x, y});
                
                while(!patientQueue.empty()){
                    
                    pair<int, int> front = patientQueue.front();
                    patientQueue.pop();
                    int current_x = front.first;
                    int current_y = front.second;
                    
                    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                    
                    for(pair<int, int> direction: directions){
                        
                        int new_x = current_x + direction.first;
                        int new_y = current_y + direction.second;
                        
                        if(new_x <0 || new_x >=hospital.size())
                            continue;
                        if(new_y<0 || new_y>=hospital[0].size())
                            continue;
                            
                        if(hospital[new_x][new_y]==1){
                            hospital[new_x][new_y]=2;
                            fresh_infections.push_back({new_x, new_y});
                            safePatients--;
                        }
                        
                    }
                    
                    
                    
                }
  
            }
            
            infectedPatients = fresh_infections;
            
            time_taken++;
        
        }
      
        return safePatients==0?time_taken:-1;
        
    }
};
