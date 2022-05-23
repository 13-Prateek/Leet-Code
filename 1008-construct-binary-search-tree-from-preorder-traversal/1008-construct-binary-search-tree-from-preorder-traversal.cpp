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
    TreeNode* ctree(vector<int>& preorder, int preS, int preE, vector<int>& inorder, int inS, int inE, map<int,int>& m){
        if(inS> inE || preS>preE){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[preS]);
        int elem=m[root->val];
        int nelem=elem-inS;
        root->left=ctree(preorder,preS+1,preS+nelem,inorder,inS,elem-1,m);
        root->right=ctree(preorder,preS+1+nelem,preE,inorder,elem+1,inE,m);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder(n);
        for(int i=0;i<n;i++){
            inorder[i]=preorder[i];
        }
        sort(inorder.begin(),inorder.end());
        int inS=0, inE=n-1;
        int preS=0, preE=n-1;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return ctree(preorder,preS,preE,inorder,inS,inE,m);
    }
};