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
class BstIterator{
  public:
    stack<TreeNode*> st;
    bool reverse;
    BstIterator(TreeNode* root, bool rev){
        reverse=rev;
        pushAll(root);
    }
    int next(){
        auto temp=st.top();
        st.pop();
        if(!reverse){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        return temp->val;
    }
    bool hasnext(){
        return !st.empty();
    }
   private:
    void pushAll(TreeNode* root){
        if(!reverse){
            while(root){
                st.push(root);
                root=root->left;
            }
        }
        else{
            while(root){
                st.push(root);
                root=root->right;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        BstIterator small(root,false);
        BstIterator large(root,true);
        int i=small.next();
        int j=large.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i=small.next();
            }
            else{
                j=large.next();
            }
            
        }
        return false;
    }
};