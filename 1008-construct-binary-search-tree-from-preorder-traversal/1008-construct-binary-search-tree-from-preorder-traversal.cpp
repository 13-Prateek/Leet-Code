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
        if(preS>preE || inS>inE){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[preS]);
        int elem=m[preorder[preS]];
        int nelem=elem-inS;
        root->left=ctree(preorder,preS+1,preS+nelem,inorder,inS,elem-1,m);
        root->right=ctree(preorder,preS+nelem+1,preE,inorder,elem+1,inE,m);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder(n);
        for(int i=0;i<n;i++){
            inorder[i]=preorder[i];
        }
        sort(inorder.begin(),inorder.end());
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return ctree(preorder,0,n-1,inorder,0,n-1,m);
    }
};