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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* curr=head;
        while(curr){
            Node *next=curr->next;
            Node* dupli=new Node(curr->val);
            curr->next=dupli;
            dupli->next=next;
            curr=next;
        }
        for(curr=head;curr!=NULL;curr=curr->next->next){
            Node* copy=curr->next;
            copy->random=curr->random?curr->random->next:NULL;
        }
        Node* h2=head->next;
        curr=head;
        Node* curr2=h2;
        while(curr && curr2){
            curr->next=curr->next?curr->next->next:NULL;
            curr2->next=curr2->next?curr2->next->next:NULL;
            curr=curr->next;
            curr2=curr2->next;
        }
        return h2;
    }
};