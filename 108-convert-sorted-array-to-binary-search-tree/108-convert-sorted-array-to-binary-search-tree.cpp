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
    TreeNode* ctree(int st, int end, vector<int> &nums){
        if(st>end){
            return NULL;
        }
        int mid=(st+end)>>1;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left=ctree(st,mid-1,nums);
        root->right=ctree(mid+1,end,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0, h=nums.size()-1;
        return ctree(l,h,nums);       
    }
};