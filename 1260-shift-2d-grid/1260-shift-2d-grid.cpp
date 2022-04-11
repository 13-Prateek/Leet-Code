class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while(k!=0){
            k--;
            int row=grid.size();
            int col=grid[0].size();
            for(int i=0;i<row;i++){
                int x=grid[i][col-1];
                for(int j=col-1;j>=1;j--){
                    grid[i][j]=grid[i][j-1];
                }
                grid[i][0]=x;
            }
            int x=grid[row-1][0];
            for(int i=row-1;i>=1;i--){
                grid[i][0]=grid[i-1][0];
            }
            grid[0][0]=x;
        }
        return grid;
    }
};