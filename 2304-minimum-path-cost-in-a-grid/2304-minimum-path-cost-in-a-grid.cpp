class Solution {
public:
     int explore(vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>> &dp,int i,int j)
    {
        if(i==grid.size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi=INT_MAX;
        
        for(int k=0;k<moveCost[grid[i][j]].size();k++)
        {
           maxi=min(maxi,grid[i][j]+moveCost[grid[i][j]][k]+explore(grid,moveCost,dp,i+1,k)); 
        }
        
        
        return dp[i][j]=maxi;
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int mini=INT_MAX;
      vector<vector<int>> dp(52,vector<int>(52,-1));
        for(int i=0;i<grid[0].size();i++)
            mini=min(mini,explore(grid,moveCost,dp,0,i));
         return mini;
    }
};