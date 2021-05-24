/*

https://www.hackerrank.com/challenges/minimum-swaps-2/problem?isFullScreen=true

Terminal Version - https://github.com/Ad1tyaV/Coding-Problems/blob/main/TerminalVersion/minimum-number-of-swaps.cpp

*/
#include <bits/stdc++.h>

using namespace std;

int WHITE = 0;
int GREY = 1;
int BLACK = 2;

//DFS
int countCycleSize(unordered_map<int, vector<int>> mp){
    
    stack<int> vectorStack;
    
    int total_cycles = 0;
    int cycles = 0;
    vector<bool> colorMap(mp.size(), WHITE);
    
    for(auto it = mp.begin(); it!=mp.end(); it++){
        
        if(colorMap[it->first]==WHITE){
            
            vectorStack.push(it->first);
            cycles++;
            colorMap[it->first] = GREY;
            
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
                        total_cycles += cycles;
                        total_cycles -= 1;
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

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {

    unordered_map<int, vector<int>> adjList;
    
    for(int i=0; i<arr.size(); i++){                
        if(arr[i]!=i+1){            
            adjList[arr[i]].push_back(arr[arr[i]-1]);            
        }        
    }
    
    return countCycleSize(adjList);

}
