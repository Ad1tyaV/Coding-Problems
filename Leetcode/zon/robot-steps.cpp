/*

https://leetcode.com/problems/robot-bounded-in-circle

*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
                
        int direction = 0;   
        int backupInitialDirection = direction;
        pair<int, int> position = {0,0};
                     
        
        for(int i=0;i<instructions.length();i++){
            
            switch(instructions[i]){
                    
                case 'L':{
                    direction--;
                    if(direction<0)
                        direction = 3;
                    break;
                }
                case 'R':{                    
                    direction++;
                    if(direction>3)
                        direction = 0;
                    break;
                }
                case 'G':{                    
                   
                    if(direction==0)
                        position.second++;
                    else if(direction==1){
                        position.first++;
                    }
                    else if(direction==2){
                        position.second--;
                    }
                    else if(direction==3){
                        position.first--;
                    }
                    
                   
                }
                    
                    
            }
            
        }
        
        
        if((direction != backupInitialDirection)|| (position.first==0 && position.second==0))
            return true;
            
        return false;
    }
};
