/*

https://leetcode.com/problems/valid-palindrome/

*/
class Solution {
public:
    
    bool isAlphaNumeric(char element){
        
        if(element==' ')
            return false;
        
        int asci = (int)element;
        
        if(asci >=65 && asci <= 90){ // UpperCase
            return true;
        }
        
        if(asci >= 97 && asci <= 122){ //LowerCase
            return true;
        }
        
        if(asci >= 48 && asci <= 57) //Numbers
            return true;
        
        return false;
    }
    
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.length()-1;
        
        while(left<=right){
            
            if(left==right)
                break;
            
            bool leftVal = isAlphaNumeric(s[left]);
            bool rightVal = isAlphaNumeric(s[right]);
                        
            if(leftVal && rightVal){
                
               
                
                if(s[left]>=97 && s[left]<=122){
                    s[left]-=32;
                }
                if(s[right]>=97 && s[right]<=122)
                    s[right]-=32;
                
                if(s[left]!=s[right]){                    
                    return false;
                }
                
                left++;
                right--;
                continue;
            }
                
            if(!leftVal)
                left++;
            if(!rightVal)
                right--;
            
    
            
        }
        
        return true;
    }
};
