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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* c1=head;
        ListNode* c2=head;
        if(head->next==NULL&&n==1){
            return head->next;
        }
        int count=n;
        while(count>=0 && c2!=NULL){
            c2=c2->next;
            count--;
        }
        if(count!=-1){
            return head->next;
        }
        while(c2!=NULL){
            c1=c1->next;
            c2=c2->next;
        }
        c1->next=c1->next->next;
        return head;
    }
};