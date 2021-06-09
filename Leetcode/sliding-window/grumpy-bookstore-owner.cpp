/*

  https://leetcode.com/problems/grumpy-bookstore-owner/

*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int index = 0;
        int satisfied_customers = 0;
        int max_satisfied_customers = INT_MIN;        
             
        
        while(index<minutes){
            satisfied_customers+=customers[index];
            index++;
        }
        for(int m = index; m<customers.size(); m++)
            satisfied_customers += grumpy[m]==0?customers[m]:0;
        
        max_satisfied_customers = satisfied_customers;//max(max_satisfied_customers, satisfied_customers);
        
        for(; index<customers.size(); index++){
            
            if(grumpy[index]==1)
                satisfied_customers+=customers[index];
            
            int exclude_index = index-minutes;
            
            if(grumpy[exclude_index]==1)
                satisfied_customers-=customers[exclude_index];
                        
            max_satisfied_customers = max(max_satisfied_customers, satisfied_customers);
                
            
        }
        
        return max_satisfied_customers;
    }
};
