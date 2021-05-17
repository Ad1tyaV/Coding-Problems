#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  
	sort(array.begin(), array.end());
	
	int left = 0;
	int right = array.size()-1;
	
	while(left<right){
		
		if(array[left]==targetSum - array[right]){
			return {array[left], array[right]};
		}
		
		if(array[left]+array[right]<targetSum){
			left++;
			continue;
		}
		
		if(array[left]+array[right]>targetSum){
			right--;
			continue;
		}
		
		
	}
	
	
  return {};
}
