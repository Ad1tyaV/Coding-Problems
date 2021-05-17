#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {  
	
	set<int> track(array.begin(), array.end());
	
	for(auto it = track.begin(); it!=track.end(); it++){
		
		if(targetSum%2==0 && *it==targetSum/2)
			continue;
			
		
		if(track.find(targetSum - *it)!=track.end())
			return {*it, targetSum-*it};
		
	}
		
  return {};
}
