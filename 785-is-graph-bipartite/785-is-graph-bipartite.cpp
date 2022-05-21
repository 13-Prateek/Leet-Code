class Solution {
public:
    bool bpt(int src,vector<vector<int>> graph,int color[]){
        if(color[src]==-1){
            color[src]=1;
        }
        for(auto it: graph[src]){
            if(color[it]==-1){
                color[it]=1-color[src];
                if(!bpt(it,graph,color))return false;
            }
            else if(color[it]==color[src]){
                return false;
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