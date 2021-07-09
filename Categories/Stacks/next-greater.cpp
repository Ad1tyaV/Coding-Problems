#include<stack>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){

    vector<int> values = {6,2,9,4,3,1,5};
    unordered_map<int, int> check;

    stack<int> st;
    st.push(values[0]);

    for(int i=1; i<values.size(); i++){

        if(st.empty()){
            st.push(values[i]);
        }
        else{

            while(st.size() && st.top()<values[i]){
                check[st.top()] = values[i];
                st.pop();
            }
            st.push(values[i]);
        }
        
    }

    for(auto iterator = check.begin(); iterator!=check.end(); iterator++){
        cout<<iterator->first<<" and "<<iterator->second<<endl;
    }
    

    

    return 0;
}
