/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void LoT(Node* root, vector<vector<Node*>>& level){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node*> arr;
            for(int i=0;i<n;i++){
                Node* x=q.front();
                q.pop();
                arr.push_back(x);
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            level.push_back(arr);
        }
    }
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        vector<vector<Node*>> level;
        LoT(root,level);
        for(auto it: level){
            for(int i=0;i<it.size();i++){
                if(i+1<it.size()){
                    it[i]->next=it[i+1];
                }
            }
        }
        return root;
    }
};