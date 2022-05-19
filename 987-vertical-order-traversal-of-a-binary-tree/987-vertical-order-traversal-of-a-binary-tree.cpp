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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            auto hd=it.second.first;
            auto lvl=it.second.second;
            mp[hd][lvl].insert(it.first->val);
            if(it.first->left){
                q.push({it.first->left,{hd-1,lvl+1}});
            }
            if(it.first->right){
                q.push({it.first->right,{hd+1,lvl+1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p: mp) {
            vector < int > col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
                }
            ans.push_back(col);
        }
        return ans;
    }
};