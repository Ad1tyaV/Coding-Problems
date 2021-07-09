/*
https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/
*/
  int findLongestConseqSubseq(int arr[], int N){
        
        if(N==1)
            return 1;
        
        set<int> element_set;
        int max_length = 1;
        
        for(int index = 0; index<N; index++)
            element_set.insert(arr[index]);
        
        vector<int> elements(element_set.begin(), element_set.end());
        
        
        int length = 1;
        
        for(int i=1; i<elements.size(); i++){
            
            if((elements[i]-elements[i-1])==1){
                length++;        
            }
            else{
                max_length = max(max_length, length);
                length = 1;
            }
            
        }
        return max(max_length, length);
    }
};
