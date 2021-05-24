#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int WHITE = 0;
int GREY = 1;
int BLACK = 2;


int countCycleSize(unordered_map<int, vector<int>> mp){
    
    stack<int> vectorStack;
    
    int total_cycles = 0;
    int cycles = 0;
    vector<bool> colorMap(mp.size(), WHITE);
    
    for(auto it = mp.begin(); it!=mp.end(); it++){
        
        if(colorMap[it->first]==WHITE){
            
            colorMap[it->first] = GREY;
            vectorStack.push(it->first);
            
            while(!vectorStack.empty()){
                
                int count = 0;
                int top = vectorStack.top();
                
                for(int neighbour : mp[top]){
                                                            
                    if(colorMap[neighbour]==WHITE){
                        cycles++;
                        colorMap[neighbour] = GREY;
                        vectorStack.push(neighbour);
                        break;
                    }
                    else if(colorMap[neighbour]==BLACK){
                        count++;
                    }
                    else{
                        // Cycle exists!
                        total_cycles += (cycles+1);
                        total_cycles -=1;
                        // cycle.push_back(cycles+1);
                        cycles = 0;
                        vectorStack = stack<int>();
                        break;
                    }
                                        
                }
                
                if(count==mp[top].size()) // If all children are visited, pop off!
                    if(vectorStack.size())
                        vectorStack.pop();
                
            }
            
        }
        
    }
      
    
    return total_cycles;
}


int minimumSwaps(vector<int> arr) {

    unordered_map<int, vector<int>> adjList;
    
    for(int i=0; i<arr.size(); i++){                
        if(arr[i]!=i+1){            
            adjList[arr[i]].push_back(arr[arr[i]-1]);            
        }        
    }
    
    return countCycleSize(adjList);

}

int main(){

    cout<<"Minimum Swaps for {7,1,3,2,4,5,6} are = "<<minimumSwaps({7,1,3,2,4,5,6})<<endl;
    cout<<"Minimum Swaps for {4, 3, 2, 1} are = "<<minimumSwaps({4, 3, 2, 1})<<endl;
    cout<<"Minimum Swaps for {2, 4, 5, 1, 3} are = "<<minimumSwaps({2, 4, 5, 1, 3})<<endl;
    cout<<"Minimum Swaps for {1 3 5 2 4 6 7} are = "<<minimumSwaps({1,3,5,2,4,6,7})<<endl;

    return 0;
}
