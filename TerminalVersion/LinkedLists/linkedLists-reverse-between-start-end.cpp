#include<iostream>
#include<stack>

using namespace std;

struct LL{
    int value;
    LL* next;

    LL(int value){
        this->value = value;
        this->next = NULL;
    }

};

void printLL(LL* head){
    while(head){
        cout<<head->value<<"\t";
        head = head->next;
    }
    cout<<endl;
}

LL* reverseRange(LL* head, int start, int end){

    stack<LL*> nodeStack;
    LL* prev;
    LL* stitch = NULL;
    int count = 0;

    while(head){
        
        if(count<start){
            prev = head;
        }
        else if(count>=start && count<=end){
            nodeStack.push(head);
        }
        else if(count==end+1){
            stitch = head;
        }
        count++;        
        head =  head->next;

    }

    if(prev!=NULL)
        prev->next = nodeStack.top();    
    LL* prevStack = NULL;
    LL* newHead = NULL;

    while(!nodeStack.empty()){

        if(prevStack == NULL){            
            prevStack = nodeStack.top();  
            if(prev==NULL){
                newHead = prevStack;
            }
            nodeStack.pop();
        }
        else{
            prevStack->next = nodeStack.top();
            prevStack = prevStack->next;
            nodeStack.pop();
        }

    }
    // cout<<"Yes"<<endl;
    if(prevStack!=NULL){
        prevStack->next = stitch;
    }

    // printLL(newHead);
    if(prev!=NULL)
        return prev;
    return newHead;

}

int main(){

    LL* head;
    head = new LL(10);
    head->next = new LL(11);
    head->next->next = new LL(12);
    head->next->next->next = new LL(14);
    head->next->next->next->next = new LL(16);
    head->next->next->next->next->next = new LL(17);
    head->next->next->next->next->next->next = new LL(18);

    printLL(head);
    head = reverseRange(head, 1,6);
    // head = reverseRange(head, 0,6);
    printLL(head);



    return 0;
}
