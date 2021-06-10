#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void displayGraph(vector<vector<int>> graph){

    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[0].size(); j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }

}

int main(){

    vector<vector<int>> graph = {{1,1,1,1,1,1}, 
                                 {1,1,2,2,1,1}, 
                                 {1,1,2,2,1,1}, 
                                 {2,2,2,2,2,2}
                                };
    vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));

    pair<int, int> input = {2, 2};


    //Fill Color 3
    int NEW_COLOR = 3;

    stack<pair<int, int>> vertexStack;
    vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vertexStack.push(input);
    visited[input.first][input.second] = true;    

    while(!vertexStack.empty()){

        pair<int, int> front = vertexStack.top();
        int xPos = front.first;
        int yPos = front.second;
        // cout<<xPos<<","<<yPos<<endl;

        // int visitedNodesCount = 0;
        int unvisitedNodes = 0;
        //Check neighbours
        for(vector<int> direction: directions){

            int verticalOffset = direction[0];
            int horizontalOffset = direction[1];

            // cout<<xPos+verticalOffset<<":"<<yPos+horizontalOffset<<endl;

            if(xPos+verticalOffset>=graph.size() || xPos+verticalOffset<0)
                continue;
            if(yPos+horizontalOffset>=graph[0].size() || yPos+horizontalOffset<0)
                continue;
            
            if(graph[xPos+verticalOffset][yPos+horizontalOffset]==graph[input.first][input.second]){
                if(!visited[xPos+verticalOffset][yPos+horizontalOffset]){

                    vertexStack.push({xPos+verticalOffset,yPos+horizontalOffset});
                    visited[xPos+verticalOffset][yPos+horizontalOffset] = true;
                    graph[xPos+verticalOffset][yPos+horizontalOffset] = NEW_COLOR;
                    unvisitedNodes++;
                    continue;

                }              
            }                        
        }
        if(unvisitedNodes==0){                
            vertexStack.pop();                
        }

    }

    graph[input.first][input.second] = NEW_COLOR;
    displayGraph(graph);

    return 0;
}
/*
Sample Output
$ ./flood-fill

1       1       1       1       1       1
1       1       3       3       1       1
1       1       3       3       1       1
3       3       3       3       3       3

*/
