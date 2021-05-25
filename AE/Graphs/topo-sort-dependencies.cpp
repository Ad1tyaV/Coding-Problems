/*
https://www.algoexpert.io/questions/Topological%20Sort
*/

#include <vector>
#include<stack>
using namespace std;

int WHITE = 0;
int GREY = 1;
int BLACK = 2;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // Write your code here.
	
	unordered_map<int, vector<int>> adjacencyList;
	vector<int> topologicalOrder;
	unordered_map<int, bool> visited;
	vector<int> colorMap(jobs.size(), WHITE);
	stack<int> vertexStack;
	
	for(vector<int> dependency : deps){		
		cout<<dependency[0]<<" "<<dependency[1]<<endl;
		adjacencyList[dependency[0]].push_back(dependency[1]);		
	}
	
	for(auto it = jobs.begin(); it!=jobs.end(); it++){				
		
		if(!visited[*it]){
			
			colorMap[*it] = GREY;
			
			vertexStack.push(*it);
			visited[*it] = true;
			
			while(!vertexStack.empty()){
				
				int top = vertexStack.top();
				int visitedChildren = 0;
				//Check Neighbours
				for(int neighbour : adjacencyList[top]){
					
					if(colorMap[neighbour]==GREY)
						return {};
					
					if(!visited[neighbour]){
						visited[neighbour] = true;
						colorMap[neighbour] = GREY;
						vertexStack.push(neighbour);
						break;
					}
					else{
						visitedChildren++;
					}
					
				}
				if(visitedChildren == adjacencyList[top].size()){
					topologicalOrder.push_back(top);
					colorMap[top] = BLACK;
					vertexStack.pop();
				}
				
			}
			
		}
		
	}
	reverse(topologicalOrder.begin(), topologicalOrder.end());
	
  return topologicalOrder;
}
