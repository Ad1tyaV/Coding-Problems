#include<stack>
using namespace std;

string reverseWordsInString(string str) {
  
	stack<pair<string, int>> st;
	string ans="";
	string local = "";
	int spaces = 0;
  
	for(int i=0;i<str.size(); i++){
		
		if(str[i]!=' '){
			local+=str[i];
		}
		else{
			if(local!=""){
				st.push({local, spaces});			
				spaces = 0;
			}
			spaces++;
			local = "";			
		}
		
	}
	//For pushing the last word, if it has no following spaces!
	if(local!=""){
		st.push({local, spaces});
		spaces = 0;
	}
  
  // If there are spaces ahead of a word - "    test"
	if(spaces){
		while(spaces){
			ans+=" ";
			spaces--;
		}
	}
	
	while(!st.empty()){
		
		pair<string, int>	temp = st.top();
		//cout<<temp.first<<" "<<temp.second<<endl;
		ans+=temp.first;
    //Unloading spaces onto answer string
		while(temp.second--){
			ans+=" ";
		}
		st.pop();
		
	}
	
	
	
  return ans;
}
