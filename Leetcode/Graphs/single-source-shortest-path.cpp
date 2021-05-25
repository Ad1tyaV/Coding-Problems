/*
  
  https://www.algoexpert.io/questions/Dijkstra's%20Algorithm
  
*/

#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  
	vector<int> distances(edges.size(), INT_MAX);	
	vector<bool> visited(edges.size()+1, false);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, start}); //stores pairs of {distance, vertex}		
	distances[start] = 0;
	
	while(!pq.empty()){
		
		pair<int, int> top = pq.top();
		visited[top.second] = true;
		pq.pop();
		
		for(vector<int> edge:edges[top.second]){
			distances[edge[0]] = min(distances[edge[0]], top.first+edge[1]);
			if(!visited[edge[0]])
				pq.push({distances[edge[0]], edge[0]});			
		}
		
	}
	
	for(int i=0; i<distances.size(); i++){
		if(distances[i]==INT_MAX)
			distances[i] = -1;
	}
	
	
  return distances;
}
