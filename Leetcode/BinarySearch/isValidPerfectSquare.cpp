/*
https://leetcode.com/problems/valid-perfect-square/
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1)
            return 1;
        
        unsigned long int leftBound = 1;
        unsigned long int rightBound = (num/2)+1;
        
        while(leftBound<rightBound){
            
            unsigned long int mid = (leftBound+rightBound)/2;
            unsigned long int square = (mid*mid);
            
            if(num==square)
                return true;
            
            if(num>square){
                leftBound = mid+1;
            }
            else{
                rightBound = mid;
            }
            
        }
        
        return false;
    }
};
