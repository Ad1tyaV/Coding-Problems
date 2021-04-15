class Solution {
public:
    map<pair<int,int>, int> mp;
    int findSol(vector<int> coins, int amount, int index , int track){
                      
        if(mp.find({amount, track})!=mp.end())
            return mp[{amount, track}];
        
        if(amount==0){            
            return track;
        }
        
        if(amount<0)
            return INT_MAX;
        
        if(index>=coins.size())
            return INT_MAX;
        
        int a = findSol(coins, amount-coins[index], index, track+1);
        int b = findSol(coins, amount, index+1, track);
                        
        return mp[{amount, min(a,b)}] = min(a,b);
        //return min(a, b);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int ans = findSol(coins, amount, 0, 0);                
        return ans==INT_MAX?-1:ans;
        
    }
};
