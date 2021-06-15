/*

Longest Substring Without Duplication

*/

#include<string>
using namespace std;

string longestSubstringWithoutDuplication(string str) {
  // Write your code here.
	string ans="";
	if(str.length()==1){
		ans.push_back(str[0]);
		return ans;
	}
		
	if(str.length()==2){
		if(str[0]==str[1]){
			ans.push_back(str[0]);
			return ans;
		}
		else{
			return str;
		}
	}
	
	unordered_map<char, vector<int>> occurences;
	occurences = {};
	// unordered_map<char, int> counter;
	vector<int> counter = vector<int>(26, 1);
	int longestLength = INT_MIN;
	pair<int, int> positions = {};
	
	
	for(int index=0; index<str.length(); index++){		
		occurences[str[index]].push_back(index);
	}
	
	int start = 0;
	int end = 0;
	
	while(end<str.length()){
		
		counter[str[end]-'a']--;
		
		
		if(counter[str[end]-'a']<0){
			while(str[start]!=str[end]){
				counter[str[start]-'a']++;
				start++;
			}
			start++;
		}
		
		
		
		
		if(end-start+1 > longestLength){			
			longestLength = end-start+1;			
			positions = {start, end};
		}
		end++;
	}
	
	for(int i=positions.first; i<=positions.second; i++){		
		ans.push_back(str[i]);
	}
	return ans;

}
