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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        ListNode* n1=head, *n2=head;
        int i=1,j=1;
        while(i!=k){
            n1=n1->next;
            i++;
        }
        while(j!=count-k+1){
            n2=n2->next;
            j++;
        }
        swap(n1->val,n2->val);
        return head;
    }
};