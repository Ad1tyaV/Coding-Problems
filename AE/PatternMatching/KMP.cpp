#include<vector>

using namespace std;

vector<int> buildPrefixTable(string matchPattern){

	int updateIndex = 1;
	int pivot = 0;
	
	vector<int> prefix_table(matchPattern.size(), -1);
	
	
	prefix_table[0] = -1;
	
	while(updateIndex<matchPattern.size()){
		
		if(matchPattern[updateIndex]==matchPattern[pivot]){
			prefix_table[updateIndex] = pivot;
			pivot++;
			updateIndex++;
		}
		else{
			
			if(pivot>0){
				pivot = prefix_table[pivot-1] + 1;
			}
			else{
				updateIndex++;
			}
			
		}
		
	}
					
	return prefix_table;	
}


bool isMatched(string str, string substr, vector<int> prefix){
	
	int mainPointer = 0;
	int subPointer = 0;
	
	while(mainPointer+subPointer<str.size()){
		
		int pointer1 = mainPointer;
		int pointer2 = subPointer;
		
		bool matched = true;
		while(pointer1<str.size() && pointer2<substr.size()){
			if(str[pointer1]==substr[pointer2]){
				pointer1++;
				pointer2++;
			}
			else{
				if(pointer2>0){					
					pointer2 = prefix[pointer2-1] + 1;
				}
				else{
					pointer1++;
					matched = false;
				}
			}
		}
		
		if(matched)
			return true;
		
		mainPointer++;
	}
	
	return false;
}

bool knuthMorrisPrattAlgorithm(string str, string substr) {
  
	vector<int> prefix_table = {};
	prefix_table = buildPrefixTable(substr);
	
	
	return isMatched(str, substr, prefix_table);	
	
	
  return false;
}
