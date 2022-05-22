class Solution {
public:
    bool dfs(int src, vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfsvis){
        visited[src]=1;
        dfsvis[src]=1;
        for(auto it: adj[src]){
            if(!visited[it]){
                if(dfs(it,adj,visited,dfsvis)) return true;
            }
            else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[src]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto c : prerequisites){
            adj[c[1]].push_back(c[0]);
        }
        vector<int> visited(numCourses,0);
        vector<int> dfsvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,dfsvis)){
                    return false;
                }
            }
        }
        return true;
    }
};