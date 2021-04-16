class Solution {
public:
    
    // https://leetcode.com/problems/minimum-cost-for-tickets
    
    //Linear Search
//     int search(vector<int> days, int target){
        
//         for(int i=0;i<days.size();i++){            
//             if(days[i]>target) return (i);            
//         }
//         cout<<"Never here"<<endl;
//         return -1;
//     }
    //Binary Search
    int search(vector<int> days, int target){
        
        int l = 0;
        int r = days.size()-1;
        int current = INT_MIN;
        int currentIndex = -1;
        
        while(l<=r){
            
            int mid = (l+r)/2;                        
            
            if(target == days[mid]){
                l = mid+1;
            }
            else if(target > days[mid]){                
                l = mid+1;                
            }
            else{
                if(current==INT_MIN){                    
                    current = days[mid];
                    currentIndex = mid;                    
                }
                else if(days[mid]<current){
                    current = days[mid];
                    currentIndex = mid;
                }
                r = mid-1;
            }
            
        }
        return currentIndex;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> mem;        
        mem.assign(days.size()+1, INT_MAX-500);
        //mem[0] = costs[0];
        //mem[0] = findMin(costs);        
        
        mem[0] = min(min(costs[0], costs[1]), costs[2]);
        
        
        
        
        for(int i=1;i<days.size();i++){
           
           int a = mem[i-1] + costs[0];
           int b,c;
           if(days[i]-7<=0)               
               mem[i] = min(costs[1], a);
           else{
                                             
               //int ind = search(days, days[i]-7,0, days.size()-1);                          
               int ind = search(days, days[i]-7);                          
               // cout<<"From 7 : index="<<ind<<" days[i] = "<<days[i]<<endl;
               if(ind>0)
                mem[i] = min(mem[ind-1] + costs[1], a);
               else{
                  mem[i]  = min(costs[1], a);
               }
                //mem[i] = min(mem[ind] + costs[1], a);               
           } 
           if(days[i]-30<=0) {
               //mem[i] = min(mem[i-1] + costs[2], mem[i]);
               
               mem[i] = min(costs[2], mem[i]);
           }
           else{                    
               
               //int ind = search(days, days[i]-30, 0, days.size()-1);     
               int ind = search(days, days[i]-30);
               // cout<<"From 30 : index="<<ind<<endl;
               if(ind>0)
                mem[i] = min(mem[ind-1] + costs[2], mem[i]);
               else
                mem[i] = min(mem[ind]+ costs[2], mem[i]);
           }
               
            
        }
        
        // for(int m:mem){
        //     cout<<"mem="<<m<<"\t";
        // }
        // cout<<endl;
        return mem[days.size()-1];
        
    }
};
