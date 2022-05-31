class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int x, int y, int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        if(x<0 || y<0 || x>=row || y>=col || vis[x][y]==1 || grid[x][y]=='0'){
            return;
        }
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            dfs(x+dx[i],y+dy[i],row,col,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row,vector<int> (col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,row,col,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};