class Solution {
public:
    bool bpt(int src,vector<vector<int>> graph,int color[]){
        color[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else{
                    if(color[node]==color[it]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int color[graph.size()];
        memset(color,-1,sizeof(color));
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!bpt(i,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};