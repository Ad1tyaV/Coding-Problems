#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<vector<int>> matrix = {  {1,2,3,4}, 
                                    {5,6,7,8}, 
                                    {9,10,11,12},
                                    {13,14,15,16}
                                };
   
    int x_index = 0;
    int y_index = 0;

    while(x_index<matrix.size() && y_index<matrix.size()){

        pair<int, int> vertical = {x_index+1, y_index};
        pair<int, int> horizontal = {x_index, y_index+1};

        while(vertical.first<matrix.size()){

            int temp = matrix[vertical.first][vertical.second];
            matrix[vertical.first][vertical.second] = matrix[horizontal.first][horizontal.second];
            matrix[horizontal.first][horizontal.second] = temp;

            vertical.first++;
            horizontal.second++;
        }

        x_index++;
        y_index++;
    }


    for(vector<int> row:matrix){
        for(int element:row){
            cout<<element<<"\t";
        }
        cout<<endl;
    }

    return 0;
}
/*
1       5       9       13
2       6       10      14
3       7       11      15
4       8       12      16
*/
