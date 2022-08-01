class Solution {
public:
    int recur(int i, int j, int m, int n,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>m-1 || j>n-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=recur(i,j+1,m,n,dp);
        int down=recur(i+1,j,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector(n,-1));
        
        return recur(0,0,m,n,dp);
    }
};