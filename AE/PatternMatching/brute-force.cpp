#include<iostream>

using namespace std;

//Brute Force

bool bruteForce(string str, string substr) {
  
	int mainPointer = 0;
	int subPointer = 0;
	
	
	while(mainPointer<str.size()){
	
		int p1 = mainPointer;
		int p2 = subPointer;
		bool flag = true;
		
		while(p2<substr.size() && p1<str.size()){
			
			if(substr[p2]==str[p1]){
				p1++;
				p2++;
			}
			else{
				flag = false;
				break;			
			}
		}
		if(flag)
			return flag;
		mainPointer++;
		
	}	
	
	
  return false;
}
