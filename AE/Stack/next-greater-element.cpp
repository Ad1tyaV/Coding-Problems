#include <vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
  
	vector<int> ans(array.size(), -1);
	stack<int> st;
	vector<bool> updated(array.size(), false);
	
	//First Pass
	for(int i = array.size()-1; i>=0; i--){
		
		if(st.empty()){
			st.push(array[i]);			
		}
		else{
			
			while(array[i]>=st.top()){
				st.pop();
				if(st.empty()){
					st.push(array[i]);
					ans[i] = -1;
					break;
				}
			}
			if(!st.empty()){
				if(array[i]<st.top()){
					updated[i] = true;
					ans[i] = st.top();	
				}
				
				st.push(array[i]);
			}			
			
		}
		
	}
	
	//Second Pass
	for(int i = array.size()-1; i>=0; i--){
		
		if(ans[i]==-1 && !updated[i]){			
			if(st.empty())
				continue;
			
			while(array[i]>=st.top()){
				
				st.pop();
				if(st.empty()){
					ans[i] = -1;
					break;
				}
			}
			if(st.empty()){
				continue;
			}
			else{
				if(array[i]<st.top())
					ans[i] = st.top();
				
				st.push(array[i]);
			}
			
		}
		
	}
	
	// cout<<"st.size()="<<st.size()<<" =>"<<st.top()<<endl;
  return ans;
}
