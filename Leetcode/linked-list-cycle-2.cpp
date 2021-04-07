/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     
        
        
        
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode* slowptr;
        ListNode* fastptr;
        
        slowptr=head;
        fastptr=head;
        
        do{
            //cout<<slowptr->val<<" "<<fastptr->val<<endl;
            if(slowptr)
                slowptr=slowptr->next;
            else
                return NULL;
            
            if(fastptr && fastptr->next)                
                fastptr=fastptr->next->next;
            else 
                return NULL;
            
        }while(slowptr!=fastptr);
        
        
        slowptr=head;
                
        while(slowptr!=fastptr){
            
            slowptr=slowptr->next;
            fastptr=fastptr->next;
        }
        
        return fastptr;
        
        
    }
};
