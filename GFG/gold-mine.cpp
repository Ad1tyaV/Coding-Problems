#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

/*

    https://www.geeksforgeeks.org/gold-mine-problem/
    $ g++ -std=c++0x gold-mine.cpp -o gold-mine
    $ ./gold-mine
    Answer = 83

*/

int main(){


    // vector<vector<int>> arr = {{1, 3, 3}, {2, 1, 4}, {0, 6, 4}};
    // vector<vector<int>> arr = { {1, 3, 1, 5},{2, 2, 4, 1},{5, 0, 2, 3},{0, 6, 1, 2}};
    vector<vector<int>> arr ={{10, 33, 13, 15},{22, 21, 04, 1},{5, 0, 2, 3},{0, 6, 14, 2}};

    int answer = INT_MIN;
    
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), INT_MIN));

    
    for(int row = 0; row<arr.size(); row++){
        dp[row][0] = arr[row][0];
    }
   
    
    for(int col = 1; col<arr[0].size(); col++){

        for(int row = 0; row<arr.size(); row++){


            dp[row][col] = arr[row][col] + max(dp[row][col-1], max(row>0?dp[row-1][col-1]:INT_MIN, row+1>=arr.size()?INT_MIN:dp[row+1][col-1]));
            answer = max(dp[row][col], answer);

        }

    }
    

    cout<<"Answer = "<<answer<<endl;

    return 0;
}
