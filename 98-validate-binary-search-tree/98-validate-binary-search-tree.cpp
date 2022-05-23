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
TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(!isValidBST(root->left))
            return false;
        
        if(prev && prev->val >= root->val) return false;
        prev = root;
        
        if(!isValidBST(root->right))
            return false;
        
        return true;
    }
};