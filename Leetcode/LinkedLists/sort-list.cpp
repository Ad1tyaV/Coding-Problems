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

/*
https://leetcode.com/problems/sort-list/
*/

class Solution {
public:
    
    ListNode* findMid(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        return slow;
        
    }
    
    ListNode* merge(ListNode* first, ListNode* second){
        
        ListNode* head = NULL;
        ListNode* crawl = NULL;
        
        while(first && second){
            
            if(first->val < second->val){
                if(!crawl){
                    
                    crawl = new ListNode(first->val);
                    head = crawl;
                    
                }
                else{
                    crawl->next = new ListNode(first->val);
                    crawl = crawl->next;
                }
                first = first->next;
            }
            else{
                
                if(!crawl){
                    crawl = new ListNode(second->val);
                    head = crawl;
                }
                else{
                    crawl->next = new ListNode(second->val);
                    crawl = crawl->next;
                }
                
                second = second->next;
                
            }            
            
        }
        
        while(first){
            if(!crawl){
                crawl = new ListNode(first->val);
                head = crawl;
            }
            else{
                
                crawl -> next = new ListNode(first->val);
                crawl = crawl->next;
                
            }
            first = first->next;
        }
        while(second){
            
            if(!crawl){
                crawl = new ListNode(second->val);
                head = crawl;
            }
            else{
                
                crawl -> next = new ListNode(second->val);
                crawl = crawl->next;
                
            }
            second = second->next;
            
        }
        
        return head;
        
    }
    
    ListNode* mergeSort(ListNode* head){
        
        if(head->next==NULL) // If only one element exists just return it.
            return head;
            
        ListNode* mid = findMid(head);
        ListNode* secondPartition = mid->next;
        mid->next = NULL;
        
        ListNode* first = mergeSort(head);
        ListNode* second = mergeSort(secondPartition);
        
        return merge(first, second);
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        
        if((!head) || (!(head->next)))
            return head;
        
        return mergeSort(head);
        
    }
};
