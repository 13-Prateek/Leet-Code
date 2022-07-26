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
    int height(TreeNode* root, int &hdiff){
        if(!root){
            return 0;
        }
        int lh=height(root->left,hdiff);
        int rh=height(root->right,hdiff);
        hdiff=max(hdiff,abs(lh-rh));
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int hdiff=0;
        height(root,hdiff);
        if(hdiff<=1){
            return true;
        }
        return false;
    }
};