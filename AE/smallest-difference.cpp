#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arr1, vector<int> arr2) {
  
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	
	int first = 0;
	int second = 0;
	int _min = INT_MAX;
	vector<int> ans;
	
	while(first<arr1.size() && second<arr2.size()){
		
		cout<<"ans={"<<arr1[first]<<","<<arr2[second]<<"}"<<endl;
		
		if(arr1[first]==arr2[second])
			return {arr1[first], arr2[second]};
		
		int current_difference = arr1[first] - arr2[second];
		
		if(current_difference>0){			
			
			if(abs(current_difference)<_min){
				_min = abs(current_difference);
				ans = {arr1[first], arr2[second]};				
			}
				
			
			second++;
		}
		else{			
			
			if(abs(current_difference) < _min){
				_min = abs(current_difference);
				ans = {arr1[first], arr2[second]};
			}						
			first++;
		}
		
	}
	
  return ans;
}
