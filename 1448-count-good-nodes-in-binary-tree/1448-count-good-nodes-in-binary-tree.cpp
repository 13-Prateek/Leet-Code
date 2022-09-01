/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void recur(TreeNode* root,int maxi){
        if(!root){
            return;
        }
        if(root->val>=maxi){
            ans++;
        }
        // int temp=maxi;
        if(root->val>=maxi){
            maxi=root->val;
        }
        recur(root->left,maxi);
        recur(root->right,maxi);
        // maxi=temp;
    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        recur(root,maxi);
        return ans;
    }
};