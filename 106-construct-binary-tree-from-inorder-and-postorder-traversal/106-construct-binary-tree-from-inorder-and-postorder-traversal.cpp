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
    TreeNode* ctree(vector<int>& inorder, int inS, int inE, vector<int>& postorder,int pS, int pE, map<int,int>& m){
        if(inS>inE || pS>pE){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pE]);
        int elem=m[root->val];
        int nelem=elem-inS;
        root->left=ctree(inorder,inS,elem-1,postorder,pS,pS+nelem-1,m);
        root->right=ctree(inorder,elem+1,inE,postorder,pS+nelem,pE-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int inS=0,inE=inorder.size()-1;
        int pS=0, pE=postorder.size()-1;
        return ctree(inorder,inS,inE,postorder,pS,pE,m);
    }
};