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

// https://leetcode.com/problems/swap-nodes-in-pairs/submissions/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL) return head;
        
        if(head->next==NULL) return head;
        
        ListNode* prev;
        ListNode* slow;
        ListNode* fast;
        ListNode* dummy;
        
        dummy = new ListNode(-1, head);
        
        
        slow=head;
        prev = dummy;
        fast = head->next;
        
        while(fast){
            
            slow->next = fast->next;
            fast->next = slow;
            prev->next = fast;
            
            //Swapping
            ListNode* temp;            
            temp = slow;
            slow = fast;
            fast = temp;
            //Swap Complete
            
            if(fast->next){
                slow = slow->next->next;
                fast = fast->next->next;
                prev = prev->next->next;
            }
            else
                break;
            
        }
        
        
        return dummy->next;
    }
};
