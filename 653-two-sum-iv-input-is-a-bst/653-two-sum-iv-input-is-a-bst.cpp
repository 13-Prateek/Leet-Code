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
    void helper(TreeNode* root, vector<int>& inorder){
        if(!root){
            return;
        }
        helper(root->left,inorder);
        inorder.push_back(root->val);
        helper(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        helper(root,inorder);
        int i=0,j=inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j]==k){
                return true;
            }
            else if(inorder[i]+inorder[j]<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};