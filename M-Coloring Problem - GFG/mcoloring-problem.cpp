// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101],int color[], int v, int c, int V){
    for(int k=0;k<V;k++){
        if(graph[v][k] && color[k]==c){
            return false;
        }
    }
    return true;
}
bool helper(bool graph[101][101], int m, int color[], int v,int V){
    if(v==V){
        return true;
    }
    for(int c=1;c<=m;c++){
        if(isSafe(graph,color,v,c,V)){
            color[v]=c;
            if(helper(graph,m,color,v+1,V)){
                return true;
            }
            color[v]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=0;
    }
    if(helper(graph,m,color,0,V)){
        return true;
    }
    return false;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends