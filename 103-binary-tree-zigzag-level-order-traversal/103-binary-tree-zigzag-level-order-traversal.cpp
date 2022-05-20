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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool flag=false;
        while(!q.empty()){
            vector<int> row;
            int n=q.size();
            for(int i=0;i<n;i++){
                if(flag){
                    auto p=q.front();
                    q.pop_front();
                    row.push_back(p->val);
                    if(p->right){
                        q.push_back(p->right);
                    }
                    if(p->left){
                        q.push_back(p->left);
                    }
                }
                else{
                    auto p=q.back();
                    q.pop_back();
                    row.push_back(p->val);
                    if(p->left){
                        q.push_front(p->left);
                    }
                    if(p->right){
                        q.push_front(p->right);
                    }
                }
            }
            ans.push_back(row);
            flag=!flag;
        }
        return ans;
    }
};