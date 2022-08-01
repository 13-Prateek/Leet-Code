class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int right=dp[i][j-1];
                int down=dp[i-1][j];
                dp[i][j]=right+down;
            }
        }
        return dp[m-1][n-1];
    }
};