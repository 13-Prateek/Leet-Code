/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr){
                s+="$,";
            }
            else{
                s+=to_string(curr->val)+",";
            }
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*> q;
        TreeNode* root= new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="$"){
                node->left=NULL;
            }
            else{
                TreeNode* curr=new TreeNode(stoi(str));
                node->left=curr;
                q.push(curr);
            }
            getline(s,str,',');
            if(str=="$"){
                node->right=NULL;
            }
            else{
                TreeNode* curr=new TreeNode(stoi(str));
                node->right=curr;
                q.push(curr);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));