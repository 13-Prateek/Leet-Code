class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(int x,int y, int row, int col, vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=row || y>=col){
            return false;
        }
        if(grid[x][y]==0){
            return false;
        }
        return true;
    }
    void dfs(int x,int y, int row, int col, vector<vector<int>>& grid, int& area){
        grid[x][y]=0;
        area++;
        for(int i=0;i<4;i++){
            if(isValid(x+dx[i],y+dy[i],row,col,grid))
            dfs(x+dx[i],y+dy[i],row,col,grid,area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int area=0;
                if(grid[i][j]!=0){
                    dfs(i,j,row,col,grid,area);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};