/*
https://www.youtube.com/watch?v=1cspuQ6qHW0
*/

#include<iostream>
#include<vector>

using namespace std;

void printPerms(string input, string so_far, int index=0){

    if(index==input.size()){
        cout<<so_far<<endl;
        return;
    }

    if(index==0){
        printPerms(input, so_far+input[index], index+1);
    }
    else{

        string include = so_far+" "+input[index];
        printPerms(input, include, index+1);
        printPerms(input, so_far+input[index], index+1);

    }

}

int main(){

    string input = "ABCDEF";

    printPerms(input, "");

    return 0;
}
