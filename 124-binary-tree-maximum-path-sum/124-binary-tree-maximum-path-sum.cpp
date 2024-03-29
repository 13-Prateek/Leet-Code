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
    int recur(TreeNode* root, int &maxi){
        if(!root){
            return 0;
        }
        int lh=max(0,recur(root->left,maxi));
        int rh=max(0,recur(root->right,maxi));
        int val=root->val;
        maxi=max(maxi,val+lh+rh);
        return val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        recur(root,maxi);
        return maxi;
    }
};