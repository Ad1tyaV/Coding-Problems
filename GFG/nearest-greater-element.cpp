#include<iostream>
#include<vector>
#include <climits>

using namespace std;


int main(){
	
	//vector<int> nums ={1, 2, 4, 5, 6, 6, 8, 9};
	vector<int> nums = {1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28};
	
	int l = 0;
	int r = nums.size()-1;
	//int target = 11;
	int target=5;
	int currentIndex = -1;
	int current = INT_MIN;
	
	while(l<=r){
		
		int m = (l+r)/2;
		
		
		if(nums[m]==target){
			l=m+1;
		}
		else if(nums[m]>target){			
			//l = m+1;			
			r = m-1;
			if(current==INT_MIN){
				current = nums[m];
				currentIndex = m;
			}
			else if(nums[m]<current){
				current = nums[m];
				currentIndex = m;
			}			
		}
		else{
			
			//r = m-1;
			l = m+1;
			
		}
		
	}
	
	cout<<"Index="<<currentIndex<<" current="<<current<<endl;
	
	return 0;
}
