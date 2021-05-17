#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	vector<vector<int>> ans;
	
	sort(array.begin(), array.end());
	
	
	for(int i=0; i<array.size()-2; i++){
		
		int first = array[i];
		
		int left = i+1;
		int right = array.size()-1;
		int target = targetSum - first;
		
		while(left<right){			
			if(array[left]+array[right]==target){
				ans.push_back({first, array[left], array[right]});		
				left++;
				right--;
			}
			else{
				if(array[left]+array[right]<target){				
					left++;				
				}
				else{
					right--;
				}
			}
			
		}
		
	}	
	
	
  return ans;
}
