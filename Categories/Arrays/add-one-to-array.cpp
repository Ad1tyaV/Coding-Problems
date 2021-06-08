#include<iostream>
#include<vector>

using namespace std;

void addOneToNumber(vector<int> &list, int carry=0){

    int index = list.size()-1;
    do{

        if(list[index]+1>9){
            carry = 1;
            list[index] = 0;            
        }
        else{
            list[index] += 1;
            carry = 0;
        }
        index--;

    }while(index>=0 && carry);

    if(carry)
        list.insert(list.begin(), carry);

}

int main(){

    vector<vector<int>> tests = { {1,2,3,4,5}, {1,2,3,4,9}, {9,9,9,9}, {9}, {9,9}, {1,1,2}, {0}};
    
    for(vector<int> test:tests){
        addOneToNumber(test);

        for(int element:test){
            cout<<element<<"\t";
        }
        cout<<endl;
    }
            

    return 0;
}
