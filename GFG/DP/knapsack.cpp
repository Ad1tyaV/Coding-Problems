class Solution
{
    public:
    
    map<pair<int, int>, int> cache;
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n, int pointer=0) { 
       
       if(pointer==n)
        return 0;
       
       if(cache.find({pointer, W})!=cache.end())
        return cache[{pointer, W}];
       
       if(wt[pointer]>W){
           return knapSack(W, wt, val, n, pointer+1);
       }
       
       cache[{pointer, W}] = max(knapSack(W, wt, val, n, pointer+1), val[pointer] + knapSack(W-wt[pointer], wt, val, n, pointer+1));
       
       return cache[{pointer, W}];
       
    }
};
