// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

struct node{
    int u,v,wt;
    node(int first, int second, int weight){
        u=first;
        v=second;
        wt=weight;
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool MyComp(node a, node b){
	    return a.wt<b.wt;
	}
	int findpar(int u, vector<int>& parent){
	    if(u==parent[u]){
	        return u;
	    }
	    return parent[u]=findpar(parent[u],parent);
	}
	void unionn(int u, int v, vector<int>&rank, vector<int>& parent){
	    u=findpar(u,parent);
	    v=findpar(v,parent);
	    if(rank[u]<rank[v]){
	        parent[u]=v;
	    }
	    else if(rank[v]<rank[u]){
	        parent[v]=u;
	    }
	    else{
	        parent[v]=u;
	        rank[u]++;
	    }
	}
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<int> parent(v);
        vector<int> rank(v,0);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
        vector<node> edge;
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                edge.push_back(node(i,it[0],it[1]));
            }
        }
        sort(edge.begin(),edge.end(),MyComp);
        int cost=0;
        for(auto it: edge){
            if(findpar(it.u,parent)!=findpar(it.v,parent)){
                cost+=it.wt;
                unionn(it.u,it.v,rank,parent);
            }
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends