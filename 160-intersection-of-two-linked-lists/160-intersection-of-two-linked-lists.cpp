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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *curr=headA;
        while(curr!=NULL){
            l1++;
            curr=curr->next;
        }
        curr=headB;
        while(curr!=NULL){
            l2++;
            curr=curr->next;    
        }
        ListNode *curr1=headA;
        ListNode* curr2=headB;
        if(l1>l2){
            int x=l1-l2;
            while(x!=0){
                curr1=curr1->next;
                x--;
            }
        }
        else{
            int x=l2-l1;
            while(x!=0){
                curr2=curr2->next;
                x--;
            }
        }
        while(curr1!=NULL && curr2!=NULL){
            if(curr1==curr2){
                return curr1;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};