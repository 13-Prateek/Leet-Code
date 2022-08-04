class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i, int j,int m,int n, vector<vector<char>> &grid){
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        if(grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        for(int x=0;x<4;x++){
            dfs(i+dx[x],j+dy[x],m,n,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }
        return count;
    }
};