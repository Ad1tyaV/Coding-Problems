class Solution {
public:
    
//     Recursive Check
//     bool canEat(vector<int> piles, int speed, int hours, int current_pile = 0){                               
//            if(current_pile==piles.size())
//                return true;
                
//             if(hours<=0)
//                 return false;            
        
//            if(piles[current_pile]>0){

//                int remaining = piles[current_pile] - speed;
//                piles[current_pile] = remaining<0?0:remaining;

//                if(piles[current_pile]==0){ //Move On               
//                    return canEat(piles, speed, hours-1, current_pile+1);               
//                }

//                //Re-Eat the current_pile
//                return canEat(piles, speed, hours-1, current_pile);

//            }

//             return canEat(piles, speed, hours-1, current_pile+1);        
//     }
    
    bool canEat(vector<int> piles, int speed, int hours){
        
        int total_time = 0;
        
        for(int index=0; index<piles.size(); index++){            
            total_time += ceil((double)piles[index]/speed);            
        }
        
        return total_time<=hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
                
        int leftBound = 1;
        int rightBound = 1;
        int max_possible = 1;
        
        for(int i=0; i<piles.size(); i++){            
            rightBound = max(rightBound, piles[i]);            
        }


        int min_speed = INT_MAX;        
        
        while(leftBound<rightBound){
                                                
            int mid_speed = leftBound+(rightBound-leftBound)/2;            
            
            if(canEat(piles, mid_speed, h)){
                                                
                          
                min_speed = min(mid_speed, min_speed);                                                
                rightBound = mid_speed;
                                
            }
            else{                
                leftBound = mid_speed + 1;                
            }
            
        }
        
        return leftBound;        
    }
};
