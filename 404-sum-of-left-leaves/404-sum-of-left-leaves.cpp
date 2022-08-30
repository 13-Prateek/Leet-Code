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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                if(!node->left->left && !node->left->right){
                    sum+=node->left->val;
                }
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return sum;
    }
};