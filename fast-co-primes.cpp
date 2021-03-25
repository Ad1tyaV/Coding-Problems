/*
Two integers are said to be co-primes if their greatest common divisor is 1. Given an array of positive integers, A, return an array of integers, B, where B[= count of integers j such that 1 sj s A[i] and jis co-prime with respect to A[i).
Example A = [5, 8, 14]
The number A[0] = 5 is prime. All numbers greater than zero and less than 5, i.e. 1-4, are co-prime to 5, so B[0] = 4. For A[1] = 8, the integers [2, 4, 6] share at least the common divisor of 2 with 8. The 4 values, [1, 3, 5, 7), are co-primes, so B[1] = 4. For A[2] = 14, the integers [2, 4, 6, 7, 8, 10, 12] share a common divisor > 1 with 14. The 6 co- primes are [1, 3, 5, 9, 11, 13), so B[2] = 6. The return array is B = [4, 4, 6).
*/

#include <bits/stdc++.h>
#include<map>

using namespace std;

map<pair<int,int>,int> global;

bool checkIsPrime(int number){
    int i=2;
    while(i*i<=number){
        if(number%i==0){
            return false;
        }
        i++;
    }
    return true;
}

int gcd(int a,int b){
	
    if(b==0){
		global[{a,b}]=global[{b,a}]=a;
		return a;
	}
    else{
		if(global.find({b,a%b})==global.end() || global.find({a%b,b})==global.end()){
			return gcd(b,a%b);
		}
		else{
			global[{b,a%b}]=global[{a%b,b}]=gcd(b,a%b);
			return global[{b,a%b}];
			
		}
	}
}

int findNumberOfCoPrimes(int number){
    if(checkIsPrime(number)) return (number-1);
    else{
        int count=0;
        for(int i=1;i<number;i++){  
			if(gcd(i,number)==1) count++;
        }
        return count;
    }
}

int main()
{
    //int n;
    //cin >> n;
    int arr[]={5,8,12,14};
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		cout<<findNumberOfCoPrimes(arr[i])<<"\n";
	}    

    return 0;
}
