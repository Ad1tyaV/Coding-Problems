/*
  Move Element to End.
*/

#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> arr, int toMove) {
  	
	int left = 0;
	int right = arr.size()-1;
	
	while(left<right){
		
		if(arr[right] == toMove){
			right--;
			continue;
		}
		
		if(arr[left]==toMove){
			arr[left] = arr[right];
			arr[right] = toMove;
			
			left++;
			right--;
		}
		else{
			left++;			
		}
		
		
	}
	
	
	
  return arr;
}
