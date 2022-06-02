class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& dfsvis, vector<int>& vis){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,dfsvis,vis))return true;
            }
            else if(dfsvis[it]==1)return true;
        }
        dfsvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,dfsvis,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(dfsvis[i]==0)ans.push_back(i);
        }
       // sort(ans.begin(),ans.end());
        return ans;
    }
};