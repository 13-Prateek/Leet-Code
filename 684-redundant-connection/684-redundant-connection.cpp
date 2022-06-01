class Solution {
public:
    bool dfs(int src, int parent, vector<int>& vis, vector<vector<int>>& graph){
        vis[src]=1;
        for(auto it: graph[src]){
            if(!vis[it]){
                if(dfs(it,src,vis,graph))return true;
            }
            else if(it!=parent)return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        vector<int> vis(n+1,0);
        for(auto it: edges){
            fill(begin(vis),end(vis),0);
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            if(dfs(it[0],-1,vis,graph))return it;
        }
        return {};
    }
};