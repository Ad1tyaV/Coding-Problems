/*
https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main(){

    // vector<int> arr1 = {1, 3, 15, 11, 2};
    // vector<int> arr2 = {23, 127, 235, 19, 8};
    vector<int> arr1 = {1, 2, 11, 5};
    vector<int> arr2 = {4, 12, 19, 23, 127, 235};

    /*
        1, 2, 3, 11, 15
        8, 19, 23, 127, 235
    */

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int first_pointer = 0;
    int second_pointer = 0;

    int min_answer = INT_MAX;

    while(first_pointer<arr1.size() && second_pointer<arr2.size()){

        min_answer = min(abs(arr1[first_pointer] - arr2[second_pointer]), min_answer);
        
        if(arr1[first_pointer] > arr2[second_pointer]){
            second_pointer++;
        }
        else
            first_pointer++;

    }

    cout<<"Min="<<min_answer<<endl;


    return 0;
}
