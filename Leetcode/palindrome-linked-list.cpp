/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

	ListNode* reverse(ListNode* head){
		
	 if(!head) return head;
     
     if(head->next==NULL) return head;   
        
        ListNode* current;
        ListNode* second;
        ListNode* prev=NULL;        
        current = head;
        
        
        
        while(current!=NULL){ 
            if(current->next==NULL){head=current;}
            second=current->next;
            current->next = prev;
            prev=current;
            current=second;
        }                
        
        
        
        return head;
		
	}

    bool isPalindrome(ListNode* head) {
        
		
		
		if(head->next==NULL) return true;
		
		if(head->next->next==NULL)
			return head->val==head->next->val;
				
		ListNode* slowptr;
		ListNode* fastptr;
		ListNode* current;
		current=head;
		
		slowptr=head;
		fastptr=head;
		
		while(fastptr->next->next!=NULL){            
			slowptr=slowptr->next;
            fastptr=slowptr->next;
            if(fastptr->next==NULL) break;			
		}
		
        
		ListNode* middle;        
		middle = reverse(slowptr);
		current=head;
		
		while(middle!=NULL && current!=NULL){            
			if(middle->val!=current->val){				
				return false;
			}
			middle=middle->next;
            current=current->next;
		}
		
		
        return true;
    }
};
