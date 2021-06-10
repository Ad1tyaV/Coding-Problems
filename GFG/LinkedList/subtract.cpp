/*
https://www.geeksforgeeks.org/subtract-two-numbers-represented-as-linked-lists/
*/
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct LinkedList{
    int value;
    LinkedList* next;

    LinkedList(int value){
        this->value = value;
        this->next = NULL;
    }

    LinkedList(int value, LinkedList* next){
        this->value = value;
        this->next = next;
    }
};
LinkedList* resultHead;
LinkedList* result;

void subtract(LinkedList* first, LinkedList* second, int carry = 0){

        stack<int> firstNumber;
        stack<int> secondNumber;

        while(first){            
            firstNumber.push(first->value);
            first=first->next;
        }

        while(second){            
            secondNumber.push(second->value);
            second=second->next;
        }

        while(firstNumber.size() && secondNumber.size()){

            int firstTop = firstNumber.top();
            int secondTop = secondNumber.top();

            cout<<firstTop<<","<<secondTop<<endl;

            if(firstTop+carry>=secondTop){
                carry = 0;
                if(!result){
                    result = new LinkedList(firstTop+carry-secondTop);
                    resultHead = result;                    
                }
                else{
                    result->next= new LinkedList(firstTop+carry-secondTop);                    
                    result = result->next;
                }
            }
            else{
                int subtraction = firstTop+carry+10 - secondTop;
                cout<<"sub="<<subtraction<<endl;
                carry = -1;
                if(!result){
                    result = new LinkedList(subtraction);
                    resultHead = result;                    
                }
                else{
                    result->next= new LinkedList(subtraction);                    
                    result = result->next;
                }
            }
            firstNumber.pop();
            secondNumber.pop();
        }
        while(!firstNumber.empty()){                        
            
            int subtraction = firstNumber.top()+carry;
            if(subtraction<0){
                subtraction+=10;
            }           

            result->next = new LinkedList(subtraction);
            result = result->next;
         
            firstNumber.pop();
        }

        while(!secondNumber.empty()){
            result->next= new LinkedList(secondNumber.top()+carry);
            result = result->next;
            carry = 0;
            secondNumber.pop();
        }

}

int main(){


    LinkedList* first;
    first = new LinkedList(7);
    first->next = new LinkedList(8);
    first->next->next = new LinkedList(9);

    LinkedList* second;
    second = new LinkedList(7);
    second->next = new LinkedList(8);    
    second->next->next = new LinkedList(8); 


    subtract(first, second);
    vector<int> ans;
    
    while(resultHead){
        ans.push_back(resultHead->value);        
        resultHead=resultHead->next;
    }
    
    for(auto it = ans.rbegin(); it!=ans.rend(); it++){
        cout<<*it<<"\t";
    }
    cout<<endl;


    return 0;
}
