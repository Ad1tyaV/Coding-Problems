/*

Breadth First Search - AlgoExpert

*/
#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    
		queue<Node*> q;
		map<Node*, bool> visited;
		q.push(this);
		visited[this] = true;
		
		while(!q.empty()){
			
			Node* temp = q.front();
			q.pop();
			array->push_back(temp->name);
			
			//Check children
			for(Node* kid:temp->children){				
				if(!visited[kid]){
					q.push(kid);
				}				
			}
		}
		
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
