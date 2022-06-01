class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis){
        vis[node]=1;
        for(auto it: rooms[node]){
            if(!vis[it]){
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,rooms,vis);
            }
        }
        if(count>1)return false;
        return true;
    }
};