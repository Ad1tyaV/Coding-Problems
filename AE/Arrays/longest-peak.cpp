using namespace std;

int longestPeak(vector<int> array) {
  
	int longestLength = 0;
	
	for(int index = 0; index < array.size(); index++){
		
		int current_index = index;
		
		while(current_index+1 < array.size() && array[current_index] < array[current_index+1]){
			current_index++;
		}
		
		if(current_index==index || current_index==array.size()-1)
			continue;
		int end = current_index;
		
		while(end+1 < array.size() && array[end] > array[end+1]){
			end++;
		}
		
		if(end==current_index){
			longestLength = max(longestLength, 0);
		}
		else
			longestLength = max(longestLength, end-index+1);
		
	}
	
	
  return longestLength;
}
