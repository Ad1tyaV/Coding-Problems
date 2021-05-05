/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*

https://leetcode.com/problems/copy-list-with-random-pointer

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return head;
        
        if(head->next==NULL){
            
            if(head->random==NULL){
                return new Node(head->val);
            }
            else{
                Node* temp = new Node(head->val);
                temp->random = temp;
                return temp;
            }
            
        }
            
        
        map<Node*, pair<Node*, Node*>> mp;
        map<Node*, Node*> oldNew;
        
        Node* h;
        h = head;
        
        while(h){            
            Node* temp;
            temp = new Node(h->val);
            oldNew[h] = temp;
            mp[h] = {h->next, h->random};            
            h=h->next;
        }
         
        
        for(map<Node*, pair<Node*, Node*>>::iterator it = mp.begin(); it!=mp.end(); it++){
            
            Node* temp;
            temp = oldNew[(it->first)];
            temp->next = oldNew[(it->second).first];
            temp->random = oldNew[(it->second).second];
            
        }
        
        return oldNew[head];
    }
};
