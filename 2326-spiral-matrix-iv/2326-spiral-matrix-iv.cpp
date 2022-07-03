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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int row=m;
        int col=n;
        int count=1;
        vector<vector<int>> spiral(row,vector<int>(col,-1));
        int top=0,right=col-1,bottom=row-1,left=0;
        ListNode* curr=head;
        while(top<=bottom && left<=right && curr!=NULL){
            for(int i=left;i<=right && curr!=NULL;i++){
                spiral[top][i]=curr->val;
                curr=curr->next;
            }
            top++;
            for(int i=top;i<=bottom && curr!=NULL;i++){
                spiral[i][right]=curr->val;
                curr=curr->next;
            }
            right--;
            for(int i=right;i>=left && curr!=NULL;i--){
                spiral[bottom][i]=curr->val;
                curr=curr->next;
            }
            bottom--;
            for(int i=bottom;i>=top && curr!=NULL;i--){
                spiral[i][left]=curr->val;
                curr=curr->next;
            }
            left++;
        }
        return spiral;
    }
};