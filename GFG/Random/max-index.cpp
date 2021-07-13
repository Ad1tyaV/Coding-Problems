/*
https://practice.geeksforgeeks.org/problems/maximum-index-1587115620
*/

class Solution{
    public:
  
    
    struct Cmp{
        
        public:
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            
            if(p1.second==p2.second)
                return p1.first<p2.first;
            
            return p1.second < p2.second;
            
        }
        
    };
    
    int maxIndexDiff(int arr[], int n) { 
        
        
        vector<pair<int, int>> check;
        
        for(int i=0; i<n; i++){
            check.push_back({i, arr[i]});
        }
        
        sort(check.begin(), check.end(), Cmp());
        
        
        int max_diff = INT_MIN;
        int min_value = check[0].first;
        
        for(int index=1; index<n; index++){
            
            max_diff = max(max_diff, check[index].first - min_value);
            min_value = min(min_value, check[index].first);
            
        }
        
        
        return max_diff<0?0:max_diff;
        
    }
    
};
