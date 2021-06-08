#include<iostream>
#include<vector>
#include<stack>
// #include<pair>

using namespace std;

int main(){

    vector<vector<int>> matrix = {  {1,2,3,4}, 
                                    {5,6,7,8}, 
                                    {9,10,11,12},
                                    {13,14,15,16}
                                };
    
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

        

    for(int i=0; i< matrix.size(); i++){

        for(int j=0; j<matrix[0].size(); j++){

            if(!visited[i][j]){
                visited[i][j] = true;
                stack<pair<int, int>> matrixStack;
                matrixStack.push({i, j});                
                
                
                
                while(matrixStack.size()){
                    
                    pair<int, int> top = matrixStack.top();                                        
                    int x = top.first;
                    int y = top.second;                    


                    //Check neighbour                    
                    if(x+1<matrix.size() && y-1>=0){ 
                        // cout<<"x+1="<<x+1<<" y-1="<<y-1<<endl;
                        if(!visited[x+1][y-1]){
                            visited[x+1][y-1] = true;
                            matrixStack.push({x+1, y-1});
                            continue;
                        }
                        else{
                            matrixStack.pop();
                            cout<<matrix[top.first][top.second]<<"\t";
                            continue;
                        }                            
                    }
                    
                    cout<<matrix[top.first][top.second]<<"\t";
                    matrixStack.pop();

                }                
                cout<<endl;
            }

        }

    }
    
    

    return 0;
}
/*

1
5       2
9       6       3
13      10      7       4
14      11      8
15      12
16

*/
