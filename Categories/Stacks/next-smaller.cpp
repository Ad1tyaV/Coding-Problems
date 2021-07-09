#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    
    vector<int> arr = {6,2,9,4,3,1,5};
    stack<int> st;
    unordered_map<int, int> check;

    st.push(arr[0]);

    for(int index=1; index<arr.size(); index++){

        if(st.empty()){
            st.push(arr[index]);            
        }
        else{

            while(st.size() && st.top()>arr[index]){
                check[st.top()] = arr[index];
                st.pop();
            }
            st.push(arr[index]);

        }

    }

    for(auto iterator = check.begin(); iterator!=check.end(); iterator++){
        cout<<iterator->first<<" and "<<iterator->second<<endl;
    }
    cout<<arr[arr.size()-1]<<" and "<<-1<<endl;


    return 0;
}
