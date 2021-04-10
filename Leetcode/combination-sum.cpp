class Solution {
public:    
    vector<vector<int>> res;
	void findSolution(vector<int> candidates,int target, int index, vector<int> track){
        
        if(target==0){               
            res.push_back(track);            
            return;
        }
        
        if(target<0)
            return;
        
        
        int n = candidates.size();
        for(int i=index;i<n;i++){
            track.push_back(candidates[i]);                   
            findSolution(candidates,target-candidates[i], i, track);
            track.pop_back();
        }
       
	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
				 
    //sort(candidates.begin(), candidates.end());
		findSolution(candidates, target, 0, {});        
		return res;
    }
};
