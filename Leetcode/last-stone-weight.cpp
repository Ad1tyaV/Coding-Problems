/*
From LeetCode
https://leetcode.com/problems/last-stone-weight/submissions/
*/
class Solution {
    priority_queue<int> heap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(vector<int>::iterator it=stones.begin();it!=stones.end();++it){
            heap.push(*it);
        }
        
        while(true){
            if(heap.size()==0) break;
            if(heap.size()==1) break;
            int first=heap.top();
            heap.pop();
            int second;
            if(heap.size()>=1){
                second=heap.top();
                heap.pop();
            }    
            
            if(first==second);
            else heap.push(first-second);
            
        }
        
        if(heap.size()==0) return 0;
        return heap.top();
    }
};
