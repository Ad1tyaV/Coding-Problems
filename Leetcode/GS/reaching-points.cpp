/*

https://leetcode.com/problems/reaching-points/
Solution by - https://www.youtube.com/watch?v=tPr5Uae6Drc
*/

class Solution {
public:
    
    bool reachingPoints(int sx, int sy, int tx, int ty) {
              
        if((sx==1 && tx==1) || (sy==1 && ty==1))
            return true;
        
        
        while(!((sx==tx) || (ty==sy))){
              
            if(max(tx, ty)%min(tx, ty)==0)
                break;
                        
            if(tx>ty){
                if(tx%ty!=0)
                    tx = tx%ty;
            }
            else if(tx<ty){
                if(ty%tx!=0)
                    ty = ty%tx;
            }
            
            if((sx>tx) || (sy>ty))
                break;
            
            if(ty==tx)
                break;
            
        }
        if(sx==tx && sy==ty)
            return true;
        
        if(sx==tx){
            if(ty>sy){
                if(((ty-sy)%sx)==0)
                    return true;
            }
            else 
                return false;            
        }
        
        if(sy==ty){
            if(tx>sx){
                if((tx-sx)%sy==0)
                    return true;
            }  
            else
                return false;           
        }                
        
        
        return false;
    }
};

