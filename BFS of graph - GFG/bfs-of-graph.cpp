// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // void helper(int i, vector<int> adj[], vector<int>& visited, vector<int>& bfs){
    //     visited[i]=1;
    //     queue<int> q;
    //     q.push(i);
    //     while(!q.empty()){
    //         int v=q.front();
    //         q.pop();
    //         bfs.push_back(v);
    //         for(auto u:adj[v]){
    //             if(!visited[u]){
    //                 q.push(u);
    //                 visited[u]=1;
    //             }
    //         }
    //     }
    // }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        vector<int> visited(V,0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            bfs.push_back(v);
            for(auto u:adj[v]){
                if(!visited[u]){
                    q.push(u);
                    visited[u]=1;
                }
            }
        }
        
        return bfs;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends