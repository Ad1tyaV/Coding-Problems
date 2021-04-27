/*

  https://leetcode.com/problems/distant-barcodes

*/

class Solution {
public:
    

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
      
        if(barcodes.size()==1 || barcodes.size()==2)
            return barcodes;
        map<int,int> store;
        int initialIndex = 0;
        int ptr = initialIndex;    
        priority_queue<pair<int,int>> pq; //store freq, max
        
        for(int i=0;i<barcodes.size();i++){            
            store[barcodes[i]]++;
        }
               
        for(map<int,int>::iterator it= store.begin();it!=store.end();++it){            
            pq.push({it->second, it->first});            
        }
        
        while(pq.size()){

            pair<int,int> temp = pq.top();
            while(temp.first){
                barcodes[ptr] = temp.second;                
                temp.first--;
                ptr+=2;
                if(ptr>=barcodes.size()){
                    ptr = initialIndex+1;
                }
            }            
            pq.pop();
        }
        
        return barcodes;
        
    }
};
