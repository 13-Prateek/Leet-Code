class Solution {
public:
    bool dfs(int node, vector<vector<int>> adj,vector<int> &color){
        if(color[node]==-1){
            color[node]=1;
        }
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!dfs(it,adj,color)){
                    return false;
                }
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(!dfs(i,graph,color)){
                return false;
            }
        }
        return true;
    }
};