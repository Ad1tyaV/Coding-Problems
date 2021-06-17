#include<iostream>
#include<vector>

using namespace std;

vector<int> parentVector;

int getParentIndex(int element){

    if(parentVector[element]<0)
        return element;
    
    return getParentIndex(parentVector[element]);

}

void unionOP(int from, int to){

    int parent_of_from = getParentIndex(from);
    int parent_of_to = getParentIndex(to);
    

    if(parent_of_to!=parent_of_to){
        
        if(parentVector[parent_of_from] > parentVector[parent_of_to]){

            parentVector[parent_of_from] += parentVector[parent_of_to];
            parentVector[parent_of_to] = parent_of_from;

        }
        else{

            parentVector[parent_of_to] += parentVector[parent_of_from];
            parentVector[parent_of_from] = parent_of_to;

        }

    }
    else{
        
        parentVector[parent_of_from] += parentVector[parent_of_to];
        parentVector[parent_of_to] = parent_of_from;

    }
    

}

int main(){

    vector<vector<int>> edges = {
        { 1, 0 }, { 0, 2 }, { 5, 3 }, { 3, 4 }, { 6, 7 }
    };

    int n = 8;

    parentVector = vector<int>(n, -1);
    

    for(vector<int> edge: edges){

        int from = edge[0];
        int to = edge[1];

        unionOP(from, to);

    }

    
    int number_of_components = 0;

    for(int i=0; i<parentVector.size(); i++){
        if(parentVector[i]<0){
            number_of_components ++;
        }
    }

    cout<<"Number of Components="<<number_of_components<<endl;

    return 0;
}
