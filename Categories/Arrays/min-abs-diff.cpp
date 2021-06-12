/*

g++ -std=c++0x minimum-abs-diff.cpp -o min-abs-diff
$ ./min-abs-diff
3 pair=11,8

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){

    vector<int> arr1 = {1, 3, 15, 11, 2};
    vector<int> arr2 = {23, 127, 235, 19, 8};
  

    int minimum_difference = INT_MAX;
    pair<int, int> difference_pair;
    

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int pointer1 = 0;
    int pointer2 = 0;

    while(pointer1<arr1.size() && pointer2<arr2.size()){

        int current_difference = abs(arr1[pointer1] - arr2[pointer2]);

        if(minimum_difference>current_difference){
            minimum_difference = current_difference;
            difference_pair.first = arr1[pointer1];
            difference_pair.second = arr2[pointer2];
        }
       
        if(arr1[pointer1]>arr2[pointer2]){
            pointer2++;
        }
        else{
            pointer1++;
        }
    
    }

    cout<<minimum_difference<<" pair="<<difference_pair.first<<","<<difference_pair.second<<endl;

    return 0;
}
