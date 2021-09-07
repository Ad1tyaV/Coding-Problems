using namespace std;

bool isIncreasing(vector<int> array){
	
	for(int index = 0; index<array.size()-1; index++){		
		if(array[index]>array[index+1])
			return false;
		
	}
	
	return true;
	
}

bool isDecreasing(vector<int> array){
	
	for(int index = 0; index<array.size()-1; index++){
			
			if(array[index]<array[index+1])
				return false;
		
	}
	return true;
}

bool isMonotonic(vector<int> array) {
  
	
	
	if(array.size()==2 || array.size()==1 || array.size()==0)
		return true;
	
	return isIncreasing(array)||isDecreasing(array);	
	
}
