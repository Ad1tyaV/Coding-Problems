/*

128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        if(nums.size()==2)
            return nums[0]==nums[1]?1:2;
        
        set<int> elements;
        
        for(int num : nums){
            elements.insert(num);
        }        
        
        
        auto iterator = elements.begin();
        int firstElement = *iterator;
        
        int length = 1;
        int max_length = 1;
        
        advance(iterator, 1);
        
        for(; iterator!=elements.end(); iterator++){
                        
            
            if(firstElement+1 == (*iterator)){                
                length++;  
                firstElement = *iterator;
                continue;
            }
            else{
                max_length = max(length, max_length);
                length = 1;
                firstElement = (*iterator);
            }
            
        }
        
        max_length = max(max_length, length);
                
        
        return max_length;
    }
};
