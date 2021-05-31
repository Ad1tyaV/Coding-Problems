#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
*/

using namespace std;

int main(){

    vector<vector<int>> graph = {{0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {2,6}, {2,7}, {3,7}};
    unordered_map<int, vector<int>> adjList;

    for(vector<int> edge:graph){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);                
    }

    queue<pair<int, vector<int>>> q;
    vector<bool> visited(8, false);

    q.push({0,{}});
    int end = 7;
    visited[0] = true;
    while(!q.empty()){

        pair<int, vector<int>> temp = q.front();
        q.pop();

        for(int neighbour:adjList[temp.first]){

            if(neighbour==end){
                cout<<0<<" ";
                for(int path:temp.second){
                    cout<<path<<" ";
                }
                cout<<neighbour<<endl;
                return 0;
            }

            if(!visited[neighbour]){

                visited[neighbour] = true;
                temp.second.push_back(neighbour);
                q.push({neighbour, temp.second});

            }

        }

    }



    return 0;
}
