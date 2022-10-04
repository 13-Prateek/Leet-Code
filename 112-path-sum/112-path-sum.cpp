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
    bool recur(TreeNode* root,int t,int s){
        if(!root){
            return false;
        }
        s+=root->val;
        if(!root->left && !root->right){
            if(s==t){
                return true;
            }
        }
        return recur(root->left,t,s)||recur(root->right,t,s);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recur(root,targetSum,0);
    }
};