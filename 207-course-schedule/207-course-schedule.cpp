class Solution {
public:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &dfsrec){
        vis[src]=true;
        dfsrec[src]=true;
        //cycle exits if there a nde appears twice in recursion call stack
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(it,adj,vis,dfsrec)){
                    return true;
                }
            }
            else if(dfsrec[it]){
                return true;
            }
        }
        dfsrec[src]=false;
        return false;
    }
    bool canFinish(int numc, vector<vector<int>>& prereq) {
        vector<int> adj[numc];
        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        vector<int> vis(numc,0);
        vector<int> dfsrec(numc,0);
        for(int i=0;i<numc;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dfsrec)){
                    return false;
                }
            }
        }
        return true;
    }
};